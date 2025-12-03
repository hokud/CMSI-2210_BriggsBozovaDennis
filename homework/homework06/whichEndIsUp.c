
#include <stdio.h>

int main(void) {
    unsigned int x = 1;
    unsigned char *p = (unsigned char *)&x;

    if (*p == 1) {
        printf("This machine is little-endian.\n");
    } else {
        printf("This machine is big-endian.\n");
    }

    return 0;
}

