#include<iostream>
#include<stdio.h>
#include<string.h>

#define MaxSize 300

using namespace std;

typedef char ElemType;

typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
}StackNode,*LinkStack;//链栈的存储结构

void Init_StackNode(LinkStack &S)
{
    S = NULL;
}//链栈的初始化

void Push_StackNode(LinkStack &S, ElemType e)
{
    LinkStack p;
    p = new StackNode;
    p->data = e;
    p->next = S;
    S = p;
}//链栈的入栈

void Pop_StackNode(LinkStack &S, ElemType &e)
{
    LinkStack p;
    if(S == NULL)
        return ;
    e = S->data;
    p = S;
    S = S->next;
    delete p;
}//链栈的出栈

ElemType GetTop_StackNode(LinkStack S)
{
    if(S != NULL)
        return S->data;
}//取链栈栈顶元素

void Solve_Problem_StackNode(ElemType *Str)
{
    StackNode *S,*T;
    Init_StackNode(S);
    Init_StackNode(T);
    ElemType e;
    for(int i = 0; i < strlen(Str); ++i)
        if(Str[i] == '@'){
            while(S != NULL)
                Pop_StackNode(S,e);
        }
        else if(Str[i] == '#')
            Pop_StackNode(S,e);
        else
            Push_StackNode(S,Str[i]);
    while(S != NULL){
        Pop_StackNode(S,e);
        Push_StackNode(T,e);
    }
    while(T != NULL){
        Pop_StackNode(T,e);
        cout<<e;
    }
    cout<<endl;
}//解决问题的算法

int main()
{
    std::ios::sync_with_stdio(false);
    ElemType *Str = new ElemType[MaxSize];
    while(gets(Str))
        Solve_Problem_StackNode(Str);
    return 0;
}
