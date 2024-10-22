#include <stdio.h>
void myFun(int* variable1,int* variable2);
int main() {
    int a,b;
    a=20;
    b=30;
    int* ptra=&a;
    int* ptrb=&b;
    myFun(ptra,ptrb);
    printf("%d", a);
    printf("%d", b);
    return 0;
}
void myFun(int* ptra,int* ptrb){
    int temp;
    temp=*ptra;
    *ptra=*ptrb;
    *ptrb=temp;



}
