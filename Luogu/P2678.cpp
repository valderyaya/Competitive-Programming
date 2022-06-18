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

int n,m,z,a[500005];
bool ck(int x){
    int cnt=0;
    for(int i=1,now=0;i<=n+1;++i)
        if(a[i]-a[now]<x) cnt++;
        else now=i;
    return cnt<=m;
}
int ret(){
    int l=1,r=z+1,mid;
    while(l+1<r){
        mid=l+r>>1;
        if(ck(mid)) l=mid;
        else r=mid;
    }
    return l;
}
int main(){Rosario
    cin>>z>>n>>m;a[n+1]=z;
    REP1(i,1,n) cin>>a[i];
    cout<<ret()<<"\n";
//    system("pause");
    return 0;
}
