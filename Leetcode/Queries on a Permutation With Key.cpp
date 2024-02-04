class Solution {
public:
struct Splay{
    int rt=0,tot=0,fa[2505],ch[2505][2],val[2505],sz[2505],cnt[2505],rk[2505];
    void up(int x){sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+cnt[x];}
    bool get(int x){return x==ch[fa[x]][1];}
    void clear(int x){ch[x][0]=ch[x][1]=fa[x]=sz[x]=cnt[x]=val[x]=0;}
    void build(int l,int r,int &o, int p){
        if(l>r) return ;
        if(!o) o = ++tot;
        int mid=(l+r)>>1;
        cnt[o]=sz[o]=1, val[o]=mid, fa[o]=p;
        rk[mid] = o;
        build(l,mid-1,ch[o][0],o);
        build(mid+1,r,ch[o][1],o);
        up(o);
    }
    void rotate(int x){
        int p=fa[x], pp=fa[p], chk=get(x);
        ch[p][chk]=ch[x][chk^1];
        if(ch[x][chk^1]) fa[ch[x][chk^1]]=p;
        ch[x][chk^1]=p;  fa[p]=x;  fa[x]=pp;
        if(pp) ch[pp][p==ch[pp][1]]=x;
        up(p);  up(x);
    }
    void splay(int x,int goal=0){
        for(int f;f=fa[x],f!=goal;rotate(x))
            if(fa[f]!=goal) rotate(get(x)==get(f)?f:x);
        if(!goal) rt=x;
    }
    void ins(int k){
        int cur=rt,p=0;
        while(cur){
            p=cur;
            cur=ch[cur][0];
        }
        cur=++tot;
        rk[k]=tot;
        if(p) ch[p][0]=cur;
        val[cur]=k, fa[cur]=p;
        sz[cur]=cnt[cur]=1;
        splay(cur);
    }
    int merge(int a,int b){
        if(!a||!b) return a+b;
        int cur=a;
        while(ch[cur][1]) cur=ch[cur][1];
        splay(cur);
        ch[cur][1]=b;
        fa[b]=cur;
        fa[cur]=0;
        up(cur);
        return cur;
    }
}tree;
    vector<int> processQueries(vector<int>& queries, int m) {
        tree.build(1,m,tree.rt,0);
        vector<int> ret;
        for(auto &i:queries){
            tree.splay(tree.rk[i]);
            ret.emplace_back(tree.sz[tree.ch[tree.rt][0]]);
            int a=tree.ch[tree.rt][0],b=tree.ch[tree.rt][1];
            tree.clear(tree.rt);
            tree.rt=tree.merge(a,b);
            tree.ins(i);
        }
        return ret;
    }
};
