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

int n,m,d[1000005]={},p[1000005],x;
queue<pii> q;
int main(){Rosario
    cin>>n>>m;
    REP1(i,2,n) cin>>x,d[x]++,p[i]=x;
    REP1(i,1,n) if(d[i]==0) q.emplace(mkp(i,1));
    x=0;
    while(q.size()){
        x++;
        pii e=q.front();q.pop();
        if(--d[p[e.F]]==0){
            if(e.S<m) q.emplace(mkp(p[e.F],e.S+1));
        }
    }
    cout<<x<<"\n";
//    system("pause");
    return 0;
}



// inline int read() {
//     int ret=0,f=1;char ch=getchar_unlocked();
//     while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar_unlocked();}
//     while (ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch^48),ch=getchar_unlocked();
//     return ret*f;
// }
