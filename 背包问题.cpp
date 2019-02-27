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
                stack.data[stack.top] = k;//��k����Ʒ������±�
                stack.top++;
                V -= w[k];
            }
            k++;
        }

        if (V == 0) {
            flag=1;
            printf("��%d�����������Ľ⣺", j);
            for (i = 0; i < stack.top; i++) {
                printf("%d ", w[stack.data[i]]);
            }
            j++;
            printf("\n");
        }
        //k��ʱ����
        k = stack.data[--stack.top];
        stack.data[stack.top] = 0;
        V += w[k];
        k++;
    } while (!(stack.top == 0 && k == number));
    if(!flag){
        printf("�����޽⣡\n");
    }
}

void judge(int number,int V,int w[]){
    int i,s = 0;
    for (i = 0; i < number; i++)
        s = s + w[i];
    if(V > s){
        printf("�����޽⣡\n");
        exit(0);
    }
    if(V==s){
        printf("ֻ��һ�����������Ľ⣺%d\n", V);
        exit(0);
    }
}

int main() {
    int w[size];
    int V;
    int i = 0;
    int j = 0;
    int number;
    printf("\t**�򵥱�������**\n\n");
    printf("\n������ɹ�ѡ��װ������ĸ�����\n");
    scanf("%d", &number);
    printf("\n��������������������\n");
    for (i = 0; i < number; i++)
        scanf("%d", &w[i]);

    //����
    for(i=0;i<number;i++)
        for(j=i+1;j<number;j++)
            if(w[i]>w[j]){
                w[i]=w[i]^w[j];
                w[j]=w[i]^w[j];
                w[i]=w[i]^w[j];
            }

    printf("\n�����뱳���ܹ�װ�����������\n");
    scanf("%d", &V);
    judge(number,V,w);

    //��ʼ��ջ
    for (i = 0; i < number; i++)
    stack.data[i] = 0;
    stack.top = 0;

    backpack(number,V,w);
    return 0;
}
.
