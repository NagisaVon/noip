#include <iostream>
using namespace std;
struct node {
    int data;
    node *next;
}*h, *p;
// *h point to head of link 
// *p point to a new node 
int main() {
    int i, n, t;
    cin >> n;
    while ( n ) {
        cin >> t;
        p = new node; // make a new node 
        p->data = t;  
        p->next = h;  // make the node linked to the head of the link
        h = p;        // make the new node as the head
        n--;
    }
    /*
     * Like this
     *
     *  O is normal node
     *  h is head(tail) node 
     *  p is a new node
     *
     *  O<-O<-h
     *  O<-O<-h p
     *  O<-O<-h<-p
     *  O<-O<-O<-h
     */

    while ( true ) {
    	cout << h->data;
    	if ( h->next == NULL )
    		break;
    	h = h->next;
    }
    return 0;
}
