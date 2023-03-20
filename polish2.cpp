//
// Created by 35320 on 2023/3/15.
//
#include<iostream>
#include<cmath>
using namespace std;
const int  N=9,M=1<<N;
int row[N],col[N],cell[3][3];
int numof1[M],dp[N][N];
void ini()        //位运算初始化
{
    for(int i=0;i<N;i++)
        row[i]=col[i]=(1 << N )-1;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cell[i][j]=(1<<N)-1;
}
void assi(int i,int j,int t,bool flag)  //赋值使能与失能
{
    if(flag)dp[i][j]=t;
    else dp[i][j]=0;
    int ob=1<<t-1;
    if(flag) ob=-ob;
    row[i]+=ob;
    col[j]+=ob;
    cell[i/3][j/3]+=ob;
}
int getn(int i,int j)  //得到可以填入的数字之和
{
    return row[i]&col[j]&cell[i/3][j/3];
}
int getl(int x)    //得到一个二进制数的最低位
{
    return x  & -x;
}
void print(int dp[][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<dp[i][j];
        cout<<endl;
    }
}
bool recur(int cnt)     //对剩余空格数进行回溯递归
{
    if(!cnt) return true;
    int sum=10,x,y;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(!dp[i][j])
            {//sta为可填入数字之和
                int sta=getn(i,j);
                if(numof1[sta]<sum)
                {//numof1数组得出可填入数
                    sum=numof1[sta];
                    x=i,y=j;
                }
            }//获得可填数最小位置的坐标
    int sta=getn(x,y);//得到可填数最小的位置
    for(int i=sta;i;i-=getl(i))
    {//对该数从最低位开始遍历
        int t=log2(getl(i))+1;//转为十进制
        assi(x,y,t,true);//使能改位置
        if(recur(cnt-1))
            return true;//对剩余空格数进行回溯递归
        assi(x,y,t,false);//失能该位置
    }
    return false;
}
int main()
{
    //得到一个数转化为二进制数后有几个1
    for(int i=0;i< 1<<N;i++)
        for(int j=0;j<N;j++)
            numof1[i]+=i>>j&1;
    int cnt=0;
    ini();
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            char t;
            cin>>t;
            if(t!='.')
            {
                int tt=t-'0';
                assi(i,j,tt,true);
            }
            else cnt++;
        }
        getchar();
    }
    if(recur(cnt)) print(dp);
    return 0;
}
