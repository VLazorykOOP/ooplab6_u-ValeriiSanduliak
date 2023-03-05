#pragma once
#include<iostream>
#include<string>
using namespace std;
class Base {
    int x;
public:
    void set(int i) { x = i; }
    void show() { cout << "Base x: " << x << endl; }
};

class D1 : public Base {
    int y;
public:
    void set(int i, int j) { Base::set(i); y = j; }
    void show() { Base::show(); cout << "D1 y: " << y << endl; }
};

class D2 : public Base {
    int z;
public:
    void set(int i, int j) { Base::set(i); z = j; }
    void show() { Base::show(); cout << "D2 z: " << z << endl; }
};

class D3 : public Base {
    int a;
public:
    void set(int i, int j) { Base::set(i); a = j; }
    void show() { Base::show(); cout << "D3 a: " << a << endl; }
};

class DD1 : public D1 {
    int b;
public:
    void set(int i, int j, int k) { D1::set(i, j); b = k; }
    void show() { D1::show(); cout << "DD1 b: " << b << endl; }
};

class DD23 : public D2, public D3 {
    int c;
public:
    void set(int i, int j, int k, int l) { D2::set(i, j); D3::set(k, l); c = i + j + k + l; }
    void show() { D2::show(); D3::show(); cout << "DD23 c: " << c << endl; }
};

class DDD23 : public DD23 {
    int d;
public:
    void set(int i, int j, int k, int l, int m) { DD23::set(i, j, k, l); d = m; }
    void show() { DD23::show(); cout << "DDD23 d: " << d << endl; }
};


// virtual 

class basev {
    int x;
public:
    void set(int i) { x = i; }
    void show() { cout << "Base x: " << x << endl; }
};

class d1v : virtual public basev {
    int y;
public:
    void set(int i, int j) { basev::set(i); y = j; }
    void show() { basev::show(); cout << "D1 y: " << y << endl; }
};

class d2v : virtual public basev {
    int z;
public:
    void set(int i, int j) { basev::set(i); z = j; }
    void show() { basev::show(); cout << "D2 z: " << z << endl; }
};

class d3v : virtual public basev {
    int a;
public:
    void set(int i, int j) { basev::set(i); a = j; }
    void show() { basev::show(); cout << "D3 a: " << a << endl; }
};

class dd1v : virtual public d1v{
    int b;
public:
    void set(int i, int j, int k) { d1v::set(i, j); b = k; }
    void show() { d1v::show(); cout << "DD1 b: " << b << endl; }
};

class dd23v : virtual public d2v, virtual public d3v {
    int c;
public:
    void set(int i, int j, int k, int l) { d2v::set(i, j); d3v::set(k, l); c = i + j + k + l; }
    void show() { d2v::show(); d3v::show(); cout << "DD23 c: " << c << endl; }
};

class ddd23v : virtual public dd23v {
    int d;
public:
    void set(int i, int j, int k, int l, int m) { dd23v::set(i, j, k, l); d = m; }
    void show() { dd23v::show(); cout << "DDD23 d: " << d << endl; }
};
void Task1()
{
    Base b;
    D1 d1;
    D2 d2;
    D3 d3;
    DD1 dd1;
    DD23 dd23;
    DD23 ddd23;
    cout << "Sizes of objects:" << endl;
    cout << "Base: " << sizeof(b) << " bytes" << endl;
    cout << "D1: " << sizeof(d1) << " bytes" << endl;
    cout << "D2: " << sizeof(d2) << " bytes" << endl;
    cout << "D3: " << sizeof(d3) << " bytes" << endl;
    cout << "DD1: " << sizeof(dd1) << " bytes" << endl;
    cout << "DD23: " << sizeof(dd23) << " bytes" << endl;
    cout << "DDD23: " << sizeof(ddd23) << " bytes" << endl;
    //virtual 
    cout << endl << "Virtual:" << endl;
    basev bv;
    d1v d1v;
    d2v d2v;
    d3v d3v;
    dd1v dd1v;
    dd23v dd23v;
    ddd23v ddd23v;
    cout << "Sizes of objects:" << endl;
    cout << "Basev: " << sizeof(bv) << " bytes" << endl;
    cout << "D1v: " << sizeof(d1v) << " bytes" << endl;
    cout << "D2v: " << sizeof(d2v) << " bytes" << endl;
    cout << "D3v: " << sizeof(d3v) << " bytes" << endl;
    cout << "DD1v: " << sizeof(dd1v) << " bytes" << endl;
    cout << "DD23v: " << sizeof(dd23v) << " bytes" << endl;
    cout << "DDD23v: " << sizeof(ddd23v) << " bytes" << endl;
}