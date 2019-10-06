#pragma once
#include <iostream>
#include <memory>

#include "Editor.h"

using namespace std;

class Command{
public:
    Command(Editor* editor): editor(editor) {}

    void saveState() {
        backup = editor->getText();
    }

    void makeBackup() {
        editor->setText(backup);
    }

    virtual bool execute() = 0;
protected:
    Editor* editor;
private:
    string backup;
};