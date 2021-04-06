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
#define pii pair<int,int>
#define mkp make_pair
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

struct qq{
    int t,x,y;
    bool operator<(const qq &a)const{
        return t<a.t;
    }
}q[1005];
int n,m,mp[1005],mq[1005];
bitset<1005> vis;
vector<int> v[1005];
bool dfs(int x){
    vis[x]=1;
    for(int &i:v[x])
        if(!~mq[i]||!vis[mq[i]]&&dfs(mq[i])) return mp[mq[i]=x]=i,1;
    return 0;
}
int main(){Rosario
    cin>>n;
    while(n--){
        cin>>m;
        REP(i,m) v[i].clear();
        memset(mp,-1,sizeof(mp)),memset(mq,-1,sizeof(mq));
        REP(i,m) cin>>q[i].t>>q[i].x>>q[i].y;
        sort(q,q+m);int cnt=0;
        REP(i,m)
            for(int j=i+1;j<m;j++) if(q[i].t+abs(q[i].x-q[j].x)+abs(q[i].y-q[j].y)<=q[j].t) v[i].em(j);
        REP(i,m) if(vis.reset(),dfs(i)) cnt++;
        cout<<m-cnt<<"\n";
    }
//    system("pause");
    return 0;
}
