#include "Solicitud.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[]){
    Solicitud cliente;
    if(argc<3)
        printf("indicar IP y un numero de iteraciones\n");
    
    int consulta=1;
    int deposito=2;
    int saldo=0;
    int nsaldo=0;
    char cadena[]="1\n";
    //auto start = high_resolution_clock::now();
    for(int i = 0; i < atoi(argv[2]); i++){
        saldo=atoi(cliente.doOperation(argv[1], 7200,consulta, cadena));
        printf("Consultando, saldo: %i\n",saldo);
        nsaldo=atoi(cliente.doOperation(argv[1], 7200,deposito, cadena));
        if(nsaldo!=saldo+1){
			printf("Error: El saldo recibido  no corresponde, Recibido: %i, Esperado: %i\n",saldo+1,nsaldo);
			exit(0);
        }
        printf("Incrementando, saldo: %i\n",nsaldo);
        
    }
    saldo=atoi(cliente.doOperation(argv[1], 7200,consulta, cadena));
    printf("Consultando, saldo final: %i\n",saldo);
    //auto stop = high_resolution_clock::now();
    //auto duration = duration_cast<microseconds>(stop - start);
    // printf("%s %ld %s\n","Tiempo:", duration.count(), " microsegundos");
    printf("%s", "TRANSACCION EXITOSA.\n");

    return 0;
}