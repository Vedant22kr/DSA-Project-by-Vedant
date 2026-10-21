#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>
#include <numeric>
using namespace std;
 
struct Node {
    int data;
    Node *left, *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
 
Node* insertNode(Node* root, int value) {
    if (root == nullptr) return new Node(value);
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);
    return root;
}
 
Node* buildTree(const vector<int>& sequence) {
    Node* root = nullptr;
    for (int value : sequence) root = insertNode(root, value);
    return root;
}
 
int treeHeight(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(treeHeight(root->left), treeHeight(root->right));
}
 
// Counts one key comparison for every node visited.
int searchComparisons(Node* root, int key, bool& found) {
    int comparisons = 0;
    Node* current = root;
    found = false;
 
    while (current != nullptr) {
        comparisons++;
        if (key == current->data) {
            found = true;
            break;
        } else if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return comparisons;
}
 
void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
 
struct Result {
    int height;
    double avgSuccessful;
    double avgUnsuccessful;
};
 
Result analyseTree(Node* root, int n) {
    long long successfulTotal = 0;
    for (int key = 1; key <= n; ++key) {
        bool found;
        successfulTotal += searchComparisons(root, key, found);
    }
 
    // Test two keys outside the stored range.
    long long unsuccessfulTotal = 0;
    bool found;
    unsuccessfulTotal += searchComparisons(root, 0, found);
    unsuccessfulTotal += searchComparisons(root, n + 1, found);
 
    return {treeHeight(root),
            static_cast<double>(successfulTotal) / n,
            static_cast<double>(unsuccessfulTotal) / 2.0};
}
 
int main() {
    vector<int> sizes = {5, 10, 20, 50, 100};
    mt19937 generator(42); // fixed seed makes results repeatable
 
    cout << "BST HEIGHT AND SEARCH COMPARISON ANALYSIS\\n";
    cout << "Comparisons = number of nodes visited during a search\\n\\n";
    cout << left << setw(8) << "Size"
         << setw(14) << "Insertion"
         << setw(10) << "Height"
         << setw(20) << "Avg Success"
         << setw(20) << "Avg Unsuccess" << '\\n';
    cout << string(72, '-') << '\\n';
 
    for (int n : sizes) {
        vector<int> ascending;
        for (int i = 1; i <= n; ++i) ascending.push_back(i);
 
        vector<int> descending = ascending;
        reverse(descending.begin(), descending.end());
 
        vector<int> randomOrder = ascending;
        shuffle(randomOrder.begin(), randomOrder.end(), generator);
 
        vector<pair<string, vector<int>>> orders = {
            {"Ascending", ascending},
            {"Descending", descending},
            {"Random", randomOrder}
        };
 
        for (const auto& item : orders) {
            Node* root = buildTree(item.second);
            Result r = analyseTree(root, n);
 
            cout << left << setw(8) << n
                 << setw(14) << item.first
                 << setw(10) << r.height
                 << setw(20) << fixed << setprecision(2) << r.avgSuccessful
                 << setw(20) << r.avgUnsuccessful << '\\n';
 
            deleteTree(root);
        }
        cout << '\\n';
    }
 
    cout << "Note: Random-order heights depend on the shuffled sequence.\\n";
    cout << "Unsuccessful searches are tested with keys 0 and n+1.\\n";
    return 0;
}
