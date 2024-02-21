#include <stdio.h>
#include <string.h>
#include <stdint.h>

void right_shift(uint32_t n)
{
    uint32_t a;

    printf("initial n = %X\n", n);

    for(int i = 0; i < 8*sizeof(n)/4; i++)
    {
        a = n & 0xF;
        //printf("a = %x\n", a);
        n = n >> 4;
        //printf("%x\n", n);
        n = n | (a<<(8*sizeof(n)-4));
        printf("n = %X\n", n);
    }
}

int main()
{
    uint32_t x = 0x123456AB;
    right_shift(x);
    return 0;
}
