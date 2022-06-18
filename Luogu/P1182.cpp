//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int a[100005],n,m;
ll l,r;
bool ck(ll mid){
    ll c=0,s=0;
    REP1(i,1,n){
        if(s+a[i]>mid){
            ++c,s=a[i];
            if(c>=m) return 0;
        }else s+=a[i];
    }
    return 1;
}
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) cin>>a[i],r+=a[i],l=max(l,(ll)a[i]);
    while(l<r){
        ll mid=l+r>>1;
        if(ck(mid))  r=mid;
        else l=mid+1;
    }
    cout<<l<<"\n";
    return 0;
}
