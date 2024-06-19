#include<iostream>
//#include"hello.h"
#include<vector>  
#include<fstream>
#include"buy.h"
#include"hung.h"
using namespace std;
class menuchung{
private:
        void QLDO(), TDO(), XDO(),TTDO();
        void BUY(),taobill(),lenbill();
        void TNV(),QLNV(),XNV(),TKNV(),SXDSNV(),DSNV(),STTNV();   
        vector<namedrink> drink;
        vector<Bill> bill;
        int k;
     //   int namedrink::n =0
public:
    void MENU(){
       system("cls");
        printf("================QUAN LY HE THONG================");
        printf("\n1. Quan ly do uong ");
        printf("\n2. Mua hang");
        printf("\n3. Quan ly nhan vien ");
      //  printf("\n4. Quan ly bill");
        printf("\n5. Thoat chuong trinh");
        printf("\n=================================================");
        printf("\n chon muc ");
        scanf("%d",&k);
        switch (k){
            case 1: QLDO(); 
                break;
            case 2: BUY();
                break;
            case 3: QLNV();
                break;
            default: {
                printf(" nhap sai roi ");
                MENU();
            }
                break;
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
        printf("\n3. thong tin cua tat ca do uong");    
        printf("\n4. Quay lai");
        printf("\n==============================================");
        printf("\nchon muc : ");
        scanf("%d",&k);
        fflush(stdin);
        switch(k){
            case 1:TDO();
                break;
            case 2:XDO();
                break;
            case 3:TTDO();
                break; 
            case 4:MENU();
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
      //  printf("\nban da xoa do uong : ");
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
    void menuchung::TTDO(){
        int k;
        system("cls");
        printf("============================");
        for(int i=0 ; i<namedrink::n;i++){ 
        printf("\n");
        printf("%d. ",i+1);   
        xuatdrink(drink[i]);
        printf("\n");
        printf("============================");
        }
        //printf("\n1. chon do uong");
        printf("\n1. them do uong");
        printf("\n2. xoa do uong");
        printf("\n3. quay lai");
        scanf("%d",&k);
        switch(k){
            case 1:TDO();
                    break;
            case 2:XDO();
                    break;
            case 3:QLDO();
                    break;        
        }
    }

void menuchung::BUY(){
    int pick;
    system("cls");
    printf("------------------------------------------------------------\n");
    printf("| %3s | %25s \t|  %10s   |\n","STT","TEN DO UONG"," GIA DO UONG ");
    for(int i= 0 ; i< namedrink::n;i++){
        printf("------------------------------------------------------------\n");
        printf("| %2d  ",i+1);
        bangnamedrink(drink[i]);
    }
    printf("------------------------------------------------------------\n");
    printf("1. tao bill");
    printf("\n2. quay lai");
    printf("\nchon muc :  ");
    cin>>pick;
    switch(pick){
        case 1 : taobill();
                break;
        case 2 : MENU();
                break;
    }

}


void menuchung::taobill(){
        int pick;
        int dem =0;
        int thoat =1 ;
        xoadong(4);
        bill.resize(Bill::n+1);
       // printf("ban chon do uong nao : \n");
       // printf("chon 0 neu ban ko muon mua :\n");
       // scanf("%d",&pick);
        while(thoat){
            printf("chon 0 neu ban ko muon mua :\n");
            printf("ban chon do uong nao : \n");
            scanf("%d",&pick);
            if(pick == 0 ) break;
            xoadong(4);
            bill[Bill::n].billdrink.resize(bill[Bill::n].number+1);
            strcpy( bill[Bill::n].billdrink[bill[Bill::n].number].name , drink[pick-1].name);
            bill[Bill::n].billdrink[bill[Bill::n].number].cost = drink[pick-1].cost;
            printf("muon mua bao nhieu %s : ", drink[pick-1].name);
            cin>>bill[Bill::n].billdrink[bill[Bill::n].number].soluong;
            bill[Bill::n].tong += drink[pick-1].cost * bill[Bill::n].billdrink[bill[Bill::n].number].soluong;
            dem =1;
            bill[Bill::n].number++;
            xoadong(2);
            printf(" mua do uong tiep ko ");
            printf("\n 1 : co ");
            printf("\n 0 : ko ");
            cin>>thoat;
            xoadong(4);
        }
    xuatbill(bill[Bill::n]);
    char c ;
    cout<<"viet chu bat ki de tiep tuc : ";
    cin>>c;
    while(c){
        system("cls");
        if(dem == 0) {   BUY();
        break;
        }
        if(dem == 1){
            Bill::n ++;
            BUY();
            break;
        }
    }


    

}
    void menuchung::QLNV(){
        system("cls");
        printf("==============QUAN LY NHAN VIEN==============");
        printf("\n1. Them nhan vien.");
        printf("\n2. Danh sach nhan vien.");
        printf("\n3. Tim kiem nhan vien theo keyword.");
        printf("\n4. Quay lai.");
        printf("\n=============================================");
        printf("\nChon muc: ");
        scanf("%d",&k);
        fflush(stdin);
        switch (k){
            case(1):
                TNV();
                break;
            case(2):
            	DSNV();
            	break;
            case(3):
                TKNV();
                break;
            case(4):
                MENU();
                break;
        }
    }
    void menuchung::TNV(){ 
        system("cls");
        Nhapdanhsachnhanvien(ds,t,n,tongluong);
        printf("\n============================");
        printf("\n1. Tiep tuc them nhan vien. ");
        printf("\n2. Quay lai.");
        printf("\n============================");
        printf("\nChon muc: ");
        scanf("%d",&k);
        switch(k){
            case(1):
                TNV();
                break;
            case(2):
                QLNV();
                break;
        }
    } 

    void menuchung::XNV(){
    	printf("Nhap ma cua nhan vien can xoa: ");scanf("%d",&k);
    	XoaNhanVienTheoMa(ds,n,k,tongluong);
    	printf("\n===================================");
    	printf("\n------THAO TAC TREN DANH SACH------");
    	printf("\n1. Xoa nhan vien.");
    	printf("\n2. Sap xep danh sach theo thu tu alpha B.");
    	printf("\n3. Sua thong tin nhan vien.");
        printf("\n4. Quay lai.");
        printf("\n===================================");
        printf("\nChon muc: ");
        scanf("%d",&k);
        switch(k){
            case(1):
                XNV();
                break;
            case(2):
                SXDSNV();
                break;
            case(3):
            	STTNV();
                break;
            case(4):
            	QLNV();
            	break;
        }
    }
    void menuchung::TKNV(){
    	char ten[25];
    	system("cls");
    	printf("Nhap keyword trong ten nhan vien can tim: ");fflush(stdin);
    	fgets(ten,sizeof(ten),stdin);
    	xoaXuongDong(ten);
    	timNhanVienTheoTen(ds,n,ten);
    	printf("\n==========================");
    	printf("\n1. Tiep tuc tim kiem.");
        printf("\n2. Quay lai.");
        printf("\n==========================");
        printf("\nChon muc: ");
        scanf("%d",&k);
        switch(k){
            case(1):
                TKNV();
                break;
            case(2):
                QLNV();
                break;
            
        }
    }
    void menuchung::DSNV(){
    	system("cls");
    	XuatDanhSachNhanVien(ds,n,tongluong);
    	printf("\n===================================");
    	printf("\n------THAO TAC TREN DANH SACH------");
    	printf("\n1. Xoa nhan vien.");
    	printf("\n2. Sap xep danh sach theo thu tu alpha B. ");
    	printf("\n3. Sua thong tin nhan vien.");
        printf("\n4. Quay lai.");
        printf("\n===================================");
        printf("\nChon muc: ");
        scanf("%d",&k);
        switch(k){
            case(1):
                XNV();
                break;
            case(2):
            	SXDSNV();
            	break;
            case(3):
            	STTNV();
            	break;
            case(4):
                QLNV();
                break;
        }
    }

    void menuchung::SXDSNV(){
    	system("cls");
    	sapXepDanhSachNhanVienTheoTen(ds,n);
    	printf("\n===================================");
    	printf("\n------THAO TAC TREN DANH SACH------");
    	printf("\n1. Xoa nhan vien.");
    	printf("\n2. Sua thong tin nhan vien.");
        printf("\n3. Quay lai.");
        printf("\n===================================");
        printf("\nChon muc: ");
        scanf("%d",&k);
        switch(k){
            case(1):
                XNV();
                break;
            case(2):
                STTNV();
                break;
            case(3):
                QLNV();
                break;
        }
    }
    void menuchung::STTNV(){
    	printf("STT cua nhan vien ban muon sua: ");scanf("%d",&k);
    	SuaNhanVien(ds,n,k,tongluong);
    	system("cls");
    	XuatDanhSachNhanVien(ds,n,tongluong);
    	printf("\n===================================");
    	printf("\n------THAO TAC TREN DANH SACH------");
    	printf("\n1. Xoa nhan vien.");
    	printf("\n2. Sap xep danh sach theo thu tu alpha B. ");
    	printf("\n3. Sua thong tin nhan vien.");
        printf("\n4. Quay lai.");
        printf("\n===================================");
        printf("\nChon muc: ");
        scanf("%d",&k);
        switch(k){
            case(1):
                XNV();
                break;
            case(2):
            	SXDSNV();
            	break;
            case(3):
            	STTNV();
            	break;
            case(4):
                QLNV();
                break;
        }
    }





int main(){
    int login =1 ;
    while(login<=3){
    system("cls");
    string c, d;
    string a = "admin";
    string b = "admin";
    printf("|------------------------------------------|\n");
    printf("| TAI KHOAN |                              |\n");
    printf("|------------------------------------------|\n");
    printf("| MAT KHAU  |                              |\n");
    printf("|------------------------------------------|");
    cout<<"\033[2;14H";
    cin>>c;
    cout<<"\033[4;14H";
    cin>>d;
    cout<<endl;



    if(c == a && d == a){
        printf("OK");
        break;
    }
    
    if(login == 3) printf("tai khoan mat khau sai roi");
    login++;
    }
    menuchung m1;
    m1.MENU();
}