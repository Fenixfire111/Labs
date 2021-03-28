.586
PUBLIC _ScalarProduct@12
.model flat
.data
result dword 0, 0, 0
.code
_ScalarProduct@12 proc
        
mov edi, dword ptr[esp + 4]
mov esi, dword ptr[esp + 8]
xor ecx, ecx
ForBegin1 :
mov ebx, dword ptr[esp + 12]
       cmp ecx, ebx
       je ForEnd
       mov ebx, dword ptr[edi]
       add edi, 4
       mov eax, dword ptr[esi]
       add esi, 4
       imul ebx
       add[result], eax
       adc[result + 4], edx
       adc[result + 8], 0
       inc ecx
       jmp ForBegin1
       ForEnd :
       mov eax, [result]
ret 12
_ScalarProduct@12 endp
end