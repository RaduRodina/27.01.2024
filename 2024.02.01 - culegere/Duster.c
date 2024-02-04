#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct masini
{
    char numar_inamtriculare[10];
    char marca[30];
    char model[20];
    unsigned capacitate_cilindrica;
    unsigned nr_pistoane;
    unsigned nr_valve;
    unsigned putere;
    char tip[10];
};



int main()
{
    struct masini masina;
    strcpy(masina.numar_inamtriculare, "TM-03-GLK");
    strcpy(masina.marca, "Dacia");
    strcpy(masina.model, "Duster");
    masina.capacitate_cilindrica = 1598;
    masina.nr_pistoane = 4;
    masina.nr_valve = 16;
    masina.putere = 115;
    strcpy(masina.tip, "Diesel");


    printf("Numar inmatriculare: %s\n", masina.numar_inamtriculare);
    printf("Marca: %s\n", masina.marca);
    printf("Model: %s\n", masina.model);
    printf("Capacitate cilindrica: %u\n", masina.capacitate_cilindrica);
    printf("Numar pistoane: %u\n", masina.nr_pistoane);
    printf("Numar valve: %u\n", masina.nr_valve);
    printf("Putere: %u CP\n", masina.marca);
    printf("Tip: %s\n", masina.tip);

    return 0;
}
