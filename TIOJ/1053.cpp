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
    int a,b;
    while(cin>>a>>b){
        !(max(a,b)%min(a,b))?cout<<"Y"<<endl:cout<<"N"<<endl;
    }
   // system("pause");
    return 0;
}
