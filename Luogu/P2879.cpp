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

int n,pos,h,m,a[10005];
map<pii,int> mp;
signed main(){Rosario
    cin>>n>>pos>>h>>m;
    for(int l,r;m;--m){
        cin>>l>>r;
        if(l==r) continue;
        if(l>r) swap(l,r);
        if(!mp[{l,r}]){
            mp[{l,r}]=1;
            a[l+1]++, a[r]--;
        }
    }
    pos=0;
    REP1(i,1,n){
        pos+=a[i];
        cout<<h-pos<<"\n";
    }
    return 0;
}
