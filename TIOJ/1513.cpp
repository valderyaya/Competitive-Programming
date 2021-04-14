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
#define oi ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll>

ll n,m,ans;
int main(){
    //oi;
    while(cin>>n){
        ans=0;
        REP(i,n){
            cin>>m;
            ans^=m;
        }
        cout<<ans<<"\n";
    }
//    system("pause");
    return 0;
}

