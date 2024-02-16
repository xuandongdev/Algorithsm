#include <iostream>
using namespace std;
/*
• Ý tưởng của thuật toán này là "chia để trị“
• Bước 1: Chọn một phần tử khóa v làm phần tử chốt (pivot)
• Bước 2: Phân hoạch dãy a[0] .. a[n-1] thành hai mảng con "bên
trái" và "bên phải". Mảng con "bên trái" bao gồm các phần tử
có khóa nhỏ hơn chốt. Mảng con "bên phải" bao gồm các
phần tử có khóa lớn hơn hoặc bằng chốt.
• Bước 3: Sau khi phân hoạch thành 2 mảng, thực hiện lại bước
2 ở từng mảng - Chọn pivot ở từng mảng và tiếp tục phân chia
thành các mảng nhỏ hơn, sắp xếp đến khi mảng được sắp xếp
hoàn toàn (mảng chỉ gồm 1 phần tử hoặc gồm nhiều phần tử có
khóa bằng nhau thì đã có thứ tự)

Phương pháp chọn chốt
Chọn giá trị khóa lớn nhất trong 2 phần tử có khóa khác nhau
đầu tiên kể từ trái qua.
• Nếu mảng chỉ gồm 1 phần tử hay gồm nhiều phần tử có khóa bằng
nhau thì không có chốt

• Ví dụ: Chọn chốt trong các mảng sau
– Cho mảng gồm các phần tử có khoá là 6, 6, 5, 8, 7, 4, ta chọn chốt là 6
(khoá của phần tử đầu tiên).
– Cho mảng gồm các phần tử có khoá là 6, 6, 7, 5, 7, 4, ta chọn chốt là 7
(khoá của phần tử thứ 3).
– Cho mảng gồm các phần tử có khoá là 6, 6, 6, 6, 6, 6 thì không có chốt
(vì các phần tử có khoá bằng nhau).
– Cho mảng gồm 1 phần tử có khoá là 6 thì không có chốt (vì chỉ có 1 phần tử).

Phương pháp phân hoạch
• Ðể phân hoạch mảng: dùng 2 "con nháy" L và R, trong đó
L đi từ bên trái và R đi từ bên phải.
• Cho L chạy sang phải tới khi gặp phần tử có khóa ≥ chốt
• Cho R chạy sang trái tới khi gặp phần tử có khóa < chốt
• Tại chỗ dừng của L và R: nếu L < R thì hoán vị a[L], a[R].
• Lặp lại quá trình dịch sang phải, sang trái của 2 "con
nháy" L và R cho đến khi L > R.
• Khi đó L sẽ là điểm phân hoạch, cụ thể là a[L] là phần tử
đầu tiên của mảng con “bên phải”.
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

int FindPivot(recordtype a[ ], int i,int j) {
    keytype firstkey;
    int k ;
    k = i+1;
    firstkey = a[i].key;
    while ( (k <= j) && (a[k].key == firstkey) ) k++;
    if (k > j) return -1;
    else
        if (a[k].key>firstkey) return k;
        else return i;
}

int Partition(recordtype a[], int i,int j, keytype pivot){
    int L,R;
    L = i;
    R = j;
    while (L <= R) {
        while (a[L].key < pivot) L++;
        while (a[R].key >= pivot) R--;
        if (L<R) Swap(a[L],a[R]);
    }
    return L; /*Tra ve diem phan hoach*/
}

void QuickSort(recordtype a[], int i,int j){
    keytype pivot;
    int pivotindex, k;
    pivotindex = FindPivot(a,i,j);
    if (pivotindex != -1) {
        pivot = a[pivotindex].key;
        k = Partition(a,i,j,pivot);
        QuickSort(a,i,k-1);
        QuickSort(a,k,j);
    }
}

int main(){
    int length;
    cout << "Nhap vao so luong phan tu:" << endl;
    cin >> length;
    recordtype arr[length];
    for(int i = 0; i < length; i++){
        cout << "Nhap vao gia tri cua phan tu " << i+1 << ":" << endl;
        cin >> arr[i].key;
    }
    cout << "Bat dau thuc hien QuickSort" << endl;
    QuickSort(arr, 0, length -1);
    for(int i = 0; i < length; i++){
        cout << arr[i].key << " ";
    }
    cout << endl;
    return 0;
}
