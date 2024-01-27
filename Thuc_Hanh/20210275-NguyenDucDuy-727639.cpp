#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#define MAX 100

using namespace std;

struct DangVien {
    int soTheDV;
    char tenDangVien[30];
    int ngay, thang, nam;
    int namVaoDang;
    char chucVuDang[30];
    float luong;
    float dangPhi;
    float tienPhuCap;
    float phaiDong;
};

typedef DangVien DV;

struct ChiBo {
    char tenCB[30];
    char diaChi[30];
    int soDangVien;
    float tongLuong;
    float tongDangPhiThu;
    float chiBoGiuLai;
    float nopCapTren; 
    float tongTroCapChucVu;
    DV dangViens[MAX];
};

typedef ChiBo CB;

void nhapDangVien(DV &dv) {
    cout << "\n\tSo the: "; cin >> dv.soTheDV;
    cout << endl;
    cout << "\tTen Dang vien: "; fflush(stdin); gets(dv.tenDangVien);
    cout << endl;
    cout << "\tNgay vao dang: \n";
    cout << "\tNgay: "; cin >> dv.ngay;
    cout << "\tThang: "; cin >> dv.thang;
    cout << "\tNam: "; cin >> dv.nam;
    cout << endl;
    cout << "\tLuong: "; cin >> dv.luong;
    cout << endl;
    cout << "\tChuc vu: "; fflush(stdin); gets(dv.chucVuDang);
    cout << endl;
    dv.dangPhi = 0.01 * dv.luong;
    string str = dv.chucVuDang;
    if(str == "BiThu") {
        dv.tienPhuCap = 0.05 * dv.luong;
    } else if(str == "PBThu") {
        dv.tienPhuCap = 0.025 * dv.luong;
    } else if(str == "Uyvien") {
        dv.tienPhuCap = 0.015 * dv.luong;
    } else dv.tienPhuCap = 0;
}

void nhapChiBo(CB &cb) {
    cout << "\nTen Chi bo: "; fflush(stdin); gets(cb.tenCB);
    cout << endl;
    cout << "So Dang vien: "; cin >> cb.soDangVien;
    cout << endl;
    cout << "Nhap danh sach Dang vien: \n";
    for(int i = 0; i < cb.soDangVien; i++) {
        cout << "Dang vien thu " << i + 1;
        nhapDangVien(cb.dangViens[i]);
    }
    for(int i = 0; i < cb.soDangVien; i++) {
        cb.tongLuong += cb.dangViens[i].luong;
        cb.tongDangPhiThu += cb.dangViens[i].dangPhi;
        cb.tongTroCapChucVu += cb.dangViens[i].tienPhuCap;
    }
    cb.chiBoGiuLai = 0.7 * cb.tongDangPhiThu;
    cb.nopCapTren = 0.3 * cb.tongDangPhiThu;
}

void inDanhSachChiBo(CB chibos[], int n) {
    
    float tongLuongCacChiBo;
    float dangPhiThuDuoc;
    float nopCapTren;
    for(int i = 0; i < n; i++) {
        tongLuongCacChiBo += chibos[i].tongLuong;
        dangPhiThuDuoc += chibos[i].tongDangPhiThu;
        nopCapTren += chibos[i].nopCapTren;
        cout << "-----------------------------------------------------------------------------------------------";
        printf("\nTen Chi bo: %s", chibos[i].tenCB);
        printf("\nSo Dang vien: %d", chibos[i].soDangVien);
        printf("\nTong luong: %.0f", chibos[i].tongLuong);
        printf("\nTong thu Dang phi: %.2f", chibos[i].tongDangPhiThu);
        printf("\nTong nop DP Cap tren: %.3f", chibos[i].nopCapTren);
        printf("\nTong tro cap chuc vu: %.3f", chibos[i].tongTroCapChucVu);
        cout << "\nBang Bang Thu Dang Phi: \n";
        cout<<left<<setw(10)<<"sothe"
        <<left<<setw(20)<<"HotenDV"
        <<left<<setw(15)<<"Ngayvaodang"
        <<left<<setw(10)<<"Tuoidang"
        <<left<<setw(10)<<"Chucvu"
        <<left<<setw(10)<<"Trocap"
        <<left<<setw(10)<<"Luong"
        <<left<<setw(10)<<"DangPhi"<<endl;
        for(int j = 0; j < chibos[i].soDangVien; j++) {
            printf("\n %-9d", chibos[i].dangViens[j].soTheDV);
            printf("%-14s", chibos[i].dangViens[j].tenDangVien);
            printf("      %d-%d-%-10d", chibos[i].dangViens[j].ngay, chibos[i].dangViens[j].thang, chibos[i].dangViens[j].nam);
            printf("%-10d", 2022 - chibos[i].dangViens[j].nam);
            printf("%-10s", chibos[i].dangViens[j].chucVuDang);
            printf("%-10.3f", chibos[i].dangViens[j].tienPhuCap);
            printf("%-10.0f", chibos[i].dangViens[j].luong);
            printf("%-10.2f", chibos[i].dangViens[j].dangPhi);
            cout << endl;
        }
    }
    cout << "\nTong luong cac chi bo: " << tongLuongCacChiBo;
    cout << "\nTong Dang phi thu duoc: " << dangPhiThuDuoc;
    cout << "\nTong nop cap tren: " << nopCapTren;
}

void pressAnyKey() {
    cout << "\nBam phim bat ky de tiep tuc ...";
    getch();
    system("cls");
}

int main() {
    int key;
    CB chiBos[MAX];
    int n;
    cout << "Vu Thi Thanh Hoa - 20210356 - 727639 - 2022.2 - IT3040: \n";
    cout << "Nhap so chi bo: "; cin >> n;
    
    while(true) {
        cout << "Vu Thi Thanh Hoa - 20210356 - 727639 - 2022.2 - IT3040: \n";
        cout << "**     CHUONG TRINH QUAN LY CHi BO - DANG VIEN     **\n";
        cout << "********************MENU*****************************\n";
        cout << "**     1. Nhap cac Chi bo                          **\n";
        cout << "**     2. In ket qua ds Chi bo Dang vien           **\n";
        cout << "**     0. Thoat                                    **\n";
        cout << "*****************************************************\n";
        cout << "Nhap lua chon: ";
        cin >> key;

        switch(key) {
            case 1:
                cout << "\nBan da chon nhap danh sach cac chi bo";
                for(int i = 0; i < n; i++) {
                    printf("\nNhap thong tin chi bo thu %d", i + 1);
                    nhapChiBo(chiBos[i]);
                }
                pressAnyKey();
                break;
            case 2:
                cout << "\nBan da chon xuat DS chi bo";
                cout << endl;
                inDanhSachChiBo(chiBos, n);
                cout << endl;
                cout << "-----------------------------------------------------------------------------------------------";
                cout << endl;
                pressAnyKey();
                break;
            case 0: 
                cout << "\nBan da thoat chuong trinh";
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