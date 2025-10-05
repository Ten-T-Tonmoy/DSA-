#include <bits/stdc++.h>

using namespace std;

void usingQueue()
{
    queue<char> st;
    vector<char> popped;

    st.push('d');
    st.push('h');
    popped.push_back(st.front());
    st.pop();

    st.push('f');
    st.push('s');
    popped.push_back(st.front());

    st.pop();
    popped.push_back(st.front());

    st.pop();
    st.push('m');

    cout << "Sequence of popped vals :";
    for (auto v : popped)
        cout << v << " ";
}

void usingStack()
{
    stack<char> st;
    vector<char> popped;

    st.push('d');
    st.push('h');
    popped.push_back(st.top());
    st.pop();

    st.push('f');
    st.push('s');
    popped.push_back(st.top());

    st.pop();
    popped.push_back(st.top());

    st.pop();
    st.push('m');

    cout << "Sequence of popped vals :";
    for (auto v : popped)
        cout << v << " ";
}

int main()
{
    usingQueue();
    return 0;
}