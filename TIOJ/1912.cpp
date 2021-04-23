//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,m;
bool ck(int x){
    int c;
    while(x>=10){
        c=0;
        while(x) c+=x%10,x/=10;
        x=c;
    }
    return x==m;
}
string s,p[]={"0","1","2","3","4","5","6","7","8","9"};
set<string> ans;
int main(){Rosario
    cin>>n>>m>>s;
    int x=0;
    for(auto &i:s) x+=i-'0';
    REP1(i,0,9) if(ck(x+i)) REP(j,n){
        string tmp=s.substr(0,j)+p[i]+s.substr(j);
        ans.insert(tmp);
    }
    ans.erase(ans.begin());
    ans.erase(--ans.end());
    for(auto &it:ans) cout<<it<<"\n";
    return 0;
}
