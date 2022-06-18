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
//#define lb(x) (x&-x)

int n,sum;
struct qq{
    int l,r;
    bool operator<(qq &x)const{
        return l==x.l?r>x.r:l<x.l;
    }
}q[20005];
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>q[i].l>>q[i].r;
    sort(q,q+n);
    int x=-2147483647,y=-2147483647;
    REP(i,n){
        if(q[i].l>=y) sum+=y-x,x=q[i].l,y=q[i].r;
        else if(q[i].r>y) y=q[i].r;
    }
    sum+=y-x;
    cout<<sum<<"\n";
//    system("pause");
    return 0;
}
