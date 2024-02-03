/*
    * Classes model real world data better than structures, extension of structures
    * Use structures when security of internal data not a concern, or when methods not needed.
    * Structures in C++ are 'typedef'ed by default.
    * Limitations of structures : 1. Members are public.
                                  2. No methods.
    * Class Members = Methods + Properties.
    * Memory Diagram of Objects:
                Common : f1, f2, f3 --> methods get common memory as common for all objects.
                obj1     : i, j, k    --> properties get separate memory as not common for all objects.
                obj2     : i, j, k
                obj3     : i, j, k
*/
#include <iostream>
#include <string>
using namespace std;

/* 
    * Defining a class 'Employee'.
    * Private and public members and methods can be clubbed separately.
        * Private : Only class methods can access data.
        * Public : All methods can access data.
*/
class Employee{

    // Variables and functions can only be accessed by class methods.
    private:
        int a, b, c;

    // Variables and functions can be accessed by all methods or functions.
    public:
        int d, e;

        // Methods can be declared or written here.
        void setData(int a, int b, int c);

        void getData(){
            cout << a << b << c << d << e << "\n";
        }
} harry, rohan, lovish; // Objects can be declared right after class declaration

// Member methods can be written outside class scope, '::' is called the scope resolution operator.
void Employee::setData(int a1, int b1, int c1){
    a = a1;
    b = b1;
    c = c1;
}

class Binary{
    
    // Members are private by default.
    // private:
        string s;

    private:
        void chk_bin(void);     // Function can be accessed only inside class scope.

    public:
        void read(void);        // Void as no arguments to function.
        void ones_comp(void);
        void display(void);
};
// Member methods of class 'Binary'.
void Binary::read(void){
    cout << "Enter a Binary Number:" << "\n";
    cin >> s;
}
void Binary::chk_bin(void){
    for (int i = 0; i < s.length(); i++)
        if (s.at(i) != '0' && s.at(i) != '1'){
            cout << "Incorrect Binary Format" << "\n";
            exit(0);            // Terminates function with exit code 0.
        }
    cout << "Correct Binary Format" << "\n";
}
void Binary::ones_comp(void){
    chk_bin(); // Nesting of member methods, maximizes encapsulation.
    for (int i = 0; i < s.length(); i++)
        if (s.at(i) == '0')
            s.at(i) = '1';
        else
            s.at(i) = '0';
}
void Binary::display(void){
    cout << "Your Binary Number is:" << "\n";
    cout << s << "\n";
}

class Shop{
    private:
        int item_id[100];
        int item_price[100];
        int counter;
    
    public:
        void initCounter(void){
            counter = 0;
        }
        void setPrice(void);
        void displayPrice(void);
};
void Shop::setPrice(void){
    cout << "Enter ID of your item " << counter + 1 << " : " << "\n";
    cin >> item_id[counter];
    cout << "Enter price of your item: " << "\n";
    cin >> item_price[counter];
    counter++;
}
void Shop::displayPrice(void){
    for (int i = 0; i < counter; i++)
        cout << item_id[i] << " " << item_price[i] << "\n";
}

class Work{

    int id;
    static int count; // Defining a class variable, common to all objects defined, static data member.

    public:
        void setData(void){
            cin >> id;
            count++;
        }
        void getData(void){
            cout << id << " " << count << "\n";
        }
        // Static functions only have access to other static functions or variables.
        static void getCount(void){
            cout << count << "\n";
        }
};

int Work::count = 100; // Defaults to 0 on declaration, can be initialized.

int main(){
    
    // Object of class 'Employee'.
    Employee me;                
    // Public variables can be accessed outside scope of class.
    me.d = 10;
    me.e = 11;

    me.setData(4, 5, 6);
    me.getData();

    // Object of class 'Binary'.
    Binary bin;
    bin.read();
    bin.display();
    bin.ones_comp();
    bin.display();

    // Object of class 'Shop'
    Shop dukaan;
    dukaan.initCounter();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.displayPrice();

    // Object of class 'Work'
    Work w1, w2, w3;
    w1.setData();
    w1.getData();
    Work::getCount();   // Acessing static method.
    w2.setData();
    w2.getData();
    Work::getCount();
    w3.setData();
    w3.getData();
    Work::getCount();

    return 0;
}