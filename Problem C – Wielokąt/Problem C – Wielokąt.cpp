#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;
};
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
// Funkcja obliczająca liczbę punktów kratowych wewnątrz wielokąta
long long countLatticePoints(const vector<Point>& polygon) {
    // Inicjalizujemy wartości zgodnie z algorytmem Picka
    long long I = 0; // Liczba wierzchołków wewnątrz wielokąta
    long long B = polygon.size(); // Liczba wierzchołków na granicy wielokąta

    // Iterujemy przez wierzchołki wielokąta
    for (size_t i = 0; i < polygon.size(); ++i) {
        auto p1 = polygon[i];
        auto p2 = polygon[(i + 1) % polygon.size()];

        auto dx = abs(p2.x - p1.x);
        auto dy = abs(p2.y - p1.y);
        auto gcd1 = gcd(dx, dy);

        // Dodajemy liczbę punktów kratowych na aktualnej krawędzi wielokąta
        I += gcd1 - 1;
    }

    // Zwracamy liczbę punktów kratowych wewnątrz wielokąta
    return I;
}

int main() {
    int n;
    cin >> n;

    vector<Point> polygon(n);
    for (int i = 0; i < n; ++i) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    cout << countLatticePoints(polygon) << endl;

    return 0;
}