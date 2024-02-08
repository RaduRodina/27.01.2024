#include <stdio.h>
#include <string.h>
#include <ctype.h>

void citire_identificatori()
{
    char buf[100];
    int i;
    char w[100];
    int j;
    int stare = 0;

    FILE *f;
    f = fopen("identificatori.txt", "rt");
    if(f == NULL)
    {
        printf("Eroare la intrare\n");
        return;
    }

    while(fgets(buf, sizeof(buf), f) != NULL)
    {
        printf("%s\n", buf);
        i = 0;
        j = 0;
        while(buf[i] != 0)
        {
            do
            {
                if(stare == 0)
                {
                    if(isalpha(buf[i]))
                    {
                        w[j] = buf[i];
                        printf("w[j] = %c\n", w[j]);
                        j++;
                        i++;
                        stare = 1;
                    }
                    else
                    {
                        stare = 0;
                        i++;
                    }
                }
                else if(stare == 1)
                {
                    if(isalnum(buf[i]))
                    {
                        w[j] = buf[i];
                        printf("w[j] = %c\n", w[j]);
                        j++;
                    }
                    else if(buf[i] == ' ' || '\n')
                    {

                        stare = 0;
                        w[j] = 0;
                        j = 0;
                        printf("%s\n", w);
                    }
                }
            }
            while(buf[i-1] == ' ');
            i++;
        }

    }
}


int main()
{
    citire_identificatori();

    return 0;
}
