#include "DoublyList.hpp"
#include <iostream>
#include <string>
using namespace std;


template <typename Func>
void runCase(const string& label, Func f) {
    cout << "\n=== " << label << " ===\n";
    try {
        f();
    } catch (string& e) {
        cout << "Caught exception: " << e << "\n";
    } catch (...) {
        cout << "Caught unknown exception\n";
    }
}

int main() {
    // -------------------------
    // INT LIST TESTS
    // -------------------------
    runCase("INT: start empty", [](){
        DoublyList<int> a;
        cout << "isEmpty: " << a.isEmpty() << "\n";
        cout << "length : " << a.getLength() << "\n";
        cout << "print  : " << a;   
    });

    runCase("INT: append 3 items", [](){
        DoublyList<int> a;
        a.append(4);
        a.append(30);
        a.append(23);

        cout << "length : " << a.getLength() << "\n";
        cout << "print  : " << a;
        cout << "getElement(0): " << a.getElement(0) << "\n";
        cout << "getElement(1): " << a.getElement(1) << "\n";
        cout << "getElement(2): " << a.getElement(2) << "\n";
    });

    runCase("INT: insert at front (pos 0)", [](){
        DoublyList<int> a;
        a.append(10);
        a.append(20);
        a.insert(0, 5);
        cout << "print  : " << a;
        cout << "length : " << a.getLength() << "\n";
        cout << "front  : " << a.getElement(0) << "\n";
    });

    runCase("INT: insert in middle", [](){
        DoublyList<int> a;
        a.append(10);
        a.append(20);
        a.append(40);
        a.insert(2, 30);  // between 20 and 40
        cout << "print  : " << a;
        cout << "elem(2): " << a.getElement(2) << "\n";
    });

    runCase("INT: insert at end (pos == length)", [](){
        DoublyList<int> a;
        a.append(1);
        a.append(2);
        a.append(3);
        a.insert(a.getLength(), 99);
        cout << "print  : " << a;
        cout << "last   : " << a.getElement(a.getLength() - 1) << "\n";
    });

    runCase("INT: remove front", [](){
        DoublyList<int> a;
        a.append(10); a.append(20); a.append(30);
        a.remove(0);
        cout << "print  : " << a;
        cout << "length : " << a.getLength() << "\n";
        cout << "new front: " << a.getElement(0) << "\n";
    });

    runCase("INT: remove middle", [](){
        DoublyList<int> a;
        a.append(10); a.append(20); a.append(30); a.append(40);
        a.remove(2); // remove 30
        cout << "print  : " << a;
        cout << "length : " << a.getLength() << "\n";
    });

    runCase("INT: remove end", [](){
        DoublyList<int> a;
        a.append(10); a.append(20); a.append(30);
        a.remove(a.getLength() - 1);
        cout << "print  : " << a;
        cout << "length : " << a.getLength() << "\n";
    });

    runCase("INT: replace values", [](){
        DoublyList<int> a;
        a.append(7); a.append(8); a.append(9);
        a.replace(1, 88);
        cout << "print  : " << a;
        cout << "elem(1): " << a.getElement(1) << "\n";
    });

    runCase("INT: search", [](){
        DoublyList<int> a;
        a.append(4); a.append(30); a.append(23);
        cout << "search(30): " << a.search(30) << "\n";
        cout << "search(999): " << a.search(999) << "\n";
    });

    runCase("INT: clear", [](){
        DoublyList<int> a;
        a.append(1); a.append(2);
        cout << "before clear: " << a;
        a.clear();
        cout << "after clear : " << a;
        cout << "isEmpty: " << a.isEmpty() << "\n";
        cout << "length : " << a.getLength() << "\n";
    });

    // -------------------------
    // ERROR TESTS
    // -------------------------
    runCase("INT: getElement out of bounds", [](){
        DoublyList<int> a;
        a.append(1);
        cout << a.getElement(1) << "\n";   
    });

    runCase("INT: insert out of bounds", [](){
        DoublyList<int> a;
        a.append(1);
        a.insert(5, 99);                  
    });

    runCase("INT: remove out of bounds", [](){
        DoublyList<int> a;
        a.append(1);
        a.remove(-1);                     
    });

    runCase("INT: replace out of bounds", [](){
        DoublyList<int> a;
        a.append(1);
        a.replace(2, 999);                
    });

    // -------------------------
    // STRING LIST TESTS
    // -------------------------
    runCase("STRING: append/insert/remove/search", [](){
        DoublyList<string> s;
        s.append("May");
        s.append("Your");
        s.append("Heart");
        cout << "print: " << s;

        s.insert(3, "Beat");          // end
        s.insert(2, "Drums");         // middle
        cout << "after inserts: " << s;

        cout << "search(\"Heart\"): " << s.search("Heart") << "\n";
        cout << "search(\"Banana\"): " << s.search("Banana") << "\n";

        s.remove(1);                  // remove "Your"
        cout << "after remove(1): " << s;

        s.replace(0, "Let");
        cout << "after replace(0,\"Let\"): " << s;
    });

    cout << "\n\nDONE.\n";
    return 0;
}
