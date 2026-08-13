#include <bits/stdc++.h>
using namespace std;

/* ------------------------------------------------------------ */
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const int INT_INF = numeric_limits<int>::max();
const long long LL_INF = numeric_limits<long long>::max();
/* ------------------------------------------------------------ */

struct Node
{
    char ch;     // Character for leaf nodes
    Node *left;  // Left
    Node *right; // Right

    Node() : ch('\0'), left(nullptr), right(nullptr) {}
};

Node *buildHuffmanTree(const unordered_map<char, string> &mapping)
{
    Node *root = new Node();

    for (const auto &pair : mapping)
    {
        char character = pair.first;
        string code = pair.second;

        Node *current = root;
        for (char bit : code)
        {
            if (bit == '0')
            {
                if (!current->left)
                {
                    current->left = new Node();
                }
                current = current->left;
            }
            else
            {
                if (!current->right)
                {
                    current->right = new Node();
                }
                current = current->right;
            }
        }
        current->ch = character;
    }

    return root;
}

int main()
{
    int k;
    cin >> k;

    unordered_map<char, string> mp;
    for (int i = 0; i < k; i++)
    {
        char c;
        string seq;
        cin >> c >> seq;
        mp[c] = seq;
    }

    string encoded, decoded;
    cin >> encoded;

    Node *root = buildHuffmanTree(mp);
    Node *current = root;
    for (char bit : encoded)
    {
        if (bit == '0')
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

        if (!current->left && !current->right)
        {
            decoded += current->ch;
            current = root;
        }
    }

    cout << decoded << endl;

    return 0;
}