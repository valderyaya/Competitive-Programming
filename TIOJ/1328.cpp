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
#define mkp make_pair

int an[100000];
int main(){
    //ios::sync_with_stdio(false),cin.tie(0);
    int n;
    while(cin>>n,n){
        REP(i,n)
            cin>>an[i];
        sort(an,an+n);
        REP(i,n)
            cout<<an[i]<<' ';
        cout<<endl;
    }
//    system("pause");
    return 0;
}