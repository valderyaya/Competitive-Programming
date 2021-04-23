#include<bits/stdc++.h>
#define loli 1000007
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
int boss[200005],t;
inline int read() {
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int FB(int x){
	if(boss[x]==0)return boss[x]=x;
	if(boss[x]==x)return x;
	return boss[x]=FB(boss[x]);
}
void merge(int a,int b){
	a=FB(a),b=FB(b);
	if(a==b)return;
	boss[b]=a,t--;
}
int main(){std::ios::sync_with_stdio(0) ,std::cin.tie(0),std::cout.tie(0);
	int n,m,i,a,b,F=1;
	for(n=read(),m=read(),i=0,t=2*n;i<m;++i){
		a=read(),b=read(),merge(a,b+100000),merge(a+100000,b);
		if(FB(a)==FB(b)||FB(a+100000)==FB(b+100000)||FB(a)==FB(a+100000)||FB(b)==FB(b+100000)){std::cout<<0;return 0;}
	}
	if(t>=2)for(i=1,t=t/2-1;t;--t,i*=2)while(i>=loli)i-=loli;
	else i=0;
	while(i>=loli)i-=loli;
	std::cout<<i%loli;
}
