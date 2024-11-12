#include "Student.h"

/////////////////// Constructors /////////////////////

Student::Student()
    : Person("", "", 'S'), passedCourses(Vector<Course>()),
      currentCourses(Vector<Course>()), grades(Vector<int>()), year(0) {}

Student::Student(std::string name, std::string surname, int year)
    : Person(name, surname, 'S'), passedCourses(Vector<Course>()),
      currentCourses(Vector<Course>()), grades(Vector<int>()), year(year) {}

Student::Student(std::string name, std::string surname)
    : Person(name, surname, 'S'), passedCourses(Vector<Course>()),
      currentCourses(Vector<Course>()), grades(Vector<int>()), year(1) {}

Student::Student(std::string name, std::string surname,
                 Vector<Course> passedCourses, Vector<Course> currentCourses,
                 int year)
    : Person(name, surname, 'S'), passedCourses(passedCourses),
      currentCourses(currentCourses), grades(Vector<int>()), year(year) {}

/////////////////////// Getters /////////////////////////

Vector<Course> &Student::getCurrentCourses() { return currentCourses; }

Vector<Course> &Student::getPassedCourses() { return passedCourses; }

Vector<int> &Student::getGrades() { return grades; }

int Student::getYear() { return year; }

/////////////////////// Modify Student Helper Methods  /////////////////////////

// Prompts the user to enter a course title and adds it to the list of current
// courses if the input is valid.
void Student::addCurrentCourse(const Vector<Course> &courses) {
  // Ask for input
  std::cout << "Enter course title: ";
  std::string title;
  std::getline(std::cin, title);
  Course *course = new Course(title);
  // Search for course
  int index = courses.indexOf(course);
  if (index == -1) {
    std::cout << "Course " << title << " does not exist.\n";
  } else {
    // Check if student has already passed the course
    bool alreadyPassed = (passedCourses.indexOf(course) != -1);
    if (alreadyPassed) {
      std::cout << "Student " << name << " " << surname
                << " has already passed course " << title << ".\n";
    } else {
      // Add course to the list of current courses
      currentCourses.add(courses.getAt(index));
      std::cout << "Student " << name << " " << surname
                << " registered in course " << title << ".\n";
    }
  }
  delete course;
}

// Prompts the user to enter a course title and removes it from the list of
// current courses if already there
void Student::deleteCurrentCourse() {
  // Ask for input
  std::cout << "Enter course title: ";
  std::string title;
  std::getline(std::cin, title);
  Course *course = new Course(title);
  // Search for course in current courses
  int index = currentCourses.indexOf(course);
  if (index == -1) {
    std::cout << "Student is not currently enrolled in course " << title
              << ".\n";
  } else {
    // Remove course and free memory
    delete currentCourses.getAt(index);
    currentCourses.removeAt(index);
    std::cout << "Student " << name << " " << surname
              << " unregistered from course " << title << ".\n";
  }
  delete course;
}

// Prompts the user to enter a course title. If the student is currently
// enrolled in this subject, it prompts the user to enter the student's grade
// and adds it to the passed subjects
void Student::addPassedCourse() {
  // Ask for input
  std::cout << "Enter course title: ";
  std::string title;
  std::getline(std::cin, title);
  Course *course = new Course(title);
  // Search for course in current courses
  int index = currentCourses.indexOf(course);
  if (index == -1) {
    std::cout << "Student " << name << " " << surname
              << " is not enrolled in course " << title << ".\n";
  } else {
    passedCourses.add(currentCourses.getAt(index));
    currentCourses.removeAt(index);
    // Ask for grade
    std::cout << "Enter student's grade in course " << title << ": ";
    int grade;
    std::cin >> grade;
    std::cout << "Student " << name << " " << surname
              << " registered as qualified for course " << title
              << " with grade " << grade << ".\n";
    // Add grade
    grades.add(new int(grade));
  }
  delete course;
}

// Prompts the user to enter a course title and removes the course from the list
// of the passed courses if already there
void Student::deletePassedCourse() {
  // Ask for input
  std::cout << "Enter course title: ";
  std::string title;
  std::getline(std::cin, title);
  Course *course = new Course(title);
  // Search for course in passed courses
  int index = passedCourses.indexOf(course);
  if (index == -1) {
    std::cout << "Student " << name << " " << surname
              << " has not passed course " << title << ".\n";
  } else {
    // Remove course and free memory
    delete passedCourses.getAt(index);
    passedCourses.removeAt(index);
    std::cout << "Student " << name << " " << surname
              << " has been removed from the passed list for the course "
              << title << ".\n";
  }
  delete course;
}

void Student::modifyCurrentCourses(const Vector<Course> &courses) {
  char answer =
      getAnswer('a', 'd',
                "Would you like to delete (d) or to add (a) a subject to those "
                "student" +
                    name + " " + surname + " is currently enrolled in? ");
  if (answer == 'a') {
    this->addCurrentCourse(courses);
  } else {
    this->deleteCurrentCourse();
  }
}

void Student::modifyPassedCourses() {
  char answer =
      getAnswer('a', 'd',
                "Would you like to delete (d) or to add (a) a subject to those "
                "student " +
                    name + surname + " has successfully completed?");
  if (answer == 'a') {
    this->addPassedCourse();
  } else {
    this->deletePassedCourse();
  }
}

/////////////////////// Operator overloaders  /////////////////////////

std::istream &operator>>(std::istream &cin, Student &student) {
  std::cin >> student.name >> student.surname >> student.year;
  return cin;
}
std::ostream &operator<<(std::ostream &cout, Student &student) {
  std::cout << "Student: " << student.name << " " << student.surname
            << " in year " << student.year << "\n";
  return cout;
}

/////////////////////// Public Methods /////////////////////////

// Prompts the user to enter the fields they want to change
void Student::modifyStudent(const Vector<Course> &courses) {
  std::cout << "Courses student is currently enrolled in:\n" << currentCourses;
  char answer = getAnswer('y', 'n', "Change (y/n)? ");
  if (answer == 'y') {
    this->modifyCurrentCourses(courses);
  }
  std::cout << "Courses student has passed:\n" << passedCourses;
  answer = getAnswer('y', 'n', "Change (y/n)? ");
  if (answer == 'y') {
    this->modifyPassedCourses();
  }
}

Student::~Student() {}