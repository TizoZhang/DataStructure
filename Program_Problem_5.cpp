#include<iostream>

using namespace std;

#define MaxSize 100

typedef int ElemType;

typedef struct{
	ElemType *base;
	ElemType *top;
	int Stack_Size;
}SqStack;//顺序栈的存储结构

void Init_SqStack(SqStack &S)
{
	S.base = new ElemType[MaxSize];
	if(!S.base)
		return;
	S.top = S.base;
	S.Stack_Size = MaxSize;
}//顺序栈的初始化

void Push_SqStack(SqStack &S, ElemType e)
{
	if (S.top - S.base == S.Stack_Size)
		return;
	*(S.top++) = e;
}//顺序栈的入栈

void Pop_SqStack(SqStack &S, ElemType &e)
{
	if (S.base == S.top)
		return;
	e = *(--S.top);
}//顺序栈的出栈

int GetTop_SqStack(SqStack S) {
	if (S.top != S.base)
		return *(S.top - 1);
}//取栈顶元素

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
}//先模运算入栈再出栈

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

