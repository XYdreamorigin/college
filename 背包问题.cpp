 #include <stdio.h>
#include <windows.h>
#define size 50
struct stacks {
    int data[size];
    int top;
} stack;

void backpack(int number,int V,int w[]){
    int i,j=1,k=0;
    int flag=0;
    do {
        while (V > 0 && k <= number) {
            if (V >= w[k]) {
                stack.data[stack.top] = k;//第k个物品的体积下标
                stack.top++;
                V -= w[k];
            }
            k++;
        }

        if (V == 0) {
            flag=1;
            printf("第%d个符合条件的解：", j);
            for (i = 0; i < stack.top; i++) {
                printf("%d ", w[stack.data[i]]);
            }
            j++;
            printf("\n");
        }
        //k满时回溯
        k = stack.data[--stack.top];
        stack.data[stack.top] = 0;
        V += w[k];
        k++;
    } while (!(stack.top == 0 && k == number));
    if(!flag){
        printf("背包无解！\n");
    }
}

void judge(int number,int V,int w[]){
    int i,s = 0;
    for (i = 0; i < number; i++)
        s = s + w[i];
    if(V > s){
        printf("背包无解！\n");
        exit(0);
    }
    if(V==s){
        printf("只有一个符合条件的解：%d\n", V);
        exit(0);
    }
}

int main() {
    int w[size];
    int V;
    int i = 0;
    int j = 0;
    int number;
    printf("\t**简单背包问题**\n\n");
    printf("\n请输入可供选择装入物件的个数：\n");
    scanf("%d", &number);
    printf("\n请输入各件物件的重量：\n");
    for (i = 0; i < number; i++)
        scanf("%d", &w[i]);

    //排序
    for(i=0;i<number;i++)
        for(j=i+1;j<number;j++)
            if(w[i]>w[j]){
                w[i]=w[i]^w[j];
                w[j]=w[i]^w[j];
                w[i]=w[i]^w[j];
            }

    printf("\n请输入背包能够装入的总重量：\n");
    scanf("%d", &V);
    judge(number,V,w);

    //初始化栈
    for (i = 0; i < number; i++)
    stack.data[i] = 0;
    stack.top = 0;

    backpack(number,V,w);
    return 0;
}
.
