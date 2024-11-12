#include "Secretary.h"

/////////////////// Constructors /////////////////////

Secretary::Secretary()
    : professors(Vector<Professor>()), students(Vector<Student>()),
      courses(Vector<Course>()) {}

Secretary::Secretary(const Secretary &oldSecretary) {
  professors = oldSecretary.professors;
  students = oldSecretary.students;
  courses = oldSecretary.courses;
}

/////////////////// Getters /////////////////////

int Secretary::getNumberOfPeople() {
  return students.getSize() + professors.getSize();
}

int Secretary::getNumberOfStudents() { return students.getSize(); }

int Secretary::getNumberOfProfessors() { return professors.getSize(); }

void Secretary::getStudents() {
  for (int i = 0; i < students.getSize(); i++) {
    std::cout << students.getAt(i)->getName() << " "
              << students.getAt(i)->getSurname() << "\n";
  }
}

void Secretary::getProfessors() {
  for (int i = 0; i < professors.getSize(); i++) {
    std::cout << professors.getAt(i)->getName() << " "
              << professors.getAt(i)->getSurname() << "\n";
  }
}

void Secretary::getProfessorData() {
  std::string name, surname;
  std::cout << "Enter professor's name: ";
  std::cin >> name;
  std::cout << "Enter professor's surname: ";
  std::cin >> surname;
  Professor *professor = new Professor(name, surname);
  int index = professors.indexOf(professor);
  if (index == -1) {
    std::cout << "Professor " << name << " " << surname
              << " is not registered.\n";
  } else {
    std::cout << "Professor's office: " << professors.getAt(index)->getOffice()
              << "\n";
    std::cout << "Courses professor " << name << " " << surname
              << " is eligible to teach:\n";
    std::cout << professors.getAt(index)->getCanTeachCourses();
    std::cout << "Courses professor " << name << " " << surname
              << " is currently teaching:\n";
    std::cout << professors.getAt(index)->getCurrentCourses();
  }
  delete professor;
}

void Secretary::getStudentData() {
  std::string name, surname;
  std::cout << "Enter students's name: ";
  std::cin >> name;
  std::cout << "Enter students's surname: ";
  std::cin >> surname;
  Student *student = new Student(name, surname);
  int index = students.indexOf(student);
  if (index == -1) {
    std::cout << "Student " << name << " " << surname
              << " is not registered.\n";
  } else {
    std::cout << "Student's year: " << students.getAt(index)->getYear() << "\n";
    std::cout << "Courses student " << name << " " << surname
              << " is currently enrolled in:\n";
    std::cout << students.getAt(index)->getCurrentCourses();
    std::cout << "Courses student " << name << " " << surname
              << " has passed:\n";
    for (int i = 0; i < students.getAt(index)->getGrades().getSize(); i++) {
      std::cout
          << students.getAt(index)->getPassedCourses().getAt(i)->getTitle()
          << " (grade " << *(int *)students.getAt(index)->getGrades().getAt(i)
          << ").\n";
    }
  }
  delete student;
}

/////////////////// Add X Methods /////////////////////

void Secretary::addProfessor() {
  // Ask for input
  std::string name, surname;
  std::cout << "Enter professor's name: ";
  std::cin >> name;
  std::cout << "Enter professor's surname: ";
  std::cin >> surname;
  char answer =
      getAnswer('y', 'n', "Would you like to add professor's office? (y/n) ");
  std::string office = "";
  if (answer == 'y') {
    std::cin >> office;
  }
  Professor p(name, surname, office);
  *this += p;
  std::cout << "Professor " << p.getName() << " " << p.getSurname()
            << " is successfully added.\n";
}

void Secretary::addStudent() {
  // Ask for input
  std::string name, surname;
  int year;
  std::cout << "Enter student's name: ";
  std::cin >> name;
  std::cout << "Enter student's surname: ";
  std::cin >> surname;
  year = getNumber(1, 4, "Enter student's year: ");
  Student s(name, surname, year);
  *this += s;
  std::cout << "Student " << s.getName() << " " << s.getSurname()
            << " is successfully added.\n";
}

void Secretary::addPerson() {
  char answer = getAnswer(
      'p', 's', "Would you like to add a professor (p) or a student(s)? ");
  if (answer == 'p') {
    addProfessor();
  } else {
    addStudent();
  }
}

void Secretary::addCourse() {
  // Ask for input
  std::string title;
  std::string random;
  int ects;
  int semester;
  bool required;
  std::cout << "Enter course title: ";
  std::getline(std::cin, random); // Reads the entire line including spaces
  std::getline(std::cin, title);
  ects = getNumber(0, 10, "Enter number of ECTS: ");
  semester = getNumber(1, 8, "Enter course semester: ");
  char answer = getAnswer('y', 'n', "Is course required? (y/n) ");
  if (answer == 'y') {
    required = true;
  } else {
    required = false;
  }
  courses.add(new Course(title, ects, semester, required));
  std::cout << "Course " << title << " is successfully added.\n";
}

