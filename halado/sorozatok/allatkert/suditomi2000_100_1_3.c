#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 25

// A = Animal
typedef unsigned int uint;
#ifndef __cplusplus
    typedef unsigned char bool;
    enum boolean { false, true };
#endif

struct A
{
    char type[MAX_STRING_LENGTH];
    uint num;
};

struct A* readZoo(uint* num)
{
    scanf("%u", num);
    struct A *as = malloc(sizeof(struct A) * (*num));
    for(uint i=0; i<*num; i++)
    {
        scanf("%s %u", as[i].type, &as[i].num);
    }
    return as;
}

int main()
{
    uint numA1, numA2;
    struct A
            *zoo1 = readZoo(&numA1),
            *zoo2 = readZoo(&numA2);
    uint minSwap, minGift;
    scanf("%u %u", &minSwap, &minGift);

    /*
     * 1: Both zoo has at least minSwap of the same type
     * 2: zooX has minGift of type, other has 0

     * print swap when found, store gifts
    */

    bool
            *swapAnimal = malloc(numA1),
            *giftByZoo1 = malloc(numA1),
            *giftByZoo2 = malloc(numA2);

    for(uint i=0; i<numA1; i++) // Filter swap && gift zoo1 -> zoo2
    {
        swapAnimal[i] = false;
        bool notFoundInZoo2 = true;
        for(uint j=0; notFoundInZoo2 && j<numA2; j++)
        {
            if (strcmp(zoo1[i].type, zoo2[j].type) == 0) // same type
            {
                swapAnimal[i] = zoo1[i].num >= minSwap && zoo2[j].num >= minSwap; // filter swapanimal
                notFoundInZoo2 = false; // filter gift zoo1 -> zoo2
            }
        }
        giftByZoo1[i] = notFoundInZoo2 && zoo1[i].num >= minGift;
    }

    for(uint i=0; i<numA2; i++)
    {
        if(zoo2[i].num < minGift)
        {
            giftByZoo2[i] = false;
            continue;
        }
        bool notFoundInZoo1 = true;
        for(uint j=0; notFoundInZoo1 && j<numA1; j++)
        {
           notFoundInZoo1 = strcmp(zoo1[j].type, zoo2[i].type) != 0; // filter gift zoo2 -> zoo1
        }
        giftByZoo2[i] = notFoundInZoo1 ;
    }

    /* print out */
    /* swaps */
    for(uint i=0; i<numA1; i++) if(swapAnimal[i]) printf("%s ",zoo1[i].type);
    printf("\n");

    /* gift zoo1 -> zoo2 */
    for(uint i=0; i<numA1; i++) if(giftByZoo1[i]) printf("%s ",zoo1[i].type);
    printf("\n");

    /* gift zoo2 -> zoo1 */
    for(uint i=0; i<numA2; i++) if(giftByZoo2[i]) printf("%s ",zoo2[i].type);
    printf("\n");

    return 0;
}
