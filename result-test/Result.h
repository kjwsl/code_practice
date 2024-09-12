#include <stdexcept>
#include <string>

template <typename T> class Result;
template <typename T> struct Ok;

template <typename T> struct Ok {
  operator T() { return value; }
  T value;
};

class Err {
public:
  Err(const std::string& msg) : msg(msg) {}
  std::string msg;
  friend std::ostream &operator<<(std::ostream &os, const Err &err) {
    return os << err.msg;
  }
};

template <typename T> class Result {
public:
  Result(T value) : value(value), hasValue(true) {}
  Result(Err err) : error(err.msg), hasValue(false) {}
  Result() : hasValue(false) {}

  friend std::ostream &operator<<(std::ostream &os, const Result &result) {
    return os << result.value;
  }

  // operator auto() { return hasValue ? Ok<T>{value} : Err{error}; }
  T unwrap() {
    if (!hasValue)
      throw std::runtime_error(error);
    return value;
  }
  T unwrapOr(T &other) noexcept { return hasValue ? value : other; }

  bool isOk() noexcept { return hasValue; }

private:
  std::string error;
  bool hasValue;
  T value;
};
