#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define sz(x) (sizeof(x)/sizeof(*x))
#define F first
#define S second

int a[10000];
int main(){
    ll n;
    while(cin>>n){
        int c=0;
        while(n){
            a[c++]=n%2;
            n/=2;
        }
        for(int i=c-1;i>=0;i--) cout<<a[i];
        cout<<endl;
    }
    return 0;
}
