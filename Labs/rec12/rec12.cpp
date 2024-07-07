/*
rec12.cpp
Implementing a linked list class
Implementing a linked list class with iterators
*/

#include <cstdlib>
#include <iostream>
using namespace std;



class List{
    struct Node;
    friend ostream& operator<<(ostream& os, const List& list){
        Node* current_node = list.head->next;
        while (current_node != list.tail) {
            os << current_node->data << " ";
            current_node = current_node->next;
        }
        return os;
    }
private:
    struct Node{
        int data = 0;
        Node* next = nullptr;
        Node* prev = nullptr;
    };
    Node* head; 
    Node* tail;
    size_t list_size;    
public: 
    List() {
    head = new Node;
    tail = new Node;
    head -> next = tail;
    tail -> prev = head;
    list_size = 0;
    }
    void push_back(int data) {
        Node* adding_node = new Node;
        adding_node->data = data;
        tail -> prev -> next = adding_node;
        adding_node -> prev = tail -> prev;
        tail -> prev = adding_node;
        adding_node -> next = tail;
        list_size += 1;
    }
    void pop_back() {
        if (list_size == 0) return;
        else {
            Node* removing_node = tail->prev;
            removing_node -> prev -> next = tail;
            tail -> prev = removing_node -> prev;
            delete removing_node;
            list_size -= 1;
        }
    }

    const int front() const{
        if (list_size != 0){
            return head -> next -> data;
        }
        else { return -1;}
        
    }
    int& front()  {
        return head ->next -> data;
    }
    const int back ()  const{
        int last_data = tail -> prev -> data;
        return last_data;
    }
    int& back () {
        return tail -> prev -> data;
    }
    size_t size () const { return list_size;}

    // Task 2
    void push_front(int data) {
        Node* adding_node = new Node;
        adding_node->data = data;
        adding_node->next = head->next;
        adding_node->prev = head;
        head->next->prev = adding_node;
        head->next = adding_node;
        list_size += 1;
    }

    void pop_front(){
        Node* removing_node = head -> next;
        if (list_size >= 1) {
            head-> next = head->next->next;
            head->next->prev = head;
            delete removing_node;
            list_size -= 1;
        }

    }

    // Task 3
    void clear(){
        while (list_size != 0){
            pop_back();
        }
    }

    // Task 4
    const int operator [] (size_t index) const {
        Node* current_node = head->next;
        for(size_t i = 0; i < index; i++){
            current_node = current_node->next;
        }
        return current_node->data;
    }
    int& operator [] (size_t index) {
        Node* current_node = head->next;
        for(size_t i = 0; i < index; i++){
            current_node = current_node->next;
        }
        return current_node->data;
    }

    // Task 5
    class iterator {
        friend bool operator==(const iterator& lhs, const iterator& rhs) {
            return rhs.pointer == lhs.pointer;
        }
        friend bool operator!=(const iterator& lhs, const iterator& rhs) {
            return rhs.pointer != lhs.pointer;
        }
        friend List;
        public:
            iterator(Node* head): pointer(head) {}
            iterator& operator++() {
                pointer = pointer->next;
                return *this;
            }
            iterator& operator--() {
                pointer = pointer->prev;
                return *this;
            }
            int& operator*(){
                return pointer->data;
            }
          //const int operator const(){
          //return pointer -> data;}
        private:
            Node* pointer;
    };
    iterator begin(){ return iterator(head->next);}
    iterator end(){ return iterator(tail);}

    // Task 6
    iterator insert(iterator iter, int data){
        Node* adding_node = new Node;
        adding_node->data = data;
        adding_node->next = iter.pointer;
        adding_node->prev = iter.pointer->prev;
        iter.pointer->prev->next = adding_node;
        iter.pointer->prev = adding_node;
        list_size += 1;
        iter.pointer = adding_node;
        return iter;
    }

    // Task 7
    iterator erase(const iterator& iter){
        Node* removing_node = iter.pointer;
        removing_node->prev->next = removing_node->next;
        removing_node->next->prev = removing_node->prev;
        delete removing_node;
        list_size -= 1;
        return iterator(removing_node->next);
    }

    // Task 8
    // Destructor
    ~List(){
        clear();
        delete head;
        head = nullptr;
        delete tail;
        tail = nullptr;
        cout << "~List ()"<< endl;
    }

    // Copy constructor
    List(const List& other) {
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
        list_size = 0;
        Node* current = other.head->next;
        for(;current != other.tail; current = current->next){
            push_back(current->data);
        }
    }

    // Assignment operator
    List& operator=(const List& rhs) {
        if (this == &rhs){return *this;}
        clear();
        Node* current = rhs.head->next;
        for(;current != rhs.tail; current = current->next){
            push_back(current->data);
        }
        cout<<"List::op=(List)"<<endl;
        return *this;
    }

};



// Task 1
void printListInfo(const List& myList) {
        cout << "size: " << myList.size()
             << ", front: " << myList.front()
             << ", back(): " << myList.back()
             << ", list: " << myList << endl;
}

/*
// The following should not compile. Check that it does not.
void changeFrontAndBackConst(const List& theList) {
    theList.front() = 17;
    theList.back() = 42;
} */

void changeFrontAndBack(List& theList) {
    theList.front() = 17;
    theList.back() = 42;
}


// Task 4
void printListSlow(const List& myList) {
    for (size_t i = 0; i < myList.size(); ++i) {
        cout << myList[i] << ' ';
    }
    cout << endl;
}

// Task 8
void doNothing(List aList) {
    cout << "In doNothing\n";
    printListInfo(aList);
    cout << "Leaving doNothing\n";
}    

int main() {

    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    
    cout << "Modify the first and last items, and display the results\n";
    changeFrontAndBack(myList);
    printListInfo(myList);
    cout << "===================\n";

    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";

    

    // Task 2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i*i << ");\n";
        myList.push_front(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_front();
    }
    printListInfo(myList);
    cout << "===================\n";

    // Task 3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.size() << ", list: " << myList << endl;
    cout << "===================\n";

    

    // Task 4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Now calling a function, printListSlow, to do the same thing\n";
    printListSlow(myList);
    cout << "Finally, for this task, using the index operator to modify\n"
         << "the data in the third item in the list\n"
         << "and then using printListSlow to display it again\n";
    myList[2] = 42;
    printListSlow(myList);
    
    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    // Note you can choose to nest the iterator class or not, your choice.
    //for (iterator iter = myList.begin(); iter != myList.end(); ++iter) {
    for (List::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";
    
    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
         << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";

    // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
    // ***Need test for erase other than begin/end***
    cout << "===================\n";

    

    // Task 8
    cout << "\n------Task Eight------\n";
    cout << "Copy control\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Calling doNothing(myList)\n";
    doNothing(myList);
    cout << "Back from doNothing(myList)\n";
    printListInfo(myList);

    cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
    List listTwo;
    for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
    printListInfo(listTwo);
    cout << "listTwo = myList\n";
    listTwo = myList;
    cout << "myList: ";
    printListInfo(myList);
    cout << "listTwo: ";
    printListInfo(listTwo);
    cout << "===================\n"; 
}


