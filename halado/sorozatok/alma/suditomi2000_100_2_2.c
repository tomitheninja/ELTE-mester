#include <stdio.h>

#define MAX_TYPE_AMOUNT 10000

typedef unsigned int uint;
typedef unsigned char bool;
enum boolean { false, true };

struct Product {
  unsigned short int numAvaliable; // Contains amount that got sold
  unsigned short int numWantBuy;
};

int main(void) {
  uint numForSell, numForBuy;
  uint numTypeSold = 0, numTypeNotSold = 0;
  struct Product types[MAX_TYPE_AMOUNT] = {0};

  scanf("%u", &numForSell);
  for (uint i = 0; i < numForSell; i++) {
    uint type;
    scanf("%u", &type);
    scanf("%hu", &types[type].numAvaliable);
  }

  scanf("%u", &numForBuy);
  for (uint i = 0; i < numForBuy; i++) {
    uint type;
    scanf("%u", &type);
    scanf("%hu", &types[type].numWantBuy);
    if (types[type].numAvaliable != 0) {
      numTypeSold += 1;
    }
  }

  for (uint i = 0; i < MAX_TYPE_AMOUNT; i++) {
    struct Product x = types[i];
    if (x.numAvaliable > x.numWantBuy) {
      numTypeNotSold += 1;
    }
  }
  printf("%u ", numTypeNotSold);
  for (uint i = 0; i < MAX_TYPE_AMOUNT; i++) {
    struct Product x = types[i];
    if (x.numAvaliable > x.numWantBuy) {
      printf("%u %u ", i, x.numAvaliable - x.numWantBuy);
    }
  }
  printf("\n");
  printf("%u ", numTypeSold);
  for (uint i = 0; i < MAX_TYPE_AMOUNT; i++) {
    struct Product x = types[i];
    if (x.numAvaliable != 0 && x.numWantBuy != 0) {
      printf("%u %u ", i,  x.numAvaliable < x.numWantBuy ? x.numAvaliable : x.numWantBuy);
    }
  }
  printf("\n");
  return 0;
}
