#include "BiTNode.h"
/// 2016-11-16 22:31:47 于教室 为了自己的未来学习，加油，坚持！！！
/// * main6-2.c 检验bo6-2.c的主程序,利用条件编译选择数据类型(另一种方法) */
/// 第二次修改 2016-11-17 14:17:48 图书馆三楼 轻音乐
/// 第三次修改 2016-11-18 21:48:42 已经没有编译错误了 开始执行
/// 执行结果:
/// 第一次:
/*  In file included from C:\Users\Cooper\ClionProjects\BiTNode\BiTNode.h:149:0,
                 from C:\Users\Cooper\ClionProjects\BiTNode\main.cpp:1:
C:\Users\Cooper\ClionProjects\BiTNode\Queue.h: In function 'Status InitQueue(LinkQueue&)':
C:\Users\Cooper\ClionProjects\BiTNode\Queue.h:26:50: error: invalid cast of an rvalue expression of type 'void*' to type 'QueuePtr {aka QNode&}'
     Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));  */
///错误原因: 在Ctrl+R替换&Q时候把数据结构定义错了
///改正方法: 重新定义结构体的指针类型
/// 第二次:
/*
 * error: expected primary-expression before ')' token
 */
///错误原因:
///改正方法: 2016-11-18 22:14:33
/* 2016-11-18 22:14:40 还未找到解决办法 加油 */
///第四次修改 2016-11-19 09:45:56
/* expected primary-expression before ')' token
   S.base=(SElemType *)malloc(STACK_INIT_SIZE&Sizeof(SElemType));
 */
///错误原因: 还是替换时候出现的错误, 把*sizeof 变成了 &Sizeof
///改正方法: &S -> *s
/*
 * call of overloaded 'PreOrderTraverse(BiTNode*&, Status (*&)(TElemType))' is ambiguous
 */
///错误原因:
///改正方法:
/*
 * error: redefinition of 'struct SqStack'
 */
