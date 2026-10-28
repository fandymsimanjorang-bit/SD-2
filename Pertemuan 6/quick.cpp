#include <iostream>
using namespace std;

// TODO : fungsi untuk menukar dua buah elemen
void swap(int &a, int &b){
    int tamp = a;
    a = b;
    b = tamp;
}

// TODO : fungsi untuk memilih pivot (KAPTEN DI KANAN)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];// pivot dari ujung kanan
    int i = low -1;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++; // majukan batas kelompok kiri
            swap(arr[i], arr[j]); // pindahkan ke kiri
        }
    }
    swap(arr[i + 1], arr[high]);
    return(i + 1);
}

// TODO : fungsi rekursif 
void quickSort (int arr[], int low, int high) {
    if(low < high){
        int pivotIndex = partition(arr, low, high);

        // panggil quickShort untuk kel kiri dan kanan pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];
    cout << "Masukkan elemen-elemen data: \n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Panggil fungsi Quick Sort
    quickSort(data, 0, n - 1);

    cout << "Data setelah diurutkan dari terkecil hingga terbesar:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}