#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define pii pair<long long,long long>
#define mkp make_pair
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
//#define lb(x) (x&(-x)) 

int n;
string a[25];
bool cmp(string x,string y){return x+y>y+x;}
int main(){
    //oi;
    cin>>n;
    REP(i,n) cin>>a[i];
    sort(a,a+n,cmp);
    REP(i,n) cout<<a[i];
//    system("pause");
    return 0;
}
