#pragma once
#include<iostream>
#include<string>
using namespace std;
class Human {
protected:
    string name;
    int age;
public:
    Human():name(""),age(0){}
    Human(string n,int a):name(n),age(a){}
    virtual ~Human(){}
    void setHN(string h) { this->name = h; }
    string getHN() { return name; }
    void setHA(int a) { this->age = a; }
    int getHA() { return age; }
    string toString() 
    {
        string r = "Name :" + name + "\nAge: " + to_string(age) + "\n";
        return r;
    }
};
class Father :  public Human {
public:
    Father() :Human() {}
    Father(string fname, int fage) :Human(fname, fage) {}
    ~Father(){}
    void setFN(string f) { this->name = f; }
    string getFN() { return name;}
    void setFA(int a) { this->age = a; }
    int getFA() { return age; }
    string toString()
    {
        string r = "Father : \n" + Human::toString();
        return r;
    }
  
};
class Mother : public Human {
public:
    Mother() :Human() {}
    Mother(string mname, int mage) :Human(mname, mage) {}
    ~Mother() {}
    void setMN(string m) { this->name = m; }
    string getMN() { return name; }
    void setMA(int a) { this->age = a; }
    int getMA() { return age; }
    string toString()
    {
        string r = "Mother : \n" + Human::toString();
        return r;
    }

};
class Son : public Human,public Father, public Mother {
public:
    Son():Human(),Father(),Mother(){}
    Son(string sname,int sage,string fname,int fage,string mname,int m_age):
        Human(sname,sage),Father(fname,fage),Mother(mname,m_age){}
    ~Son(){}
    string toString()
    {
        string r = "Son : \n" + Human::toString() + Father::toString() + Mother::toString();
        return r;
    }
    void setSN(string s) { Human::name = s; }
    string getSN() { return Human::name;}
    void setSA(int a){Human::age = a;}
    int getSA(){ return Human::age;}
    friend istream& operator>>(istream& in, Son& s) {
        cout << "Input son name: ";
        in >> s.Human::name;
        cout << "Input son age: ";
        in >> s.Human::age;
        cout << "Input father name: ";
        in >> s.Father::name;
        cout << "Input father age: ";
        in >> s.Father::age;
        cout << "Input mother name: ";
        in >> s.Mother::name;
        cout << "Input mother age: ";
        in >> s.Mother::age;
        return in;
    }

    friend ostream& operator<<(ostream& out, Son& s) {
        out << "Son: \n" << s.Human::toString() << s.Father::toString() << s.Mother::toString();
        return out;
    }

};




void Task3()
{
    cout << "Test:\n";
    cout << "-----------------" << endl;
    Son def;
    cout << def.toString();
    cout << "-----------------" << endl;
    Son p("Petro", 10, "Olesia", 34, "Volodya", 37);
    cout << p.toString();
    cout << "-----------------" << endl;
    Son* ptr = new Son();
    ptr->setMN("Olena");
    ptr->setMA(34);
    ptr->setFN("Jon");
    ptr->setFA(39);
    ptr->setSN("Mika");
    ptr->setSA(10);
    cout << ptr->toString();
    cout << "-----------------" << endl;
    cout << "Test override cin cout" << endl;
    Son cs;
    cin >> cs;
    cout << cs;
    cout << "-----------------" << endl;
    cout << "End test"<<endl;
}