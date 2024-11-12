#include "Course.h"
#include "General.h"
#include "Professor.h"
#include "Student.h"
#include "Vector.h"
#include <iostream>
#include <string>

class Secretary {
  Vector<Professor> professors;
  Vector<Student> students;
  Vector<Course> courses;
  void addProfessor();
  void addStudent();
  void deleteProfessor();
  void deleteStudent();

public:
  Secretary();
  Secretary(const Secretary &oldSecretary);
  int getNumberOfPeople();
  int getNumberOfStudents();
  int getNumberOfProfessors();
  void deleteCourseHelper(Course *course, int index);
  void addCourse(Vector<Course> &courses);
  friend std::istream &operator>>(std::istream &cin, Secretary &secretary);
  friend std::ostream &operator<<(std::ostream &cout, Secretary &secretary);
  friend Secretary operator+(Secretary &secretary, Person person);
  friend Secretary operator+(Secretary &secretary, Professor professor);
  Secretary &operator+=(Professor &professor) {
    Professor *p = new Professor(professor);
    professors.add(p);
    return *this;
  }
  Secretary &operator+=(Student &student) {
    Student *s = new Student(student);
    students.add(s);
    return *this;
  }
  Secretary &operator=(const Secretary &other) {
    if (this == &other)
      return *this;
    professors = other.professors;
    students = other.students;
    return *this;
  }
  void addPerson();
  void addCourse();
  void modifyPerson();
  void modifyCourse();
  void deletePerson();
  void deleteCourse();
  void assignProfessors();
  void getStudents();
  void getProfessors();
  void getProfessorData();
  void getStudentData();
  void exit();
  ~Secretary();
};