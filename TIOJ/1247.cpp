//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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

int n,cnt=1,a[10005];
bool solve(){
    REP(i,n){
        sort(a+i,a+n,greater<int>());
        for(int j=i+1;j<n&&a[i]>0;++j){
            --a[i];--a[j];
            if(a[j]<0) return 0; 
        }if(a[i]>0) return 0;
    }return 1;
}
int main(){Rosario
    while(cin>>n,n){
        REP(i,n) cin>>a[i];
        cout<<"Case #"<<cnt++<<':'<<(solve()?"Yes":"No")<<"\n";
    }
    return 0;
}
