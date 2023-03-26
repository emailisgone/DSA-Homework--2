#include "intcont.cpp"

int main(){
    IntCont container;

    // Position always >= 1 !!!
    for(int i=1; i<=10; ++i){
        container.add(i);
    }
    //std::cout<<container;

    //std::cout<<container.getSize();
    container.removeAt(4);
    container.removeAll(6);
    container.addLast(2248);

    for(int i=1; i<=10; ++i){
        container.add(1654);
    }

    std::cout<<container<<container.getSize()<<" "<<container.getMaxSize();


    return 0;
}