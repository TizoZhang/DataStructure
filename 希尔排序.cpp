#include<iostream>
#define MAXSIZE 20
typedef int KeyType;

using namespace std;

typedef struct{
    KeyType key;
}RedType;

typedef struct{
    RedType r[MAXSIZE+1];
    int length;
}SqList;

void ShellInsert(SqList &L,int dk)
{
    int i,j;
    for(i=dk+1;i<=L.length;++i)
        if(L.r[i].key<L.r[i-dk].key)
        {
            L.r[0]=L.r[i];
            for(j=i-dk;j>0 && L.r[0].key<L.r[j].key;j-=dk)
                L.r[j+dk]=L.r[j];
            L.r[j+dk]=L.r[0];
        }
}

void ShellSort(SqList &L,int dt[],int t)
{
    int k;
    for(k=0;k<t;++k)
        ShellInsert(L,dt[k]);
}

int main()
{
    int t;
    SqList L;
    int a[10]={9,8,7,6,5,4,3,2,1,0};
    int i,j;
    for(i=0;i<10;i++)
    {
        L.r[i+1].key=a[i];
    }
    L.length=10;
    ShellSort(L,a,10);
    cout<<"排序后的结果为 "<<endl;
    for(j=1;j<=10;j++)
        cout<<L.r[j].key<<endl;
}
