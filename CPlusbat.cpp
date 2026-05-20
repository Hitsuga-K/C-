//  Типы данных 
// bool
// float - плавающая точка
// int
// string
// char - символы
// long long
// double - больше диапозон
// size_t - азмер контейнера
// int32_t - точный 32 битный инт
// uint32_t - unsigned то есть беззнаковый
// unt64_t - тончый 64 битный инт

// отличие float от double
// float - занимает 4 байта а дабл 8 байт
// занимет и выделяет больше памяти
// int: hp, кол-во предметов, уровней, очков опыта, индексов
// float : координаты, скорости, дельта времени, множитель урона, плавной анимации
// double: используем там же где и флоат, но когда значения нужно точнее, или дшля обработки не в реал-тайм
// Беззнаковый тип:
// Кажется удобным, то есть переменная не может быть отрицательной, но:
// unsigned int gold = 0;
// gold = gold - 1;
// Если unsigned тип уходит в минус, то он перекручивается в огромное число
// инт: 0 -> 2 147 483 647
// Так же мы не можем класть инт в число uint - даже если ноно положительное
// gold = max(0, golod - cost)

// static_cost -> конвертация типа данных, что и .toInt()
// int damage = static_cast<int>(baseDamage * multiplier);
// Явная смена типа данных

#include <iostream>
// i -> int
// o -> out
// stream - поток
#include <limits>
// Для просмотра границ типов данных 
#include <cstdint>
// подключаем фиксированные типа данных (int32_t or int64_t)
using namespace std;
#include <locale>
#include <string>
#include <vector>
// int main()
// {
//     setlocale(LC_ALL, "Russian");
//     cout << "bool:" << sizeof(bool) << "байт" << endl;
//     cout << "char:" << sizeof(char) << "байт" << endl;
//     cout << "int:" << sizeof(int) << "байт" << endl;
//     cout << "float:" << sizeof(float) << "байт" << endl;
//     cout << "double:" << sizeof(double) << "байт" << endl;
//     cout << "int32_t:" << sizeof(int32_t) << "байт" << endl;
//     cout << "int64_t:" << sizeof(int64_t) << "байт" << endl;
//     cout << endl;
//     cout << "Лимиты тд:"<< endl;
//     cout << "int min" << numeric_limits<int>::min() << endl;
//     cout << "int max" << numeric_limits<int>::max() << endl;
//     cout << "float min" << numeric_limits<float>::min() << endl;
//     cout << "float max" << numeric_limits<float>::max() << endl;
//     cout << "double min" << numeric_limits<double>::min() << endl;
//     cout << "double max" << numeric_limits<double>::max() << endl;
//     return 0;
// }
enum class ItemType
{
    Weapon,
    Armor,
    Potion
};
// data class -> struct
struct Item
{
    string id;
    string name;
    ItemType type;
    int maxStack;
};

struct  ItemStack
{
    Item item;
    int count;
};

string itemTypeToText(ItemType type)
{
    switch (type)
    {
        case ItemType::Weapon: return "Weapon";
        case ItemType::Armor: return "Armor";
        case ItemType::Potion: return "Potion";
    }
}

void PrintStack( const ItemStack& stack)
{
    cout << stack.item.name;
    cout << "x" << stack.count;
    cout << "[" << itemTypeToText(stack.item.type) << "]";
    cout << endl;
}

int main()
{
    Item potion{"potion_heal", "Healing potion", ItemType::Potion};
    Item sword{"sword", "megaSword" , ItemType::Weapon};
    Item hat{"hat", "hatArmor", ItemType::Armor };

    vector<ItemStack> inventory;
    inventory.push_back(ItemStack{potion, 6});
    inventory.push_back(ItemStack{sword, 1});
    inventory.push_back(ItemStack{hat, 1});

    cout << "inventory: " << endl;
    for (const ItemStack& stack : inventory)
    {
        PrintStack(stack);
    }
    return 0;
}
