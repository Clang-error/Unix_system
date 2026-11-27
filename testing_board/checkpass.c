//
// Created by Clang on 26. 9. 6..
//

#include <stdio.h>
#include <string.h>

int checkpass(void) {
    //
    int x;
    char a[9];
    // strcpy(a,"mypass");
    x=0;
    //stderr 형식으로 a와 x의 주소를 출력
    fprintf(stderr,"a at %p and\nx at %p\n",(void *)a,(void *)&x);
    printf("%s",a);
    if (strcmp(a,"mypass")==0)
        x = 1;
    return x;
}
`
int main(void) {
    int result = checkpass();
    // printf("%d",result);

}
