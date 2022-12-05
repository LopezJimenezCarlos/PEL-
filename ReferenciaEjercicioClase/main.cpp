#include <iostream>
#include <vector>


using std::cout; using std::endl;
using std::vector; using std::cin;
class MyClass {
private:
    int* data;

public:
    explicit MyClass(int d) {
        data = new int;
        *data = d;
        cout << "Constructor 1 is called" << endl;
    };

    MyClass(const MyClass& source):

    MyClass(*source.data) {

            cout << "Copy Constructor is called " << endl;

        }

    
        void getData(int &dato) const {
            dato=*data;
             
        }

        

        ~MyClass() {

            delete data;

            cout << "Destructor is called" << endl;

        }

    
    };

    void printVec(const vector<MyClass> &vec) {
        int dato;
    
        for (const auto & i : vec) {
            i.getData(dato);
            cout << dato << " ";

        }

        cout << endl;

    }

    
    int main() {

        vector<MyClass> vec;

            vec.push_back(MyClass(10));

        vec.push_back(MyClass(11));

        printVec(vec);

        cout << "------------------" << endl;

            return EXIT_SUCCESS;

    }