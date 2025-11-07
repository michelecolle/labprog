#include <iostream>

class MyVector {
public:
    //Costruttori
    MyVector(size_t size);
    //initializer list
    MyVector(std::initializer_list<double> lst);
    //copy constructor (deep copy)
    MyVector(const MyVector& other);
    // move constructor 
    MyVector(MyVector&& other);

    // destructor to free allocated memory, size é automatica e viene distrutta in autonomia
    ~MyVector() { delete[] data_; data_ = nullptr; } 
    //semplici funzioni membro che lascio inline
    //size
    size_t size() const { return written_size_; }
    size_t size_allocated() const { return allocated_size_; }
    //opeartor overloading
    double& operator[](size_t index) { return data_[index]; }
    const double& operator[](size_t index) const { return data_[index]; }
    MyVector& operator =(const MyVector& other);
    MyVector& operator =(MyVector&& other); //disabilito l'assegnazione per move per semplicità
    double at(size_t index) const;
    double& at(size_t index);
    void push_back(double value);
    void pop_back();
    void reserve(size_t new_size);
private:
    //molto interessante per l'ottimizzazione delle prestazioni
    //https://en.algorithmica.org/hpc/cpu-cache/cache-lines/
    //in pratica pacchetti di 8 double alla volta, ottimizzati per le CPU moderne
    //se invece sono previsti array molto grandi converrebbe utilizzare multipli della memory page (4KB o 8KB a seconda del sistema operativo)
    //https://en.wikipedia.org/wiki/Page_(computer_memory)
    const static size_t kCacheLineSize = 64 / sizeof(double); //8 doubles per cache line
    size_t written_size_;
    size_t allocated_size_;
    double* data_;
};
//funzioni membro
//costruttori
MyVector::MyVector(size_t size)
{
    written_size_ = size;
    allocated_size_ = ((size + kCacheLineSize - 1) / kCacheLineSize) * kCacheLineSize; //arrotondo per eccesso alla cache line successiva
    //chiamo new per allocare un array di interi di dimensione full_size_
    data_ = new double[allocated_size_];
    std::cout << "Base constructor called with Size requested: " << size << "\n";
}
MyVector::MyVector(std::initializer_list<double> lst)
{   
    size_t size = lst.size();
    written_size_ = size;
    allocated_size_ = ((size + kCacheLineSize - 1) / kCacheLineSize) * kCacheLineSize; //arrotondo per eccesso alla cache line successiva
    data_ = new double[allocated_size_];
    std::copy(lst.begin(), lst.end(), data_);
    std::cout << "Initializer list constructor called\n";
}
MyVector::MyVector(const MyVector& other)
{
    written_size_ = other.written_size_;
    allocated_size_ = other.allocated_size_;
    data_ = new double[allocated_size_];
    std::copy(other.data_, other.data_ + written_size_, data_);
    std::cout << "Copy constructor called\n";
}
MyVector::MyVector(MyVector&& other) : written_size_(other.written_size_), allocated_size_(other.allocated_size_), data_(other.data_) 
{
    other.written_size_ = 0;
    other.allocated_size_ = 0;
    other.data_ = nullptr;
    std::cout << "Move constructor called\n";
}
//funxioni membro
//overload operatore di assegnazione (deep copy)
MyVector& MyVector::operator =(const MyVector& other) 
{
    if (this != &other) { //evito self-assignment
        delete[] data_; //libero la memoria esistente, se non lo facessi avrei un memory leak 
        written_size_ = other.written_size_;
        allocated_size_ = other.allocated_size_;
        data_ = new double[allocated_size_];
        std::copy(other.data_, other.data_ + written_size_, data_);
    }
    std::cout << "Copy assignment operator called\n";
    return *this;
}
MyVector& MyVector::operator =(MyVector&& other){
    if (this != &other) { //evito self-assignment
        delete[] data_; //libero la memoria esistente, se non lo facessi avrei un memory leak 
        written_size_ = other.written_size_;
        allocated_size_ = other.allocated_size_;
        data_ = other.data_;
        other.written_size_ = 0;
        other.allocated_size_ = 0;
        other.data_ = nullptr;
    }
    std::cout << "Move assignment operator called\n";
    return *this;
}
//accesso agli elementi e overload operatori
double MyVector::at(size_t index) const
{
    if (index >= written_size_ || index < 0)
    {
        std::cerr << "Index out of bounds: " << index << "\n";
        throw std::out_of_range("Index out of bounds");
    }
    return (*this)[index];//devo dereferenziare this per chiamare l'operatore di accesso agli elementi
}
double& MyVector::at(size_t index)//se non metto la & ritorna una copia del valore, non posso usarla per assegnare, errore di compilazione
{
    if (index >= written_size_ || index < 0)
    {
        std::cerr << "Index out of bounds: " << index << "\n";
        throw std::out_of_range("Index out of bounds");
    }
    return (*this)[index];//devo dereferenziare this per chiamare l'operatore di accesso agli elementi
}
void MyVector::push_back(double value)
{
    if(written_size_>=allocated_size_){
        reserve(allocated_size_ + kCacheLineSize); //alloco un'altra cache line
    }
    data_[written_size_]=value;
    written_size_++;
}
void MyVector::pop_back()
{
    if(written_size_==0){
        std::cerr<<"Error: pop_back on empty vector\n";
        throw std::out_of_range("pop_back on empty vector");
    }
    written_size_--;
}
void MyVector::reserve(size_t new_size){
        if(new_size>allocated_size_){
            size_t new_allocated_size = ((new_size + kCacheLineSize - 1) / kCacheLineSize) * kCacheLineSize; //arrotondo per eccesso alla cache line successiva
            double* new_data = new double[new_allocated_size];
            std::copy(data_, data_ + written_size_, new_data);
            delete[] data_;
            data_ = new_data;
            allocated_size_ = new_allocated_size;
        }
    }


