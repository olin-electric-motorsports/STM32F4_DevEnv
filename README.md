# STM32F4_DevEnv
STM32F4 Development Environment

## Installing
### CMake
Follow this [link](https://cmake.org/download/) to download the bash file for Linux and install the latest version of CMake. Example of bash file for Ubuntu `cmake-3.12.2-Linux-x86_64.sh`. To install cmake from `.sh` file downloaded run the commands similar to the following:
```
wget https://cmake.org/files/v$version/cmake-$version.$build-Linux-x86_64.sh
sudo mkdir /opt/cmake
sudo sh cmake-$version.$build-Linux-x86_64.sh --prefix=/opt/cmake
```
Answer `Y` for license and answer `N` for including subdirectory. Then, add your binary link for Cmake.
```
sudo ln -s /opt/cmake/bin/cmake /usr/local/bin/cmake
```
Test your Cmake by typing in `cmake --version`

### GNU-MCU-ECLIPSE
A detailed instructions and troubleshooting can be followed in this [link](https://gnu-mcu-eclipse.github.io/toolchain/arm/install/#target-vs-host-platform) to install GNU MCU Eclipse ARM Embedded GCC. The official webpage of gnu instructs installing the compiler in the `/opt` folder but is not necessary. In the `CMakeList.txt`, the path to the compiler is pointed to the folder of this repository. A quick installation instruction can be followed below:

1. The GNU/Linux versions of GNU MCU Eclipse ARM Embedded GCC are packed as .tgz archives. Download the latest version from this [link](https://github.com/gnu-mcu-eclipse/arm-none-eabi-gcc/releases) named like `gnu-mcu-eclipse-arm-none-eabi-gcc-7.3.1-1.1-20180724-0637-centos64.tgz`.

2. To install the toolchain, unpack the archive and copy it to`/${HOME}/path-to-this-repo/gnu-mcu-eclipse/arm-none-eabi-gcc/` :
  1. `$ cd <this repo>`
  2. `$ mkdir gnu-mcu-eclipse` and `$ cd gnu-mcu-eclipse`
  3. `$ mkdir arm-none-eabi-gcc` and `cd arm-none-eabi-gcc`
  4. `$ tar xf ~/Downloads/gnu-mcu-eclipse-arm-none-eabi-gcc-7.3.1-1.1-20180724-0637-centos64.tgz`
  5. `$ chmod -R -w "${HOME}"/path-to-this-repo/gnu-mcu-eclipse/arm-none-eabi-gcc/7.3.1-1.1-20180724-0637`

### OpenOCD
Follow the instructions in this [link](https://gnu-mcu-eclipse.github.io/openocd/install/) to install `OpenOCD`. Example instructions:
1.  Download the latest version from this [link](https://github.com/gnu-mcu-eclipse/openocd/releases) named like `gnu-mcu-eclipse-openocd-0.10.0-8-20180512-1921-centos64.tgz`
2. To install the toolchain, unpack the archive and copy it to`/${HOME}/path-to-this-repo/gnu-mcu-eclipse/openocd/` :
  1. `$ cd <this repo>/gnu-mcu-eclipse`
  2. `$ mkdir openocd` and `cd openocd`
  3. `$ tar xf ~/Downloads/gnu-mcu-eclipse-openocd-0.10.0-8-20180512-1921-centos64.tgz`
  4. `$ chmod -R -w "${HOME}"/path-to-this-repo/gnu-mcu-eclipse/openocd/0.10.0-8-20180512-1921`

### STM32F4 Hardware Abstraction Layer
1. Mount the network drive `Sandbox (\\fsvs01)` to your Ubuntu partition. Instructions are available [here](http://wikis.olin.edu/linux/doku.php?id=accessing_windows_shares).
2. Copy `en.stm32cubef4.zip` from `Sandbox (\\fsvs01)` to your local direction somewhere.
3. Unzip the folder in the directory of this repository.

## Flashing your board
The order of commands are described in `instructions_to_load.txt` in this repository
1. Open `OpenOCD` by running your edited bash file with `bash openocd.sh`
2. Open `GDB` by running your edited bash file with `bash gdb.sh`
3. In the `GDB` terminal, connect to the chip, select the binary file you compile, and enable `semihosting` (so that you can use `printf`) by running `source gdb_src`
4. Enter `load` to load the program onto the STM32 chip.
5. Enter `c` to allow the chip to go ahead witht the program. You can find more detailed OpenOCD commands [here](http://condor.depaul.edu/glancast/373class/docs/gdb.html).

[This](https://www.segger.com/products/debug-probes/j-link/models/j-link-edu-mini/) makes a good and economical programmer when you don't have a dev board with ST-Link.


## IMPORTANT:
### You need to configure your file/folder placements exactly as described because all path in `CMake.list` is relative.

### The order in which you open `OpenOCD` and `GDB` matters
