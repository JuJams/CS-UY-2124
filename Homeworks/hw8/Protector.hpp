/*
hw 08 - More on Inheritanace
Nobles battle simulation
Declares protector class hierarchy
*/
#include <string>
#include <vector>

#ifndef WARRIORCRAFT_PROTECTOR_H
#define WARRIORCRAFT_PROTECTOR_H
namespace WarriorCraft {
//Declaration
    class Lord;
//Protector class
    class Protector {
    public:
        //constructor
        //setters and getters
        Protector(const std::string& name, double strength);
                void setStrength(double strength);
        Lord* const getLord() const;
        void setLord(Lord* lord);
        const std::string& getName() const;
        double getNewStrength() const;
        //runaway method
        bool runaway();
        //pure virtual method
        virtual void battleCry() const = 0;
        
        friend std::ostream& operator<<(std::ostream& os, const Protector& protector);
        
    private:
        //data methods
        std::string name;
        double strength;
        bool alive;
        Lord* lord;
    };

//Derived classes
    class Wizard: public Protector {
    public:
        Wizard(const std::string& name, double strength);
        void battleCry() const;
    };

    class Warrior: public Protector {
    public:
        Warrior(const std::string& name, double strength);
    };

    class Archer: public Warrior {
    public:
        Archer(const std::string& name, double strength);
        void battleCry() const;
    };

    class Swordsman: public Warrior {
    public:
        Swordsman(const std::string& name, double strength);
        void battleCry() const;
    };
}
#endif //WARRIORCRAFT_PROTECTOR_H

