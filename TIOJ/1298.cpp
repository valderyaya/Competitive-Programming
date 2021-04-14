#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define pii pair<int,int>
#define mkp make_pair
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&(-x)) 

int n,m;
vector<int> v;
int main(){
    //Rosario
    while(cin>>n){
        int c1=0,c2=0,sum=0;
        REP(i,n){
            cin>>m;
            if(m>0) c1++;
            else c2++;
            v.em(abs(m));
        }
        sort(ALL(v));
        for(int i=1;i<v.size()-1;i++) sum+=v[i];
        cout<<fixed<<setprecision(3)<<"Average time: "<<(double)sum/(c1+c2-2)<<" sec(s).\n"<<"Winning rate: "<<c1*100./double(c1+c2)<<" %.\n";
        v.clear();
    }
//    system("pause");
    return 0;
}
