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
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

map<int,map<char,vector<string>>> mp;
string s;
int n,ans;
signed main(){Aincrad
    cin>>n;
    REP(i,n){
        cin>>s;
        int cnt=0;
        char last;
        for(auto &j:s)
            if(j=='a'||j=='e'||j=='i'||j=='o'||j=='u') ++cnt,last=j;
        mp[cnt][last].em(s);
    }
    int x=0,y=0;
    for(auto &i:mp){
        int a=0,b=0;
        for(auto &j:i.S){
            a+=j.S.size()/2;
            b+=j.S.size()%2;
        }
        x+=a, y+=b/2;
    }
    if(x<=y) cout<<x<<'\n';
    else cout<<(y+(x-y)/2)<<'\n';
    return 0;
}
