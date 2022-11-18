#ifndef ITEM_H
#define ITEM_H

#include <iostream>


class Item{
protected:
    int m_x;
    int m_y;
    std::string m_name;
    std::string m_description;
public:
    Item(int x, int y, std::string name, std::string description);
    int getX();
    int getY();
    std::string getName();
    std::string getDescription();
};

#endif // ITEM_H
