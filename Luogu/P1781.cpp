#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define oi ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

struct q{string s;int n;}a[21];
int n;
bool cmp(q x,q y){
    if(x.s.size()>y.s.size()) return 1;
    else if(x.s.size()<y.s.size()) return 0;
    else return x.s>y.s; 
}
int main(){
    //oi;
    cin>>n;
    REP(i,n){cin>>a[i].s;a[i].n=i;}
    sort(a,a+n,cmp);
    cout<<a[0].n+1<<endl<<a[0].s;
//    system("pause");
    return 0;
}
