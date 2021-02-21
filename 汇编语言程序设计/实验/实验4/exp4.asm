assume cs:code
data segment
    db "Beginner's All-purpose Symbolic Instruction Code.",0
data ends

code segment

begin:
    mov ax,data
    mov ds,ax
    mov si,0
    
    mov dh,8			; 行数
    mov dl,3			; 列数
    mov cx,0cah		    ; 字符属性
    call show_str

    call letterc

    mov dh,10			; 行数
    mov dl,3			; 列数
    mov cx,0cah		    ; 字符属性
    call show_str

    mov ax,4c00h
    int 21h

;名称：letterc
;功能：将以0结尾的字符串中的小写字母转变为大写字母
;参数：ds:si指向字符串首地址
letterc:
    push cx
    pushf
    mov cx,0

s1:
    mov cl,ds:[si]
    jcxz ok
    cmp cl,61h
    jb nextgo
    cmp cl,7ah
    ja nextgo
    and cl,0dfh
    mov ds:[si],cl

nextgo:
    inc si
    jmp short s1

ok:
    popf
    pop cx
    ret

show_str:   
	push dx
	push cx
	push si     		; 保护子程序寄存器中用到的寄存器
					
	mov di,0			; 显示缓存区中的偏移量
	mov bl,dh	
	dec bl				; 第bl行之前有bl-1个完整的行
	mov al,160  
	mul bl				; 每行160字节, 用行数乘偏移量得到目标行的偏移量
	mov bx,ax   		; 乘积存储在ax中, 送入bx中
	mov al,2			; 列的偏移量为2(第1字节为数值, 第2字节为属性)
	mul dl				; 与行偏移量同理
	add bl,al			; 将列偏移量与行偏移量相加, 得到指定位置的偏移量。
		
	mov ax,0b800h
	mov es,ax			; 指定显示缓存区的内存位置
		
	mov ax,cx			; 现将字符属性保存
s:     
	mov ch,0
	mov cl,ds:[si] 		; 首先将当前指向字符串的某个字符存入cx中
	jcxz okk			; 如果cx为0, 则转移到okk标号执行相应代码
	mov es:[bx+di],cl	; 将字符传入低地址
	mov es:[bx+di+1],ax	; 将颜色传入高地址
	add di,2			    ; 列偏移量为2
	inc si				    ; 字符串的偏移量为1
	loop s				    ; 不为0, 继续复制

okk: 
    pop dx		
	pop cx
	pop si				    ; 还原寄存器变量
	ret					    ; 结束子程序调用


code ends
end begin