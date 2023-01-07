#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QString>

class Item : public QObject {
protected:
    Q_OBJECT
    Q_PROPERTY(QString QitemName READ getQStringName CONSTANT)

    int m_x;
    int m_y;
    std::string m_name;
    std::string m_description;
public:
    Item(int x, int y, std::string name, std::string description);
    int getX();
    int getY();
    QString getQStringName() const;
    std::string getName();
    std::string getDescription();
};

#endif // ITEM_H
