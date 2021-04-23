//#pragma GCC optimize("Ofast")
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
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

const int st=2e6+2,ed=2e6+3;
struct link{
    int pre[2000050],nxt[2000050];
    void init(){memset(pre,-1,sizeof(pre));memset(nxt,-1,sizeof(nxt));}
    void insert(int ptr,int self){
        int back=nxt[ptr];
        pre[self]=ptr;pre[back]=self;
        nxt[self]=back;nxt[ptr]=self;
    }
    void erase(int ptr){
        int front=pre[ptr],back=nxt[ptr];
        pre[back]=front;nxt[front]=back;
    }
    void cut(int l,int r){
        int front=pre[l],back=nxt[r];
        nxt[front]=back;pre[back]=front;
    }
    void linkup(int ptr,int l,int r){
        int back=nxt[ptr];
        pre[l]=ptr;nxt[r]=back;
        nxt[ptr]=l;pre[back]=r;
    }
}lst;
ll sum;
vector<int> ans;
int t,n,m,k,a,b,c,ptr;
int main(){Rosario
    cin>>t;
    while(t--){sum=0;
        cin>>n>>m>>k;
        lst.init();ans.clear();
        lst.pre[ed]=st,lst.nxt[st]=ed;lst.insert(st,k);
        while(m--){
            cin>>k>>a>>b>>c;
            if(k==1){
                if(c==1) b=lst.pre[b];
                 lst.insert(b,a);
            }else if(k==2){
                lst.cut(a,b);
                lst.linkup(lst.pre[c],a,b);
            }else{
                if(c==1){
                    while(a!=st&&b>0){
                        ans.em(a);
                        ptr=lst.pre[a];
                        lst.erase(a);
                        a=ptr;b--;
                    }
                }else{
                    while(a!=ed&&b>0){
                        ans.em(a);
                        ptr=lst.nxt[a];
                        lst.erase(a);
                        a=ptr;b--;
                    }
                }
                sum+=b;
            }
        }cout<<sum<<"\n";
        for(int i:ans) cout<<i<<"\n";
    }
//    system("pause");
    return 0;
}
