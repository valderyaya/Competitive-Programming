//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

ll ma=0,t,n,m,k,tme[1005],deg[1005],val[1005];
vector<ll> v[1005];
queue<ll> q;
int main(){
    oi;
    ll x,y;
    cin>>t;
    while(t--){
        cin>>n;ma=0;
        while(q.size()) q.pop();
        REP1(i,1,n) deg[i]=val[i]=0,v[i].clear();
        REP1(i,1,n){
            cin>>k>>m;
            tme[i]=k;
            REP(j,m) cin>>x,deg[x]++,v[i].em(x);
        }
        REP1(i,1,n){
            if(deg[i]==0){val[i]=tme[i];q.emplace(i);}
        }
        while(q.size()){
            x=q.front();q.pop();
            if(v[x].size()==0){
                ma=max(ma,val[x]);continue;
            }
            for(ll i:v[x]){
                deg[i]--;
                val[i]=max(val[i],val[x]+tme[i]);
                if(!deg[i]) q.emplace(i);
            }
        }
        cout<<ma<<"\n";
    }
//    system("pause");
    return 0;
}
