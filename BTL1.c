#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*typedef struct iningredient{
   //  char name[50];
     char donvi[20];
     float soluong;
} inin;*/

typedef struct ingredient{
       char name[50];
      // inin hehe ;
       char donvi[20];
     float soluong;
     int o;
}in;

void nhapin(in*a){
    printf("\nnhap ten nguyen lieu : ");
    fgets(a->name,sizeof(a->name),stdin);
    printf(" chon don vi (kg/l/cai)(1,2,3)");
    scanf("%d",&a->o);
    if(a->o == 1) strcpy(a->donvi,"kg");
    if(a->o == 2) strcpy(a->donvi,"l");
    if(a->o == 3) strcpy(a->donvi,"cai");
    printf("nhap ve bao nhieu (%s) : ",&a->donvi); 
    scanf("%f",&a->soluong);
    fflush(stdin);
}
typedef struct namefood{
    char name[50];
    in * haha ;//tao nguyen lieu cho do uong
    int h,b; // tao so luong nguyen lieu cho do an , do uong va
}namefood;

void innamefood(namefood*a, int N ,in *b ){ // N: số lượng nguyên liệu
     printf("nhap ten do an / do uong : ");
     fgets(a->name,sizeof(a->name),stdin);
     fflush(stdin);
     printf("nhap so luong nguyen lieu cho %s: ", a->name);
     scanf("%d",&a->h);
   //  a->haha * c;
     a->haha =(in*)malloc(a->h*sizeof(in));
     for(int i=0 ; i < a->h;i++){
        int k;
        printf("nguyen lieu %d la : ",i+1);
        for(int j =0; j< N ; j++)    printf(" %s--->%d  ",b[j].name,j);
        scanf("%d",&k);
        strcpy(a->haha[i].name,b[k].name);
        strcpy(a->haha[i].donvi,b[k].donvi);
        printf("%s can bao nhieu %s : ",a->haha[i].name,a->haha[i].donvi );
        scanf("%f",&a->haha->soluong);
     }


}

// tạo 1 hàm struct chứa tên các món ăn , đồ uống và nó chứa những thành phần nào trong bảng nguyên liệu , bao nhiêu và cần tạo thêm 1 hầm nhập thông tin 
 // của món ăn vào 

int main(){
    printf("nhap so luong nguyen lieu : ");
    int N;
    scanf("%d",&N);
    fflush(stdin);
    in  *a;
    a=(in*)malloc(N*sizeof(in));
    for(int i=0 ; i<N;i++){ 
        printf("nguyen lieu %d",i+1);
        nhapin(&a[i]);
    }
    int A;
    printf("nhap so loai do uong , do an vao ");
    scanf("%d",&A);
    fflush(stdin);
    namefood *b;
    b=(namefood*)malloc(A*sizeof(namefood));
    for(int i=0 ; i< A ; i++) innamefood(&b[i],N,a);
    
}
