assume cs:codesg,ds:datasg,es:tablesg

datasg segment
   db '1975','1976','1977','1978','1979','1980','1981','1982','1983'
   db '1984','1985','1986','1987','1988','1989','1990','1991','1992'
   db '1993','1994','1995'
   ;以上是表示21年的21个字符串

   dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514
   dd 345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000
   ;以上是表示21年公司总收入的21个dword型数据

   dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226
   dw 11542,14430,15257,17800
   ;以上是表示21年公司雇员人数的21个word型数据
datasg ends

tablesg segment
   db 21 dup ('year summ ne ?? ')
tablesg ends

codesg segment

start: mov ax,datasg
       mov ds,ax                     ;将data段传入ds
       mov ax,tablesg
       mov es,ax                     ;将table段传入es
       mov bx,0
       mov si,0
       mov di,0
       mov cx,15h                    ; 循环次数
       
    s: mov ax,ds:[bx]                ; 将年份低位传入ax寄存器
       mov es:[si],ax                ; 将ax中的年份低位传入es:[si]的0位
       mov ax,ds:[bx + 2]            ; 将年份高位传入ax寄存器
       mov es:[si + 2],ax            ; 将ax中的年份高位传入es:[si]的2位
                                     ; 以上四条指令处理表格此行的年份

       mov ax,ds:[bx + 54h]          ; 将收入低位传入ax寄存器
       mov es:[si + 5],ax            ; 将ax中的收入低位传入es:[si]的5位
       mov ax,ds:[bx + 56h]          ; 将收入高位传入ax寄存器
       mov es:[si + 7],ax            ; 将ax中的收入高位传入es:[si]的7位
                                     ; 以上四条指令处理表格此行的收入
       
       mov ax,ds:[di + 00a8h]        ; 将雇员数传入ax寄存器
       mov es:[si + 0ah],ax          ; 将雇员数传入es:[si]的10位 
                                     ; 以上两条指令处理表格此行的雇员数

       mov ax,[bx + 54h]             ; 取收入的低位传入ax
       mov dx,[bx + 56h]             ; 取收入的高位传入dx
       div word ptr ds:[di + 00a8h]  ; 收入除以雇员数
       mov es:[si + 0dh],ax          ; 将ax中收入的整数传入es:[si]的13位
                                     ; 以上四条指令处理表格此行的人均收入

       add si,16                     ; 表格换行
       add di,2                      ; 雇员数和人均收入均为2字节
       add bx,4                      ; 年份和收入均为4字节

       loop s

       mov ax,4c00h
       int 21h

codesg ends
end start