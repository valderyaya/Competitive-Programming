#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define oi ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

int n,a[200005],t,ans=1e9,tim[200005];
bitset<200005> vis , col;
inline int read() {
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void init(){
    REP1(i,1,n){
        tim[i]=0;
    }
    col.reset();
    t=0;
}
int main(){
    //oi;
    n=read();
    REP1(i,1,n) a[i]=read();
    REP1(i,1,n){
        if(!vis[i]){
            init();
            for(int j=i;;j=a[j]){
                if(col[j]){
                    ans=min(ans,t-tim[j]+1);
                    break;
                }
                if(vis[j]) break;
                vis[j]=1;
                col[j]=1;
                tim[j]=++t;
            }
        }
    }
    printf("%d\n",ans);
//    system("pause");
    return 0;
}
