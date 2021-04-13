#include "lib1227.h"
long long* D;
int N,ck=1;
long long q[1000005];

void init(int n, long long d[]) {
  N = n;
  D = d;
  q[0]=D[0];q[1]=D[1];
  for(int i=2;i<N;i++){
      q[i]=D[i]-D[i-2];
  }
}

void change(int a, int b, long long k) {
    q[a]-=k;q[a+1]+=k;
    if((b-a)%2){
        if(b+1<N)   q[b+1]+=k;
        if(b+2<N)   q[b+2]-=k;
    }else{
        if(b+1<N)   q[b+1]-=k;
        if(b+2<N)   q[b+2]+=k;
    }
}

long long query(int c) {
    if(ck){
        for(int i=2;i<N;i++) q[i]=q[i-2]+q[i];
        ck=0;
    }
    return q[c];
}