/////////////////// Delete X Methods /////////////////////

void Secretary::deleteProfessor() {
  // Ask for input
  std::cout << "Enter professor information: Name Surname\n";
  std::string name, surname;
  std::cin >> name >> surname;
  Professor *professor = new Professor(name, surname);
  // Search for professor
  int index = professors.indexOf(professor);
  if (index == -1) {
    // Professor not found
    std::cout << "Professor " << name << " " << surname
              << " does not exist in university records.\n";
  } else {
    // Delete professor
    delete professors.getAt(index);
    professors.removeAt(index);
    std::cout << "Professor " << name << " " << surname
              << " is successfully deleted.\n";
  }
  delete professor;
}

void Secretary::deleteStudent() {
  // Ask for input
  std::string name, surname;
  std::cout << "Enter student's name: ";
  std::cin >> name;
  std::cout << "Enter student's surname: ";
  std::cin >> surname;
  Student *student = new Student(name, surname);
  // Search for student
  int index = students.indexOf(student);
  if (index == -1) {
    // Student not found
    std::cout << "Student " << name << " " << surname
              << " does not exist in university records.\n";
  } else {
    // Delete student
    delete students.getAt(index);
    students.removeAt(index);
    std::cout << "Student " << name << " " << surname
              << " is successfully deleted.\n";
  }
  delete student;
}

void Secretary::deletePerson() {
  char answer = getAnswer(
      'p', 's', "Would you like to delete a professor (p) or a student (s)? ");
  if (answer == 'p') {
    deleteProfessor();
  } else {
    deleteStudent();
  }
}

// Deletes all occurencies of course in object secretary
void Secretary::deleteCourseHelper(Course *course, int index) {
  for (int i = 0; i < students.getSize(); i++) {
    // Delete course from all students' current courses
    Student *student = students.getAt(i);
    int indexInStudentCourses = student->getCurrentCourses().indexOf(course);
    if (indexInStudentCourses != -1) {
      student->getCurrentCourses().removeAt(indexInStudentCourses);
    }
    indexInStudentCourses = student->getPassedCourses().indexOf(course);
    // Delete course from all students' passed courses
    if (indexInStudentCourses != -1) {
      student->getPassedCourses().removeAt(indexInStudentCourses);
      delete student->getGrades().getAt(indexInStudentCourses);
      student->getGrades().removeAt(indexInStudentCourses);
    }
  }
  for (int i = 0; i < professors.getSize(); i++) {
    // Delete course from all professors' current courses
    Professor *professor = professors.getAt(i);
    int indexInProfessorCourses =
        professor->getCurrentCourses().indexOf(course);
    if (indexInProfessorCourses != -1) {
      professor->getCurrentCourses().removeAt(indexInProfessorCourses);
    }
    // Delete course from all professors' can-teach courses
    indexInProfessorCourses = professor->getCanTeachCourses().indexOf(course);
    if (indexInProfessorCourses != -1) {
      professor->getCanTeachCourses().removeAt(indexInProfessorCourses);
    }
  }
  // Free memory
  delete courses.getAt(index);
  courses.removeAt(index);
}

void Secretary::deleteCourse() {
  // Ask for input
  std::cout << "Enter course title:\n";
  std::string random, title;
  std::getline(std::cin, random);
  std::getline(std::cin, title);
  Course *course = new Course(title);
  // Search for course
  int index = courses.indexOf(course);
  if (index == -1) {
    // Course not found
    std::cout << "Course " << title << " does not exist.\n";
  } else {
    // Delete course
    deleteCourseHelper(course, index);
    std::cout << "Course " << title << " is successfully deleted.\n";
  }
}

/////////////////// Modify X Methods /////////////////////

void modifyEcts(Course *course) {
  int ects;
  std::cout << "Enter new number of ects units: ";
  std::cin >> ects;
  course->setEcts(ects);
}

void modifySemester(Course *course) {
  int semester;
  std::cout << "Enter new semester: ";
  std::cin >> semester;
  course->setSemester(semester);
}

void modifyRequired(Course *course) {
  course->setRequired(!course->getRequired());
}

void Secretary::modifyPerson() {
  // Ask for input
  std::string name, surname;
  std::cout << "Enter person's name: ";
  std::cin >> name;
  std::cout << "Enter person's surname: ";
  std::cin >> surname;

  // Search whether person is a registered student or professor
  Student *student = new Student(name, surname);
  Professor *professor = new Professor(name, surname);
  int indexInProfessors = professors.indexOf(professor);
  int indexInStudents = students.indexOf(student);
  if (indexInProfessors == -1 && indexInStudents == -1) {
    // Person not found
    std::cout << "Person " << name << " " << surname << " is not registered.\n";
    return;
  } else if (indexInProfessors != -1 && indexInStudents != -1) {
    // There exists both a student and a professor with the same name
    char answer = getAnswer('p', 's',
                            "Would you like to modify the professor (p) " +
                                name + " " + surname + " or the student (s) " +
                                name + " " + surname + "? ");
    // Ask for role clarification
    if (answer == 'p') {
      professors.getAt(indexInProfessors)->modifyProfessor(courses);
    } else {
      students.getAt(indexInStudents)->modifyStudent(courses);
    }
  } else if (indexInProfessors != -1) {
    // Person found in professors
    professors.getAt(indexInProfessors)->modifyProfessor(courses);
  } else {
    // Person found in students
    students.getAt(indexInStudents)->modifyStudent(courses);
  }
  delete student;
  delete professor;
}

