// canvas.c
#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"

char canvas[ROWS][COLS];

/* Initialize canvas with '_' */
void initializeCanvas()
{
    int i,j;
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            canvas[i][j]='_';
        }
    }
}

/* Display canvas */
void displayCanvas()
{
    int i,j;
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            printf("%c",canvas[i][j]);
        }
        printf("\n");
    }
}

/* DDA Line Drawing */
void drawLine(int x1,int y1,int x2,int y2)
{
    int dx=x2-x1;
    int dy=y2-y1;
    int steps;

    if(abs(dx)>abs(dy))
        steps=abs(dx);
    else
        steps=abs(dy);
    float xIncrement=dx/(float)steps;
    float yIncrement=dy/(float)steps;
    float x=x1;
    float y=y1;
    int i;

    for(i=0;i<=steps;i++)
    {
        if((int)x>=0 && (int)x<COLS && (int)y>=0 && (int)y<ROWS)
        {
            canvas[(int)y][(int)x]='*';
        }
        x+=xIncrement;
        y+=yIncrement;
    }
}

/* Rectangle */
void drawRectangle(int x,int y,int width,int height)
{
    drawLine(x,y,x+width,y);
    drawLine(x,y+height,x+width,y+height);
    drawLine(x,y,x,y+height);
    drawLine(x+width,y,x+width,y+height);
}

/* Triangle */
void drawTriangle(int x1,int y1,int x2,int y2,int x3,int y3)
{
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}

/* Helper for circle */
void plotCirclePoints(int xc,int yc,int x,int y)
{
    if(yc+y>=0 && yc+y<ROWS && xc+x>=0 && xc+x<COLS)
        canvas[yc+y][xc+x]='*';
    if(yc+y>=0 && yc+y<ROWS && xc-x>=0 && xc-x<COLS)
        canvas[yc+y][xc-x] ='*';
    if(yc-y>=0 && yc-y<ROWS && xc+x>=0 && xc+x<COLS)
        canvas[yc-y][xc+x]='*';
    if(yc-y>=0 && yc-y<ROWS && xc-x>=0 && xc-x<COLS)
        canvas[yc - y][xc - x] = '*';
    if(yc+x>=0 && yc+x<ROWS && xc+y>=0 && xc+y<COLS)
        canvas[yc+x][xc+y]='*';
    if(yc+x>=0 && yc+x<ROWS && xc-y>=0 && xc-y<COLS)
        canvas[yc+x][xc-y]='*';
    if(yc-x>=0 && yc-x<ROWS && xc+y>=0 && xc+y<COLS)
        canvas[yc-x][xc+y]='*';
    if(yc-x>=0 && yc-x<ROWS && xc-y>=0 && xc-y<COLS)
        canvas[yc-x][xc-y]='*';
}

/* Circle */
void drawCircle(int xc,int yc,int r)
{
    int x=0;
    int y=r;
    int p=1-r;
    while(x<=y)
    {
        plotCirclePoints(xc,yc,x,y);
        x++;
        if(p<0)
        {
            p=p+2*x+1;
        }
        else
        {
            y--;
            p=p+2*x-2*y+1;
        }
    }
}