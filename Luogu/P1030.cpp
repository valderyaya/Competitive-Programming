#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

string a,b;
void solve(int l,int r,int L,int R){
    cout<<b[R];
    int m=a.find(b[R]);
    if(m>l) solve(l,m-1,L,L+m-l-1);
    if(m<r) solve(m+1,r,L+m-l,R-1);
}
int main(){
    //oi;
    cin>>a>>b;
    solve(0,a.size()-1,0,b.size()-1);
//    system("pause");
    return 0;
}
