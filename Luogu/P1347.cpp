//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,m,k;
set<int> s;
vector<int> v[28],in,now;
void print(){
    queue<int> q;
    now.resize(n);
    REP(i,26) for(auto &j:v[i]) ++now[j];
    REP(i,26) if(!now[i]&&s.count(i)) q.emplace(i),cout<<char('A'+i);
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(auto &j:v[x]) if(--now[j]==0) cout<<char('A'+j),q.emplace(j);
    }
}
void topo(){
    queue<pii> q;
    int sum=0,ans=0;
    REP(i,26) if(!in[i]&&s.count(i)) ++sum,q.emplace(mkp(i,1));
    while(!q.empty()){
        pii x=q.front(); q.pop();
        for(auto &i:v[x.F]){
            if(--now[i]==0){
                ++sum;
                q.emplace(mkp(i,x.S+1));
                ans=max(ans,x.S+1);
            }
        }
    }
    if(ans==n){
        cout<<"Sorted sequence determined after "<<k<<" relations: ";
        print(); cout<<".";
        exit(0);
    }
    if(sum!=s.size()){
        cout<<"Inconsistency found after "<<k<<" relations.\n";
        exit(0);
    }
}
int main(){Rosario
    cin>>n>>m;
    in.resize(n);
    char a,b,c;
    REP1(i,1,m){
        cin>>a>>b>>c;
        //cout<<a<<b<<c<<endl;
        v[a-'A'].em(c-'A');
        ++in[c-'A'];
        s.insert(a-'A'),s.insert(c-'A');
        now=in; k=i;
        topo();
    }
    cout<<"Sorted sequence cannot be determined.\n";
    return 0;
}
