//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int tot,n,mp[129],d,v[55][55],ans=1e9,dis[55];
char a,b,an;
void spfa(){
    priority_queue<pii,vector<pii>,greater<pii>> q;
    REP1(i,1,tot) dis[i]=1e9;
    q.emplace(dis[mp['Z']]=0,mp['Z']);
    int x;
    while(!q.empty()){
        tie(d,x)=q.top(); q.pop();
        if(dis[x]!=d) continue;
        REP1(i,1,tot){
            if(dis[i]>d+v[x][i]){
                dis[i]=d+v[x][i];
                q.emplace(dis[i],i);
            }
        }
    }
}
signed main(){Rosario
    memset(v,0x3f3f,sizeof(v));
    cin>>n;
    while(n--){
        cin>>a>>b>>d;
        if(!mp[a]) mp[a]=++tot;
        if(!mp[b]) mp[b]=++tot;
        v[mp[a]][mp[b]]=min(v[mp[a]][mp[b]],d);
        v[mp[b]][mp[a]]=min(v[mp[b]][mp[a]],d);
    }
    spfa();
    for(int i='A';i<'Z';++i)
        if(mp[i]&&dis[mp[i]]<ans){
            ans=dis[mp[i]];
            an=i;
        }
    cout<<an<<' '<<ans<<'\n';
    return 0;
}
