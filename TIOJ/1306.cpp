//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

struct kmp{
    vector<int> f;
    string s;
    void build(){
        int fp=-1,n=s.size();
        f.resize(n); f[0]=-1;
        REP1(i,1,n-1){
            while(~fp&&s[fp+1]!=s[i]) fp=f[fp];
            if(s[fp+1]==s[i]) ++fp;
            f[i]=fp;
        }
    }
    int query(string p){
        int n=s.size(),fp=-1,res=0;
        REP(i,p.size()){
            while(~fp&&s[fp+1]!=p[i]) fp=f[fp];
            if(s[fp+1]==p[i]) ++fp;
            if(fp==n-1) ++res,fp=f[fp];
        }
        return res;
    }
}pp;
int t,n;
string s;
int main(){Rosario
    cin>>t;
    while(t--){
        cin>>s>>n;
        while(n--){
            cin>>pp.s;
            pp.build();
            cout<<pp.query(s)<<"\n";
        }
    }
    return 0;
}
