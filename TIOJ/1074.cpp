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
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,a[25],c[450];
int main(){//Rosario
    while(cin>>n,n){
        int sum=0,x=0;
        memset(c,0,sizeof(c));
        REP(i,n) cin>>a[i],sum+=a[i];
        if(sum==n){cout<<"NO\n";continue;}
        REP(i,n){
            for(int j=i,s=0;j<n;j++){
                s+=a[j];
                c[s]=1;
            }
        }
        REP1(i,1,sum) if(!c[i]){x=1;break;}
        cout<< (x?"NO\n":"YES\n");
    }
//    system("pause");
    return 0;
}
