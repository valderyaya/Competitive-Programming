//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------\n";

const int z=5e5+5;
int ch[2][z],len,cnt=0,val[z],ed[z],n,m;
string s;
void inter(int rt){
    REP(i,len){
        if(!ch[s[i]-'0'][rt]) ch[s[i]-'0'][rt]=++cnt;
        rt=ch[s[i]-'0'][rt]; val[rt]++;
    }
    ed[rt]++;
}
int que(int rt){
    int res=0,ck=1;
    REP(i,len){
        if(!ch[s[i]-'0'][rt]){ck=0;break;} 
        rt= ch[s[i]-'0'][rt];
        res+=ed[rt];
    }
    return ck?res+val[rt]-ed[rt]:res;
}
int main(){Rosario
    int rt=0,x;
    cin>>n>>m;
    REP(i,n){
        cin>>len; s="";
        REP(j,len) cin>>x,s.push_back(char(x+'0'));
        inter(rt);
    }
    while(m--){
        cin>>len; s="";
        REP(j,len) cin>>x,s.push_back(char(x+'0'));
        cout<<que(rt)<<"\n";
    }
    return 0;
}
