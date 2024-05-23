#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
     int o;
}in;

void nhapin(in*a){
    printf("\nnhap ten nguyen lieu : ");
    fgets(a->name,sizeof(a->name),stdin);
    a->name[strcspn(a->name,"\n")]=0;    
    printf(" chon don vi (kg/l/cai)(1,2,3)");
    scanf("%d",&a->o);
    fflush(stdin);
    if(a->o == 1) strcpy(a->donvi,"kg");
    if(a->o == 2) strcpy(a->donvi,"l");
    if(a->o == 3) strcpy(a->donvi,"cai");
    printf("nhap ve bao nhieu (%s) : ",&a->donvi); 
    scanf("%f",&a->soluong);
    fflush(stdin);
    printf("nhap ma cho %s : ", a->name);
    scanf("%d",&a->code);
  //  a->code[strcspn(a->code,"\n")]=0;
  fflush(stdin);
}
typedef struct namefood{
    char donvi[50];
    char name[50];
    in * haha ;//tao nguyen lieu cho do uong
    int h; // tao so luong nguyen lieu cho do an , do uong 
    float cost ;
}namefood;

void innamefood(namefood*a, int N ,in *b ){ // N: số lượng nguyên liệu
     printf("nhap ten do an / do uong : ");
     fgets(a->name,sizeof(a->name),stdin);
   //  fflush(stdin);    
     a->name[strcspn(a->name, "\n")] = 0;
     printf(" don vi cua %s : ", a->name);
     scanf("%s",&a->donvi);
     fflush(stdin);
     printf("gia cua %s la : ",a->name);
     scanf("%f",&a->cost);
     printf("nhap so luong nguyen lieu cho %s: ", a->name);
     scanf("%d",&a->h);
   //  a->haha * c;
     a->haha =(in*)malloc(a->h*sizeof(in));
     for(int i=0 ; i < a->h;i++){
        int k;
        printf("nguyen lieu %d la : \n",i+1);
        for(int j =0; j< N ; j++)    printf("%s ----> %d  \n",b[j].name,j);
        scanf("%d",&k);
        a->haha[i].code=b[k].code;
        strcpy(a->haha[i].name,b[k].name);
        strcpy(a->haha[i].donvi,b[k].donvi);
        printf("%s can bao nhieu %s : ",a->haha[i].name,a->haha[i].donvi );
        scanf("%f",&a->haha->soluong);
        fflush(stdin);
     }
}
 typedef struct bill{
    char name[50];
    int number;
    float cost;
    char donvi[50];

 }bill;
 
 void check(in *a, namefood *b,int N,int A ){
  int k = 9000;
  int u;
  printf("hien quan con : ");
  for(int m=0;m<A;m++){
  for ( int i=0 ;i<b->h;i++)  
  for(int j=0 ;j<N ;j++ ) if(a[j].code == b[m].haha[i].code)  if(k > (a[j].soluong/b[m].haha[i].soluong) ) k= (a[j].soluong/b[m].haha[i].soluong) ;
  printf("\n %s con lai : %d (%s)^^",b[m].name,k,b[m].donvi);  
  k=9000;  }
  }
void tonkho(namefood * b ,int N, in * a, int k){
  for(int i=0 ; i< b->h;i++ ) 
    for(int j=0 ;j<N;j++) if(b->haha[i].code==a[j].code) a[j].soluong-=b->haha[i].soluong*k ;
}
void check1(namefood *b,int * k,in*a,int N,int *number){
       char c ='n';
       while(c=='n'){
         for(int i=0 ;i<b[*k].h;i++)
          for(int j=0 ;j<N ;j++) 
            if(b[*k].haha[i].code == a[j].code) {
              if(b[*k].haha[i].soluong * *number > a[j].soluong ){ 
              printf("ko du so luong nen hay nhap lai ma do an / do uong ^^");
              printf("\nma do uong : ");
              scanf("%d",k);             
              printf("so luong : ");
              scanf("%d",number) ;
              getchar();
              continue;            
              }
            else c='y';
                                                }

                    }
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
    }
    int A;
    printf("nhap so loai do uong , do an vao ");
    scanf("%d",&A);
    getchar();
    // tao ten do uong , thuc an 
    namefood *b;
    b=(namefood*)malloc(A*sizeof(namefood));
    for(int i=0 ; i< A ; i++) innamefood(&b[i],N,a);
// chon do an
  //  printf("moi khach hang chon do an / do uong : ");
    char c = 'y';
    int p=0;
    float money =0 ;
    bill * m= NULL ;
    while(c=='y' || c=='Y'){
      printf("moi khach hang chon do an / do uong : ");      
        check (a,b,N,A );
        for(int i=0;i<A;i++)    printf("\n %s ------> %d ", b[i].name , i );
                                printf("\n");
                                int k,number;
                                scanf("%d",&k);
                                getchar();
                                printf("quy khach muon dung bao nhieu %s : ", b [k].name);
                                scanf("%d",&number);
                                getchar();
                                check1(b,&k,a,N,&number);

                                m=(bill*)realloc(m,(p+1)*sizeof(bill));
                                strcpy(m[p].name,b[k].name);
                                strcpy(m[p].donvi,b[k].donvi);                                
                                //printf("quy khach muon dung bao nhieu %s : ", b [k].name);
                                //scanf("%d",&m[p-1].number);
                                //fflush(stdin);
                                m[p].number=number;
                                money = money + b[k].cost * m[p].number ;
                                tonkho(&b[k],N,a,m[p-1].number);
                                printf("quy khach muon mua nua ko (y/n)?");
                                scanf("%c",&c);
                                p++;
    }


    printf("khach da mua : ");
    for(int i=0 ; i<p;i++)
      printf("\n %s :%d(%s)  ",m[i].name,m[i].number,m[i].donvi);
    printf("\ntong tien : %f",money);
free(a);
free(b);
free(m);    
    
}
