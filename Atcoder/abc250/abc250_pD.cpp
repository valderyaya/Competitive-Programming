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
#define endl "\n"

bitset<1000005> no;
vector<ll> p,p3;
ll n,ans;
signed main(){valder
    cin>>n;
    p.em(1); p3.em(1);
    for(ll i=2;i<1000000;++i){
        if(!no[i]){
            p.em(i);
            p3.em(i*i*i);
        }
        for(ll j=1;j<p.size();++j){
            if(i*p[j]>1000000) break;
            no[i*p[j]]=1;
            if(i%p[j]==0) break;
        }
    }
    //for(int i=1;i<10;++i) cout<<p[i]<<' '<<p3[i]<<endl;
    for(ll i=lower_bound(ALL(p3),n)-p3.begin()-1; i>0; --i){
        ll key = n/p3[i], it = lower_bound(p.begin(),p.begin()+i-1,key)-p.begin();
        ans += (p[it]*p3[i]>n?it-1:it);
        //cout<<p[i]<<' '<<p3[i]<<' '<<key<<' '<<ans<<endl;
    }
    cout<<ans;
}
