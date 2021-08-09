#define DEBUG 0
#include <iostream>
#if DEBUG
    #include <fstream>
    #define __DIR__ "/home/tomi/Dropbox/Qt Projects/NemesTihamer/Kozephalado/Szulok/legkevesebbGyerek"
    std::fstream inFile(__DIR__"/minta/be2.txt");
    #define in inFile
    #define out std::cout
#else
    #define in std::cin
    #define out std::cout
#endif


int main() {
  int arr[1000]{};
  int arrLng, conLng;
  in >> arrLng >> conLng;
  for (int i=0;i<conLng;i++) {
    int p, c;
    in >> p >> c;
    arr[p-1]++; // array is indexed from 0
  }
  int minI = -1;
  for (int i=0; i<arrLng;i++) {
      if(minI==-1){ // not found child previously
          if(arr[i]) // now found node with child
              minI=i;
      } else if(arr[i] && arr[i] < arr[minI]) // Found node with less child
          minI=i;
  }
  out << minI + 1;
  return 0;
}
