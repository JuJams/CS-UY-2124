/*
    rec14 Recursion and Exceptions
 */

#include <iostream>
#include <vector>
#include <algorithm>  // max
using namespace std;


// Node type for the linked list
struct Node {
    int data = 0;
    Node* next = nullptr;
};

// Node type for the binary tree
struct TNode {
    int data = 0;
    TNode* left = nullptr;
    TNode* mid = nullptr;
    TNode* right = nullptr;
};



/////////////////////////////////////////////////////////////////////////
//
// Provided code for use in testing
//
void listPrint(const Node* headPtr);
void listClear(Node*& headPtr);
Node* listBuild(const vector<int>& vals);


//
// Your functions go here
//
//   Task 1 function:
Node* listSum(Node*& list1,Node*& list2){
    if (list1 == nullptr && list2 == nullptr) return nullptr;
    else {
        if(list1 != nullptr && list2 != nullptr){
            Node* summy = new Node{list1->data + list2->data, listSum(list1->next,list2->next)};
            return summy;
        }
        else if(list1 == nullptr){
            Node* summy = new Node{list2->data, listSum(list1,list2->next)};
            return summy;
        }
        else{
            Node* summy = new Node{list1->data, listSum(list1->next,list2)};
            return summy;
        }
    }
}

//   Task 2 function:
int treeMax(TNode* node){
    if (node == nullptr){
        throw invalid_argument("Maximum cannot be defined");
    }
    else{

    }
    if(node->left == nullptr && node->right == nullptr && node->mid == nullptr) return node->data;
    else{
        // if(node->left != nullptr && node->mid != nullptr && node->right != nullptr ){
        //     return max(max(treeMax(node->left),treeMax(node->mid)), treeMax(node->right));
        // }
        // else if(node->left == nullptr && node->mid != nullptr && node->right != nullptr ){
        //     return max(treeMax(node->mid), treeMax(node->right));
        // }
        // else if(node->left != nullptr && node->mid == nullptr && node->right != nullptr ){
        //     return max(treeMax(node->left), treeMax(node->right));
        // }
        // else if(node->left != nullptr && node->mid != nullptr && node->right == nullptr ){
        //     return max(treeMax(node->left), treeMax(node->mid));
        // }
        // else if(node->left != nullptr && node->mid == nullptr && node->right == nullptr ){
        //     return treeMax(node->left);
        // }
        // else if(node->left == nullptr && node->mid != nullptr && node->right == nullptr ){
        //     return treeMax(node->mid);
        // }
        // else {
        //     return treeMax(node->right);
        // }
        int maxy = node->data;
        if (node->left != nullptr){
            maxy = max(maxy, treeMax(node->left));
        }  
        if (node->mid != nullptr){
            maxy = max(maxy, treeMax(node->mid));
        } 
        if (node->right != nullptr){
            maxy = max(maxy, treeMax(node->right));
        }  
        return maxy;
    }
}

//   Task 3 function:
bool palindrome(char* word, int len){
    if (len < 2){
        return true;
    }
    if (word[0]!= word[len-1]){
        return false;
    }
    return palindrome(word+1, len-2);
}


//   Task 4 function:
bool parity(int num) {
    if (num < 2){
        return 1 - num;
    } 
    if (num % 2){
        return !parity(num/2);
    } 
    else{
        return parity(num/2);
    } 
}

//   Task 5 function:
int towers(int num, char start, char target, char spare) {
    if (num == 0){
        return 0;
    }
    int moves = 2 * towers(num - 1, start, spare, target) + 1;
    cout << "towers(" << num << ", '" << start << "', '" << target << 
    "', '" << spare << "'): " << moves << endl;
    return moves;
}

// Task 6
void mystery (int n){
    if (n > 1){
        cout << 'a';
        mystery(n/2);
        cout<< 'b';
        mystery(n/2);
    }
    cout<<'c';
}



/*
1 c
2 acbcc
4 aacbccbacbccc
8 aaacbccbacbcccbaacbccbacbcccc
16


*/


int main() {
    // We have provided some test code to save you time. Certainly fee
    // free to write more!

    // Task 1:
    cout << "\n==============\n#1: Testing listSum\n";
    Node* l1 = listBuild({2, 7, 1, 8});
    cout << "List (l1): ";
    listPrint(l1);
    
    Node* l2 = listBuild({9, 1, 4, 1});
    cout << "List (l2): ";
    listPrint(l2);

    Node* l3 = listBuild({3, 1, 4, 1, 5, 9});
    cout << "List (l3): ";
    listPrint(l3);

    cout << "The sum of l1 and l2: ";
    Node* l4 = listSum(l1, l2);
    listPrint(l4);

    cout << "The sum of l1 and l3: ";
    Node* l5 = listSum(l1, l3);
    listPrint(l5);

    cout << "The sum of l3 and l1: ";
    Node* l6 = listSum(l3, l1);
    listPrint(l6);

    listClear(l1);
    listClear(l2);
    listClear(l3);
    listClear(l4);
    listClear(l5);
    listClear(l6);


    
    // Task 2:
    TNode a{1}, b{2}, c{4}, d{-8, &a, &b, &c}, e{-16}, f{-32, &d, &e};
    cout << "treeMax(&f): " << treeMax(&f) << endl;

    // How do you keep this from crashing? try/catch! Here in main!
    try {  
        treeMax(nullptr);
    } catch (exception& e) {
        cout << "caught an exception: " << e.what() << endl;
    }
    


    
    // Task 3:
    cout << "\n==============\n"
	 << "#3) Testing palindrome\n";
    cout << boolalpha
	 << "palindrome(\"racecar\", 7): " << palindrome("racecar", 7) << endl
	 << "palindrome(\"noon\", 4): " << palindrome("noon", 4) << endl
	 << "palindrome(\"raceXar\", 7): " << palindrome("raceXar", 7) << endl
	 << "palindrome(\"noXn\", 4): " << palindrome("noXn", 4) << endl;
    
    // Task 4:
    cout << "\n==============\n"
	 << "#4) Are there an even number of 1's in binary representation?\n";
    cout << boolalpha;
    for (int i = 0; i < 10; ++i) {
        cout << i << ": " << parity(i) << endl;
    }


    
    // Task 5:
    cout << "\n==============\n"
	 << "#5) How many moves are required for various sized towers?";
    for (int i = 1; i < 30; ++i) {
	cout << "towers(" << i << ", 'a', 'b', 'c'): " 
	     << towers(i, 'a', 'b', 'c') << endl;
    }

    
}


//
// The provided utility functions:
//

// listPrint prints out the data values in the list.
// All the values are printed on a single line with blanks separating them.
void listPrint(const Node* headPtr) {
    const Node* curr = headPtr;
    while (curr != nullptr) {
        cout << curr->data << ' ';
        curr = curr->next;
    }
    cout << endl;
}

// listClear frees up all of the nodes in list setting the the head
// pointer to null.
void listClear(Node*& headPtr) {
    while (headPtr) {
        Node* next = headPtr->next;
        delete headPtr;
        headPtr = next;
    }
}

// listBuild returns a list with the same values as in the vector.
Node* listBuild(const vector<int>& vals) {
    Node* result = nullptr;
    for (size_t index = vals.size(); index > 0; --index) {
	result = new Node{vals[index-1], result};
    }
    return result;
}
