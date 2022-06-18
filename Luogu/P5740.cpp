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
//#define line cout<<"-------------------------\n";

struct qq{
    int sum,id,x,y,z;
    string s;
    bool operator<(const qq &a)const{
        return sum==a.sum?id<a.id:sum>a.sum;
    }
}q[1005];
int n;
int main(){Rosario
    cin>>n;
    REP(i,n){
        cin>>q[i].s>>q[i].x>>q[i].y>>q[i].z;
        q[i].sum=q[i].x+q[i].y+q[i].z;q[i].id=i;
    }sort(q,q+n);
    cout<<q[0].s<<' '<<q[0].x<<' '<<q[0].y<<' '<<q[0].z<<"\n";
//    system("pause");
    return 0;
}
