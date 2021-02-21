#include <windows.h>
#include <stdio.h>
#pragma comment(lib,"Urlmon")
 void main()
{
 HRESULT urldown;
 urldown = URLDownloadToFile(NULL,"https://images-1301794075.cos.ap-chengdu.myqcloud.com/%E5%AE%9E%E9%AA%8C%E4%B8%89%20%E7%A8%8B%E5%BA%8F%E5%AE%9E%E9%AA%8C.docx","c:\\test.docx",0,NULL);
 switch(urldown)
 {
 case E_OUTOFMEMORY:
  printf("下载失败！");
  break;
 case S_OK:
  printf("下载成功！");
  break;
 }
}
