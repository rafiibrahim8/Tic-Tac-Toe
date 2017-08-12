#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int getCorner(int ar[]);
int getEdge(int ar[]);

int victory(int arr[])
{
    int ret=0;
    if(arr[1]==arr[2] && arr[2]==arr[3])
        ret=1;
    else if(arr[4]==arr[5] && arr[5]==arr[6])
        ret=1;
    else if(arr[7]==arr[8] && arr[8]==arr[9])
        ret=1;
    else if(arr[1]==arr[4] && arr[4]==arr[7])
        ret=1;
    else if(arr[2]==arr[5] && arr[5]==arr[8])
        ret=1;
    else if(arr[3]==arr[6] && arr[6]==arr[9])
        ret=1;
    else if(arr[1]==arr[5] && arr[5]==arr[9])
        ret=1;
    else if(arr[3]==arr[5] && arr[5]==arr[7])
        ret=1;
    return ret;
}
int occinv(int arr[],int x)
{
    int r=0;
    if(x<1 || x>9)
        r=2;
    else if(arr[x]==88 || arr[x]==79)
        r=1;
    return r;
}
int tied(int arr[])
{
    return (arr[1]>57) && (arr[2]>57) && (arr[3]>57) && (arr[4]>57) && (arr[5]>57) && (arr[6]>57) && (arr[7]>57) && (arr[8]>57) && (arr[9]>57);
}

int comfst(void)
{
    return rand()%2;
}

int comInput(int arr[],int x,int lvl)
{
    int i,a,b,c,d,ret=0;
    int opp=(x==79)?88:79;

    if(lvl==3)
    {
        a=25;
        b=25;
        c=35;
        d=40;
    }
    else if(lvl==2)
    {
        a=10;
        b=10;
        c=15;
        d=20;
    }
    else
    {
        a=0;
        b=0;
        c=0;
        d=0;
    }

    while(ret==0)
    {
        //Computer is checking for own Victory
        if((rand()%100)<(75+a))
        {
            for(i=1; i<10; i++)
            {
                if(arr[i]<79)
                {
                    arr[i]=x;
                    if(victory(arr))
                    {
                        ret=i;
                        break;
                    }
                    arr[i]=i+48;
                }
            }
        }
        if(ret!=0)
            break;
        if((rand()%100)<(75+b))
        {
            //Computer is checking for opponent Victory
            for(i=1; i<10; i++)
            {
                if(arr[i]<79)
                {
                    arr[i]=opp;
                    if(victory(arr))
                    {
                        ret=i;
                        arr[i]=48+i;
                        break;
                    }
                    arr[i]=i+48;
                }
            }
        }
        if(ret!=0)
            break;

        if(((rand()%100)<(65+c)) && arr[5]<79)
            ret=5;
        else if((rand()%100)<(60+d))
            ret=getCorner(arr);
        else
            ret=getEdge(arr);
    }

    return ret;
}

int getCorner(int ar[])
{
    int n,cont=0,r=0;
    while(cont<20)
    {
        n=rand()%10;
        if(n==1 || n==3 || n==7 || n==9)
        {
            if(ar[n]<79)
            {
                r=n;
                break;
            }
        }
        cont++;
    }
    return r;
}

int getEdge(int ar[])
{
    int n,cont=0,r=0;
    while(cont<20)
    {
        n=rand()%10;
        if(n==2 || n==4 || n==6 || n==8)
        {
            if(ar[n]<79)
            {
                r=n;
                break;
            }
        }
        cont++;
    }
    return r;
}

int getInt(void)
{
    char str[40];
    gets(str);
    int i,sum=0,len=strlen(str);
    for(i=0;i<len;++i)
    {
        if(str[i]>47 && str[i]<58)
        {
            sum=sum*10+str[i]-48;
        }

        else
        {
            sum=0;
            break;
        }

    }
    return sum;
}
