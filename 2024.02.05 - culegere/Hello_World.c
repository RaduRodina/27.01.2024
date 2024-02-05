#include <stdio.h>
#include <string.h>
#include <ctype.h>

void hello_world()
{

    FILE *f;
    f = fopen("Hello_World.txt", "w");
    if(f == NULL)
    {
        printf("Eroare la intrare\n");
    }
    //1

    fprintf(f, "Hello World!\n");

    //2

    for(int i = 0; i < 5; i++)
    {
        fprintf(f, "Hello World!");
    }
    fprintf(f, "\n");

    //3

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
