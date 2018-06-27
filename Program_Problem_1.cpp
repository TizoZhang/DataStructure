#include<iostream>
#define MaxSize 1000000

typedef int ElemType;

using namespace std;

typedef struct
{
    ElemType *elem;
    int length;
}SqList;//˳���Ĵ洢�ṹ

void Init_SqList(SqList &L)
{
    L.elem = new ElemType[MaxSize];
    if(!L.elem) return;
    L.length = 0;
}//˳���ĳ�ʼ��


void Input_SqList(SqList &L,int length)
{
    L.length = length;
    for(int i = 0; i < L.length; ++i)
        cin>>L.elem[i];
}//˳��������

void Display_SqList(SqList L)
{
    for(int i = 0; i < L.length; ++i)
        cout<<L.elem[i]<<" ";
        cout<<endl;
}//˳�������

void Insert_SqList(SqList &L,int i,ElemType e)
{
    if((i < 1) || (i > L.length+1)) return;
    if(L.length == MaxSize) return;
    for(int j = L.length-1; j >= i-1; --j)
        L.elem[j+1] = L.elem[j];
    L.elem[i-1] = e;
    ++L.length;
}//˳���Ĳ���

void Delete_SqList(SqList &L,int i,ElemType &e)
{
    if((i < 1) || (i > L.length)) return;
    e = L.elem[i-1];
    for(int j = i; j <= L.length-1; ++j)
        L.elem[j-1] = L.elem[j];
    --L.length;
}//˳����ɾ��

void SolveProblem_SqLsit(SqList &L,int t)
{
    ElemType e;
    int s = L.length;
    for(int i = 1; i <= t; ++i){
        Delete_SqList(L,1,e);
        Insert_SqList(L,s,e);
    }
}//���������㷨

int main()
{
    std::ios::sync_with_stdio(false);
    int N;
    cin>>N;
    SqList L;
    Init_SqList(L);
    while(N--){
        int length,t;
        cin>>length>>t;
        Input_SqList(L,length);
        SolveProblem_SqLsit(L,t);
        Display_SqList(L);
    }
    return 0;
}
