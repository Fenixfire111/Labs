#include <iostream>

extern "C" int _stdcall DeleteBracers(char* s, int length);

int main()
{
    std::string line;
    std::cout << "Enter the line:" << std::endl;
    std::cin >> line;
    char* s = new char[line.size()];
    int n = line.size();
    for (int i = 0; i < n; ++i) {
        s[i] = line[i];
    }
    std::cout << "The size of the new line: " << DeleteBracers(s, n);
    delete[] s;
    return 0;
}
