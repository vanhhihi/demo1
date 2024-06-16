#include"hello.h"
#include<stdio.h>
//#include<iostream>
#include<vector>
using namespace std;
typedef struct billdrink{
    char name[50];
    double cost;
    int soluong;
}Billdrink;

void bangnamedrink(namedrink a){
    printf("| %18s \t\t|  %7.2lf(dong)  |\n",a.name,a.cost);
}
typedef struct bill{
    static int n;
    int number=0;
    vector<Billdrink>billdrink;
    double tong;
}Bill;
int Bill::n =0;

void xoadong(int number){
    for(int i=1 ; i<= number ; i++){
        cout<<"\033[2K";
        cout<<"\033[A";
    }
    printf("\n");
}
void xuatbill(Bill a){
    system("cls");
    double tong=0;
    printf("---------------------------------------------------------------\n");
    printf("| %3s | %15s         | %10s |   %10s   |\n","STT","TEN DO UONG","SO LUONG","TONG TIEN");
    for(int i = 0 ; i< a.number; i++){
        printf("---------------------------------------------------------------\n");
        printf("| %2d  | %13s           | %6d     |%10.2lf(dong)|\n", i+1,a.billdrink[i].name,a.billdrink[i].soluong,a.billdrink[i].cost*a.billdrink[i].soluong); 
        tong += a.billdrink[i].cost*a.billdrink[i].soluong;    
    }
    printf("---------------------------------------------------------------\n");
    printf("| TONG TIEN | %10.2lf(dong)                                |\n",tong);
    printf("---------------------------------------------------------------\n");

}
