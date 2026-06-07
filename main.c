#include "canvas.h"

int main()
{
    initializeCanvas();
    drawRectangle(2, 2, 15, 8);
    drawTriangle(25, 2,15, 15,35, 15);
    displayCanvas();
    return 0;
}
