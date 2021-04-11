
#include <iostream>

extern "C" float _stdcall CalculateSh(float x, float eps);

int main()
{
    float x, eps;
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter eps: ";
    std::cin >> eps;
    std::cout << CalculateSh(x, eps);
    return 0;
}

