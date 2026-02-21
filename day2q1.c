#include<stdio.h>
int main(){
    int a[50], size, pos, i;
    printf("enter the size of array: ");
    scanf("%d", &size);
    printf("enter the elements of an array: ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("from which position you want to delete: ");
    scanf("%d", &pos);
    if(pos<=0 || pos>size)
    {
        printf("invalid position");
    }
    else
    {
        for(i=pos-1; i<size-1; i++)
        a[i]=a[i+1];
    }
    size--;
    printf("array after deletion:\n");
    for(i=0; i<size; i++)
    {
        printf("%d", a[i]);
    }
}