#include <iostream>
#include <limits>
#include <vector>

using namespace std;

enum class PieceType { King, Queen, Rook, Pawn };

void Sort(std::vector<int> &arr)
{
    int i, j;
    auto n = arr.size();

    for (i = 0; i < n - 1; ++i) {
        cout << "i: " << i << "\n";
        for (j = 0; j < n - i - 1; ++j) {
            cout << "j: " << j << " ";
            if(arr.at(j) > arr.at(j + 1))
            {
                cout << "swap\n";
                swap(arr.at(j), arr.at(j + 1));
            }
        }
    }
}

int main() {
    std::vector<int> array { 5, 6, 2, 7, 12, 85, 25, 7, 7, 3, 4, 4, 6, 65 , 1};
    Sort(array);
    for (size_t i = 0; i < array.size(); ++i) {
        cout << array.at(i) << ", ";
    }
    cout << endl;

    return 0;
}
