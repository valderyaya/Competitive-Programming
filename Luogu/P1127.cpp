#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)
#define wait system("pause");

int n,f=0,st=0,ans[1001],idx=0;
map<char,int> pre,post;
string s[1001];
bitset<1001> in;
void dfs(int cnt,int id){
    if(f) return;
    if(cnt==n){f=1;
        REP1(i,1,idx) cout<<(i==1?"":".")<<s[ans[i]];
        return;
    }
    REP(i,n){
        if(in[i]) continue;
        if(s[id][s[id].size()-1]==s[i][0]){
            in[i]=1;
            ans[++idx]=i;
            dfs(cnt+1,i);
            if(f) return;
            in[i]=0;--idx;
        }
    }
}
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>s[i],pre[s[i][0]]++,post[s[i][s[i].size()-1]]++;
    sort(s,s+n);
    REP(i,n) if(pre[s[i][0]]-post[s[i][0]]==1){st=i;break;}
    in[st]=1;ans[++idx]=st;dfs(1,st);
    if(!f) cout<<"***";
//    wait
    return 0;
}
