#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QString>

class Item : public QObject {
protected:
    Q_OBJECT
    Q_PROPERTY(QString QitemName READ getQStringName CONSTANT)
    Q_PROPERTY(ItemType itemType READ getItemType CONSTANT)
    Q_PROPERTY(bool itemCorruption READ getItemCorruption NOTIFY itemCorruptionChanged)

    int m_x;
    int m_y;
    std::string m_name;
    std::string m_description;
    bool m_isEquiped;

public:
    enum class ItemType {
        None, Potion, Armor, Weapon
    };
    Q_ENUM(ItemType)

    Item(int x, int y, std::string name, std::string description, bool isEquiped=false);
    int getX();
    int getY();
    bool isEquiped();
    void equip();
    void unEquip();
    QString getQStringName() const;
    QString getQstringDescription() const;
    std::string getName();
    std::string getDescription();
    bool getItemCorruption() const;
    virtual Item::ItemType getItemType() const;

    void setItemCorruption();

protected:
    bool m_itemCorruption;

signals:
    void itemCorruptionChanged();
};

Q_DECLARE_METATYPE(Item::ItemType)

#endif // ITEM_H
