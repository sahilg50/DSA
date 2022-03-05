#include <iostream>
#include <string>

using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    /* Initialiaze the data structer here. */
    Trie()
    {
        root = new Node();
    }
    /* Insert the word into Trie. */
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
        }
        node->setEnd();
    }

    /* Returns True if the word is in the trie*/
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        if (node->isEnd())
        {
            return true;
        }
        return false;
    }

    /* Return true if there is any word starting with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main()
{

    Trie *obj = new Trie();
    obj->insert("Hello");
    cout << obj->search("Hell");
    cout << obj->startsWith("He");
    cout << obj->startsWith("zebra");

    return 0;
}