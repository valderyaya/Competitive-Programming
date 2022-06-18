//#pragma GCC optimize("Ofast")
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
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

vector<int> v;
int n,f[105],a[105],mx=0;
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>a[i];
    REP(i,n){
        if(v.size()&&v.back()>=a[i]) v[lower_bound(ALL(v),a[i])-v.begin()]=a[i];
        else v.em(a[i]);
        f[i]=v.size();
    }v.clear();
    for(int i=n-1;i>=0;i--){
        if(v.size()&&v.back()>=a[i]) v[lower_bound(ALL(v),a[i])-v.begin()]=a[i];
        else v.em(a[i]);
        mx=max(mx,f[i]+(int)v.size()-1);
    }
    cout<<n-mx<<"\n";
//    system("pause");
    return 0;
}
