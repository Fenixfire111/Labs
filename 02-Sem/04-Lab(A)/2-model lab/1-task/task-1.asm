.586
PUBLIC _Checking@12
.model flat
.code
_Checking@12 proc
        mov eax, [esp+4]
        mov ebx, [esp+8]
        mov ecx, 0
        add eax, ebx
        jc cf
        mov ebx, [esp+12]
        cmp ebx, eax
        jl _netr
        add ecx, -1
        _netr :
        cf :
        inc ecx
        mov eax, ecx
        ret 12
_Checking@12 endp
end