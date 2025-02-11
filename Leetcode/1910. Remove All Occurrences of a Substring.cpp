class Solution {
public:
    string removeOccurrences(string s, string part) {
        vector<int> fail(part.size()+1), p;
        for(int i=1,j;i<part.size();++i){
            j = fail[i-1];
            while(j && part[i]!=part[j]) j=fail[j-1];
            if(part[i] == part[j]) ++j;
            fail[i]=j;
	    }
        int i = 0;
        for(int j=0,k=0;k<s.size();++k){
            s[i++] = s[k];
            while(j && s[k]!=part[j]) j=fail[j-1];
            if(s[k]==part[j]) ++j;
            p.emplace_back(j);
            if(j==part.size()){
                i -= j;
                p.resize(i);
                j = i ? p.back() : 0;
		    }
        }
        s.resize(i);
        return s;
    }
};
