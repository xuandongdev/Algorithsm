//Bubble Sort
#include <stdio.h>

typedef int keytype;
typedef float othertype;

typedef struct {
	keytype key;
	othertype otherfields;
}recordtype;

void swap(recordtype *x,recordtype *y){
	recordtype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void Read_Data(recordtype a[], int *n){
	FILE *f;
	f=fopen("data.txt", "r");
	int i=0;
	if(f!=NULL)
	while (!feof(f)){
		fscanf(f,"%d%f",&a[i].key, &a[i].otherfields);
		i++;
	} else printf("Loi mo file\n");
	fclose(f);
	*n=i;
}
	
void Print_Data(recordtype a[], int n){
	int i;
	for(i=0;i<n;i++) 
	printf("%3d%5d%8.2f\n",i+1,a[i].key,a[i].otherfields);
}

void BubbleSort(recordtype a[ ], int n) {
    //T=O(n^2)
    int i,j;
    for(i= 0; i<= n-2; i++){
        for(j=n-1;j>=i+1; j--){
            if (a[j].key < a[j-1].key){
                swap(&a[j], &a[j-1]);
            }
        }
    }
}

int main(){
	recordtype a[10000];
	int n;
	
	printf("BubbleSort Starting...\n");
	Read_Data(a, &n);
	printf("\n\nDu lieu truoc khi sap xep:\n\n");
	Print_Data(a, n);
	BubbleSort(a, n);
	printf("\n\nDu lieu sau khi sap xep:\n\n");
	Print_Data(a, n);
	
	return 0;
}
