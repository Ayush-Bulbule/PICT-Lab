/**
 * Problem Statement: Write a program to implement Huffman Encoding using a greedy strategy.
 * Must Watch: https://youtu.be/uDS8AkTAcIU?si=J79pJbEHLW588mcA
 */
  

#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode{
    char data;  // character
    int freq;  // freuency of the character
    MinHeapNode *left, *right; 


    MinHeapNode(char data, int freq){
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(struct MinHeapNode* left, MinHeapNode* right){
        return (left->freq > right->freq);
    }
};

// Function to print HuffMan Tree() (hint: preorder)
void printCodes(struct MinHeapNode* root, string code){
    if(!root)
        return;

    // if node is a leaf node then only print the character
    if(!root->left && !root->right)
        cout<< root->data<<" : "<<code<<"\n"<<endl;
    
    // traverse left and right subtrees with added code "0" and "1" imp. step to get correct code
    printCodes(root->left, code+"0");
    printCodes(root->right, code+"1");
}

// Build Huffman Tree
void HuffmanCodes(vector<char> &data, vector<int>& freq){
    int n = data.size();

    // create a min heap(priority queue)
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for(int i =0;i<n;i++){
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }

    // Iterate until the heap contains only one node (root of the Huffman Tree)
    while(minHeap.size() != 1){
        MinHeapNode *left = minHeap.top(); minHeap.pop();
        MinHeapNode *right = minHeap.top(); minHeap.pop();

        MinHeapNode *top = new MinHeapNode('$', left->freq+right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // Print Huffman Codes using the tree built above
    printCodes(minHeap.top(), "");
}


int main(){

    vector<char> data = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    cout << "Huffman Codes:\n";
    HuffmanCodes(data, freq);

    return 0;
}