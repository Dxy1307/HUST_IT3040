#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#define MAX 100
using namespace std;

struct SinhVien {
    int id;
    char ten[30];
    char gioiTinh[5];
    int tuoi;
    float diemToan;
    float diemLy;
    float diemHoa;
    float diemTB = 0;
    char hocLuc[10] = "-";
};

typedef SinhVien SV;

void printLine(int n); // in ra 1 dòng có ký tự "_"
int idLonNhat(SV a[], int n); // lấy ra id lớn nhất của danh sách svien a[]

void nhapThongTinSV(SV &sv, int id);// 2 hàm này để thêm mới
void nhapSV(SV a[], int id, int n);// sinh viên vào danh sách

void capNhatThongTinSV(SV &sv); // cập nhật thông tin
void capNhatSV(SV a[], int id, int n); // sinh viên theo ID

int xoaTheoID(SV a[], int id, int n); // xóa svien khỏi danh sách theo ID
void timKiemTheoTen(SV a[], char ten[], int n);// tìm kiếm svien theo tên không phân biệt hoa thường

void tinhDTB(SV &sv);
void xepLoai(SV &sv);

void sapxepTheoDTB(SV a[], int n);
void sapxepTheoTen(SV a[], int n);

void showStudent(SV a[], int n);
int docFile(SV a[], char fileName[]);
void ghiFile(SV a[], int n, char fileName[]);
void pressAnyKey();

void printLine(int n) {
    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}

int idLonNhat(SV a[], int n) {
    int idMax = 0;
    if(n > 0) {
        idMax = a[0].id;
        for(int i = 0; i < n; i++) {
            if(a[i].id > idMax) {
                idMax = a[i].id;
            }
        }
    }
    return idMax;
}

void nhapThongTinSV(SV &sv, int id) {
    cout << "\n Nhap ten: "; fflush(stdin); gets(sv.ten);
    cout << " Nhap gioi tinh: "; gets(sv.gioiTinh);
    cout << " Nhap tuoi: "; cin >> sv.tuoi;
    cout << " Nhap diem Toan: "; cin >> sv.diemToan;
    cout << " Nhap diem Ly: "; cin >> sv.diemLy;
    cout << " Nhap diem Hoa: "; cin >> sv.diemHoa;
    sv.id = id;
    tinhDTB(sv);
    xepLoai(sv);
}

void nhapSV(SV a[], int id, int n) {
    printLine(40);
    printf("\n Nhap sinh vien thu %d:", n + 1);
    nhapThongTinSV(a[n], id);
    printLine(40);
}

void capNhatThongTinSV(SV &sv) {
    cout << "\n Nhap ten: "; fflush(stdin); gets(sv.ten);
    cout << " Nhap gioi tinh: "; gets(sv.gioiTinh);
    cout << " Nhap tuoi: "; cin >> sv.tuoi;
    cout << " Nhap diem Toan: "; cin >> sv.diemToan;
    cout << " Nhap diem Ly: "; cin >> sv.diemLy;
    cout << " Nhap diem Hoa: "; cin >> sv.diemHoa;
    tinhDTB(sv);
    xepLoai(sv);
}

void capNhatSV(SV a[], int id, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].id == id) {
            found = 1;
            printLine(40);
            cout << "\n Cap nhat thong tin sinh vien co ID = " << id;
            capNhatThongTinSV(a[i]);
            printLine(40);
            break;
        }
    }
    if(found == 0) {
        printf("\n Sinh vien co ID = %d khong ton tai.", id);
    }
}

int xoaTheoID(SV a[], int id, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].id == id) {
            found = 1;
            printLine(40);
            for(int j = i; j < n; j++) {
                a[j] = a[j + 1];
            }
            cout << "\n Da xoa SV co ID = " << id;
            printLine(40);
            break;
        }
    }
    if(found == 0) {
        printf("\n Sinh vien co ID = %d khong ton tai.", id);
        return 0;
    } else {
        return 1;
    }
}

