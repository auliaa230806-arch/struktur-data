#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class StackList {
private:
    Node* head;

public:
    StackList() {
        head = nullptr;
    }

    bool empty() const {
        return head == nullptr;
    }

    // Push: tambah data tanpa kapasitas tetap
    void push(int nilai) {
        Node* baru = new Node;

        baru->data = nilai;
        baru->next = head;
        head = baru;

        cout << "Data " << nilai
             << " berhasil ditambahkan.\n";
    }

    // Pop: hapus data paling atas
    void pop() {
        if (empty()) {
            cout << "Stack kosong!\n";
            return;
        }

        Node* hapus = head;
        cout << "Data " << hapus->data
             << " berhasil dihapus.\n";

        head = head->next;
        delete hapus;
    }

    // Melihat data paling atas
    void tampilkanTop() const {
        if (empty()) {
            cout << "Stack kosong!\n";
            return;
        }

        cout << "TOP: " << head->data << endl;
    }

    // Menampilkan semua data
    void tampilkan() const {
        if (empty()) {
            cout << "Stack kosong!\n";
            return;
        }

        Node* current = head;

        cout << "TOP -> ";
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr\n";
    }

    // Membebaskan seluruh memori
    ~StackList() {
        while (head != nullptr) {
            Node* hapus = head;
            head = head->next;
            delete hapus;
        }
    }
};

int main() {
    StackList stack;
    int pilihan, nilai;

    do {
        cout << "\n=== STACK LINKED LIST ===\n";
        cout << "1. Push (Tambah Data)\n";
        cout << "2. Pop (Hapus Data)\n";
        cout << "3. Lihat TOP\n";
        cout << "4. Tampilkan Stack\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                stack.push(nilai);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                stack.tampilkanTop();
                break;

            case 4:
                stack.tampilkan();
                break;

            case 0:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}

