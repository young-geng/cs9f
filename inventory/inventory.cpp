#include <vector>
#include <string>
#include <utility>
#include <map>
#include <algorithm>

#include "inventory.h"

using namespace std;

bool EntryQuantityLess(const Entry& a, const Entry& b) {
    return a.second < b.second;
}

Inventory::Inventory() {}

void Inventory::Update(string item, int amount) {
    auto iter = table.find(item);
    if (iter == table.end()) {
        table.insert(Entry(item, amount));
    } else {
        Entry new_entry(item, iter->second + amount);
        table.erase(item);
        table.insert(new_entry);
    }
}

vector<Entry> Inventory::ListByName() {
    vector<Entry> v;
    for(auto iter = table.begin(); iter != table.end(); iter++) {
        v.push_back(*iter);
    }
    return v;
}

vector<Entry> Inventory::ListByQuantity() {
    auto v = ListByName();
    sort(v.begin(), v.end(), EntryQuantityLess);
    return v;
}

