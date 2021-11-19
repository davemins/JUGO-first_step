#include <stdio.h>
#include <windows.h>
#include <conio.h>


#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

int keyControl();
void init();
void titleDraw();
int menuDraw();
void gotoxy(int, int);

int main() 
{
    init();
    titleDraw();
    menuDraw();

    int keyCode =  keyControl ();
    printf("입력한 키 값은 : %d 입니다\n", keyCode);   
    return 0;

}

int keyControl()
{
    char temp = getch();

    if(temp == 'w' || temp == 'W')
    {
        return UP;
    }
    else if(temp == 'a' || temp == 'A')
    {
        return LEFT;
    }
    else if(temp == 's' || temp == 'S')
    {
        return DOWN;
    }
    else if(temp == 'd' || temp == 'D')
    {
        return RIGHT;
    }
    else if(temp == ' ')
    {
        return SUBMIT;
    }
}


void init()
{
    system("mode con cols=56 lines=20 | title 게임제목");
}

void titleDraw() 
{
    printf("\n\n\n\n");
    printf("     #####    ###     ###     #     ####   #####       \n");
    printf("     #       #       #       # #    #   #  #           \n");
    printf("     ####    ####    #      #####   ####   ####        \n");
    printf("     #           #   #      #   #   #      #           \n");
    printf("     #####   ####     ###   #   #   #      #####       \n");        
}

int menuDraw()
{
    int x = 24;
    int y = 12;
    gotoxy(x-2,y);
    printf("> 게임시작");
    gotoxy(x,y+1);
    printf("게임정보");
    gotoxy(x,y+2);
    printf("종료");
    while(1);
    {
        int n = keyControl();
        switch(n)
        {
            case UP :
            {
                if(y >12)
                {
                    gotoxy(x-2, y);
                    printf(" ");
                    gotoxy(x-2, --y);
                    printf(">");
                }
                break;
            }
            
            case DOWN :
            {
                if(y >14)
                {
                    gotoxy(x-2, y);
                    printf(" ");
                    gotoxy(x-2, ++y);
                    printf(">");
                }
                break;
            }
            
            case SUBMIT :
            {
                return y-12;
            }
            
        }
    }
}

void gotoxy(int x, int y)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);

}