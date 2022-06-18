#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
//#define pb push_back
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair


int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int a[10001]={},n,m,x,y,cnt=0;
    cin>>n>>m;
    while(m--){
        cin>>x>>y;
        REP1(i,x,y)a[i]=1;
    }
    REP1(i,0,n) if(!a[i])cnt++;
    cout<<cnt;
//    system("pause");
    return 0;
}
