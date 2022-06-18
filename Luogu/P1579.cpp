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

vector<int> v;
int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    v.em(2);
    for(int i=3;i<20000;i+=2){
        bool c=1;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){c=0;break;}
        }
        if(c)v.em(i);
    }
    int n;
    bool c=0;
    cin>>n;
    REP(i,v.size()){
        REP(j,v.size()){
            REP(k,v.size()){
                if(v[i]+v[j]+v[k]==n){
                    cout<<v[i]<<' '<<v[j]<<' '<<v[k];c=1;break;
                }
            }
            if(c)break;
        }
        if(c)break;
    }
//    system("pause");
    return 0;
}
