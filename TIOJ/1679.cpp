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

struct qq{int x,y;}q[100];
bool cmp(qq x,qq y){
    return x.y==y.y?x.x>y.x:x.y>y.y;
}
int n,a,b;
string s;
map<int,char> ma;
int main(){
    //oi;
    ma[4]='S',ma[3]='H',ma[2]='D',ma[1]='C';
    cin>>n;
    REP(i,2*n){
        cin>>s;
        if(i&1){
            b=stoi(s);
        }else{
            if(s=="S") a=4;
            else if(s=="H") a=3;
            else if(s=="D") a=2;
            else if(s=="C") a=1;
        }
        if(i&1) q[i/2].x=a,q[i/2].y=b;
    }
    sort(q,q+n,cmp);
    cin>>n;n--;
    cout<<ma[q[n].x]<<' '<<q[n].y;
//    system("pause");
    return 0;
}
