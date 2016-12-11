//
// Created by Cooper on 07/12/2016.
//2016-12-10 08:50:26 于图书馆
///错误：将要读取的文件没有放在该可执行文件的根目录下，导致fopen函数无法读取文件
//以后如果不能确定可执行文件（.exe）在哪里，就要在fopen的第一个地址参数中填写绝对路径，而不可以使用相对路径！！！
//另外clion的调试功能今天初次大规模使用，真是爽的飞起，程序员的利器啊！设置断点，观察变量值的改变是否如自己所愿。可以精确地定位到出错的位置，由此可见，debug程序是一个程序员的必备工具，要用好这个工具以后就不在害怕错误，反而能够迎难而上呢！debug对于程序员来说就如同金箍棒对于齐天大圣呢！
#ifndef GRAPH_FUNC_H
#define GRAPH_FUNC_H

#include "graph.h"

/* bo7-1.c 图的数组(邻接矩阵)存储(存储结构由c7-1.h定义)的基本操作(20个) */
int LocateVex(MGraph G,VertexType u)
{ /* 初始条件:图G存在,u和G中顶点有相同特征 */
    /* 操作结果:若G中存在顶点u,则返回该顶点在图中位置;否则返回-1 */
    int i;
    for(i=0;i<G.vexnum;++i) //遍历图中当前存在的结点
        if(strcmp(u,G.vexs[i])==0) //比较要定位的元素u是否与图中的某个结点相同
            return i; //返回
    return -1;
}

Status CreateFAG(MGraph *G)
{ /* 采用数组(邻接矩阵)表示法,由文件构造没有相关信息的无向图G */
    int i,j,k;
    char filename[13];
    VertexType va,vb;
    FILE *graphlist;
//    printf("Please input file name:"); //请输入数据文件名(f7-1.c)：
//    scanf("%s",filename);

    if(!(graphlist=fopen("file.c" ,"r")))///相对路径使用要注意文件要存放在和.exe同一个根目录下，否则fopen找不到这个文件！！！
        exit(OVERFLOW);
    fscanf(graphlist,"%d",&(*G).vexnum);
    fscanf(graphlist,"%d",&(*G).arcnum);
    for(i=0;i<(*G).vexnum;++i) /* 构造顶点向量 */
        fscanf(graphlist,"%s",(*G).vexs[i]);
    for(i=0;i<(*G).vexnum;++i) /* 初始化邻接矩阵 */
        for(j=0;j<(*G).vexnum;++j)
        {
            (*G).arcs[i][j].adj=0; /* 图 */
            (*G).arcs[i][j].info=NULL; /* 没有相关信息 */
        }
    for(k=0;k<(*G).arcnum;++k)
    {
        fscanf(graphlist,"%s%s",va,vb);
        i=LocateVex(*G,va);
        j=LocateVex(*G,vb);
        (*G).arcs[i][j].adj=(*G).arcs[j][i].adj=1; /* 无向图 */
    }
    fclose(graphlist);
    (*G).kind=AG;
    return OK;
}

