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

inline int cnt(int n,int m){
    int c=0;
    while(n){
        if(n%10==m) c++;
        n/=10;
    }
    return c;
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,m,sum=0;
    cin>>n>>m;
    REP1(i,1,n){
        sum+=cnt(i,m);
    }
    cout<<sum;
//    system("pause");
    return 0;
}
