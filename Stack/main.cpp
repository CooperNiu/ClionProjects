/* main.cpp 调用函数 实现相关的功能 */

#include "header.h" // 该头文件中包含constant.h
#define N 20

Status visit(ElemType c)
{
    printf("%d ", c);
    return  OK;
}

//int  main(void )
//{
//    int j;
//    SqStack s;
//    ElemType e;
//    if(InitStack(&s))
//    {
//        for(j=1; j<=N; j++)
//        {
//            Push(&s, j);
//        }
//    }
//    printf("Output stack elements:");
//    StackTraverse(s,visit);
//    Pop(&s,&e);
//    printf("Pop element e=%d\n",e);
//    printf("Is stack empty:%d(1:Y 0:N)\n",StackEmpty(s));
//    GetTop(s,&e);
//    printf("Top element:e=%d Stack length:%d\n",e,StackLength(s));
//    ClearStack(&s);
//    printf("After destroying stack, is stack empty:%d(1:Y 0:N )\n",StackEmpty(s));
//    DestroyStack(&s);
//    printf("After destroying stack, s.top=%u s.base=%u s.stacksize=%d\n",s.top,s.base, s.stacksize);
//}

int main(void)
{// 逆波兰表达式
    SqStack s;
    char c;
    ElemType d, e;
    int i=0;
    char str[10]; //字符缓冲区
    InitStack(&s);

    printf("请按后缀(逆波兰)表达式输入待计算数据, 数据与运算符用空格隔开, 以#结束:\n");
    scanf("%c", &c);//字符转换为整数

    while(c!='#')
    {
        while(isdigit(c) || c=='.')//判断是否为数字
        {
            str[i++] = c;
            str[i]='\0';
            if(i>=10){
                printf("出错,输入的单个数据过大!\n");
                return -1;
            }
            scanf("%c", &c);
            if(c==' ')
            {
                d=atof(str); //字符串转换为浮点数
                Push(&s, d);
                i=0;
                break; //数字输入已经结束, 跳出while循环
            }
        }
        switch (c)
        {
            case '+':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, d+e);
                break;
            case '-':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, d-e);
                break;
            case '*':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, d*e);
                break;
            case '/':
                Pop(&s, &e);
                Pop(&s, &d);
                if(e!=0){
                    Push(&s, d/e);
                }
                else{
                    printf("\n出错, 除数为零!\n");
                    return -1;
                }
                break;
        }

        scanf("%c", &c);
    }
    Pop(&s, &d);
    printf("\n最终的计算结果是: %f\n", d);

    return 0;
}