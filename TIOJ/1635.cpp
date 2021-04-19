#include <bits/stdc++.h>
#include "lib1635.h"
using namespace std;

int n,l,r,mid;
int solve(){
      l=1,r=n;
      while(r-l>1){
          mid=l+r>>1;
          if(Max(mid,mid+1)==mid) r=mid;
          else l=mid;
      }
      if(Max(l,r)==l) return l;
      return r;
}
int main(){
    n=Initialize();
    Report(solve());
}
