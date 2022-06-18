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

bool c[1001];
int n,a,b;
bool ck(){
    REP1(i,1,n-1) if(!c[i]) return 0;
    return 1;
}
int main(){//Rosario
    cin>>n>>a;
    REP(i,n-1) cin>>b,c[abs(a-b)>1000?0:abs(a-b)]=1,a=b;
    cout<<(ck()?"Jolly":"Not jolly");
//    wait
    return 0;
}
