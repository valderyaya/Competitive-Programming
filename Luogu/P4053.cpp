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

struct qq{
    int x,y;
    bool operator<(const qq &a)const{
        return y<a.y;
    }
}a[150005];
int n,sum=0,cnt=0;
priority_queue<int> q;
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>a[i].x>>a[i].y;
    sort(a,a+n);
    REP(i,n){
        if(sum+a[i].x<=a[i].y) q.emplace(a[i].x),sum+=a[i].x,++cnt;
        else if(a[i].x<q.top()){
           sum-=q.top();
           q.pop();
           sum+=a[i].x;
           q.emplace(a[i].x); 
        }
    }
    cout<<cnt<<"\n";
//    system("pause");
    return 0;
}
