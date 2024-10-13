#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

// Node for Huffman Tree
struct HuffmanNode {
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

// Comparison object for priority queue (min-heap)
struct compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->freq > right->freq;
    }
};

// Function to print the Huffman codes
void printHuffmanCodes(HuffmanNode* root, string str) {
    if (!root) return;

    if (root->data != '$')  // '$' is a special marker for internal nodes
        cout << root->data << ": " << str << "\n";

    printHuffmanCodes(root->left, str + "0");
    printHuffmanCodes(root->right, str + "1");
}

// Function to implement Huffman Encoding
void huffmanEncoding(char data[], int freq[], int size) {
    // Create a min-heap (priority queue)
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> minHeap;

    // Create leaf nodes for each character and push into minHeap
    for (int i = 0; i < size; i++)
        minHeap.push(new HuffmanNode(data[i], freq[i]));

    // Iterate until heap has only one node (root of Huffman Tree)
    while (minHeap.size() != 1) {
        // Extract two nodes with minimum frequency
        HuffmanNode* left = minHeap.top();
        minHeap.pop();
        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with frequency equal to the sum of two nodes
        HuffmanNode* top = new HuffmanNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        // Add this node to the min-heap
        minHeap.push(top);
    }

    // Print Huffman codes (root node is in minHeap)
    printHuffmanCodes(minHeap.top(), "");
}

int main() {
    // Sample data
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(data) / sizeof(data[0]);

    huffmanEncoding(data, freq, size);

    return 0;
}
//chatgpt