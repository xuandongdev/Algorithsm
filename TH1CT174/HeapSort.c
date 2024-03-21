//HeapSort
#include <stdio.h>

typedef int keytype;
typedef float othertype;

typedef struct {
	keytype key;
	othertype otherfields;
}recordtype;

void Swap(recordtype *x,recordtype *y){
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

void PushDown(recordtype a[], int first, int last) {
    int r = first;
    while (r <= (last - 1) / 2) {
        if (last == 2 * r + 1) {
            if (a[r].key > a[last].key) Swap(&a[r], &a[last]);
            r = last;
        } else if ((a[r].key > a[2 * r + 1].key) && (a[2 * r + 1].key <= a[2 * r + 2].key)) {
            Swap(&a[r], &a[2 * r + 1]);
            r = 2 * r + 1;
        } else if ((a[r].key > a[2 * r + 2].key) && (a[2 * r + 2].key < a[2 * r + 1].key)) {
            Swap(&a[r], &a[2 * r + 2]);
            r = 2 * r + 2;
        } else {
            r = last;
        }
    }
}

void HeapSort(recordtype a[], int n){
    int i;
    for (i = (n-2)/2; i>=0; i--)
    PushDown(a, i, n-1);
    for (i = n-1; i>=2; i--) {
        Swap(&a[0], &a[i]);
        PushDown(a, 0, i-1);
    }
    Swap(&a[0], &a[1]);
}

int main(){
	recordtype a[10000];
	int n;
	
	printf("QuickSortVariant Starting...\n");
	Read_Data(a, &n);
	printf("\n\nDu lieu truoc khi sap xep:\n\n");
	Print_Data(a, n);
	HeapSort(a, n);
	printf("\n\nDu lieu sau khi sap xep:\n\n");
	Print_Data(a, n);
	
	return 0;
}
