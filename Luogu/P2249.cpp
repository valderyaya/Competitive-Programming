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

int n,m,a[1000005];
inline int sol(int x){
    int l=0,r=n,mid;
    while(l<r){
        mid=l+r>>1;
        if(a[mid]>=x) r=mid;
        else l=mid+1;
    }
    return a[l]==x?l+1:-1;
}
int main(){Rosario
    cin>>n>>m;int x;
    REP(i,n) cin>>a[i];
    while(m--) cin>>x,cout<<sol(x)<<' ';
//    system("pause");
    return 0;
}
