#include<iostream>
using namespace std;
class pile
{
private:
    float *T;
    int size;
    int pos;
public:
    pile();
    pile(int size);
    pile(const pile&);
    void empiler(float);
    void affiche();
    float depiler();
    bool nonvide();
    void vider();
    bool nonpleine();
    bool vide();
    void depiler(float&);
    ~pile();
};

pile::pile(){
    T= new float[100];
    this->size=100;
    pos=-1;
}
pile::pile(int size)
{
    T= new float[size];
    this->size=size;
    pos=-1;
}
void pile::empiler(float a){
    if(pos<size-1){
        pos++;
        T[pos]=a;
    }
}
float pile::depiler(){
    return T[pos--];
}
void pile::affiche(){
    for(int i=0;i<=pos;i++)
    {
        cout<<T[i]<<"\t";
    }
}
bool pile::nonvide(){
    return pos!=-1;
}
pile::pile(const pile &a){
    pos=a.pos;
    size=a.size;
    T=new float[a.size];
    for(int i=0;i<=pos;i++)
    {
        T[i]=a.T[i];
    }
}
void pile::vider(){
    pos=-1;
}
bool pile::nonpleine(){
    return pos!=size-1;
}
bool pile::vide(){
    return pos==-1;
}
void pile::depiler(float& a){
    a=T[pos--];
}

pile::~pile()
{
}
int main(){
    float x;
    pile s(100); // tableau de 100 réels
    s.empiler(10);
    s.affiche();
    cout<<"\n---------------------\n";
    s.empiler(20);
    s.affiche();
    cout<<"\n---------------------\n";
    s.empiler(30);
    s.affiche();
    cout<<"\n---------------------\n";
    x=s.depiler();
    s.affiche();
    cout<<"\n---------------------\n";
    cout<<"x="<<x<<"\n";
    s.empiler(s.depiler());
    cout<<"\n---------------------\n";
    s.affiche();
    if(s.nonvide()) x=s.depiler();
    s.affiche();
    pile P(s) ; // Copie qui doit être profonde
    P.affiche();
    s.vider();// vider la pile
    s.affiche();
    P.affiche() ;// P reste inchangé (pas le cas si la copie est superficielle)
    cin>>x;
    while(s.nonpleine()) s.empiler(x);
    s.affiche();
    while(!s.vide()) s.depiler(x);
}
