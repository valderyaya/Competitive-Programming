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


int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    set<int> s;
    int n,m;
    cin>>n;
    while(n--){
        cin>>m;
        s.insert(m);
    }
    cout<<s.size()<<endl;
    for(set<int>::iterator it=s.begin();it!=s.end();it++){
        cout<<*it<<' ';
    }
//    system("pause");
    return 0;
}
