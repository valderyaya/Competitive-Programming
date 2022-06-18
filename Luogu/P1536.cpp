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


int n,m,pa[1001],cnt;
int fin(int x){return x==pa[x]?x:pa[x]=fin(pa[x]);}
int main(){Rosario
    while(cin>>n,n){
        cin>>m; cnt=n;
        REP1(i,1,n) pa[i]=i;
        int a,b;
        while(m--){
            cin>>a>>b;
            a=fin(a),b=fin(b);
            if(a!=b){
                cnt--;
                pa[a]=b;
            }
        }
        cout<<cnt-1<<"\n";
    }
//    system("pause");
    return 0;
}
