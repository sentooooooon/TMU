#include<iostream>
#include<string>
using namespace std;

class character{
    private:
    string name_;
    public:
    character(string name) : name_(name) {}

    virtual void print_info() const = 0;
};

class Archer : public character{
    private:
    int hp = 100;
    int attack = 30;
    string job = "Archer";
    public:
    Archer(string name) : character(name) {}
    void print_info() const override{
        cout << "job :" << job << endl;
        cout << "hp :" << hp << endl;
        cout << "attack :" << attack << endl;
    }
};

class Warrior : public character{
    private:
    int hp = 250;
    int attack = 10;
    string job = "Warrior";
    public:
    Warrior(string name) : character(name) {}
    void print_info() const override{
        cout << "job :" << job << endl;
        cout << "hp :" << hp << endl;
        cout << "attack :" << attack << endl;
    }
};




int main(){
    Archer A("Satoshi");
    Warrior B("Yui");

    A.print_info();
    B.print_info();
    return 0;

}