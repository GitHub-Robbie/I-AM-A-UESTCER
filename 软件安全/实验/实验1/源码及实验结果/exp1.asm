 .386
;告诉汇编器应该生成386处理器（或更高）的伪代码。

.model flat,stdcall
;使用平坦内存模式并使用stdcall调用习惯,函数的参数从右往左压入

include msvcrt.inc
includelib msvcrt.lib
include user32.inc
includelib user32.lib
include kernel32.inc
includelib kernel32.lib
;为了使用来自WindowsAPI的函数，需要导入dll和包含文件

.data   ;数据段
s1 db 'this is a simple ',0
s2 db 'program you are annalyzing now!',0
s3 db "hello dou have get the right result?no! it't not over\n",0
s4 db "this is true end! but you should not relax yourself!!!Be careful ",0
s5 db "trap congratulation! now is the end\n",0
s6 db "their sum is %d\n",0
s7 db "can you have ",0
s8 db "the ability of ",0
s9 db "reverse analysis\n",0

.code   ;代码段
start:
	push ebp    
	mov ebp,esp 
	sub esp,0D8h    ;为当前栈预留本地变量空间
	push ebx        ;保护寄存器 
	push esi        ;保护寄存器
	push edi        ;保护寄存器
	lea edi,[ebp+0FFFFFF28h]
	mov ecx,36h
	mov eax,0CCCCCCCCh
	rep stos dword ptr es:[edi]     ;初始化


	invoke crt_printf,offset s1
	invoke crt_printf,offset s2
	mov dword ptr [ebp-8],39h
	mov dword ptr [ebp-14h],3Ch ;初始化本地变量
	mov eax,dword ptr [ebp-8]
	cmp eax,dword ptr [ebp-14h] ;比较
	jle r
	invoke crt_printf,offset s3
	jmp s
	r:
		mov eax,dword ptr [ebp-14h]
		push eax     ;将参数压栈
		mov ecx,dword ptr [ebp-8]
		push ecx     ;将参数压栈
		call compare
	    add esp,8       ;平衡栈
	s:
		mov dword ptr [ebp-14h],32h
		mov eax,dword ptr [ebp-8]
		cmp eax,dword ptr [ebp-14h]
		jle t
	    mov eax,dword ptr [ebp-14h]
	    push eax
	    mov ecx,dword ptr [ebp-8]
	    push ecx        ;将参数压栈
	    call compare
	    add esp,8       ;平衡栈
    t:
	    invoke crt_printf,offset s4
	    invoke crt_printf,offset s5
	    xor eax,eax
	    pop edi
        pop esi
        pop ebx
        add esp,0D8h
        pop ebp         ;恢复上一栈栈底
        ret

	compare:
        push ebp
        mov ebp,esp
        sub esp,0CCh
        push ebx
        push esi
        push edi
        lea edi,[ebp+0FFFFFF34h]
        mov ecx,33h
        mov eax,0CCCCCCCCh
        rep stos dword ptr es:[edi]
        mov eax,dword ptr [ebp+8]   ;参数a
        cmp eax,dword ptr [ebp+0Ch] ;参数b
        jl u
        mov eax,dword ptr [ebp+8]
        sub eax,dword ptr [ebp+0Ch]
        mov dword ptr [ebp-8],eax
        jmp v
	u:
        mov eax,dword ptr [ebp+0Ch]
        sub eax,dword ptr [ebp+8]
        mov dword ptr [ebp-8],eax
	v:
        mov esi,esp
        mov eax,dword ptr [ebp-8]
        push eax
        invoke crt_printf,offset s6,eax
        invoke crt_printf,offset s7
        invoke crt_printf,offset s8
        invoke crt_printf,offset s9
        mov eax,dword ptr [ebp-8]
        pop edi
        pop esi
        pop ebx
        add esp,0CCh
        mov esp,ebp
        pop ebp
        ret

end start