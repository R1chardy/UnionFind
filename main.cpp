#include <iostream>
#include <vector>
#include "UnionFind.h"

using namespace std;

int main() {
    //testing UnionFind
    UnionFind ds(6);
    ds.print();
    ds.unify(1,2);
    cout << "connected 1 and 2: ";
    ds.connected(1, 2)? cout << "true " : cout << "false ";
    ds.print();

    UnionFind ds2(ds);
    cout << "original: ";
    ds.print();
    cout << "copied: ";
    ds2.print();

    UnionFind ds3(5);
    ds3 = ds2;
    cout << "equals on copy: ";
    ds3.print();

    ds2.unify(0, 3);
    cout << "changing copy: ";
    ds2.print();

    cout << "checking equals: ";
    ds3.print();

    ds.unify(1, 3);
    cout << "numComponents: " << ds.components() << " ";
    ds.print();
    ds.unify(5, 4);
    cout << "size: " << ds.size() << " ";
    ds.print();
    ds.unify(5, 0);
    cout << "size of component w/ 2: " << ds.componentSize(2) << " ";
    ds.print();
    ds.unify(3, 0);
    ds.print();
    return 0;
}