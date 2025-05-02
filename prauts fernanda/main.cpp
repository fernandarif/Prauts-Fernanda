#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

pair<int, vector<int>> knapsackBruteForce(const vector<int>& weights, const vector<int>& values, int capacity) {
    int n = weights.size();
    int max_value = 0;
    vector<int> best_combination;

    for (int i = 0; i < (1 << n); ++i) {
        int total_weight = 0, total_value = 0;
        vector<int> current_combination;

        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                total_weight += weights[j];
                total_value += values[j];
                current_combination.push_back(j);
            }
        }

        if (total_weight <= capacity && total_value > max_value) {
            max_value = total_value;
            best_combination = current_combination;
        }
    }

    return {max_value, best_combination};
}

int main() {
    cout << "==================================" << endl;
    cout << "TUGAS PRAUTS KNAPSACK PROBLEM" << endl;
    cout << "==================================" << endl;
    cout << "Nama  : FERNANDA RIFKY SYAHRIAL" << endl;
    cout << "Nim   : 23533738" << endl;
    cout << "Kelas : 4-B" << endl;
    cout << "UNIVERSITAS MUHAMMADIYAH PONOROGO" << endl;
    cout << "==================================" << endl;

    int n, capacity;

    cout << "Masukkan jumlah item: ";
    cin >> n;

    vector<string> names(n);
    vector<int> weights(n), values(n);

    for (int i = 0; i < n; ++i) {
        cout << "\nItem ke-" << i + 1 << ":\n";
        cout << "  Nama  : ";
        cin >> ws;
        getline(cin, names[i]);
        cout << "  Berat : ";
        cin >> weights[i];
        cout << "  Nilai : ";
        cin >> values[i];
    }

    cout << "\nMasukkan kapasitas maksimum knapsack: ";
    cin >> capacity;

    pair<int, vector<int>> result = knapsackBruteForce(weights, values, capacity);
    int max_value = result.first;
    vector<int> best_combination = result.second;

    cout << "\nNilai maksimum yang dapat diperoleh: " << max_value << endl;

    if (max_value == 0) {
        cout << "==> Kapasitas terlalu kecil.\n";
        cout << "==> Tidak ada item yang dapat dimasukkan ke dalam knapsack.\n";
    } else {
        cout << "==> Terdapat item yang sesuai dengan kapasitas knapsack.\n";
        cout << "\nItem yang dipilih:\n";
        for (int idx : best_combination) {
            cout << "  - " << names[idx]
                 << " (Berat: " << weights[idx]
                 << ", Nilai: " << values[idx] << ")\n";
        }
    }

    return 0;
}
