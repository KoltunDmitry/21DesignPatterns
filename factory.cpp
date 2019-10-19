/*Фабричный метод - это порождающий шаблон проектирования, который 
определяет интерфейс для создания объектов в суперклассе, а наследники
могут переопределять этот интерфейс, тем самым меняя тип, создаваемого объекта*/
#include <iostream>
#include <memory>
using namespace std;

class Building
{
public:
    virtual void show() = 0;
};

class House : public Building
{
    void show() override 
    {
        cout << "it's House\n";
    }
};

class Flat : public Building
{
    void show() override
    {
        cout << "it's Flat\n";
    }
};

class BuildingFactory
{
public:
    virtual unique_ptr<Building> create() = 0;
};

class HouseFactory : public BuildingFactory
{
public:
    unique_ptr<Building> create() override
    {
        return make_unique<House>();
    }
};

class FlatFactory : public BuildingFactory
{
public:
    unique_ptr<Building> create() override
    {
        return make_unique<Flat>();
    }
};

int main()
{
    unique_ptr<BuildingFactory> factory;
    factory = make_unique<FlatFactory>();
    
    unique_ptr<Building> building = factory->create();
    building->show();
    return 0;
}