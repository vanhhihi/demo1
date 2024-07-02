#include<stdio.h>
#include<stdlib.h>
#include<string.h>
static int nn = 0;
typedef struct namedrink{
    char name[50];
    double cost;
    int number; 
}namedrink;
void xuatdrink(namedrink a){
    printf("do uong %s (%.2lf dong) ",a.name,a.cost);
}
void xoadong(int number){
    for(int i=1 ; i<= number ; i++){
        printf("\033[2K");
        printf("\033[A");
    }
    printf("\n");
}
void xoadongn(char c[]){
  size_t len = strlen(c);
  if(c[len-1]=='\n') c[len-1]='\0';
}
void nhapnamedrink(namedrink *a){
    printf("nhap ten do uong : ");
    fgets(a->name,sizeof(a->name),stdin);
    //fflush(stdin);
    //getchar();
    xoadongn(a->name);
    printf("gia cua do uong : ");
    scanf("%lf",&a->cost);
    fflush(stdin);
}




typedef struct billdrink{
    char name[50];
    double cost;
    int soluong;
}Billdrink;

void bangnamedrink(namedrink a){
    printf("| %18s \t\t|  %7.2lf(dong)   |\n",a.name,a.cost);
}
typedef struct bill{
    int number;
    Billdrink *billdrink ;
    double tong;
}Bill;
static int bn =0;
void xuatbill(Bill b){
    system("cls");
    double tong=0;
    printf("---------------------------------------------------------------\n");
    printf("| %3s | %15s         | %10s |   %10s   |\n","STT","TEN DO UONG","SO LUONG","TONG TIEN");
    for(int i = 0 ; i< b.number; i++){
        printf("---------------------------------------------------------------\n");
        printf("| %2d  | %13s           | %6d     |%10.2lf(dong)|\n", i+1,b.billdrink[i].name,b.billdrink[i].soluong,b.billdrink[i].cost*b.billdrink[i].soluong); 
        tong += b.billdrink[i].cost*b.billdrink[i].soluong;    
    }
    printf("---------------------------------------------------------------\n");
    printf("| TONG TIEN | %10.2lf(dong)                                |\n",tong);
    printf("---------------------------------------------------------------\n");
    b.tong=tong;
}

