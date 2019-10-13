#define IS_MAC 1
#define IS_WIN 0
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Button{
public:
    virtual void info() = 0;
};

class CheckBox
{
public:
    virtual void info() = 0;
};



class WinButton : public Button {
    void info() override {
        cout << "Win button\n";
    }
};

class WinCheckBox : public CheckBox {
    void info() override {
        cout << "Win checkbox\n";
    }
};

class MacButton : public Button {
    void info() override {
        cout << "Mac button\n";
    }
};

class MacCheckBox : public CheckBox {
    void info() override {
        cout << "Mac checkbox\n";
    }
};

class Factory {
public:
    virtual unique_ptr<Button> createButton() = 0;
    virtual unique_ptr<CheckBox> createCheckBox() = 0;
};

class WinFactory : public Factory {
public:
    unique_ptr<Button> createButton() override {
        return make_unique<WinButton>();
    }

    unique_ptr<CheckBox> createCheckBox() override {
        return make_unique<WinCheckBox>();
    }
};

class MacFactory : public Factory {
public:
    unique_ptr<Button> createButton() override {
        return make_unique<MacButton>();
    }

    unique_ptr<CheckBox> createCheckBox() override {
        return make_unique<MacCheckBox>();
    }
};



int main() {
    unique_ptr<Factory> f;
#ifdef IS_MAC
    f = make_unique<MacFactory>();
#elif IS_WIN
    f = make_unique<WinFactory>();
#endif
    unique_ptr<Button> b = f->createButton();
    unique_ptr<CheckBox> c = f->createCheckBox();

    b->info();
    c->info();
    
    return 0;
}