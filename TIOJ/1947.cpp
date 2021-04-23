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


int n,a,mi=1e9,b,d[1000005];
vector<int> v[1000005];
void dfs(int x,int p){
    d[x]=1;int mx=0;
    for(int i:v[x]){
        if(i!=p){
            dfs(i,x);
            d[x]+=d[i];
            mx=max(mx,d[i]);
        }
    }
    mx=max(mx,n-d[x]);
    mi=min(mi,mx);
}
int main(){Rosario
    cin>>n;
    REP(i,n-1) cin>>a>>b,v[a].em(b),v[b].em(a);
    dfs(0,-1);
    cout<<mi<<"\n";
//    system("pause");
    return 0;
}
// inline int read() {
//     int ret=0,f=1;char ch=getchar_unlocked();
//     while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar_unlocked();}
//     while (ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch^48),ch=getchar_unlocked();
//     return ret*f;
// }
