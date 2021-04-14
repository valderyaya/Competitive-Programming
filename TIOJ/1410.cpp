#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define pii pair<int,int>
#define mkp make_pair
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&(-x)) 

struct q{
    ll x,v;
    bool operator <(const q &a)const{
        return x==a.x?v>a.v:x<a.x;
    }
}a[2000005];
ll n,x,y,mx,cnt;
int main(){
    Rosario
    while(cin>>n){
        cnt=mx=0;
        REP(i,n){
            cin>>x>>y;
            a[i]=q{x,1},a[i+n]=q{y,-1};
        }
        sort(a,a+n*2);
        REP(i,n<<1){
            cnt+=a[i].v;
            mx=max(mx,cnt);
        }
        cout<<mx<<"\n";
    }
//    system("pause");
    return 0;
}
