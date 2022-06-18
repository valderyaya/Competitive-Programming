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
#define Rosario ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

int n,m,col[10005]={},a,b,sum=0;
vector<int> v[10005];
bool vis[10005];
bool bfs(int x){
    col[x]=1;a=b=0;
    queue<int> q;q.emplace(x);
    while(q.size()){
        x=q.front();q.pop();vis[x]=1;
        if(col[x]==1) a++;
        else b++;
        for(int i:v[x]){
            if(col[i]==col[x]) return 0;
            else if(col[i]==0) col[i]=-col[x],q.emplace(i);
        }
    }
    return 1;
}
int main(){Rosario
    cin>>n>>m;
    REP(i,m) cin>>a>>b,v[a].em(b),v[b].em(a);
    REP1(i,1,n){
        if(!vis[i]){
            if(!bfs(i)){cout<<"Impossible\n";return 0;}
            else sum+=min(a,b);
        }
    }
    cout<<sum<<"\n";
//    system("pause");
    return 0;
}
