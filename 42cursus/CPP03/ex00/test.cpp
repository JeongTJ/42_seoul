#include <iostream>

class Example {
public:
    std::string value;

    // 생성자
    Example(const std::string &v) : value(v) {
        std::cout << "생성자 호출됨" << std::endl;
    }

    // 복사 생성자
    Example(const Example &other) : value(other.value) {
        std::cout << "복사 생성자 호출됨" << std::endl;
    }

    // 복사 대입 연산자
    Example& operator=(const Example &other) {
        if (this != &other) {
            value = other.value;
            std::cout << "복사 대입 연산자 호출됨" << std::endl;
        }
        return *this;
    }
};

int main() {
    Example a("a");
    Example b = a; // 복사 생성자 호출됨
    return 0;
}
