#include<iostream>
#include<vector>
using namespace std;

class MinStack {
public:
    MinStack() {
        _stack.clear();
        _min.clear();
    }

    void push(int x) {
        if (_stack.empty()) {
            _min.push_back(x);
        }

        if (_min.back() >= x) {
            _min.push_back(x);
        }

        _stack.push_back(x);

    }

    void pop() {
        if (!_stack.empty()) {
            if (_stack.back() == _min.back()) {
                _min.pop_back();
            }

            _stack.pop_back();
        }


    }

    int top() {
        if (_stack.empty()) {
            return -1;
        }

        int topnum;
        topnum = *(_stack.end()-1);

        return topnum;

    }

    int min() {
        if (_stack.empty()) {
            return -1;
        }
        return _min.back();
    }

private:

    vector<int> _stack;

    vector<int> _min;
};