#include <iostream>
#include <string>

template <typename T>
T max_value(const T& a, const T& b) {
    return (a > b) ? a : b;
}

template <typename T>
class ExampleClass {
public:
    ExampleClass(const T& val) : value(val) {}

    T getValue() const {
        return value;
    }

    ExampleClass<T> max(const ExampleClass<T>& other) const {
        return ExampleClass<T>(max_value(value, other.getValue()));
    }

private:
    T value;
};

int main() {
    int int_a = 5, int_b = 8;
    std::cout << max_value(int_a, int_b) << std::endl;

    double double_a = 3.14, double_b = 2.71;
    std::cout << max_value(double_a, double_b) << std::endl;

    std::string str_a = "apple", str_b = "banana";
    std::cout << max_value(str_a, str_b) << std::endl;

    ExampleClass<int> int_instance_a(10), int_instance_b(15);
    ExampleClass<int> max_int_instance = int_instance_a.max(int_instance_b);
    std::cout << max_int_instance.getValue() << std::endl;

    ExampleClass<std::string> str_instance_a("cat"), str_instance_b("dog");
    ExampleClass<std::string> max_str_instance = str_instance_a.max(str_instance_b);
    std::cout << max_str_instance.getValue() << std::endl;

    return 0;
}
