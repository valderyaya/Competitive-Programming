#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define sz(x) (sizeof(x)/sizeof(*x))
#define F first
#define S second
#define mkp make_pair

string s="123456789";
int a,b,c,ck=1;
void solve(){
    int x=stoi(s.substr(0,3)),y=stoi(s.substr(3,3)),z=stoi(s.substr(6,3));
    if(b*x==a*y&&c*y==b*z&&c*x==a*z){cout<<x<<' '<<y<<' '<<z<<"\n";ck=0;}
}
int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>a>>b>>c;
    do{
        solve();
    }while(next_permutation(ALL(s)));
    if(ck)cout<<"No!!!";
//    system("pause");
    return 0;
}