Status CreateDG(MGraph *G)
{ /* 采用数组(邻接矩阵)表示法,构造有向图G */
    int i,j,k,l,IncInfo;
    char s[MAX_INFO],*info=NULL;
    VertexType va,vb;
    printf("Please input vexnum, arcnum, if have other info(0=No,1=Yes):"); // 请输入有向图G的顶点数,弧数,弧是否含其它信息(是:1,否:0):
    scanf("%d,%d,%d",&(*G).vexnum,&(*G).arcnum,&IncInfo);
    printf("Please input %d vex's value\n",(*G).vexnum,MAX_NAME); // 请输入%d个顶点的值(<%d个字符):
    for(i=0;i<(*G).vexnum;++i) /* 构造顶点向量 */
        scanf("%s",(*G).vexs[i]);
    for(i=0;i<(*G).vexnum;++i) /* 初始化邻接矩阵 */
        for(j=0;j<(*G).vexnum;++j)
        {
            (*G).arcs[i][j].adj=0; /* 图 */
                (*G).arcs[i][j].info=NULL; //初始化的信息为空
        }
    printf("Please input %d arcs' arctail, archead(split with ' '\n",(*G).arcnum); // 请输入%d条弧的弧尾 弧头(以空格作为间隔):
    for(k=0;k<(*G).arcnum;++k)
    {
        scanf("%s%s%*c",va,vb);  /* %*c吃掉回车符 */
        i=LocateVex(*G,va);
        j=LocateVex(*G,vb);
        (*G).arcs[i][j].adj=1; // 记录该位置的弧是否相通 /* 有向图 */
        if(IncInfo) // 如果有相关信息
        {
            printf("Please input this arc's info(<%d char)",MAX_INFO); // 请输入该弧的相关信息(<%d个字符):
            gets(s);
            l=strlen(s);
            if(l)
            {
                info=(char*)malloc((l+1)*sizeof(char)); // 因为初始化时侯，info只是一个字符指针并没有分配空间
                strcpy(info,s); // 字符串之间复制记得用 strcpy函数，便捷高效
                (*G).arcs[i][j].info=info; /* 有向 */ //将弧的信息存入数组中
            }
        }
    }
    (*G).kind=DG; // 有向图
    return OK;
}

Status CreateDN(MGraph *G)
{ /* 采用数组(邻接矩阵)表示法,构造有向网G */
    int i,j,k,w,IncInfo;
    char s[MAX_INFO],*info;
    VertexType va,vb;
    printf("Please input DG's vexnum, arcnum, if have info(Y:1,N:0):");
    // 请输入有向网G的顶点数,弧数,弧是否含其它信息(是:1,否:0):
    scanf("%d,%d,%d",&(*G).vexnum,&(*G).arcnum,&IncInfo);
    printf("Please input %d vex value(<%d char)\n",(*G).vexnum,MAX_NAME); // 请输入%d个顶点的值(<%d个字符):
    for(i=0;i<(*G).vexnum;++i) /* 构造顶点向量 */
        scanf("%s",(*G).vexs[i]);
    for(i=0;i<(*G).vexnum;++i) /* 初始化邻接矩阵 */
        for(j=0;j<(*G).vexnum;++j)
        {
            (*G).arcs[i][j].adj=INFINITY; /* 网 */
            (*G).arcs[i][j].info=NULL;
        }
    printf("Please input %d arcs' tail head weight(split with ' ')\n",(*G).arcnum); // 请输入%d条弧的弧尾 弧头 权值(以空格作为间隔):
    for(k=0;k<(*G).arcnum;++k)
    {
        scanf("%s%s%d%*c",va,vb,&w);  /* %*c吃掉回车符 */
        i=LocateVex(*G,va);
        j=LocateVex(*G,vb);
        (*G).arcs[i][j].adj=w; /* 有向网 */
        if(IncInfo)
        {
            printf("Please input this arc's info(<%d char)",MAX_INFO); // 请输入该弧的相关信息(<%d个字符):
            gets(s);
            w=strlen(s);
            if(w)
            {
                info=(char*)malloc((w+1)*sizeof(char));
                strcpy(info,s);
                (*G).arcs[i][j].info=info; /* 有向 */
            }
        }
    }
    (*G).kind=DN;
    return OK;
}

