#include <iostream>




class Object {       
  public:            
    int a;        
    Object() { 
      
    }~Object();
};


int main(int, char**) {
    
    Object* p = new Object[10];
    
    delete []p;
    
    
   
}
