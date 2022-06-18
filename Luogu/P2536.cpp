//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

struct qwq{
    bool ed;
    vector<int> nxt[4];
}tr[1005];
int cnt=1,n,ans;
string s;
char mp[128];
bitset<1005> vis;
vector<int> now,nxt;
void match(){
    now.clear(); now.em(1);
    int flg;
    for(auto &i:s){
        nxt.clear(); flg=0; vis.reset();
        for(auto &j:now)
            for(auto &k:tr[j].nxt[mp[i]])
                if(!vis[k]){
                    vis[k]=1;
                    nxt.em(k);
                    flg|=tr[k].ed;
                }
        now=nxt;
    }
    ans+=1-flg;
}
int main(){Rosario
    mp['A']=0,mp['C']=1,mp['T']=2,mp['G']=3;
    cin>>s;
    for(auto &i:s){
        if(i=='?') {
            REP(j,4) tr[cnt].nxt[j].em(cnt+1);
            ++cnt;
        }else if(i=='*'){
            REP(j,4) tr[cnt].nxt[j].em(cnt);
        }else{
            tr[cnt].nxt[mp[i]].em(cnt+1);
            ++cnt;
        }
    }
    tr[cnt].ed=1;
    cin>>n;
    REP(i,n) cin>>s,match();
    cout<<ans<<"\n";
    return 0;
}
