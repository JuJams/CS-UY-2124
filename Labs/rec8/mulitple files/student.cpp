#include "student.h"
#include "course.h"
#include <iostream>
#include <string>
using namespace std;


namespace BrooklynPoly {
	//student
	ostream& operator<<(ostream& os, const Student& rhs) {
		os << endl<<rhs.name << ": ";
		if (rhs.courses.size() > 0) {
			for (size_t i = 0; i < rhs.courses.size(); ++i) {
				os <<rhs.courses[i]->getName()<<" ";
			}
			cout<<endl;
		}
		else {
			os << "No Courses";
		}
		return os;
	}

	Student::Student(const string& name) :name(name) {};

	const string& Student::getName() const { return name; };

	bool Student::addCourse(Course* course) {
		for (size_t i = 0; i < courses.size(); ++i) {
			if (courses[i] == course) {
				return false;
			}
		}
		courses.push_back(course);
		return true;
	}


	void Student::removedFromCourse(Course* course) {
		for (size_t i = 0; i < courses.size(); ++i) {
			if (courses[i] == course) {
				swap(courses[i], courses[courses.size() - 1]);
				courses.pop_back();
			}
		}
	}

}