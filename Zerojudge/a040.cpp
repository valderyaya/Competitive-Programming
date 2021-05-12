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


set<int> se;
set<int>::iterator it,iy;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    REP1(i,1,1000000){
        int n=0,m=i,k=log10(i)+1;
        REP(i,k){
            n+=pow(m%10,k);
            m/=10;
        }
        if(n==i)se.insert(i);
    }
    int n,m;
    while(cin>>n>>m){
        it=se.lower_bound(n),iy=se.lower_bound(m);
        if(it==iy) cout<<"none\n";
        else{
        for(;it!=iy;it++){
            cout<<*it<<' ';
        }
        if(*iy==m) cout<<*iy;
        cout<<"\n";
        }
    }
 //   system("pause");
    return 0;
}
