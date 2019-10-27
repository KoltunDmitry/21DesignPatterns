/* Декоратор — это структурный паттерн проектирования,
который позволяет динамически добавлять объектам новую функциональность, оборачивая их в полезные «обёртки».*/
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Notifier
{
public:
    virtual void send(string message) = 0;
};

class BaseNotifier : public Notifier
{
public:
    void send(string message)
    {
        cout << "Base: " << message << endl;
    }
};

class Decorator : public Notifier
{
public:
    Decorator(unique_ptr<Notifier> n) : wrapee(move(n)) {}
    virtual void send(string message) override
    {
        wrapee->send(message);
    }

protected:
    unique_ptr<Notifier> wrapee;
};

class SMSDecorator : public Decorator
{
public:
    SMSDecorator(unique_ptr<Notifier> n) : Decorator(move(n)) {}
    void send(string message) override
    {
        Decorator::send(message);
        cout << "SMS: " << message << endl;
    }
};

class TelegramDecorator : public Decorator
{
public:
    TelegramDecorator(unique_ptr<Notifier> n) : Decorator(move(n)) {}
    void send(string message) override
    {
        Decorator::send(message);
        cout << "Telegram: " << message << endl;
    }
};

class VKDecorator : public Decorator
{
public:
    VKDecorator(unique_ptr<Notifier> n) : Decorator(move(n)) {}
    void send(string message) override
    {
        Decorator::send(message);
        cout << "VK: " << message << endl;
    }
};


int main()
{
    unique_ptr<Notifier> b = make_unique<BaseNotifier>();
    
    b = make_unique<TelegramDecorator>(move(b));
    b = make_unique<SMSDecorator>(move(b));
    b = make_unique<VKDecorator>(move(b));
    b->send("SOS!");
    return 0;
}