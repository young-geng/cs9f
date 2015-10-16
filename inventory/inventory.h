#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include <utility>
#include <map>

typedef std::pair<std::string, int> Entry;

class Inventory {
 public:
    Inventory ();
    void Update (std::string item, int amount);
    std::vector<Entry> ListByName ();
    std::vector<Entry> ListByQuantity ();
 private:
    std::map<std::string, int> table;
};

#endif