Status CreateAG(MGraph *G)
{ /* 采用数组(邻接矩阵)表示法,构造有相关信息的无向图G */
    int i,j,k,l,IncInfo;
    char s[MAX_INFO],*info;
    VertexType va,vb;
    printf("Please input AG's vexnum, arcnum, if have info(Y:1,N:0): ");
    // 请输入无向图G的顶点数,边数,边是否含其它信息(是:1,否:0):
    scanf("%d,%d,%d",&(*G).vexnum,&(*G).arcnum,&IncInfo);
    printf("Please input %d vex value(<%d char):\n",(*G).vexnum,MAX_NAME);
    // 请输入%d个顶点的值(<%d个字符):
    for(i=0;i<(*G).vexnum;++i) /* 构造顶点向量 */
        scanf("%s",(*G).vexs[i]);
    for(i=0;i<(*G).vexnum;++i) /* 初始化邻接矩阵 */
        for(j=0;j<(*G).vexnum;++j)
        {
            (*G).arcs[i][j].adj=0; /* 图 */
            (*G).arcs[i][j].info=NULL;
        }
    printf("Please input %d arcs' tail head weight(split with ' ')\n",(*G).arcnum);//请输入%d条边的顶点1 顶点2(以空格作为间隔):
    for(k=0;k<(*G).arcnum;++k)
    {
        scanf("%s%s%*c",va,vb); /* %*c吃掉回车符 */
        i=LocateVex(*G,va);
        j=LocateVex(*G,vb);
        (*G).arcs[i][j].adj=(*G).arcs[j][i].adj=1; /* 无向图 */
        if(IncInfo)
        {
            printf("Please input this arc's info(<%d char)",MAX_INFO);//请输入该边的相关信息(<%d个字符):
            gets(s);
            l=strlen(s);
            if(l)
            {
                info=(char*)malloc((l+1)*sizeof(char));
                strcpy(info,s);
                (*G).arcs[i][j].info=(*G).arcs[j][i].info=info;
            }
        }
    }
    (*G).kind=AG; /* 无向图 */
    return OK;
}

Status CreateAN(MGraph *G)
{ /* 采用数组(邻接矩阵)表示法,构造无向网G。算法7.2 */
    int i,j,k,w,IncInfo;
    char s[MAX_INFO],*info;
    VertexType va,vb;
    printf("请输入无向网G的顶点数,边数,边是否含其它信息(是:1,否:0): ");
    scanf("%d,%d,%d",&(*G).vexnum,&(*G).arcnum,&IncInfo);
    printf("请输入%d个顶点的值(<%d个字符):\n",(*G).vexnum,MAX_NAME);
    for(i=0;i<(*G).vexnum;++i) /* 构造顶点向量 */
        scanf("%s",(*G).vexs[i]);
    for(i=0;i<(*G).vexnum;++i) /* 初始化邻接矩阵 */
        for(j=0;j<(*G).vexnum;++j)
        {
            (*G).arcs[i][j].adj=INFINITY; /* 网 */
            (*G).arcs[i][j].info=NULL;
        }
    printf("请输入%d条边的顶点1 顶点2 权值(以空格作为间隔): \n",(*G).arcnum);
    for(k=0;k<(*G).arcnum;++k)
    {
        scanf("%s%s%d%*c",va,vb,&w); /* %*c吃掉回车符 */
        i=LocateVex(*G,va);
        j=LocateVex(*G,vb);
        (*G).arcs[i][j].adj=(*G).arcs[j][i].adj=w; /* 无向 */
        if(IncInfo)
        {
            printf("请输入该边的相关信息(<%d个字符): ",MAX_INFO);
            gets(s);
            w=strlen(s);
            if(w)
            {
                info=(char*)malloc((w+1)*sizeof(char));
                strcpy(info,s);
                (*G).arcs[i][j].info=(*G).arcs[j][i].info=info; /* 无向 */
            }
        }
    }
    (*G).kind=AN;
    return OK;
}

Status CreateGraph(MGraph *G)
{ /* 采用数组(邻接矩阵)表示法,构造图G。算法7.1 */
    printf("Please input G's type(DG:0, DN:1, AG:2, AN:3:"); //请输入图G的类型(有向图:0,有向网:1,无向图:2,无向网:3):
    scanf("%d",&(*G).kind);
    switch((*G).kind)
    {
        case DG: return CreateDG(G); /* 构造有向图 */
        case DN: return CreateDN(G); /* 构造有向网 */
        case AG: return CreateAG(G); /* 构造无向图 */
        case AN: return CreateAN(G); /* 构造无向网 */
        default: return ERROR;
    }
}

