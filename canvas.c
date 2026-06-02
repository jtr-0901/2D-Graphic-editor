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
