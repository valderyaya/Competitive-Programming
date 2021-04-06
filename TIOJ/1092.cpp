//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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

const int z=10005;
int n,m,col[z],in[z];
vector<int> v[z];
queue<int> q;
void bfs(){
    q.emplace(n);
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(auto &i:v[x]){
            if(col[x]==0) col[i]=1;
            if(--in[i]==0) q.emplace(i);
        }
    }
}
string s;
int main(){Rosario
    while(cin>>n>>m,n){int x,y;
        REP1(i,1,n) v[i].clear();
        memset(col,0,sizeof(col)); memset(in,0,sizeof(in));
        while(m--) cin>>x>>y,v[y].em(x),++in[x];
        bfs(); cin>>s;
        if(!col[1]) cout<<s<<"\n";
        else{
            if(s=="Mimi") cout<<"Moumou\n";
            else cout<<"Mimi\n";
        }
    }
    return 0;
}
