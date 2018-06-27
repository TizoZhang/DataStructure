#include<iostream>

using namespace std;

#define MaxSize 100

typedef int ElemType;

typedef struct{
	ElemType *base;
	ElemType *top;
	int Stack_Size;
}SqStack;//˳��ջ�Ĵ洢�ṹ

void Init_SqStack(SqStack &S)
{
	S.base = new ElemType[MaxSize];
	if(!S.base)
		return;
	S.top = S.base;
	S.Stack_Size = MaxSize;
}//˳��ջ�ĳ�ʼ��

void Push_SqStack(SqStack &S, ElemType e)
{
	if (S.top - S.base == S.Stack_Size)
		return;
	*(S.top++) = e;
}//˳��ջ����ջ

void Pop_SqStack(SqStack &S, ElemType &e)
{
	if (S.base == S.top)
		return;
	e = *(--S.top);
}//˳��ջ�ĳ�ջ

int GetTop_SqStack(SqStack S) {
	if (S.top != S.base)
		return *(S.top - 1);
}//ȡջ��Ԫ��

void Problem_Push_Pop_SqStack(SqStack &S, ElemType n, int R)
{
    ElemType e,tot=0;
    while(n){
        Push_SqStack(S,n%R);
        tot++;
        n/=R;
    }
    while(tot--){
        Pop_SqStack(S,e);
        cout<<e;
    }
    cout<<endl;
}//��ģ������ջ�ٳ�ջ

int main()
{
    std::ios::sync_with_stdio(false);
    SqStack S;
    Init_SqStack(S);
    int n,R;
    cin>>n>>R;
    Problem_Push_Pop_SqStack(S,n,R);
	return 0;
}

