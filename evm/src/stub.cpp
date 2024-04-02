extern "C" void eapp_print(const char* s, ...);

typedef unsigned long int size_t;
extern "C" void *malloc(size_t);
extern "C" void free(void *);

extern "C" void exit(int) {
	for (;;);
}

extern "C" int __snprintf_chk(char * str, size_t maxlen, int flag, size_t strlen, const char * format)
{
	return 0;
}

extern "C" double sqrt(double x) {
	return __builtin_sqrt(x);
}

extern "C" float sqrtf(float x) {
	return __builtin_sqrtf(x);
}

static const float one=1.0, two=2.0, tiny = 1.0e-30;
static const float
o_threshold	= 8.8721679688e+01,/* 0x42b17180 */
ln2_hi		= 6.9313812256e-01,/* 0x3f317180 */
ln2_lo		= 9.0580006145e-06,/* 0x3717f7d1 */
invln2		= 1.4426950216e+00,/* 0x3fb8aa3b */
	/* scaled coefficients related to expm1 */
Q1  =  -3.3333335072e-02, /* 0xbd088889 */
Q2  =   1.5873016091e-03, /* 0x3ad00d01 */
Q3  =  -7.9365076090e-05, /* 0xb8a670cd */
Q4  =   4.0082177293e-06, /* 0x36867e54 */
Q5  =  -2.0109921195e-07; /* 0xb457edbb */
static const float huge = 1.0e+30;

#define math_force_eval(x) \
({ __typeof (x) __x = (x); __asm __volatile__ ("" : : "w" (__x)); })

#define min_of_type_f() __FLT_MIN__
#define min_of_type_() __DBL_MIN__

# define __MATH_TG(TG_ARG, FUNC, ARGS)		\
  (sizeof (TG_ARG) == sizeof (float)		\
   ? FUNC ## f ARGS				\
   : FUNC ARGS)

#define min_of_type(x) __MATH_TG ((x), (__typeof (x)) min_of_type_, ())

#define fabs_tg(x) __MATH_TG ((x), (__typeof (x)) __builtin_fabs, (x))

#define math_check_force_underflow(x)				\
  do								\
    {								\
      __typeof (x) force_underflow_tmp = (x);			\
      if (fabs_tg (force_underflow_tmp)				\
	  < min_of_type (force_underflow_tmp))			\
	{							\
	  __typeof (force_underflow_tmp) force_underflow_tmp2	\
	    = force_underflow_tmp * force_underflow_tmp;	\
	  math_force_eval (force_underflow_tmp2);		\
	}							\
    }								\
  while (0)

#define GET_FLOAT_WORD(i, f) \
	do { i = *(uint32_t *) &f; } while (0)
#define SET_FLOAT_WORD(f, i) \
	do { *(uint32_t *) &f = i; } while (0)

extern "C" float fabsf(float x) {
	return __builtin_fabsf(x);
}

extern "C" void mmap() {
	eapp_print("Stub!");
}

extern "C" void munmap() {
	eapp_print("Stub!");
}

extern "C" void open() {
	eapp_print("Stub!");
}

extern "C" void close() {
	eapp_print("Stub!");
}

extern "C" void *memalign(size_t alignment, size_t size);

extern "C" void* __memmove_chk(void*, const void*, long unsigned int, long unsigned int) {
	eapp_print("Stub!");
	return nullptr;
}

extern "C" long sysconf(int name) {
	eapp_print("Stub!");
	return -1;
}

extern "C" void _ZNSt8ios_base4InitC1Ev() {
}

extern "C" void _ZNSt8ios_base4InitD1Ev() {
	eapp_print("Stub!");
}

extern "C" void __fxstat() {
	eapp_print("Stub!");
}

extern "C" int read() {
	eapp_print("Stub!");
	return -1;
}

namespace std {
	void __throw_bad_function_call() {
		eapp_print("Stub!");
		for (;;);
	}

	class ios_base {
	public:
		class Init {
		public:
			Init() { eapp_print("Stub!"); }
		};
	};
}

