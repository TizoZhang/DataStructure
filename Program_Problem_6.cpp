#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
#define MaxSize 100

typedef char ElemType;

typedef struct{
    ElemType *base;
    ElemType *top;
    int SqStack_Length;
}SqStack;//Ë³ÐòÕ»µÄ´æ´¢½á¹¹

void Init_SqStack(SqStack &S)
{
    S.base = new ElemType[MaxSize];
    if(!S.base)
        return ;
    S.top = S.base;
    S.SqStack_Length = MaxSize;
}//Ë³ÐòÕ»µÄ³õÊ¼»¯

void Push_SqStack(SqStack &S, ElemType e)
{
    if(S.top - S.base == S.SqStack_Length)
        return ;
    *(S.top++) = e;
}//Ë³ÐòÕ»µÄÈëÕ»

void Pop_SqStack(SqStack &S, ElemType &e)
{
    if(S.top == S.base)
        return ;
    e = *(--S.top);
}//Ë³ÐòÕ»µÄ³öÕ»

ElemType GetTop_SqStack(SqStack S)
{
    if(S.top != S.base)
        return *(S.top - 1);
}//È¡Õ»¶¥ÔªËØ

bool StackEmpty_SqStack(SqStack S)
{
    if(S.top == S.base)
        return true;
    else
        return false;
}//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ

bool Matching_Brackets(ElemType* Str)
{
    SqStack S;
    Init_SqStack(S);
    int flag = 1;
    ElemType x;
    for(int i = 0;i < strlen(Str); ++i){
        if(!flag)
            break;
        if(Str[i] == '[' || Str[i] == '(' || Str[i] == '{')
            Push_SqStack(S,Str[i]);
        else if(Str[i] == ')'){
            if(!StackEmpty_SqStack(S) && GetTop_SqStack(S) == '(')
                Pop_SqStack(S,x);
            else
                flag = 0;
        }
        else if(Str[i] == ']'){
            if(!StackEmpty_SqStack(S) && GetTop_SqStack(S) == '[')
                Pop_SqStack(S,x);
            else
                flag = 0;
        }
        else if(Str[i] == '}'){
            if(!StackEmpty_SqStack(S) && GetTop_SqStack(S) == '{')
                Pop_SqStack(S,x);
            else
                flag = 0;
        }
    }
    if(StackEmpty_SqStack(S) && flag)
        return true;
    else
        return false;
}//À¨ºÅÆ¥ÅäËã·¨

int main()
{
    std::ios::sync_with_stdio(false);
    ElemType* Str = new ElemType[MaxSize];
    while(gets(Str)){
        if(Matching_Brackets(Str))
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
    return 0;
}


