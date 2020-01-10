#include "stdafx.h"
#include <iostream>
using namespace std;

// Класс делающий классы взаимозаменяемыми
class Widget
{
  public:
    virtual void draw() = 0;
};

class TextField: public Widget
{
    //  Основной класс, использующий отношение "является"
    int width, height;
  public:
    TextField(int w, int h)
    {
        width = w;
        height = h;
    }
 
    /*virtual*/
    void draw()
    {
        cout << "TextField: " << width << ", " << height << '\n';
    }
};

// Базовый класс второго уровня для реализации дополнительной функциональности.
class Decorator: public Widget  // использует отношение "является"
{
    Widget *wid; // отношение "имеет"
  public:
    Decorator(Widget *w)
    {
        wid = w;
    }
 
    /*virtual*/
    void draw() 
    {	// Класс Decorator делегирует выполнение операции объекту "имеет"
        wid->draw(); 
    }
};

class BorderDecorator: public Decorator
{
  public:
    //  Дополнительное декорирование
    BorderDecorator(Widget *w): Decorator(w){}
 
    /*virtual*/
    void draw()
    {
        //  Делегирование базовому классу и
        Decorator::draw();
		//реализация дополнительной функциональности
        cout << "   BorderDecorator" << '\n';
    }
};

class ScrollDecorator: public Decorator
{
  public:
    // Дополнительное декорирование
    ScrollDecorator(Widget *w): Decorator(w){}
 
    /*virtual*/
    void draw()
    {
        // Делегировать в базовый класс и добавить дополнительные вещи
        Decorator::draw();
        cout << "   ScrollDecorator" << '\n';
    }
};

int main()
{
  // Клиент ответственен за конфигурирование нужной функциональности
  Widget *aWidget = new BorderDecorator(new BorderDecorator(new ScrollDecorator
    (new TextField(80, 24))));
  aWidget->draw();
}