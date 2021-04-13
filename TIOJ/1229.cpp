#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,m,c,a[105];
string s,p;
int main(){//Rosario
    cin>>n>>m>>c;
    REP(i,m) cin>>a[i],a[i]--;
    getchar();
    while(n--){
        getline(cin,s);
        p.resize(m);
        REP(i,c){
            REP(j,m) p[a[j]]=s[j];
            s=p;
        }cout<<s<<"\n";
    }
//    system("pause");
    return 0;
}
