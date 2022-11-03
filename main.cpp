#include "number.h"

Number Fibonacci(unsigned);
Number factorial(unsigned);
void hailstone(Number);

int main() {
    std::cout << "Fibonacci(1000): " << Fibonacci(1000) << "\n\nfactorial(1000): " << factorial(1000) << std::endl;
    hailstone("90560792656972947582439785608972465789628974587264056284658721771");
    return 0;
}