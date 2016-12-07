#include "HuffmanTree.h"
char ch[10000];
int main() {
    HuffmanTree HT;
    HuffmanCode HC;
    int *w,n,i;
    FILE *fp;
    char string[10]="00000";
    fp = fopen("C:\\Users\\Cooper\\ClionProjects\\DataStructure\\article.txt", "w+");
    printf("%d", fp);
//    if(!fp)
//        return ERROR;
    if (fputs(string, fp))
        printf("OK");
    while(fgets(ch, 10000, fp) != NULL){
//        for (int j = 0; j < 10000; ++j) {
//            printf("%c", ch[i]);
//        }
        puts(ch);
    }
//    for(;;){
//        printf("Please input the number of weight(>1), input 0 to exit:");// 请输入权值的个数(>1)：
//        scanf("%d",&n);
//        if(!n) exit(1);
//        w=(int *)malloc(n*sizeof(int));
//        printf("Please input %d weights(int):\n",n); // 请依次输入%d个权值(整型)：
//        for(i=0;i<=n-1;i++){
//            scanf("%d",w+i);
////        printf("%d", w[i]);
//        }
//        HuffmanCoding(&HT, &HC,w,n);
//        for(i=1;i<=n;i++)
//            puts(HC[i]);
//    }

    return 0;
}