const char _nl_C_LC_CTYPE_class[769] =
  /* 0x80 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0x86 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0x8c */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0x92 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0x98 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0x9e */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xa4 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xaa */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xb0 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xb6 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xbc */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xc2 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xc8 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xce */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xd4 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xda */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xe0 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xe6 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xec */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xf2 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xf8 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xfe */ "\000\000" "\000\000" "\002\000" "\002\000" "\002\000" "\002\000"
  /* 0x04 */ "\002\000" "\002\000" "\002\000" "\002\000" "\002\000" "\003\040"
  /* 0x0a */ "\002\040" "\002\040" "\002\040" "\002\040" "\002\000" "\002\000"
  /* 0x10 */ "\002\000" "\002\000" "\002\000" "\002\000" "\002\000" "\002\000"
  /* 0x16 */ "\002\000" "\002\000" "\002\000" "\002\000" "\002\000" "\002\000"
  /* 0x1c */ "\002\000" "\002\000" "\002\000" "\002\000" "\001\140" "\004\300"
  /* 0x22 */ "\004\300" "\004\300" "\004\300" "\004\300" "\004\300" "\004\300"
  /* 0x28 */ "\004\300" "\004\300" "\004\300" "\004\300" "\004\300" "\004\300"
  /* 0x2e */ "\004\300" "\004\300" "\010\330" "\010\330" "\010\330" "\010\330"
  /* 0x34 */ "\010\330" "\010\330" "\010\330" "\010\330" "\010\330" "\010\330"
  /* 0x3a */ "\004\300" "\004\300" "\004\300" "\004\300" "\004\300" "\004\300"
  /* 0x40 */ "\004\300" "\010\325" "\010\325" "\010\325" "\010\325" "\010\325"
  /* 0x46 */ "\010\325" "\010\305" "\010\305" "\010\305" "\010\305" "\010\305"
  /* 0x4c */ "\010\305" "\010\305" "\010\305" "\010\305" "\010\305" "\010\305"
  /* 0x52 */ "\010\305" "\010\305" "\010\305" "\010\305" "\010\305" "\010\305"
  /* 0x58 */ "\010\305" "\010\305" "\010\305" "\004\300" "\004\300" "\004\300"
  /* 0x5e */ "\004\300" "\004\300" "\004\300" "\010\326" "\010\326" "\010\326"
  /* 0x64 */ "\010\326" "\010\326" "\010\326" "\010\306" "\010\306" "\010\306"
  /* 0x6a */ "\010\306" "\010\306" "\010\306" "\010\306" "\010\306" "\010\306"
  /* 0x70 */ "\010\306" "\010\306" "\010\306" "\010\306" "\010\306" "\010\306"
  /* 0x76 */ "\010\306" "\010\306" "\010\306" "\010\306" "\010\306" "\004\300"
  /* 0x7c */ "\004\300" "\004\300" "\004\300" "\002\000" "\000\000" "\000\000"
  /* 0x82 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0x88 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0x8e */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0x94 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0x9a */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xa0 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xa6 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xac */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xb2 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xb8 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xbe */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xc4 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xca */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xd0 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xd6 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xdc */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xe2 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xe8 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xee */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xf4 */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
  /* 0xfa */ "\000\000" "\000\000" "\000\000" "\000\000" "\000\000" "\000\000"
;

void __calloc(){
    eapp_print("__calloc stub.\n");
}

struct locale_t
{
    /* data */
};

extern "C" unsigned long long strtoull_l (const char *__restrict s, char **__restrict ptr, int base, locale_t loc){
    eapp_print("strtoull_l stub.\n");
}

extern "C" void *strtoll_l(void){
    eapp_print("strtoll_l stub.\n");
}

extern "C" void *__libc_fatal(void){
    eapp_print("__libc_fatal stub.\n");
}

extern "C" void *__libc_longjmp(void){
    eapp_print("__libc_longjmp stub.\n");
}

extern "C" void *calloc(long unsigned int, long unsigned int){
    eapp_print("calloc stub.\n");
}
