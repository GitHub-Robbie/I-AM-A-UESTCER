#include<windows.h>  
#include<stdio.h>  
typedef void (*MYPROC)(LPTSTR);  
int main() {  
    HINSTANCE LibHandle;  
    MYPROC ProcAdd;  
    LibHandle = LoadLibrary("kernel32");  
    printf("kernel32 = 0x%x\n", LibHandle);  
    ProcAdd = (MYPROC)GetProcAddress(LibHandle, "ExitProcess");  
    printf("ExitProcess = 0x%x\n", ProcAdd);  
    getchar();  
    return 0;  
}  

