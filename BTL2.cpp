#include<iostream>
#include<unistd.h>
#include<vector>  
#include<fstream>
#include"buy.h"
#include"hung.h"
using namespace std;
class menuchung{
private:
        void QLDO(), TDO(), XDO(),TTDO(),ghifile(),docfile();
        void BUY(),taobill(),lenbill();
        void TNV(),QLNV(),XNV(),TKNV(),SXDSNV(),DSNV(),STTNV(),LNV();   
        vector<namedrink> drink;
        vector<Bill> bill;
        int k;
     //   int namedrink::n =0
public:
    void doc(){
        docfile();
    }
    void MENU(){
       system("cls");
        cout<<"================QUAN LY HE THONG================";
        cout<<"\n1. Quan ly do uong ";
        cout<<"\n2. Mua hang";
        cout<<"\n3. Quan ly nhan vien ";
        cout<<"\n4. Luu thong tin do uong";
        cout<<"\n5. Luu thong tin nhan vien";
        cout<<"\n6. Thoat chuong trinh";
        cout<<"\n=================================================";
        cout<<"\n chon muc ";
        cin>>k;
        switch (k){
            case 1: 
            QLDO();         
                break;
            case 2: 
            BUY();
            
                break;
            case 3:
             QLNV();
                break;
            case 4:
                ghifile();
                
                MENU();
                break;
            case 5:
                GhiVaoFile(ds,n,tongluong);
                
                MENU();
                break;
            default : break;
                    
        }
    }
};
    void menuchung::QLDO(){
        int k;
        system("cls");
        cout<<"================QUAN LY DO UONG================";
        cout<<"\n1. Them do uong";
        cout<<"\n2. Xoa do uong ";
        cout<<"\n3. thong tin cua tat ca do uong";    
        cout<<"\n4. Quay lai";
        cout<<"\n==============================================";
        cout<<"\nchon muc : ";
        cin>>k;
        fflush(stdin);
        switch(k){
            case 1:
                TDO();
                break;
            case 2:
                XDO();
                break;
            case 3:
                TTDO();
                break; 
            case 4:
                MENU();
                break;
            default : {
                cout<<("co ve ban chon sai roi");
                sleep(1);
                QLDO();
                break;
            }
        }
    }
    void menuchung::TDO(){
        int k;
        system("cls");
        int plus;
        cout<<"muon them bao nhieu do uong vao : ";
        cin>>plus;
        fflush(stdin);
        drink.resize(namedrink::n+plus);
        for(int i=namedrink::n;i<namedrink::n+plus;i++)
            nhapnamedrink(&drink[i]);
        namedrink::n+=plus;
        cout<<"\n============================";
        cout<<"\n1. tiep tuc them do uong ";
        cout<<"\n2. quay lai";
        cout<<"\n============================";
        cout<<"\n";
        cin>>k;
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
        cout<<"============================";
        cout<<"\n";
        for(int i=0;i<namedrink::n;i++){ 
            cout<<("%d .",i+1);
            xuatdrink(drink[i]);
            cout<<"\n";
        }
        cout<<"\n============================";
        cout<<"\nban muon xoa do uong nao : ";
        cin>>k;
     //   themrubbish(rubbish[rubbish::number],drink[k-1]);
        drink.erase(drink.begin()+(k-1));
        namedrink::n--;
        system("cls");
        cout<<"============================";
      //  cout<<("\nban da xoa do uong : ");
     //   xuatrubbish(rubbish[rubbish::number-1]);
        cout<<"\n1. Tiep tuc xoa ";
        cout<<"\n2. Quay lai ";
        cin>>a;
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
        cout<<"============================";
        for(int i=0 ; i<namedrink::n;i++){ 
        cout<<"\n";
        cout<<i+1;   
        xuatdrink(drink[i]);
        cout<<"\n";
        cout<<"============================";
        }
        //cout<<("\n1. chon do uong");
        cout<<"\n1. them do uong";
        cout<<"\n2. xoa do uong";
        cout<<"\n3. quay lai";
        cin>>k;
        switch(k){
            case 1:
                TDO();
                    break;
            case 2:
                XDO();
                    break;
            case 3:
                QLDO();
                    break;        
        }
    }

