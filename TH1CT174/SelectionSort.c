//Selection Sort
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

void SelectionSort(recordtype a[], int n){
	int i, j,lowindex;
	keytype lowkey;
	for(i = 0; i < n-2; i++ ){
		lowkey = a[i].key;
		lowindex = i;
		for(j = i+1; j < n-1; j++){
			//xet khoa a[j] nho nhat thi
			if(a[j].key < lowkey){
				//dat lai khoa nho nhat la khoa cua a[j]
				lowkey = a[j].key;
				//chi so phan tu cua khoa nho nhat la j
				lowindex = j;
			}
		}
		//sau khi xet thi phan tu nho nhat la a[lowindex]
		swap(&a[i], &a[lowindex]);
	}
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

int main(){
	recordtype a[10000];
	int n;
	
	printf("SelectionSort Starting...\n");
	Read_Data(a, &n);
	printf("\n\nDu lieu truoc khi sap xep:\n\n");
	Print_Data(a, n);
	SelectionSort(a, n);
	printf("\n\nDu lieu sau khi sap xep:\n\n");
	Print_Data(a, n);
	
	return 0;
}
