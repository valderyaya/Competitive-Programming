// luogu-judger-enable-o2
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

int n,a[100001];
int main(){
    oi;
    cin>>n;
    REP(i,n)cin>>a[i];
    sort(a,a+n);
    REP(i,n)cout<<a[i]<<' ';
//    system("pause");
    return 0;
}
