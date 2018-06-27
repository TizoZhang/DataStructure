#include<iostream>

#define MaxSize 100

using namespace std;

typedef char ElemType;

typedef struct BiNode{
    ElemType data;
    struct BiNode *Lchild,*Rchild;
}BiNode,*BiTree;//二叉树的链式存储结构

ElemType *Pre_Order = new ElemType [MaxSize];
int cnt;

BiNode *Creat_BiTree_PreOrder()
{
    BiTree root;
    if(Pre_Order[cnt++] == ',')
        root = NULL;
    else
    {
        root = new BiNode;
        root->data = Pre_Order[cnt - 1];
        root->Lchild = Creat_BiTree_PreOrder();
        root->Rchild = Creat_BiTree_PreOrder();
    }
    return root;
}//先序遍历法创建二叉树

void Leaves_LevelOrderTraverse(BiTree T)
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
        if(p->Lchild == NULL && p->Rchild == NULL)
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
}//二叉树的层次遍历输出叶子结点（运用循环队列）

int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>Pre_Order){
       cnt = 0;
       BiTree T = Creat_BiTree_PreOrder();
       Leaves_LevelOrderTraverse(T);
    }
    return 0;
}
