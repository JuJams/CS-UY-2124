/*
  rec08.cpp
  Starter Code for required functionality
  Yes, of course, you may add other methods.
  And no, this won't compile. You have to implement the methods and
  fix the cyclic association.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student;  

class Course {  
    friend ostream& operator<<(ostream& os, const Course& rhs);

public:
    Course(const string& courseName);
    const string& getName() const;
    bool addStudent(Student* add_student);
    bool dropStudent(Student* drop_student);
    void removeStudentsFromCourse();

private:
    string name;
    vector<Student*> students;
};  

class Student {
    friend ostream& operator<<(ostream& os, const Student& rhs);

public:

    Student(const string& theName);
    const string& getName() const;
    void setName(const string& newName);
    bool addCourse(Course* todocourse);
    void removedFromCourse(Course* todocourse);
    void dropFromCourses();

private:
    string name;
    vector<Course*> courses;
};  

class Registrar {
    friend ostream& operator<<(ostream& os, const Registrar& rhs);

public:
    Registrar();
    bool addCourse(const string& courseName);
    bool addStudent(const string& studentName);
    bool enrollStudentInCourse(const string& studentName,const string& courseName);
    bool cancelCourse(const string& courseName);
    bool changeStudentName(const string& oldName, const string& newName);
    bool dropStudentFromCourse(const string& studentName,const string& courseName);
    bool removeStudent(const string& studentName);
    void purge();

private:
    size_t findStudent(const string& studentName) const;
    size_t findCourse(const string& courseName) const;

    vector<Course*> courses;
    vector<Student*> students;
};  


int main() {

    Registrar registrar;

    cout << "No courses or students added yet\n";
    cout << registrar << endl;
     
    cout << "AddCourse CS101.001\n";
    registrar.addCourse("CS101.001");
    cout << registrar << endl;

    cout << "AddStudent FritzTheCat\n";
    registrar.addStudent("FritzTheCat");
    cout << registrar << endl;

    cout << "AddCourse CS102.001\n";
    registrar.addCourse("CS102.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
    cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
    cout << "Should fail, i.e. do nothing, "
         << "since Bullwinkle is not a student.\n";
    registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
    cout << registrar << endl;

    cout << "CancelCourse CS102.001\n";
    registrar.cancelCourse("CS102.001");
    cout << registrar << endl;
   
    
    // [OPTIONAL - do later if time]
    /*
    cout << "ChangeStudentName FritzTheCat MightyMouse\n";
    registrar.changeStudentName("FritzTheCat", "MightyMouse");
    cout << registrar << endl;  

    cout << "DropStudentFromCourse MightyMouse CS101.001\n";
    registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
    cout << registrar << endl;  

    cout << "RemoveStudent FritzTheCat\n";
    registrar.removeStudent("FritzTheCat");
    cout << registrar << endl;  
    

    cout << "Purge for start of next semester\n";ßßß
    registrar.purge();
    cout << registrar << endl;
    */
}
  

// Course codes
Course::Course(const string& courseName) : name(courseName) {}

const string& Course::getName() const { return name; }

bool Course::addStudent(Student* add_student) {
    if (add_student->addCourse(this)) {
        students.push_back(add_student);
        return true;
    }
    return false;
}

bool Course::dropStudent(Student* drop_student) {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i] == drop_student) {
            students[i]->removedFromCourse(this);
            students[i] = students.back();
            students.pop_back();
            return true;
        }
    }
    return false;
}

void Course::removeStudentsFromCourse() {
    for (Student* add_student : students) {
        add_student->removedFromCourse(this);
    }
    students.clear();
}


// Student codes
Student::Student(const string& theName) : name(theName) {}
const string& Student::getName() const { return name; }
void Student::setName(const string& newName) { name = newName; }


bool Student::addCourse(Course* add_course) {
    for (const Course* todocourse : courses) {
        if (add_course == todocourse) {
            return false;
        }
    }
    courses.push_back(add_course);
    return true;
}


void Student::removedFromCourse(Course* removed_course) {
    size_t i;
    for (i = 0; i < courses.size(); i++) {
        if (courses[i] == removed_course) {
            break;
        }
    }
    courses[i] = courses.back();
    courses.pop_back();
}


void Student::dropFromCourses() {
    for (Course* todocourse : courses) {
        todocourse->dropStudent(this);
    }
    courses.clear();
}

//Registar Class
Registrar::Registrar() {}

bool Registrar::addCourse(const string& courseName) {
    if (findCourse(courseName) == courses.size()) {
        courses.push_back(new Course(courseName));
        return true;
    }
    return false;
}
bool Registrar::addStudent(const string& studentName){
    if (findStudent(studentName) == studentName.size()) {
        students.push_back(new Student(studentName));
        return true;
    }
    return false;
}
bool Registrar::enrollStudentInCourse(const string& studentName,const string& courseName){
    size_t courseindex = findCourse(courseName);
    size_t studentindex = findStudent(studentName);
    if (courseindex < courses.size() && studentindex < students.size()){
        return courses[courseindex]->addStudent(students[studentindex]);
    return true;
    }
    return false;
    
}
bool Registrar::cancelCourse(const string& courseName){
    size_t courseindex = findCourse(courseName);
    if (courseindex < courses.size()) {
        courses[courseindex]->removeStudentsFromCourse();
        delete courses[courseindex];
        courses[courseindex] = courses[courses.size() - 1];
        courses.pop_back();
        return true;
    }
    return false;
}
void Registrar::purge() {
    for (Student* add_student : students) {
        delete add_student;
    }
    students.clear();

    for (Course* todocourse : courses) {
        delete todocourse;
    }
    courses.clear();
}


size_t Registrar::findStudent(const string& studentName) const{
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i]->getName() == studentName) {
            return i;
        }
    }
    return students.size();
}

size_t Registrar::findCourse(const string& courseName) const{
    for (size_t i = 0; i < courses.size(); i++) {
        if (courses[i]->getName() == courseName) {
            return i;
        }
    }
    return courses.size();
}

ostream& operator<<(ostream& os, const Course& rhs) {
    os << rhs.name << ":";
    if (rhs.students.empty()) {
        os << " No Students";
    } else {
        for (const Student* add_student : rhs.students) {
            os << " " << add_student->getName();
        }
    }
    os << endl;
    return os;
}

ostream& operator<<(ostream& os, const Student& rhs) {
    os << rhs.name << ":";
    if (rhs.courses.empty()) {
        os << " No Courses";
    } else {
        for (const Course* todocourse : rhs.courses) {
            os << " " << todocourse->getName();
        }
    }
    os << endl;
    return os;
}


ostream& operator<<(ostream& os, const Registrar& rhs) {
    os << "Registar's Report" << endl;
    os << "Courses:" << endl;
    for (const Course* todocourse : rhs.courses) {
        os << *todocourse;
    }
    os << "Students:" << endl;
    for (const Student* add_student : rhs.students) {
        os << *add_student;
    }
    return os;
}






































































