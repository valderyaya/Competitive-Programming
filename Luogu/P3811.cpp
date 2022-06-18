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
#define Rosario ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)


ll n,p,inv[3000005];
inline void build(){
    inv[1]=1;cout<<"1\n";
    REP1(i,2,n){inv[i]=(p-p/i)*inv[p%i]%p;
        cout<<inv[i]<<"\n";
    }
}
int main(){Rosario
    cin>>n>>p;
    build();
    return 0;
}
