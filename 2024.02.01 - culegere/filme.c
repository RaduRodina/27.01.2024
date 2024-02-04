#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct film
{
    char titlu[50];
    char nume_regizor[50];
    char nume_actor[50];
    float rating;
    unsigned an_aparitie;
};


void prelucrare()
{
    char buf[100];
    int i;
    char w[100];
    int j;
    struct film tablou[20];
    int count = 0;

    FILE *f;
    f = fopen("filme.txt", "rt");
    if(f == NULL)
    {
        printf("Eroare la intrare\n");
    }

    while(!feof(f))
    {
        fgets(buf, sizeof(buf), f);
        printf("%s\n", buf)
        i = 0;
        j = 0;
        while(buf[i]!= 0)
        {
            if(buf[i] != ' ' && buf[i] != '\n')
            {
                buf[i] = w[j];
                w[j+1] = 0;
                j++;
            }
            else
            {
                count++;
                if(count == 1)
                {
                    film.titlu =
                }
                w[0] = 0;
                j = 0;

            }
        }
    }


    fclose(f);
}


int main()
{
    prelucrare();

    return 0;
}