void timKiemTheoTen(SV a[], char ten[], int n) {
    SV arrayFound[MAX];
    char tenSV[30];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(tenSV, a[i].ten);
        if(strstr(strupr(tenSV), strupr(ten))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    showStudent(arrayFound, found);
}

void tinhDTB(SV &sv) {
    sv.diemTB = (sv.diemHoa + sv.diemLy + sv.diemToan) / 3;
}

void xepLoai(SV &sv) {
    if(sv.diemTB >= 8) strcpy(sv.hocLuc, "Gioi");
    else if(sv.diemTB >= 6.5) strcpy(sv.hocLuc, "Kha");
    else if(sv.diemTB >= 5) strcpy(sv.hocLuc, "Trung binh");
    else strcpy(sv.hocLuc, "Yeu");
}

void sapxepTheoDTB(SV a[], int n) {
    SV tmp;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i].diemTB > a[j].diemTB) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void sapxepTheoTen(SV a[], int n) {
    SV tmp;
    char tenSV1[30];
    char tenSV2[30];
    for(int i = 0; i < n; i++) {
        strcpy(tenSV1, a[i].ten);
        for(int j = i + 1; j < n; j++) {
            strcpy(tenSV2, a[j].ten);
                if(strcmp(strupr(tenSV1), strupr(tenSV2)) > 0) {
                    tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
        }
    }
}

void showStudent(SV a[], int n) {
    printLine(100);
    cout << "\n STT\tID\tHo va ten\tGioi Tinh\tTuoi\tToan\tLy\tHoa\tDiem TB\tHoc luc";
    for(int i = 0; i < n; i++) {
        // in svien thứ i ra màn hình
        printf("\n %d", i + 1);
        printf("\t %d", a[i].id);
        printf("\t %s", a[i].ten);
        printf("\t\t%s", a[i].gioiTinh);
        printf("\t\t%d", a[i].tuoi);
        printf("\t%.2f\t%.2f\t%.2f", a[i].diemToan, a[i].diemLy, a[i].diemHoa);
        printf("\t%.2f", a[i].diemTB);
        printf("\t%s", a[i].hocLuc);
    }    
    printLine(100);
}

int docFile(SV a[], char fileName[]) {
    FILE * fp;
    int i = 0;
    fp = fopen (fileName, "r");
    cout << "Chuan bi doc file: "; puts(fileName);
    // doc thong tin sinh vien
    while (fscanf(fp, "%5d%30s%5s%5d%10f%10f%10f%10f%10s\n", &a[i].id, &a[i].ten, 
            &a[i].gioiTinh, &a[i].tuoi, &a[i].diemToan, &a[i].diemLy, &a[i].diemHoa, 
            &a[i].diemTB, &a[i].hocLuc) != EOF) {
       i++;
       cout << " Doc ban ghi thu: " << i << endl;
    }
    cout << " So luong sinh vien co san trong file la: " << i << endl;
    cout << endl;
    // tra ve so luong sinh vien duoc doc tu file
    return i;
    fclose (fp);
}

void ghiFile(SV a[], int n, char fileName[]) {
    FILE * fp;
    fp = fopen (fileName,"w");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%5d%30s%5s%5d%10f%10f%10f%10f%10s\n", a[i].id, a[i].ten,a[i].gioiTinh, 
            a[i].tuoi, a[i].diemToan, a[i].diemLy, a[i].diemHoa, a[i].diemTB, a[i].hocLuc);
    }
    fclose (fp);
}

void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc ...";
    getch();
    system("cls");
}

