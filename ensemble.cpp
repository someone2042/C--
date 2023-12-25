#include <iostream>

using namespace std;

class Ensemble {
  private:
     int taille ;
     int nbr_element ;
     int* Tab ;
  public:
     Ensemble() ;
     Ensemble(const Ensemble &);
     Ensemble(int t) ;
     ~Ensemble();
     bool estVide();
     int cardinal();
     void operator+(int);
     Ensemble operator+(const Ensemble &);
     Ensemble& operator=(const Ensemble &);
     bool operator>(int);
     bool operator>(const Ensemble &);
     friend ostream& operator<<(ostream & , const Ensemble&);
     friend istream& operator>>(istream & , Ensemble&);
};
 int main(){
    Ensemble e1 ;

    if(e1.estVide()) cout << "e1 est vide \n";
    else cout << "e1 n'est pas vide \n" ;

    cout << "le cardinal de e1 est :" << e1.cardinal(); cout << endl;

    Ensemble e2(e1);

    e1 + 17 ;
    e1 + 7 ;
    e2 + 3 ;
    e2 + 7 ;

    cout << e1 ;  cout << endl;

    Ensemble e3 ;
    e3 = e1 + e2 ;

    if(e1 > 7 ) cout << "7 app a e1 \n" ;
    else cout << "7 n'est pas app a e1 \n";

    if (e2 > e1) cout << "e1 est inclus dans e2 \n";
    else cout << "e1 n'est pas inclus dans e2 \n";
    cin >> e1 ;
    cout << e1 ;  cout<< endl ;
    cout << e2 ;  cout << endl ;
    cout << e3 ;
    return 0 ;
 }
//  #######################################################
 Ensemble :: Ensemble(){
    taille = 10 ;
    Tab = new int [taille] ;
    nbr_element = 0 ;
 }
 Ensemble :: Ensemble(const Ensemble & E){
     taille = E.taille ;
     Tab = new int [taille] ;
     nbr_element = E.nbr_element;
     for(int i=0 ; i < nbr_element ; i++)
        Tab[i] = E.Tab[i] ;
 }
 Ensemble :: Ensemble(int t) {
     taille = t ;
     Tab = new int [taille] ;
     nbr_element = 0;
 }
 Ensemble :: ~Ensemble(){
     if(Tab) delete []Tab ;
 }
 bool Ensemble :: estVide(){
     return nbr_element==0 ;
 }
 int Ensemble :: cardinal(){
     return nbr_element ;
 }
 void Ensemble :: operator+(int val){
    // on suppose toujours que le nbr_element < taille
     if( !(*this > val) )
        Tab[nbr_element++] = val ;
 }
 Ensemble Ensemble :: operator+(const Ensemble& E){
     Ensemble unione(taille + E.taille );
     int i=0 ;
     while(i<nbr_element)
        unione + Tab[i++] ;
     i=0;
     while(i< E.nbr_element)
        unione + E.Tab[i++] ;
     return unione ;
 }
 Ensemble& Ensemble :: operator=(const Ensemble &E){
     if (this != &E) {
        delete [] Tab;
        taille = E.taille ;
        Tab = new int [taille];
        nbr_element = E.nbr_element ;
        for(int i = 0 ;i < nbr_element ; i++)
          Tab[i] = E.Tab[i];
     }
     return *this ;
 }
 bool Ensemble :: operator>(int val){
     int i=0 ;
     while (i<nbr_element && Tab[i]!= val) i++;
     return i != nbr_element ;
 }
 bool Ensemble :: operator>(const Ensemble &E){
     int j=0 ;
     for(int i=0 ; i< E.nbr_element ; i++){
        if(*this > E.Tab[i]) j++ ;
	 }
     return j == E.nbr_element ;
 }
 ostream& operator<<(ostream &os , const Ensemble&E){
 	 os << E.nbr_element << "  " ;
     os << "[" ;
     for(int i=0 ; i< E.nbr_element ; i++){
        os << E.Tab[i] ;
        if(i!= E.nbr_element-1) os << ",";
     }
     os << "]";
     return os ;
 }
 istream& operator>>(istream& is , Ensemble&E){
 	  int n , x ;
 	  E.nbr_element = 0 ;
 	  do{
	  cout << "entrer le nombre element : " ;
 	  is >> n ;
 	  }while(n > E.taille);
 	  for(int i=0 ; i<n ; i++){
 	  	 cout << "entrer l'element " << i << " : ";
 	  	 is >> x ;
 	  	 E+x ;
      }
      return is ;
}