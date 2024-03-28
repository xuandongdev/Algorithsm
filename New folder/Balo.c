#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char tenDV;
    float TL, GT, DG;
    int SLDV;
}DoVat;

DoVat * ReadFromFile(float *w, float *n){
    FILE *f;
    f = fopen("Balo1.txt", "r");
    fscanf(f, "%d", w);
    DoVat *dsdv;
    dsdv = (DoVat*)malloc(sizeof(DoVat));
    int i = 0;
    while(!feof(f)){
        fscanf(f, "%f%f[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].tenDV);
        dsdv[i].DG = dsdv[i].GT / dsdv[i].TL;
        dsdv[i].SLDV = 0;
        i++;
        dsdv = realloc(dsdv, sizeof(DoVat)*(i+1));
    }
    *n = i; //so luong do vat
    fclose(f);
    return dsdv;//mang cac do vat
}
void swap(DoVat *x, DoVat *y){
    DoVat temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void bubleSort(DoVat *dsdv, int n){
    int i, j;
    for(i = 0; i < n-2; i++){
        for(j = n-1; j >= i+1; j--){
            if(dsdv[j].DG > dsdv[j-1].DG){
                swap(&dsdv[j], &dsdv[j-1]);
            }
        }
    }
}
void display(DoVat *dsdv, int n, float w){
    int i;
    float tongTL = 0.0, tongGT = 0.0;
    printf("\nPhuong an cai Balo1 dung thuat toan Greedy nhu sau:\n");
    printf("|---|------------------|---------|---------|---------|-----------|\n");
    printf("|STT|    Ten Do Vat    | TLuong  | Gia Tri | Don Gia | Phuong An |\n");
    printf("|---|------------------|---------|---------|---------|-----------|\n");
    for(i = 0; i < n; i++){
        printf("|%2d |%-18s|%9.2f|%9.2f|%9.2f|%6d     |\n",
               i+1, dsdv[i].tenDV, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].SLDV);
        tongTL = tongTL + dsdv[i].SLDV * dsdv[i].TL;
        tongGT = tongGT + dsdv[i].SLDV * dsdv[i].GT;
    }
    printf("|---|------------------|---------|---------|---------|-----------|\n");
    printf("So luong do vat theo thu tu giam dan: X(");
    for(i = 0; i < n-1; i++){
        printf("%d", dsdv[i].SLDV);
    }
    printf("%d)", dsdv[i].SLDV);
    printf("\nTong trong luong = %-9.2f\n", tongTL);
}
void Greedy(DoVat *dsdv, int n, float w){
    int i;
    for(i = 0; i < n; i++){
        dsdv[i].SLDV = (w / dsdv[i].TL);
        w = w - dsdv[i].SLDV * dsdv[i].TL;
    }
}
int main(){
    int n;
    float w;
    DoVat *dsdv;
    dsdv = ReadFromFile(&w, &n);
    bubleSort(dsdv, n);
    Greedy(dsdv, n, w);
    display(dsdv, n, w);
    free(dsdv);
    return 0;
}
