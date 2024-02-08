#include <stdio.h>
#include <string.h>
#include <ctype.h>

void citire_cuvinte()
{
    char buf[100];
    int i;
    char w[100];
    int j = 0;;
    FILE *f;
    f = fopen("cuvinte.txt", "rt");
    if(f == NULL)
    {
        printf("Eroare la intrare\n");
        return;
    }

    while(fgets(buf, sizeof(buf), f) != NULL)
    {
        i = 0;
        printf("%s\n", buf);
        while(buf[i]!='\0')
        {
            if(isalpha(buf[i]))
            {
                w[j] = buf[i];
                printf("w[j] = %c\n", w[j]);
                j++;
            }
            else if(buf[i] == ' ' || buf[i] == '\n')
            {
                w[j] = '\0';
                j = 0;
                printf("Cuvant: %s\n", w);
            }
            i++;
        }
    }
    fclose(f);
}

int main()
{
    citire_cuvinte();

    return 0;
}
