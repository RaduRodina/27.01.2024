#include <stdio.h>
#include <string.h>
#include <ctype.h>

void citire(char *ex, int *i)
{
    char c;
    do
    {
         c = getchar();
         ex[*i] = c;
         (*i)++;
    }
    while(c!=10);
    ex[*i] = 0;
}
void elimina(char *ex1, char *ex2)
{
    int i = 0;
    int j = 0;
    while(ex1[i]!= 0)
    {
        if(ex1[i]!=' ')
        {
            ex2[j]=ex1[i];
            j++;
        }
        i++;
    }
    ex2[j] = 0;
}

int prelucreaza(char *ex, int n)
{
    int i = 0;
    int s = 0;

    do
    {
        int p = 1;
        do
        {
            int nr = 0;
            while(isdigit(ex[i]))
            {
                nr = nr*10 + (ex[i]-'0');
                i++;
            }

            p=p*nr;
            printf("%d %d\n", nr,p);
            i++;
            printf("%c\n", ex[i-1]);
        }
        while(ex[i-1]=='*');

        s=s+p;
        printf("%d %d\n", p, s);
        printf("%c\n", ex[i-1]);
    }
    while(ex[i-1]=='+');

    return s;
}

int main()
{
    char ex[1000];
    char ex2[1000];
    int i = 0;
    printf("Dati expresia: ");
    citire(ex, &i);
    elimina(ex,ex2);
    printf("%s", ex2);
    prelucreaza(ex2, i);
    return 0;
}

