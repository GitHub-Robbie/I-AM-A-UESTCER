#include <WINDOWS.H>
#include <WINBASE.H>
#include<stdio.h>
	char* content="UnderAttack!";
	char* title="fuckyou!";    //aa bb是2个字符串的首地址
int main()
{
	__asm{
		push ebp
		mov ebp,esp
	xor ecx,ecx
	push 0x6c6c
	push 0x642e3233
	push 0x72657375
	push esp;'user32.dll'
	;push 0x76ae0000;此处获取到的LoadLibraryA地址本身就已经是可以直接使用的的地址的了，不需要再压栈kerne32.dll地址
	mov eax,0x76b02990
	call eax
	add esp,0x0c
	mov ebx,eax
	push 0x41786f
	push 0x42656761
	push 0x7373654d
	push esp
	push ebx;'user32.dll'地址
	mov eax,0x76af5f20;GetProcAddress
	call eax
	add esp,0x0c

	mov ebx,eax
	push 0x40 //最后一个参数
	mov eax,title //标题
	push eax
	mov eax,content //内容
	push eax
	push 0   //句柄
	call ebx
	pop ebp
	}
	//getchar();
    return 0;
}
