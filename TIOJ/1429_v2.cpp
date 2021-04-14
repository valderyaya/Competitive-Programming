#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(register int i=l;i<=r;++i)
#define FOR(i,l,r) for(register int i=l;i>=r;--i)
#define MAXN 100001
int N,M,f[MAXN],a[MAXN],b[MAXN],siz[MAXN],rt[MAXN],ls[MAXN],rs[MAXN],dis[MAXN];ll sum[MAXN],ans;
void get(int &x){x=0;char c=getchar_unlocked();while(c<'0'||c>'9')c=getchar_unlocked();while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar_unlocked();}
int mrg(int x,int y){if(!x||!y)return x|y;if(a[x]<a[y])x^=y^=x^=y;rs[x]=mrg(rs[x],y);if(dis[ls[x]]<dis[rs[x]])swap(ls[x],rs[x]);dis[x]=dis[rs[x]]+1;return x;}
void pop(int x){sum[x]-=a[rt[x]],rt[x]=mrg(ls[rt[x]],rs[rt[x]]),--siz[x];}
int main(){
	cin>>N>>M;For(i,1,N)get(f[i]),get(a[i]),get(b[i]),ans=max(ans,1ll*b[i]),rt[i]=i,sum[i]=a[i],siz[i]=1;
	FOR(i,N,2){rt[f[i]]=mrg(rt[f[i]],rt[i]),sum[f[i]]+=sum[i],siz[f[i]]+=siz[i];while(sum[f[i]]>M)pop(f[i]);ans=max(ans,1ll*siz[f[i]]*b[f[i]]);}
	cout<<ans;return 0;}
