#include "stdafx.h"
#include <iostream>

class Strategy //интерфейс
{
public:
	virtual ~Strategy() {}
	virtual void use() = 0;
};

class Strategy_1: public Strategy //стратегия 1
{
public:
	void use(){ 
        cout << "Strategy_1" << endl; 
    }
};

class Strategy_2: public Strategy // стратегия 2
{
public:
	void use(){ 
        cout << "Strategy_2" << endl; 
    }
};

class Context //основной класс
{
protected: //ссылка на интерфейс
	Strategy* operation;

public: //конструктор контекста
	virtual ~Context() {}
	virtual void useStrategy() = 0;
	virtual void setStrategy(Strategy* v) = 0;
};

class Client: public Context
{
public: 
	void useStrategy() //установка стратегии
	{
		operation->use();
	}

	void setStrategy(Strategy* o)
	{
		operation = o;
	}
};

int main()
{
	Client customClient;
	Strategy_1 str1;
	Strategy_2 str2;
	Strategy_3 str3;

	customClient.setStrategy(&str1);
	customClient.useStrategy();
	customClient.setStrategy(&str2);
	customClient.useStrategy();
	return 0;
}