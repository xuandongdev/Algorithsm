#include <iostream>
using namespace std;
/*
    Voi so phan tu can sap xep cang lon thi hieu qua sap xep duoc xep theo thu tu:
    BubbleSort > SelectionSort > InsertionSort
*/
typedef int keytype;
typedef float othertype;
typedef struct recordtype {
    keytype key;
    othertype otherfields;
};
void Swap(recordtype &x, recordtype &y){
    recordtype temp;
    temp = x;
    x = y;
    y = temp;
}

void SelectionSort (recordtype a[ ], int n){
    //T=O(n^2)
    int i,j, lowindex;
    keytype lowkey;
    for(i=0; i<=n-2; i++){
    lowkey = a[i].key;
    lowindex = i;
    for(j=i+1; j<=n-1; j++)
        if(a[j].key < lowkey) {
            lowkey = a[j].key;
            lowindex = j;
        }
    Swap(a[i],a[lowindex]);
    }
}

void InsertionSort(recordtype a[], int n){
    //T=O(n^2)
    int i,j;
    for(i=1; i<=n-1; i++){
        j=i;
        while ((j>0)&&(a[j].key<a[j-1].key)) {
            Swap(a[j],a[j-1]);
            j--;
        }
    }
}

void BubbleSort(recordtype a[ ], int n) {
    //T=O(n^2)
    int i,j;
    for(i= 0; i<= n-2; i++){
        for(j=n-1;j>=i+1; j--){
            if (a[j].key < a[j-1].key){
                Swap(a[j],a[j-1]);
            }
        }
    }
}

int main(){
    cout << "Nhap vao so phan tu cua mang: " << endl;
    int length;
    cin >> length;
    recordtype arr[length];
    for(int i = 0; i < length; i++){
        cout << "Nhap gia tri phan tu thu " << i+1 <<":";
        cin >> arr[i].key;
    }
    cout << endl;

    //Selection
    cout << "SelectionSort:" << endl;
    SelectionSort(arr, length);
    for(int i = 0; i < length; i++){
        cout << arr[i].key << " ";
    }
    cout<<endl;

    //Insertion
    cout<<"InsertionSort:" << endl;
    InsertionSort(arr, length);
    for(int i = 0; i < length; i++){
        cout << arr[i].key<<" ";
    }
    cout<<endl;

    //Bubble
    cout<<"BubbleSort" << endl;
    BubbleSort(arr, length);
    for(int i = 0; i < length; i++){
        cout << arr[i].key << " ";
    }
    return 0;
}
