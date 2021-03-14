

#include <iostream>

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

    int result[3] = { 0,0,0 };
    __asm {
        mov edi, a
        mov esi, b
        xor ecx, ecx
        ForBegin1 :
        mov ebx, n
            cmp ecx, ebx
            je ForEnd
            mov ebx, dword ptr[edi]
            add edi, 4
            mov eax, dword ptr[esi]
            add esi, 4
            imul ebx
            add [result], eax
            adc [result + 4], edx
            adc [result + 8], 0
            inc ecx
            jmp ForBegin1
            ForEnd :
    }

    std::cout << result[0] << std::endl;
    return 0;
}


