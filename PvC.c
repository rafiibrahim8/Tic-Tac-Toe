/* Alhamdulillah */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<windows.h>

int victory(int arr[]);
int occinv(int arr[],int x);
int tied(int arr[]);
int comfst(void);
int comInput(int arr[],int x,int lvl);
int getInt(void);

int pvc(void)
{
    int n[10]={0};
    char p1n[50],p2n[50],pn[50],choice;
    int t,i,com1st,lvl;
    system("cls");
    printf("Enter Player Name:");   gets(pn);
    printf("Choose Level:\n\t1. Easy\n\t2. Medium\n\t3. Hard\nPlease Enter: "); lvl=getInt();
    while(lvl<1 || lvl>3)
    {
        printf("\nEnter Between 1-3: ");
        lvl=getInt();
    }
    srand((unsigned)time(NULL));
    while(1)
    {
        com1st=comfst();
        if(com1st)
        {
            strcpy(p1n,"Computer");
            strcpy(p2n,pn);
        }

        else
        {
            strcpy(p2n,"Computer");
            strcpy(p1n,pn);
        }
        for(i=1; i<10; i++)
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
            if(com1st)
            {
                t=comInput(n,88,lvl);
                Sleep(1700);
                printf("%d",t);
                Sleep(1200);
                printf("\n");
            }
            else
            {
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
            if(!com1st)
            {
                t=comInput(n,79,lvl);
                Sleep(1700);
                printf("%d",t);
                Sleep(1200);
                printf("\n");
            }
            else
            {
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
