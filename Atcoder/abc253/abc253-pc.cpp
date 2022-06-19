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


map<int,int> mp;
int q;
signed main(){valder
    cin>>q;
    for(int k,x,c;q--;){
        cin>>k;
        if(k==1){
            cin>>x;
            mp[x]++;
        }else if(k==2){
            cin>>x>>c;
            mp[x]=max(0,mp[x]-c);
            if(mp[x]==0) mp.erase(x);
        }else{
            cout<<mp.rbegin()->F-mp.begin()->F<<endl;
        }
    }
}
