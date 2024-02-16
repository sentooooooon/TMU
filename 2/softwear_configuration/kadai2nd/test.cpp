#include <iostream>
#include <cmath>
#include <limits>

template <typename T>
struct FunctionF {
    T a;

    FunctionF(T a_val) : a(a_val) {}

    T operator()(T x) const {
        return std::cos(a * x * x);
    }
};

template <typename T, typename Func>
struct TrapezoidalIntegration {
    Func func;

    TrapezoidalIntegration(const Func& func_obj) : func(func_obj) {}

    T operator()(T a, T x, int num_intervals) const {
        T h = x / static_cast<T>(num_intervals);
        T result = (func(0) + func(x)) / 2;

        for (int i = 1; i < num_intervals; ++i) {
            T t = i * h;
            result += func(t);
        }

        result *= h;
        return result;
    }
};

int main() {
    FunctionF<double> f_obj(1.0);
    TrapezoidalIntegration<double, FunctionF<double>> integrate(f_obj);

    // Check if x is finite before performing the integral
    double x = INFINITY;
    if (std::isfinite(x)) {
        double result = integrate(1.0, x, 10000);

        // Check if the result is a valid number
        if (std::isnan(result) || std::isinf(result)) {
            std::cout << "Error: Unable to compute the integral." << std::endl;
        } else {
            std::cout << "Result of the integral: " << result << std::endl;
        }
    } else {
        std::cout << "Error: x is not a finite value." << std::endl;
    }

    return 0;
}
