#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TAMA 100

char *tiposProductos[] = {"Galletas", "Snacks", "Cigarrillos", "Caramelos", "Bebidas"};

struct
{

    int productoID;
    int cantidad;       // entre 1 a 10
    char *tipoProducto; // algun valor del arreglo tipoProducto
    float precioU;      // entre 10-100

} typedef producto;

struct
{

    int clienteID;
    char *nombreCliente; // ingresado por el usuario
    int cantProdAPedir;  // aleatorio entre 1 y 5
    producto *productos; // el tamaño depende de la variable cantProdAPedir

} typedef cliente;


void cargarClientesYProductos(cliente *puntero, int cantidad);
void mostrarClientesYProductos(cliente *puntero, int cantidad);
float costo(producto producto);

int main()
{

    srand(time(NULL));
    // yo soy preventista y me solicitan:

    cliente *Mclientes;
    int cantClientes; 
   

    printf("\nIngrese la cantidad de clientes:");
    scanf("%d", &cantClientes);

    Mclientes = (cliente*)malloc(cantClientes * sizeof(cliente)); // arreglo dinamico de clientes

    cargarClientesYProductos(Mclientes,cantClientes);
    mostrarClientesYProductos(Mclientes,cantClientes);
    

    return 0;
}

void cargarClientesYProductos(cliente *puntero, int cantidad){

    char nombre[TAMA];
    int longCadena;

    //cargamos datos del cliente
    for (int i = 0; i < cantidad; i++)
    {
        puntero->clienteID = rand()% 6 + 1; 

        printf("\nIngrese el nombre:");
        fflush(stdin);
        gets(nombre);

        longCadena = ( strlen(nombre) + 1 );

        puntero->nombreCliente = (char*) malloc(longCadena * sizeof(char));
        strcpy(puntero->nombreCliente,nombre);

        puntero->cantProdAPedir = rand()%6 +1;  //aleatorios de 1 a 5

        //arreglo dinamico de productos del cliente
        puntero->productos = (producto*)malloc(puntero->cantProdAPedir * sizeof(producto)); 

        //Cargamos el producto
        for (int j = 0; j < puntero->cantProdAPedir; j++)
        {
            //id producto
            puntero->productos[j].productoID = rand()%5 + 1;

            //cantidad
            puntero->productos[j].cantidad = rand()%10 + 1; //aleatorio de 1 a 10 prod

            //tipo de producto del arreglo inicializado global
            int aleatorio = rand()%5;// 0 a 4
            puntero->productos[j].tipoProducto = tiposProductos[aleatorio];
            
            //precio unitario valores del 10 al 100
            puntero->productos[j].precioU = rand () % 91 + 10;

        }

        puntero++;

    }
    
}

void mostrarClientesYProductos(cliente *puntero, int cantidad){

    float suma, aux, TotalPagar;

   for (int i = 0; i < cantidad; i++)
   {  
        printf("\n------------Datos Cliente------------");
        printf("\nCliente:%d",puntero->clienteID);
        printf("\nNombre:%s", puntero->nombreCliente);
        printf("\nCantidad de productos:%d", puntero->cantProdAPedir);
        printf("\n-------------Producto-----------------");
        for (int j = 0; j < puntero->cantProdAPedir; j++)
        {
            printf("\n ID Producto:%d",puntero->productos[j].productoID);
            printf("\n Cantidad:%d", puntero->productos[j].cantidad);
            printf("\nTipo:%s",puntero->productos[j].tipoProducto);
            printf("\nPrecio:%.2f",puntero->productos[j].precioU);
            aux = costo(puntero->productos[j]);
            suma = suma + aux;
            printf("\n");
        }
        
        puntero++;
        printf("\n");

        printf("\n total a pagar es:%.2f",suma);
   }
   
   suma = 0;

}

float costo(producto producto){

    return (producto.precioU * producto.cantidad);

}

