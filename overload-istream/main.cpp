#include <iostream>
#include <string>

class Rando {
  public:
    Rando(std::string_view text = "") : m_text(text) {}

    std::string get_str() const noexcept {
        std::string str = "Rando:\n"
                          "\t" +
                          m_text + "\n";
        return str;
    }

    friend std::ostream &operator<<(std::ostream &out, const Rando &rando) {
        out << rando.get_str();
        return out;
    }
    friend std::istream &operator>>(std::istream &in, Rando &rando) {
        std::getline(in, rando.m_text);
        return in;
    }

  private:
    std::string m_text;
};

int main() {
    Rando randoA{};
    Rando randoB{};
    std::cin >> randoA >> randoB;
    std::cout << randoA << randoB << std::endl;

    return 0;
}
