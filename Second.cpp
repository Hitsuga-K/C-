#include <iostream>
#include <cmath>
using namespace std;

int CalculateDamage(int baseDamage, float multiplier, int armor) {
    float afterMultiplier = baseDamage * multiplier;
    float afterArmor = afterMultiplier - armor;
    if (afterArmor < 0.0f) {
        afterArmor = 0.0f;
    }
    return static_cast<int>(round(afterArmor));
}

int main() {
    int baseDamage = 50;
    float critMultiplier = 2.0f;
    int enemyArmor = 30;

    int finalDamage = CalculateDamage(baseDamage, critMultiplier, enemyArmor);

    cout << "Базовый урон: " << baseDamage << endl;
    cout << "Критический множитель: " << critMultiplier << endl;
    cout << "Броня врага: " << enemyArmor << endl;
    cout << "Итоговый урон: " << finalDamage << endl;

    return 0;
}