#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 1e4 + 50;
struct LCT {
    int ch[MAXN][2] ,tag[MAXN] ,par[MAXN];
    int Get_Child(int t) { return (ch[par[t]][1] == t ? 1 : 0); }
    bool Is_Root(int t) { return par[t] == -1 || (ch[par[t]][0] != t && ch[par[t]][1] != t); }
    void Push_Down(int t) {
        if(tag[t] != 0) {
            if(ch[t][0] != -1) swap(ch[ch[t][0]][0] ,ch[ch[t][0]][1]) ,tag[ch[t][0]] ^= 1;
            if(ch[t][1] != -1) swap(ch[ch[t][1]][0] ,ch[ch[t][1]][1]) ,tag[ch[t][1]] ^= 1;
            tag[t] = 0;
        }
    }
    void Rotate(int t) {
        int p = par[t] ,pp = par[par[t]] ,style = Get_Child(t) ,subtree = ch[t][style ^ 1];
        par[t] = pp;
        if(!Is_Root(p)) ch[pp][Get_Child(p)] = t;
        ch[p][style] = subtree;
        if(subtree != -1) par[subtree] = p;
        ch[t][style ^ 1] = p;
        par[p] = t;
    }
    void Update(int t) {
        if(!Is_Root(t)) Update(par[t]);
        Push_Down(t);
    }
    void Splay(int t) {
        Update(t);
        for(int p = par[t];!Is_Root(t);Rotate(t)) {
            p = par[t];
            if(!Is_Root(p)) Rotate(Get_Child(p) == Get_Child(t) ? p : t);
        }
    }
    int Access(int t) {
        int pre = -1;
        while(t != -1) {
            Splay(t);
            ch[t][1] = pre;
            pre = t;
            t = par[t];
        }
        return pre;
    }
    int Get_Root(int t) {
        for(Access(t) ,Splay(t);ch[t][0] != -1;t = ch[t][0]) ;
        Splay(t);
        return t;
    }
    void Make_Root(int t) {
        Access(t);
        Splay(t);
        swap(ch[t][0] ,ch[t][1]);
        tag[t] ^= 1;
    }
    LCT() {
        memset(ch ,-1 ,sizeof(ch));
        memset(par ,-1 ,sizeof(par));
        memset(tag ,0 ,sizeof(tag));
    }
} tree;

char cmd[32];
int main() {
    int N ,Q ,a ,b;
    scanf("%d%d", &N, &Q);
    tree = LCT();
    while(Q--) {
        scanf("%s%d%d" ,cmd ,&a ,&b);
        if(cmd[0] == 'C') {
            if(tree.Get_Root(a) != tree.Get_Root(b)) {
                tree.Make_Root(a);
                tree.par[a] = b;
            }
        } else if(cmd[0] == 'D') {
            tree.Make_Root(a);
            tree.Access(b);
            tree.Splay(b);
            if(tree.ch[b][0] == a && tree.ch[a][1] == -1) tree.ch[b][0] = tree.par[a] = -1;
        } else if(cmd[0] == 'Q') {
            printf(tree.Get_Root(a) == tree.Get_Root(b) ? "Yes\n" : "No\n");
        }
    }
}
