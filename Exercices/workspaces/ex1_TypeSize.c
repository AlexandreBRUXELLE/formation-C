#include <stdio.h>
#include <limits.h>
#include <float.h>

void main()
{
    printf("============================================\n");
    printf("=============unsigned char==================\n");
    unsigned char ii = 0;
    int taille =  sizeof(ii);
    printf("la taille du ii est %d octets\n", taille);
    ii = 0b11111111; // 1 octets (8bits)
    printf("la valeur max de ii est %hhu  \n", ii);
    printf("la valeur min de ii est %hhu  \n", ~ii);

    printf("=============signed char====================\n");
    signed char jj = 0;
    printf("la taille du ii est %ld octets\n", sizeof(jj));
    jj = 0b01111111; // 1 octets (8bits)
    printf("la valeur max de jj est %hhi  \n", jj);
    printf("la valeur min de jj est %hhi  \n", ~jj);

    printf("la valeur de SCHAR_MIN est %hhi \n", SCHAR_MIN);

    printf("============================================\n");
    printf("=============unsigned short=================\n");
    unsigned short oo = 0;
    printf("la taille du oo est %ld octets\n", sizeof(oo));
    oo = 0b1111111111111111; // 2 octets (16bits)
    printf("la valeur max de oo est %hu  \n", oo);
    printf("la valeur min de oo est %hu  \n", ~oo);

    printf("=============signed short===================\n");
    signed short pp = 0;
    printf("la taille du pp est %ld octets\n", sizeof(pp));
    pp = 0b0111111111111111; // 2 octets (16bits)
    printf("la valeur max de pp est %hi  \n", pp);
    printf("la valeur min de pp est %hi  \n", ~pp);

    printf("la valeur de SHRT_MIN est %hi \n", SHRT_MIN);
    printf("============================================\n");
    printf("=============unsigned int===================\n");
    unsigned int rr = 0;
    printf("la taille du rr est %ld octets\n", sizeof(rr));
    rr = 0b11111111111111111111111111111111; // 4 octets (32bits)
    printf("la valeur max de rr est %u  \n", rr);
    printf("la valeur min de rr est %u  \n", ~rr);

    printf("=============signed int=====================\n");
    signed int tt = 0;
    printf("la taille du tt est %ld octets\n", sizeof(tt));
    tt = 0b01111111111111111111111111111111; // 4 octets (32bits)
    printf("la valeur max de tt est %i  \n", tt);
    printf("la valeur min de tt est %i  \n", ~tt);
    printf("la valeur de INT_MIN est %i \n", INT_MIN);

    printf("-----------------------------------------------------\n");
    printf("  /\\                                                 \n");
    printf("  ||   C integer data types on this 64-bit machine   \n");
    printf("-----------------------------------------------------\n");
    printf("\n-----------------------------------------------------\n");
    printf("  ||   C float/double data types on this 64-bit machine   \n");
    printf("  \\/                                                 \n");
    printf("-----------------------------------------------------\n");
    printf("============================================\n");
    printf("====================float===================\n");
    float uu = FLT_MAX;
    printf("la valeur de FLT_MIN est %e \n", FLT_MAX);

    printf("=================double=====================\n");
    float vv = 0;
    printf("la valeur de DBL_MIN est %e \n", DBL_MAX);


}
