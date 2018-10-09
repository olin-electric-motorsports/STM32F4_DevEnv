# STM32F4_DevEnv
STM32F4 Development Environment

## Installing CMake
Follow this [link](https://cmake.org/download/) to download the bash file for Linux and install the latest version of CMake


## Installing GNU-MCU-ECLIPSE
Follow the instructions in this [link](https://gnu-mcu-eclipse.github.io/toolchain/arm/install/#target-vs-host-platform) to install GNU MCU Eclipse ARM Embedded GCC. 

Follow the instructions in this [link](https://gnu-mcu-eclipse.github.io/openocd/install/) to install OpenOCD.

## Installing STM32F4 Hardware Abstraction Layer
1. Mount the network drive `Sandbox (\\fsvs01)` to your Ubuntu partition. Instructions are available [here](http://wikis.olin.edu/linux/doku.php?id=accessing_windows_shares).
2. Copy `en.stm32cubef4.zip` to your local direction somewhere.
3. Unzip the folder.

## IMPORTANT: You need to edit the paths in the `CMakeList.txt` to match the installation paths of the above mentioned software packages to be able to use them.
