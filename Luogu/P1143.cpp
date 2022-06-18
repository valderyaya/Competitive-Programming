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

inline int ret(char c){
    if(isdigit(c)) return c^48;
    else return c-'A'+10;
}
inline char rev(int x){return char(x<10?'0'+x:x-10+'A');}
int get(int c,string s){
    int sum=0;
    for(int i=s.size()-1,k=1;~i;i--,k*=c) sum+=ret(s[i])*k;
    return sum;
}
void solve(int sum,int c){
    string x="";
    while(sum){
        x.push_back(rev(sum%c));
        sum/=c;
    }
    for(int i=x.size()-1;~i;i--) cout<<x[i];
}
int main(){Rosario
    int n,m;
    string s;
    cin>>n>>s>>m;
    int num=get(n,s);
    solve(num,m);
//    system("pause");
    return 0;
}
