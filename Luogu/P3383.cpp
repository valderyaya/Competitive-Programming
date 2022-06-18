//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

bool vis[100000005];
int n,q;
vector<int> p;
signed main(){Rosario
    cin>>n>>q;
    REP1(i,2,n){
        if(!vis[i]) p.em(i);
        for(auto &j:p){
            if(i*j>n)break;
            vis[i*j]=1;
            if(i%j==0) break;
        }
    }
    for(int x;q;--q){
        cin>>x;
        cout<<p[x-1]<<"\n";
    }
    return 0;
}
