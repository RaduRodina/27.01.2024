#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


float convert(char w[])
{
    float nr = 0;
    float fr = 0.1;
    for(int i = 0; i < strlen(w); i++)
    {
        if(w[i] == '.')
        {
            i++;
            nr = nr + (w[i] - '0')*fr;
            fr = fr/10;
        }
        else
        {
            nr = nr*10 + (w[i] - '0');
        }
    }
    return nr;
}


void parcurgere()
{
    char c;
    char w[100];
    int j = 0;
    int st = 0;

    FILE *f;
    f = fopen("input_2.txt", "rt");
    if(f == NULL)
    {
        printf("Error at input\n");
        return;
    }
    c = fgetc(f);
    while(!feof(f))
    {
        printf("st=%d, c=%c\n", st, c);

        if(st == 0)
        {
            if(isdigit(c))
            {
                w[j] = c;
                j++;
                st = 1;
                c = fgetc(f);
            }
            /*else if(c == '(')
            {
                st = 4;
                c = fgetc(f);
            }
            else if(c == '[')
            {
                st = 9;
                c = fgetc(f);
            }*/
            else
            {
                st = 0;
                c = fgetc(f);
            }
        }
        else if(st == 1)
        {
            if(isdigit(c))
            {
                w[j] = c;
                j++;
                st = 1;
                c = fgetc(f);
            }
            else if(c == '.')
            {
                w[j] = c;
                j++;
                st = 2;
                c = fgetc(f);
            }
            else
            {
                st = 3;
            }
        }
        else if(st == 2)
        {
            if(isdigit(c))
            {
                w[j] = c;
                j++;
                st = 4;
                c = fgetc(f);
            }
            else
            {
                st = 3;
            }
        }
        else if(st == 3)
        {
            w[j] = 0;
            j = 0;
            float x = convert(w);
            printf("Am gasit un numar intreg: %f\n", x);
            st = 0;
            c = fgetc(f);
        }
        else if(st == 4)
        {
            if (isdigit(c))
            {
                w[j] = c;
                j++;
                st = 4;
                c = fgetc(f);
            }
            else
            {
                st = 5;
            }
        }
        else if(st == 5)
        {
            w[j] = 0;
            j = 0;
            printf("w = %s\n", w);
            float y = convert(w);
            printf("Am gasit un numar zecimal: %f\n", y);
            int q = round(y);
            printf("Numarul rotunjit: %d\n", q);
        }
    }


    fclose(f);
}


int main()
{
    parcurgere();
    return 0;
}
