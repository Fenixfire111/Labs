
#include <iostream>

extern "C" int _stdcall Arcsin(float x);

int main()
{
    float x;
    std::cin >> x;
    std::cout << Arcsin(x);
    return 0;
}
