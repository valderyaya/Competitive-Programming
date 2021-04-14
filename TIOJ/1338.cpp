#include<bits/stdc++.h>
#include "lib1338.h"
using namespace std;
const int z=1e6+10;

long long a[21][z],mi[21][z];
void init(int N, long long C[]){
  for(int i=0;i<N;++i) a[0][i]=mi[0][i]=C[i];
  for(int j=1;j<=20;++j)
    for(int i=0;i+(1<<j)-1<N;++i){
      a[j][i]=__gcd(a[j-1][i],a[j-1][i+(1<<(j-1))]);
      mi[j][i]=min(mi[j-1][i],mi[j-1][i+(1<<(j-1))]);
    }
}
int query(int L, int R){
  int x=__lg(R-L);
  return min(mi[x][L],mi[x][R-(1<<x)])==__gcd(a[x][L],a[x][R-(1<<x)]);
}
