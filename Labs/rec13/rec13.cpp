// rec13.cpp
// Lab on STL

#include <iostream>
#include <fstream>
#include <vector>      // task 1 
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;

// Task 9
void printList(const list<int>& list_numbers){
    list<int>::const_iterator list_num = list_numbers.begin();
    // list<int>::iterator list_num = int_list.begin();
    while(list_num != list_numbers.end()){
        cout << *list_num <<" ";
        list_num++;
        }
    cout<<endl;
    }
// Task 10
void rangedForPrintList(const list<int>& list_numbers){
    for (int num : list_numbers){
        cout << num << " ";
    }
    cout << endl;
}
// Task 11
void autoPrint(const list<int>& list_numbers){
    for (auto num : list_numbers){
        cout << num << " ";
    }
    cout << endl;
}
// Task 12
list<int>::const_iterator listItem(const list<int>& list_numbers, int value){
    list<int>::const_iterator item = list_numbers.begin();
    while (item != list_numbers.end()){
        if (*item == value){
            return item;
        }
        item++;
    }
    return list_numbers.end();
}
// Task 13
auto findList(const list<int>& list_numbers, int value){ // auto
    for (auto num = list_numbers.begin(); num != list_numbers.end(); ++num){
        if(*num == value){
            return num;
        }
    }
    return list_numbers.end();
    
}
// Task 15
bool evenNum(int num2){
    return num2 % 2 == 0;
}
// Task 16
class findEven{
    public:
        bool operator()(int num) const { return num % 2 == 0;}
};
// Task 19
list<int>::iterator ourFind(list<int>::iterator start, list<int>::iterator stop, int value){
    for(list<int>::iterator dum = start; dum!= stop; dum++){
        if(*dum == value){
            return dum;
        }
    }
    return stop;
}

// Task 20
template<typename T, typename U>
T ourFind(T start, T stop, U value){
    for(T dum = start; dum!= stop; dum++){
        if(*dum == value){
            return dum;
        }
    }
    return stop;
}



