#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define sz(x) (sizeof(x)/sizeof(*x))

int main(){
    int x;
    while(cin>>x){
        if(x<=5){cout<<1<<endl;}
        else cout<<(x+4)/5<<endl;
    }

    return 0;
}
