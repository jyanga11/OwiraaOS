#include <stddef.h>
#include <stdint.h>
#include <kernel/uart.h>
#include <common/stdio.h>
#include <common/stdlib.h>


// Control transfers from boot.S and starts here in kernel_main
void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags)
{
    // r0 r1 and r2 are function as parameters for the kernel
    (void) r0;        // r0 is not being used
    (void) r1;        // r1 is not being used
    (void) atags;     // r2 is designated for atags (info about the hardware passed from bootloader)

    uart_init();
    uart_puts("Hello, kernel World!\r\n");

    while (1) {
        uart_putc(uart_getc());
        uart_putc('\n');
    }
}
