#include <stddef.h>
#include <stdint.h>

#ifndef UART_H
#define UART_H

void mmio_write(uint32_t reg, uint32_t data);
uint32_t mmio_read(uint32_t reg);
void delay(int32_t count);

enum
{
    // The GPIO registers base address.
    GPIO_BASE = 0x3F200000, // 0x20200000 for raspi0

    GPPUD = (GPIO_BASE + 0x94),       // Pull-up/Pull-down register
    GPPUDCLK0 = (GPIO_BASE + 0x98),   // Register to apply GPPUD to specified GPIO pins

    // The base address for UART.
    UART0_BASE = 0x3F201000, // 0x20201000 for raspi0

    // UART Registers
    UART0_DR     = (UART0_BASE + 0x00),  // Holds data for recieveing and transmitting
    UART0_RSRECR = (UART0_BASE + 0x04),  // Status about recieved data
    UART0_FR     = (UART0_BASE + 0x18),  // Contains flag bits to indicate conditions
    UART0_ILPR   = (UART0_BASE + 0x20),  // 
    UART0_IBRD   = (UART0_BASE + 0x24),  // Integer Baud rate divisor
    UART0_FBRD   = (UART0_BASE + 0x28),  // Fractional Baud rate divisor
    UART0_LCRH   = (UART0_BASE + 0x2C),  // Controls parameters of transmission
    UART0_CR     = (UART0_BASE + 0x30),  // Control Register
    UART0_IFLS   = (UART0_BASE + 0x34),  // Controls FIFO interrupt trigger levels
    UART0_IMSC   = (UART0_BASE + 0x38),  // Enable/Disable specific UART interrupts
    UART0_RIS    = (UART0_BASE + 0x3C),  // Raw status of UART interrupts
    UART0_MIS    = (UART0_BASE + 0x40),  // Masked status of UART interrupts
    UART0_ICR    = (UART0_BASE + 0x44),  // Clears UART interrupts
    UART0_DMACR  = (UART0_BASE + 0x48),
    UART0_ITCR   = (UART0_BASE + 0x80),
    UART0_ITIP   = (UART0_BASE + 0x84),
    UART0_ITOP   = (UART0_BASE + 0x88),
    UART0_TDR    = (UART0_BASE + 0x8C),
};

void uart_init();

void uart_putc(unsigned char c);
unsigned char uart_getc();
void uart_puts(const char* str);

#endif
