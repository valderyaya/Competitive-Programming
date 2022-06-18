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

string a,b;
int cnt;
void dfs(int l,int r,int c){
    if(l>r) return;
    ++cnt;
    if(l==r) return cout<<a[l],void();
    int x=a.find(b[c]);
    dfs(l,x-1,cnt);
    dfs(x+1,r,cnt);
    cout<<b[c];
}
int main(){//Rosario
    cin>>a>>b;
    dfs(0,a.size()-1,0);
//    system("pause");
    return 0;
}
