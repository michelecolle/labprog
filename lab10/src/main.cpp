#include <iostream>
#include <vector>
#include <memory>

class My_unique_ptr {
    // Implementation of a simple unique pointer
    public: 
        My_unique_ptr(std::vector<int>* p){ptr=p;}
        ~My_unique_ptr(){delete ptr;ptr = NULL;}
        std::vector<int> release(){return *ptr;}
        std::vector<int>* operator*(){return ptr;}
        std::vector<int>* operator->(){return ptr;}
    private:
        std::vector<int>* ptr;
};

int main() {
    std::cout<<"Esercizio 1"<<std::endl;
    std::vector<int> a{1,2,3};
    My_unique_ptr up(new std::vector<int>);
    std::vector<int>* test = *up;
    (*test).push_back(11);
    up->push_back(2);
    std::vector<int> b = up.release();
    std::cout << b[0] << " " << b[1]<< std::endl;
    std::cout<<"Esercizio 2"<<std::endl;
    //questo causa segmantation fault perché target viene eliminato due volte
    // std::cout<<"Test due unique ptr "<<std::endl;
    // int target = 778;
    // std::unique_ptr<int> p1{&target};
    // std::cout<<(*p1)<<std::endl;

    //questo funziona correttamente, il puntqatore viene eliminato dallo unique pointer
    std::unique_ptr<int> p1{new int(10)};
    std::cout<<(*p1)<<std::endl;

    //questo causa un crash in uscita dallo scope (NB: senza il get non compila)
    //std::unique_ptr<int> p2{p1.get()};


    //test make unique
    int initLen = 10;
    std::unique_ptr<std::vector<int>> uv = std::make_unique<std::vector<int>>(initLen);
    for(size_t i=0;i<initLen;i++){
        (*uv)[i] = i*33;
    }

    for(size_t i=0;i<initLen;i++){
        std::cout<<(*uv)[i] <<" ";
    }
    std::cout<<std::endl;

    //ora aggiungo 4 elementi
    uv->push_back(99);
    uv->push_back(999);
    uv->push_back(9999);
    uv->push_back(99999);

    for(size_t i=0;i<initLen+4;i++){
        std::cout<<(*uv)[i] <<" ";
    }
    std::cout<<std::endl;

    return 0;
}