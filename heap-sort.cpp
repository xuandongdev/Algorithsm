/*
(1) Xem mảng là cây nhị phân:
- a[0] là nút gốc
- Nút trong a[i] có con trái a[2i+1] và con phải a[2i+2]
- Nút trong từ a[0],…, a[(n-2)/2] đều có 2 con
(trừ nút a[(n-2)/2] có thể chỉ có 1 con trái khi n chẵn)
(2) Sắp xếp cây thành Heap: dùng thủ tục PushDown
(3) Hoán đổi nút gốc a[0] cho nút lá cuối
(4) Sắp xếp lại cây sau khi đã bỏ đi nút lá cuối thành Heap mới dùng PushDown
Lặp lại (3) và (4) cho đến khi cây chỉ còn 2 nút.
2 nút này cùng các nút lá đã bỏ đi tạo thành mảng theo thứ tự giảm dần.

PushDown nhận 2 tham số first và last để đẩy nút first xuống.
• Giả sử cây a[first],..,a[last] đã đúng vị trí của một Heap trừ a[first]:
PushDown sẽ đẩy a[first] xuống đúng vị trí của nó trong cây.
• Các khả năng có thể của a[first]:
(1) Nếu a[first] chỉ có một con trái và khoá > khoá con trái: hoán đổi
a[first] cho con trái của nó và kết thúc.
(2) Nếu a[first] có khoá > khóa con trái và khoá con trái ≤ khoá con phải:
hoán đổi a[first] cho con trái của nó  con trái có thể không đúng vị trí
nên phải xem xét lại con trái để có thể đẩy xuống.
(3) Ngược lại, nếu a[first] có khoá > khoá con phải và khoá con phải <
khoá con trái : hoán đổi a[first] cho con phải của nó  con phải có thể
không đúng vị trí nên phải xem xét lại con phải để có thể đẩy xuống.
Nếu các trường hợp trên không xảy ra : a[first] đã đúng vị trí.

PushDown: Trường hợp 1
(1) Nếu a[first] chỉ có
1 con trái (là nút lá) và
khoá > khoá con trái:
Hoán đổi a[first] cho con
trái của nó và kết thúc.

PushDown: Trường hợp 2
(2) Nếu a[first] có
khoá > khóa con trái và
khoá con trái ≤ khoá con phải:
- Hoán đổi a[first] cho con trái
của nó
 con trái có thể không đúng vị
trí nên phải xem xét lại con trái
để đẩy xuống (PushDown L)

PushDown: Trường hợp 3
(3) Nếu a[first] có
khoá > khoá con phải và
khoá con phải < khoá con trái:
- Hoán đổi a[first] cho con phải
của nó
 con phải có thể không đúng vị
trí nên phải xem xét lại con phải
để đẩy xuống (PushDown R)


*/
#include <iostream>
using namespace std;

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

void PushDown(recordtype a[], int first, int last) {
    int r = first;
    while (r <= (last - 1) / 2) {
        if (last == 2 * r + 1) {
            if (a[r].key > a[last].key) Swap(a[r], a[last]);
            r = last;
        } else if ((a[r].key > a[2 * r + 1].key) && (a[2 * r + 1].key <= a[2 * r + 2].key)) {
            Swap(a[r], a[2 * r + 1]);
            r = 2 * r + 1;
        } else if ((a[r].key > a[2 * r + 2].key) && (a[2 * r + 2].key < a[2 * r + 1].key)) {
            Swap(a[r], a[2 * r + 2]);
            r = 2 * r + 2;
        } else {
            r = last;
        }
    }
}
/*
Phân tích thủ tục PushDown
• Xét PushDown(0, n-1) : PushDown trên cây n nút.
• PushDown chỉ duyệt trên một nhánh nào đó của cây nhị phân, tức là
sau mỗi lần lặp thì số nút còn lại một nửa.
- Ban đầu PushDown trên cây có n nút;
- Sau lần lặp thứ nhất: PushDown trên cây có n/2 nút;
- Sau lần lặp thứ hai: PushDown trên cây có n/4 nút;…
Tổng quát, sau lần lặp thứ i: PushDown trên cây có n/2i nút.
• Trường hợp xấu nhất (luôn phải thực hiện việc đẩy xuống): while
thực hiện i lần sao cho n/2i = 1, tức i=logn. Mỗi lần lặp chỉ thực hiện
lệnh IF với thân là lời gọi Swap và lệnh gán, do đó tốn O(1) = 1.
• PushDown lấy O(logn) thời gian để đẩy xuống 1 nút trong cây n nút.
*/

/*
Thủ tục HeapSort
(1) Sắp xếp cây ban đầu thành Heap dùng thủ tục PushDown
Khởi đầu từ nút a[(n-2)/2], lần ngược tới nút gốc a[0]
(2) Hoán đổi nút gốc a[0] cho a[i].
(3) Sắp xếp cây a[0] .. a[i – 1] thành Heap dùng thủ tục
PushDown
Lặp lại (2) và (3) cho i chạy từ n – 1 đến 2
(4) Cuối cùng chỉ cần hoán đổi a[0] với a[1]
*/
void HeapSort(recordtype a[], int n){
    int i;
    for (i = (n-2)/2; i>=0; i--)
    PushDown(a, i, n-1);
    for (i = n-1; i>=2; i--) {
        Swap(a[0],a[i]);
        PushDown(a, 0, i-1);
    }
    Swap(a[0],a[1]);
}
/*
Phân tích HeapSort
• Hàm PushDown lấy O(logn).
• Trong HeapSort,
– Vòng lặp {1}-{2} lặp (n-2)/2+1 lần, mỗi lần
tốn O(logn) nên thời gian thực hiện {1}-{2} là
O(n logn).
– Vòng lặp {3}-{5} lặp n-2 lần, mỗi lần tốn
O(logn) nên thời gian thực hiện của {3}-{5} là
O(n logn).
• Thời gian thực hiện HeapSort là O(nlogn).
*/

int main(){
    int length;
    cout << "Nhap vao so luong phan tu: " << endl;
    cin >> length;
    recordtype arr[length];
    for(int i = 0; i < length; i++){
        cout << "Nhap vao gia tri cua phan tu thu " << i+1 << ":";
        cin >> arr[i].key;
    }
    cout << "Bat dau sap xep QuickSort:" << endl;
    HeapSort(arr, length);
    for(int i = 0; i < length; i++){
        cout << arr[i].key << " ";
    }
    cout << endl;
    return 0;
}
