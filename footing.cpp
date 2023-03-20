//
// Created by 35320 on 2023/3/8.
//

//普通回溯


#include<iostream>
using namespace std;
int dp[10][10];
bool checkr(int x,int y) //行检验
{
    for(int i=1;i<10;i++)
    {
        if(i!=y&&dp[x][i]==dp[x][y])
            return false;
    }
    return true;
}
bool checkc(int x,int y)   //列检验
{
    for(int i=1;i<10;i++)
    {
        if(i!=x&&dp[i][y]==dp[x][y])
            return false;
    }
    return true;
}
bool checkg(int x,int y)   //九宫格检验
{
    int xx=(x-1)/3,yy=(y-1)/3;
    for(int i=xx*3+1;i<=xx*3+3;i++)
        for(int j=yy*3+1;j<=yy*3+3;j++)
        {
            if((i!=x||j!=y)&&dp[i][j]==dp[x][y])
                return false;
        }
    return true;
}
bool check(int x,int y)      //检验
{
    if(checkr(x,y)&&checkc(x,y)&&checkg(x,y))
        return true;
    return false;
}
void print(int dp[][10])
{
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
            cout<<dp[i][j];
        cout<<endl;
    }
}

void backtr(int x,int y)
{
    if(x==10&&y==1)
    {
        print(dp);
        cout<<endl;
        return;
    }
    if(dp[x][y]==0)
    {
        for(int k=1;k<=9;k++)
        {
            dp[x][y]=k;
            if(check(x, y))
            {
                if(y==9)
                {
                    backtr(x+1,1);
                }
                else backtr(x,y+1);
            }
            dp[x][y]=0;
        }
    }
    else
    {
        if(check(x, y))
        {
            if(y==9)
            {
                backtr(x+1,1);
            }
            else backtr(x,y+1);
        }
    }
}
int main()
{
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            char c;
            cin>>c;
            if(c!='.')
            {
                dp[i][j] = c - '0';
            }
        }
        getchar();
    }
    backtr(1,1);
    return 0;
}
