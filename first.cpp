#include <iostream>
#include<array> 
using namespace std;

// int** matrice() {
    // int l=4, c=3;
    // cout<<sizeof(int);
    // cout << "Enter the number of rows: ";
    // cin >> l;
    // cout << "Enter the number of columns: ";
    // cin >> c;

    // int** M = new int*[l];
    // for (int i = 0; i < l; i++) {
    //     M[i] = new int[c];
    // }

    // for (int i = 0; i < l; i++) {
    //     for (int j = 0; j < c; j++) {
    //         cout << "Enter the value of the cell M[" << i << "][" << j << "]: ";
    //         cin >> M[i][j];
    //     }
    // }
    // int M[4][3]={{1,-1,-1},{1,2,3},{1,-1,-1},{-1,-1,-1}}
    // return M;
// }

int* mot() {
    int taille;
    char x;
    cout << "Enter the size of the word: ";
    cin >> taille;
    int* T = new int[taille+1];
    T[0]=taille;
    for (int i = 1; i < taille+1; i++) {
        cout << "Enter the value of the cell T[" << i << "]: ";
        cin >> x;
        if( (int)x ==120||(int)x==88)
        {
            T[i]=4;
        }
        else{
            if((int)x==43){
                T[i]=5;
            }
            else{
                if((int)x==45){
                    T[i]=6;
                }
                else{
                    T[i]=(int)x-48;
                }
            }
        }
    }
    return T;
}

int trace(int M[][7], int* T, int taille) {
    int tr = M[0][T[1]];
    int cnt = 2;
    while (tr!=-1 && cnt<=taille){
        tr = M[tr][T[cnt]];
        cnt++;
        cout<<"cnt="<<cnt<<"  tr="<<tr;
    }
    return tr;
}

bool reconnaissance(int trace) {
    return (trace == 5|| trace == 3);
}

int main() 
{
    // int** M;
    int M[6][7]=
    {
        {-1, 1, 1, 1,-1, 2, 2},
        { 1, 1, 1, 1, 3,-1,-1},
        {-1, 1, 1, 1, 3,-1,-1},
        {-1,-1,-1,-1,-1, 4, 4},
        { 5, 5, 5, 5,-1,-1,-1},
        { 5, 5, 5, 5,-1,-1,-1}
    };
    int *motArray;
    // M = matrice();
    motArray = mot();
    int traceResult = trace(M,motArray,motArray[0]);

    if (reconnaissance(traceResult)) {
        cout << "The word is recognized.";
    } else {
        cout << "The word is not recognized.";
    }

    // Free allocated memory
    // for (int i = 0; i < sizeof(*M); i++) {
    //     delete[] M[i];
    // }
    // delete[] M;
    // delete[] motArray;

    return 0;
}