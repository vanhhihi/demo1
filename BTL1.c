#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

/*typedef struct iningredient{
   //  char name[50];
     char donvi[20];
     float soluong;
} inin;*/

typedef struct ingredient{
       int code;// tao ma cho nguyen lieu 
       char name[50];
      // inin hehe ;
       char donvi[50];
     float soluong;
    // int o;
}in;

void nhapin(in*a){
    int o;
    printf("\nnhap ten nguyen lieu : ");
    fgets(a->name,sizeof(a->name),stdin);
    a->name[strcspn(a->name,"\n")]=0;    
    printf(" chon don vi (kg/l/cai)(1,2,3)");
    scanf("%d",&o);
    fflush(stdin);
    if(o == 1) strcpy(a->donvi,"kg");
    if(o == 2) strcpy(a->donvi,"l");
    if(o == 3) strcpy(a->donvi,"cai");
    printf("nhap ve bao nhieu (%s) : ",&a->donvi); 
    scanf("%f",&a->soluong);
    fflush(stdin);
    //printf("nhap ma cho %s : ", a->name);
    //scanf("%d",&a->code);
  //  a->code[strcspn(a->code,"\n")]=0;
  fflush(stdin);
}
typedef struct namefood{
    char donvi[50];
    char name[50];
    in * ingredient ;//tao nguyen lieu cho do uong
    int in_number; // tao so luong nguyen lieu cho do an , do uong 
    float cost ;//gia cua do an/ do uong
}namefood;

void innamefood(namefood*a, int N ,in *b ){ // N: số lượng nguyên liệu
     printf("nhap ten do an / do uong : ");
     fgets(a->name,sizeof(a->name),stdin);
   //  fflush(stdin);    
     a->name[strcspn(a->name, "\n")] = 0;
     printf("don vi cua %s : ", a->name);
     scanf("%s",&a->donvi);
     fflush(stdin);
    //a->name[strcspn(a->name,"\n")]=0;
     printf("gia cua %s la (dong) : ",a->name);
     scanf("%f",&a->cost);
     printf("nhap so luong nguyen lieu cho %s: ", a->name);
     scanf("%d",&a->in_number);
   //  a->haha * c;
     a->ingredient =(in*)malloc(a->ingredient*sizeof(in));
     for(int i=0 ; i < a->h;i++){
        int k;
        printf("nguyen lieu %d la : \n",i+1);
        for(int j =0; j< N ; j++)    printf("%s ----> %d  \n",b[j].name,j);
        scanf("%d",&k);
        a->ingredient[i].code=b[k].code;
        strcpy(a->ingredient[i].name,b[k].name);
        strcpy(a->ingredient[i].donvi,b[k].donvi);
        printf("%s can bao nhieu %s : ",a->ingredient[i].name,a->ingredient[i].donvi );
        scanf("%f",&a->ingredient->soluong);
        fflush(stdin);
     }
}
 typedef struct bill{
    char name[50];
    int number;// so luong do mua 
    float cost;
    char donvi[50];

 }bill;
 
 void check(in *a, namefood *b,int a_number,int b_number ){ // kiem tra coi co bao nhieu san pham de thong bao cho khach hang chon
  
  printf("hien quan con : ");
  for(int m=0;m<b_number;m++){
    int k=INT_MAX;
    for ( int i=0 ;i<b->h;i++){  
      for(int j=0 ;j<a_number ;j++ ){
        if(a[j].code == b[m].ingredient[i].code){
          int min =(int)( a[j].soluong/b[m].ingredient[i].soluong);
          if(k>min) k=min;
        }  //if(k >= (a[j].soluong/b[m].haha[i].soluong) ) k= (a[j].soluong/b[m].haha[i].soluong) ;
  //k=(k>(a[j].soluong/b[m].haha[i].soluong))? (a[j].soluong/b[m].haha[i].soluong) : k ;
      }  
    }

  printf("\n %s con lai : %d (%s)^^",b[m].name,k,b[m].donvi);  
  
  }  
  }
