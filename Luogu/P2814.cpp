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

map<string,string> m;
char c;
string s,fa;
string fin(string x){return m[x]==x?x:m[x]=fin(m[x]);}
int main(){Rosario
    while(cin>>c,c!='$'){
        cin>>s;
        if(c=='#'){
            fa=s;
            if(m.count(s)==0) m[s]=s;
        }else if(c=='+') m[s]=fa;
        else cout<<s<<' '<<fin(s)<<"\n";
    }
//    system("pause");
    return 0;
}
