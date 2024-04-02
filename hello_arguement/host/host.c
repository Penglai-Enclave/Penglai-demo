#include "arguements.h"
#include "penglai-enclave.h"
#include <stdlib.h>
#include <stdlib.h>
#include <pthread.h>

struct args
{
  void* in;
  int i;
};

void run_enclave_with_args(struct PLenclave *enclave)
{
  uint8_t* untrusted_mem_extent = NULL;
  get_name_t arguement;

  // init input arguements
  arguement.A = 1;
  arguement.B = 2;
  untrusted_mem_extent = (uint8_t*)malloc(DEFAULT_UNTRUSTED_SIZE);
  // untrusted_mem_extent = (uint8_t*)malloc(sizeof(arguement));
  memcpy(untrusted_mem_extent, &arguement, sizeof(arguement));

  //trans args by untrusted mem
  enclave->user_param.untrusted_mem_ptr = (unsigned long)untrusted_mem_extent;
  enclave->user_param.untrusted_mem_size = DEFAULT_UNTRUSTED_SIZE;
  
  PLenclave_run(enclave);

  //handle outputs
  get_name_t *args_after_run = (get_name_t *)untrusted_mem_extent;
  printf("1 + 2 = %d\n", args_after_run->C);
  if(args_after_run->C != 3){
    printf("something wrong with args\n");
  }
  printf("enclave's name: %s\n", args_after_run->enclave_name);
}

void* create_enclave(void* args0)
{
  struct args *args = (struct args*)args0;
  void* in = args->in;
  int i = args->i;
  int ret = 0;
  
  struct PLenclave* enclave = malloc(sizeof(struct PLenclave)); 
  struct enclave_args* params = malloc(sizeof(struct enclave_args)); 
  PLenclave_init(enclave);
  enclave_param_init(params);

  struct elf_args * enclaveFile = (struct elf_args *)in;
  params->untrusted_mem_size = DEFAULT_UNTRUSTED_SIZE;
  params->untrusted_mem_ptr = 0;
  if(PLenclave_create(enclave, enclaveFile, params) < 0 )
  {
    printf("host:%d: failed to create enclave\n");
    pthread_exit((void*)0);
  }
  else
  {
    printf("host:%d: enclave run\n", i);
    run_enclave_with_args(enclave);
    pthread_exit((void*)0);
  }
  PLenclave_finalize(enclave);
  enclave_param_destroy(params);
  free(enclave);
  free(params);
}

int main(int argc, char** argv)
{
  if(argc <= 1)
  {
    printf("Please input the enclave ELF file name\n");
  }

  int thread_num = 1;
  if(argc == 3)
  {
    thread_num = atoi(argv[2]);
    if(thread_num <= 0)
    {
      printf("error number\n");
      return -1;
    }
  }

  pthread_t* threads = (pthread_t*)malloc(thread_num * sizeof(pthread_t));
  struct args* args = (struct args*)malloc(thread_num * sizeof(struct args));

  struct elf_args* enclaveFile = malloc(sizeof(struct elf_args));
  char * eappfile = argv[1];
  elf_args_init(enclaveFile, eappfile);
  
  if(!elf_valid(enclaveFile))
  {
    printf("error when initializing enclaveFile\n");
    goto out;
  }

  for(int i=0; i< thread_num; ++i)
  {
    args[i].in = (void*)enclaveFile;
    args[i].i = i + 1;
    pthread_create(&threads[i], NULL, create_enclave, (void*)&(args[i]));
  }

  for(int i =0; i< thread_num; ++i)
  {
    pthread_join(threads[i], (void**)0);
  }

out:
  elf_args_destroy(enclaveFile);
  free(enclaveFile);
  free(threads);
  free(args);

  return 0;
}
