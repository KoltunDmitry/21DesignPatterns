#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class WeatherCenter;

class Subscriber
{
public:
    virtual void update(WeatherCenter*) = 0;
};

class EventManager
{
public:
    void addSubscriber(Subscriber* item)
    {
        m_subscribers.push_back(item);
    }
    void removeSubscriber(Subscriber* item)
    {
        auto it = find(m_subscribers.begin(), m_subscribers.end(), item);
        if(it != m_subscribers.end())
        {
            m_subscribers.erase(it);
        }
    }
    void notify(WeatherCenter* info)
    {
        for(auto* item : m_subscribers)
        {
            item->update(info);
        }
    }
private:
    vector<Subscriber*> m_subscribers;
};

class WeatherCenter : public EventManager
{
public:
    WeatherCenter(int degreeCelsius)
        : m_degreeCelsius(degreeCelsius) {}

    void setDegree(int value)
    {
        if(m_degreeCelsius != value)
        {
            m_degreeCelsius = value;
            notify(this);
        }
    }
    int getDegree() const { return m_degreeCelsius; }
private:
    int m_degreeCelsius;
};

class WeatherApplication : public Subscriber
{
public:
    void update(WeatherCenter* info)
    {
        cout << "New weather: " << info->getDegree() << " degrees!\n";
    }
};

int main()
{
    WeatherCenter weatherCenter(25);
    WeatherApplication app;
    weatherCenter.addSubscriber(&app);
    weatherCenter.setDegree(30);
    weatherCenter.setDegree(10);
    return 0;
}

