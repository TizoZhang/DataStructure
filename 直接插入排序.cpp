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

void InsertSort(SqList &L)
{
    int i,j;
    for(i=2;i<=L.length;++i)
        if(L.r[i].key<L.r[i-1].key)
        {
            L.r[0]=L.r[i];
            L.r[i]=L.r[i-1];
            for(j=i-2;L.r[0].key<L.r[j].key;--j)
                L.r[j+1]=L.r[j];
            L.r[j+1]=L.r[0];
        }
}

int main()
{
    SqList L;
    int a[10]={9,8,7,6,5,4,3,2,1,0};
    int i,j;
    for(i=0;i<10;i++)
    {
        L.r[i+1].key=a[i];
    }
    L.length=10;
    InsertSort(L);
    cout<<"排序后的结果为 "<<endl;
    for(j=1;j<=10;j++)
        cout<<L.r[j].key<<endl;
}
