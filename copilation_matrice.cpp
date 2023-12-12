#include <iostream>
using namespace std;

int **saisir_matrice(int l,int c){
	int **m;
	int i,j;
//saisir matrice:
     m=new int*[l];
     for(i=0;i<l;i++){
     	m[i]=new int[c];
	 }
	 //remplisage 
	 for(i=0;i<l;i++){
	 	for(j=0;j<c;j++){
	 		cout<<"m["<<i<<"]["<<j<<"]=";
	 		cin>>m[i][j];
		 }
	 }
	 cout<<"\n";
	 //Affichage
	 for(i=0;i<l;i++){
	 	for(j=0;j<c;j++){
	 		cout<<m[i][j]<<"\t";
		 }
		 cout<<"\n";
	 }
	 return m;
}
int *mot(){
	int *t;
	int taille,i,j;
	cout<<"taille=";
	cin>>taille;
	t=new int[taille+1];
	for(i=0;i<taille;i++){
		cout<<"t["<<i<<"]=";
		cin>>t[i];
	}
	return t;
}
int trace(int **m,int *t){
	int trc=m[0][t[0]];
	int cmp=1,i,j;
	while(cmp<sizeof(t)/sizeof(int) && trc!=-1){
		trc=m[trc][t[cmp]];
		cmp++;
	}
	return trc;
}
bool reconnaissance(int trace){
	return (trace==4||trace==3);
}

int main(int argc, char** argv) {
	int **m,*t;
	int resu;
	
	m=saisir_matrice(5,2);
	t=mot();
	resu=reconnaissance(trace(m,t));
	if(resu) cout<<"le mot est reconnu:";
	else cout<<"le mot n'est pas reconnu:";
	return 0;
}
