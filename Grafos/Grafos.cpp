#include <iostream>
using namespace std;
//representación a traves de una matriz de adyaciencia
#define tam 500
class ColaCircular
{
    //atributos
    int tamanho = tam;
    int elementos[tam];
    int indiceInicio;
    int indiceFinal;
    int cantidadElementos;
public:
    //construtor
    ColaCircular()
    {
        indiceInicio = 0;
        indiceFinal = 0;
        cantidadElementos = 0;
    }
    //metodos
    bool ColaLlena()
    {
        if (cantidadElementos >= tamanho)
            return true;
        else
            return false;
    }
    bool ColaVacia()
    {
        if (cantidadElementos <= 0)
            return true;
        else
            return false;
    }
    void Insertar(int elemento)
    {
        if (ColaLlena())
        {
            cout << "La cola esta llena" << endl;
        }
        else
        {
            cantidadElementos++;
            elementos[indiceFinal] = elemento;
            indiceFinal = indiceFinal + 1;
            if (indiceFinal >= tamanho)
                indiceFinal = 0;
        }
    }
    int Quitar()
    {
        if (ColaVacia())
        {
            cout << "La cola esta vacia" << endl;
        }
        else
        {
            int valorRetornar = elementos[indiceInicio];
            indiceInicio = indiceInicio + 1;
            if (indiceInicio >= tamanho)
                indiceInicio = 0;
            cantidadElementos--;
            return valorRetornar;
        }
    }
    void Imprimir()
    {
        int indice = indiceInicio;
        for (int i = 0; i < cantidadElementos; i++)
        {
            cout << elementos[indice] << "\t";
            indice++;
            if (indice >= tamanho)
                indice = 0;
        }
        cout << endl;
    }

};
class Pila
{
    //atributos
    int tamanho = tam;
    int elementos[tam];
    int indice;
public:
    //constructor
    Pila()
    {
        indice = 0;
    }
    //métodos
    //Pila llena
    bool PilaLlena()
    {
        if (indice == tamanho)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //Pila vacia
    bool PilaVacia()
    {
        if (indice == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //Insertar elemento
    void Insertar(int elemento)//Push
    {
        if (PilaLlena())
        {
            cout << "La pila esta llena." << endl;
        }
        else
        {
            elementos[indice] = elemento;
            indice = indice + 1;
        }
    }
    /// Quitar elemento
    int Quitar() // Pop
    {
        if (PilaVacia())
        {
            cout << "No hay en elementos en la pila" << endl;
            return NULL;
        }
        else
        {
            indice = indice - 1;
            return elementos[indice];
        }
    }
    //Imprimir
    void Imprimir()
    {
        for (int i = indice - 1; i >= 0; i--)
        {
            cout << "|\t" << elementos[i] << "|" << endl;
            cout << "-----------" << endl;
        }
    }
    void Invertir()
    {
        int indicePosterior = indice - 1;
        for (int i = 0; i < indice / 2; i++)
        {
            int temp = elementos[i];
            elementos[i] = elementos[indicePosterior];
            elementos[indicePosterior] = temp;
            indicePosterior--;
        }
    }
};
class MatrizAdyacencia
{
    int cantidadNodos;
    int matriz[tam][tam];
    string diccionario[10];
public:
    MatrizAdyacencia(int nodos, string dic[10])
    {
        cantidadNodos = nodos;
        for (int i = 0; i < tam; i++)
        {
            for (int j = 0; j < tam; j++)
            {
                matriz[i][j] = 0;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            diccionario[i] = dic[i];
        }

    }
    int getCantidadNodos()
    {
        return cantidadNodos;
    }
    void Imprimir()
    {
        for (int i = 0; i < cantidadNodos; i++)
        {
            for (int j = 0; j < cantidadNodos; j++)
            {
                cout << "\t" << matriz[i][j];
            }
            cout << endl;
        }
    }
    void VicularNodos(int inicio, int destino, int valor)
    {
        matriz[inicio][destino] = valor;
        //en caso sea grafo no dirido
        //matriz[destino][inicio] = valor;
    }
    void RecorridoAnchura(int nodoInicio)
    {
        int nodoRecorrido[tam] = { 0 };

        ColaCircular cola = ColaCircular();
        cola.Insertar(nodoInicio);
        nodoRecorrido[nodoInicio] = 1;
        while (!cola.ColaVacia())
        {
            int elemento = cola.Quitar();
            cout << diccionario[elemento] << "\t";
            for (int i = 0; i < cantidadNodos; i++)
            {
                if (matriz[elemento][i] > 0 && nodoRecorrido[i] == 0)
                {
                    nodoRecorrido[i] = 1;
                    cola.Insertar(i);
                }
            }
        }
    }

    void RecorridoAltura(int nodoInicio)
    {
        int nodoRecorrido[tam] = { 0 };

        Pila pila = Pila();
        pila.Insertar(nodoInicio);
        nodoRecorrido[nodoInicio] = 1;
        while (!pila.PilaVacia())
        {
            int elemento = pila.Quitar();
            cout << diccionario[elemento] << "\t";
            for (int i = 0; i < cantidadNodos; i++)
            {
                if (matriz[elemento][i] > 0 && nodoRecorrido[i] == 0)
                {
                    nodoRecorrido[i] = 1;
                    pila.Insertar(i);
                }
            }
        }
    }
};
int main()
{
    /*MatrizAdyacencia obj = MatrizAdyacencia(4);
    cout << "matriz inicial" << endl;
    obj.Imprimir();
    obj.VicularNodos(0, 1, 30);
    obj.VicularNodos(1, 2, 60);
    obj.VicularNodos(2, 3, 80);
    obj.VicularNodos(1, 3, 120);
    cout << "matriz final" << endl;
    obj.Imprimir();
    cout << "Recorrido por anchura" << endl;
    obj.RecorridoAnchura(0);*/
    string diccionario[10];
    diccionario[0] = "A";
    diccionario[1] = "B";
    diccionario[2] = "C";
    diccionario[3] = "D";
    diccionario[4] = "H";
    diccionario[5] = "T";
    diccionario[6] = "R";

    MatrizAdyacencia obj = MatrizAdyacencia(7, diccionario);
    cout << "matriz inicial" << endl;
    obj.Imprimir();
    obj.VicularNodos(3, 1, 1);
    obj.VicularNodos(3, 2, 1);
    obj.VicularNodos(1, 4, 1);
    obj.VicularNodos(2, 6, 1);
    obj.VicularNodos(6, 4, 1);
    obj.VicularNodos(4, 3, 1);
    obj.VicularNodos(4, 0, 1);
    obj.VicularNodos(4, 5, 1);
    cout << "matriz final" << endl;
    obj.Imprimir();
    cout << "Recorrido por anchura" << endl;
    obj.RecorridoAnchura(3);
    cout << endl << "Recorrido por altura" << endl;
    obj.RecorridoAltura(3);

}
