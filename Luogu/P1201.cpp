// luogu-judger-enable-o2
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define sz(x) (sizeof(x)/sizeof(*x))
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>

map<string,int> ma;
string a[11];
int main(){//
    oi;
    int n,x,y,z;
    string s;
    cin>>n;
    REP(i,n){
        cin>>a[i];
        ma[a[i]]=0;
    }
    REP(i,n){
        cin>>s>>x>>y;
        if(x==0||y==0) continue;
        z=x/y;
        ma[s]-=z*y;
        REP(j,y){
            cin>>s;
            ma[s]+=z;
        }
    }
    REP(i,n){
        cout<<a[i]<<' '<<ma[a[i]]<<"\n";
    }
//    system("pause");
    return 0;
}  
