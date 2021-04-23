#include<bits/stdc++.h>
#include "lib1945.h"
using namespace std;

const int z=131091;
int a[z],b[z],s[z],n=131072;
int qry(int l,int r){
	return (s[r]-s[l-1])%2;
}
void solve(){
	int mid,l=1,r=n;
	while(l<r){
		mid=l+r>>1;
		if(qry(l,mid)!=Query(mid-l+1,b+l)) r=mid;
		else l=mid+1;
	}
	if(Query(1,b+l)!=qry(l,l)) a[l]=Query(1,b+l);
}
signed main(){
	Init();
	for(int i=1;i<=n;++i){
		b[i]=i-1;
		a[i]=Query(1,b+i);
		s[i]=s[i-1]+a[i];
	}
	solve();
	for(int i=1;i<=n;++i) cout<<a[i]<<' ';
	return 0;
}
