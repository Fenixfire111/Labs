.686
.model flat

.data
gr dd 180
res dd 1
.code
_Arcsin@4 proc

finit
fld dword ptr[esp+4]
fld dword ptr[esp+4]
fmul
fld1
fsubr
fsqrt
fld dword ptr[esp+4]
fxch
fpatan
fild gr
fmul
fldpi
fdiv
fistp gr
mov eax, gr

ret 4
_Arcsin@4 endp
end