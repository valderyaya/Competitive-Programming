std::istream & operator >>(std::istream &in,Dish &d){
    std::string s;
    in>>s;
    if(s=="Ramsay"){
        int x;
        in>>x;
        d.food = new IdiotSandwich(x);
    }else d.food = new NormalSandwich(s);
    return in;
}
void NormalSandwich::print(std::ostream &out){
    out<<name<<". Masterpiece of sandwiches.";
}
void IdiotSandwich::print(std::ostream &out){
    out<<"An idiot sandwich with intelligence level "<<intelligence<<" only.";
}
Dish::~Dish(){delete food;}
