#include <iostream>  
#include <cstring>  
  
class Chicken  
{  
private:  
    int age = 24;  
    char* name = nullptr;  
  
    void copyName(const char* _name)  
    {  
        if (_name != nullptr)  
        {  
            int len = strlen(_name) + 1;  
            name = new char[len];  
            strncpy(name, _name, len);  
        }  
        else  
        {  
            name = nullptr;  
        }  
    }  
  
public:  
    Chicken() : age(24), name(nullptr) {}  
  
    Chicken(int _age) : age(_age), name(nullptr) {}  
  
    Chicken(int _age, const char* _name) : age(_age), name(nullptr)  
    {  
        copyName(_name);  
    }  
  
    Chicken(const Chicken& other) : age(other.age), name(nullptr)  
    {  
        copyName(other.name);  
    }  
  
    Chicken& operator=(const Chicken& other)  
    {  
        if (this != &other)  
        {  
            age = other.age;  
            delete[] name;  
            copyName(other.name);  
        }  
        return *this;  
    }  
  
    Chicken(Chicken&& other) noexcept : age(other.age), name(other.name)  
    {  
        other.age = 0;  
        other.name = nullptr;  
    }  
  
    Chicken& operator=(Chicken&& other) noexcept  
    {  
        if (this != &other)  
        {  
            age = other.age;  
            delete[] name;  
            name = other.name;  
            other.age = 0;  
            other.name = nullptr;  
        }  
        return *this;  
    }  
  
    ~Chicken()  
    {  
        delete[] name;  
    }  
  
    void setAge(int _age)  
    {  
        age = _age;  
    }  
  
    void setName(const char* _name)  
    {  
        delete[] name;  
        copyName(_name);  
    }  
  
    const char* getName() const  
    {  
        return name;  
    }  
  
    const int& getAge() const  
    {  
        return age;  
    }  
};  



int main() {
    auto print = [](const Chicken &c) {
        std::cout << "Hi, everyone! My name is " << c.getName() 
                  << ", I am " << c.getAge() << " years old." << std::endl;
        };
    Chicken c(24, "Kunkun");
    print(c);

    Chicken d;    
    d = c;    
    print(d);
    
    Chicken a = c;    
    print(a);

    c.setName("Xukun Cai");    
    print(c);    
    print(a);    
    print(d);

    Chicken b;    
    b = d = c;    
    print(b);    
    print(d);
    return 0;
}