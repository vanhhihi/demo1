#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct date{
    int ngay;
    int thang;
    int nam;
}date;

typedef struct NhanVien{
    int tt;
    char Ten[50];
    char gioiTinh[5];
    date ngaySinh; 
    int gioCong;
    int luong;
}NV;

int tongluong=0;
NV ds[100];
int n=0;
int t;

void xoaXuongDong(char x[]){
    size_t len=strlen(x);
    if(x[len-1]=='\n'){
        x[len-1]='\0';
    }
}

void nhapNhanVien(NV&nv){
    fflush(stdin);
    printf("\nHo va ten: ");fgets(nv.Ten,sizeof(nv.Ten),stdin);xoaXuongDong(nv.Ten);
    fflush(stdin);
    printf("Gioi tinh: ");fgets(nv.gioiTinh,sizeof(nv.gioiTinh),stdin);xoaXuongDong(nv.gioiTinh);
    printf("Ngay sinh(dd/mm/yyyy): ");scanf("%d/%d/%d",&nv.ngaySinh.ngay,&nv.ngaySinh.thang,&nv.ngaySinh.nam);
    printf("So gio cong: ");scanf("%d",&nv.gioCong);
}

void tinhluong(NV&nv){
    nv.luong=30000*nv.gioCong;
}

void capnhatnhanvien(NV&nv){
    nhapNhanVien(nv);
    tinhluong(nv);
}

void Nhapdanhsachnhanvien(NV ds[],int t,int&n,int&tongluong){
    do{
        printf("\nSo luong nhan vien muon them: ");scanf("%d",&t);
    }while(t<=0);
    for(int i=n;i<n+t;i++){
        printf("\n-----Nhan vien thu %d-----",i+1);
        capnhatnhanvien(ds[i]);
        ds[i].tt=i+1;
        tongluong+=ds[i].luong;
        
    }
    n+=t;
}

void inNhanVien(NV nv){
    printf("|%3d \t| %25s \t| %6s \t| %2d/%d/%2d \t| %10d \t| %12d |",nv.tt,nv.Ten,nv.gioiTinh,nv.ngaySinh.ngay,nv.ngaySinh.thang,nv.ngaySinh.nam,nv.gioCong,nv.luong);
}

void XuatDanhSachNhanVien(NV ds[],int &n,int&tongluong){
	for(int i=0;i<n;i++){
		ds[i].tt=i+1;
	}
	printf("--------------------------------------------------------------------------------------------------------\n");
    printf("|%3s \t| %25s \t| %6s \t| %10s \t| %10s \t| %12s |","STT","HO VA TEN","GIOI TINH","NGAY SINH","SO GIO CONG","LUONG(dong)");
    printf("\n");
    for(int i=0;i<n;i++){
    	printf("--------------------------------------------------------------------------------------------------------\n");
    	inNhanVien(ds[i]);
    	printf("\n");
	}
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("-Tong so luong nhan vien: %d nhan vien.",n);
	printf("\n-Tong tien luong can thanh toan la: %d (dong)\n",tongluong);
}

void XoaNhanVienTheoMa(NV ds[],int&n,int id,int&tongluong){
	for(int i=0;i<n;i++){
		if(ds[i].tt==id){
			tongluong=tongluong-ds[i].luong;
			for(int j=i;j<n;j++){
				ds[j]=ds[j+1];
				ds[j].tt-=1;
			}
			n-=1;
		}
	}
	printf("--------------------------------------------------------------------------------------------------------\n");
    printf("|%3s \t| %25s \t| %6s \t| %10s \t| %10s \t| %12s |","STT","HO VA TEN","GIOI TINH","NGAY SINH","SO GIO CONG","LUONG(dong)");
    printf("\n");
    for(int i=0;i<n;i++){
    	printf("--------------------------------------------------------------------------------------------------------\n");
    	inNhanVien(ds[i]);
    	printf("\n");
	}
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("-Tong so luong nhan vien: %d nhan vien.",n);
	printf("\n-Tong so tien luong can thanh toan la: %d (dong)\n",tongluong);
}
 
 void timNhanVienTheoTen(NV ds[],int n, char ten[]){
 	NV *ds2=new NV[n];
 	for(int i=0;i<n;i++){
 		ds2[i]=ds[i];
	}
    for(int i=0;i<n;i++){
    	for(int j=0;j<=strlen(ds2[i].Ten);j++){
            if(ds2[i].Ten[j]>=65&&ds2[i].Ten[j]<=90)
                ds2[i].Ten[j]+=32;
        }
    }
    for(int j=0;j<=strlen(ten);j++){
            if(ten[j]>=65&&ten[j]<=90)
                ten[j]+=32;
    }
 	printf("--------------------------------------------------------------------------------------------------------\n");
    printf("|%3s \t| %25s \t| %6s \t| %10s \t| %10s \t| %12s |","STT","HO VA TEN","GIOI TINH","NGAY SINH","SO GIO CONG","LUONG(dong)");
    printf("\n");
 	for(int i=0;i<n;i++){
 		if(strstr(ds2[i].Ten,ten) ){
 			
 	     	printf("--------------------------------------------------------------------------------------------------------\n");
 			inNhanVien(ds[i]);
 			printf("\n");
		}
	 }
	printf("--------------------------------------------------------------------------------------------------------\n");
 }
 
