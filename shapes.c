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
