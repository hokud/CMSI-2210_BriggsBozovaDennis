 int isLittleEndian(void) {
    unsigned int x = 1;
    unsigned char *p = (unsigned char *)&x;

    if (*p == 1)
        return 1;   // little-endian
    else
        return 0;   // big-endian
}