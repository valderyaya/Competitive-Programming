class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& v) {
        int ans=0,x=0,y=0,dir=0;
        for(int &i:commands){
            if(i==-1) dir=(dir+1)%4;
            else if(i==-2) dir=(dir+3)%4;
            else{
                if(dir==0){
                    int yy=y+i,mn=1e9;
                    for(int i=0;i<v.size();++i)
                        if(v[i].front()==x && v[i].back()<=yy && v[i].back()>y) mn=min(mn,v[i].back());
                    if(mn==1e9) y=yy;
                    else y=mn-1;
                }else if(dir==1) {
                    int xx=x+i,mn=1e9;
                    for(int i=0;i<v.size();++i)
                        if(v[i].back()==y && v[i].front()<=xx && v[i].front()>x) mn=min(mn,v[i].front());
                        if(mn==1e9) x=xx;
                        else x=mn-1;
                }else if(dir==2) { 
                    int yy=y-i,mn=-1e9;
                    for(int i=0;i<v.size();++i)
                        if(v[i].front()==x && v[i].back()>=yy && v[i].back()<y) mn=max(mn,v[i].back());
                    if(mn==-1e9) y=yy;
                    else y=mn+1;
                }else {
                    int xx=x-i,mn=-1e9;
                    for(int i=0;i<v.size();++i)
                        if(v[i].back()==y && v[i].front()>=xx && v[i].front()<x) mn=max(mn,v[i].front());
                    if(mn==-1e9) x=xx;
                    else x=mn+1;
                }
                ans=max(ans,x*x+y*y);
            }
        }
        return ans;
    }
};
