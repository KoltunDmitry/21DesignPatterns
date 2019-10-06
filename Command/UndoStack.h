#pragma once

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Command;

class UndoStack{
public:
    void push(Command* c){
        st.push(c);
    }
    Command* pop() {
        Command* c = st.top();
        st.pop();
        return c;
    }
private:
    stack<Command*> st;
};