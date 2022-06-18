#include<bits/stdc++.h>
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
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

struct q{int id,a,b,c,sum;}x[305];
bool cmp(q a,q b){
    return a.sum==b.sum?(a.a==b.a?a.id<b.id:a.a>b.a):a.sum>b.sum;
}
int n;
int main(){
    oi;
    cin>>n;
    REP1(i,1,n){
        cin>>x[i].a>>x[i].b>>x[i].c;
        x[i].sum=x[i].a+x[i].b+x[i].c;
        x[i].id=i;
    }
    sort(x+1,x+1+n,cmp);
    REP1(i,1,5){
        cout<<x[i].id<<' '<<x[i].sum<<"\n";
    }
//    system("pause");
    return 0;
}
