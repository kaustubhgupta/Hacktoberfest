/*
    Implementation of a trie that can maintain information of strings and supports insertion,checking if startswith the prefix and search methods on the strings.
    It inserts all the prefixes of the string into trie making a prefix tree which makes it very easy to implement searching and string matching problems.
*/

#include<bits/stdc++.h>
using namespace std;

// Declaring the node class with the features of the Trie.
class trieNode
{
public:
    char val;
    bool end;
    // for 26 characters an array of 26 pointers
    trieNode *children[26] = {NULL};
    // Constructor
    trieNode(char inVal, bool inEnd)
    {
        val = inVal;
        end = inEnd;
    }   
};
// Declaring the class with the functions of insert,search
class Trie {
private:
    trieNode *root;
       
public:
    /** Constructor of data structure */
    Trie() 
    {
        root = new trieNode('/', false);
    }
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        bool end = false;
        trieNode *parNode = root;
        trieNode *curNode = root;
        for(int i = 0; i < word.length(); i++)
        {
            // Is a end node of Trie DS.
            if(i == word.length() - 1)
            {
                end = true;
            }   
            // if not find children,creat new TireNode
            if(curNode->children[word[i] - 'a'] == NULL)
            {
                curNode->children[word[i] - 'a'] = new trieNode(word[i], end);
            }
            else 
            {
                //Marking the string as an end node
                if(end)
                    curNode->children[word[i] - 'a']->end = true;
            }
            // if find move to child node
             curNode = curNode->children[word[i] - 'a'];
        }       
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trieNode *curNode = root;
        for(int i = 0; i < word.length(); i++)
        {
            curNode = curNode->children[word[i] - 'a'];
            // String not found
            if(curNode == NULL)
            {
                return false;
            }            
        }
        // If reached the end 
        if(curNode->end)
        {
            return true;
        }
        else 
        {
            return false;
        }  
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        trieNode *curNode = root;
        for(int i = 0; i < prefix.length(); i++)
        {
            curNode = curNode->children[prefix[i] - 'a'];
            if(curNode == NULL)
            {
                return false;
            }
        }
        return true;
    }
};
/* Driver program to test above function */
int main(){
    // in search and startswith operations if output is 1 then the element was present else if 0 then not present in the DS.
    Trie trie;
    trie.insert("sunny");
    cout<<trie.search("sunny")<<'\n';   // returns true
    cout<<trie.search("sun")<<'\n';     // returns false
    cout<<trie.startsWith("sun")<<'\n'; // returns true
    trie.insert("sun");   
    cout<<trie.search("sun")<<'\n';     // returns true
}
