#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <utility>

#include "UndoStack.h"

using namespace std;

class Command;

class Editor{
public:
    Editor(string text): text(text) {}
    bool setSelection(pair<size_t, size_t> p);
    
    pair<size_t, size_t> getSegmentSelection() const {
        return selection;
    }

    string getSelection() {
        return text.substr(selection.first, selection.second);
    }

    void setText(const string& newText) {
        text = newText;
    }

    string getText() const {
        return text;
    }

    void setClipboard(string s){
        clipboard = s;
    }

    string getClipboard() const {
        return clipboard;
    }

    void insert(size_t pos, string str);
    
    void undo();

    void makeCommand(Command* c);

private:
    UndoStack st;
    string text;
    string clipboard;
    pair<size_t, size_t> selection;
};