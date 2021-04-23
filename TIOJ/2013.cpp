// #ifndef LIB2013_H_INCLUDED
// #define LIB2013_H_INCLUDED
#include "lib2013.h"
#include <bits/stdc++.h>
using namespace std;
const int z=1e6+5;
#define pii pair<int,int> 
#define F first
#define S second
int fa[z],dep[z],ac[22][z];
pii fin(int x){
	if(fa[x]==x) return {x,dep[x]};
	pii res=fin(fa[x]);
	fa[x]=res.F, dep[x]+=res.S;
	return {fa[x],dep[x]};
}
int get(int i,int j){
	if(~ac[i][j]) return ac[i][j];
	ac[i-1][j]=get(i-1,j);
	return ac[i][j]=get(i-1,ac[i-1][j]);
}
void init(int n){
	for(int i=0;i<n;++i) fa[i]=i;
	for(int i=0;i<22;++i) for(int j=0;j<n;++j) ac[i][j]=-1;
}
void explore(int a, int b){
	fa[b]=a;
	ac[0][b]=a;
	dep[b]=1;
}
int run(int a, int b){
	pii x=fin(a), y=fin(b);
	if(x.F!=y.F) return 0;
	int da=x.S, db=y.S; 
	if(da>db) return 0;
	for(int i=db-da,k=0; i; i>>=1,++k)
		if(i&1) b=get(k,b);
	return a==b;
}

// int main()
// {
//   int N, Q;
//   scanf("%d%d", &N, &Q);
//   init(N);
//   while (Q--) {
//     int a, b, c;
//     scanf("%d%d%d", &a, &b, &c);
//     if (a == 2) printf("%d\n", run(b, c));
//     else explore(b, c);
//   }
// }

// #endif // LIB2013_H_INCLUDED
