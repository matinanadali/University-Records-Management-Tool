#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

class Course {
  std::string title;
  int ects;
  int semester;
  bool required;

public:
  Course();
  Course(std::string title);
  Course(std::string title, int ects, int semester, bool required);
  void setEcts(int ects);
  void setRequired(bool required);
  void setSemester(int semester);
  int getSemester();
  int getEcts();
  bool getRequired();
  std::string getTitle();
  friend bool operator==(Course &A, Course &B);
  friend std::ostream &operator<<(std::ostream &cout, Course &course);
  ~Course();
};

#endif