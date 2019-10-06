#pragma once
#include "Command.h"

class CutCommand: public Command {
public:
    CutCommand(Editor* editor): Command(editor) {}

    bool execute() override {
        if(!editor->getSelection().empty()) {
            saveState();
            editor->setClipboard(editor->getSelection());
            pair<size_t, size_t> p = editor->getSegmentSelection();
            string text = cut(editor->getText(), p);
            editor->setText(text);

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