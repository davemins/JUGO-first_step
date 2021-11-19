#include <stdio.h>
#include <windows.h>

void init();
void titleDraw();
void gotoxy(int, int);

int main() 
{
    init();
    titleDraw();
    return 0;
}


void init()
{
    system("mode con cols=56 lines=20 | title 게임제목");
}

void titleDraw() 
{
    printf("\n\n\n\n");
    printf("     #####     ###    ###     #     ####   #####       \n");
    printf("     #        #      #       # #    #   #  #           \n");
    printf("     ####     ####   #      #####   ####   ####        \n");
    printf("     #            #  #      #   #   #      #           \n");
    printf("     #####    ####    ###   #   #   #      #####       \n");        
}

