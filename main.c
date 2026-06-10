#include <stdio.h>
#include "canvas.h"
#include "shapes.h"

int main()
{
    int choice;
    initializeCanvas();
    while(1)
    {
        printf("\n");
        printf("===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Add Line\n");
        printf("2. Add Rectangle\n");
        printf("3. Add Triangle\n");
        printf("4. Add Circle\n");
        printf("5. Delete Shape\n");
        printf("6. Modify Shape\n");
        printf("7. List Shapes\n");
        printf("8. Display Canvas\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                int x1,y1,x2,y2;
                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                addLine(x1,y1,x2,y2);
                redrawCanvas();
                break;
            }
            case 2:
            {
                int x,y,width,height;
                printf("Enter x y width height: ");
                scanf("%d%d%d%d",&x,&y,&width,&height);
                addRectangle(x,y,width,height);
                redrawCanvas();
                break;
            }
            case 3:
            {
                int x1,y1,x2,y2,x3,y3;
                printf("Enter x1 y1 x2 y2 x3 y3: ");
                scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
                addTriangle(x1,y1,x2,y2,x3,y3);
                redrawCanvas();
                break;
            }
            case 4:
            {
                int xc,yc,r;
                printf("Enter centerX centerY radius: ");
                scanf("%d%d%d",&xc,&yc,&r);
                addCircle(xc,yc,r);
                redrawCanvas();
                break;
            }
            case 5:
            {
                int id;
                printf("Enter Shape ID to delete: ");
                scanf("%d",&id);
                deleteShape(id);
                break;
            }
            case 6:
            {
                int id;
                printf("Enter Shape ID to modify: ");
                scanf("%d",&id);
                modifyShape(id);
                break;
            }
            case 7:
            {
                listShapes();
                break;
            }
            case 8:
            {
                displayCanvas();
                break;
            }
            case 9:
            {
                printf("Exiting...\n");
                return 0;
            }
            default:
            {
                printf("Invalid choice.\n");
            }
        }
    }
    return 0;
}