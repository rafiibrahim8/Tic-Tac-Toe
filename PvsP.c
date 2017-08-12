/* Alhamdulillah */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int victory(int arr[]);
int occinv(int arr[],int x);
int tied(int arr[]);
int getInt(void);

int pvp(void)
{
    int n[10]={0};
    char p1n[50],p2n[50],choice;
    int t,i;
    system("cls");
    printf("Enter 1st Player Name:");   gets(p1n);
    printf("Enter 2nd Player Name:");   gets(p2n);
    while(1)
    {

        for(i=1;i<10;i++)
            n[i]=48+i;
        while(1)
        {
            system("cls");
            printf("%c      %c      %c\n\n%c      %c      %c\n\n%c      %c      %c\n\n",n[1],n[2],n[3],n[4],n[5],n[6],n[7],n[8],n[9]);
            if(victory(n))
            {
                printf("%s Wins",p2n);
                break;
            }
            printf("\n\n%s\'s Turn[X]: ",p1n);
            t=getInt();
            while(occinv(n,t)>0)
            {
                if(occinv(n,t)<2)
                    printf("Place %d is already occupied by \'%c\'.",t,n[t]);
                else
                    printf("Enter Number between 1-9.");
                printf("\nPlease Enter again: ");
                t=getInt();
            }
            n[t]=88;
            system("cls");
            printf("%c      %c      %c\n\n%c      %c      %c\n\n%c      %c      %c\n\n",n[1],n[2],n[3],n[4],n[5],n[6],n[7],n[8],n[9]);
            if(victory(n))
            {
                printf("%s Wins",p1n);
                break;
            }

            if(tied(n))
            {
                printf("Game Tied.\n");
                break;
            }
            printf("\n\n%s\'s Turn[O]: ",p2n);
            t=getInt();
            while(occinv(n,t)>0)
            {
                if(occinv(n,t)<2)
                    printf("Place %d is already occupied by \'%c\'.",t,n[t]);
                else
                    printf("Enter Number between 1-9.");
                printf("\nPlease Enter again: ");
                t=getInt();
            }
            n[t]=79;
        }
        printf("\n\nDo you want to start over?\nY=Yes\nAny Key=No");
        choice=getch();
        if(!(choice=='y' || choice=='Y'))
            break;
    }
    return 0;
}


