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

int l=1,r=1e9+1,mid,x;
int main(){//Rosario
    while(r-l>1){
        mid=(r-l)/2+l;
        cout<<mid<<'\n';
        cin>>x;
        if(x==0) return 0;
        else if(x==1) r=mid;
        else l=mid;
    }cout<<l<<'\n';
    return 0;
}
