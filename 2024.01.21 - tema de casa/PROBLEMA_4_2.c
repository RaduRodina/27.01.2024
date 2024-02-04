#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printAvg()
{
    FILE *f;
    char buf[100];
    int i;

    float n;

    float w[100];
    int j;
    int k;

    float s;
    float avg;

    float u[100];
    int m;

    f = fopen("sample2.txt", "rt");
    if(f == NULL)
    {
        printf("Error at input");
        return;
    }

    while(fgets(buf, sizeof(buf), f))
    {
        fputs(buf, stdout);

        while(buf[i]!= 0)
        {
            i = 0;
            j = 0;
            s = 0;
            printf("%c\n", buf[i]);
            while(!isspace(buf[i]))
            {
                n = 0.0;
                if(isdigit(buf[i]))
                {
                    n = n*10.0 + (buf[i] - '0');
                    i++;
                }
                if(buf[i] == '.')
                {
                    i++;
                    if(isdigit(buf[i]))
                    {
                        n = n + (buf[i] - '0')/10.0;
                        i++;
                    }
                }
            }
            w[j] = n;
            j++;
            i++;

            //Suma
            while(w[k] != 0)
            {
                k = 0;
                s = s + w[k];
                k++;
            }

            //Media
            avg = s/(j+1);
            u[m] = avg;
            m++;
        }
    }

    //Sortare
    int aux;
    for(int p = 0; p < k - 1; i++)
    {
        if(u[p] < u[p+1])
        {
            aux = u[p];
            u[p] = u[p+1];
            u[p+1] = aux;
        }
    }

    //Afisare
    for(int i = 0; i < k; k++)
    {
        printf("%f", u[k]);
    }

    fclose(f);
}


int main()
{
    printAvg();

    return 0;
}
