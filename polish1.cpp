//
// Created by 35320 on 2023/3/20.
//
#include  <iostream>
#include <algorithm>
using namespace std;
const int N=10;
char g[N][N];
bool row[N][N];
bool col[N][N];
bool cell[4][4][N];
bool dfs(int x,int y)
{
    if(y==9) 
    {
        x++, y = 0; 
    }
    if(x==9)
    {
        for(int i=0;i<9;i++)
            cout<<g[i]<<endl;
        return true;
    }
    if(g[x][y]!='.')
        return dfs(x,y+1);
    for(int i=1;i<=9;i++)
        if(!row[x][i]&&!col[y][i]&&!cell[x/3][y/3][i])
        {
            g[x][y]=i+'0';
            row[x][i]=col[y][i]=cell[x/3][y/3][i]=true;
            if(dfs(x,y+1))
                return true;
            g[x][y]='.';
            row[x][i]=col[y][i]=cell[x/3][y/3][i]=false;
        }
    return false;
}
int main()
{
    for(int i=0;i<9;i++)
    {
        cin>>g[i];
        for(int j=0;j<9;j++)
        {
            if(g[i][j]=='.')
                continue;
            else
            {
                int t =g[i][j]-'0'; 
                row[i][t]=col[j][t]=cell[i/3][j/3][t]=true;
            }
        }
    }
    dfs(0,0);
    return 0;
}
