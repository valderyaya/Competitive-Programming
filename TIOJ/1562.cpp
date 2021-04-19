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

int l,r,n,m,a[105];
bool c(int mid){
    int cnt=0,now=0;
    REP(i,n){
        if(now+a[i]>mid){
            if(++cnt>m) return 0;
            now=a[i];
        }else now+=a[i];
    }
    return cnt<=m;
}
int main(){//Rosario
    while(cin>>n>>m){
        l=0,r=0;--m;
        REP(i,n) cin>>a[i],r+=a[i],l=max(l,a[i]);
        --l;
        while(r-l>1){
            int mid=l+r>>1;
            if(c(mid)) r=mid;
            else l=mid;
        }
        cout<<r<<"\n";
    }
    return 0;
}
