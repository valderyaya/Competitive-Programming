#pragma GCC optimize("O2")
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


ll ans;
int X,Y,n,pos=-1;
vector<int> a,b;
signed main(){valder
    cin>>n>>X>>Y;
    for(int x,i=1;i<=n;++i){
        cin>>x;
        if(x>X||x<Y){
            a.clear(); b.clear();
            pos=-1;
            continue;
        }
        if(!~pos) pos=i-1;
        if(x==X) a.em(i);
        if(x==Y) b.em(i);
        if(X==Y&&!a.empty()) ans+=a.size();
        else if(X!=Y&&!a.empty()&&!b.empty()) ans+=min(a.back(),b.back())-pos;
    }
    cout<<ans;
}
