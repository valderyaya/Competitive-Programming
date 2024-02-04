class WordDictionary {
public:
    struct Trie{
        char c;
        bool end;
        Trie *ch[26];
        void Tire(){
            for(int i = 0; i < 26; ++i) ch[i]=nullptr;
            end = 0;
        }
    }*rt;
    WordDictionary() {
        rt = new Trie();
    }
    
    void addWord(string word) {
        Trie *p = rt;
        for(auto &chr : word){
            int c = chr - 'a';
            if(!p->ch[c]) p->ch[c] = new Trie();
            p = p->ch[c];
        }
        p->end = 1;
    }
    bool dfs(Trie *p, string &word, int ind){
        if(ind >= (int)word.size()) return p->end;
        if(word[ind] == '.'){
            bool ret = 0;
            for(int i=0; i<26; ++i) if(p->ch[i]) ret |= dfs(p->ch[i], word, ind + 1);
            return ret;
        }else{
            int c = word[ind]-'a';
            if(!p->ch[c]) return 0;
            else return dfs(p->ch[c],word,ind+1);
        }
    }
    bool search(string word) {
        return dfs(rt, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
