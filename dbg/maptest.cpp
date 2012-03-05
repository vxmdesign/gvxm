#include <stdio.h>
#include <string>
#include <map>

using namespace std;

int main(){
  map<string, int> mlist;
  char bob[] = "tmp";
  mlist[string(bob)] = 5;
  printf("val %d\n", mlist["tmp"]);
  return 0;

}
