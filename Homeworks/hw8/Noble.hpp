/*
hw 08 - More on Inheritanace
Nobles battle simulation
Declares hierarchy
*/

#include <string>
#include <vector>

#ifndef WARRIORCRAFT_NOBLE_H
#define WARRIORCRAFT_NOBLE_H
namespace WarriorCraft {
    //Forward declaration
    class Protector;
    
//Noble class
    class Noble {
    public:
        //Noble constructor
        Noble(const std::string& name, double strength = 0);
        
        //Getters and setters
        const std::string& getName() const;
        bool isDeadOrAlive() const;
        double getStrength() const;
        
        //Battle method
        void battle(Noble& other);
        
        friend std::ostream& operator<<(std::ostream& os, const Noble& noble);
    protected:
        //Pure virtual methods
        virtual std::ostream& printer(std::ostream& os) const = 0;
        virtual void battleCry() const = 0;
        virtual void battleHelper(double ratio);
        
        //Setters
        void setStrength(double strength);
    private:
        
        //Data members
        std::string name;
        double strength;
        bool aliveStatus;
    };

    class Lord: public Noble {
    public:
        //Lord constructor
        Lord(const std::string& name);
        //Hiring and Firing method
        bool hires(Protector& protector);
        bool fires(Protector& protector, bool runaway = false);
        
    private:
        
        //Battle cry method
        void battleCry() const;
        void battleHelper(double ratio);
        
        //printing method
        std::ostream& printer(std::ostream& os) const;
        //Warriors
        std::vector<Protector*> warriors;
    };

    class PersonWithStrengthToFight: public Noble {
    public:
        
        PersonWithStrengthToFight(const std::string& name, double strength);
    private:
        
        void battleCry() const;
        std::ostream& printer(std::ostream& os) const;
    };
}
#endif