void DestroyGraph(MGraph *G)
{ /* 初始条件: 图G存在。操作结果: 销毁图G */
    int i,j;
    if((*G).kind<2) /* 有向 */
        for(i=0;i<(*G).vexnum;i++) /* 释放弧的相关信息(如果有的话) */
        {
            for(j=0;j<(*G).vexnum;j++)
                if((*G).arcs[i][j].adj==1&&(*G).kind==0||(*G).arcs[i][j].adj!=INFINITY&&(*G).kind==1) /* 有向图的弧||有向网的弧 */
                    if((*G).arcs[i][j].info) /* 有相关信息 */
                    {
                        free((*G).arcs[i][j].info);
                        (*G).arcs[i][j].info=NULL;
                    }
        }
    else // 无向
        for(i=0;i<(*G).vexnum;i++) /* 释放边的相关信息(如果有的话) */
            for(j=i+1;j<(*G).vexnum;j++)
                if((*G).arcs[i][j].adj==1&&(*G).kind==2||(*G).arcs[i][j].adj!=INFINITY&&(*G).kind==3) /* 无向图的边||无向网的边 */
                    if((*G).arcs[i][j].info) /* 有相关信息 */
                    {
                        free((*G).arcs[i][j].info);
                        (*G).arcs[i][j].info=(*G).arcs[j][i].info=NULL;
                    }
    (*G).vexnum=0;
    (*G).arcnum=0;
}

VertexType* GetVex(MGraph G,int v)
{ /* 初始条件: 图G存在，v是G中某个顶点的序号。操作结果: 返回v的值 */
    if(v>=G.vexnum||v<0)
        exit(ERROR);
    return &G.vexs[v];
}

Status PutVex(MGraph *G,VertexType v,VertexType value)
{ /* 初始条件: 图G存在，v是G中某个顶点。操作结果: 对v赋新值value */
    int k;
    k=LocateVex(*G,v); /* k为顶点v在图G中的序号 */
    if(k<0)
        return ERROR;
    strcpy((*G).vexs[k],value);
    return OK;
}

int FirstAdjVex(MGraph G,VertexType v)
{ /* 初始条件: 图G存在,v是G中某个顶点 */
    /* 操作结果: 返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点,则返回-1 */
    int i,j=0,k;
    k=LocateVex(G,v); /* k为顶点v在图G中的序号 */
    if(G.kind==DN||G.kind==AN) /* 网 */
        j=INFINITY;
    for(i=0;i<G.vexnum;i++)
        if(G.arcs[k][i].adj!=j)
            return i;
    return -1;
}

int NextAdjVex(MGraph G,VertexType v,VertexType w)
{ /* 初始条件: 图G存在,v是G中某个顶点,w是v的邻接顶点 */
    /* 操作结果: 返回v的(相对于w的)下一个邻接顶点的序号, */
    /*           若w是v的最后一个邻接顶点,则返回-1 */
    int i,j=0,k1,k2;
    k1=LocateVex(G,v); /* k1为顶点v在图G中的序号 */
    k2=LocateVex(G,w); /* k2为顶点w在图G中的序号 */
    if(G.kind==DN||G.kind==AN) /* 网 */
        j=INFINITY;
    for(i=k2+1;i<G.vexnum;i++)
        if(G.arcs[k1][i].adj!=j)
            return i;
    return -1;
}

void InsertVex(MGraph *G,VertexType v)
{ /* 初始条件: 图G存在,v和图G中顶点有相同特征 */
    /* 操作结果: 在图G中增添新顶点v(不增添与顶点相关的弧,留待InsertArc()去做) */
    int i;
    strcpy((*G).vexs[(*G).vexnum],v); /* 构造新顶点向量 */
    for(i=0;i<=(*G).vexnum;i++)
    {
        if((*G).kind%2) /* 网 */
        {
            (*G).arcs[(*G).vexnum][i].adj=INFINITY; /* 初始化该行邻接矩阵的值(无边或弧) */
            (*G).arcs[i][(*G).vexnum].adj=INFINITY; /* 初始化该列邻接矩阵的值(无边或弧) */
        }
        else /* 图 */
        {
            (*G).arcs[(*G).vexnum][i].adj=0; /* 初始化该行邻接矩阵的值(无边或弧) */
            (*G).arcs[i][(*G).vexnum].adj=0; /* 初始化该列邻接矩阵的值(无边或弧) */
        }
        (*G).arcs[(*G).vexnum][i].info=NULL; /* 初始化相关信息指针 */
        (*G).arcs[i][(*G).vexnum].info=NULL;
    }
    (*G).vexnum+=1; /* 图G的顶点数加1 */
}

