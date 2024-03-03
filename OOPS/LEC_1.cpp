/*
    * What is Object Oriented Programming (OOP)?
        - Programming paradigm that works around objects. 
        - Objects have 1. States / Properties 2. Behaviours.
        - Want to bring programming close to real world entities.
        - Increases extensibility, manageability, readability.
        - Class is an user defined datatype (object being instance of class)
        - It is a template (on object creation the instance of this template is made)
        - Class is a blueprint and an object realizes this blueprint.
        - An empty class will occupies 1 byte for identification.
        - Objects can be instanciated outside the class, remember to include the cpp file path.
        - Access public properties / data members using '.' operator.
    * Access Modifiers: 
        - Public - Private - Protected (private by default)
    * Getters and Setters can be used to fetch and manipulate the private class members.
    * 
*/

#include <iostream>
using namespace std;

class Hero {

    // States / properties.
    public:
        int health;

        Hero(Hero &hero){
            this->health = hero.health;
        }

};

int main() {

    // Creation of object (instance of class).
    Hero h1;
    cout << "size: " << sizeof(h1) << "\n"; // Garbage value inside h1.

    return 0;
}