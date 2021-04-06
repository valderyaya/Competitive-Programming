//#pragma GCC optimize("Ofast")
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
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

struct qq{int a,b;}q[10001];
bool cmp(qq x,qq y){return x.a==y.a?x.a>y.a:x.b>y.b;}

int main(){
    oi;
    int n,a,b;
    while(cin>>n,n){
        REP(i,n){cin>>q[i].a>>q[i].b;}
        sort(q,q+n,cmp);
        int sum=0,t=0;
        REP(i,n){
           sum+=q[i].a;
           t=max(t,sum+q[i].b); 
        }
        cout<<t<<"\n";
    }
//    system("pause");
    return 0;
}
