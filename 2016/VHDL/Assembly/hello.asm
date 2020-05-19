.386                        ;使用80386指令集
.model flat, stdcall
option casemap:none
includelib msvcrt.lib
printf PROTO C :dword,:vararg ;double word 4 bytes
scanf PROTO C :dword,:vararg
;数据段
.data
InputMsg byte 'Input',0ah,0 ;define /0 at the end
OutputMsg byte 'Output',0ah,0
MyInputFormatStr byte '%d %c %d',0
MyOutputFormatStr byte '= %d',0ah,0
MyOutputFormatStr2 byte '= %x',0ah,0
Str1 sbyte 'a'
Inputa sdword ?
Inputb sdword ?
MyOperator sbyte ?
MyOutput sdword ?
TestData word 1234h
HigherByte sbyte ?
LowerByte sbyte ?
;代码段
.code
start:
invoke printf, offset InputMsg
invoke scanf, offset MyInputFormatStr, offset Inputa, offset MyOperator, offset Inputb
mov eax, Inputa
mov ebx, Inputb
add eax,ebx
mov MyOutput,eax
mov edx,0
mov ax, TestData
MyLoop:
    add ax,1
    inc edx
    cmp edx,10
    je labelOut
    jmp MyLoop
labelOut:
mov HigherByte,ah
mov LowerByte,al


invoke printf, offset OutputMsg
invoke printf, offset MyOutputFormatStr, MyOutput
invoke printf, offset MyOutputFormatStr2,HigherByte
invoke printf, offset MyOutputFormatStr2,LowerByte

ret
end start