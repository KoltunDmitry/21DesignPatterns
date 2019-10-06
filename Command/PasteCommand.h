#pragma once
#include "Command.h"

class PasteCommand: public Command {
public:
    PasteCommand(Editor* editor): Command(editor) {}

    bool execute() override {
        if(!editor->getSelection().empty()) {
            saveState();
            editor->insert(editor->getText().size(), editor->getClipboard());
            return true;
        }
        return false;
    }

    string cut(const string& text, pair<size_t, size_t> p){
        string part1 = {text.begin(), text.begin() + p.first};
        string part2 = {text.begin() + p.second, text.end()};
        return part1 + part2;
    }
};