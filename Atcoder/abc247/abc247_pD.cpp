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

queue<pll> q;
ll Q;
signed main(){valder
    cin>>Q;
    for(ll k,x,y;Q--;){
      cin>>k>>x;
      if(k==1){
        cin>>y;
        q.emplace(mkp(x,y));
      }else{
        ll ans=0;
        while(!q.empty()&&x>0){
          if(x<=q.front().S){
            q.front().S-=x;
            ans+=q.front().F*x;
            if(q.front().S==0) q.pop();
            break;
          }else{
            ans+=q.front().F*q.front().S;
            x-=q.front().S;
            q.pop();
          }
        }
        cout<<ans<<"\n";
      }
    }
}
