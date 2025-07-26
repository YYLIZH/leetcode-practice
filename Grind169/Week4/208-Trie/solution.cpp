#include <string>

using namespace std;

class TrieNode
{
public:
    bool endOfWord;
    TrieNode *children[26];

    TrieNode()
    {
        endOfWord = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *curr = root;

        for (char c : word)
        {
            int index = c - 'a';

            if (curr->children[index] == NULL)
            {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->endOfWord = true;
    }

    bool search(string word)
    {
        TrieNode *curr = root;

        for (char c : word)
        {
            int index = c - 'a';
            curr = curr->children[index];
            if (curr == NULL)
            {
                return false; // Not reach not exist
            }
        }

        return curr->endOfWord; // is not end of word
    }

    bool startsWith(string prefix)
    {
        TrieNode *curr = root;

        for (char c : prefix)
        {
            int index = c - 'a';
            curr = curr->children[index];

            if (curr == NULL)
            {
                return false;
            }
        }
        return true;
    }

    ~Trie()
    {
        clear(root);
    }

    void clear(TrieNode *node)
    {
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] != NULL)
            {
                clear(node->children[i]);
            }
        }

        delete node;
    }
};