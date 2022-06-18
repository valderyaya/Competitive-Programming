#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)


struct qq{
    int t,ed;
    bool operator<(const qq &x){
        return (ed-t==x.ed-x.t?ed<x.ed:ed-t<x.ed-t);
    }
}a[1001];
int n;
bool ck(int x){
    REP(i,n){
        x+=a[i].t;
        if(x>a[i].ed) return 0;
    }
    return 1;
}
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>a[i].t>>a[i].ed;
    sort(a,a+n);
    int m,l=0,r=a[0].ed-a[0].t+1;
    while(l<r){
        m=l+r>>1;
        if(ck(m)) l=m+1;
        else r=m;
    }
    cout<<l-1<<"\n";
//    system("pause");
    return 0;
}
