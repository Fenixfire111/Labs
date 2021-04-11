.586
.model flat
.code

_DeleteBracers@8 proc

mov esi, dword ptr[esp+4]
mov ecx, dword ptr[esp+8]

xor edx, edx

mov al, '('

_rep:
mov al, '('
xor ebx, ebx
_firstBracket:
cmp ecx, 0
jng _end
movsb
dec edi
inc edx
dec ecx
scasb
jne _firstBracket;
dec edx

xor ebx, ebx
mov al, ')'
_secondBracket:
cmp ecx, 0
jng _end
movsb
dec edi
inc ebx
dec ecx
scasb
jne _secondBracket;

jmp _rep

_end:
add edx, ebx
mov eax, edx
ret 8
_DeleteBracers@8 endp

end