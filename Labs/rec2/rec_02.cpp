#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct compound {
    vector<string> string_vector;
    int num_c;
    int num_h;
};

// Function prototypes
void open_vector(ifstream& ifs);
void fill_vector(ifstream& ifs, vector<compound>& compounds);
void insert_vector(vector<compound>& compounds, const string& formula, int num_c, int num_h);
size_t find_vector(int num_c, int num_h, const vector<compound>& compounds);
void sorting_vector(vector<compound>& compounds);
void display_vector(const vector<compound>& compounds);
void print_vector(const compound& compound);

int main() {
    ifstream ifs;
    open_vector(ifs);

    vector<compound> compounds;
    fill_vector(ifs, compounds);
    ifs.close();
    display_vector(compounds);
    sorting_vector(compounds);
    
}

void open_vector(ifstream& ifs) {
    do {
        string file_name;
        cout << "Enter the file name: " << endl;
        cin >> file_name;
        ifs.open(file_name);

        if (!ifs) {
            cerr << "Unable to open: " << file_name << endl;
        }

    } while (!ifs);
}

void fill_vector(ifstream& ifs,vector<compound>& compounds) {
    string formula;
    char CH;
    int num_c;
    int num_h;

    while (ifs>>formula>>CH>>num_c>>CH>>num_h) {
        insert_vector(compounds,formula,num_c,num_h);
    }
}

void insert_vector(vector<compound>& compounds,const string& formula,int num_c,int num_h) {
    size_t location;
    location = find_vector(num_c,num_h,compounds);
    compound new_formula;

    if (location == compounds.size()) {
        new_formula.string_vector.push_back(formula);
        new_formula.num_c = num_c;
        new_formula.num_h = num_h;
        compounds.push_back(new_formula);
    } else {
        compounds[location].string_vector.push_back(formula);
    }
}

size_t find_vector(int num_c,int num_h,const vector<compound>& compounds) {
    for (size_t index=0;index<compounds.size();++index) {
        if (compounds[index].num_c==num_c && compounds[index].num_h==num_h) {
            return index;
        }
    }
    return compounds.size();
}

void sorting_vector(vector<compound>& compounds) {
    for (size_t i = 0;i<compounds.size();i++) {
        for (size_t j = 0;j<compounds.size()-1;j++) {
            if (compounds[j].num_c>compounds[j + 1].num_c) {
                compound sort_1;
                sort_1=compounds[j];
                compounds[j]=compounds[j + 1];
                compounds[j + 1] = sort_1;
            } else if (compounds[j].num_c==compounds[j + 1].num_c && compounds[j].num_h>compounds[j + 1].num_h) {
                compound sort_2;
                sort_2 = compounds[j];
                compounds[j] = compounds[j+1];
                compounds[j + 1] = sort_2;
            }
        }
    }
}

void display_vector(const vector<compound>& compounds) {
    for (const compound& compound:compounds) {
        print_vector(compound);
    }
}

void print_vector(const compound& compound) {
    string formula_print;
    for (const string& formula:compound.string_vector) {
        formula_print=formula_print+formula+' ';
    }
    cout <<'C'<<compound.num_c<<'H'<<compound.num_h<<' '<<formula_print<<endl;
}


