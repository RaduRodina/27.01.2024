// NU MERGE INTERSCHIMBAREA
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

void interschimbare(uint16_t x)
{
    uint16_t n;
    n = x;
    printf("%x\n", n);
    uint16_t m;
    uint16_t p;
    /*m = n & 0xF;
    printf("%x\n", m);
    p  = n & (0xF<< 8*sizeof(x) - 4);*/
    printf("%x\n", p);
    for(int i = 0; i < 8*sizeof(x)/4/2; i++)
    {
        printf("MASTI: \n");
        m = n & (0xF << (4*i));
        printf("m = %x\n", m);
        p = n & (0xF << (8*sizeof(x) - 4 - (4*i)));
        printf("p = %x\n", p);

        printf("NUMERE \n");
        n = n & ~(0xF << (4*i));
        printf("n = %x\n", n);
        n = n & ~(0xF << (8*sizeof(x) - 4 - (4*i)));
        printf("n = %x\n", n);
        n = n | (p >> (8*sizeof(x) - 4 - (4*i)));
        printf("n = %x\n", n);
        n = n | (m << (8*sizeof(x) - 4 - (4*i)));
        printf("n = %x\n", n);
    }

}

int main()
{
    uint16_t x = 0xABCD;
    interschimbare(x);

    return 0;
}
