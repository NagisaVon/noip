#include <iostream>
#include <stack>
using namespace std;

stack <int> st;
int mem[1001];

int main () {
    int n, add = 0, preMem = 0;
    cin >> n;
    st.push(n);
    while ( !st.empty() ) {
        add++;

        if ( add > st.top()/2 ) {  // st.top don't have child
            add = st.top();
            preMem = ++mem[add];
            st.pop();
            if ( !st.empty() )
                mem[ st.top() ] += preMem;
        }
        else if ( mem[add] != 0 ) {// Add already in memory
            mem[st.top()] += mem[add]; 
        }
        else {
            st.push(add);
            add = 0;
        } 
    }
    cout << mem[n] << endl;
    return 0;
}
