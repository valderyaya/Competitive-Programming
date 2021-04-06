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

const int z=1e7+1;
int n,x;
bitset<z> is;
vector<int> p;
int main(){Rosario
    for(int i=2;i<z;++i){
        if(!is[i]) p.em(i);
        for(auto &j:p){x=i*j;
            if(x>=z) break;
            is[x]=1;
            if(i%j==0) break;
        }
    }
    //REP(i,10) cout<<p[i]<<" \n"[i==9];
    cin>>n;
    while(n--){
        cin>>x;
        cout<<(upper_bound(ALL(p),x)-p.begin())<<"\n";
    }
    return 0;
}
