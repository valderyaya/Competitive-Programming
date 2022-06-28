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


map<int,vector<pii>> mp;
int n,x[200005],y[200005];
string s;
signed main(){valder
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>x[i]>>y[i];
    
    cin>>s;

    for(int i=0;i<s.size();++i)
        mp[y[i]].em(x[i],s[i]=='R');

    for(auto &i:mp) {
        bool r=0;
        sort(ALL(i.S));
        for(auto &j:i.S){
            if(j.S==1) r=1;
            else if(j.S==0&&r) return cout<<"Yes",0;
        }
    }
    cout<<"No";
}
