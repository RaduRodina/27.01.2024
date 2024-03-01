//MAI AM DE LUCRAT
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int my_round(char w[])
{
    printf("--DEBUG MY_ROUND--\n");
    int i = 0;
    int nr = 0;
    int st = 0;
    int after_point = 0;

    while(w[i] != '\0')
    {
        printf("st=%d, c=%c, nr=%d\n", st, w[i], nr);

        if(st == 0)
        {
            if(isdigit(w[i]))
            {
                nr = nr*10 + (w[i] - '0');
                st = 1;
                i++;
            }
            else
            {
                printf("ERROR\n");
                break;
            }
        }
        else if(st == 1)
        {
            if(isdigit(w[i]))
            {
                nr = nr*10 + (w[i] - '0');
                i++;
            }
            else if(w[i] == '.')
            {
                st = 2;
                i++;

            }
            else
            {
                st = 0;
            }
        }
        else if(st == 2)
        {
            if(isdigit(w[i]))
            {
                after_point = after_point*10 + (w[i] - '0');
                if(after_point >= 5)
                {
                    nr = nr + 1;
                }
                else
                {
                    nr = nr;
                }
            }
        }
        i++;
    }
    printf("--FIN--\n");
    return nr;
}


void parcurgere()
{
    char c;
    char w[100];
    int j = 0;
    int st = 0;

    FILE *f;
    f = fopen("input.txt", "rt");
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
            printf("w = '%s\n", w);
            int x = my_round(w);
            printf("Am gasit un numar intreg: %d\n", x);
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
            printf("Am gasit un nr zecimal: %s\n", w);
            int y = my_round(w);
            printf("Numarul rotunjit: %d\n", y);
            st = 0;
            c = fgetc(f);
        }
    }


    fclose(f);
}


int main()
{
    parcurgere();
    return 0;
}

