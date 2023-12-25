#include<iostream>
using namespace std;
class vecteur
{
private:
    int size;
    float* T;
public:
    vecteur();
    ~vecteur();
    vecteur(int);
    vecteur(const vecteur&);
    void show();
    bool equal(const vecteur&);
    vecteur sum(const vecteur&);
    int operator[](int);
    int operator*(const vecteur&);
    vecteur operator*(const int&);
    friend vecteur operator*(int,const vecteur&);
    vecteur& operator=(const vecteur&);
    bool operator==(const vecteur&);
    bool operator!=(const vecteur&);
    void setvalue(int,float);

};

vecteur::vecteur()
{
}
vecteur::vecteur(int taille)
{
    size=taille;
    T = new float[size];   
}
vecteur::~vecteur()
{
}
vecteur::vecteur(const vecteur &a){
    size=a.size;
    T=new float[a.size];
    for(int i=0;i<=size;i++)
    {
        T[i]=a.T[i];
    }
}
void vecteur::show(){
    for(int i=0;i<size;i++)
    {
        cout<<T[i]<<"\t";
    }
    cout<<'\n';
}
bool vecteur::equal(const vecteur&a){
    if(size==a.size)
    {
        for ( int i = 0; i < size; i++)
        {
            if(T[i]!=a.T[i])
            {
                return false;
            }
        }
        return true;
        
    }
    return false;
}
vecteur vecteur::sum(const vecteur&a){
    if(size==a.size){
        vecteur A(size);
        for (int i = 0; i < size; i++)
        {
            A.T[i]=T[i]+a.T[i];
        }
        return A;
    }
    throw 'error';
}
int vecteur::operator[](int i){
    return T[i];

}
int vecteur::operator*(const vecteur &A){
    float x;
    for (int i = 0; i < size; i++)
    {
        x+=T[i]*A.T[i];
    } 
    return x;
}
vecteur vecteur::operator*(const int& x){
    vecteur a(size);
    for (int i = 0; i < size; i++)
    {
        a.T[i]=T[i]*x;
    }
    return a;
}
vecteur operator*(int x,const vecteur &a){
    vecteur b(a.size);
    for (int i = 0; i < a.size; i++)
    {
        a.T[i]*=x;
    }
    return a;
}
vecteur& vecteur::operator=(const vecteur& v){
    if(this!=&v){
        delete [] T;
        size=v.size;
        T= new float[size];
        for (int i = 0; i < size; i++)
        {
            T[i]=v.T[i];
        }
    }
    return *this;
}
bool vecteur::operator==(const vecteur &v)
{
    return equal(v);
}
bool vecteur::operator!=(const vecteur &v)
{
    return !equal(v);
}
void vecteur::setvalue(int i,float x){
    T[i]=x;
}
int main(void){
    // vecteur a(3),b(3);
    // a.setvalue(0,1);
    // a.setvalue(1,1);
    // a.setvalue(2,1);
    // b.setvalue(0,2);
    // b.setvalue(1,2);
    // b.setvalue(2,2);
    // a.show();
    // b.show();
    // a=4*b;
    // cout<<'\n';
    // a.show();
    string a;
    a="hello";
    cout<<a;
}