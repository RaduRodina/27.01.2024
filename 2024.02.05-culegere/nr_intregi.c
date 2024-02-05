#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void citire()
{
    int nr;
    char buf[1000];
    int i;

    FILE *f;
    f = fopen("Intregi.txt", "rt");
    if(f == NULL)
    {
        printf("Eroare la intrare\n");
        return;
    }

    printf("Numere intregi: ");

    while(fscanf(f, "%d", &nr) == 1)
    {
        printf("%d\n", nr);
    }

    /*while(fgets(buf, sizeof(buf), f))
    {
        i = 0;
        while(buf[i]!= '\0')
        {
            nr = 0;
            while(isdigit(buf[i]))
            {
                nr = nr*10 + (buf[i] - '0');
                i++;
            }
        }
        if(nr !=0)
        {
            printf("d\n", nr);
        }
        else
        {
            i++;
        }
    }
*/
fclose(f);
}


int main()
{
    citire();
    return 0;
}
