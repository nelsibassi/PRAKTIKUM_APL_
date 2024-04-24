#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void showMenu() {
    cout << "\nMenu:\n";
    cout << "1. Tambahkan Data\n";
    cout << "2. Lihat Data\n";
    cout << "3. Ubah Data\n";
    cout << "4. Hapus Data\n";
    cout << "5. Sortir Data (Huruf Descending)\n";
    cout << "6. Sortir Data (Angka Ascending)\n";
    cout << "7. Keluar\n";
    cout << "Pilih menu (1-7): ";
}

void handleMenu(vector<pair<string, int>>* dataList) {
    int choice;
   cin >> choice;

    switch (choice) {
        case 1: {
            pair<string, int> newData;
            string name;
            int taxID;
            cout << "Masukkan Nama: ";
            cin >> name;
            newData.first = name;
            cout << "Masukkan Nomor ID Pajak: ";
            cin >> taxID;
            newData.second = taxID;
            dataList->push_back(newData);
            break;
        }
        case 2: {
            if (dataList->empty()) {
                cout << "Data kosong.\n";
            } else {
                cout << "\nData Pajak:\n";
                for (const auto& data : *dataList) {
                    cout << "Nama: " << data.first << ", Nomor ID Pajak: " << data.second << "\n";
                }
            }
            break;
        }
        case 3: {
            int index;
            cout << "Masukkan indeks data yang ingin diubah: ";
            cin >> index;
            if (index >= 0 && index < dataList->size()) {
                string name;
                int taxID;
                cout << "Masukkan Nama baru: ";
                cin >> name;
                (*dataList)[index].first = name;
                cout << "Masukkan Nomor ID Pajak baru: ";
                cin >> taxID;
                (*dataList)[index].second = taxID;
            } else {
                cout << "Indeks tidak valid.\n";
            }
            break;
        }
        case 4: {
            int index;
            cout << "Masukkan indeks data yang ingin dihapus: ";
            cin >> index;
            if (index >= 0 && index < dataList->size()) {
                dataList->erase(dataList->begin() + index);
            } else {
                cout << "Indeks tidak valid.\n";
            }
            break;
        }
        case 5: {
            sort(dataList->begin(), dataList->end(), [](const auto& a, const auto& b) {
                return a.first > b.first; // Huruf Descending
            });
            cout << "Data berhasil diurutkan (Huruf Descending).\n";
            break;
        }
        case 6: {
            sort(dataList->begin(), dataList->end(), [](const auto& a, const auto& b) {
                return a.second < b.second; // Angka Ascending
            });
            cout << "Data berhasil diurutkan (Angka Ascending).\n";
            break;
        }
        case 7:
            cout << "Terima kasih!\n";
            return;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
    }

    showMenu();
    handleMenu(dataList);
}

int main() {
    vector<pair<string, int>> dataList;
    string username, password;
    int attempts = 0;

    do {
        cout << "Masukkan Username: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;

        if (username != "NELSI" || password != "120") {
            attempts++;
           cout << "Username atau password salah. Silakan coba lagi.\n";
        }
        if (attempts == 3) {
           cout << "Anda telah melebihi batas percobaan. Program berhenti.\n";
            return 0;
        }
    } while (username != "NELSI" || password != "120");

    showMenu();
    handleMenu(&dataList);
    return 0;
}