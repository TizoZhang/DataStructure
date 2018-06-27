#include<iostream>

typedef int ElemType;

using namespace std;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;//链表的存储结构

void Init_LinkList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
}//初始化链表

void Insert_LinkList(LinkList &L,int i,ElemType e)
{
    LinkList s,p = L;
    int j=0;
    while(p && (j<i-1)){
        p = p->next;
        ++j;
    }
    if(!p || j > i-1) return;
    s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
}//链表的插入

void Delete_LinkList(LinkList &L,int i,ElemType &e)
{
    LinkList q,p = L;
    int j = 0;
    while(p && (j<i-1)){
        p = p->next;
        ++j;
    }
    if(!(p->next) || (j>i-1)) return;
    q = p->next;
    e = q->data;
    p->next = q->next;
    delete q;
}//链表的删除

void Creat_LinkList(LinkList &L,int n)
{
    LinkList r,p;
    L = new LNode;
    L->next = NULL;
    r = L;
    for(int i = 0; i < n; ++i){
        p = new LNode;
        cin>>p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}//后插法创建链表

int Length_LinkList(LinkList L)
{
    int tot=0;
    LinkList p = L->next;
    while(p){
        ++tot;
        p = p->next;
    }
    return tot;
}//计算链表长度

void Display_LinkList(LinkList L)
{
    LinkList p = L->next;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}//输出链表

void Re_LinkLsit(LinkList &L)
{
    ElemType e;
    for(int i = 1; i <= Length_LinkList(L)-1; ++i){
    Delete_LinkList(L,Length_LinkList(L),e);
    Insert_LinkList(L,i,e);
    }
}//链表的逆序

void Delete_Repeat_LinkList(LinkList &L)
{
    LinkList r,q,p = L;
    ElemType e1,e2,e3;
    for(int i = 1; i <= Length_LinkList(L); ++i){
        p = p->next;
        e1 = p->data;
        q = p;
        for(int j = i+1; j <= Length_LinkList(L); ++j){
            r = q;
            q = q->next;
            e2 = q->data;
            if(e2 == e1){
                Delete_LinkList(L,j,e3);
                --j;
                q = r;
            }
        }
    }
}//删除链表中的重复元素

int main()
{
    std::ios::sync_with_stdio(false);
    int length;
    cin>>length;
    LinkList L;
    Init_LinkList(L);
    Creat_LinkList(L,length);
    Re_LinkLsit(L);
    cout<<Length_LinkList(L)<<endl;
    Display_LinkList(L);
    Delete_Repeat_LinkList(L);
    cout<<Length_LinkList(L)<<endl;
    Display_LinkList(L);
    return 0;
}
