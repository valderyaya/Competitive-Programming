#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
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
// #define lb(x) (x&-x)

int n,c=0;
bool now=0;
string s;
int main(){Rosario
   cin>>n>>s;
   for(int i=n-1;i>0;i--){
       if(s[i]=='0'&&!now||s[i]=='1'&&now){
           c++;
           if(s[i-1]==s[i]) now=!now;
       }
   }
   if(s[0]=='0'&&!now||s[0]=='1'&&now) c++;
   cout<<c<<"\n";
//    system("pause");
    return 0;
}
