#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second


int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s;int i,j=0;
    cin>>s;
    i=stoi(s);
    while(i){
        j=j*10+i%10;
        i/=10;
    }
    cout<<j<<endl;
//    system("pause");
    return 0;
}
