#include <iostream>
#include <string>
using namespace std;

// Base class
class Character {
protected:
    string characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(string id, string n, int lvl, int hp, string weapon = "None")
        : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}

    virtual void attack() {
        cout << name << " attacks!" << endl;
    }
    
    virtual void defend() {
        cout << name << " defends!" << endl;
    }

    virtual void displayStats() {
        cout << "Character: " << name << " (Level: " << level << ", HP: " << healthPoints << ")" << endl;
    }
};

// Derived classes
class Warrior : public Character {
    int armorStrength;
    int meleeDamage;
public:
    Warrior(string id, string n, int lvl, int hp, int armor, int damage)
        : Character(id, n, lvl, hp, "Sword"), armorStrength(armor), meleeDamage(damage) {}

    void attack() override {
        cout << name << " swings sword with " << meleeDamage << " damage!" << endl;
    }
};

class Mage : public Character {
    int manaPoints;
    int spellPower;
public:
    Mage(string id, string n, int lvl, int hp, int mana, int spell)
        : Character(id, n, lvl, hp, "Staff"), manaPoints(mana), spellPower(spell) {}

    void defend() override {
        cout << name << " casts a magical barrier!" << endl;
    }
};

class Archer : public Character {
    int arrowCount;
    int rangedAccuracy;
public:
    Archer(string id, string n, int lvl, int hp, int arrows, int accuracy)
        : Character(id, n, lvl, hp, "Bow"), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() override {
        cout << name << " shoots an arrow with " << rangedAccuracy << " accuracy!" << endl;
    }
};

class Rogue : public Character {
    int stealthLevel;
    int agility;
public:
    Rogue(string id, string n, int lvl, int hp, int stealth, int agi)
        : Character(id, n, lvl, hp, "Dagger"), stealthLevel(stealth), agility(agi) {}

    void displayStats() override {
        cout << "Rogue " << name << " (Stealth: " << stealthLevel << ", Agility: " << agility << ")" << endl;
    }
};

int main() {
    Warrior warrior("Y1", "Thor", 30, 80, 20, 60);
    Mage mage("R1", "Gandalf", 31, 70, 90, 50);
    Archer archer("T1", "Legolas", 14, 80, 70, 40);
    Rogue rogue("E1", "Ezio", 23, 55, 40, 20);
    warrior.displayStats();
    warrior.attack();
    mage.displayStats();
    mage.defend();
    archer.displayStats();
    archer.attack();
    rogue.displayStats();
    return 0;
}
