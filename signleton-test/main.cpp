#include <iostream>

template <class T> class Singleton {
public:
  Singleton(const Singleton &) = delete;
  virtual ~Singleton() { delete instance; }

  static T *getInstance() {
    if (!instance) {
      instance = new T();
    }
    return instance;
  }

private:
  static T *instance;
};

template <class T> T *Singleton<T>::instance = nullptr;

class MyService {
public:
  void doSomething() { std::cout << "data: " << data << std::endl; }

  int data{};
};

int main() {
  auto service1 = Singleton<MyService>::getInstance();
  service1->data = 42;
  service1->doSomething();

  auto service2 = Singleton<MyService>::getInstance();
  service2->data = 28;
  service2->doSomething();

  service1->doSomething();

  return 0;
}
