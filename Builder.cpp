#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

// лассы всех возможных видов письменных принадлежностей
class Pencil
{
  public:
    void info() { 
      cout << "Pencil" << endl; 
    }
};
  
class Pen
{
  public:
    void info() { 
      cout << "Pen" << endl; 
    }
};
  
class Eraser
{
  public:        
    void info() { 
      cout << "Eraser" << endl; 
    }
};
  
class Ruler
{
  public:    
    void info() { 
      cout << "Ruler" << endl; 
    }
};
  
class Marker
{
  public:    
    void info() { 
      cout << "Marker" << endl; 
    }
};
   
// ласс " онцел€ри€", содержащий все типы письменных принадлежностей
class Chancery
{
  public:
    vector<Pencil>     pe; 
    vector<Pen>       pen; 
    vector<Eraser>    er;     
    vector<Ruler>    ru;     
    vector<Marker>       ma; 
    void info() {   
      int i;
      for(i=0; i<pe.size(); ++i)  pe[i].info();
      for(i=0; i<pen.size(); ++i)  pen[i].info();
      for(i=0; i<er.size(); ++i)  er[i].info();
      for(i=0; i<ru.size(); ++i)  ru[i].info();
      for(i=0; i<ma.size(); ++i)  ma[i].info();
    }
};
  
  
//Ѕазовый класс ChanceryBuilder объ€вл€ет интерфейс дл€ поэтапного
// "построени€" концел€рии и предусматривает его реализацию по умолчанию
class ChanceryBuilder
{
  protected: 
    Chancery* p;
  public:    
    ChanceryBuilder(): p(0) {}
    virtual ~ChanceryBuilder() {}
    virtual void createChancery() {}
    virtual void buildPencil() {}
    virtual void buildPen() {}
    virtual void buildEraser() {}
    virtual void buildRuler() {}
    virtual void buildMarker() {}    
    virtual Chancery* getChancery() { return p; }    
};
   
//ћо€ концел€ри€ имеет все типы пис.принадлежностей кроме маркера
class MyChanceryBuilder: public ChanceryBuilder
{    
  public:    
    void createChancery() { p = new Chancery; }
    void buildPencil() { p->pe.push_back( Pencil()); }
    void buildPen() { p->pen.push_back( Pen()); }
    void buildEraser() { p->er.push_back( Eraser()); }    
    void buildRuler() { p->ru.push_back( Ruler()); }
};
  
  
// онцел€ри€ друга имеет все типы пис.принадлежностей кроме линейки
class FriendChanceryBuilder: public ChanceryBuilder
{    
  public:    
    void createChancery() { p = new Chancery; }
    void buildPencil() { p->pe.push_back( Pencil()); }
    void buildPen() { p->pen.push_back( Pen()); }
    void buildEraser() { p->er.push_back( Eraser()); }    
    void buildMarker() { p->ma.push_back( Marker()); }
};
  
  
// ласс-распор€дитель, поэтапно создающий мою концел€рию или друга
//»менно здесь определен алгоритм построени€ концел€рии
class Manager
{    
  public:    
    Chancery* createChancery( ChanceryBuilder & builder ) 
    { 
        builder.createChancery();
        builder.buildPencil();
        builder.buildPen();
        builder.buildEraser();
        builder.buildRuler();
        builder.buildMarker();
        return( builder.getChancery());
    }
};
  
  
int main()
{   
    Manager man;
    MyChanceryBuilder my_builder;
    FriendChanceryBuilder fr_builder;
     
    Chancery * my = man.createChancery( my_builder);
    Chancery * fr = man.createChancery( fr_builder);
    cout << "My Chancery:" << endl;
    my->info();
    cout << "\nFriend's Chancery:" << endl;
    fr->info();
    return 0;
}