Status DeleteVex(MGraph *G,VertexType v)
{ /* 初始条件: 图G存在,v是G中某个顶点。操作结果: 删除G中顶点v及其相关的弧 */
    int i,j,k;
    VRType m=0;
    k=LocateVex(*G,v); /* k为待删除顶点v的序号 */
    if(k<0) /* v不是图G的顶点 */
        return ERROR;
    if((*G).kind==DN||(*G).kind==AN) /* 网 */
        m=INFINITY;
    for(j=0;j<(*G).vexnum;j++)
        if((*G).arcs[j][k].adj!=m) /* 有入弧或边 */
        {
            if((*G).arcs[j][k].info) /* 有相关信息 */
                free((*G).arcs[j][k].info); /* 释放相关信息 */
            (*G).arcnum--; /* 修改弧数 */
        }
    if((*G).kind==DG||(*G).kind==DN) /* 有向 */
        for(j=0;j<(*G).vexnum;j++)
            if((*G).arcs[k][j].adj!=m) /* 有出弧 */
            {
                if((*G).arcs[k][j].info) /* 有相关信息 */
                    free((*G).arcs[k][j].info); /* 释放相关信息 */
                (*G).arcnum--; /* 修改弧数 */
            }
    for(j=k+1;j<(*G).vexnum;j++) /* 序号k后面的顶点向量依次前移 */
        strcpy((*G).vexs[j-1],(*G).vexs[j]);
    for(i=0;i<(*G).vexnum;i++)
        for(j=k+1;j<(*G).vexnum;j++)
            (*G).arcs[i][j-1]=(*G).arcs[i][j]; /* 移动待删除顶点之后的矩阵元素 */
    for(i=0;i<(*G).vexnum;i++)
        for(j=k+1;j<(*G).vexnum;j++)
            (*G).arcs[j-1][i]=(*G).arcs[j][i]; /* 移动待删除顶点之下的矩阵元素 */
    (*G).vexnum--; /* 更新图的顶点数 */
    return OK;
}

Status InsertArc(MGraph *G,VertexType v,VertexType w)
{ /* 初始条件: 图G存在,v和W是G中两个顶点 */
    /* 操作结果: 在G中增添弧<v,w>,若G是无向的,则还增添对称弧<w,v> */
    int i,l,v1,w1;
    char *info,s[MAX_INFO];
    v1=LocateVex(*G,v); /* 尾 */
    w1=LocateVex(*G,w); /* 头 */
    if(v1<0||w1<0)
        return ERROR;
    (*G).arcnum++; /* 弧或边数加1 */
    if((*G).kind%2) /* 网 */
    {
        printf("请输入此弧或边的权值: ");
        scanf("%d",&(*G).arcs[v1][w1].adj);
    }
    else /* 图 */
        (*G).arcs[v1][w1].adj=1;
    printf("是否有该弧或边的相关信息(0:无 1:有): ");
    scanf("%d%*c",&i);
    if(i)
    {
        printf("请输入该弧或边的相关信息(<%d个字符)：",MAX_INFO);
        gets(s);
        l=strlen(s);
        if(l)
        {
            info=(char*)malloc((l+1)*sizeof(char));
            strcpy(info,s);
            (*G).arcs[v1][w1].info=info;
        }
    }
    if((*G).kind>1) /* 无向 */
    {
        (*G).arcs[w1][v1].adj=(*G).arcs[v1][w1].adj;
        (*G).arcs[w1][v1].info=(*G).arcs[v1][w1].info; /* 指向同一个相关信息 */
    }
    return OK;
}

