#include "Course.h"
#include "General.h"
#include "Person.h"
#include "Vector.h"

class Professor : public Person {
  Vector<Course> canTeachCourses;
  Vector<Course> currentCourses;
  std::string office;
  void addCanTeachCourse(const Vector<Course> &courses);
  void deleteCanTeachCourse();
  void modifyOffice();
  void modifyCanTeachCourses(const Vector<Course> &courses);
  void modifyCurrentCourses();

public:
  Professor();
  Professor(std::string name, std::string surname);
  Professor(std::string name, std::string surname, std::string office);
  Professor(std::string name, std::string surname,
            Vector<Course> canTeachCourses, Vector<Course> currentCourses,
            std::string office);
  Vector<Course> &getCanTeachCourses();
  Vector<Course> &getCurrentCourses();
  std::string getOffice();
  void setOffice(std::string office);
  void modifyProfessor(const Vector<Course> &courses);
  friend std::ostream &operator<<(std::ostream &cout, Professor &professor);
  ~Professor();
};