void tonkho(namefood * b ,int a_number, in * a, int k){
  for(int i=0 ; i< b->h;i++ ) 
    for(int j=0 ;j<a_number;j++) if(b->ingredient[i].code==a[j].code) a[j].soluong-=b->ingredient[i].soluong*k ;
}
void check1(namefood *b,int * code,in*a,int a_number,int *number){
       char c ='n';
       while(c=='n'){
         for(int i=0 ;i<b[*code].h;i++)
          for(int j=0 ;j<a_number ;j++) 
            if(b[*code].ingredient[i].code == a[j].code) {
              if(b[*code].ingredient[i].soluong * *number > a[j].soluong ){ 
              printf("ko du so luong nen hay nhap lai ma do an / do uong ^^");
              printf("\nma do uong : ");
              scanf("%d",code);             
              printf("so luong : ");
              scanf("%d",number) ;
              getchar();
              continue;            
              }
            else c='y';                          }
                  }
}

typedef struct customer{
    char name[50];
    bill * bill; // hoa don moi mon hang ma khach hang mua
    float money;
    int number; // so luong hang ma khach hang da mua 
}cus;

void incustomer(cus *a){
   printf("nhap ten khach hang vao");
   fgets(a->name,sizeof(a->name),stdin);
   a->name[strcspn(a->name,"\n")]=0;
}
void xuatcustomer(cus * a){
   printf("\n%s da mua : ",a->name);
   for(int i=0 ; i< a->number;i++) printf("\n %s : %d (%s)",a->bill[i].name,a->bill[i].number,a->bill[i].donvi);
   printf("\n tong tien hoa don : %f",a->money);

}



int main(){
    printf("nhap so luong nguyen lieu : ");
    int N;
    scanf("%d",&N);
    fflush(stdin);
    // tao nguyen lieu
    in  *a;
    a=(in*)malloc(N*sizeof(in));
    for(int i=0 ; i<N;i++){ 
        printf("nguyen lieu %d",i+1);
        nhapin(&a[i]);
        a[i].code = i;
    }
    int A; // so loai do uong , do an
    printf("nhap so loai do uong , do an vao ");
    scanf("%d",&A);
    getchar();
    // tao ten do uong , thuc an 
    namefood *b;
    b=(namefood*)malloc(A*sizeof(namefood));
    for(int i=0 ; i< A ; i++)       innamefood(&b[i],N,a);
  
// chon do an
  //  printf("moi khach hang chon do an / do uong : ");
  cus * customer =NULL;
  char khach = 'y';
  int member =0;
  while(khach == 'y' || khach == 'Y'){
    customer = (cus*)realloc(customer,(member+1)*sizeof(cus));
    incustomer(&customer[member]);

    char c = 'y';
    int p=0;
    float money =0 ;
    customer[member].bill=NULL;
    //bill * m= NULL ;
    while(c=='y' || c=='Y'){
      printf("moi %s chon do an / do uong : ",customer[member].name);      
        check (a,b,N,A );
        for(int i=0;i<A;i++)    printf("\n %s ------> %d ", b[i].name , i );
                                printf("\n");
                                int k,number;
                                scanf("%d",&k);
                                getchar();
                                printf("%s muon dung bao nhieu %s : ",customer[member].name, b [k].name);
                                scanf("%d",&number);
                                getchar();
                                check1(b,&k,a,N,&number);

                                customer[member].bill=(bill*)realloc(customer[member].bill,(p+1)*sizeof(bill));
                                strcpy(customer[member].bill[p].name,b[k].name);
                                strcpy(customer[member].bill[p].donvi,b[k].donvi);                                
                                //printf("quy khach muon dung bao nhieu %s : ", b [k].name);
                                //scanf("%d",&m[p-1].number);
                                //fflush(stdin);
                                customer[member].bill[p].number=number;
                                customer[member].money += b[k].cost * customer[member].bill[p].number ;
                                tonkho(&b[k],N,a,customer[member].bill[p-1].number);
                                printf("quy khach muon mua nua ko (y/n)?");
                                scanf("%c",&c);
                                p++;
                                customer[member].number=p;
    }
   printf("\nkhach hang thu %d cua cua hang ",member+1) ;
   xuatcustomer(&customer[member]);
   printf("\n co khach hang thu %d khong (y/n)",member+1);
   scanf("%c",&khach);

   
  }


free(a);
free(b);
free(customer);    
    
}
