#include <stdio.h>
#include "lib1044.h"
int main(void)
{
  long long r,m,l=1;
  r = Initialize();
  ++r;
  while(l<r){
      m=l+r>>1;
      if(Guess(m)){
          if(Guess(m-1)){
              r=m;
          }else{
              Report(m);
          }
      }else{
          l=m+1;
      }
  }
  return 0;
}
