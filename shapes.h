#ifndef SHAPES_H
#define SHAPES_H

#define MAX_SHAPES 100
#define LINE 1
#define RECTANGLE 2
#define TRIANGLE 3
#define CIRCLE 4

typedef struct
{
    int id;
    int type;

    int x1, y1;
    int x2, y2;
    int x3, y3;

    int width;
    int height;

    int radius;

    int active;
} Shape;

extern Shape shapes[MAX_SHAPES];
extern int shapeCount;

#endif