MyVector f(int n){
    MyVector v(n);
    for(size_t i=0;i<v.size();i++){
        v[i]=i*2.0;
    }
    return v;
}
void print_vector(const MyVector& v){
    for(size_t i=0;i<v.size();i++){
        std::cout<<"v["<<i<<"]="<<v.at(i)<<std::endl;
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
        std::cout << "__cplusplus = " << __cplusplus << std::endl;

    MyVector vec{89,99,234,1,1,5};
    for(size_t i=0;i<vec.size();i++){
        std::cout<<"vec["<<i<<"]="<<vec.at(i)<<std::endl;
    }
    std::cout<<"Size allocated: "<<vec.size_allocated()<<std::endl;
    std::cout<<"Size occupied: "<<vec.size()<<std::endl;

    //ATTENZIONE: qui entra in gioco il return value optimization (RVO) del compilatore
    //per evitare l'elisione del copy/move constructor ho impostato in cmake add_compile_options(-fno-elide-constructors)
    MyVector vec2(f(10));
    MyVector vec3 = f(30);
    vec3 = vec; //questo solo con il copy constructor e l'assegnazione predefinita (elisione?) crasha sul distruttore doppio delete
    //gestisco l'assegnazione tramite overload dell'operatore di assegnazione (deep copy)
    vec2 = f(30);//move assignment
    MyVector vec4(vec2);//copy constructor

    vec.at(2)=555.0;
    std::cout<<" AT MODIFIED vec2:"<<vec.at(2)<<std::endl;

    print_vector(vec4);
    vec4.push_back(777.0);
    std::cout<<"After push_back, vec4 size: "<<vec4.size()<<", allocated size: "<<vec4.size_allocated()<<std::endl;
    print_vector(vec4);
    vec4.pop_back();
    std::cout<<"After pop_back, vec4 size: "<<vec4.size()<<", allocated size: "<<vec4.size_allocated()<<std::endl;
    print_vector(vec4); 

    return 0;
}

//memory leak check:
/*
nella cartella del main con il suo cmakelists.txt
eseguire:

cmake -S . -B build-asan -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="-fsanitize=address -fno-omit-frame-pointer"
cmake --build build-asan

poi eseguire il programma con:
asanrun build-asan/memoryleak
NB: asanrun é un alias in ~/.bashrc
alias asanrun='ASAN_OPTIONS=detect_leaks=1:leak_check_at_exit=1'

*/