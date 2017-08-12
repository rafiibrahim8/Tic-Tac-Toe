/* Alhamdulillah */
#include<stdio.h>
#include<windows.h>
#include<conio.h>

int pvc(void);
int pvp(void);
int getInt(void);

int main()
{
    SetConsoleTitle("TIC TAC TOE");
    printf(":::::::::::::::::Tic Tac Toe:::::::::::::::::\n\n:::::::::::::::::Idea By JIM:::::::::::::::::\n\n\nPress any key to continue....\n");
    getch();
    system("cls");
    printf("Game Mode:\n\t1. 1 Player.\n\t2. 2 Players.\n\nEnter Choice (1 or 2): ");
    int choice=getInt();
    if(choice==1)
        pvc();
    else if(choice==2)
        pvp();
    else
        printf("\n\nInput is not valid.\nPress any key to exit.");
    getch();
    return 0;
}
