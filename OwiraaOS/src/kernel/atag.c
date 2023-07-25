#include <kernel/atag.h>

uint32_t get_mem_size(atag_t * atag) {
        
    return (uint32_t) 1024 * 1024 * 1000;

    /*
    while (atag->tag != NONE) {
	if (atag->tag == MEM) {
	    return atag->mem.size;
	}
	atag = ((uint32_t*) atag) + atag->tag_size;
    }
    return 0;
    */

}
