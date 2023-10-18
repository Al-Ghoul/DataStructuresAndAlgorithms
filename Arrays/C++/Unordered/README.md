# Intro
There's nothing really to run/execute here except for unit tests, for c++ I'm using CMake and CTest to run the tests.

## CMake & CTest
To build and run the tests, you need to use a cmd (windows) or a shell (linux), make sure you have [CMake](https://cmake.org/download/) installed, navigate to the current folder and run the following command to let cmake configure ur project (You also need MSBuild or a c/c++ compiler):
```sh
# Config the project in the current folder (Hence the dot .) and put the result in /build folder
cmake -S. -Bbuild
```
After the last command running successfully, navigate to the build folder and run the following to build the project:
```sh
# Build the project in the current directory (Supposed to be /build)
cmake --build .
```
After building the project, we are ready to run the tests; We only need one command from there.
```sh
# Replace build_conf with Debug or release accordingly (By default cmake builds the debug configuration)
ctest -C <build_conf>
```