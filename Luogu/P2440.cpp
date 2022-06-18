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

int n,m,a[100005],mx=0;
bool ck(int x){
    int c=0;
    REP(i,n){
        c+=a[i]/x;
        if(c>=m) return 1;
    }
    return 0;
}
inline int sol(){
    int l=0,r=mx+1,mid;
    while(l+1<r){
        mid=l+r>>1;
        if(ck(mid)) l=mid;
        else r=mid;
    }
    return l;
}
int main(){Rosario
    cin>>n>>m;
    REP(i,n) cin>>a[i],mx=max(mx,a[i]);
    cout<<sol()<<"\n";
//    system("pause");
    return 0;
}
