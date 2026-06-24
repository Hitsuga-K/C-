#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Enemy {
    string name;
    int hp;
    int armor;
};

int CalculateDamage(int baseDamage, float critMultiplier, int armor) {
    float afterMultiplier = baseDamage * critMultiplier;
    float afterArmor = afterMultiplier - armor;
    if (afterArmor < 0.0f) {
        afterArmor = 0.0f;
    }
    return static_cast<int>(round(afterArmor));
}

void ApplyDamage(Enemy& enemy, int damage) {
    enemy.hp -= damage;
    if (enemy.hp < 0) {
        enemy.hp = 0;
    }
    cout << enemy.name << " получил " << damage << " урона!" << endl;
    cout << "Текущее HP: " << enemy.hp << endl;
}

bool IsEnemyAlive(const Enemy& enemy) {
    return enemy.hp > 0;
}

void PrintEnemyInfo(const Enemy& enemy) {
    cout << "=== Информация о враге ===" << endl;
    cout << "Имя: " << enemy.name << endl;
    cout << "HP: " << enemy.hp << endl;
    cout << "Броня: " << enemy.armor << endl;
    cout << "===========================" << endl;
}

int main() {
    Enemy goblin{"Гоблин", 100, 15};

    PrintEnemyInfo(goblin);
    cout << endl;

    int baseDamage = 45;
    float critMultiplier = 1.8f;

    int finalDamage = CalculateDamage(baseDamage, critMultiplier, goblin.armor);
    cout << "Нанесенный урон: " << finalDamage << endl << endl;

    ApplyDamage(goblin, finalDamage);
    cout << endl;

    if (IsEnemyAlive(goblin)) {
        cout << goblin.name << " все еще жив!" << endl;
    } else {
        cout << goblin.name << " повержен!" << endl;
    }
    cout << endl;

    cout << "Вторая атака!" << endl;
    int secondDamage = CalculateDamage(30, 1.5f, goblin.armor);
    ApplyDamage(goblin, secondDamage);

    if (IsEnemyAlive(goblin)) {
        cout << goblin.name << " все еще жив!" << endl;
    } else {
        cout << goblin.name << " повержен!" << endl;
    }

    return 0;
}