#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct grup
{
    char nume[100];
    int dimensiune;
};

void increment(char *w, struct grup *grupuri, int *n)
{
    int gasit = 0;
    for(int i = 0; i < *n; i++)
    {
        if(strcmp(w, grupuri[i].nume)==0)
        {
            grupuri[i].dimensiune++;
            gasit = 1;
            break;
        }
    }

    if(gasit == 0)
    {
        strcpy(grupuri[*n].nume,w);
        grupuri[*n].dimensiune = 1;
        (*n)++;
    }
}

void prelucreaza(char *s)
{
    FILE *f;
    struct grup grupuri[100];
    // Buffer pentru linie
    int n = 0;
    char buf[80];

    f=fopen(s, "rt");
    if(f==NULL)
    {
        printf("Eroare la intrare");
        return;
    }

    // Parcurgere pe linii si colectare frecvente grupuri
    while (fgets(buf, sizeof(buf), f))
    {
        fputs(buf, stdout);
        int i = 0;
        // Variabila de stare pentru numararea campurilor
        int c = 0;
        // Tablou pentru campuri de pe o linie
        char w[100];
        int j = 0;

        while(buf[i]!=0)
        {
            if(buf[i]!=':')
            {
                w[j] = buf[i];
                w[j+1] = 0;
                j++;
            }
            else
            {
                if(c==3)
                {
                    printf("%d, %s\n", c, w);
                    increment(w, grupuri, &n);
                }

                w[0] = 0;
                j = 0;
                c++;
            }
            i++;
        }
    }
    fclose(f);

    int ni;
    do
    {
        ni = 0;

        for (int i = 0; i < n-1; i++)
        {
            if(grupuri[i].dimensiune < grupuri[i+1].dimensiune)
            {
                struct grup aux = grupuri[i];
                grupuri[i] = grupuri[i+1];
                grupuri[i+1] = aux;
                ni++;
            }
        }
    }
    while(ni>0);

    // Afisare
    for(int i = 0; i < n; i++)
    {
        printf("%s, %d\n", grupuri[i].nume, grupuri[i].dimensiune);
    }

}

int main()
{
    prelucreaza("passwd.txt");

    return 0;
}
