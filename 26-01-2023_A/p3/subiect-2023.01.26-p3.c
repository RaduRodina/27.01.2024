#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Verificam daca un caracter dat este separator
int esteSeparator(char c, char *s)
{
    for(int i=0; i < strlen(s); i++)
    {
        if(s[i] == c)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char t[100] = "Ana, are, mere.";
    char s[100] = " ,;.";
    char w[100];
    char *v[100];
    int i = 0;
    int j = 0;
    int k = 0;

    //Analizam fiecare caracter din textul t
    while(t[i]!=0)
    {
        //Daca caracterul este separator
        if(esteSeparator(t[i], s))
        {
            if(j!=0)
            {
                //Duplicam bufferul w si il inregistram in tabela de rezultate v
                v[k] = strdup(w);
                k++;

                //Resetam bufferul de lucru
                w[0] = 0;
                j = 0;
            }
        }
        else
        {
            //Daca nu e separator, caracterul analizat se adauga in bufferul w
            w[j] = t[i];
            w[j+1] = 0;
            j++;
        }
        i++;
    }
    //Afisam tabloul de pointeri la caractere
    for(i = 0; i < k; i++)
    {
        printf("%s\n", v[i]);
    }
    printf("%d",k);


    return 0;
}
