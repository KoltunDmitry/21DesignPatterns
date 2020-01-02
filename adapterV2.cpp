// adapter using agregation
#include <iostream>
#include <memory>

class JSON {};

class XML {};

class DrawerGraphics
{
public:
    void plotGraphics(const XML& xmlData)
    {
        std::cout << "Draw graphics by xml data\n";
    } 
};

class Client
{
public:
    virtual void draw(const JSON& jsonData) = 0; 
};

class Adapter : public Client
{
public:
    Adapter(DrawerGraphics& drawer) : m_drawer(drawer) {} 
    void draw(const JSON& jsonData) override
    {
        m_drawer.plotGraphics(convertJsonToXml(jsonData));
    }
private:
    XML convertJsonToXml(const JSON& json)
    {
        // some code that converts json to xml ...
        return XML();
    }
private:
    DrawerGraphics& m_drawer;
};

JSON proccessData(/*...*/)
{
    return JSON();
}

int main()
{
    JSON data = proccessData();
    DrawerGraphics drawer;
    std::unique_ptr<Client> client = std::make_unique<Adapter>(drawer);
    client->draw(data);
    return 0;
}