#include <iostream>
extern "C" int _stdcall ScalarProduct(int*, int*, int);

int main()
{
    std::cout << "Enter the number of elements in the arrays: " << std::endl;
    int n;
    std::cin >> n;
    int* a = new int[n];
    int* b = new int[n];
    std::cout << "Enter the elements of array A: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::cout << "Enter the elements of array B: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::cout << "Scalar Product: " << ScalarProduct(a, b, n);
    delete[] a;
    delete[] b;
    system("pause");
    return 0;
}
