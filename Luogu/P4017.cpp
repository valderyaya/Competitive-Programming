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

const int mod=80112002;
int n,m,cnt[5005]={},in[5005]={},out[5005]={},ans=0;
vector<int> v[5005];
queue<int> q;
void solve(){
    while(!q.empty()){
        int x=q.front();q.pop();
        for(auto &i:v[x]){
            in[i]--;cnt[i]=(cnt[i]+cnt[x])%mod;
            if(in[i]==0){
                if(out[i]==0) ans=(ans+cnt[i])%mod;
                q.emplace(i);
            }
        }
    }
}
int main(){Rosario
    cin>>n>>m;
    int a,b;
    while(m--) cin>>a>>b,v[a].em(b),in[b]++,out[a]++;
    REP1(i,1,n) if(in[i]==0)cnt[i]=1,q.emplace(i);
    solve();
    cout<<ans<<"\n";
//    system("pause");
    return 0;
}
