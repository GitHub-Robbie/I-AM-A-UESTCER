#include <WINDOWS.H>
#include <WINBASE.H>
#include<stdio.h>
	char* content="UnderAttack!";
	char* title="fuckyou!";    //aa bb��2���ַ������׵�ַ
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
	;push 0x76ae0000;�˴���ȡ����LoadLibraryA��ַ������Ѿ��ǿ���ֱ��ʹ�õĵĵ�ַ���ˣ�����Ҫ��ѹջkerne32.dll��ַ
	mov eax,0x76b02990
	call eax
	add esp,0x0c
	mov ebx,eax
	push 0x41786f
	push 0x42656761
	push 0x7373654d
	push esp
	push ebx;'user32.dll'��ַ
	mov eax,0x76af5f20;GetProcAddress
	call eax
	add esp,0x0c

	mov ebx,eax
	push 0x40 //���һ������
	mov eax,title //����
	push eax
	mov eax,content //����
	push eax
	push 0   //���
	call ebx
	pop ebp
	}
	//getchar();
    return 0;
}
