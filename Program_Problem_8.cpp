#include<iostream>
#include<string.h>

#define MaxSize 100

using namespace std;

typedef char ElemType;

typedef struct BiNode{
    ElemType data;
    struct BiNode *Lchild,*Rchild;
}BiNode,*BiTree;//����������ʽ�洢�ṹ

int Search_Num(ElemType Num, ElemType *Str, int len)
{
    for(int i = 0; i < len; ++i)
        if(Str[i] == Num)
            return i;
}//����һ��Ԫ���������е�λ��

void PostOrderTraverse(BiTree T)
{
    if(T != NULL)
    {
        PostOrderTraverse(T->Lchild);
        PostOrderTraverse(T->Rchild);
        cout<<T->data;
    }
}//���������������

void LevelOrderTraverse(BiTree T)
{
    BiTree p;
    BiTree Queue[MaxSize];
    int front,rear;
    front = rear = -1;
    rear++;
    Queue[rear] = T;
    while(front != rear){
        front = (front + 1) % MaxSize;
        p = Queue[front];
        cout<<p->data;
        if(p->Lchild != NULL){
            rear = (rear + 1) % MaxSize;
            Queue[rear] = p->Lchild;
        }
        if(p->Rchild != NULL){
            rear = (rear + 1) % MaxSize;
            Queue[rear] = p->Rchild;
        }
    }
}//�������Ĳ�α���������ѭ�����У�

BiTree Resume_BiTree(ElemType *Pre_Order,ElemType *In_Order,int len)
{
    if(len <= 0)
      return NULL;
    BiTree temp = new BiNode;
    temp->data = *Pre_Order;
    int index = Search_Num(*Pre_Order,In_Order,len);
    temp->Lchild = Resume_BiTree(Pre_Order+1,In_Order,index);
    temp->Rchild = Resume_BiTree(Pre_Order+index+1,In_Order+index+1,len-index-1);
    return temp;
}//��֪������������������ԭ������

int main(void)
{
    std::ios::sync_with_stdio(false);
    ElemType *Pre_Order = new ElemType [MaxSize];
    ElemType *In_Order  = new ElemType [MaxSize];
    int N;
    cin>>N;
    while(N--){
        cin>>Pre_Order>>In_Order;
        BiTree Tree = Resume_BiTree(Pre_Order,In_Order,strlen(In_Order));
        PostOrderTraverse(Tree);
        cout<<endl;
        LevelOrderTraverse(Tree);
        cout<<endl;
    }
    return 0;
}
