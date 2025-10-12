#include <iostream>
#include <cstring>

void    cppy(char *dest, const char *src)
{
    for (size_t i = 0; i < 13; i++){
        dest[i] = src[i];
        if((i + 1) == 12)
            dest[i + 1] = '\0';
    }
    return ;
}
class str{
    private:
        char name[13];
        int age;
    public:
        str(){
            std::strcpy(name, "NULL");
            age = 0;
        }
        str(const str& other){
            std::cout << "Copy constructor called\n";
            cppy(name, other.name);
            age = other.age;
        }
        void    set_artibiute(const char *n_name, int n_age){
            strcpy(name, n_name);
            age = n_age;
        }
        void show(){
            std::cout << "name is : " << name << std::endl;
            std::cout << "age is : " << age << std::endl;
        }
};

int main(){

    str a;
    a.set_artibiute("ayoub adouay", 26);
    str b = a; // copy constractor !!
    // str b(a); //
    b.show();
}