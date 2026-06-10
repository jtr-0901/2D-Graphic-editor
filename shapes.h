#ifndef SHAPES_H
#define SHAPES_H

#define MAX_SHAPES 100

/* Shape Types */
#define LINE 1
#define RECTANGLE 2
#define TRIANGLE 3
#define CIRCLE 4

typedef struct
{
    int id,type,x1, y1,x2, y2,x3, y3,width,height,radius,active;
} Shape;

/* Global Shape Storage */
extern Shape shapes[MAX_SHAPES];
extern int shapeCount;

/* Add Shapes */
void addLine(int x1,int y1,int x2,int y2);
void addRectangle(int x,int y,int width,int height);
void addTriangle(int x1,int y1,int x2,int y2,int x3,int y3);
void addCircle(int xc,int yc,int radius);

/* Shape Operations */
void deleteShape(int id);
void modifyShape(int id);
void listShapes();
void redrawCanvas();

#endif