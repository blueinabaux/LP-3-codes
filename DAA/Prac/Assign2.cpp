#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char ch;
    int freq;
    Node *left;
    Node *right;

    Node(char c, int f)
    {
        this->ch = c;
        this->freq = f;
        left = NULL;
        right = NULL;
    }
};

class Compare
{

public:
    bool operator()(Node *l, Node *r)
    {
        if (l->freq == r->freq)
        {
            return l->ch > r->ch;
        }
        return l->freq > r->freq;
    }
};

class HuffmannAlgo
{
public:
    Node *root;
    map<char, string> mp;

    void generateCode(Node *root, string str)
    {
        if (root == NULL)
        {
            return;
        }

        if (!root->left && !root->right)
        {
            mp[root->ch] = str;
            return;
        }

        generateCode(root->left, str + "0");
        generateCode(root->right, str + "1");
    }

    void displayCodes()
    {
        for (auto pair : mp)
        {
            cout << pair.first << " : " << pair.second << endl;
        }
    }

    void buildTree()
    {
        priority_queue<Node *, vector<Node *>, Compare> minHeap;

        int n;
        cout << "Enter the number of unique characters and frequency: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            char ch;
            int freq;
            cin >> ch >> freq;
            minHeap.push(new Node(ch, freq));
        }

        while (minHeap.size() > 1)
        {
            Node *left = minHeap.top();
            minHeap.pop();

            Node *right = minHeap.top();
            minHeap.pop();

            Node *parent = new Node('$', left->freq + right->freq);

            parent->left = left;
            parent->right = right;

            minHeap.push(parent);
        }

        this->root = minHeap.top();
        mp.clear();
        generateCode(this->root, "");
    }

    string encode(string str)
    {
        string res = "";

        for (auto x : str)
        {
            if (mp.find(x) != mp.end())
            {
                res += mp[x];
            }
        }

        return res;
    }

    string decode(string str)
    {
        string res = "";

        Node *curr = root;
        for (auto ch : str)
        {
            if (ch == '0')
            {
                curr = curr->left;
            }
            else if (ch == '1')
            {
                curr = curr->right;
            }
            if (!curr->left && !curr->right)
            {
                res += curr->ch;
                curr = root;
            }
        }

        return res;
    }
};

int main()
{

    HuffmannAlgo obj;
    while (true)
    {
        cout << "Enter 1 to Build Huffmann Tree" << endl;
        cout << "Enter 2 to Display the characters adn their hashcodes" << endl;
        cout << "Enter 3 to Encode the String" << endl;
        cout << "Enter 4 to Decode the String" << endl;
        cout << "Enter 0 to Exit" << endl;

        int op;
        cout << "Enter the option: ";
        cin >> op;

        switch (op)
        {
        case 1:
            obj.buildTree();
            break;

        case 2:
            obj.displayCodes();
            break;

        case 3:
        {
            string str;
            cout << "Enter the string to encode: ";
            cin >> str;
            string res = obj.encode(str);
            cout << "Encoded string: " << res << endl;
            break;
        }

        case 4:
        {
            string str;
            cout << "Enter the string to decode: ";
            cin >> str;
            string res = obj.decode(str);
            cout << "Decoded string: " << res << endl;
            break;
        }

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid option";
            break;
        }
    }

    return 0;
}