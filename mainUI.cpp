#pragma once
#include<graphics.h>//easyx图形库的头文件
#include <conio.h> 
#include "alphaDraw.cpp"
//#include"tools.h"

#define WINDOW_WIDTH  900
#define WINDOW_HEIGHT 600
void startMainMenu() {
    IMAGE img_menu_adventureCard1;
    IMAGE img_menu_adventureCard2;
    IMAGE img_menu_adventureCard3;
    IMAGE img_background;

    loadimage(&img_background, _T ("./resource/Screen/MainMenu.png"), WINDOW_WIDTH, WINDOW_HEIGHT,true); // Load main menu image
    loadimage(&img_menu_adventureCard1, _T("./resource/Screen/Adventure_0.png"), 300, 140,true);
    loadimage(&img_menu_adventureCard2, _T("./resource/Screen/Adventure_1.png"), 300, 140,true);
    //loadimage(&img_menu_adventureCard3, _T("./resource/Screen/conlinkinfo.png"));
    int flag = 1;

    while (true)
    {
        BeginBatchDraw();

        putimage(0, 0, &img_background); // Display main menu image
        // 使用alphaDraw函数绘制带透明通道的图像
        drawAlpha(flag ? &img_menu_adventureCard2 : &img_menu_adventureCard1, 474, 75);

        ExMessage msg;
        if (peekmessage(&msg))//如果有消息响应
        {
            if (msg.message == WM_LBUTTONDOWN && msg.x > 474 && msg.x < 474 + 300
                && msg.y>75 && msg.y < 75 + 140)//按下鼠标
                //判断按下的位置对不对
            {
                flag = 1;
                //鼠标松开
                //EndBatchDraw();//渲染一下
            }
            else if (msg.message == WM_LBUTTONUP && flag)//鼠标抬起
            {
                return;
            }
        }
        FlushBatchDraw();

        Sleep(10);
        EndBatchDraw();
    }
}
