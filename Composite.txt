#include "stdafx.h"
#include<iostream>
#include<vector>
 
using namespace std;
 
class node //класс сдержит метод, который просто 
	//возвращает сохраненное значение
{
	int val;
public:
	node(int x) :val(x){}
	int value()const
	{
		return val;
	}
};
 
class IComposite //интерфейс 
	//У него есть два метода, Display и Add.
{
public:
	virtual void Display(void)const = 0;
	virtual void Add(node* elem){}
};
 
class Single : public IComposite //класс single, который реализует интерфейс.
{
	node* elem;
public:
	Single(node* x) :elem(x){}
 
	void Display(void)const  //реализованный метод Display просто вызывает 
		//функцию value для отображения содержимого.
	{
		cout << elem->value() << "\n";
	}
 
	void Add(node* elem)
	{
		cout << "Not implemented\n";
	}
 
	~Single()
	{
		delete elem;
	}
};
 
class Composite : public IComposite
{
	vector<node*> elems;
public:
	void Display(void)const
	{
		for (vector<node*>::const_iterator iter = elems.begin(); iter != elems.end(); ++iter)
		{
			cout << (*iter)->value() << "\n";
		}
		cout << "\n";
	}
 
	void Add(node* elem)
	{
		elems.push_back(elem);
	}
 
	~Composite()
	{
		for (vector<node*>::const_iterator iter = elems.begin(); iter != elems.end(); ++iter)
		{
			delete *iter;
		}
	}
};
 
int main()
{
	node* a = new node(5);
	node* b = new node(6);
	node* c = new node(7);
	IComposite* clientSingle = new Single(a);
	clientSingle->Display();
	clientSingle->Add(b);
	cout << "\n";
	IComposite* clientComposite = new Composite();
	clientComposite->Add(b);
	clientComposite->Display();
	clientComposite->Add(c);
	clientComposite->Display();
	return 1;
}