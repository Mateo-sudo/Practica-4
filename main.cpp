#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

//Prototipo de red-------------------------------------------------------------------

class Red {
private:
    vector <char> Enrutadores;
    vector <int> rutas;
    vector <int> nruta;
    vector <int> tabla;
public:
    void nombres ();
    void g_rutas();
    void ordenar();
    void agregar();
    void Eliminar();
};
//-----------------------------------------------------------------------------------
class Enrutador{
private:
    char nombre;
    vector<int> datos;
    //costes
public:
    void setnombre(char _nombre){
        nombre=_nombre;
    }
    void setdatos(vector<int>);
    char getnombre();
    vector<int> getdatos();
    void impr();
};

void Enrutador::setdatos(vector<int> _datos){

    for (auto k =_datos.begin(); k!=_datos.end(); ++k) {      
            datos.push_back(*k);
    }
}
void Enrutador:: impr(){
    cout<<"Enrutador : "<<nombre;
    for (auto k = datos.begin(); k!=datos.end(); ++k) {
            cout<<setw(10)<<*k;
    }cout<<endl;
}
char Enrutador::getnombre(){
    return nombre;
}
vector <int> Enrutador::getdatos(){
        return datos;
}
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
vector<Enrutador> red;
void Red::g_rutas(){
    red.clear();
    rutas.clear();
    nruta.clear();
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


}
void Red::agregar(){
    char nuevo;
    cout<<"nombre del enrutador nuevo : "<<endl;
    cin>>nuevo;
    Enrutadores.push_back(nuevo);
    g_rutas();
    ordenar();
}
void Red::ordenar(){
    int n;

    n=rutas.size();
    for (int j=0;j<n-1;j++){
       if (j==0){
           nruta.push_back(rutas[n-1]);
           nruta.push_back(rutas[j]);
       }
        nruta.push_back(rutas[j]);
        nruta.push_back(rutas[j+1]);
    }

    for (int i=0;i<n;i++) {

        int par=0,impar=1;
        int sum=0;
            for (int j=0;j<n;j++) {

                if (nruta[i*2]==nruta[impar]){
                    sum++;
                    tabla.push_back(nruta[i*2]);

                }
                if (nruta[(i*2)+1]==nruta[par]){
                    sum++;
                    tabla.push_back(nruta[(i*2)+1]);
                }
                if (sum==0) {
                    tabla.push_back(sum);

                }

                par=par+2;
                impar=impar+2;
                sum=0;
            }cout<<endl;

            Enrutador E;
            E.setnombre(Enrutadores[i]);
            E.setdatos(tabla);
            red.push_back(E);
            tabla.clear();
        }

}
void Red::Eliminar(){
    char Eliminar;
    cout<<"nombre del enrutador a Eliminar : "<<endl;
    cin>>Eliminar;
    int tam;
    tam=Enrutadores.size();
    vector<char> elim;
    elim=Enrutadores;
    Enrutadores.clear();
    for (int r = 0; r < tam; ++r) {
        if (Eliminar!=elim[r]){
            Enrutadores.push_back(elim[r]);
        }
    }
   g_rutas();
   ordenar();
}

int main()
{

Red uno;
uno.nombres();
uno.g_rutas();
uno.ordenar();
for ( auto k=red.begin(); k != red.end(); k++ ){
    cout<<setw(10)<<k->getnombre();
    k->getnombre();
    vector<int> l;
    l=k->getdatos();
    for (auto i=l.begin();i!=l.end();i++) {
        cout<<setw(10)<<*i;
    }cout<<endl;
}
uno.Eliminar();

//for ( auto k=red.begin(); k != red.end(); k++ )
  // k->impr();

for ( auto k=red.begin(); k != red.end(); k++ ){
    cout<<setw(10)<<k->getnombre();
    vector<int> l;
    l=k->getdatos();
    for (auto i=l.begin();i!=l.end();i++) {
        cout<<setw(10)<<*i;
    }cout<<endl;

    /*
    for (auto j = k->getdatos().begin(); j != k->getdatos().end(); ++j) {
          cout<<setw(10)<<*j;
    }*/
}



}
