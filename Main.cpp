#include <graphics.h> 
#include <conio.h>    
#include <string> // Added for _T with string literals
#include "mainUI.cpp"
#include "utils/utils.h" // 包含我们新创建的工具头文件
#define WINDOW_WIDTH  900
#define WINDOW_HEIGHT 600

int main()
{
initgraph(WINDOW_WIDTH,WINDOW_HEIGHT); 
SetWindowText(GetHWnd(), _T("植物大战僵尸"));
   startMainMenu();
   
   int timer = 0;
   bool flag = true;
   /*while (1)
   {
       
   }*/
   system("pause");
   
   //closegraph();
   return 0;
}