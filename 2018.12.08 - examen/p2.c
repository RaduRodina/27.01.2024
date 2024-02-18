#include <stdio.h>
#include <string.h>
#include <stdint.h>

uint32_t swap_nibbles(uint32_t n)
{
    uint32_t aux;
    aux = n;
    uint32_t a = aux & 0xF;
    uint32_t b = aux & (0xF << (8*sizeof(b) - 4));
    printf("a = %x\n", a);
    printf("b = %x\n", b);

    aux = aux & ~0xF;
    aux = aux & ~(0xF << 8*sizeof(b) - 4);

    aux = aux | (a << 8 * sizeof(b)-4);
    aux = aux | (b >> 8 * sizeof(b)-4);

    return aux;
}

uint32_t getMaxRot(uint32_t n)
{
    uint32_t aux;
    uint32_t max = 0;
    aux = n;
    for (int i = 0; i < 8*sizeof(aux) - 1; i++)
    {
        uint32_t lsb = aux & 1;
        aux = aux>>1;
        aux = aux | (lsb << 8*sizeof(aux) - 1);
        if(aux > max)
        {
            max = aux;
        }
    }
    return max;
}

int main()
{
    uint32_t x = 0x12345ABC;
    uint32_t y = swap_nibbles(x);
    printf("Rezultatul este: %x\n", y);

    uint32_t v = 0x12345678;
    uint32_t result = getMaxRot(v);
    printf("result=%x\n", result);


    return 0;
}
