#include <iostream>
#include <memory.h>
#include <set>
#include <algorithm>
#include <assert.h>

using namespace std;
const int MAXN = 5e4 + 50 ,MAXM = 2e5 + 50 ,INF = (1LL << 31) - 1;
const int MAXV = MAXN + MAXM;
class LCT {
    int ch[MAXV][2] ,par[MAXV] ,rev[MAXV] ,mini[MAXV] ,val[MAXV];
    int Get_Child(int x) { return (ch[par[x]][1] == x ? 1 : 0); }
    bool Is_Root(int x) { return par[x] == -1 || (ch[par[x]][0] != x && ch[par[x]][1] != x); }
    void Pull_Up(int x) {
        mini[x] = val[x];
        if(ch[x][0] != -1) mini[x] = min(mini[x] ,mini[ch[x][0]]);
        if(ch[x][1] != -1) mini[x] = min(mini[x] ,mini[ch[x][1]]);
    }
    void Send(int x) { swap(ch[x][0] ,ch[x][1]); rev[x] ^= 1; }
    void Push_Down(int x) {
        if(rev[x]) {
            if(ch[x][0] != -1) Send(ch[x][0]);
            if(ch[x][1] != -1) Send(ch[x][1]);
            rev[x] = 0;
        }
    }
    void Rotate(int x) {
        int p = par[x] ,pp = par[p] ,style = Get_Child(x) ,subtree = ch[x][style ^ 1];
        par[x] = pp;
        if(!Is_Root(p)) ch[pp][Get_Child(p)] = x;
        if(subtree != -1) par[subtree] = p;
        ch[p][style] = subtree;
        par[p] = x;
        ch[x][style ^ 1] = p;
        Pull_Up(p); Pull_Up(x);
        if(pp != -1) Pull_Up(pp);
    }
    void Update(int x) {
        //assert(par[x] != x);
        if(!Is_Root(x)) Update(par[x]);
        Push_Down(x);
    }
    void Splay(int x) {
        Update(x);
        for(int p;!Is_Root(x);Rotate(x)) {
            p = par[x];
            if(!Is_Root(p)) Rotate(Get_Child(x) == Get_Child(p) ? p : x);
        }
    }
    int Access(int x) {
        int pre = -1;
        while(x != -1) { Splay(x); ch[x][1] = pre; Pull_Up(x); pre = x; x = par[x];  }
        return pre;
    }
    void Make_Root(int x) { Access(x); Splay(x); swap(ch[x][0] ,ch[x][1]); rev[x] ^= 1; }
    int Get_Root(int x) {
        Access(x); Splay(x);
        while(ch[x][0] != -1) x = ch[x][0];
        Splay(x);
        return x;
    }
public:
    void Show(int x) {
        if(x == -1) return;
        Push_Down(x);
        Show(ch[x][0]);
        printf("x:%d\tp:%d\tL:%d\tR:%d\tV:%d\tM:%d\tR:%d\n" ,x ,par[x] ,ch[x][0] ,ch[x][1] ,val[x] ,mini[x] ,rev[x]);
        Show(ch[x][1]);
    }
    bool Same_Boss(int a ,int b) { return Get_Root(a) == Get_Root(b); }
    int Find_Min(int a ,int b) { Make_Root(a); return mini[Access(b)]; }
    void Cut(int a ,int b) { Make_Root(a); Access(b); Splay(b); par[a] = ch[b][0] = -1; Pull_Up(b); }
    void Link(int a ,int b) { Make_Root(a); par[a] = b;  }
    LCT() {
        memset(ch ,-1 ,sizeof(ch)); memset(par ,-1 ,sizeof(par)); memset(rev ,0 ,sizeof(rev));
        for(int i = 0;i < MAXV;i++) mini[i] = val[i] = (i >= MAXN ? i - MAXN : INF);
    }
} tree;

struct E { int src ,dst ,val; } edges[MAXM];
bool cmp(E a ,E b) { return a.val < b.val; }

void Cut(int e) { tree.Cut(edges[e].src ,MAXN + e); tree.Cut(edges[e].dst ,MAXN + e); }
void Link(int e) { tree.Link(edges[e].src ,MAXN + e); tree.Link(edges[e].dst ,MAXN + e); }

int main() {
    ios::sync_with_stdio(0) ,cin.tie(0);
    int N ,M ,temp ,ans = INF;
    int i ,lptr ,rptr;
    set<int> ids;
    cin >> N >> M;
    for(i = 0;i < M;i++) {
        cin >> edges[i].src >> edges[i].dst >> edges[i].val;
        if(edges[i].src == edges[i].dst) { i -= 1; M -= 1; }
    }
    sort(edges ,edges + M ,cmp);
    for(lptr = rptr = 0;lptr < M;lptr++) {
        while(!ids.empty() && *ids.begin() < lptr) {
            Cut(temp = *ids.begin());
            ids.erase(temp);
        }
        for(;ids.size() < N - 1 && rptr < M;rptr++) {
            if(tree.Same_Boss(edges[rptr].src ,edges[rptr].dst)) {
                Cut(temp = tree.Find_Min(edges[rptr].src ,edges[rptr].dst));
                ids.erase(temp);
            }
            Link(rptr); ids.insert(rptr);
        }
        if(ids.size() == N - 1) ans = min(ans ,edges[*ids.rbegin()].val - edges[*ids.begin()].val);
        else break;
    }
    cout << ans << endl;
}
