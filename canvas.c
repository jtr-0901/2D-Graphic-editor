#include "canvas.h"

char canvas[rows][cols];
void initializeCanvas()
{
    int i,j;
    for(i=0;i<rows;i++)
    {
        for(j= 0;j<cols;j++)
        {
            canvas[i][j] = '_';
        }
    }
}

#include <stdio.h>

void displayCanvas()
{
    int i,j;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            printf("%c",canvas[i][j]);
        }
        printf("\n");
    }
}

#include <stdlib.h>

void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps;

    if(abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    float x = x1;
    float y = y1;

    for(int i = 0; i <= steps; i++)
    {
        if((int)y >= 0 && (int)y < ROWS &&
           (int)x >= 0 && (int)x < COLS)
        {
            canvas[(int)y][(int)x] = '*';
        }

        x += xIncrement;
        y += yIncrement;
    }
}

void drawRectangle(int x, int y, int width, int height)
{
    // Top edge
    drawLine(x, y, x + width, y);

    // Bottom edge
    drawLine(x, y + height, x + width, y + height);

    // Left edge
    drawLine(x, y, x, y + height);

    // Right edge
    drawLine(x + width, y, x + width, y + height);
}

void drawTriangle(int x1, int y1,int x2, int y2,int x3, int y3)
{
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}

void plotCirclePoints(int xc, int yc, int x, int y)
{
    if(yc + y >= 0 && yc + y < ROWS && xc + x >= 0 && xc + x < COLS)
        canvas[yc + y][xc + x] = '*';

    if(yc + y >= 0 && yc + y < ROWS && xc - x >= 0 && xc - x < COLS)
        canvas[yc + y][xc - x] = '*';

    if(yc - y >= 0 && yc - y < ROWS && xc + x >= 0 && xc + x < COLS)
        canvas[yc - y][xc + x] = '*';

    if(yc - y >= 0 && yc - y < ROWS && xc - x >= 0 && xc - x < COLS)
        canvas[yc - y][xc - x] = '*';

    if(yc + x >= 0 && yc + x < ROWS && xc + y >= 0 && xc + y < COLS)
        canvas[yc + x][xc + y] = '*';

    if(yc + x >= 0 && yc + x < ROWS && xc - y >= 0 && xc - y < COLS)
        canvas[yc + x][xc - y] = '*';

    if(yc - x >= 0 && yc - x < ROWS && xc + y >= 0 && xc + y < COLS)
        canvas[yc - x][xc + y] = '*';

    if(yc - x >= 0 && yc - x < ROWS && xc - y >= 0 && xc - y < COLS)
        canvas[yc - x][xc - y] = '*';
}

void drawCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;

    int p = 1 - r;

    while(x <= y)
    {
        plotCirclePoints(xc, yc, x, y);

        x++;

        if(p < 0)
        {
            p = p + 2 * x + 1;
        }
        else
        {
            y--;
            p = p + 2 * x - 2 * y + 1;
        }
    }
}
