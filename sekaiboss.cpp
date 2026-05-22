// типы данных
// bool
// float - с плавающей точкой
// int
// string
// char - символ или маленькое число
// long long
// double -большое число с плавающей точкой
// size_t - размер контейнера (индекс в памяти)
// int32_t - точный 32 битный int
// uint32_t - usigned то есть беззнаковый (не отрицательный)
// int64_t - точный 64 битный int

// отличие float от double
// float  - занимает 4 байта в дабл 8 байт
// занимает и выделяет больше памяти
// int: hp, кол-во предметов, уровней, очков опыта, индексов
// float : координаты, скорости, дельта времени, множитель урона, плавной анимации
// double : используем там же где и флоат, но когда значения нужно точнее или для обработки


#include <iostream>

// ередача парваметров функций
// Передача по значению
using namespace std;

void TakeDamage(int hp, int damage)
{
    hp = hp- damage;
}
// здесь хп копируется 
//Если вызвать
// int playerHp = 100;
// TakeDamage(playerHp, 30);
// То хп отниметься но playerHp останеться 100

// Передача по ссылке
// void TakeDamage(int& hp, int damage)
// {
//     hp = hp - damage;
// }
// int$ hp значает:
// hp - это ссылка на оригинальную переменную

struct  CharacterStats
{
    string name;
    int hp;
    int maxHp;
    int damage;
};

// Передача по конст-ссылке
// Подходит когда объекты передаются большими, но функция не должна их менять
void PrintPlayer(const CharacterStats& stats)
{
    cout << stats.name << endl;
    cout << stats.hp << "/" << stats.maxHp << endl;
    cout << stats.damage << endl;
}
// const - запрещает менять объект 
// & - позволяет не копировать объект


// Передача ччерез указатель
// Указатель похож на ссылку, но он может быть пустым(nullptr)
// null ptr - Pointer (указатель)

// void Heal(int* hp, int amount)
// {
//     Функция при нимает адрес переменной hp 
// }

void HealByPointer(int* hp, int amount, int maxHp)
{
    if (hp == nullptr)
    { // Проверяет не пустой ли указатель(найден ли адрес)
        return;
    }
    *hp = *hp + amount; // Разыменование (меняем оригинальное значение)
    
    if (*hp > maxHp)
    {
        *hp = maxHp;
    }
}
int CalculateDamage(int baseDamage, float multiplier, int armor)
{
    float afterMultiplier = baseDamage * multiplier;
    float afterArmor = afterMultiplier - armor;
    if (afterArmor < 0.0f)
    {
        afterArmor = 0.0f;
    }
    return static_cast<int>(round(afterArmor));
}
int main()
{
    CharacterStats oleg{"oleg", 50, 100, 20};
    PrintPlayer(oleg);
    int playerHP = 50;
    int maxHP = 100;
    
    HealByPointer(&playerHP, 50, maxHP);// Передаем адрес player hp через оператор &
    
    cout << "playerHP" << ":" << playerHP << endl;
    
    // &playerHp - это адрес переменной
    // hp* - это указатель на значение по этому адресу
    
    int baseDamage = 40;     
    float critMultiplier = 1.5f; 
    int enemyArmor = 20;      

    int finalDamage = CalculateDamage(baseDamage, critMultiplier, enemyArmor);

    cout << "Final Damage: " << finalDamage << endl;

    return 0;
}