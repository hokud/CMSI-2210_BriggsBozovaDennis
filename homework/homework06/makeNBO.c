extern int isLittleEndian(void);

unsigned int makeNBO(unsigned int x) {
    if (!isLittleEndian())
        return x; // already in network(big) byte order

    return ((x & 0x000000FFu) << 24) |
           ((x & 0x0000FF00u) << 8)  |
           ((x & 0x00FF0000u) >> 8)  |
           ((x & 0xFF000000u) >> 24);
}