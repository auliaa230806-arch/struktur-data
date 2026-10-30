#include <iostream>
using namespace std;

// Membuat struktur Node
struct Node {
    int data;
    Node* next;
};

// Membuat class Stack
class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() {
        top = nullptr;
    }

    // Menambahkan data (Push)
    void push(int nilai) {
        Node* baru = new Node;
        baru->data = nilai;
        baru->next = top;
        top = baru;

        cout << nilai << " berhasil ditambahkan\n";
    }

    // Menghapus data paling atas (Pop)
    void pop() {
        if (top == nullptr) {
            cout << "Stack kosong!\n";
            return;
        }

        Node* hapus = top;
        cout << "Data yang dihapus: " << top->data << endl;

        top = top->next;
        delete hapus;
    }

    // Melihat data paling atas (Top)
    void tampilTop() {
        if (top == nullptr) {
            cout << "Stack kosong!\n";
        } else {
            cout << "Data paling atas: " << top->data << endl;
        }
    }

    // Menampilkan seluruh isi Stack
    void tampil() {
        if (top == nullptr) {
            cout << "Stack kosong!\n";
            return;
        }

        Node* bantu = top;

        cout << "Isi Stack (TOP ke bawah): ";
        while (bantu != nullptr) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }

        cout << endl;
    }

    // Destructor
    ~Stack() {
        while (top != nullptr) {
            Node* hapus = top;
            top = top->next;
            delete hapus;
        }
    }
};

// Fungsi utama
int main() {
    Stack s;
    int pilihan, nilai;

    do {
        cout << "\n===== PROGRAM STACK LINKED LIST =====\n";
        cout << "1. Push (Tambah Data)\n";
        cout << "2. Pop (Hapus Data)\n";
        cout << "3. Tampilkan Stack\n";
        cout << "4. Lihat TOP\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                s.push(nilai);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.tampil();
                break;

            case 4:
                s.tampilTop();
                break;

            case 5:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 5);

    return 0;
}