Status DeleteArc(MGraph *G,VertexType v,VertexType w)
{ /* 初始条件: 图G存在,v和w是G中两个顶点 */
    /* 操作结果: 在G中删除弧<v,w>,若G是无向的,则还删除对称弧<w,v> */
    int v1,w1;
    v1=LocateVex(*G,v); /* 尾 */
    w1=LocateVex(*G,w); /* 头 */
    if(v1<0||w1<0) /* v1、w1的值不合法 */
        return ERROR;
    if((*G).kind%2==0) /* 图 */
        (*G).arcs[v1][w1].adj=0;
    else /* 网 */
        (*G).arcs[v1][w1].adj=INFINITY;
    if((*G).arcs[v1][w1].info) /* 有其它信息 */
    {
        free((*G).arcs[v1][w1].info);
        (*G).arcs[v1][w1].info=NULL;
    }
    if((*G).kind>=2) /* 无向,删除对称弧<w,v> */
    {
        (*G).arcs[w1][v1].adj=(*G).arcs[v1][w1].adj;
        (*G).arcs[w1][v1].info=NULL;
    }
    (*G).arcnum--;
    return OK;
}

Boolean visited[MAX_VERTEX_NUM]; /* 访问标志数组(全局量) */
Status (*VisitFunc)(VertexType v); /* 函数变量 */
Status Visit(VertexType v)
{
    printf("%s", v);
    return 0;
}

void DFS(MGraph G,int v)
{ /* 从第v个顶点出发递归地深度优先遍历图G。算法7.5 */
    VertexType w1,v1;
    int w;
    VisitFunc= Visit;
    visited[v]=TRUE; /* 设置访问标志为TRUE(已访问) */
    VisitFunc(G.vexs[v]); /* 访问第v个顶点 */
    strcpy(v1,*GetVex(G,v));
    for(w=FirstAdjVex(G,v1);w>=0;w=NextAdjVex(G,v1,strcpy(w1,*GetVex(G,w))))
        if(!visited[w])
            DFS(G,w); /* 对v的尚未访问的序号为w的邻接顶点递归调用DFS */
}

void DFSTraverse(MGraph G,Status(*Visit)(VertexType))
{ /* 初始条件: 图G存在,Visit是顶点的应用函数。算法7.4 */
    /* 操作结果: 从第1个顶点起,深度优先遍历图G,并对每个顶点调用函数Visit */
    /*           一次且仅一次。一旦Visit()失败,则操作失败 */
    int v;
    VisitFunc=Visit; /* 使用全局变量VisitFunc,使DFS不必设函数指针参数 */
    for(v=0;v<G.vexnum;v++)
        visited[v]=FALSE; /* 访问标志数组初始化(未被访问) */
    for(v=0;v<G.vexnum;v++)
        if(!visited[v])
            DFS(G,v); /* 对尚未访问的顶点调用DFS */
    printf("\n");
}

typedef VRType QElemType; /* 队列类型 */
//#include"bo3-2.c" /* BFSTraverse()用 */
//bo3-2.c中的类型定义 放到了c3-2.h 中了
//#include"c3-2.h" /* BFSTraverse()用 */
#include "StackLinkStored.h"
Status GetHead_Q(LinkQueue Q,QElemType *e) /* 避免与bo2-6.c重名 */
{ /* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR */
    QueuePtr p;
    if(Q.front==Q.rear)
        return ERROR;
    p=Q.front->next; // 因为队列是FIFO，所以front指针记录着队列头节点的地址，而队列的第一个元素在头节点之后
    *e=p->data;
    return OK;
}

Status EnQueue(LinkQueue *Q,QElemType e)
{ /* 插入元素e为Q的新的队尾元素 */
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
    if(!p) /* 存储分配失败 */
        exit(OVERFLOW);
    p->data=e;
    p->next=NULL;
    (*Q).rear->next=p;// 将原来的队尾指针指向p，即p插入到队列中
    (*Q).rear=p; // 将队尾指针更新为p
    return OK;
}

Status DeQueue(LinkQueue *Q,QElemType *e)
{ /* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */
    QueuePtr p;
    if((*Q).front==(*Q).rear) //队列为空
        return ERROR;
    p=(*Q).front->next; // 队头元素
    *e=p->data;
    (*Q).front->next=p->next;// 队头元素弹出后，队头指针指向下一个结点
    if((*Q).rear==p) // 若队空
        (*Q).rear=(*Q).front; //特殊情况，特殊对待
    free(p);
    return OK;
}

