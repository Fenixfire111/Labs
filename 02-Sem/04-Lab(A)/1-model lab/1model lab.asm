.586
PUBLIC _Calculate@16
.model flat
.code
_Calculate@16 proc
    mov eax, dword ptr[esp+8]
        mov ebx, dword ptr[esp+16]
        imul eax, ebx
        mov ebx, dword ptr[esp+12]
        add eax, ebx
        neg eax
        cdq
        mov ebx, dword ptr[esp+4]
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
ret 16
_Calculate@16 endp
end