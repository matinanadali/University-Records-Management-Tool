#include "Person.h"

int Person::total = 0;

int Person::getTotal() { return total; }

/////////////////// Constructors /////////////////////
Person::Person() : name(""), surname(""), role('\0') { total++; };

Person::Person(std::string name, std::string surname)
    : name(name), surname(surname), role('S') {
  total++;
}

Person::Person(std::string name, std::string surname, char role)
    : name(name), surname(surname), role(role) {}

/////////////////// Getters /////////////////////
std::string Person::getName() { return name; }

std::string Person::getSurname() { return surname; }

char Person::getRole() { return role; }

std::string Person::getRoleDescription() {
  return role == 'S' ? "Student " : "Professor ";
}

/////////////////// Setters /////////////////////
void Person::setName(std::string name) { this->name = name; }

void Person::setSurname(std::string surname) { this->surname = surname; }

void Person::setRole(char role) { this->role = role; }

/////////////////// Operator Overloaders /////////////////////
std::istream &operator>>(std::istream &cin, Person &person) {
  cin >> person.name >> person.surname;
  return cin;
}

std::ostream &operator<<(std::ostream &cout, Person &person) {
  cout << person.getRoleDescription() << " " << person.name << " "
       << person.surname;
  return cout;
}

bool operator==(Person &A, Person &B) {
  return B.name == A.name && B.surname == A.surname;
}

/////////////////// Default Destructor /////////////////////
Person::~Person() {}