void Secretary::modifyCourse() {
  // Ask for input
  std::cout << "Enter course title: ";
  std::string random, title;
  std::getline(std::cin, random);
  std::getline(std::cin, title);
  Course *course = new Course(title);
  // Search for course
  int index = courses.indexOf(course);
  if (index == -1) {
    // Course not found
    std::cout << "Course " << title << " does not exist.\n";
  } else {
    // Modify fields of given course
    char answer =
        getAnswer('y', 'n',
                  "ECTS: " + std::to_string(courses.getAt(index)->getEcts()) +
                      ". Change (y/n)? ");
    if (answer == 'y') {
      modifyEcts(courses.getAt(index));
    }

    answer = getAnswer(
        'y', 'n',
        "Semester: " + std::to_string(courses.getAt(index)->getSemester()) +
            ". Change (y/n)? ");
    if (answer == 'y') {
      modifySemester(courses.getAt(index));
    }

    answer =
        getAnswer('y', 'n',
                  std::string("Is required: ") +
                      (courses.getAt(index)->getRequired() ? "yes" : "no") +
                      ". Change (y/n)? ");

    if (answer == 'y') {
      modifyRequired(courses.getAt(index));
    }

    std::cout << "Course " << title << " is successfully modified.\n";
  }

  delete course;
}

/////////////////// Assign Professors Method /////////////////////

void Secretary::assignProfessors() {
  // Ask for input
  std::cout << "Enter course title: ";
  std::string random, title;
  std::getline(std::cin, random);
  std::getline(std::cin, title);
  Course *course = new Course(title);
  // Search for course
  int courseIndex = courses.indexOf(course);
  if (courseIndex == -1) {
    // Course not found
    std::cout << "Course " << title << " does not exist.\n";
  } else {
    char answer = 'y';
    do {
      // Ask for professor data
      std::string name, surname;
      std::cout << "Enter delegated professor's name: ";
      std::cin >> name;
      std::cout << "Enter delegated professor's surname: ";
      std::cin >> surname;
      Professor *professor = new Professor(name, surname);
      // Search professor
      int professorIndex = professors.indexOf(professor);
      if (professorIndex == -1) {
        // Professor not found
        std::cout << "Professor " << name << " " << surname
                  << " is not registered.\n";
      } else {
        // Find whether professor can teach the given course
        int indexInCanTeachCourses = professors.getAt(professorIndex)
                                         ->getCanTeachCourses()
                                         .indexOf(course);
        if (indexInCanTeachCourses == -1) {
          // Professor cannot teach the given course
          std::cout << "Professor " << name << " " << surname
                    << " is not eligible to teach course " << title << "\n";
        } else {
          professors.getAt(professorIndex)
              ->getCurrentCourses()
              .add(courses.getAt(courseIndex));
          std::cout << "Professor " << name << " " << surname
                    << " assigned to course " << title << ". ";
        }
      }
      delete professor;
      answer = getAnswer('y', 'n', "Assign new professor to course (y/n)? ");
    } while (answer == 'y');
  }
  delete course;
}

/////////////////// Operation Overloaders /////////////////////

std::ostream &operator<<(std::ostream &cout, Secretary &secretary) {
  cout << "Number of enrolled students: " << secretary.students.getSize()
       << "\n";
  for (int i = 0; i < secretary.students.getSize(); i++) {
    cout << *(Student *)secretary.students.getAt(i);
  }
  cout << "Number of professors: " << secretary.professors.getSize() << "\n";
  for (int i = 0; i < secretary.professors.getSize(); i++) {
    cout << *(Professor *)secretary.professors.getAt(i);
  }
  return cout;
}

Secretary operator+(Secretary &secretary, Professor &professor) {
  Secretary newSecretary = secretary;
  newSecretary += professor;
  return newSecretary;
}

Secretary operator+(Secretary &secretary, Student &student) {
  Secretary newSecretary = secretary;
  newSecretary += student;
  return newSecretary;
}

/////////////////// Destructor /////////////////////

Secretary::~Secretary() {
  while (courses.getSize()) {
    deleteCourseHelper(courses.getAt(0), 0);
  }

  while (professors.getSize()) {
    delete professors.getAt(0);
    professors.removeAt(0);
  }

  while (students.getSize()) {
    delete students.getAt(0);
    students.removeAt(0);
  }
}