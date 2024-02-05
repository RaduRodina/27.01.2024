#include <stdio.h>
#include <string.h>
#include <ctype.h>

void hello_world()
{
    FILE *f;

    // 1
    f = fopen("Hello_World1.txt", "wt");
    if(f == NULL)
    {
        printf("Eroare la intrare\n");
    }
    fprintf(f, "Hello World!\n");
    fclose(f);


    // 2
    f = fopen("Hello_World2.txt", "wt");
    if(f == NULL)
    {
        printf("Eroare la intrare\n");
    }
    for(int i = 0; i < 5; i++)
    {
        fprintf(f, "Hello World!");
    }
    fprintf(f, "\n");
    fclose(f);


    //3
    f = fopen("Hello_World3.txt", "wt");
    if(f == NULL)
    {
        printf("Eroare la intrare\n");
    }
    for(int i = 0; i < 5; i++)
    {
        fprintf(f, "Hello World!\n");
    }
    fprintf(f, "\n");

    fclose(f);
}


int main()
{
    hello_world();
    return 0;
}
