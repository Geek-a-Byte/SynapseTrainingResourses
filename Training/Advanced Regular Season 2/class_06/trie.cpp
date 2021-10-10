#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    bool isEnd;
    node* next[26];
    node()
    {
        isEnd = false;
        for(int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
    }
};

void insert_item(node* root, string &str)
{
    node* curr = root;
    for (auto c : str)
    {
        int v = c - 'a';
        if (curr -> next[v] == NULL)
        {
            curr -> next[v] = new node();
        }
        curr = curr -> next[v];
    }
    curr -> isEnd = true;
}

bool exists(node* root, string &str, bool search_prefix = false)
{
    node* curr = root;
    for (auto c : str)
    {
        int v = c - 'a';
        if (curr -> next[v] == NULL)
        {
            return false;
        }
        curr = curr -> next[v];
    }
    return search_prefix || (curr && curr -> isEnd);
}

void remove_trie(node *root)
{
    if(root == NULL) return;
    for (int i = 0; i < 26; i++)
    {
        remove_trie(root->next[i]);
    }
    free(root);
}

int main()
{
    node* root = new node();
    string str = "sakib";
    insert_item(root, str);
    str = "sajib";
    insert_item(root, str);
    str = "sa";
    cout << exists(root, str) << "\n";
    remove_trie(root);
    return 0;
}
