#include <stdio.h>
#include <string.h>
#include <ctype.h>

void citire_zecimal()
{
    char c;
    int stare = 0;
    float nr;
    char buf[1000];


    FILE *f;
    f = fopen("zecimale.txt", "rt");
    if(f == NULL)
    {
        printf("Eroare la intrare\n");
        return;
    }

    /*while(fgets(buf, sizeof(buf), f) != NULL)
        {
            printf("%s", buf);
        }
*/
    c = fgetc(f);
    nr = 0;
    while(c != EOF)
    {
        if (stare == 0)
        {
            if(isdigit(c))
            {
                nr = nr*10 + (c-'0');
                stare = 1;
                c = fgetc(f);
            }
            else
            {
                stare = 0;
                c = fgetc(f);
            }
        }
        else if(stare == 1)
        {
            if(isdigit(c))
            {
                nr = nr*10 + (c - '0');
                stare = 1;
                c = fgetc(f);
            }
            else
            {
                if(c == '.')
                {
                    stare = 2;
                    c = fgetc(f);
                }
            }
        }
        else if(stare == 2)
        {
            float o = 1;
            while(isdigit(c))
            {
                nr = (nr*10 + (c - '0'))/o;
                o = o * 10;
                c = fgetc(f);
            }
            printf("%f\n", nr);
        }
    }
    fclose(f);
}

int main()
{
    citire_zecimal();

    return 0;
}
