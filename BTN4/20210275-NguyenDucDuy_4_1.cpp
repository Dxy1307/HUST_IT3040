// Nguyễn Đức Duy - 20210275
#include <iostream> 
using namespace std;
struct Node { // khởi tạo danh sách liên kết đơn
    int data; 
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// Thêm phần tử vào đầu danh sách
Node* prepend(Node* head, int data) {
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    Node* temp = new Node(data);
    temp -> next = head;
    return temp;
}

// In danh sách
void print(Node* head) {
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    while(head) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

// Đảo ngược danh sách
Node* reverse(Node* head) {
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    Node* tmp = head, *dsmoi = NULL, *newNode;
    while(tmp != NULL) {
        newNode = prepend(head, tmp -> data);
        newNode -> next = dsmoi;
        dsmoi = newNode;
        tmp = tmp -> next;
    }
    return dsmoi;
}
  
int main() {
    int n, u;
    cin >> n; // danh sách có n phần tử
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;// phần tử có data là u
        head = prepend(head, u);
    } 
    
    cout << "Original list: ";
    print(head);

    head = reverse(head);
    
    cout << "Reversed list: ";
    print(head);

    return 0; 
}
// Nguyễn Đức Duy - 20210275