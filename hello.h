#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<iostream>
//#include"BTL2.cpp"
//using namespace std;
typedef struct namedrink{ // tạo hàm struct để lưu trữ thông tin cảu đồ uống
   char name[50];
    double cost;
    static int n ;
} namedrink;
int namedrink::n = 0;
void xuatdrink(namedrink a){ // xuất tên đồ uống
    printf("do uong %s (%.2lf dong) ",a.name,a.cost);
}
void nhapnamedrink(namedrink *k){ // nhập thông tin đồ uống vào
   // namedrink::n++;
    printf("ten do uong : ");
    fgets(k->name,sizeof(k->name),stdin);
    fflush(stdin);
    k->name[strcspn(k->name,"\n")]=0;
    printf("gia cua do uong : ");
    scanf("%lf",&k->cost);
    fflush(stdin);
}


