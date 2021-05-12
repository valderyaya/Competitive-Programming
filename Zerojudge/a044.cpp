#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//typedef pair<int,int> pii;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
//#define sz(x) (sizeof(x)/sizeof(*x))
#define F first
#define S second
#define mkp make_pair
//#define ios_base::sync_with_stdio(false),cin.tie(0);


int main(){
    int n;
    while(cin>>n){
        cout<<1 + n + n * (n + 1) * (n - 1) / 6<<endl;
    }


//    system("pause");
    return 0;
}
