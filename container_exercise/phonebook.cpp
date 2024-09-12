#include "phonebook.h"
#include <string>

PhoneBook::PhoneBook(multimap<Person, string> &&phoneBook)
    : m_phoneBook(std::move(phoneBook)) {}

auto PhoneBook::insert(Person &&person, string &&phone) {
  m_phoneBook.insert({std::move(person), std::move(phone)});
}

void PhoneBook::erasePerson(const std::string &name) {
  for (auto it = m_phoneBook.begin(); it != m_phoneBook.end();) {
    if (it->first.hasSameName(name)) {
      it = m_phoneBook.erase(it);
    } else {
      ++it;
    }
  }
}

void PhoneBook::eraseNumber(const string &person, const string &phone) {
    for (auto it = m_phoneBook.begin(); it != m_phoneBook.end();) {
        if (it->first.hasSameName(person) && it->second == phone) {
        it = m_phoneBook.erase(it);
        } else {
        ++it;
        }
    }
}
