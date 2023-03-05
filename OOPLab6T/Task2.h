#pragma once
#include<iostream>
using namespace std;
class Quadrangle {
protected:
	double a, b, c ,d;
public:
	Quadrangle():a(0),b(0),c(0),d(0){}
	Quadrangle(double a_,double b_,double c_,double d_):a(a_),b(b_),c(c_),d(d_){}
	virtual double Area() = 0;
	virtual double Perimetr() = 0;
};
class Square : public Quadrangle {
public:
	Square(double a_):Quadrangle(a_,a_,a_,a_){}
	double Area() override
	{
		return a * a;
	}
	double Perimetr() override
	{
		return 4 * a;
	}
};
class Rectangle : public Quadrangle {
public:
	Rectangle(double length,double width): Quadrangle(length, width, length, width){}
	double Area() override
	{
		return a * b;
	}
	double Perimetr() override
	{
		return 2 * (a + b);
	}
 };
class Parallelogram : public Quadrangle {
public:
	Parallelogram(double b,double height,double side):Quadrangle(b,side,b,side){
		this->b = height;
	}
	double Area() override
	{
		return a * b;
	}
	double Perimetr() override
	{
		return 2 * (a + b);
	}
};
class Trapezia : public Quadrangle {
private:
	double height;
public:
	Trapezia (double top,double buttom,double left,double right,double height_):Quadrangle(top,buttom,left,right),height(height_){}
	double Area() override
	{
		return (a + b) * height / 2;
	}
	double Perimetr() override 
	{
		return a + b + c + d;
	}
};
void Task2()
{
	string q[4] = {"Square","Rectangle","Parallelogram","Trapezia"};
	Quadrangle* qles[4];
	qles[0] = new Square(10.0);
	qles[1] = new Rectangle(3.0, 9.0);
	qles[2] = new Parallelogram(7.0, 5.0, 9.0);
	qles[3] = new Trapezia(3.0, 7.0, 5.0, 5.0, 8.0);

	for (int i = 0; i < 4; i++)
	{
		cout << "Quadrangle " << q[i] <<"["<< i<< "] Area: " << qles[i]->Area() << endl;
		cout << "Quadrangle " << q[i] <<"[" << i << "] Perimetr: " << qles[i]->Perimetr() << endl;
		cout << endl;
		delete qles[i];
	}
}