void sapXepDanhSachNhanVienTheoTen(NV ds[],int n){
 	for(int i=0;i<n-1;i++){
 		for(int j=i+1;j<n;j++){
 			if(strcmp(ds[i].Ten,ds[j].Ten)>0){
 				NV temp;
 				temp=ds[i];
 				ds[i]=ds[j];
 				ds[j]=temp;
 			}
		 }
	}
	for(int i=0;i<n;i++){
		ds[i].tt=i+1;
	}
	printf("--------------------------------------------------------------------------------------------------------\n");
    printf("|%3s \t| %25s \t| %6s \t| %10s \t| %10s \t| %12s |","STT","HO VA TEN","GIOI TINH","NGAY SINH","So GIO CONG","LUONG(dong)");
    printf("\n");
    for(int i=0;i<n;i++){
    	printf("--------------------------------------------------------------------------------------------------------\n");
    	inNhanVien(ds[i]);
    	printf("\n");
	}
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("-Tong so luong nhan vien: %d nhan vien.",n);
	printf("\n-Tong so tien luong can thanh toan la: %d (dong)\n",tongluong);
 }
 void SuaNhanVien(NV ds[],int n,int k, int&tongluong){
 	for(int i=0;i<n;i++){
 		if(ds[i].tt==k){
 			int c;
 			printf("\n----Thong tin nhan vien----",k);
 			printf("\n1.Ten: %s",ds[i].Ten);
 			printf("\n2.Gioi tinh: %s",ds[i].gioiTinh);
 			printf("\n3.Ngay sinh: %d/%d/%d",ds[i].ngaySinh.ngay,ds[i].ngaySinh.thang,ds[i].ngaySinh.nam);
 			printf("\n4.So gio cong: %d",ds[i].gioCong);
 			printf("\n  Luong: %d(dong)\n",ds[i].luong);
 			printf("\nBan muon sua muc nao(nhap 0 de sua het): ");scanf("%d",&c);
 			printf("--------------");
 			if(c==0){
 				fflush(stdin);
                printf("\nHo va ten: ");fgets(ds[i].Ten,sizeof(ds[i].Ten),stdin);xoaXuongDong(ds[i].Ten);
                fflush(stdin);
                printf("Gioi tinh: ");fgets(ds[i].gioiTinh,sizeof(ds[i].gioiTinh),stdin);xoaXuongDong(ds[i].gioiTinh);
                printf("Ngay sinh(dd/mm/yyyy): ");scanf("%d/%d/%d",&ds[i].ngaySinh.ngay,&ds[i].ngaySinh.thang,&ds[i].ngaySinh.nam);
                printf("So gio cong: ");scanf("%d",&ds[i].gioCong);
                tongluong-=ds[i].luong;
                tinhluong(ds[i]);
                tongluong+=ds[i].luong;
			}
 			if(c==1){
			    fflush(stdin);
                printf("\nHo va ten: ");fgets(ds[i].Ten,sizeof(ds[i].Ten),stdin);xoaXuongDong(ds[i].Ten);
			}
			if(c==2){ 
			    fflush(stdin);
                printf("\nGioi tinh: ");fgets(ds[i].gioiTinh,sizeof(ds[i].gioiTinh),stdin);xoaXuongDong(ds[i].gioiTinh);
			}
			if(c==3){
				printf("\nNgay sinh(dd/mm/yyyy): ");scanf("%d/%d/%d",&ds[i].ngaySinh.ngay,&ds[i].ngaySinh.thang,&ds[i].ngaySinh.nam);
			}
			if(c==4){
                printf("\nSo gio cong: ");scanf("%d",&ds[i].gioCong);
                tongluong-=ds[i].luong;
                tinhluong(ds[i]);
                tongluong+=ds[i].luong;
			}
	    }
	}
 }
 void GhiVaoFile( NV ds[],int n,int tongluong){
 	FILE*f;
 	f=fopen("tenFile.bin","wb");
 	if(f==NULL){
 		printf("\nLoi mo file de ghi!");
 		return ;
	}
	fwrite(&n,sizeof(n),1,f);
	fwrite(&tongluong,sizeof(tongluong),1,f);
	int i;
	for( i=0;i<n;i++){
		fwrite(&ds[i],sizeof(NV),1,f);
	}
	fclose(f);
}


void DocFile(NV ds[],int&n,int&tongluong){
 	FILE*f;
 	f=fopen("tenFile.bin","rb");
 	if(f==NULL){
 		printf("\nLoi mo file de doc!");
 		return ;
	 }
	fread(&n,sizeof(n),1,f);
	fread(&tongluong,sizeof(tongluong),1,f);
	int i;
	for( i=0;i<n;i++){
		fread(&ds[i],sizeof(NV),1,f);
	}
	fclose(f);
}
