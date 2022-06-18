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
    int n,m;
    cin>>n;
    for(int i=2;i*i<=n;i+=(i==2?1:2)){
        if(n%i==0){
            bool c=1;m=n/i;
            for(int j=2;j*j<=m;j+=(j==2?1:2)){
                if(m%j==0){c=0;break;}
            }
            if(c){cout<<m;return 0;}
        }
    }
//    system("pause");
    return 0;
}
