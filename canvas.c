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
