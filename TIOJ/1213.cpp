#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int n,ma,id,vis[100005]={},a,b,c;
vector<pii> v[100005];
void dfs(int x,int now){
    if(now>ma){ma=now,id=x;}
    vis[x]=1;
    for(auto &i:v[x]){
        if(!vis[i.F]){
            dfs(i.F,now+i.S);
        }
    }
    vis[x]=0;
}
int main(){
    oi;
    while(cin>>n,n){
        REP1(i,1,n){
            vis[i]=0;v[i].clear();
        }
        REP(i,n-1){
            cin>>a>>b>>c;
            v[a].em(mkp(b,c));v[b].em(mkp(a,c));
        }
        ma=0;
        dfs(1,0);
        dfs(id,0);
        cout<<ma<<"\n";
    }
//    system("pause");
    return 0;
}

