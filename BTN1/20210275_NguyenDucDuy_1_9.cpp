// Nguyễn Đức Duy - 20210275
#include<iostream>
using namespace std;

int main(){
    printf("Ho Va Ten: Nguyen Duc Duy\n");
    printf("MSSV: 20210275\n\n");
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i=0; i<n; i++)
        cin >> *(arr + i);

    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++){
            for(int k=i; k<=j; k++)
                cout << *(arr + k) << " ";
            cout << endl;
        }
    
    delete[] arr;
    return 0;
}
// Nguyễn Đức Duy - 20210275