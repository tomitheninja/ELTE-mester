#include <iostream>
#include <list>

#define in std::cin
#define out std::cout

struct Node {
  std::list<Node*> parents;
  std::list<Node*> children;
  int lastCheckedWith=-1;
    //int childLen = 0; // false data if(my parents == sib's.parents)
};

int main() {
  Node arr[1000];
  int arrLng, conLng;
  in >> arrLng >> conLng;
  for (int i = 0; i < conLng; i++) {
    int p, c; // parent, child
    in >> p >> c;
    p--;c--; // Count from 0, not 1
    arr[c].parents.push_back(&arr[p]); //childNode.parents.add(&parentNode)
    arr[p].children.push_back(&arr[c]);//parentNode.parents.add(&childNode)
  };
  int minSibVal=-1;
  int minSibPos;
  for(int n=0;n<arrLng;++n) { //for->nodes
      int howMany=0;
      for(Node* pParent : arr[n].parents) { // for->parents
          auto sibs = pParent->children;
           for(Node* sib : sibs) {    //for->siblings
               if(sib->lastCheckedWith!=n) { // 1 sib from multiple parents
                   howMany++;
                    sib->lastCheckedWith=n;
               }
           }
      }
      if(howMany>1 && (howMany<minSibVal || minSibVal==-1)) {// not just me AND (less sib || first hit)
        minSibVal=howMany;
        minSibPos=n;
      }
  };
  out << minSibPos+1;
  return 0;
}
