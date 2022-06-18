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

const int z=1e5+5;
int prv[z],nxt[z],n,a[z];
int main(){Rosario
    cin>>n;
    int x;
    REP1(i,1,n){
        cin>>a[i];
        nxt[a[i-1]]=a[i];
        prv[a[i]]=a[i-1];
    }
    for(int i=n;i;--i)
        if(nxt[i]){
            cout<<i<<' '<<nxt[i]<<' ';
            nxt[prv[i]]=nxt[nxt[i]];
            prv[nxt[prv[i]]]=prv[i];
            nxt[nxt[i]]=0;
        }
    return 0;
}
