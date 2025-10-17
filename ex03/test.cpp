#include <iostream>

class Youtub_chanel{
    private:
        std::string name;
        int folowers;
    public:
        Youtub_chanel(std::string User, int folowers_count){
            name = User;
            folowers = folowers_count;
        }
        std::string&    get_name(){
            return name;
        }
        int get_flw(){
            return folowers;
        }
};

std::ostream&    operator<<(std::ostream& os, Youtub_chanel& chanel){
    os << "name : " << chanel.get_name() << std::endl;
    os << "folowers : " << chanel.get_flw() << std::endl;
    return os;
}

int main(){
    Youtub_chanel yt1("ayoub adouay", 702);

    std::cout << yt1 << yt1;
    // operator<<(std::cout, yt1);
}