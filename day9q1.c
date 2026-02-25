#include <stdio.h>
void mirror(char str[], int index) {
    if (str[index] == '\0') 
        return;
    mirror(str, index + 1);   
    printf("%c", str[index]); 
}
int main() {
    char str[1000];
    scanf("%s", str);
    mirror(str, 0);
    return 0;
}