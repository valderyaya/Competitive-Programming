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
#define lb(x) (x&-x)
#define wait system("pause");


int n,a[10005],c=0,mx=0;
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>a[i];
    REP(i,n-1){
        if(a[i]+1==a[i+1]) c++;
        else c=0;
        mx=max(mx,c);
    }
    cout<<mx+1<<"\n";
//    wait
}
