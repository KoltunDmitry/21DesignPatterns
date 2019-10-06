#include "Editor.h"
#include "Command.h"

bool Editor::setSelection(pair<size_t, size_t> p) {
    if(p.first >= 0 && p.first < p.second){
        size_t end = min(p.second, text.size());
        selection = make_pair(p.first, end);
    }
    return false;
}

void Editor::insert(size_t pos, string str) {
        if(pos <= text.size() && pos >= 0) {
            text.insert(pos, str);
        }
    }

void Editor::undo() {
    Command* c = st.pop();
    c->makeBackup();
}

void Editor::makeCommand(Command* c) {
    if(c->execute()) {
        st.push(c);
    }
}