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
#define Rosario ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

struct qq{
    int x,y;
    bool operator<(const qq &a)const{
        return (double)x/y<(double)a.x/a.y;
    }
};
set<qq> s;
int n,g;
int main(){Rosario
    cin>>n;
    for(int i=2;i<=n;i++){
        for(int j=i-1;j;j--){
            g=__gcd(i,j);
            s.insert(qq{j/g,i/g});
        }
    }cout<<s.size()<<"\n";
    if(s.size()<=n) {auto it=--s.end();cout<<it->x<<'/'<<it->y;}
    else{
    g=1;
    for(auto i:s){
        if(g++==n){cout<<i.x<<'/'<<i.y;break;}
    }
    }
//    system("pause");
    return 0;
}
