#include <stdio.h>
#include <stdint.h>

unsigned long sameA(uint16_t x)
{
    uint16_t m;
    m = 0xF000;
    unsigned long c = 0;
    for(int i = 0; i < 8*sizeof(m)/4; i++)
    {
        if(x&m == 0xA000)
        {
            c++;
        }
        m = m >> 4;
    }
    return c;
}
void subSeq(unsigned k)
{
    uint16_t x[100];
    x[0] = 0x2A90;
    x[1] = 0xA0AB;
    x[2] = 0x0AA7;
    x[3] = 0x2DF9;
    x[4] = 0xBA00;
    x[5] = 0x0CD7;
    unsigned long q;
    unsigned long p;

    printf("%x\n", x[0]);

    for(int i = 0; i < k; i++)
    {
        p = i+1;
        q = 1;
        printf("p = %d q = %d\n", p, q);
        if(sameA(x[i] == sameA(x[p])))
        {
            q++;
            p++;
            printf("p = %d q = %d\n", p, q);
        }
        else
        {
            p++;
        }
        printf("p = %d q = %d\n", p, q);
    }
}

int main()
{
    unsigned int k = 5;
    subSeq(k);


    return 0;
}
