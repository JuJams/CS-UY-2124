/*
  4.Tree
    - How can we use recursion on a binary tree if empty trees are permitted?
    - And how if they are not?
    - consider functions treeSum and treeMax
    - others? treeSumLeaves, treeReverse, ...
 */
#include <iostream>   // cout
#include <algorithm>  // max, min
using namespace std;

struct TNode {
    int data = 0;
    TNode* left = nullptr;
    TNode* right = nullptr;
};

// int treeSum(const TNode* root) {
//     it (root == nullptr) return 0;
//     treeSum(root->left) + treeSum(root->right) + root->data;
// }

// Don't pass null
int treeSum(const TNode* root) {
    //    treeSum(root->left) + treeSum(root->right) + root->data;
    int result= 0;
    if (root->left != nullptr) result += treeSum(root->left);
    if (root->right != nullptr) result += treeSum(root->right);
    return result + root->data;
}

int treeMin(const TNode* root) {
    return 0;
}

int main() {
    TNode* tree = new TNode{1};
    tree->left = new TNode{2};
    tree->right = new TNode{3};
    tree->left->left = new TNode{4};
    tree->left->right = new TNode{5};

    TNode* tree2 = new TNode{-1};
    tree2->left = new TNode{-2};
    tree2->right = new TNode{-3};
    tree2->left->left = new TNode{-4};
    tree2->left->right = new TNode{-5};

    cout << treeSum(tree) << ' ' << treeSum(tree2) << endl;
    cout << treeMin(tree) << ' ' << treeMin(tree2) << endl;

    TNode* tree3 = nullptr;

}
