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


int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int a[2001]={6},n,cnt=0,b[10]={6,2,5,5,4,5,6,3,7,6};
    REP1(i,1,2000){
        for(int j=i;j;j/=10){
            a[i]+=b[j%10];
        }
    }
    cin>>n;
    n-=4;
    REP(i,1000){
        REP(j,1000){
            if(a[i]+a[j]+a[i+j]==n) cnt++;
        }
    }
    cout<<cnt;
//    system("pause");
    return 0;
}
