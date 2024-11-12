#include "Professor.h"

/////////////////// Constructors /////////////////////

Professor::Professor() : Person("", "", 'P'), office("") {}

Professor::Professor(std::string name, std::string surname)
    : Person(name, surname, 'P'), office("") {}

Professor::Professor(std::string name, std::string surname, std::string office)
    : Person(name, surname, 'P'), office(office) {}

Professor::Professor(std::string name, std::string surname,
                     Vector<Course> canTeachCourses,
                     Vector<Course> currentCourses, std::string office)
    : Person(name, surname, 'P'), canTeachCourses(canTeachCourses),
      currentCourses(currentCourses), office(office) {}

/////////////////// Getters /////////////////////

Vector<Course> &Professor::getCanTeachCourses() { return canTeachCourses; }

Vector<Course> &Professor::getCurrentCourses() { return currentCourses; }

std::string Professor::getOffice() { return office; }

/////////////////// Setters /////////////////////

void Professor::setOffice(std::string office) { this->office = office; }

/////////////////// Modify Professor Helper Functions /////////////////////

// Prompts the user to enter a course title and adds it to the list of courses
// that professor can teach
void Professor::addCanTeachCourse(const Vector<Course> &courses) {
  // Ask for input
  std::cout << "Enter course title: ";
  std::string title;
  std::getline(std::cin, title);
  Course *course = new Course(title);
  // Search for course
  int index = courses.indexOf(course);
  if (index == -1) {
    // Course not found
    std::cout << "Course"
              << "does not exist.\n";
  } else {
    // Add course to the list
    canTeachCourses.add(courses.getAt(index));
    std::cout << course->getTitle() << " added to courses that professor "
              << name << " " << surname << " is eligible to teach.\n ";
  }
  delete course;
}

// Prompts the user to enter a course title and removes it from the list of
// courses that professor can teach
void Professor::deleteCanTeachCourse() {
  // Ask for input
  std::cout << "Enter course title: ";
  std::string title;
  std::getline(std::cin, title);
  Course *course = new Course(title);
  // Search for course
  int index = canTeachCourses.indexOf(course);
  if (index == -1) {
    // Course not found
    std::cout << "Professor is not eligible to teach course " << title << ".\n";
  } else {
    // Remove course from list
    canTeachCourses.removeAt(index);
    std::cout << course->getTitle() << " deleted from courses that professor "
              << name << " " << surname << " is eligible to teach.\n ";
  }
  delete course;
}

void Professor::modifyCanTeachCourses(const Vector<Course> &courses) {
  char answer =
      getAnswer('a', 'd',
                "Would you like to delete (d) or to add (a) a subject to those "
                "professor " +
                    name + surname + " can teach?");
  if (answer == 'a') {
    this->addCanTeachCourse(courses);
  } else {
    this->deleteCanTeachCourse();
  }
}
void Professor::modifyProfessor(const Vector<Course> &courses) {
  char answer = getAnswer('y', 'n',
                          "Office: " + (office == "" ? "-" : office) +
                              ". Change (y/n)? ");
  if (answer == 'y') {
    this->modifyOffice();
  }
  std::cout << "Courses professor is eligible to teach:\n" << canTeachCourses;
  answer = getAnswer('y', 'n', "Change (y/n)? ");
  if (answer == 'y') {
    this->modifyCanTeachCourses(courses);
  }
}

void Professor::modifyOffice() {
  std::cout << "Enter professor's new office: ";
  std::string office;
  std::cin >> office;
  this->setOffice(office);
}

/////////////////// Operator overloaders /////////////////////

std::ostream &operator<<(std::ostream &cout, Professor &professor) {
  std::cout << "Professor: " << professor.name << " " << professor.surname
            << " with office code " << professor.office << "\n";
  return cout;
}

/////////////////// Default Destructor /////////////////////

Professor::~Professor() {}