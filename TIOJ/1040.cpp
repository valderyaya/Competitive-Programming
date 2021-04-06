#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define oi ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll>

int t,n,m;
queue<int> q;
void dfs(int a,int b){
    int c=a/b,d=a%b;
    q.emplace(c);
    if(d==1||d==0){
        if(d)q.emplace(b);
        return;
    }
    dfs(b,d);
}
int main(){
    //oi;
    cin>>t;
    while(t--){
        cin>>n>>m;
        cout<<n<<'/'<<m<<" = ";
        while(q.size())q.pop();
        if(n==0) cout<<"0\n";
        else if(n>=m&&n%m==0) cout<<n/m<<"\n";
        else{
            int gcd=__gcd(n,m);
            dfs(n/gcd,m/gcd);
            int x=q.size()-2,y=0;
            cout<<q.front();q.pop();
            while(x--){
                cout<<"+1/{"<<q.front();
                q.pop();
                y++;
            }
            cout<<"+1/"<<q.front();
            q.pop();
            while(y--) cout<<'}';
            cout<<"\n";
        }
    }
//    system("pause");
    return 0;
}

