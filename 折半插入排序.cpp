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

void BInsertSort(SqList &L)
{
    int i,j,m,low,high;
    for(i=2;i<=L.length;i++)
    {
        L.r[0]=L.r[i];
        low=1;high=i-1;
        while(low<=high)
        {
            m=(low+high)/2;
            if(L.r[0].key<L.r[m].key)   high=m-1;
            else low=m+1;
        }
        for(j=i-1;j>=high+1;--j)    L.r[j+1]=L.r[j];
        L.r[high+1]=L.r[0];
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
    BInsertSort(L);
    cout<<"排序后的结果为 "<<endl;
    for(j=1;j<=10;j++)
        cout<<L.r[j].key<<endl;
}
