#include "canvas.h"

int main()
{
    addRectangle(2,2,15,8);

    addCircle(40,10,6);

    redrawCanvas();

    printf("Before Delete:\n");
    displayCanvas();

    deleteShape(1);

    printf("\nAfter Delete:\n");
    displayCanvas();

    return 0;
}