Status QueueTraverse(LinkQueue Q,void(*vi)(QElemType))
{ /* 从队头到队尾依次对队列Q中每个元素调用函数vi()。一旦vi失败,则操作失败 */
    QueuePtr p;
    p=Q.front->next;
    while(p)
    {
        vi(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}

void vi(QElemType q){
    printf("%d", q);
}
void BFSTraverse(MGraph G,Status(*Visit)(VertexType))
{ /* 初始条件: 图G存在,Visit是顶点的应用函数。算法7.6 */
    /* 操作结果: 从第1个顶点起,按广度优先非递归遍历图G,并对每个顶点调用函数 */
    /*           Visit一次且仅一次。一旦Visit()失败,则操作失败。 */
    /*           使用辅助队列Q和访问标志数组visited */
    int v,u,w;
    VertexType w1,u1;
    LinkQueue Q;
    for(v=0;v<G.vexnum;v++)
        visited[v]=FALSE; /* 置初值 */
    InitQueue(&Q); /* 置空的辅助队列Q */
    for(v=0;v<G.vexnum;v++)
        if(!visited[v]) /* v尚未访问 */
        {
            visited[v]=TRUE; /* 设置访问标志为TRUE(已访问) */
            Visit(G.vexs[v]);
            EnQueue(&Q,v); /* v入队列 */
            while(!QueueEmpty(Q)) /* 队列不空 */
            {
                DeQueue(&Q,&u); /* 队头元素出队并置为u */
                strcpy(u1,*GetVex(G,u));
                for(w=FirstAdjVex(G,u1);w>=0;w=NextAdjVex(G,u1,strcpy(w1,*GetVex(G,w))))
                    if(!visited[w]) /* w为u的尚未访问的邻接顶点的序号 */
                    {
                        visited[w]=TRUE;
                        Visit(G.vexs[w]);
                        EnQueue(&Q,w);
                    }
            }
        }
    printf("\n");
}

void Display(MGraph G)
{ /* 输出邻接矩阵G */
    int i,j;
    char s[7],s1[3];
    switch(G.kind)
    {
        case DG: strcpy(s,"DG\0"); //有向图
            strcpy(s1,"Arc\0");
            break;
        case DN: strcpy(s,"DN\0"); //有向网
            strcpy(s1,"Arc\0");
            break;
        case AG: strcpy(s,"AG\0"); //无向图
            strcpy(s1,"edge\0");
            break;
        case AN: strcpy(s,"AN\0");
            strcpy(s1,"edge\0");
    }
    printf("%dvexnums %d vexnum %s's %s\n",G.vexnum,G.arcnum,s1,s);//%d个顶点%d条%s的%s
    for(i=0;i<G.vexnum;++i) /* 输出G.vexs */
        printf("G.vexs[%d]=%s\n",i,G.vexs[i]);
    printf("G.arcs.adj:\n"); /* 输出G.arcs.adj */
    for(i=0;i<G.vexnum;i++)
    {
        for(j=0;j<G.vexnum;j++)
            printf("%6d",G.arcs[i][j].adj);
        printf("\n");
    }
    printf("G.arcs.info:%s\n", s); /* 输出G.arcs.info */
    printf("vex1(tail) vex2(head) info:%s\n",s1); //顶点1(弧尾) 顶点2(弧头) 该%s信息：
    if(G.kind<2) /* 有向 */
        for(i=0;i<G.vexnum;i++)
            for(j=0;j<G.vexnum;j++)
            {
                if(G.arcs[i][j].info)
                    printf("%5s %11s     %s\n",G.vexs[i],G.vexs[j],G.arcs[i][j].info);
            }
    else /* 无向 */
    {
        for(i=0;i<G.vexnum;i++)
            for(j=i+1;j<G.vexnum;j++)
                if(G.arcs[i][j].info)
                    printf("%5s %11s     %s\n",G.vexs[i],G.vexs[j],G.arcs[i][j].info);
    }
}
#endif //GRAPH_FUNC_H