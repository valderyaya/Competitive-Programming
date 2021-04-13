#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

map<string,vector<string>> m;
int n;
string a,b;
int main(){
    //oi;
    while(cin>>n,n){
        m.clear();
        bool ck=1;
        REP(i,n){
            cin>>a;
            b=a;sort(ALL(b));
            m[b].em(a);
        }
        vector<vector<string>> v;
        for(auto u:m){
            if(u.S.size()>1){
                ck=0;
                sort(ALL(u.S));
                v.em(u.S);
            }
        }
        if(ck)cout<<"No Answer\n";
        else{
            sort(ALL(v));
            REP(i,v.size()){
                REP(j,v[i].size()){
                    cout<<v[i][j]<<",\n"[j==v[i].size()-1];
                }
            }
        }
    }
 //   system("pause");
    return 0;
}
