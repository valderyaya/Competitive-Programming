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
#define wait system("pause");

int dfn=0,col[105],cnt=0,n,dep[105],low[105],in[105]={},out[105]={};
vector<int> v[105];
stack<int> st;
bitset<105> ins;
void dfs(int x){
    dep[x]=low[x]=++dfn;
    st.emplace(x); ins[x]=1;
    for(auto &i:v[x])
        if(!dep[i]) dfs(i),low[x]=min(low[x],low[i]);
        else if(ins[i]) low[x]=min(low[x],dep[i]);
    if(low[x]==dep[x]){++cnt;
        for(int u=0;u!=x;st.pop()) u=st.top(),ins[u]=0,col[u]=cnt;
    }
}
int main(){Rosario
    cin>>n;
    int x,y;
    REP1(i,1,n) while(cin>>x,x) v[i].em(x);
    REP1(i,1,n) if(!dep[i]) dfs(i);
    REP1(i,1,n)
        for(auto &j:v[i]) if(col[i]!=col[j]) in[col[j]]++,out[col[i]]++;
    x=y=0;
    REP1(i,1,cnt){
        if(!in[i]) x++;
        if(!out[i]) y++;
    }
    if(cnt==1) cout<<"1\n0";
    else cout<<x<<"\n"<<max(x,y)<<"\n";
//    system("pause");
    return 0;
}
