#ifndef CANVAS_H
#define CANVAS_H

#define rows 20
#define cols 40

extern char canvas[rows][cols];

void initializeCanvas();
void displayCanvas();
void drawLine(int x1, int y1, int x2, int y2);

#endif
