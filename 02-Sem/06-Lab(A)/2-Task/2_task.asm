.686
.model flat
.data

xx dd ?
tmp dd ?
eps dd ?
count dd 1
one dd 1
res dd ?

.code

_CalculateSh@8 proc

finit
fld dword ptr[esp+4]
fst tmp
fst res
fld dword ptr[esp+4]
fmul
fst xx
fld dword ptr[esp+8]
fst eps
fcompp
fstsw ax
sahf
ja _first

_cycle:
fld tmp
fld xx
fmul
fild count 
fild one
fadd 
fist count
fdiv
fild count 
fild one
fadd 
fist count
fdiv
fst tmp
fld res
fadd
fst res

fld tmp
fld eps
fcompp
fstsw ax
sahf
jb _cycle

_first:
fld res
ret 8
_CalculateSh@8 endp
end 