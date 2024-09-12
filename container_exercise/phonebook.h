#ifndef INCLUDE_CONTAINER_EXERCISE_PHONEBOOK_H_
#define INCLUDE_CONTAINER_EXERCISE_PHONEBOOK_H_

#include "person.h"
#include <map>
#include <string>

using namespace std;
class PhoneBook {
public:
  explicit PhoneBook(multimap<Person, string> &&);

  /**
   * @brief Insert a new person into the phone book.
   *
   * @param person Person to insert.
   * @param phone Phone number to insert.
   */
  auto insert(Person &&, std::string &&);
  void erasePerson(const std::string &);
  void eraseNumber(const std::string &, const std::string &);
  auto getPhoneNumbers(Person &&) const;


  PhoneBook();
  PhoneBook(PhoneBook &&) = default;
  PhoneBook(const PhoneBook &) = delete;
  PhoneBook &operator=(PhoneBook &&) = default;
  PhoneBook &operator=(const PhoneBook &) = delete;
  ~PhoneBook();

private:
  multimap<Person, string> m_phoneBook;

  bool isSamePerson(const string & name, const string & phoneNum) const {
    for (const auto & [person, phone] : m_phoneBook) {
      if (person.hasSameName(name) && phone == phoneNum) {
        return true;
      }
    }
    return false;
  }
};

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

#endif // INCLUDE_CONTAINER_EXERCISE_PHONEBOOK_H_
