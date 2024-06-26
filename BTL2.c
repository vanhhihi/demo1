#include<stdio.h>
#include<stdlib.h>
#include"vanhc.h"
#include"hungc.h"
//vanh
void TDO(),QLDO(),MENU(),XDO(),TTDO(),LDO();
void BUY(),taobill(),lenbill();
//hung
void QLNV();
void TNV();
void XNV();
void TKNV();
void SXDSNV();
void DSNV();
void STTNV();
void LNV();
void DocFile();
void GhiVaoFile();
// nn: so luong do uong
// bn so luong bill

namedrink *a = NULL;
Bill *bill =NULL;


void xoanamedrink(int k){
  for(int i=k-1;i<nn;i++) a[i] =a[i+1];
  a = realloc(a,(nn-1)*sizeof(namedrink));
}
void ghifile(){
    FILE *f;
    f=fopen("vanh.bin","wb");
    if(f == NULL){
        printf("\nloi mo file");
        return;
    }
    fwrite(&nn,sizeof(nn),1,f);
    for(int i=0 ;i<nn;i++) fwrite(&a[i],sizeof(namedrink),1,f);
    fclose(f);
}
void docfile(){
    FILE *f;
    f=fopen("vanh.bin","rb");
    if(f==NULL){
        printf("\nloi mo file");
        return;
    }
    fread(&nn,sizeof(int),1,f);
    a = realloc(a,nn*sizeof(namedrink));
    for(int i = 0 ;i<nn;i++) fread(&a[i],sizeof(namedrink),1,f);
    fclose(f);
}



void MENU(){
    int k;
    system("cls");
        printf("================QUAN LY HE THONG================");
        printf("\n1. Quan ly do uong ");
        printf("\n2. Mua hang");
        printf("\n3. Quan ly nhan vien ");
      //  printf("\n4. Quan ly bill");
        printf("\n4. Thoat chuong trinh");
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
            default:
                ghifile();  
              break;    
        }
}

