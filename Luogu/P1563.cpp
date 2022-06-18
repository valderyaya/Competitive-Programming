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
#define pll pair<ll,ll>

struct q{
    int out;
    string s;
}x[100000];
int n,m,a,b;
int main(){
    //oi;
    cin>>n>>m;
    REP(i,n) cin>>x[i].out>>x[i].s;
    int now=0;
    REP(i,m){
        cin>>a>>b;
        if(x[now].out){
            if(a){
                now-=b%n;
                if(now<0) now+=n;
            }else{
                now+=b%n;
                if(now>=n) now-=n;
            }
        }else{
            if(a){
                now+=b%n;
                if(now>=n) now-=n;
            }else{
                now-=b%n;
                if(now<0) now+=n;
            }
        }
    }
    cout<<x[now].s<<endl;
//    system("pause");
    return 0;
}
