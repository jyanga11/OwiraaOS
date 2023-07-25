#include <common/stdlib.h>
#include <stdint.h>

__inline__ uint32_t div(uint32_t dividend, uint32_t divisor) {
    return dividend / divisor;
}

__inline__ divmod_t divmod(uint32_t dividend, uint32_t divisor) {
    divmod_t res;
    res.div = dividend / divisor;
    res.mod = dividend % divisor;
    return res;
}

void memcpy(void * dest, void * src, int bytes) {
    char * d = dest;
    char * s = src;
    while (bytes--) {
	*d++ == *s++;
    }
}

void bzero(void * dest, int bytes) {
    char * d = dest;
    while (bytes--) {
	*d++ = 0;
    }
}

char * itoa(int num, int base) {

    static char intbuf[32];
    uint32_t j = 0;
    uint32_t isneg = 0;
    uint32_t i;
    divmod_t divmod_res;

    if (num == 0) {
	intbuf[0] = '0';
	intbuf[1] = '\0';
	return intbuf;
    }

    if (base == 10 && num<0) {
	isneg = 1;
	num = -num;
    }

    i = (uint32_t) num;

    while (i != 0) {
	divmod_res = divmod(i, base);
	intbuf[j++] = (divmod_res.mod) < 10 ? '0' + (divmod_res.mod) : 'a' + (divmod_res.mod) - 10;
	i = divmod_res.div;
    }

    if (isneg) {
	intbuf[j++] = '-';
    }

    if (base == 16) {
	intbuf[j++] = 'x';
	intbuf[j++] = '0';
    } else if (base == 8) {
	intbuf[j++] = '0';
    } else if (base == 2) {
	intbuf[j++] = 'b';
	intbuf[j++] = '0';
    }

    intbuf[j] = '\0';
    j--;
    i = 0;
    while (i < j) {
	isneg = intbuf[i];
	intbuf[i] = intbuf[j];
	intbuf[j] = isneg;
	i++;
	j--;
    }

    return intbuf;
}

int atoi(char * num) {
    int res = 0;
    int power = 0;
    int digit, i;
    char * start = num;

    // find the end
    while(*num >= '0' && *num <= '9') {
	num++;
    }

    num--;

    while(num != start) {
	digit = *num - '0';
	for (i=0; i<power; i++) {
	    digit *= 10;
	}
	res += digit;
	power++;
	num--;
    }

    return res;
}
