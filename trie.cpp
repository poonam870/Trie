#include <algorithm>
#include <iostream>
#include <vector>
#include<queue>

using namespace std;
class Node{
    public:
    bool isTerminal;
    Node* child[26];
    Node(){
        isTerminal=false;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};
    void add(string word,Node *trie){
        int n=word.size();
        for(int i=0;i<n;i++){
            if(trie->child[word[i]-'A']==NULL){
                trie->child[word[i]-'A']=new Node();
            }
            trie=trie->child[word[i]-'A'];
        }
        trie->isTerminal=true;
    }
    bool search(string word,Node*trie){
        int n=word.size();
        for(int i=0;i<n;i++){
            if(trie->child[word[i]-'A']==NULL) return false;
            trie=trie->child[word[i]-'A'];
        }
        return trie->isTerminal;
        
    }

int main() {
    vector<string>dict;
    dict.push_back("ARE");
    dict.push_back("HELLO");
    dict.push_back("AIR");
    Node* root=new Node();
    for(int i=0;i<dict.size();i++){
        add(dict[i],root);
    }
   cout<<search("ARE",root)<<endl;
   cout<<search("HLO",root);
    
	
	return 0;
}
