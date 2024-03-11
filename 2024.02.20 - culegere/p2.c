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
    
    int e,f,d;

    printf("%x\n", p);
    for(int i = 0; i < 8*sizeof(x)/4/2; i++)
    {
        e=8*sizeof(x) - 4 - (4*i);
        f=4*i;

        printf("\n");
        printf("e = %d f=%d\n", e,f);

        printf("Extragere nibble: \n");
        
        m = n & (0xF << (4*i));
        // 0
        // 4
        printf("m = %x\n", m);
        
        p = n & (0xF << (8*sizeof(x) - 4 - (4*i))); 
        // 8*2 - 4 - 4*0=12
        // 8*2 - 4 - 4*1=08
        printf("p = %x\n", p);

        printf("Sterge LSN\n");
        printf("n = %x\n", n);
        n = n & ~(0xF << (4*i));
        printf("n = %x\n", n);

        printf("Sterge MSN\n");
        printf("n = %x\n", n);
        n = n & ~(0xF << (8*sizeof(x) - 4 - (4*i)));
        printf("n = %x\n", n);

        printf("Deplasare LSN\n");
        printf("p = %x\n", p);
        p = p >> (e-f);
        printf("p = %x\n", p);

        printf("Inserare LSN\n");
        printf("n = %x\n", n);
        n = n | p;
        printf("n = %x\n", n);

        printf("Deplasare MSN\n");
        printf("m = %x\n", m);
        m = m << (e-f);
        printf("m = %x\n", m);

        printf("Inserare MSN\n");
        printf("n = %x\n", n);
        n = n | m;
        printf("n = %x\n", n);
    }
}

int main()
{
    uint16_t x = 0xABCD;
    interschimbare(x);
    return 0;
}
