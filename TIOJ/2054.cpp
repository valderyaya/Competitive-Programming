#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)


int mx=0,n,l,w;
vector<pii> v,c;
bool cmp(pii a,pii b){return a.S<b.S;}
void solve(){
    vector<pii> t=c;
    sort(ALL(t),cmp);
    int i=0,j=0;
    for(;j<t.size();){
        while(j<t.size()&&t[j].S-t[i].S<=l) j++;
        if(j==t.size()) break;
        mx=max(mx,j-i+1);
        i++;
    }mx=max(mx,j-i+1);
}
int main(){Rosario
    cin>>n>>l>>w;v.resize(n);
    REP(i,n) cin>>v[i].F>>v[i].S;
    sort(ALL(v));
    int i=0,j=0,last=-1;
    for(;j<n;){
        while(j<n&&v[j].F-v[i].F<=w) c.em(v[j++]);
        if(j==n) break;
        if(last!=j) solve(),last=j;
        i++;c.erase(c.begin());
    }
    solve();
    cout<<mx-1<<"\n";
//    system("pause");
    return 0;
}
