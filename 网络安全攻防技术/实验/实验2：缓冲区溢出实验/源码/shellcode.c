#include "windows.h"  
int main(){  
    LoadLibrary("user32.dll");  
    _asm{  
        sub esp,0x50    //抬高栈顶  
        xor ebx,ebx   
        push ebx   
        push 0x2020206f  
        push 0x6c6c6568 //push "hello" 字符串  
        mov eax,esp      
        push ebx   
        push 0x2020206f  
        push 0x6c6c6568  
        mov ecx,esp   
  
        push ebx    //messagebox 的第4个参数  
        push eax    //messagebox 的第3个参数  
        push ecx    //messagebox的第2个参数  
        push ebx    //messagebox的第1个参数  
  
        mov eax, 0x757cea80 //msg  
        call eax           //调用msg  
  
        push ebx    //向栈内压入0  
        mov eax,0x770d4100  //将exit函数地址赋给eax  
        call eax//调用exit函数  
    }  
    return 0;  
}  

