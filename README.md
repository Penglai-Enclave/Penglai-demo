# Demos

The demo/ directory provides several example enclave applications, e.g., prime.

Make sure you have compiled and installed the relevant programs and libraries in penglai-sdk before doing the following, the default path is `/opt/penglai`, you can specify the path with the parameter PENGLAI_LIB. Installation and acquisition of penglai-sdk can be found [here](https://github.com/Penglai-Enclave/penglai-sdk/tree/oe-24.03).

## Build environment
We have provided a docker image with a cross-compilation toolchain, so if you don't have a local riscv build tool, you can use the following image.But make sure you copy the penglai-sdk dependencies from the previous step.

```
docker run -v $(pwd):/home/penglai/penglai-demo -w /home/penglai/penglai-demo --network=host --rm -it fly0307/penglai-enclave:v0.5 bash
```


## Run encalve app

To run a Penglai-Enclave demo app you need two executables: host and Enclave demo.

If you just want to write and run a simple demo, such as hello_world, you can use the `penglai-host` executable provided by us in penglai-sdk. 
The host manages the Enclave lifecycle, where the create_enclave() function manages the Enclave by calling the following interface

```
PLenclave_create(): creates an Enclave and loads the specified application into the safe memory of the Enclave.
PLenclave_attest(): generates an Enclave report.
PLenclave_run(): executes the programme in the Enclave.
PLenclave_finalize(): destroy an Enclave.
```

Take `penglai-host hello_world` as an example, host will create an Enclave after execution, hello_world as an argument to host, and eventually host will load the contents of hello_world into pmp-protected safe memory, and after executing PLenclave_run(), it will actually run the hello_world programme from the beginning of the programme in memory. hello_world programme.

## Building your own demo

As explained in [Penglai (PMP)](https://github.com/Penglai-Enclave/Penglai-Enclave-sPMP), running an enclave demo requires two executables, host and enclave.

If you just want to write some simple demos, such as `hello_world`, then you can directly use the host executable we provide.

First you should create a new directory in the demo directory to place your enclave related files, such as `hello_world`, and then create a new file for writing your code, such as `hello_world.c`.

Before you write your own enclave code, you can refer to the writing of `demo/prime/prime.c`, and you should note the following requirements:

- `EAPP_ENTRY` is used to declare that this is the entry function of an enclave;
- `EAPP_RESERVE_REG` is is used to save the value of the register;
- `EAPP_RETURN` is used to provide the return value after exiting the enclave;
- If you need to output some information, you can use the `eapp_print` function which is also used in `prime.c`, and you can also see its implementation in `lib/app/src/print.c`;
- Make sure you include the appropriate header files: `#include "eapp.h"` and `#include "print.h"`;

After you have written the logic of your enclave, you also need to write a corresponding Makefile for your enclave. If your enclave is simple, you can directly imitate the structure of `demo/prime/Makefile`.

Finally, you need to modify the `demo/Makefile` to add the name of the newly created directory to the corresponding location. For example, you need to add `make -C hello_world` under the `all` target and `make -C hello_world clean` under the `clean` target.

Now, you can re-execute `PENGLAI_SDK=$(pwd) make -j8` command. If everything is successful, you will see the corresponding executable file appear in your demo directory. Then you just need to refer to [Penglai (PMP)](https://github.com/Penglai-Enclave/Penglai-Enclave-sPMP) to copy the executable file to the VM using *scp*, and run your own demo, e.g., a hello_world enclave, using `penglai-host hello_world`.

Congratulations! You have successfully built and run a demo written by yourself on Penglai.

## The demo_app that needs to be passed a parameter

Take the hello_arguement demo as an example.

In `demo/hello_arguement/host/host.c`, the interface for managing the Enclave remains unchanged, but the PLenclave_run() interface is replaced by the encapsulated run_enclave_with_args() interface, i.e., when loading the Enclave app and running it, it will either pass in arguments to the Enclave app, or receive the return value of the Enclave app.

The parameters passed to and from the Enclave app can be adjusted as needed. After the final compilation, an executable named `host` will be generated in the `demo/hello_arguement/host` directory, and an executable named `prime` will be generated in the `demo/hello_arguement/enclave` directory. Go into the hello_arguement directory and run the command `. /host/host . /prime/prime` .