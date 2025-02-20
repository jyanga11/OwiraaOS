# OwiraaOS - A Custom Operating System for Raspberry Pi Zero


## Overview

This project is an experimental, custom-built operating system for the Raspberry Pi Zero. Designed from the ground up, it explores low-level system programming, bare-metal development, and hardware interaction. While the OS remains incomplete, it serves as a strong foundation for learning about kernel development, bootloaders, and embedded systems.

### Features (Implemented & In Progress)
  - Custom Bootloader – Initializes the Raspberry Pi Zero from bare metal.
  - Basic Kernel – Handles core system operations and interrupts.
  - Minimal Device Drivers – Early-stage drivers for GPIO, UART, and basic I/O.

## Tech Stack
  - Language: C, ARM Assembly
  - Tools: GNU Arm Toolchain, QEMU, GCC, Make
  - Platform: Raspberry Pi Zero

## Lessons Learned
  - Low-Level System Programming – Understanding memory management and boot sequences.
  - ARM Architecture – Hands-on experience with ARM assembly and register-level programming.
  - Embedded Development Challenges – Debugging without an OS and handling hardware directly.

## Future Enhancements
  - Memory Management – Simple physical memory allocator.
  - Task Scheduling – Basic multitasking support.
  - File System – Develop a simple filesystem to support basic file operations.
  - Networking (Stretch Goal) – Experiment with lightweight TCP/IP stack integration.

## Impact
While this OS is a work in progress, it showcases an in-depth exploration of operating system fundamentals and embedded system design. It serves as a learning resource for developers interested in OS development, bare-metal programming, and Raspberry Pi hacking.
