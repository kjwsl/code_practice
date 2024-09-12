#include <format>
#include <iostream>
#include <string>

class RandomClass {
  public:
    RandomClass(int val = 4) : m_value(val) {}
    void show_info() const noexcept {
        std::cout << "I'm just a random class to demonstrate" << std::endl;
    }

    int operator-() { return -m_value; }
    int operator+() { return m_value; }
    RandomClass& operator++() {
        ++m_value;
        return *this;
    }
    RandomClass operator++(int) {
        RandomClass oldMe{*this};
        ++(*this);
        return oldMe;
    }

    friend std::ostream& operator<<(std::ostream&, const RandomClass&);

  private:
    int m_value;
};

std::ostream& operator<<(std::ostream& os, const RandomClass& cls) {
    return os << cls.m_value;
}

int main() {
    RandomClass rando{};
    std::cout << ++rando << std::endl;
    std::cout << rando++ << std::endl;
    std::cout << rando << std::endl;

    return 0;
}
