#include "Secretary.h"

int main() {
  Secretary s;
  bool exit = false;
  while (!exit) {
    int option;
    std::cout << "Choose action:\n";
    std::cout << "1. Add person to university records\n";
    std::cout << "2. Add course\n";
    std::cout << "3. Modify registered person\n";
    std::cout << "4. Modify existing course\n";
    std::cout << "5. Delete person from university records\n";
    std::cout << "6. Delete course\n";
    std::cout << "7. Assign professors to course\n";
    std::cout << "8. Get all students\n";
    std::cout << "9. Get all professors\n";
    std::cout << "10. Get professor's data\n";
    std::cout << "11. Get student's data\n";
    std::cout << "12. Exit\n";
    option = getNumber(1, 12, "");
    switch (option) {
    case 1:
      s.addPerson();
      break;
    case 2:
      s.addCourse();
      break;
    case 3:
      s.modifyPerson();
      break;
    case 4:
      s.modifyCourse();
      break;
    case 5:
      s.deletePerson();
      break;
    case 6:
      s.deleteCourse();
      break;
    case 7:
      s.assignProfessors();
      break;
    case 8:
      s.getStudents();
      break;
    case 9:
      s.getProfessors();
      break;
    case 10:
      s.getProfessorData();
      break;
    case 11:
      s.getStudentData();
      break;
    case 12:
      exit = true;
      break;
    }
  }
  return 0;
}