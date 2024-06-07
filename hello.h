#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
typedef struct rubbish{ // tạo hàm struct để lưu trữ thông tin của đồ uống bị xóa
   char name[50];
    double cost;
    static int number ;
} rubbish;
int rubbish::number =0;
void themrubbish(rubbish & a , namedrink b){// lưu thông tin cảu đồ uống bị xóa vào hàm rubbish
    strcpy(a.name,b.name);
    a.cost= b.cost;
    rubbish::number ++;
}
void xuatrubbish(rubbish a){
    printf("\n %s : %.2lf(dong)",a.name,a.cost);
}