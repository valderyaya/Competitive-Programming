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

struct p{int x,y;}a[5001];
bool cmp(p n,p m){return n.y<m.y;}
int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,s,cm,m,cnt=0;
    cin>>n>>m>>s>>cm;cm+=s;
    REP(i,n)cin>>a[i].x>>a[i].y;
    sort(a,a+n,cmp);
    for(int i=0;i<n&&m;i++){
        if(m>=a[i].y&&a[i].x<=cm){
            m-=a[i].y;cnt++;
        }
    }
    cout<<cnt;
//    system("pause");
    return 0;
}
