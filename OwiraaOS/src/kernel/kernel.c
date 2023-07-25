#include <stddef.h>
#include <stdint.h>
#include <kernel/uart.h>
#include <kernel/mem.h>
#include <kernel/atag.h>
#include <kernel/kerio.h>
#include <kernel/gpu.h>
#include <common/stdlib.h>


// Control transfers from boot.S and starts here in kernel_main
void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags)
{
    char buf[256];

    // r0 r1 and r2 are function as parameters for the kernel
    (void) r0;        // r0 is not being used
    (void) r1;        // r1 is not being used
    (void) atags;     // r2 is designated for atags (info about the hardware passed from bootloader)

    puts("Initializing Memory Module...\n");
    mem_init((atag_t *) atags);
    gpu_init();

    puts("Hello, kernel World!");

    while (1) {
        gets(buf, 256);
        puts(buf);
	putc('\n');
    }
}
