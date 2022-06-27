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

string s="BGR",p;
map<string,int> mp;
int n,f[10][10];
signed main(){valder
    do{
        mp[s]=++n;
    }while(next_permutation(ALL(s)));
    s="BGR";
    do{
        p=s;
        swap(p[0],p[1]);
        f[mp[s]][mp[p]]=1;
        swap(p[0],p[1]);
        swap(p[1],p[2]);
        f[mp[s]][mp[p]]=1;
        swap(p[1],p[2]);
        swap(p[0],p[2]);
        f[mp[s]][mp[p]]=1;
    }while(next_permutation(ALL(s)));
    s=p="";
    char c;
    for(int i=0;i<3;++i) cin>>c,s.push_back(c);
    for(int i=0;i<3;++i) cin>>c,p.push_back(c);
    if(f[mp[s]][mp[p]]==1) cout<<"No";
    else cout<<"Yes";
}
