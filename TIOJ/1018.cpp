//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n;
string s,a[15];
int main(){Rosario
    cin>>n; getline(cin,s);
    while(n--){
        getline(cin,s); int id=0,th;
        stringstream ss(s);
        while(ss>>a[id]){
            if(a[id]=="THEN") th=id;
            ++id;
        }--id;
        //REP1(i,0,id) cout<<a[i]<<" \n"[i==id];
        cout<<"IF ";
        if(id-th==1) cout<<"not "<<a[id];
        else if(id-th==2) cout<<a[id];
        else if(id-th==3){
            if(a[th+2]=="or") cout<<"not "<<a[th+1]<<" and not "<<a[id];
            else cout<<"not "<<a[th+1]<<" or not "<<a[id];
        }else if(id-th==4){
            if(a[th+2]=="and") cout<<"not "<<a[th+1]<<" or "<<a[id];
            else if(a[id-1]=="and") cout<<a[th+2]<<" or not "<<a[id];
            else if(a[th+2]=="or") cout<<"not "<<a[th+1]<<" and "<<a[id];
            else if(a[id-1]=="or") cout<<a[th+2]<<" and not "<<a[id];
        }else if(id-th==5){
            if(a[th+3]=="or") cout<<a[th+2]<<" and "<<a[id];
            else cout<<a[th+2]<<" or "<<a[id];
        }
        cout<<" THEN ";
        if(th==2) cout<<"not "<<a[th-1];
        else if(th==3) cout<<a[th-1];
        else if(th==4){
            if(a[th-2]=="or") cout<<"not "<<a[th-3]<<" and not "<<a[th-1];
            else cout<<"not "<<a[th-3]<<" or not "<<a[th-1];
        }else if(th==5){
            if(a[th-3]=="and") cout<<"not "<<a[th-4]<<" or "<<a[th-1];
            else if(a[th-2]=="and") cout<<a[th-3]<<" or not "<<a[th-1];
            else if(a[th-3]=="or") cout<<"not "<<a[th-4]<<" and "<<a[th-1];
            else if(a[th-2]=="or") cout<<a[th-3]<<" and not "<<a[th-1];
        }else if(th==6){
            if(a[th-3]=="and") cout<<a[th-4]<<" or "<<a[th-1];
            else cout<<a[th-4]<<" and "<<a[th-1];
        }
        if(n>=0) cout<<"\n";
    }
    return 0;
}
