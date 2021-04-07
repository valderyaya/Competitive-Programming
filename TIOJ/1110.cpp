//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

pii a[26];
string s;
bool cmp(pii x,pii y){return x.S==y.S?x.F<y.F:x.S>y.S;}
int main(){Rosario
    int n,m;
    cin>>n;
    while(n--){
        REP(i,26) a[i].S=0,a[i].F=i;
        cin>>m>>s;
        REP(i,s.size()) a[s[i]-'a'].S++;
        sort(a,a+26,cmp);
        REP(i,26){
            if(a[i].S!=a[0].S) break;
           cout<<char('a'+a[i].F);
        }
        cout<<"\n";
    }
//    system("pause");
    return 0;
}
