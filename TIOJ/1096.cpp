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
#define lb(x) (x&-x)

int n,a[1001][1001];
int main(){
    Rosario
    while(cin>>n,n){
        REP(i,n){
            REP(j,n){
                cin>>a[i][j];
                if(a[i][j]==0) a[i][j]=1e9;
            }
        }
        REP(k,n){
            REP(i,n){
                REP(j,n) a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
        int c=1,mi=1e9;
        REP(i,n){
            if(mi>a[i][i]){
                c=0;mi=a[i][i];
            }
        }
        cout<<(c?-1:mi)<<"\n";
    }
//    system("pause");
    return 0;
}
