//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<bits/extc++.h>
//using namespace __gnu_pbds;
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
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------------\n";
 
struct qq{
    int x,y,z;
    bool operator<(const qq &a)const{
        return z<a.z;
    }
}q[50005];
int n;
double ans;
double dis(qq a,qq b){
    int x=a.x-b.x,y=a.y-b.y,z=a.z-b.z;
    return sqrt(double(x*x+y*y+z*z));
}
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>q[i].x>>q[i].y>>q[i].z;
    sort(q,q+n);
    for(int i=1;i<n;i++) ans+=dis(q[i-1],q[i]);
    cout<<fixed<<setprecision(3)<<ans<<"\n";
//    system("pause");
    return 0;
}
