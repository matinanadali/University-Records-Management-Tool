#include <iostream>
#include <stdexcept>
#include <string>

#ifndef PERSON_H
#define PERSON_H

class Person {
protected:
  std::string name;
  std::string surname;
  char role; // 'S' - student, 'P' - professor
  static int total;

public:
  Person();
  Person(std::string name, std::string surname);
  Person(std::string name, std::string surname, char role);
  void setName(std::string name);
  void setSurname(std::string surname);
  void setRole(char role);
  static int getTotal();
  std::string getName();
  std::string getSurname();
  char getRole();
  std::string getRoleDescription();
  friend std::istream &operator>>(std::istream &cin, Person &person);
  friend std::ostream &operator<<(std::ostream &cout, Person &person);
  friend bool operator==(Person &A, Person &B);
  ~Person();
};

#endif