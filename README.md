# STM32F4_DevEnv
STM32F4 Development Environment

## Installing
### CMake
Follow this [link](https://cmake.org/download/) to download the bash file for Linux and install the latest version of CMake
### GNU-MCU-ECLIPSE
Follow the instructions in this [link](https://gnu-mcu-eclipse.github.io/toolchain/arm/install/#target-vs-host-platform) to install GNU MCU Eclipse ARM Embedded GCC. 
### OpenOCD
Follow the instructions in this [link](https://gnu-mcu-eclipse.github.io/openocd/install/) to install `OpenOCD`.
### STM32F4 Hardware Abstraction Layer
1. Mount the network drive `Sandbox (\\fsvs01)` to your Ubuntu partition. Instructions are available [here](http://wikis.olin.edu/linux/doku.php?id=accessing_windows_shares).
2. Copy `en.stm32cubef4.zip` from `Sandbox (\\fsvs01)` to your local direction somewhere.
3. Unzip the folder in the directory of this repository.

## Flashing your board
1. Open `OpenOCD` by running your edited bash file with `bash openocd.sh`
2. Open `GDB` by running your edited bash file with `bash gdb.sh`
3. In the `GDB` terminal, connect to the chip, select the binary file you compile, and enable `semihosting` (so that you can use `printf`) by running `source gdb_src`
4. Enter `load` to load the program onto the STM32 chip.
5. Enter `c` to allow the chip to go ahead witht the program. You can find more detailed OpenOCD commands [here](http://condor.depaul.edu/glancast/373class/docs/gdb.html).

## IMPORTANT: 
### You need to edit the paths in the `CMakeList.txt` to match the installation paths of the above mentioned software packages to be able to use them.
### The order in which you open `OpenOCD` and `GDB` matters
