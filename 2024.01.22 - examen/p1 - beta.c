#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

uint32_t swap_nibbles(uint32_t a, uint32_t b)
{
    uint32_t m;
    uint32_t result = 0;
    for (int i = 0; i < 8*sizeof(a)/4; i++)
    {
        if (i % 2 == 0)
        {
            m = (0xF<<(4*i)) & a;
            printf("%x\n", m);
            result = result | m;
        }
        else
        {
            m = (0xF << (4*i)) & b;
            printf("%x\n", m);
            result = result | m;
        }
    }
    return result;
}

int main()
{
    uint16_t n = 0xabcd;
    printf("%x, %d\n", n, n);
    uint32_t a = 0xA1B2C3D4;
    uint32_t b = 0x1A2B3C4D;
    uint32_t result;
    result = swap_nibbles(a, b);
    printf("Rezultatul este: %x %d\n", result);

    return 0;
}
