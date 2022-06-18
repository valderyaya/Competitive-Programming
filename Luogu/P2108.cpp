#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)


struct qq{
    ll c,v;
    bool operator<(const qq &a)const{
        return c<a.c;
    }
}a[2000005];
ll n,m,sum=0,re=0;
int main(){Rosario
    cin>>n>>m;
    REP(i,m) cin>>a[i].c>>a[i].v;
    sort(a,a+m);
    for(int i=0;i<m&&re<n;i++){
        sum+=a[i].c*min(n-re,a[i].v);
        re+=min(n-re,a[i].v);
    }cout<<sum<<"\n";
//    system("pause");
    return 0;
}
