#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
struct Node{
    int a;
    struct Node* Pnext;
};
struct Node* g_pHead=NULL;
struct Node* g_pEnd=NULL;

// 创建链表,在链表中增加一个数据 尾添加
void AddlistTill(int a){
    struct Node* pTmep= (struct Node*)malloc(sizeof(struct Node));
    pTmep->a=a;
    pTmep->Pnext=NULL;
    if(g_pEnd==NULL)
    {
        g_pEnd=pTmep;
        g_pHead=pTmep;
    }
    else
    {
        g_pEnd->Pnext=pTmep;
        g_pEnd=pTmep;
    }
}

// 插入表头
void AddListHead(int a){
    struct Node* pTcmp=(struct Node*)malloc(sizeof(struct Node));
    pTcmp->a=a;
    pTcmp->Pnext=NULL;
    if(g_pHead==NULL)
    {
        g_pHead=pTcmp;
        g_pEnd=pTcmp;
    }
    else{
        pTcmp->Pnext=g_pHead;
        g_pHead=pTcmp;
    }
}

// 遍历链表
void ScanList(){
    struct Node* pTcmp=g_pHead;
    while(pTcmp!=NULL){
        cout<<pTcmp->a<<endl;
        pTcmp=pTcmp->Pnext;
    }
}

// 选择值为a的链表元素
struct Node* SelectNode(int a){
    struct Node *pTemp=g_pHead;
    while(pTemp!=NULL)
    {
        if(pTemp->a==a)
        {
            return pTemp;
        }
        pTemp=pTemp->Pnext;
    }
    return NULL;
}

// 找到位置为index链表元素
struct Node* SelectIndex(int index){
    int i=0;
    struct Node * pTemp=g_pHead;
    while(pTemp!=NULL&&i<index){
        i++;
        pTemp=pTemp->Pnext;
    }
    return pTemp;
};

// 释放链表
void FreeList()
{
    struct Node *pTemp=g_pHead;
    while(pTemp!=NULL)
    {
        struct Node* Pt=pTemp;
        pTemp=pTemp->Pnext;
        free(Pt);
    }
    g_pHead=NULL;
    g_pEnd=NULL;
}

// 指定位置之后插入节点
void AddListRans(int index,int a){
    if(NULL==g_pHead)
    {
        cout<<"链表没有节点"<<endl;
        return;
    }
    // 找位置
    struct Node* pTemp=SelectIndex(index);
    if(pTemp==NULL)
    {
        cout<<"链表没有节点"<<endl;
        return;
    }
    struct Node* pt=(struct Node*)malloc(sizeof(struct Node));
    pt->a=a;
    pt->Pnext=NULL;
    // 当前为尾指针
    if(pTemp==g_pEnd)
    {
        g_pEnd->Pnext=pt;
        g_pEnd=pt;
    }else{
        pt->Pnext=pTemp->Pnext;
        pTemp->Pnext=pt;
    }
}

// 头删除
void DeleteListHead(){
    if(NULL==g_pHead){
        printf("链表为空");
        return ;
    }
    struct Node* pTemp=g_pHead;
    g_pHead=g_pHead->Pnext;
    return ;
}

// 尾删除
void DeleteListTail(){
    if(NULL==g_pHead){
        printf("链表为空");
        return ;
    }
    if(g_pHead==g_pEnd)
    {
        free(g_pHead);
        g_pHead=NULL;
        g_pEnd=NULL;
    }else{
        struct Node* pTemp=g_pHead;
        while(pTemp->Pnext!=g_pEnd)
        {
            pTemp=pTemp->Pnext;
        }
        free(g_pEnd);
        g_pEnd=pTemp;
        g_pEnd->Pnext=NULL;
    }
}

//  删除指定节点
void DeleteListRand(int a)
{
    if(NULL==g_pHead)
    {
        cout<<"链表为NULL"<<endl;
        return ;
    }
    struct Node* Ptemp=SelectNode(a);
    if(g_pHead==g_pEnd){
        free(g_pEnd);
        g_pEnd=NULL;
        g_pHead=NULL;
    }else if(g_pHead->Pnext==g_pEnd){
        if(g_pHead==Ptemp){
            DeleteListHead();
        }else if(g_pEnd==Ptemp){
            DeleteListTail();
        }
    }else{
        if(g_pHead==Ptemp){
            DeleteListHead();
        }else if(g_pEnd==Ptemp){
            DeleteListTail();
        }
        else{
            struct Node* pT=g_pHead;
            while(pT->Pnext!=Ptemp)
            {
                pT=pT->Pnext;
            }
            // 链接
            pT->Pnext=Ptemp->Pnext;
            free(Ptemp);
        }
    }
    return ;
}
int main(){

    for(int i=1;i<=10;i++)
    {
        AddListHead(i);
    }
   // 遍历链表
   // ScanList();
   // struct Node *pFind=SelectNode(1);
   // cout<<pFind->a<<endl;

    // 清空链表
    // FreeList();

    // 选择相应的索引
    // struct Node *pTemp=SelectIndex(0);
    // 指定位置添加节点
    // AddListRans(0,11);
    system("pause");
    return 0;
}
