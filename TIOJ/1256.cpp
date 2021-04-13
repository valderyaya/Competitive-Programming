#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,m,k=1,dep[10005],low[10005];
vector<int> ans;
bitset<10005> vis;
vector<int> v[10005];
void dfs(int x,int d,int p){
    int cnt=0,ap=0;
    vis[x]=1;dep[x]=low[x]=d;
    for(int i:v[x]){
        if(!vis[i]){
            cnt++;
            dfs(i,d+1,x);
            low[x]=min(low[x],low[i]);
            if(dep[x]<=low[i]) ap=1;
        }else if(i!=p&&dep[i]<=dep[x]) low[x]=min(low[x],dep[i]);
    }
    if((ap&&p)||(!p&&cnt>1)) ans.em(x);
}
int main(){Rosario
    while(cin>>n>>m,n){
        REP1(i,1,n) v[i].clear();
        vis.reset();ans.clear();
        for(int i=0,a,b;i<m;i++) cin>>a>>b,v[a].em(b),v[b].em(a);
        dfs(1,0,0);
        sort(ALL(ans));
        cout<<"Case #"<<k++<<':'<<ans.size()<<' '<<(ans.empty()?"0":"");
        for(int i:ans) cout<<i<<' ';
        cout<<"\n";
    }
//    system("pause");
    return 0;
}
