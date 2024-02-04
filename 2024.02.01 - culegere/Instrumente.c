#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct chitara_s
{
    char marca[20];
    unsigned int nr_corzi;
    char tip[20];
};

struct baterie_s
{
    char marca[20];
    unsigned nr_tobe;
};

 struct sintetizator_s
 {
     char marca[20];
     unsigned nr_octave;
 };

 struct instrumente_s
 {
     struct chitara_s chitara;
     struct baterie_s baterie;
     struct sintetizator_s sintetizator;
 };

int main()
{
    struct instrumente_s set_instrumente;

    strcpy(set_instrumente.chitara.marca, "Yamaha");
    set_instrumente.chitara.nr_corzi = 6;
    strcpy(set_instrumente.chitara.tip, "acustica");

    strcpy(set_instrumente.baterie.marca, "Epiphone");
    set_instrumente.baterie.nr_tobe = 5;

    strcpy(set_instrumente.sintetizator.marca, "Yamaha");
    set_instrumente.sintetizator.nr_octave = 61;

    printf("Chitara este: \n");
    printf("De marca: %s\n", set_instrumente.chitara.marca);
    printf("Are: %u corzi\n", set_instrumente.chitara.nr_corzi);
    printf("Este de tip: %s\n", set_instrumente.chitara.tip);
    printf("\n");

    printf("Bateria este: \n");
    printf("De marca: %s\n", set_instrumente.baterie.marca);
    printf("Are: %u tobe\n", set_instrumente.baterie.nr_tobe);
    printf("\n");

    printf("Sintetizatorul este: \n");
    printf("De marca: %s\n", set_instrumente.sintetizator.marca);
    printf("Are: %u octave\n", set_instrumente.sintetizator.nr_octave);
    printf("\n");

    return 0;
}
