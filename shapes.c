#include "shapes.h"

Shape shapes[MAX_SHAPES];
int shapeCount = 0;

void addLine(int x1, int y1, int x2, int y2)
{
    Shape s;

    s.id = shapeCount + 1;
    s.type = LINE;

    s.x1 = x1;
    s.y1 = y1;
    s.x2 = x2;
    s.y2 = y2;

    s.active = 1;

    shapes[shapeCount] = s;
    shapeCount++;
}

void addRectangle(int x, int y, int width, int height)
{
    Shape s;

    s.id = shapeCount + 1;
    s.type = RECTANGLE;

    s.x1 = x;
    s.y1 = y;

    s.width = width;
    s.height = height;

    s.active = 1;

    shapes[shapeCount] = s;
    shapeCount++;
}

void addCircle(int xc, int yc, int radius)
{
    Shape s;

    s.id = shapeCount + 1;
    s.type = CIRCLE;

    s.x1 = xc;
    s.y1 = yc;
    s.radius = radius;

    s.active = 1;

    shapes[shapeCount] = s;
    shapeCount++;
}

void addTriangle(int x1,int y1,
                 int x2,int y2,
                 int x3,int y3)
{
    Shape s;

    s.id = shapeCount + 1;
    s.type = TRIANGLE;

    s.x1=x1;
    s.y1=y1;

    s.x2=x2;
    s.y2=y2;

    s.x3=x3;
    s.y3=y3;

    s.active = 1;

    shapes[shapeCount] = s;
    shapeCount++;
}

void redrawCanvas()
{
    initializeCanvas();

    for(int i = 0; i < shapeCount; i++)
    {
        if(shapes[i].active == 0)
            continue;

        switch(shapes[i].type)
        {
            case LINE:
                drawLine(
                    shapes[i].x1,
                    shapes[i].y1,
                    shapes[i].x2,
                    shapes[i].y2
                );
                break;

            case RECTANGLE:
                drawRectangle(
                    shapes[i].x1,
                    shapes[i].y1,
                    shapes[i].width,
                    shapes[i].height
                );
                break;

            case CIRCLE:
                drawCircle(
                    shapes[i].x1,
                    shapes[i].y1,
                    shapes[i].radius
                );
                break;

            case TRIANGLE:
                drawTriangle(
                    shapes[i].x1,
                    shapes[i].y1,
                    shapes[i].x2,
                    shapes[i].y2,
                    shapes[i].x3,
                    shapes[i].y3
                );
                break;
        }
    }
}

void deleteShape(int id)
{
    for(int i = 0; i < shapeCount; i++)
    {
        if(shapes[i].id == id)
        {
            shapes[i].active = 0;
            break;
        }
    }

    redrawCanvas();
}
