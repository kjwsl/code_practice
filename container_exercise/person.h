#ifndef INCLUDE_CONTAINER_EXERCISE_PERSON_H_
#define INCLUDE_CONTAINER_EXERCISE_PERSON_H_

#include <string>
using namespace std;

class Person {
public:
  Person();
  Person(Person &&) = default;
  Person(const Person &) = default;
  Person &operator=(Person &&) = default;
  Person &operator=(const Person &) = default;
  ~Person();

  operator std::string() const { return getFullName(); } 
  operator const std::string() const { return getFullName(); } 


  string getFullName() const { return name + " " + surname; }

  bool hasSameName(const Person &other) const {
    return hasSameName(other.getFullName());
  }
  bool hasSameName(const string & other) const {
      return getFullName() == other;
  }

  friend bool hasSameName(const Person &lhs, const Person &rhs) {
    return lhs.name == rhs.name && lhs.surname == rhs.surname;
  }

private:
  std::string name{"John"};
  std::string surname{"Doe"};
  std::string address{"Unknown"};
  std::string email{"johndoe@fakemail.com"};
};

#endif // INCLUDE_CONTAINER_EXERCISE_PERSON_H_