///错误原因:
///改正方法:
///第五次修改 2016-11-24 14:47:21 于图书馆四楼
// 错误: 从记事本文件中打开的代码复制粘贴进入CLion时候就会在运行程序时候出现乱码, 而且自己输入的汉字在显示时候也是乱码
// 改正方法: 暂无
// 改善方法: 将汉字全部翻译成英文
int main() {
    int i;
    BiTree T,p,c;
    TElemType e1,e2;
    InitBiTree(T);
    printf("After init BiTree, is it empty?%d(1:Y 0:N) \nDepth of Root:%d\n",BiTreeEmpty(T),BiTreeDepth(T));
    e1=Root(T);
    if(e1!=Nil)
#ifdef CHAR
    printf("Root is %c\n",e1);
#endif
#ifdef INT
    printf("Root is %d\n",e1);
#endif
    else
    printf("BiTree Empty, No Root\n");
#ifdef CHAR
    printf("Input BiTree at PreOrder (e.g.: ab with 3 space means a is root, b is BiTree's left subtree)\n");
#endif
#ifdef INT
    printf("Input BiTree at PreOrder (e.g.: 1 2 0 0 0 means 1 is root, 2 is BiTree's left subtree)\n");
    //请先序输入二叉树(如:1 2 0 0 0表示1为根结点,2为左子树的二叉树)
#endif
    CreateBiTree(T);
    printf("After init BiTree, is it empty?%d(1:Y 0:N) Depth of Root:%d\n",BiTreeEmpty(T),BiTreeDepth(T));
    e1=Root(T);
    if(e1!=Nil)
#ifdef CHAR
        printf("Root is : %c\n",e1);
#endif
#ifdef INT
        printf("Root is :%d\n",e1);
#endif
    else
        printf("BiTree Empty, No Root\n");
    printf("InOrder Traverse BiTree(Recursive);\n");
    InOrderTraverse(T,Visit);
    printf("\nInOrder Traverse BiTree-1(Non-Recursive);\n");
    InOrderTraverse1(T,Visit);
    printf("InOrder Traverse BiTree-2(Non-Recursive);\n");
    InOrderTraverse2(T,Visit);
    printf("PostOrder Traverse BiTree;\n");
    PostOrderTraverse(T,Visit);
    printf("\nLevelOrder Traverse BiTree;\n");
    LevelOrderTraverse(T,Visit);
    printf("Please input a node: ");
#ifdef CHAR
    scanf("%*c%c",&e1);
#endif
#ifdef INT
    scanf("%d",&e1);
#endif
    p=Point(T,e1); /* p为e1的指针 */
#ifdef CHAR
    printf("Node's data is %c\n",Value(p));
#endif
#ifdef INT
    printf("Node's data is %d\n",Value(p));
#endif
    printf("if you want to change the data, please input the new data: ");
#ifdef CHAR
    scanf("%*c%c%*c",&e2);
#endif
#ifdef INT
    scanf("%d",&e2);
#endif
    Assign(p,e2);
    printf("LevelOrder Traverse BiTree;\n");
    LevelOrderTraverse(T,Visit);
    e1=Parent(T,e2);
    if(e1!=Nil)
#ifdef CHAR
        printf("%c's parent is %c\n",e2,e1);
#endif
#ifdef INT
        printf("%d's parent is %d\n",e2,e1);
#endif
    else
#ifdef CHAR
        printf("%c has no parent\n",e2);
#endif
#ifdef INT
    printf("%d has no parent\n",e2);
#endif
    e1=LeftChild(T,e2);
    if(e1!=Nil)
#ifdef CHAR
        printf("%c's left child is %c\n",e2,e1);
#endif
#ifdef INT
        printf("%d's left child is %d\n",e2,e1);
#endif
    else
#ifdef CHAR
        printf("%c has no left child\n",e2);
#endif
#ifdef INT
    printf("%d has no left child\n",e2);
#endif
    e1=RightChild(T,e2);
    if(e1!=Nil)
#ifdef CHAR
        printf("%c's right child is %c\n",e2,e1);
#endif
#ifdef INT
        printf("%d's right child is %d\n",e2,e1);
#endif
    else
#ifdef CHAR
        printf("%c's right child is \n",e2);
#endif
#ifdef INT
    printf("%d has no right child\n",e2);
#endif
    e1=LeftSibling(T,e2);
    if(e1!=Nil)
#ifdef CHAR
        printf("%c's left sibling is %c\n",e2,e1);
#endif
#ifdef INT
        printf("%d's left sibling is %d\n",e2,e1);
#endif
    else
#ifdef CHAR
        printf("%c has no left sibling \n",e2);
#endif
#ifdef INT
    printf("%d has no left sibling \n",e2);
#endif
    e1=RightSibling(T,e2);
    if(e1!=Nil)
#ifdef CHAR
        printf("%c's right sibling is %c\n",e2,e1);
#endif
#ifdef INT
        printf("%d's right sibling is %d\n",e2,e1);
#endif
    else
#ifdef CHAR
        printf("%c has no right sibling \n",e2);
#endif
#ifdef INT
    printf("%d has no right sibling \n",e2);
#endif
    InitBiTree(c);
    printf("Init a BiTree with empty right subtree c:\n");
#ifdef CHAR
    printf("Input BiTree at PreOrder (e.g.: ab with 3 space means a is root, b is BiTree's left subtree)\n");
    //请先序输入二叉树(如:ab三个空格表示a为根结点,b为左子树的二叉树)
#endif
#ifdef INT
    printf("Input BiTree at PreOrder (e.g.: 1 2 0 0 0 means 1 is root, 2 is BiTree's left subtree)\n");
#endif
    CreateBiTree(c);
    printf("PreOrder Traverse BiTree(Recursive) c:\n");
    PreOrderTraverse(c,Visit);
    printf("Insert c into T, please input c'parent in T (c is left subtree(0) or right subtree(1)\n");
    //树c插到树T中,请输入树T中树c的双亲结点 c为左(0)或右(1)子树:
#ifdef CHAR
    scanf("%*c%c%d",&e1,&i);
#endif
#ifdef INT
    scanf("%d%d",&e1,&i);
#endif
    p=Point(T,e1); /* p是T中树c的双亲结点指针 */
    InsertChild(p,i,c);
    printf("PreOrder Traverse BiTree(Recursive):\n");
    PreOrderTraverse(T,Visit);
    printf("Delete subtree, input the \n");
    //删除子树,请输入待删除子树的双亲结点  左(0)或右(1)子树:
#ifdef CHAR
    scanf("%*c%c%d",&e1,&i);
#endif
#ifdef INT
    scanf("%d%d",&e1,&i);
#endif
    p=Point(T,e1);
    DeleteChild(p,i);
    printf("PreOrder Traverse BiTree(Recursive):\n");
    PreOrderTraverse(T,Visit);
    printf("\n");
    DestroyBiTree(T);
    return 0;
}
