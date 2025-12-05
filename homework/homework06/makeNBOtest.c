// makeNBOtest.c
#include <stdio.h>

extern int isLittleEndian(void);
extern unsigned int makeNBO(unsigned int x);

int main(void) {
    unsigned int value = 0x12345678;
    unsigned int result = makeNBO(value);

    printf("System Endianness: %s-endian\n",
           isLittleEndian() ? "little" : "big");

    printf("Original:          0x%08X\n", value);
    printf("Network Byte Order:0x%08X\n", result);

    return 0;
}
