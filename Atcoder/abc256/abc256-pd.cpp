#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair

int n;
pii a[200005];
vector<pii> ans;
signed main(){valder
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i].F>>a[i].S;
    sort(a,a+n);
    int lll=a[0].F,lr=a[0].S;
    for(int i=1;i<n;++i){
        if(lr>=a[i].F) lr=max(lr,a[i].S);
        else{
            ans.push_back(mkp(lll,lr));
            lll=a[i].F, lr=a[i].S;
        }
    }
    ans.push_back(mkp(lll,lr));
    for(auto &i:ans) cout<<i.F<<' '<<i.S<<endl;
    return 0;
}
