#ifndef CANVAS_H
#define CANVAS_H
#define ROWS 20
#define COLS 80

extern char canvas[ROWS][COLS];

void initializeCanvas();
void displayCanvas();
void drawLine(int x1,int y1,int x2,int y2);
void drawRectangle(int x,int y,int width,int height);
void drawTriangle(int x1,int y1,int x2,int y2,int x3,int y3);
void drawCircle(int xc,int yc,int r);

#endif