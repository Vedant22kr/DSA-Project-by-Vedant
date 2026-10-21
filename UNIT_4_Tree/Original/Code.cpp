#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std;
 
struct Node {
    int data;
    Node* left;
    Node* right;
 
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
 
Node* insertNode(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);
 
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);
 
    return root;
}
 
int treeHeight(Node* root) {
    if (root == nullptr)
        return 0;
 
    return 1 + max(treeHeight(root->left),
                   treeHeight(root->right));
}
 
Node* buildTree(const vector<int>& sequence) {
    Node* root = nullptr;
    for (int value : sequence)
        root = insertNode(root, value);
    return root;
}
 
void deleteTree(Node* root) {
    if (root == nullptr)
        return;
 
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
 
void printSequence(const vector<int>& sequence) {
    for (int value : sequence)
        cout << value << " ";
    cout << endl;
}
 
int main() {
    int n;
 
    cout << "BST HEIGHT ANALYSIS\\n";
    cout << "Enter number of elements (1-10000): ";
 
    if (!(cin >> n) || n < 1 || n > 10000) {
        cout << "Invalid input.\\n";
        return 1;
    }
 
    vector<int> ascending, descending, randomOrder;
 
    for (int i = 1; i <= n; i++)
        ascending.push_back(i);
 
    descending = ascending;
    reverse(descending.begin(), descending.end());
 
    randomOrder = ascending;
    mt19937 generator(
        static_cast<unsigned int>(time(nullptr)));
    shuffle(randomOrder.begin(), randomOrder.end(), generator);
 
    Node* rootAscending = buildTree(ascending);
    Node* rootDescending = buildTree(descending);
    Node* rootRandom = buildTree(randomOrder);
 
    int hAscending = treeHeight(rootAscending);
    int hDescending = treeHeight(rootDescending);
    int hRandom = treeHeight(rootRandom);
 
    cout << "\\nAscending sequence: ";
    printSequence(ascending);
    cout << "Descending sequence: ";
    printSequence(descending);
    cout << "Random sequence: ";
    printSequence(randomOrder);
 
    cout << "\\nHeight Comparison\\n";
    cout << left << setw(20) << "Sequence" << "Height\\n";
    cout << "------------------------------\\n";
    cout << left << setw(20) << "Ascending" << hAscending << endl;
    cout << left << setw(20) << "Descending" << hDescending << endl;
    cout << left << setw(20) << "Random" << hRandom << endl;
 
    cout << "\\nAnalysis:\\n";
    if (n == 1) {
        cout << "All three BSTs have height 1.\\n";
    } else {
        cout << "Ascending and descending trees are skewed.\\n";
        cout << "Both heights are equal to n = " << n << ".\\n";
        cout << "Random tree height depends on insertion order.\\n";
    }
 
    deleteTree(rootAscending);
    deleteTree(rootDescending);
    deleteTree(rootRandom);
 
    cout << "Program completed successfully.\\n";
    return 0;
}

 
