#include <iostream>
using namespace std;

//base class.
class Shape;
{
    public:
     int width;
     int height;

     void setWidth(int w)
     {
        width = w;
     }
    void setHeight(int h)
     {
        height = h;
     }
};

//derived class
class Rectangle: public Shape
{
    public:
     int getArea()
      
    {return (width*height);}
      
};

int main()
{
  Rectangle Rect;
  Rect.setWidth(5);
  Rect.getHeight(7);
  // print the area of the object.
  cout<<"Total area: "<<Rect.getArea()<<endl;

  return 0;
}