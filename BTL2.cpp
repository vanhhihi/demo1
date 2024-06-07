#include<iostream>
#include"hello.h"
#include<vector>  
using namespace std;
class menuchung{
private:
        void TDO(), XDO();
        void QLDO();
       vector<namedrink> drink;
       vector<rubbish> rubbish;
        int k;
public:
    void MENU(){
       system("cls");
        printf("================QUAN LY HE THONG================");
        printf("\n1. Quan ly do uong ");
       // printf("\n2. Quan ly khach hang");
      //  printf("\n3. Quan ly nhan vien ");
      //  printf("\n4. Quan ly bill");
        printf("\n5. Thoat chuong trinh");
        printf("\n=================================================");
        printf("\n chon muc ");
        scanf("%d",&k);
        switch (k){
            case 1: QLDO(); 
                break;
 /*           case 2: QLKH();
                break;
            case 3: QLNV();
                break;
            case 4: QLB();
                break;
            default: {
                printf(" nhap sai roi ");
                MENU();
            }
                break;*/
            case 5: break;    
        }
    }
};
    void menuchung::QLDO(){
        int k;
        system("cls");
        printf("================QUAN LY DO UONG================");
        printf("\n1. Them do uong");
        printf("\n2. Xoa do uong ");    
        printf("\n3. Quay lai");
        printf("\n==============================================");
        printf("\nchon muc : ");
        scanf("%d",&k);
        fflush(stdin);
        switch(k){
            case 1:TDO();
                break;
            case 2:XDO();
                break;
            case 3:MENU();
                break;
        }
    }
    void menuchung::TDO(){
        int k;
        system("cls");
        int plus;
        printf("muon them bao nhieu do uong vao : ");
        scanf("%d",&plus);
        fflush(stdin);
        drink.resize(namedrink::n+plus);
        for(int i=namedrink::n;i<namedrink::n+plus;i++)
            nhapnamedrink(&drink[i]);
        namedrink::n+=plus;
        printf("\n============================");
        printf("\n1. tiep tuc them do uong ");
        printf("\n2. quay lai");
        printf("\n============================");
        printf("\n");
        scanf("%d",&k);
        switch(k){
            case(1):
                TDO();
                break;
            case(2):
                QLDO();
                break;    
        }
    }
    void menuchung::XDO(){
        int k,a;
        char c;
        system("cls");
        printf("============================");
        printf("\n");
        for(int i=0;i<namedrink::n;i++){ 
            printf("%d .",i+1);
            xuatdrink(drink[i]);
            printf("\n");
        }
        printf("\n============================");
        printf("\nban muon xoa do uong nao : ");
        scanf("%d",&k);
     //   themrubbish(rubbish[rubbish::number],drink[k-1]);
        drink.erase(drink.begin()+(k-1));
        namedrink::n--;
        system("cls");
        printf("============================");
        printf("\nban da xoa do uong : ");
     //   xuatrubbish(rubbish[rubbish::number-1]);
        printf("\n1. Tiep tuc xoa ");
        printf("\n2. Quay lai ");
        scanf("%d",&a);
        switch(a){
            case 1:
                XDO();
                break;
            case 2:
                QLDO();
                break;
        }


    }
int main(){
    menuchung m1;
    m1.MENU();

}