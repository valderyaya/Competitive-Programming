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
    int a[12],re=0,bank=0,ck=1;
    REP(i,12) cin>>a[i];
    REP(i,12){
        if(re+300<a[i]){if(ck){cout<<-(i+1);ck=0;break;}}
        else{
            int tmp=re+300-a[i];
            re=tmp%100;
            bank+=tmp/100*100;
        }
    }
    if(ck) cout<<bank*1.2+re;
//   system("pause");
    return 0;
}
