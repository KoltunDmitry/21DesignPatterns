/*Стратегия — это поведенческий паттерн проектирования, который определяет семейство схожих алгоритмов
и помещает каждый из них в собственный класс, после чего алгоритмы можно взаимозаменять прямо во время
исполнения программы.*/
#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

//Example1
class Operation{
public:
    virtual int execute(int a, int b) = 0;
};

class OperationAdd: public Operation {
public:
    int execute(int a, int b) override {
        cout << "Add: \n";
        return a + b;
    }
};

class OperationSubtract: public Operation {
public:
    int execute(int a, int b) override {
        cout << "Subtract: \n";
        return a - b;
    }
};

class OperationMultiplication: public Operation {
public:
    int execute(int a, int b) override {
        cout << "Multiplication: \n";
        return a * b;
    }
};

class OperationDivision: public Operation {
public:
    int execute(int a, int b) override {
        cout << "Division: \n";
        return a/b;
    }
};

class Context{
public:
    void run(int a, int b) {
        cout << operation->execute(a,b) << endl;
    }
    void setStrategy(unique_ptr<Operation> op) {
        operation = move(op);
    }
private:
    unique_ptr<Operation> operation;
};

//end Example1



int main()
{
    Context context;
    context.setStrategy(make_unique<OperationAdd>());
    context.run(10,5);
    context.setStrategy(make_unique<OperationMultiplication>());
    context.run(10,5);
}