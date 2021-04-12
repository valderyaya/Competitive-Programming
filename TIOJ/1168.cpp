#include "lib1168.h"
#include<bits/stdc++.h>
const int z=5e5+1;
struct  node{
    int v,id;
    bool operator<(const node &x){return v<x.v;}
};
struct heap{
    node a[z];
    int sz;
    void push(node x){
        a[sz++]=x;
        std::push_heap(a,a+sz);
        if(sz>=z) sz=z-1;
    }
    node top(){return a[0];}
    void pop(){
        std::pop_heap(a,a+sz);
        --sz;
    }
}mx,mn;
int cnt;
bool pp[z<<1];
inline void push(int x){
    mx.push({x,cnt});
    mn.push({-x,cnt++});
}
inline int big(){
    while(pp[mx.top().id]) mx.pop();
    return mx.top().v;
}
inline int small(){
    while(pp[mn.top().id]) mn.pop();
    return -mn.top().v;
}
inline void pop_big(){
    while(pp[mx.top().id]) mx.pop();
    pp[mx.top().id]=1; mx.pop();
}
inline void pop_small(){
    while(pp[mn.top().id]) mn.pop();
    pp[mn.top().id]=1; mn.pop();
}