void menuchung::BUY(){
    int pick;
    system("cls");
    cout<<"------------------------------------------------------------\n";
    cout<<"STT","TEN DO UONG"," GIA DO UONG ";
    for(int i= 0 ; i< namedrink::n;i++){
        cout<<"------------------------------------------------------------\n";
        cout<<i+1;
        bangnamedrink(drink[i]);
    }
    cout<<"------------------------------------------------------------\n";
    cout<<"1. tao bill";
    cout<<"\n2. quay lai";
    cout<<"\nchon muc :  ";
    cin>>pick;
    switch(pick){
        case 1 : 
            taobill();
                break;
        case 2 :
             MENU();
                break;
    }

}


/// @brief 
void menuchung::taobill(){
        int pick;
        int dem =0;
        int thoat =1 ;
        xoadong(4);
        bill.resize(Bill::n+1);
       // cout<<("ban chon do uong nao : \n");
       // cout<<("chon 0 neu ban ko muon mua :\n");
       // cin>>("%d",&pick);
        while(thoat){
            cout<<"chon 0 neu ban ko muon mua :\n";
            cout<<"ban chon do uong nao : \n";
            cin>>pick;
            if(pick == 0 ) break;
            xoadong(4);
            bill[Bill::n].billdrink.resize(bill[Bill::n].number+1);
            strcpy( bill[Bill::n].billdrink[bill[Bill::n].number].name , drink[pick-1].name);
            bill[Bill::n].billdrink[bill[Bill::n].number].cost = drink[pick-1].cost;
            cout<<("muon mua bao nhieu %s : ", drink[pick-1].name);
            cin>>bill[Bill::n].billdrink[bill[Bill::n].number].soluong;
            bill[Bill::n].tong += drink[pick-1].cost * bill[Bill::n].billdrink[bill[Bill::n].number].soluong;
            dem =1;
            bill[Bill::n].number++;
            xoadong(2);
            cout<<" mua do uong tiep ko ";
            cout<<"\n 1 : co ";
            cout<<"\n 0 : ko ";
            cin>>thoat;
            xoadong(4);
        }
    xuatbill(bill[Bill::n]);
    char c ;
    cout<<"viet chu bat ki de tiep tuc : ";
    cin>>c;
    getchar();
    while(c){
        system("cls");
        if(dem == 0) {   BUY();
        break;
        }
        if(dem == 1){
            ++Bill::n ;
            BUY();
            break;
        }
    }


    

}
    void menuchung::QLNV(){
        system("cls");
        cout<<"==============QUAN LY NHAN VIEN==============";
        cout<<"\n1. Them nhan vien.";
        cout<<"\n2. Danh sach nhan vien.";
        cout<<"\n3. Tim kiem nhan vien theo keyword.";
        cout<<"\n4. Luu du lieu nhan vien.";
        cout<<"\n5. Quay lai.";
        cout<<"\n=============================================";
        cout<<"\nChon muc: ";
        cin>>k;
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
        }
    }
    void menuchung::TNV(){ 
        system("cls");
        Nhapdanhsachnhanvien(ds,t,n,tongluong);
        cout<<"\n============================";
        cout<<"\n1. Tiep tuc them nhan vien. ";
        cout<<"\n2. Quay lai.";
        cout<<"\n============================";
        cout<<"\nChon muc: ";
        cin>>k;
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
    	cout<<"Nhap ma cua nhan vien can xoa: ";
        cin>>k;
        system("cls");
    	XoaNhanVienTheoMa(ds,n,k,tongluong);
    	cout<<"\n===================================";
    	cout<<"\n------THAO TAC TREN DANH SACH------";
    	cout<<"\n1. Xoa nhan vien.";
    	cout<<"\n2. Sap xep danh sach theo thu tu alpha B.";
    	cout<<"\n3. Sua thong tin nhan vien.";
        cout<<"\n4. Quay lai.";
        cout<<"\n===================================";
        cout<<"\nChon muc: ";
        cin>>k;
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
    	cout<<"Nhap keyword trong ten nhan vien can tim: ";fflush(stdin);
    	fgets(ten,sizeof(ten),stdin);
    	xoaXuongDong(ten);
    	timNhanVienTheoTen(ds,n,ten);
    	cout<<"\n==========================";
    	cout<<"\n1. Tiep tuc tim kiem.";
        cout<<"\n2. Quay lai.";
        cout<<"\n==========================";
        cout<<"\nChon muc: ";
        cin>>k;
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
    	cout<<"\n===================================";
    	cout<<"\n------THAO TAC TREN DANH SACH------";
    	cout<<"\n1. Xoa nhan vien.";
    	cout<<"\n2. Sap xep danh sach theo thu tu alpha B. ";
    	cout<<"\n3. Sua thong tin nhan vien.";
        cout<<"\n4. Quay lai.";
        cout<<"\n===================================";
        cout<<"\nChon muc: ";
        cin>>k;
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
    	cout<<"\n===================================";
    	cout<<"\n------THAO TAC TREN DANH SACH------";
    	cout<<"\n1. Xoa nhan vien.";
    	cout<<"\n2. Sua thong tin nhan vien.";
        cout<<"\n3. Quay lai.";
        cout<<"\n===================================";
        cout<<"\nChon muc: ";
        cin>>k;
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
    	cout<<"STT cua nhan vien ban muon sua: ";
        cin>>k;
    	SuaNhanVien(ds,n,k,tongluong);
    	system("cls");
    	XuatDanhSachNhanVien(ds,n,tongluong);
    	cout<<"\n===================================";
    	cout<<"\n------THAO TAC TREN DANH SACH------";
    	cout<<"\n1. Xoa nhan vien.";
    	cout<<"\n2. Sap xep danh sach theo thu tu alpha B. ";
    	cout<<"\n3. Sua thong tin nhan vien.";
        cout<<"\n4. Quay lai.";
        cout<<"\n===================================";
        cout<<"\nChon muc: ";
        cin>>k;
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
    void menuchung::LNV(){
        GhiVaoFile(ds,n,tongluong);
        QLNV();
    }
void menuchung:: ghifile(){
    FILE*f;
    f=fopen("vanhcpp.bin","wb");
    if(f==NULL){
        cout<<"\nloi mo file";
        return;
    }
    fwrite(&namedrink::n,sizeof(int),1,f);
    for(int i=0;i<n;i++) fwrite(&drink[i],sizeof(namedrink),1,f);
    fclose(f);
}
void menuchung:: docfile(){
    FILE*f;
    f=fopen("vanhcpp.bin","rb");
    if(f==NULL){
        cout<<("\nloi mo file");
        return;
    }
    fread(&namedrink::n,sizeof(int),1,f);
    drink.resize(namedrink::n);
    for(int i=0;i<namedrink::n;i++) fread(&drink[i],sizeof(namedrink),1,f);
    fclose(f);
}




int main(){
    int login =1 ;
    while(login<=3){
    system("cls");
    string c, d;
    string a = "admin";
    string b = "admin";
    cout<<"|------------------------------------------|\n";
    cout<<"| TAI KHOAN |                              |\n";
    cout<<"|------------------------------------------|\n";
    cout<<"| MAT KHAU  |                              |\n";
    cout<<"|------------------------------------------|";
    cout<<"\033[2;14H";
    cin>>c;
    cout<<"\033[4;14H";
    cin>>d;
    cout<<endl;



    if(c == a && d == a){
        sleep(2);
        cout<<"OK";
        sleep(1);
        menuchung m1;
        DocFile(ds,n,tongluong);
        m1.doc();
        m1.MENU();
        break;
    }
    
    else{ cout<<("tai khoan mat khau sai roi");
    sleep(1);
    }
    ++login;
    if(login ==3 ) {
        return 0 ;
    }
    sleep(2);
    }
   
}