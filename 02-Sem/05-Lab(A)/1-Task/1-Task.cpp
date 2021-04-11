#include <iostream>
#include <string>

extern "C" bool _stdcall IsPalindrom(char* s);

int main()
{
    std::string line;
    std::cout << "Enter the line:"<< std::endl;
    std::cin >> line;
    char* s = new char[line.size() + 1];
    int n = line.size();
    for (int i = 0; i < n; ++i) {
        s[i] = line[i];
    }
    s[n] = '.';

    if (IsPalindrom(s)) {
        std::cout << "It's a palindrom)\n";
    }
    else {
        std::cout << "It's not a palindrom(\n";
    }
    delete[] s;
    return 0;
}