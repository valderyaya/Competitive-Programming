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
    int a[10],b,cnt=0;
    REP(i,10)cin>>a[i];
    cin>>b;
    REP(i,10){
        if(b+30>=a[i])cnt++;
    }
    cout<<cnt;
//    system("pause");
    return 0;
}
