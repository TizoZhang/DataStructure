#include<iostream>
#define MaxSize 10000

typedef int ElemType;

using namespace std;

typedef struct
{
    ElemType *elem;
    int length;
}SqList;//顺序表的存储结构

void Init_SqList(SqList &L)
{
    L.elem = new ElemType[MaxSize];
    if(!L.elem) return;
    L.length = 0;
}//顺序表的初始化


void Input_SqList(SqList &L,int length)
{
    L.length = length;
    for(int i = 0; i < L.length; ++i)
        cin>>L.elem[i];
}//顺序表的输入

void Display_SqList(SqList L)
{
    for(int i = 0; i < L.length; ++i)
        cout<<L.elem[i]<<" ";
        cout<<endl;
}//顺序表的输出

void Insert_SqList(SqList &L,int i,ElemType e)
{
    if((i < 1) || (i > L.length+1)) return;
    if(L.length == MaxSize) return;
    for(int j = L.length-1; j >= i-1; --j)
        L.elem[j+1] = L.elem[j];
    L.elem[i-1] = e;
    ++L.length;
}//顺序表的插入

void SolveProblem_SqLsit(SqList &L1,SqList L2)
{
    for(int i = 0; i < L2.length; ++i)
    for(int j = 0; j < L1.length; ++j){
        if(L2.elem[i] > L1.elem[L1.length-1]){
            Insert_SqList(L1,L1.length+1,L2.elem[i]);
            break;
        }
        else if(L2.elem[i] == L1.elem[j])
            break;
        else if(L2.elem[i] < L1.elem[j]){
            Insert_SqList(L1,j+1,L2.elem[i]);
            break;
        }
    }
}//解决问题的算法

int main()
{
    std::ios::sync_with_stdio(false);
    SqList L1,L2;
    Init_SqList(L1);
    Init_SqList(L2);
    int length_1,length_2;
    cin>>length_1>>length_2;
    Input_SqList(L1,length_1);
    Input_SqList(L2,length_2);
    SolveProblem_SqLsit(L1,L2);
    Display_SqList(L1);
    return 0;
}

