
#include <iostream>

int Calculate(int a, int b, int c, int y)
{
    int result;

    __asm
    {
        mov eax, b
        mov ebx, y
        imul eax, ebx
        mov ebx, c
        add eax, ebx
        neg eax
        cdq
        mov ebx, a
        imul ebx, 3
        idiv ebx

        cmp edx, 0
        je zero

        imul edx, 2
        cmp edx, ebx
        jg more

        cmp edx, ebx
        jl less
        
        mov ecx, eax
        mov ebx, 2
        cdq
        idiv ebx
        cmp edx, 0
        je zero2
        add eax, 1
        
        more:
        add eax, 1

        zero2 :
        zero :
        less :
        mov result, eax
    }

    return result;
}

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
    std::cout <<"Result: "<< Calculate(a, b, c, y);
    return 0;
}
