#include <stdio.h>
#include <assert.h>

long findGCDfunc(long a, long b);

int main(void) {
    assert(findGCDfunc(3113041662L, 11570925L) == 462837L);
    assert(findGCDfunc(10L, 5L) == 5L);
    assert(findGCDfunc(24L, 18L) == 6L);
    assert(findGCDfunc(7L, 13L) == 1L);
    assert(findGCDfunc(0L, 5L) == 5L);
    assert(findGCDfunc(5L, 0L) == 5L);

    printf("All GCD tests passed.\n");
    return 0;
}

