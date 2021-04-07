//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
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

void dfs(string a,string b,int x){
    if(x==0) return;
    int i;
    for(i=0;;i++) if(b[i]==a[0]) break;
    dfs(a.substr(1),b,i);
    dfs(a.substr(i+1),b.substr(i+1),x-i-1);
    cout<<a[0];
}
int main(){//Rosario
    string a,b;
    while(cin>>a>>b) dfs(a,b,a.size()),cout<<"\n";
//    system("pause");
    return 0;
}
