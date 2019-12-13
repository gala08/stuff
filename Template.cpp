
#include "stdafx.h"
#include <iostream>
using namespace std;
 
class DailyRoutine
{
    void WakeUp()
    {
        cout << "WakeUp \n";
    }
    void Work()
    {
        cout << "GoToWork Work  \n";
    }
    void Chill()
    {
        cout << "GoToHome Chill  \n";
    } 
    //"замещающие" методы.
    virtual void xx1() = 0;
    virtual void xx2() = 0;
  public:
    //шаблонный метод
    void execute()
    {
        WakeUp();
        xx1();
        Work();
        xx2();
        Chill();
    }
};
 
class Monday: public DailyRoutine
{
   //классы реализуют "замещающие" методы.
     /*virtual*/void xx1()
    {
        cout << "DoHometask  \n";
    }
     /*virtual*/void xx2()
    {
        cout << "GoToUniversity  \n";
    }
};
 
class Tuesday: public DailyRoutine
{
     /*virtual*/void xx1()
    {
        cout << "";
    }
     /*virtual*/void xx2()
    {
        cout << "GoToUniversity  \n";
    }
};
 
int main()
{
  DailyRoutine *array[] = 
  {
     &Monday(), &Tuesday()
  };
  for (int i = 0; i < 2; i++)
  {
    array[i]->execute();
    cout << '\n';
  }
}
