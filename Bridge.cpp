#include "stdafx.h"
#include <iostream>
#include <string>
 
using namespace std;
 
class IColor //объ€вл€ем интерфейс IColor
{
public:
    virtual string Color() = 0; //метод, который будет возвращать цвет в реализующих классах
};
 
class RedColor : public IColor //класс RedColor, реализующий интерфейс
{
public:
    string Color()
    {
        return "of Red Color";
    }
};
 
class BlueColor : public IColor //класс RedColor, реализующий интерфейс
{
public:
    string Color()
    {
        return "of Blue Color";
    }
};
 
class ICarModel //интерфейс дл€ моделей автомобилей
{
public:
    virtual string WhatIsMyType() = 0; //метод, который будет возвращать тип модели
};
 
class Model_A : public ICarModel  //класс Model_A, реализующий интерфейс
{
    IColor* _myColor; //указатель на IColor присутствует в классе. Ёто будет инициализировано в конструкторе
public:
//конструктор, в котором происходит инициализаци€. ќбъект этого класса будет
//создан с использованием экземпл€ра типа IColor.
    Model_A(IColor *obj) :_myColor(obj){}
    string WhatIsMyType()
    {
        return "I am a Model_A " + _myColor->Color();
    }
};
 
class Model_B : public ICarModel //класс Model_B, реализующий интерфейс.
{
    IColor* _myColor;
public:
    Model_B(IColor *obj) :_myColor(obj){}
    string WhatIsMyType()
    {
        return "I am a Model_B " + _myColor->Color();;
    }
};
 
int main()
{	//клиент объ€вл€ет и инициализирует экземпл€ры классов
    IColor* red = new RedColor();
    IColor* blue = new BlueColor();
 
    ICarModel* modelA = new Model_B(red);
    ICarModel* modelB = new Model_A(blue);
	//------------------------------------------------------------
	//вызов метода
    cout << "\n" << modelA->WhatIsMyType();           
    cout << "\n" << modelB->WhatIsMyType() << "\n\n";
 
    delete red;
    delete blue;
    return 1;
}