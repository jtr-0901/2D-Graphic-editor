#include "canvas.h"

int main()
{
    initializeCanvas();
    drawRectangle(2,2,15,8);
    drawTriangle(30,2,20,15,40,15);
    drawCircle(60,10,7);
    displayCanvas();
    return 0;
}
