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

int n,m,ck=1;
map<pii,int> ma;
int main(){Rosario
    cin>>n>>m;
    if((n-1)*n/2<m) cout<<"Yes";
    else{
        int x,y;
        REP(i,m) {
            cin>>x>>y;
            if(x==y){ck=0;break;}
            if(x>y) swap(x,y);
            if(ma[{x,y}]++) {ck=0;break;} 
        }
        cout<<(ck?"yes":"Yes");
    }
    return 0;
}
