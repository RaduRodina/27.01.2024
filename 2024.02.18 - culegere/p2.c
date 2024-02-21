#include <stdio.h>
#include <string.h>
#include <stdint.h>

void rot_left(uint32_t n)
{
    for(int i = 0; i < 8*sizeof(n)/4; i++)
    {
        uint32_t msn = n & (0xF<<(8*sizeof(n) - 4));
        printf("msn = %x\n", msn);
        n = n << 4;
        n = n | (msn >> (8*sizeof(n) - 4));
        printf("n = %x\n", n);
    }
}

int main()
{
    uint32_t x = 0x12345678;
    rot_left(x);

    return 0;
}
