/*
rec05.cpp
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// To-do:
// Four classes: TA, Section, Time slot, Student grades
// Create a grade class to keep students and their lab grades
// Create a section class with time slot class inside it
// Functions to update the student lab grades
// Put an overloading operator to print all the details

class Section;
class studentGrade {
    // Protoype
    public:
        friend ostream& operator<<(ostream& os, const Section& sec);
        // Constructor and the initialisation list
        studentGrade(const string& student)
            : student(student),grades(14, -1) {}  
        // Getter and Setter
        const string& getStudent() const { return student; }
        void setGrade(int grade, int lab) {
            grades[lab - 1] = grade;
        }
    private:
        string student;
        vector<int> grades;
    };

class Section {
    // Prototype
    friend ostream& operator<<(ostream& os, const Section& sec);

    public:
        class TimeSlot {
            // Prototype
            friend ostream& operator<<(ostream& os, const Section& sec);

            public:
                // Constructor and the initialisation list
                TimeSlot(const string& day, int start)
                    : day(day), start(start) {}

            private:
                string day;
                int start;
        };
        // Section constructor
        Section(const string& secName, const string& day, int start)
            : secName(secName), timeSlot(day, start) {} 

        // Copy constructor
        Section(const Section& nextSec)  
            : secName(nextSec.secName), timeSlot(nextSec.timeSlot) {
            for (size_t i = 0; i < nextSec.grades.size(); i++) {
                grades.emplace_back(new studentGrade(*nextSec.grades[i]));
            }
        }

        // Getters and Setters
        // vector<studentGrade*>& getGrades() {return grades;}
        void addStudent(const string& student) {
            grades.emplace_back(new studentGrade(student));
        }
        void addGrade(const string& student, int grade, int lab) {
            // Loop to go through grades vector which has ptrs to studentGrade objects
            for (studentGrade*& gradePointer : grades) {
                if (gradePointer->getStudent() == student) {
                    gradePointer->setGrade(grade, lab);
                    
                }
            }
             
        }
        // Destructor
        ~Section() {  
            cout << "Section " << secName << " is being deleted" << endl;
            for (studentGrade*& grade : grades) {
                cout << "deleting " << grade->getStudent() << endl;
                delete grade;
            }
        } 

    private:
        string secName;
        TimeSlot timeSlot;
        vector<studentGrade*> grades;  
    };


class LabWorker {
    // Protoype
    friend ostream& operator<<(ostream& os, const LabWorker& worker);

    public:
        // Constructor and Initialisation list
        LabWorker(const string& name) : name(name), section(nullptr) {}
        void addSection(Section& sec) { section = &sec; }
        void addGrade(const string& student, int grade, int lab) {
            section->addGrade(student,grade,lab);
            }

    private:
        string name;
        Section* section;
    };





// Test code
void doNothing(Section sec) { cout << sec << endl; }

int main() {

    cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    cout << secA2 << endl;

    cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    cout << secA2 << endl;

    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe( "Moe" );
    cout << moe << endl;

    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection( secA2 );
    cout << moe << endl;

    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection( secB3 );
    cout << jane << endl;

    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);  
    moe.addGrade("Paul", 19, 1);  
    moe.addGrade("George", 16, 1);  
    moe.addGrade("Ringo", 7, 1);  
    cout << moe << endl;

    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);  
    moe.addGrade("Paul", 20, 3);  
    moe.addGrade("Ringo", 0, 3);  
    moe.addGrade("George", 16, 3);  
    cout << moe << endl;

    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
          << "those students (or rather their records?)\n";

    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
         << "then make sure the following call works:\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n";

} // main

// Overloading operator for LabWorker
ostream& operator<<(ostream& os, const LabWorker& worker) {
    if (!worker.section) {
        os << worker.name << " does not have a section" << endl;
        return os;
    } else {
        os << worker.name << " has " << *worker.section;
        return os;
    }
}

// Overloading operator for Section
ostream& operator<<(ostream& os, const Section& sec) {
    os << "Section: " << sec.secName << ", Time slot: [Day: " << sec.timeSlot.day
       << ", Start time: ";
    if (sec.timeSlot.start > 12) {
        os << sec.timeSlot.start - 12 << "pm";
    } else {
        os << sec.timeSlot.start << "am";
    }
    os << "], Students: ";
    if (sec.grades.empty()) {
        os << "None" << endl;
    } else {
        os << endl;
        for (const studentGrade* gradePointer : sec.grades) {
            os << "Name: " << gradePointer->getStudent() << ", Grades:";
            for (int newGrade : gradePointer->grades) {
                os << " " << newGrade;
            }
            os << endl;
        }
    }
    return os;
}