int main() {
    int key; // giá trị bạn nhập để tùy chọn trong menu
    char fileName[] = "sinhvien.txt";
    SV arraySV[MAX]; // lưu trưc một mảng các struct sinh viên
    int soluongSV = 0; // số lượng svien hiện tại của mảng arraySV
    int idCount = 0; // biến đếm id tự động tăng của svien

    soluongSV = docFile(arraySV, fileName);
    idCount = idLonNhat(arraySV, soluongSV);

    while(true) {
        cout << "CHUONG TRINH QUAN LY SINH VIEN C/C++\n";
        cout << "***********************MENU*********************************\n";
        cout << "**   1. Them sinh vien.                                   **\n";
        cout << "**   2. Cap nhat thong tin sinh vien boi ID.              **\n";
        cout << "**   3. Xoa sinh vien boi ID.                             **\n";
        cout << "**   4. Tim kiem sinh vien theo ten.                      **\n";
        cout << "**   5. Sap xep sinh vien theo diem trung binh (GPA)      **\n";
        cout << "**   6. Sap xep sinh vien theo ten.                       **\n";
        cout << "**   7. Hien thi danh sach sinh vien.                     **\n";
        cout << "**   8. Ghi danh sach sinh vien vao file                  **\n";
        cout << "**   0. Thoat                                             **\n";
        cout << "************************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch(key) {
            case 1:
                cout << "\n 1. Them sinh vien.";
                idCount++;
                nhapSV(arraySV, idCount, soluongSV);
                printf("\n Them sinh vien thanh cong!");
                soluongSV++;
                pressAnyKey();
                break;
            case 2:
                if(soluongSV > 0) {
                    int id;
                    cout << "\n2. Cap nhat thong tin sinh vien. ";
                    cout << "\n Nhap ID: "; cin >> id;
                    capNhatSV(arraySV, id, soluongSV);
                }else{
                    cout << "\nDanh sach sinh vien trong!";
                }
                pressAnyKey();
                break;
            case 3:
                if(soluongSV > 0) {
                    int id;
                    cout << "\n3. Xoa sinh vien.";
                    cout << "\n Nhap ID: "; cin >> id;
                    if (xoaTheoID(arraySV, id, soluongSV) == 1) {
                        printf("\nSinh vien co id = %d da bi xoa.", &id);
                        soluongSV--;
                    }
                }else{
                    cout << "\nDanh sach sinh vien trong!";
                }
                pressAnyKey();
                break;
            case 4:
                if(soluongSV > 0) {
                    cout << "\n4. Tim kiem sinh vien theo ten.";
                    char strTen[30];
                    cout << "\nNhap ten de tim kiem: "; fflush(stdin); gets(strTen);
                    timKiemTheoTen(arraySV, strTen, soluongSV);
                }else{
                    cout << "\nDanh sach sinh vien trong!";
                }
                pressAnyKey();
                break;
            case 5:
                if(soluongSV > 0) {
                    cout << "\n5. Sap xep sinh vien theo diem trung binh (GPA).";
                    sapxepTheoDTB(arraySV, soluongSV);
                    showStudent(arraySV, soluongSV);
                }else{
                    cout << "\nDanh sach sinh vien trong!";
                }
                pressAnyKey();
                break;
            case 6:
                if(soluongSV > 0) {
                    cout << "\n6. Sap xep sinh vien theo ten.";
                    sapxepTheoTen(arraySV, soluongSV);
                    showStudent(arraySV, soluongSV);
                } else {
                    cout << "\nDanh sach sinh vien trong!";
                }
                pressAnyKey();
                break;
            case 7:
                if(soluongSV > 0){
                    cout << "\n7. Hien thi danh sach sinh vien.";
                    showStudent(arraySV, soluongSV);
                }else{
                    cout << "\nDanh sach sinh vien trong!";
                }
                pressAnyKey();
                break;
            case 8:
                if(soluongSV > 0){
                    cout << "\n8. Ghi danh sach sinh vien vao file.";
                    ghiFile(arraySV, soluongSV, fileName);
                }else{
                    cout << "\nDanh sach sinh vien trong!";
                }
                printf("\nGhi danh sach sinh vien vao file %s thanh cong!", fileName);
                pressAnyKey();
                break;
            case 0:
                cout << "\nBan da chon thoat chuong trinh!";
                getch();
                return 0;
            default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                pressAnyKey();
                break;
        }
    }
}