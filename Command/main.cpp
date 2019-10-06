#include <iostream>
#include <utility>
#include <memory>

#include "Command.h"
#include "CopyCommand.h"
#include "CutCommand.h"
#include "PasteCommand.h"
#include "Editor.h"


using namespace std;


int main() {
    unique_ptr<Editor> editor = make_unique<Editor>("Hello, world!");
    unique_ptr<Command> copy = make_unique<CopyCommand>(editor.get());
    unique_ptr<Command> paste = make_unique<PasteCommand>(editor.get());
    unique_ptr<Command> cut = make_unique<CutCommand>(editor.get());


    editor->setSelection(make_pair(0,5));

    cout << "Source text:\n";
    cout << editor->getText() << endl;
    editor->makeCommand(copy.get());
    editor->makeCommand(paste.get());

    cout << "After copy-paste:\n";
    cout << editor->getText() << endl;
    editor->makeCommand(cut.get());
    cout << "After cut:\n";
    cout << editor->getText() << endl;
    cout << "Undo:\n";
    editor->undo();
    cout << editor->getText() << endl;
    editor->undo();
    cout << editor->getText() << endl;
}
// Output:
// Source text:
// Hello, world!
// After copy-paste:
// Hello, world!Hello
// After cut:
// , world!Hello
// Undo:
// Hello, world!Hello
// Hello, world!