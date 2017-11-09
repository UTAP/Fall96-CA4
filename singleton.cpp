#include <iostream>

class SomeClass{
private:
    SomeClass(){};
    static SomeClass* instance;
public:
    static SomeClass* get_instance();
};

SomeClass* SomeClass::instance = NULL;

SomeClass* SomeClass::get_instance(){
    if(SomeClass::instance == NULL){
        std::cout<<"initing"<<std::endl;
        SomeClass::instance = new SomeClass();
    }
    return SomeClass::instance;
}

int main(){
    SomeClass* instance = SomeClass::get_instance();
    return 0;
}
