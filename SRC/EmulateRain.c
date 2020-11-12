// Rain.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <time.h> 
#include <dos.h> 
#include <graphics.h> 
#define LEN sizeof(struct rainDrop)         // 一个雨滴结构体的大小

int rainDropNumber = 60;                    // 雨滴的数量
int downSpeed = 20;                         // 雨滴的下落速率
struct rainDrop* head;                      // 雨滴是一个链表， 这里是链表头

struct rainCircle                           // 雨滴落下形成的水圈，是一个椭圆
{
    int x;
    int y;
    int r;
    int curR;
    int rainCircleStep;
};

struct rainDrop                         // 雨滴 结构体， 链表结点， 
{
    int startX;
    int startY;
    int endY;
    int curX;
    int curY;
    int rainColor;
    int rainLineStep;
    int rainLineLength;
    int status;
    struct rainCircle water;            // 雨圈
    struct rainDrop* next;              // 指向下一个雨滴节点
};

void initgraphics(void)                 // 初始化图形环境
{
    int gmode, gdriver;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");
}

struct rainDrop* creatDrop(void)        // 创建雨滴节点
{
    struct rainDrop* p;                 // 雨滴指针头
    p = (struct rainDrop*)malloc(LEN);  // 分配空间，并赋给雨滴指针头
    p->startX = rand() % 640;           // 
    p->startY = rand() % 430;
    p->endY = 430 + rand() % 50;
    p->curX = p->startX;
    p->curY = p->startY;
    p->rainLineStep = 8;
    p->rainColor = rand() % 15 + 1;     // 雨的颜色，15种颜色
    p->rainLineLength = rand() % 10 + 10;
    p->status = 0;
    p->water.x = p->startX;
    p->water.y = p->endY;
    p->water.r = rand() % 40;
    p->water.curR = rand() % 2;
    p->water.rainCircleStep = rand() % 2 + 1;
    p->next = NULL;
    return(p);                          // 返回指针头
}

void recreatDrop(struct rainDrop* p)
{
    p->startX = rand() % 640;
    p->startY = rand() % 430;
    p->endY = 430 + rand() % 50;
    p->curX = p->startX;
    p->curY = p->startY;
    p->rainLineStep = 8;
    p->rainColor = rand() % 15 + 1;
    p->rainLineLength = rand() % 10 + 10;
    p->status = 0;
    p->water.x = p->startX;
    p->water.y = p->endY;
    p->water.r = rand() % 40;
    p->water.curR = rand() % 2;
    p->water.rainCircleStep = rand() % 2 + 1;
}

void creatRain(void)
{
    struct rainDrop* p1, * p2;
    int i;
    p1 = p2 = creatDrop();
    head = p1;
    for (i = 0; i < rainDropNumber; i++)
    {
        p2 = creatDrop();
        p1->next = p2;
        p1 = p2;
    }
}

void updateRainLineData(struct rainDrop* p)
{
    if (p->rainLineStep % 5 == 0)
        p->rainLineStep++;
    p->curY += p->rainLineStep;
    p->startY = p->curY - p->rainLineLength;
}

void drawRainLine(struct rainDrop* p)
{
    setcolor(p->rainColor);
    line(p->startX, p->startY, p->curX, p->curY);
}

void clearRainLine(struct rainDrop* p)
{
    setcolor(BLACK);
    line(p->startX, p->startY, p->curX, p->curY);
}

void rainDropDown(struct rainDrop* p)
{
    if (p->curY >= p->endY)
    {
        clearRainLine(p);
        p->status = 1;
    }
    else
    {
        clearRainLine(p);
        updateRainLineData(p);
        drawRainLine(p);
    }
}

void updateRainCircleData(struct rainDrop* p)
{
    p->water.curR += p->water.rainCircleStep;
}

void drawRainCircle(struct rainDrop* p)
{
    setcolor(p->rainColor);
    circle(p->water.x, p->water.y, p->water.curR);
}

void clearRainCircle(struct rainDrop* p)
{
    setcolor(BLACK);
    circle(p->water.x, p->water.y, p->water.curR);
}

void fallToWater(struct rainDrop* p)
{
    if (p->water.curR >= p->water.r)
    {
        clearRainCircle(p);
        recreatDrop(p);
    }
    else
    {
        clearRainCircle(p);
        updateRainCircleData(p);
        drawRainCircle(p);
    }
}

void rain(void)
{
    struct rainDrop* p;
    p = head;
    while (!kbhit())
    {
        if (p == NULL)
            p = head;
        else
        {
            if (p->status == 0)
                rainDropDown(p);
            else
                fallToWater(p);
        }
        delay(downSpeed);
        p = p->next;
    }
}

void clearAll(void)
{
    struct rainDrop* p, * pf;
    p = head;
    while (p != NULL)
    {
        pf = p;
        p = p->next;
        free(pf);
    }
    closegraph();
}

main()
{
    printf("Input rainDrop Number:");
    scanf("%d", &rainDropNumber);
    printf("Input down speed:");
    scanf("%d", &downSpeed);
    randomize();
    initgraphics();
    creatRain();
    rain();
    clearAll();
}
