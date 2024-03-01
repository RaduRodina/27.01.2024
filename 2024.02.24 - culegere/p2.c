//MAI AM DE LUCRAT
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float convert(char w[])
{
    printf("--DEBUG CONVERT--\n");
    int i = 0;
    int st = 0;
    float nr = 0;
    float o = 1; // float o SE RESETEAZA LA 0 MEREU, NU INTELEG DE CE :( 

    while(w[i]!= 0)
    {
        printf("st=%d, c=%c, nr=%f, i=%d, o=%f\n", st, w[i], nr, i);
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
                st = 1;
            }
            else if(w[i] == '.')
            {
                i++;
                st = 2;
            }
        }
        else if(st == 2)
        {
            if(isdigit(w[i]))
            {
                nr = nr*10 + (w[i]- '0')/(float)o;
                o = o*10;
                i++;
                st = 3;
            }
            else
            {
                printf("ERROR\n");
                break;
            }
        }
        else if(st == 3)
        {
            if(isdigit(w[i]))
            {
               nr = nr*10 + (w[i] - '0')/(float)o;
               o = o*10;
               i++;
               st = 3;
            }
            else
            {
                st = 0;
            }
        }
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
            else if(c == '(')
            {
                st = 6;
                c = fgetc(f);
            }
            /*else if(c == '[')
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
                printf("ERROR(invalid input)\n");
                st = 0;
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
            int x = (int)round(convert(w));
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
            int y = (int)round(convert(w));
            printf("Numarul rotunjit: %d\n", y);
            st = 0;
            c = fgetc(f);
        }
        else if(st == 6)
        {
            if(isdigit(c))
            {
                w[j] = c;
                j++;
                st = 7;
                c = fgetc(f);
            }
            else if(c == ')')
            {
                st = 12;
            }
            else
            {
                st = 6;
                c = fgetc(f);
            }
        }
        else if(st == 7)
        {
            if(isdigit(c))
            {
                w[j] = c;
                j++;
                st = 7;
                c = fgetc(f);
            }
            else if(c == '.')
            {
                w[j] = c;
                j++;
                st = 8;
                c = fgetc(f);
            }
            else
            {
                st = 10;
            }
        }
        else if(st == 8)
        {
            if(isdigit(c))
            {
                w[j] = c;
                j++;
                st = 9;
                c = fgetc(f);
            }
            else
            {
                printf("ERROR (invalid input)\n");
                st = 6;
            }
        }
        else if(st == 9)
        {
            if(isdigit(c))
            {
                w[j] = c;
                j++;
                st = 9;
                c = fgetc(f);
            }
            else
            {
                st = 11;
            }
        }
        else if(st == 10)
        {
            w[j] = 0;
            j = 0;
            printf("Am gasit un nr intreg: %s\n", w);
            int x = (int)round(convert(w));
            printf("Numarul rotunjit: %d", x);
            st = 6;
            c = fgetc(f);
            if(c == ')')
            {
                st = 12;
            }
            else
            {
                st = 6;
            }
        }
        else if(st == 11)
        {
            w[j] = 0;
            j = 0;
            printf("Am gasit un nr zecimal: %s\n", w);
            int y = (int)ceil(convert(w));
            printf("Numarul rotunjit: %d\n", y);
            c = fgetc(f);
            if(c == ')')
            {
                st = 12;
            }
            else
            {
                st = 6;
            }
        }
        else if(st == 12)
        {
            w[j] = 0;
            j = 0;
            printf("Am incheiat de parcurs o paranteza\n");
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

