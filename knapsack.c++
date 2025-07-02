#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Item {
public:
    int value, weight;
    Item(int v, int w) {
        value = v;
        weight = w;
    }
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items;

    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; ++i) {
        int value, weight;
        cin >> value >> weight;
        items.push_back(Item(value, weight));
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (Item item : items) {
        if (capacity >= item.weight) {
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += item.value * ((double)capacity / item.weight);
            break;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Maximum value: " << totalValue << endl;

    return 0;
}
