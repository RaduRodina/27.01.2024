#include <stdio.h>
#include <ctype.h>

int del_max_digit(int n)
{
    int c;
    int max = -1;
    int m = n;
    int o = 1;
    int s = 0;

    // Afla cifra maxima
    while(m!=0)
    {
        c = m%10;
        if (max < c)
        {
            max = c;
        }
        m = m/10;
    }

    m = n;
    while(m!=0)
    {
        c = m % 10;
        if(c != max)
        {
            s = s + c*o;
            o = o *10;
        }
        m = m/10;
    }
    return s;
}

int append_first_odd(int n)
{
    int c;
    int m = n;
    int aux;
    while(m!=0)
    {
        c = m%10;
        if(c%2!= 0)
        {
            aux = c;
        }
        m = m/10;
    }
    return n*10 + aux;
}

void change(int n, int k)
{
    for(int i = 0; i < k; i++)
    {
        if(i%2==0)
        {
            n = del_max_digit(n);
        }
        else
        {
            n = append_first_odd(n);
        }
        printf("%d\n", n);
    }
}

int main()
{
    int n = 123456;
    int rezultat;

    rezultat = del_max_digit(n);
    printf("%d\n", rezultat);

    rezultat = append_first_odd(n);
    printf("%d\n",rezultat);

    change(n, 5);

    return 0;
}
