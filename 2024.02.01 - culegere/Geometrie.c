#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Definim punctele pe axa xOy
struct punct_2d
{
    int x;
    int y;
};

struct punct_3d
{
    int x;
    int y;
    int z;
};

// Definim patrulaterul avand un nume si un sir de 4 puncte.
struct patrulater
{
    char nume[100];
    struct punct_2d puncte[4]
};

struct corp_3d
{
    char nume[100];
    struct punct_3d puncte[8];
};

void patrulater(struct punct_2d a, struct punct_2d b, struct punct_2d c, struct punct_2d d)
{
    // Construim patrulaterul

    struct patrulater patrulater1;

    strcpy(patrulater1.nume, "Patrulater1");
    printf("Numele patrulaterului este: %s\n", patrulater1.nume);

    patrulater1.puncte[0] = a;
    patrulater1.puncte[1] = b;
    patrulater1.puncte[2] = c;
    patrulater1.puncte[3] = d;

    printf("Acesta are 4 puncte: \n");

    for(int i = 0; i < 4; i++)
    {
        printf("(%d, %d)\n", patrulater1.puncte[i].x, patrulater1.puncte[i].y);
    }
}

void corp_3d(struct punct_3d a, struct punct_3d b, struct punct_3d c, struct punct_3d d, struct punct_3d e, struct punct_3d f, struct punct_3d g, struct punct_3d h)
{
    //Construim corpul 3d

    struct corp_3d cub;

    strcpy(cub.nume, "Cub1");
    printf("Numele corpului 3d este: %s\n", cub.nume);

    cub.puncte[0] = a;
    cub.puncte[1] = b;
    cub.puncte[2] = c;
    cub.puncte[3] = d;
    cub.puncte[4] = e;
    cub.puncte[5] = f;
    cub.puncte[6] = g;
    cub.puncte[7] = h;

    printf("Acesta are 8 puncte: \n");
    for(int i = 0; i < 8; i++)
    {
        printf("(%d, %d, %d)\n", cub.puncte[i].x, cub.puncte[i].y, cub.puncte[i].z);
    }

}

int main()
{
        // Initializam punctele 2d

    struct punct_2d p1 = {1, 2};
    struct punct_2d p2 = {3, 4};
    struct punct_2d p3 = {5, 6};
    struct punct_2d p4 = {7, 8};

    //Initalizam punctele 3d

    struct punct_3d a1 = {0, 0, 0};
    struct punct_3d a2 = {1, 0, 0};
    struct punct_3d a3 = {1, 1, 0};
    struct punct_3d a4 = {0, 1, 0};
    struct punct_3d a5 = {0, 0, 1};
    struct punct_3d a6 = {1, 0, 1};
    struct punct_3d a7 = {1, 1, 1};
    struct punct_3d a8 = {0, 1, 1};


    patrulater(p1, p2, p3, p4);
    corp_3d(a1, a2, a3, a4, a5, a6, a7, a8);


    return 0;
}
