#include "student.h"
#include "course.h"
#include "registrar.h"
#include <iostream>
#include <string>
using namespace std;


namespace BrooklynPoly {

	ostream& operator<<(ostream& os, const Registrar& rhs) {
		os << "Registrar's Report" << endl;
		os << "Courses: ";
		for (size_t i = 0; i < rhs.courses.size(); ++i) {
			os << *rhs.courses[i];
		}
		
		os << "\nStudents: ";
		for (size_t i = 0; i < rhs.students.size(); ++i) {
			os << *rhs.students[i]<<endl;;
		}
		return os;
	}


	Registrar::Registrar() {};
	bool Registrar::addCourse(const string& name) {
		for (size_t i = 0; i < courses.size(); ++i) {
			if (courses[i]->getName() == name) {
				return false;
			}
		}

		Course* newCourse = new Course(name);
		courses.push_back(newCourse);
		return true;
	}

	bool Registrar::addStudent(const string& name) {
		for(size_t i = 0; i < students.size(); ++i) {
			if (students[i]->getName() == name) {
				return false;
			}
		}

		Student* newStudent = new Student(name);
		students.push_back(newStudent);
		return true;
	}

	bool Registrar::enrollStudentInCourse(const string& studentName,
		const string& courseName) {
		size_t studentInd = findStudent(studentName);
		size_t i = findCourse(courseName);
		if (studentInd != students.size() && i != courses.size()) {
			students[studentInd]->addCourse(courses[i]);
			courses[i]->addStudent(students[studentInd]);
			return true;
		}
		return false;
	}


	bool Registrar::cancelCourse(const string& courseName) {
		size_t i = findCourse(courseName);
		if (i != courses.size()) {
			courses[i]->removeStudentsFromCourse();
			swap(courses[i], courses[courses.size() - 1]);
			delete courses[courses.size() - 1];
			courses.pop_back();
			return true;
		}
		return false;
	}


	void Registrar::purge() {
		for (size_t i = 0; i < courses.size(); ++i) {
			delete courses[i];
		}

		for (size_t i = 0; i < students.size(); ++i) {
			delete students[i];
		}

		students.clear();
		courses.clear();
	};


	size_t Registrar::findStudent(const string& name) const {
		for (size_t i = 0; i < students.size(); ++i) {
			if (students[i]->getName() == name) {
				return i;
			}
		}
		return students.size();
	}


	size_t Registrar::findCourse(const string& name) const {
		for (size_t i = 0; i < courses.size(); ++i) {
			if (courses[i]->getName() == name) {
				return i;
			}
		}
		return courses.size();
	}

}