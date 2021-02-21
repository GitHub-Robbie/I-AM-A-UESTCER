#include<Windows.h>
#include<iostream>
#include<fstream>
using namespace std;

void CodeInfo(int *start,int *CodeSize)
{
 DWORD s,e;
 _asm
 {
	push eax
	mov eax,begin1
	mov s,eax
	mov eax,end1
	mov e,eax
	jmp end1
begin1:
	push 0x00006c6c
	push 0x642e3233
	push 0x72657375
	push esp
	;push ebp_zhen
	;call LoadLibraryAAddr
	mov ebx,eax
	push 0
	push 0x74736574
	push 74696873
	push 0
	call ebx


	
;这里放你需要的汇编代码
end1:
  pop eax

 

 }
 *start=s;
 *CodeSize=e-s;
}