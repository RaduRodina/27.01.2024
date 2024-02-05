#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void citire()
{
    int stare=0;
    char c;
    int nr=0;

    FILE *f;
    f = fopen("intregi.txt", "rt");
    if(f == NULL)
    {
        printf("Eroare la intrare\n");
        return;
    }

    c=fgetc(f);
    while(!feof(f))
    {
        //printf("stare=%d c=%d\n",stare,c);
        // facem automat cu mai multe stari
        // starea initiala
        if(stare==0)
        {
            if(isdigit(c))
            {
                // daca gasim o cifra intram in starea 1 si acolo cumulam
                nr=nr*10+c-'0';
                stare=1;
                c=fgetc(f);
            }
            else
            {
                // ramanem in starea 0 si ignoram tot ce nu este cifra
                stare=0;
                c=fgetc(f);
            }
        }
        else if(stare==1)
        {
            if(isdigit(c))
            {
                // daca gasim o cifra ramanem in starea 1 si cumulam
                nr=nr*10+c-'0';
                stare=1;
                c=fgetc(f);
            }
            else
            {
                // trecem in starea 2 si raportam
                stare=2;
            }
        }
        else if(stare==2)
        {
            printf("n=%d\n",nr);
            nr=0;
            stare=0;
        }
    }
    fclose(f);
}

int main()
{
    citire();
    return 0;
}
