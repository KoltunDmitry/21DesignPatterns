#pragma once
#include "Command.h"

class CopyCommand: public Command {
public:
    CopyCommand(Editor* editor): Command(editor) {}

    bool execute() override {
        if(!editor->getSelection().empty())
            editor->setClipboard(editor->getSelection());
        return false;
    }
};