#include <stddef.h>
#include <stdint.h>
#include <kernel/uart.h>
#include <common/stdlib.h>

// static?
// inline: compiler optimization
// uint32_t: unsigned integer of 32 bits from stdint
void mmio_write(uint32_t reg, uint32_t data) {

  // *(int*) ??
  // volatile: tells compiler that the register can change at any time
  *(volatile uint32_t*)reg = data;
}

uint32_t mmio_read(uint32_t reg) {

  return *(volatile uint32_t*)reg;
}

void delay(int32_t count) {

    // ???
    asm volatile("__delay_%=: subs %[count], %[count], #1; bne __delay_%=\n" : "=r"(count): [count]"0"(count) : "cc");
}

void uart_init() {

    mmio_write(UART0_CR, 0x00000000);  // Disables UART??

    mmio_write(GPPUD, 0x00000000);                  // Pull-down to ensure 0
    delay(150);

    mmio_write(GPPUDCLK0, (1 << 14) | (1 << 15));   // Apply pull-down to pins 14 and 15
    delay(150);
    mmio_write(GPPUDCLK0, 0x00000000);		    // Apply changes


    mmio_write(UART0_ICR, 0x7FF);  // Clears all interrupts

    mmio_write(UART0_IBRD, 1);  // Set Baud rate (integer)
    mmio_write(UART0_FBRD, 40); // Set Baud rate (fractional)

    // Bit 4: Sets FIFO capacity to 8 items
    // Bits 5 and 6: Data sent or recieved will be 8-bit long words
    mmio_write(UART0_LCRH, (1 << 4) | (1 << 5) | (1 << 6));

    // Disable all interrupts by setting the relevant bits
    mmio_write(UART0_IMSC, (1 << 1) | (1 << 4) | (1 << 5) | (1 << 6) |
           		   (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10));


    // Bit 1: Enable UART
    // Bit 2: Enable data reception
    // Bit 3: Enable data transmission
    mmio_write(UART0_CR, (1 << 0) | (1 << 8) | (1 << 9));

}

void uart_putc(unsigned char c) {

    // ???
    while ( mmio_read(UART0_FR) & (1 << 5)) { }

    mmio_write(UART0_DR, c);
}

unsigned char uart_getc() {

    // ???
    while( mmio_read(UART0_FR) & (1 << 4)) { }

    return mmio_read(UART0_DR);
}

void uart_puts(const char* str) {
    for (size_t i=0; str[i] != '\0'; i++) {
	uart_putc( (unsigned char) str[i] );
    }
}


