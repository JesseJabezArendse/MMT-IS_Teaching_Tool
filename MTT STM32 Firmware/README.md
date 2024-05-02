## MTT STM32 Firmware

To get started make sure you using the USB port with the ST-Link.

You may use STM32CubeIDE or VS Code [requires vscode for stm32 extension] to open this folder as a project to program and modify.
Or use a programmer [such as STM32CubeProgrammer] to flash the Mech_Board.elf file.

The board does nothing but display "HI" on the 7 Segment Display. but all peripherals are modularized and used in the Src/main.c file.
