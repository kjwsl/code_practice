#include <iostream>
#include "Result.h"


Result<int> succeed() {
    return Result<int>(42);
}

Result<int> fail() {
    return Err("Something went wrong!");
}

int main() {
    auto result = succeed();
    if (result.isOk()) {
        std::cout << "Value: " << result << std::endl;
    } else {
        std::cout << "Error: " << Err("wrong") << std::endl;
    }

    auto result2 = fail();
    if (result2.isOk()) {
        int value = result2.unwrap();
        std::cout << "Value: " << value << std::endl;
    } else {
        std::cout << "Error: " << Err("Wrong") << std::endl;
    }

    return 0;
}
