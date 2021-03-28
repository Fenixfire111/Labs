
#include <iostream>
extern "C" int _stdcall Calculate(int , int , int , int );

int main()
{
    int a, b, c, y;
    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;
    std::cout << "Enter c: ";
    std::cin >> c;
    std::cout << "Enter y: ";
    std::cin >> y;
    std::cout << "Result: " << Calculate(a, b, c, y);
}


