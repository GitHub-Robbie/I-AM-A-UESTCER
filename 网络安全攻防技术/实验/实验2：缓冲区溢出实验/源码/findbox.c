#include<windows.h>  
#include<stdio.h>  
typedef void (*MYPROC)(LPTSTR);  
int main() {  
    HINSTANCE LibHandle;  
    MYPROC ProcAdd;  
    LibHandle = LoadLibrary("user32.dll");  
    printf("user32 = 0x%x\n", LibHandle);  
    ProcAdd = (MYPROC)GetProcAddress(LibHandle, "MessageBoxA");  
    printf("MessageBoxA = 0x%x\n", ProcAdd);  
    getchar();  
    return 0;  
}  
