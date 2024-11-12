#ifndef STUDENT_H
#define STUDENT_H
#include "Course.h"
#include "General.h"
#include "Person.h"
#include "Vector.h"

class Student : public Person {
  Vector<Course> passedCourses;
  Vector<Course> currentCourses;
  Vector<int> grades;
  int year;

public:
  Student();
  Student(std::string name, std::string surname);
  Student(std::string name, std::string surname, int year);
  Student(std::string name, std::string surname, Vector<Course> passedCourses,
          Vector<Course> currentCourses, int year);
  Vector<Course> &getPassedCourses();
  Vector<Course> &getCurrentCourses();
  Vector<int> &getGrades();
  void deleteCurrentCourse();
  void addPassedCourse();
  void deletePassedCourse();
  void addCurrentCourse(const Vector<Course> &courses);
  void modifyCurrentCourses(const Vector<Course> &courses);
  void modifyStudent(const Vector<Course> &courses);
  void modifyPassedCourses();
  int getYear();
  friend std::istream &operator>>(std::istream &cin, Student &student);
  friend std::ostream &operator<<(std::ostream &cout, Student &student);
  ~Student();
};

#endif