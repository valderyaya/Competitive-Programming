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

int n,a,b,m[1001];
int main(){
    Rosario
    cin>>n;
    while(n--){
        cin>>a>>b;
        REP(i,a-1) cin>>m[i];
        sort(m,m+a-1);
        a=upper_bound(m,m+a-1,b)-m;
        cout<<m[a]<<' ';
        if(m[a-1]==b) cout<<m[a-2]<<"\n";
        else cout<<m[a-1]<<"\n";
    }
//    system("pause");
    return 0;
}
