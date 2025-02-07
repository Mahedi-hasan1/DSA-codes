#include <stdio.h>

void display(char *string){
    printf("%s", string);
}

int main(){
    char string[] = "hello world";
    display(string);
}