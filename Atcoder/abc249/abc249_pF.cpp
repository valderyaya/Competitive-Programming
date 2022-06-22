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

ll n,k,ans=-1e18,sum;
pll ope[200005];
priority_queue<ll> pq;
signed main(){valder
    cin>>n>>k;
    ope[0]={1,0};
    for(int i=1;i<=n;++i)
        cin>>ope[i].F>>ope[i].S;
    for(int i=n;~i;--i){
        if(ope[i].F==1){
            ans=max(ans,ope[i].S+sum);
            if(k==0) break;
            --k;
            while(pq.size()>k) sum+=pq.top(), pq.pop();
        }else{
            if(ope[i].S>=0) sum+=ope[i].S;
            else{
                pq.emplace(ope[i].S);
                while(pq.size()>k) sum+=pq.top(), pq.pop();
            }
        }
    }
    cout<<ans;
}
