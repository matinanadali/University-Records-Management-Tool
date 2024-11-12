#include "Course.h"

/////////////////// Constructors /////////////////////

Course::Course() {}

Course::Course(std::string title)
    : title(title), ects(0), semester(0), required(false) {}

Course::Course(std::string title, int ects, int semester, bool required)
    : title(title), ects(ects), semester(semester), required(required) {}

/////////////////// Getters /////////////////////

std::string Course::getTitle() { return title; }

int Course::getSemester() { return semester; }

int Course::getEcts() { return ects; }

bool Course::getRequired() { return required; }

/////////////////// Setters /////////////////////
void Course::setSemester(int semester) { this->semester = semester; }

void Course::setEcts(int ects) { this->ects = ects; }

void Course::setRequired(bool required) { this->required = required; }

/////////////////// Operator Overloaders /////////////////////
std::ostream &operator<<(std::ostream &cout, Course &course) {
  std::cout << course.title << "\n";
  return std::cout;
}

bool operator==(Course &A, Course &B) { return A.title == B.title; }

/////////////////// Default Destructor /////////////////////
Course::~Course() {}