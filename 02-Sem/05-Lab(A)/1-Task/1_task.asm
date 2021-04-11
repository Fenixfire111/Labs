.586
.model flat
.code
_IsPalindrom@4 proc

mov edi, dword ptr[esp+4]
mov al, '.'
mov ecx, -1

_counter:
inc ecx
scasb
jne _counter;

dec ecx
mov edi, dword ptr[esp+4]
mov esi, dword ptr[esp+4]
add esi, ecx

_palimdrom:
cmp ecx, 0
jng _true;
add ecx, -2
mov eax, 0

std
lodsb
cld
scasb

je _palimdrom;

mov eax, 0
jmp _false;

_true:
mov eax, 1

_false:

ret 4
_IsPalindrom@4 endp
end