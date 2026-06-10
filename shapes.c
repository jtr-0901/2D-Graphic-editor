// shapes.c
#include <stdio.h>
#include "shapes.h"
#include "canvas.h"

Shape shapes[MAX_SHAPES];
int shapeCount = 0;

/* Add Line */
void addLine(int x1,int y1,int x2,int y2)
{
    if(shapeCount>=MAX_SHAPES)
        return;
    Shape s;
    s.id=shapeCount+1;
    s.type=LINE;
    s.x1=x1;
    s.y1=y1;
    s.x2=x2;
    s.y2=y2;
    s.active=1;
    shapes[shapeCount]=s;
    shapeCount++;
}

/* Add Rectangle */
void addRectangle(int x,int y,int width,int height)
{
    if(shapeCount>=MAX_SHAPES)
        return;
    Shape s;
    s.id=shapeCount+1;
    s.type=RECTANGLE;
    s.x1=x;
    s.y1=y;
    s.width=width;
    s.height=height;
    s.active=1;
    shapes[shapeCount]=s;
    shapeCount++;
}

/* Add Triangle */
void addTriangle(int x1,int y1,int x2,int y2,int x3,int y3)
{
    if(shapeCount>=MAX_SHAPES)
        return;
    Shape s;
    s.id=shapeCount+1;
    s.type=TRIANGLE;
    s.x1=x1;
    s.y1=y1;
    s.x2=x2;
    s.y2=y2;
    s.x3=x3;
    s.y3=y3;
    s.active=1;
    shapes[shapeCount]=s;
    shapeCount++;
}

/* Add Circle */
void addCircle(int xc,int yc,int radius)
{
    if(shapeCount>=MAX_SHAPES)
        return;
    Shape s;
    s.id=shapeCount+1;
    s.type=CIRCLE;
    s.x1=xc;
    s.y1=yc;
    s.radius=radius;
    s.active=1;
    shapes[shapeCount]=s;
    shapeCount++;
}

/* Redraw Entire Canvas */
void redrawCanvas()
{
    int i;
    initializeCanvas();
    for(i=0;i<shapeCount;i++)
    {
        if(shapes[i].active==0)
            continue;
        switch(shapes[i].type)
        {
            case LINE:
                drawLine(shapes[i].x1,shapes[i].y1,shapes[i].x2,shapes[i].y2);
                break;
            case RECTANGLE:
                drawRectangle(shapes[i].x1,shapes[i].y1,shapes[i].width,shapes[i].height);
                break;
            case TRIANGLE:
                drawTriangle(shapes[i].x1,shapes[i].y1,shapes[i].x2,shapes[i].y2,shapes[i].x3,shapes[i].y3);
                break;
            case CIRCLE:
                drawCircle(shapes[i].x1,shapes[i].y1,shapes[i].radius);
                break;
        }
    }
}

/* Delete Shape */
void deleteShape(int id)
{
    int i;
    for(i=0;i<shapeCount;i++)
    {
        if(shapes[i].id==id)
        {
            shapes[i].active=0;
            redrawCanvas();
            printf("Shape deleted.\n");
            return;
        }
    }
    printf("Shape not found.\n");
}

/* List Shapes */
void listShapes()
{
    int i;
    printf("\n----- SHAPES -----\n");
    for(i=0;i<shapeCount;i++)
    {
        if(shapes[i].active)
        {
            printf("ID = %d, Type = %d\n",shapes[i].id,shapes[i].type);
        }
    }
}

/* Modify Shape */
void modifyShape(int id)
{
    int i;
    for(i=0;i<shapeCount;i++)
    {
        if(shapes[i].id==id && shapes[i].active==1)
        {
            switch(shapes[i].type)
            {
                case LINE:
                    printf("Enter x1 y1 x2 y2: ");
                    scanf("%d%d%d%d",&shapes[i].x1,&shapes[i].y1,&shapes[i].x2,&shapes[i].y2);
                    break;
                case RECTANGLE:
                    printf("Enter x y width height: ");
                    scanf("%d%d%d%d",&shapes[i].x1,&shapes[i].y1,&shapes[i].width,&shapes[i].height);
                    break;
                case TRIANGLE:
                    printf("Enter x1 y1 x2 y2 x3 y3: ");
                    scanf("%d%d%d%d%d%d",&shapes[i].x1,&shapes[i].y1,&shapes[i].x2,&shapes[i].y2,&shapes[i].x3,&shapes[i].y3);
                    break;
                case CIRCLE:
                    printf("Enter centerX centerY radius: ");
                    scanf("%d%d%d",&shapes[i].x1,&shapes[i].y1,&shapes[i].radius);
                    break;
            }
            redrawCanvas();
            printf("Shape modified.\n");
            return;
        }
    }
    printf("Shape not found.\n");
}