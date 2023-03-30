#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
struct node 
{
    node *nxt[26];
    node() 
    {
        for(int i = 0; i < 26; i++)
        {
            nxt[i] = NULL;
        }
        cnt++;
    }
};

node *root;
void insert_trie(string s) 
{
    node *cur = root;
    for (int i = 0; i < s.size(); ++i)
    {
        int imap = s[i] - 'a';
        // new node
        if(cur->nxt[imap] == NULL)
        {
            cur->nxt[imap] = new node();
        }
        // goto that node
        cur = cur->nxt[imap];
    }
}

bool search_trie(string s)
{
    node *cur = root;
    for (int i = 0; i < s.size(); ++i)
    {
        int imap = s[i] - 'a';
        if(cur->nxt[imap] == NULL)
        {
            return false;
        }
        // goto that node
        cur = cur->nxt[imap];
    }
    return true;
}

int main()
{

    root = new node();

    string text = "ababaaabbbbabbababa";
    string pat = "abba";

    int n = text.size();
    for (int i = 0; i < n; ++i)
    {
        insert_trie(text.substr(i));
    }

    search_trie(pat) ? cout << "Found" : cout << "Not Found"; 

    return 0;
}
