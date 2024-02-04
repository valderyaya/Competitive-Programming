class Solution {
public:
    string simplifyPath(string s) {
        deque<string> dq;
        string str="";
        for(auto &i:s)
            if(i=='/'){
                if(!str.empty()&&str.back()!='/') str+='/';
            }else str+=i;
        stringstream ss(str);
        while(getline(ss,s,'/')){
            if(s==".") continue;
            else if(s==".."){
                if(!dq.empty()) dq.pop_back();
            }else if(s.size()) dq.push_back(s);
        }
        string ret=dq.empty()?"/":"";
        while(!dq.empty()){
            ret+="/"+dq.front();
            dq.pop_front();
        }
        return ret;
    }
};