void QLDO(){
    int k;
        system("cls");
        printf("================QUAN LY DO UONG================");
        printf("\n1. Them do uong");
        printf("\n2. Xoa do uong ");
        printf("\n3. thong tin cua tat ca do uong");   
        printf("\n4.luu thong tin do uong"); 
        printf("\n5. Quay lai");
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
            case 4:ghifile();
                    QLDO();
                    break;
            case 5:MENU();
                break;
            default : {
                printf("co ve ban chon sai roi");
                QLDO(); 
                break;
            }
        }
}
void TDO(){
    int k;
        system("cls");
        int plus;
        printf("muon them bao nhieu do uong vao : ");
        scanf("%d",&plus);
        fflush(stdin);
        a = realloc(a,(nn+plus)*sizeof(namedrink));
        for(int i=nn;i<nn+plus;i++)
            nhapnamedrink(&a[i]);
        nn+=plus;
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
void TTDO(){
  int k;
        system("cls");
        printf("============================");
        for(int i=0 ; i<nn;i++){ 
        printf("\n");
        printf("%d. ",i+1);   
        xuatdrink(a[i]);
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
void XDO(){
  int k,b;
        char c;
        system("cls");
        printf("============================");
        printf("\n");
        for(int i=0;i<nn;i++){ 
            printf("%d .",i+1);
            xuatdrink(a[i]);
            printf("\n");
        }
        printf("\n============================");
        printf("\nban muon xoa do uong nao : ");
        scanf("%d",&k);
     //   themrubbish(rubbish[rubbish::number],drink[k-1]);
      //  drink.erase(drink.begin()+(k-1));
        xoanamedrink(k);  
        nn--;
        system("cls");
        printf("============================");
      //  printf("\nban da xoa do uong : ");
     //   xuatrubbish(rubbish[rubbish::number-1]);
        printf("\n1. Tiep tuc xoa ");
        printf("\n2. Quay lai ");
        scanf("%d",&b);
        switch(b){
            case 1:
                XDO();
                break;
            case 2:
                QLDO();
                break;
        }
}
void BUY(){
  int pick;
    system("cls");
    printf("------------------------------------------------------------\n");
    printf("| %3s | %25s \t|  %10s   |\n","STT","TEN DO UONG"," GIA DO UONG ");
    for(int i= 0 ; i< nn;i++){
        printf("------------------------------------------------------------\n");
        printf("| %2d  ",i+1);
        bangnamedrink(a[i]);
    }
    printf("------------------------------------------------------------\n");
    printf("1. tao bill");
    printf("\n2. quay lai");
    printf("\nchon muc :  ");
    scanf("%d",&pick);
    switch(pick){
        case 1 : taobill();
                break;
        case 2 : MENU();
                break;
    }
}
void taobill(){
int pick;
        int dem =0;
        int thoat =1 ;
        xoadong(4);
        bill = realloc(bill,(bn+1)*sizeof(Bill));
        for(int i=bn;i<bn+1;i++) bill[bn].number =0;
        bill[bn].billdrink =NULL;
       // bill.resize(bn+1);
       // printf("ban chon do uong nao : \n");
       // printf("chon 0 neu ban ko muon mua :\n");
       // scanf("%d",&pick);
        while(thoat){
            printf("chon 0 neu ban ko muon mua :\n");
            printf("ban chon do uong nao : \n");
            scanf("%d",&pick);
            //fflush(stdin);
            if(pick == 0 ) break;
            xoadong(4);
           // bill[bn].billdrink.resize(bill[bn].number+1);
            bill[bn].billdrink = realloc(bill[bn].billdrink,bill[bn].number+1);
            strcpy( bill[bn].billdrink[bill[bn].number].name , a[pick-1].name);
            bill[bn].billdrink[bill[bn].number].cost = a[pick-1].cost;
            printf("muon mua bao nhieu %s : ", a[pick-1].name);
            scanf("%d",&bill[bn].billdrink[bill[bn].number].soluong);
            bill[bn].tong += a[pick-1].cost * bill[bn].billdrink[bill[bn].number].soluong;
            dem =1;
            bill[bn].number++;
            xoadong(1);
            printf(" mua do uong tiep ko ");
            printf("\n 1 : co ");
            printf("\n 0 : ko ");
            printf("thoat");
            xoadong(4);
        }
  xuatbill(bill[bn]);
    char c ;
    printf("viet chu bat ki de tiep tuc : ");
    scanf("%c",&c);
    getchar();
    while(c){
        system("cls");
        if(dem == 0) {   BUY();
        break;
        }
        if(dem == 1){
            bn ++;
            BUY();
            break;
        }
    }

}
//hung//////////////////////////////////////////////////////////////////////////////////
void QLNV(){
	int k;
    system("cls");
    printf("==============QUAN LY NHAN VIEN==============");
    printf("\n1. Them nhan vien.");
    printf("\n2. Danh sach nhan vien.");
    printf("\n3. Tim kiem nhan vien theo keyword.");
    printf("\n4. Luu du lieu nhan vien.");
    printf("\n5. Quay lai.");
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
           LNV();
           break;
        case(5):
            MENU();
            break;
        default:
            QLNV();
            break;
        }
} 

void TNV(){ 
    int k;
    system("cls");
    Nhapdanhsachnhanvien(ds,t,&n,&tongluong);
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
        default:
            QLNV();
            break;
    }
} 

void XNV(){
	int k;
    printf("Nhap ma cua nhan vien can xoa: ");scanf("%d",&k);
    system("cls");
    XoaNhanVienTheoMa(ds,&n,k,&tongluong);
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
        default:
            DSNV();
            break;
    }
}

void TKNV(){
	int k;
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
        default:
            QLNV();
            break;
        }
}

void DSNV(){
    int k;
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
        default:
            DSNV();
            break;
        }
}

void SXDSNV(){
    int k;
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
        default:
            DSNV();
            break;
        }
    }
    
void STTNV(){
    int k;
   	printf("STT cua nhan vien ban muon sua: ");scanf("%d",&k);
    SuaNhanVien(ds,n,k,&tongluong);
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
        default:
           	DSNV();
            break;
        }
    }
    
void LNV(){
    GhiVaoFile(ds,n,tongluong);
    QLNV();
}

int main(){
    
    DocFile(ds,&n,&tongluong);
    docfile();
  MENU();



}





