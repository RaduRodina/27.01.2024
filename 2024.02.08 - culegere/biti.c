#include <stdio.h>
#include <string.h>
#include <stdint.h>

void bitz_32bit(uint32_t n)
{
    uint32_t m;
    printf("Biti: ");
    for (int i = 8*sizeof(n)-1; i >= 0; i--)
    {
        m = (n>>i)&1;
        printf("%d ", m);
    }
    printf("\n");
}

void nr_biti_32(uint32_t n)
{
    uint32_t m;
    int c = 0;
    int count = 1;
    for(int i = 8*sizeof(n) - 1; i >= 0; i--)
    {
        m = (n>>i)&1;
        if(m == 1)
        {
            c++;
        }
        else
        {
            count++;
        }
    }
    printf("Sunt %d biti = 1\n", c);
    printf("Sunt %d biti = 0\n", count);
}

void nr_nibbles(uint32_t n)
{
    uint32_t m;
    int a = 0;
    int b = 0;
    int c = 0;

    for(int i = 8*sizeof(n)/4 - 1; i >= 0; i--)
    {

        m = (n>>(4*i))&0xF;
        printf("m = %x\n", m);
        if(m == 0xA)
        {
            a++;
        }
        else if(m == 0xB)
        {
            b++;
        }
        else if(m == 0xC)
        {
            c++;
        }
    }
    printf("Sunt %d nibbles A\n", a);
    printf("Sunt %d nibbles B\n", b);
    printf("Sunt %d nibbles C\n", c);
}

void interschimbare_nibble(uint32_t n)
{
    uint32_t m;
    uint32_t p;
    uint32_t aux;
    aux = n;

    for(int i = 8*sizeof(aux)/4-1; i>=0; i--)
    {
        for(int j = 0; j < 8*sizeof(aux)/4; j++)
        {
            if(i%2 == 0)
            {
                if(j%2 == 0)
                {
                    //Identificam nibbles de pe pozitii pare
                    m = (aux>>(4*i))&0xF;
                    p = (aux>>(4*j))&0xF;

                    //Setam nibble-ul de pe pozitia data la 0 pentru a putea aplica |
                    aux = aux & ~(0xF << (4*i));
                    aux = aux & ~(0xF << (4*j));

                    //Interschimbam
                    aux = aux | (m << (4*j));
                    aux = aux | (p << (4*i));

                }
            }
        }
    }
    printf("Numarul interschimbat: %x\n", aux);
}

void bitz_64bit(uint64_t n)
{
    uint64_t m;
    printf("Biti: ");
    for (int i = 8*sizeof(n)-1; i >= 0; i--)
    {
        m = (n>>i)&1;
        printf("%d ", m);
    }
}

void nr_biti_64(uint64_t n)
{
    uint64_t m;
    int c = 0;
    int count = 1;
    for(int i = 8*sizeof(n) - 1; i >= 0; i--)
    {
        m = (n>>i)&1;
        if(m == 1)
        {
            c++;
        }
        else
        {
            count++;
        }
    }
    printf("Sunt %d biti = 1\n", c);
    printf("Sunt %d biti = 0\n", count);
}



int main()
{
    uint32_t x;
    uint64_t y;

    printf("Introduceti numarul de 32 biti: \n");
    scanf("%x", &x);
    printf("%u %x\n", x, x);
    bitz_32bit(x);
    nr_biti_32(x);
    nr_nibbles(x);
    interschimbare_nibble(x);

    //Verificam daca caracterul nu e endline pentru ca altfel scanf nu merge
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Introduceti numarul de 64 biti: \n");
    scanf("%llx", &y);
    printf("%llu %llx\n", y, y);
    bitz_64bit(y);
    nr_biti_64(y);

    return 0;
}
