#include<stdio.h>
#define MAX 2147483647
#define NODE 300
#define QLEN 1000000
int con[NODE][NODE],cost[NODE][NODE],dist[NODE],from[NODE];
bool inq[NODE];
int arr[QLEN];
struct queue{
    int front,rear,*ar;
    void init(){
        front=rear=0;
        ar=arr;
    }
    int deq(){
        int x=ar[front];
        front=++front%QLEN;
        return x;
    }
    void enq(int a){
        ar[rear]=a;
        rear=++rear%QLEN;
    }
}q;
int n,t,max;
main(){
    while(scanf("%d",&n),n){
        //Initialize
        max=0;
        for(int i=0;i<NODE;i++)
            for(int j=0;j<NODE;j++)
                con[i][j]=cost[i][j]=0;
        for(int i=1;i<=n;i++)
            con[0][i]=con[i+150][NODE-1]=1;
        //Input
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                scanf("%d",&t);
                con[i][j+150]=1;
                cost[i][j+150]=-t;
                cost[j+150][i]=t;
                if(!t)con[i][j+150]=1;
            }
        while(1){
            //Initialize
            q.init();q.enq(0);
            int flow=MAX,now,m=0;
            for(int i=0;i<NODE;i++){
                dist[i]=MAX;inq[i]=0;
                from[i]=-1;
            }
            //SPFA
            dist[0]=0;inq[0]=1;
            while(q.front!=q.rear){
                now=q.deq();
                for(int i=0;i<=NODE;i++){
                    if(con[now][i]>0 && dist[i]>dist[now]+cost[now][i]){
                        dist[i]=dist[now]+cost[now][i];
                        from[i]=now;
                        if(!inq[i]){
                            inq[i]=1;
                            q.enq(i);
                        }
                    }
                }
                inq[now]=0;
            }
            if(from[NODE-1] == -1)break;
            for(now=NODE-1;now;now=from[now]){
                if(flow>con[from[now]][now])
                    flow=con[from[now]][now];
            }
            for(now=NODE-1;now;now=from[now]){
                m+=cost[from[now]][now];
                con[from[now]][now]-=flow;
                con[now][from[now]]+=flow;
            }
            if(m<=0)
                max+=m;
        }
        printf("%d\n",-max);
    }
}
