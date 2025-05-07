#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char ch, int freq) : ch(ch), freq(freq), left (nullptr),right(nullptr){}
    Node(char ch, int freq, Node* left, Node* right): ch(ch), freq(freq), left(left), right(right){}
};

struct compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

void print_codes(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if(root == nullptr)
        return;
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }
    print_codes(root->left, str + '0', huffmanCode);
    print_codes(root->right, str + '1', huffmanCode);
}

void buildHuffmanTree(string text) {

    unordered_map<char, int> freq;
    for(auto ch:text)
        freq[ch]++;
    priority_queue<Node*, vector<Node*>, compare> pq;

    for(auto pair:freq)
        pq.push(new Node(pair.first, pair.second));

    while(pq.size() != 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        int sum = left->freq + right->freq;
        pq.push(new Node('\0', sum, left, right));
    }

    Node* root = pq.top();
    unordered_map<char, string> huffmanCode;
    print_codes(root, "", huffmanCode);
    cout << "Huffman Codes:\n";

    for(auto pair:huffmanCode)
        cout << pair.first << ' ' << pair.second << endl;

}


int main()
{
    string str;
    cin >> str;
    buildHuffmanTree(str);
}
