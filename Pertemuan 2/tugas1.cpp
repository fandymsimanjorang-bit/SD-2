#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void tambahAwal(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = head;
    head = baru;
}

void tambahAkhir(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
        return;
    }

    Node* bantu = head;
    while (bantu->next != nullptr) {
        bantu = bantu->next;
    }

    bantu->next = baru;
}

void tambahSetelahNilai(int target, int nilai) {
    Node* bantu = head;

    while (bantu != nullptr && bantu->data != target) {
        bantu = bantu->next;
    }

    if (bantu == nullptr) {
        cout << "Nilai " << target << " tidak ditemukan.\n";
        return;
    }

    Node* baru = new Node;
    baru->data = nilai;
    baru->next = bantu->next;
    bantu->next = baru;
}

void hapusNilai(int nilai) {
    if (head == nullptr) {
        cout << "Linked List kosong.\n";
        return;
    }

    if (head->data == nilai) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        return;
    }

    Node* bantu = head;

    while (bantu->next != nullptr && bantu->next->data != nilai) {
        bantu = bantu->next;
    }

    if (bantu->next == nullptr) {
        cout << "Nilai " << nilai << " tidak ditemukan.\n";
        return;
    }

    Node* hapus = bantu->next;
    bantu->next = hapus->next;
    delete hapus;
}

void tampilkan() {
    Node* bantu = head;

    cout << "Isi Linked List: ";

    while (bantu != nullptr) {
        cout << bantu->data << " -> ";
        bantu = bantu->next;
    }

    cout << "NULL\n";
}

void hapusSemua() {
    while (head != nullptr) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
    }
}

int main() {
    int pilihan, nilai, target;

    do {
        cout << "\n===== MENU SINGLE LINKED LIST =====\n";
        cout << "1. Tambah di awal\n";
        cout << "2. Tambah di akhir\n";
        cout << "3. Tambah setelah nilai tertentu\n";
        cout << "4. Hapus berdasarkan nilai\n";
        cout << "5. Tampilkan Linked List\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahAwal(nilai);
                tampilkan();
                break;

            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahAkhir(nilai);
                tampilkan();
                break;

            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> nilai;
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> target;
                tambahSetelahNilai(target, nilai);
                tampilkan();
                break;

            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilai;
                hapusNilai(nilai);
                tampilkan();
                break;

            case 5:
                tampilkan();
                break;

            case 0:
                break;

            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    hapusSemua();

    return 0;
}
