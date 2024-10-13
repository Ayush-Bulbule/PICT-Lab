### Huffman Encoding Program (C++)

Write a program to implement Huffman Encoding using a greedy strategy.

```cpp
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
```

#### How Huffman Encoding Works:
1. **Min-Heap Construction**: The frequency of characters is used to build a min-heap.
2. **Merge Two Minimums**: The two least frequent nodes are extracted and merged to form a new internal node.
3. **Tree Building**: Repeat the process until one node (root) remains, forming a binary tree.
4. **Assign Codes**: Traverse the tree to assign '0' and '1' to edges, producing the Huffman codes.

#### Example Input:
Characters: `{ 'a', 'b', 'c', 'd', 'e', 'f' }`  
Frequencies: `{ 5, 9, 12, 13, 16, 45 }`

#### Example Output:
```
f: 0
c: 100
d: 101
a: 1100
b: 1101
e: 111
```

#### Time Complexity:
- **Heap operations**: O(n log n) (for inserting and extracting nodes)
- **Overall**: O(n log n)

#### Space Complexity:
- **Space**: O(n) for heap and tree storage