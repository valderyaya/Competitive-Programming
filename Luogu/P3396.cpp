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

int n,m,s,a[150005],d[400][400];
int main(){Rosario
    cin>>n>>m;
    s=sqrt(n);
    REP1(i,1,n){
        cin>>a[i];
        REP1(j,1,s) d[j][i%j]+=a[i];
    }
    char c;
    int x,y;
    while(m--){
        cin>>c>>x>>y;
        if(c=='A'){
            int sum=0;
            if(x<=s) sum=d[x][y];
            else for(int i=y;i<=n;i+=x) sum+=a[i];
            cout<<sum<<"\n";
        }else{
            REP1(i,1,s) d[i][x%i]+=y-a[x];
            a[x]=y;
        }
    }
//    system("pause");
    return 0;
}
