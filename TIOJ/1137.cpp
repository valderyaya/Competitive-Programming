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

int t,n,m,dep[10005],low[10005];
vector<int> v[10005],ans;
bool vis[10005];
void dfs(int x,int d,int p){
    dep[x]=low[x]=d;vis[x]=1;
    int ap=0,cnt=0;
    for(int i: v[x]){
        if(!vis[i]){
            cnt++,dfs(i,d+1,x);
            if(dep[x]<=low[i]) ap=1;
            low[x]=min(low[x],low[i]);
        }else if(dep[i]<dep[x]&&p!=i) low[x]=min(low[x],dep[i]);
    }
    if(cnt>=2&&p==0||ap&&p) ans.em(x);
}
int main(){Rosario
    cin>>t;
    while(t--){int a,b;
        cin>>n>>m;ans.clear();
        REP1(i,1,n) v[i].clear(),vis[i]=0;
        REP(i,m) cin>>a>>b,v[a].em(b),v[b].em(a);
        dfs(1,0,0);
        if(ans.empty()) cout<<"0\n0\n";
        else{
            cout<<ans.size()<<"\n";
            sort(ALL(ans));
            for(int i:ans) cout<<i<<" ";
            cout<<"\n";
        }
    }
//    system("pause");
    return 0;
}
