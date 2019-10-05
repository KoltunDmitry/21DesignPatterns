//Одиночка — это порождающий паттерн проектирования, который гарантирует,
// что у класса есть только один экземпляр, и предоставляет к нему глобальную точку доступа.
#include <iostream>
#include <utility>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <list>

using namespace std;

class Database {
public:
    Database(const Database&) = delete;
    Database(Database&&) = delete;
    static Database* getInstance() {
        if(!instance){
            instance = new Database;
        }
        return instance;
    }

    void query(const string& str){
        cout << "Count query: " << ++countQuery << endl;
    }
private:
    Database() {
        countQuery = 0;
    }
    static Database* instance;
    size_t countQuery;
};

Database* Database::instance = nullptr;

int main(){
    Database::getInstance()->query("SELECT");
    Database::getInstance()->query("JOIN");
}