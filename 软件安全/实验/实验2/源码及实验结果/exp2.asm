.386
.model flat,stdcall

include msvcrt.inc
includelib msvcrt.lib
include user32.inc
includelib user32.lib
include kernel32.inc
includelib kernel32.lib

ASSUME FS:NOTHING

.data
s1 db "The address of Kernel32.dll base is %x",0
s2 db "The address of LoadLibraryA is %x",0
s3 db "The address of GetProcAdress is %x",0
s4 db "LoadLibraryA",0

.code
start:
	push ebp   ;寄存器保护
	mov ebp,esp  ;新栈
	push ebx     ;寄存器保护
	push esi     ;寄存器保护
	push edi     ;寄存器保护

	mov eax,dword ptr fs:[30h]  ;eax = PEB
	mov eax,dword ptr [eax+0ch] ;eax = LDR
	mov esi,dword ptr [eax+1ch] ;eax = ntdll.dll
	lodsd        ;eax = InInitOrder.flink
	mov ebp,[eax+8]     ;ebp = kernel32.dll
	mov edi, ebp        ;edi = kernel32.dll
	invoke crt_printf,offset s1,ebp

    mov eax,[ebp+3Ch]  ;eax = PE Header相对偏移地址
    mov edx,[ebp+eax+78h]
    add edx,ebp        ;edx = 导出表地址
    mov ecx,[edx+18h]  ;ecx = 输出函数的个数,确定循环次数
    mov ebx,[edx+20h]
    add ebx, ebp       ;ebx ＝ 函数名地址

searchGet:
    dec ecx     ;从后往前找
    mov esi,[ebx+ecx*4]
    add esi,ebp ;依次找每个函数名称
    ;GetProcAddress
    mov eax,50746547h
    cmp [esi], eax  ;'PteG'
    jne searchGet
    mov eax,41636f72h
    cmp [esi+4],eax ;'Acor'
    jne searchGet
    ;如果是GetProcA，表示找到了

    mov ebx,[edx+24h]
    add ebx,ebp ;ebx = 序号数组地址
    mov ecx,[ebx+ecx*2] ;ecx = 计算出的序号值
    mov ebx,[edx+1Ch]
    add ebx,ebp ;ebx ＝ 函数地址的起始位置
    mov ebx,[ebx+ecx*4]
    add ebx,ebp ;利用序号值，得到出GetProcAddress的地址
    invoke crt_printf,offset s2,ebx

	;为局部变量分配空间
	push ebp
	sub esp, 50h
	mov ebp, esp
	;查找LoadLibrary的地址
	mov [ebp + 40h], ebx   ;把GetProcAddress的地址保存到ebp + 40中
	;压入"LoadLibrary/0"的地址
	mov eax,offset s4
	push eax
	push edi    ;edi:kernel32的基址
	call DWORD PTR[ebp + 40h] ;返回值(即LoadLibrary的地址)保存在eax中
	invoke crt_printf,offset s3,eax

	pop         edi
	pop         esi
	pop         ebx
	mov         esp,ebp
	pop         ebp
	invoke ExitProcess,0h
end start