// 1.listRecursion


#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data = 0;
    Node* next = nullptr;
};
Node* buildList(const vector<int>& vals);

//
// recursive list functions
//
// listDup

Node* listDup(const Node* p) {
    if (p == nullptr) return nullptr;
    return new Node{p->data, listDup(p->next)};
} // listDup

// listPrint
void listPrint(const Node* p)
{
    if (p == nullptr) {
        cout << endl;
    } else {
        cout << p->data << ' ';
        listPrint(p->next);
    }
} // listPrint

// End of recursive list functions


int main() {
    Node* myList = buildList({1, 1, 2, 3, 5, 8, 13, 21, 34, 55});

    listPrint(myList);
    Node* otherList = listDup(myList);
    listPrint(myList);
    listPrint(otherList);
}

Node* buildList(const vector<int>& vals) {
    Node* head = nullptr;
    for (size_t i = vals.size(); i > 0; --i) {
        head = new Node{vals[i-1], head};
    }
    return head;
}
