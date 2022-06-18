//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)
#define wait system("pause");

const int z=1e5+5;
int l[z],r[z],n,p,k,m;
void left(int x,int y){
    int pre=l[y];
    l[x]=pre, r[x]=y;
    l[y]=x , r[pre]=x;
}
void right(int x,int y){
    int nxt=r[y];
    r[y]=x, l[nxt]=x;
    l[x]=y, r[x]=nxt;
}
void del(int x){
    if(!~l[x]) return;
    int pre=l[x],nxt=r[x];
    r[pre]=nxt, l[nxt]=pre;
    l[x]=r[x]=-1;
}
int main(){Rosario
    cin>>n;
    REP1(i,0,n) l[i]=r[i]=-1;
    r[0]=1,l[1]=0;
    for(int i=2;i<=n;++i){
        cin>>k>>p;
        if(p) right(i,k);
        else left(i,k);
    }
    cin>>m;
    while(m--) cin>>k,del(k);
    for(int i=r[0];~i;i=r[i]) cout<<i<<' ';
//    system("pause");
    return 0;
}
