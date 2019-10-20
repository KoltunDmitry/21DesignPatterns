/*Адаптер — это структурный паттерн проектирования,
который позволяет объектам с несовместимыми интерфейсами работать вместе.*/
#include <iostream>
#include <memory>

using namespace std;

typedef int Coordinate;
typedef int Dimension;

class Rectangle
{
public:
    virtual void draw() = 0;
};

class LegacyRectangle
{
public:
    LegacyRectangle(Coordinate x1, Coordinate y1, Coordinate x2, Coordinate y2) : x1(x1), x2(x2), y1(y1), y2(y2)
    {}
    void oldDraw()
    {
        cout << "Legacy rectangle draw: x1 = " << x1 << " y1 = " << y1 <<
         " x2 = " << x2 << " y2 = " << y2 << endl; 
    }
private:
    Coordinate x1,y1,x2,y2;
};

class RectangleAdapter : public Rectangle, public LegacyRectangle
{
public:
    RectangleAdapter(Coordinate x, Coordinate y, Dimension width, Dimension height) :
        LegacyRectangle(x, y, x + width, y + height)
    {}
    void draw() override
    {
        cout << "Rectangle Adapter\n";
        oldDraw();
    }
private:
    Coordinate x,y;
    Dimension width, height;

};


int main()
{
    unique_ptr<Rectangle> rectangleAdapter = make_unique<RectangleAdapter>(10,10,50,30);
    rectangleAdapter->draw();
    return 0;
}