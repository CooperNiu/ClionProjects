#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

int BinarySearch(int a[], const int &x, int n);

int a[100010][6];

struct node{
    int data;
    node *next;
}head[100010];

int main() {
    int n;
    int same;
    bool flag = false;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            scanf("%d", &a[i][j]);
        }

        if(flag)
            continue;

        sort(a[i], a[i]+6);

        int zh = a[i][0] % 100000;
        node *p = (&head[zh])->next;
        node *q = &(head[zh]);

        while(p)
        {
            same = 0;
            for (int j = 0; j < 6; ++j) {
                if(a[p->data][j] == a[i][j])
                    same++;
                else
                    break;
            }

            if(same == 6)
            {
                flag = true;
                break;
            }

            q=p;
            p=p->next;
        }

        if(!p)
        {
            node *r = new node;
            r->data = i;
            r->next = NULL;
            q->next = r;
        }
    }

    if(flag)
        printf("Twin snowflakes found.\n");
    else
        printf("No two snowflakes are alike.\n");

    return 0;
}