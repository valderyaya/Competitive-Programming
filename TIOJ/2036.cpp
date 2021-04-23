#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
// #define lb(x) (x&-x)

inline ll read() {
    ll ret=0,f=1;char ch=getchar_unlocked();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar_unlocked();}
    while (ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch^48),ch=getchar_unlocked();
    return ret*f;
}
ll ans=0,n,x[3][8]={};
int main(){//Rosario
    n=read();
    for(ll i=0,a,b,c,k;i<n;i++) k=read(),a=read(),b=read(),c=read(),x[k-1][a+a+a+a+b+b+c]++;
    REP(i,8) 
        REP(j,8)
            REP(k,8) if((i|j|k)==7) ans+=x[0][i]*x[1][j]*x[2][k];
    printf("%lld\n",ans);//cout<<ans<<"\n";
//    system("pause");
    return 0;
}
