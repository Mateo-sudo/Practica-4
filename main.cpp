#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
using namespace std;

//Prototipo de red-------------------------------------------------------------------
class Red {
private:
    vector <char> Enrutadores;
    list <int> rutas;
    list <int> nruta;
public:
    void nombres ();
    void g_rutas();
    void agregar(int n, char b);


};
//-----------------------------------------------------------------------------------
class Enrutador{
private:
    list <int> datos;//costes
public:
    void ingresardatos();
};



void Red :: nombres(){

    char palabra;
    cout<<"cuando desee dejar de poner Enrutadores escriba [-] "<<endl;
    cout<<"Nombre del Enrutador : "<<endl;
    while (cin >> palabra) {
    if(palabra!=45){
        cout<<"Nombre del Enrutador : "<<endl;
    Enrutadores.push_back(palabra);}
    else{
    break;
    }

    }
    cout << "Enrutadores registrados : " << Enrutadores.size() << endl;
}


void Red::g_rutas(){
    int n;
    n=Enrutadores.size();

    if (n>2){
    for(int i=0;i<n;i++){
        if (i<(n-1)){
        cout<<"conexion de "<<Enrutadores[i]<<" --> "<<Enrutadores[i+1]<<" : ";
        int r;
        cin>>r;
        rutas.push_back(r);
        }
        else{
            cout<<"conexion de "<<Enrutadores[i]<<" --> "<<Enrutadores[0]<<" : ";
            int r;
            cin>>r;
            rutas.push_back(r);
        }
    }
    }if (n==2) {
        for(int i=0;i<n;i++){
            if (i<(n-1)){
            cout<<"conexion de "<<Enrutadores[i]<<" --> "<<Enrutadores[i+1]<<" : ";
            int r;
            cin>>r;
            rutas.push_back(r);
            }
    }

    }
    if (n<=1)cout<<"Se necesita más de un enrutador para hacer una red "<<endl;
//--------------------------------------
    for (auto j=rutas.begin();j!=rutas.end();j++) {
        for (int l=0;l<n;l++) {
            for(int m=0;m<n;m++){

                if(l==m) nruta.push_back(0);
                if (m==0 || l==1) nruta.push_back(*j);
                if (m==0 || l==(n-1)) nruta.push_back(*j);
                if (m==(l+1)) nruta.push_back(*j);
                else nruta.push_back(-1);
            }
        }
    }

    for (auto i=nruta.begin();i!=nruta.end();i++){
        for (auto i=nruta.begin();i!=nruta.end();i++){
            cout<<setw(10)<<*i;

        }cout<<endl;

    }
}


void Red::agregar(int n, char b){
    cout<<"Entre que enrutadores quieres poner el nuevo enrutador : "<<endl;


}


int main()
{
int n;
char b;
Red uno;

uno.nombres();
uno.g_rutas();
//cout<<"Agregue un enrutador: "<<endl;
//cout<<"Ingrese un nombre para el enrutador: ";
//cin>>b;
//uno.agregar(n,b);
}
