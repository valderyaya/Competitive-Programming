#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)


int n,l,r;
string s;
int main(){Rosario
    while(cin>>n,n){
        cin>>s;l=0,r=1e9;
        queue<int> q;int c[26]={},w=0;
        REP(i,s.size()){
            if(c[s[i]-'a']==0) w++;
            q.emplace(i);c[s[i]-'a']++;
            if(w!=26) continue;
            while(c[s[q.front()]-'a']>1) c[s[q.front()]-'a']--,q.pop();
            if(i-q.front()<r-l) l=q.front(),r=i;
        }
        if(w!=26) cout<<"not found";
        else for(;l<=r;l++) cout<<s[l];
        cout<<"\n";
    }
//    system("pause");
    return 0;
}