int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> numbers = {2,3,1,6,5,4};
    for (int number : numbers){
        cout<<number<<" ";
    }

    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> list_numbers(numbers.begin(),numbers.end());
    for(int number: list_numbers){
        cout << number << " ";
    }

    cout << "\n=======\n";

    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    // Orginial vector
    sort(numbers.begin(), numbers.end());
    for(int number: numbers){
        cout << number << " ";
    }

    cout << "\n=======\n";

    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    for(int i=0; i<numbers.size(); i+=2){
        cout << numbers[i] << " ";
    }

    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
    /* for(int i=0; i < list_numbers.size(); i++){
        cout<< list_numbers[i]<<" ";  // Compilation error: Nooperator matches these operands
    } */

    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    vector<int>::iterator num = numbers.begin();
    while(num != numbers.end()){
        cout << *num << " ";
        num += 2;
    }

    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    list<int>::iterator list_num = list_numbers.begin();
    while(list_num != list_numbers.end()){
        cout << *list_num <<" ";
        list_num++;
        list_num++;
    }


    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
    list_numbers.sort();
    for( int num : list_numbers){
            cout << num << " ";
    }

    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    printList(list_numbers);

    cout << "=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    rangedForPrintList(list_numbers);
    cout << "=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    autoPrint(list_numbers);

    cout << "=======\n";

    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    int value = 5;
    list<int>::const_iterator item = findList(list_numbers,value);
    if(item == list_numbers.end()){
        cout << "Value not found" << endl;
    }
    else{
        cout << "Value found: " << *item << endl;
    }

    cout << "=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    int val = 8;
    cout<< *listItem(list_numbers, val);
    cout<<endl;
    cout << "=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    int value1 = 5;
    list<int>::iterator to_find = find(list_numbers.begin(), list_numbers.end(), value1);
    if(to_find == list_numbers.end()){
        cout << "Value not found" << endl;
    }
    else{
        cout << "Value found: " << *to_find << endl;
    }

    cout << "=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    list<int>::iterator even_num = find_if(list_numbers.begin(), list_numbers.end(), evenNum);
    if (even_num != list_numbers.end()){
        cout << "Even number found: " << *even_num << endl;
    }
    else{
        cout << "No even number found" << endl;
    }


    cout << "=======\n";

    // 16. Functor
    cout << "Task 16:\n";
    list<int>::iterator find_even = find_if(list_numbers.begin(), list_numbers.end(), findEven());
    if (find_even != list_numbers.end()){
        cout << "Even number found: " << *find_even << endl;
    }
    else{
        cout << "No even number found" << endl;
    }

    cout << "=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n"; 
    list<int>::iterator find_lambda = find_if(list_numbers.begin(), list_numbers.end(), [](int x){return x%2==0;});
    if (find_lambda != list_numbers.end()){
        cout << "Even number found: " << *find_lambda << endl;
    }
    else{
        cout << "No even number found" << endl;
    }

    cout << "=======\n";

    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int* arr1 = new int[numbers.size()];
    copy(list_numbers.begin(), list_numbers.end(), arr1);
    for(size_t i = 0; i < list_numbers.size(); i++){
        cout << arr1[i] << " ";
    }
    cout <<endl;
    int val3 = 10;
    int* pointer = find(arr1, arr1+list_numbers.size(), val3);
    if(pointer != arr1+list_numbers.size()){
        cout << "Value found: " << *pointer << endl;
    }
    else{
        cout << "Value not found" << endl;
    }
    delete[] arr1;
    cout << "=======\n";

    //
    // Templated Functions
    //

    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    int val4 =1;
    list<int>::iterator our_find = ourFind(list_numbers.begin(), list_numbers.end(), val4);
    if(our_find == list_numbers.end()){
        cout << "Value not found" << endl;
    }
    else{
        cout << "Value found: " << *our_find << endl;
    }

    cout << "=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    int val5 = 4;
    list<int>::iterator our_find1 = ourFind(list_numbers.begin(), list_numbers.end(), val5);
    if(our_find1 == list_numbers.end()){
        cout << "Value not found" << endl;
    }
    else{
        cout << "Value found: " << *our_find1 << endl;
    }

    cout << "=======\n";

    //
    // Associative collections
    //

    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
    vector<string> words;
    string token;
    ifstream ifs("pooh-nopunc.txt");
    if (!ifs){
        cerr << "Error opening file" << endl;
        exit(1);
    }
    while (ifs >> token){
        if (find(words.begin(), words.end(), token) == words.end()){
            words.push_back(token);
        }
    }
    ifs.close();
    cout << "Size " << words.size() << endl;
    for(size_t i =0; i < words.size(); i++){
        cout << words[i] << " ";
    }
    cout << "\n=======\n";

    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    set<string> words_set;
    ifstream ifs2("pooh-nopunc.txt");
    if (!ifs2){
        cerr << "Error opening file" << endl;
        exit(1);
    }
    while (ifs2 >> token){
        words_set.insert(token);
    }
    ifs2.close();
    cout << "Size " << words_set.size() <<endl;
    for (const string& word : words_set){
        cout << word << " ";
    }
    cout << "=======\n";

    // 23. Word co-occurence using map
    
    cout << "Task 23:\n";
    map<string, vector<int>> maps;
    string words1;
    int index = 0;
    ifstream ifs3("pooh-nopunc.txt");
    if (!ifs3){
        cerr << "Error opening file" << endl;
        exit(1);
    }
    while (ifs3 >> words1){
        maps[words1].push_back(index);
        index++;
    }
    ifs3.close();
    cout << "Size: " << maps.size() << endl;
    for(const auto& pair : maps){
        cout << pair.first << ": ";
        for(size_t i : pair.second){
            cout << i << " ";
        }
        cout << endl;
    }
    
    cout << "=======\n";
}

/*
class iterator{
    friend List;
    public:
        itearator(Node* head):pointer(head){}
        friend bool operator==(const iterator& rhs, const iterator& lhs){
            return rhs.pointer == lhs.pointer;
        }
        friend bool operator!=(const iterator& rhs, const iterator& lhs){
            return rhs.pointer != lhs.pointer;
        }
        iterator& operator++(){
            pointer = pointer->next;
            rteurn *this;
        }
        iterator& operator--(){
            pointer = pointer -> prev;
            return *this;
        }
        int& operator*(){
            return pointer -> data;
        }
    private:
        Node* pointer;
};

iterator begin(){return iterator(head->next);}
iterator end() {return iterator(tail);}
*/