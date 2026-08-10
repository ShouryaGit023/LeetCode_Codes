class Trie {
public:
    Trie* children[26];
    bool end;
    Trie() {
        end=false;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
    
    void insert(string word) {
        Trie *curr=this;
        for(auto i:word){
            if(curr->children[i-'a']==nullptr){
                Trie* nn=new Trie();
                curr->children[i-'a']=nn;
            }
            curr=curr->children[i-'a'];
        }
        curr->end=true;
    }
    
    bool search(string word) {
        if(!this)return false;
        Trie* curr=this;
        for(auto i:word){
            if(curr->children[i-'a']==nullptr){
                return false;
            }
            curr=curr->children[i-'a'];
        }
        return curr->end;
        
    }
    
    bool startsWith(string prefix) {
        Trie* curr=this;
        for(auto i:prefix){
            if(curr->children[i-'a']==nullptr){
                return false;
            }
            curr=curr->children[i-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */