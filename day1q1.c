#include<stdio.h>
int main(){
    int pos, size, i, num, a[50];
    printf("enter size of an array: ");
    scanf("%d", &size);
    printf("enter te elements of an array: ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the number you want to insert: ");
    scanf("%d", &num);
    printf("enter the position: ");
    scanf("%d", &pos);
    for(i=size-1; i>=pos-1; i--)
    {
        a[i+1]=a[i];
    }
    a[pos-1]=num;
    size++;
    printf("array after insertion: ");
    for(i=0; i<size; i++)
    {
        printf("%d", a[i]);
    }

}