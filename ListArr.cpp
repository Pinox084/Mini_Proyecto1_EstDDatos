#include <iostream>
#include <queue>
#include "ListArr.h"
using namespace std;

ListArr:: ListArr(int capacity, int particiones){
	
		
		int aux = capacity/particiones;
		
		Node* temp = new Node(particiones);
		
		Inicial = temp;		

		countarr = aux;
		for (int i = 0; i < aux-1; ++i){
			
			Node* temp2 = new Node(particiones);
			temp2->arr = new int[particiones];
			temp->cajanext = temp2;
			temp = temp2;

		}
		Final = temp;
		Final->cajanext=nullptr;
		Ramas();
	
}
ListArr:: ~ListArr(){

	DestRamas(Raiz);
	DestArr();
}


int ListArr:: size(){
	return Raiz-> size;
} 

void ListArr:: Ramas(){
	
	Node* current = Inicial;
	queue<Node*> lista; 
	
    
    Node* temp;
    
    while(current != nullptr)
    {
        lista.push(current);
        current = current->cajanext;
    }
    
    Node* nodo;
    Node* nodo2;
    if(lista.size() == 1){

        nodo = lista.front();

        lista.pop();

        temp = new Node();

        temp->Nodeizq =  nodo;

        temp->n = nodo->n;

        temp->size =  nodo->size;
		ListRes.push(temp);
        lista.push(temp);
        

    }
    while(lista.size() != 1){

        int aux = lista.size()/2;
        int aux2 = lista.size()%2;
        
        for (int i = 0; i < aux; ++i)
        {
            nodo = lista.front();

            lista.pop();

            nodo2 = lista.front();

            lista.pop();

            temp = new Node();

            temp->Nodeizq =  nodo;

            temp->n = nodo->n;

            temp->size = nodo->size;

            temp->Nodeder = nodo2;

            temp->n = temp->n + nodo2->n;

            temp->size = temp->size + nodo2->size;
            
            ListRes.push(temp);
           

            lista.push(temp);

        }
        if(aux2 != 0){

            lista.push(lista.front());
            lista.pop();
        }
        
    }
    
    
    nodo = lista.front();
    lista.pop();
    Raiz = nodo;
    
    
    

}
void ListArr:: DestRamas(Node* nodo){

	while(ListRes.size() != 0){
		Node* aux = ListRes.front();
		ListRes.pop();
		delete aux;
	}

}

void ListArr:: DestArr(){
	
	Node* current = Inicial;
	while(current != nullptr){
		Node* next = current->cajanext;
		delete current;
		current = next;
	}
	Inicial = nullptr;
	Final = nullptr;
	
}
int ListArr::checksize(Node* arreglo) { //Cambia el size del nodo resumen
	
		
	
    if(arreglo->n == Inicial->n){
    	
    	
        return arreglo->size;
        
    } else{
        int aux = checksize(arreglo->Nodeizq) + checksize(arreglo->Nodeder);
        arreglo->size = aux;
        
        return aux;
    }
    
    

}
void ListArr:: insert_left(int dato){
	cout<< "Left "<< endl;
	if(Inicial -> n == Inicial-> size){
		
		Node* temp = new Node(Inicial->n);
		temp->arr[0] = dato;
		
		
		temp->cajanext = Inicial;
		Inicial = temp;
		DestRamas(Raiz);
		Node* current = Inicial;
		
		temp->size++;
		Ramas();
		
	}else{
		
		for (int i = Inicial->size; i > 0; --i)
		{
			Inicial->arr[i] = Inicial->arr[i-1];
		}
		
		Inicial->arr[0] = dato;
		Inicial->size++;
		
		Raiz-> size = checksize(Raiz);
		
		
	}
}

void ListArr:: insert_right(int dato){
	cout<< "Right "<< endl;
	if(Final->n == Final->size){
	
		
		Node* temp = new Node(Final->n);
		
		temp->size++;
		
		
		temp->arr[0] = dato;
		temp->cajanext = Final->cajanext;
		Final->cajanext = temp;
		Final = temp;
		DestRamas(Raiz);
		
		
		Ramas();
		
		
	}else{
		
		
		Final->arr[Final->size] = dato;
		
		Final->size++;
		
		Raiz->size = checksize(Raiz);
		
		
	}
}

void ListArr:: insert(int dato, int pos){
	cout<< "Insert  "<< endl;
	cout<<"Dato:"<< dato << "  Pos:"<< pos <<endl;
	cout<< Raiz->size <<endl;
	Node* current = Raiz;
	if(pos > Raiz->size || pos<= 0){
		cout<< "Imposible "<< endl;
	}else{
		
		while(current->n != Inicial-> n ){
		

		    if(pos< current->Nodeizq->size){
			    current = current->Nodeizq;
	
		    }else{
			pos = pos - current->Nodeizq ->size;
			current =  current-> Nodeder;
			
			}
		}

		if(current-> n == current-> size){
			Node* temp = new Node(Inicial->n);
			
			temp->arr[0] = dato;
			int aux=current->arr[current->size - 1];

			for (int i = current->size; i > pos; --i)
			{
				current->arr[i] = Inicial->arr[i-1];
			}
			temp->arr[0]=aux;
			temp->size++;
			temp->cajanext = current->cajanext;
			current->cajanext = temp;
			DestRamas(Raiz);
			Ramas();
		}
		else{
			int aux;
			if(pos==current->size - 1){
				aux=current->arr[current->size-1];
				current->arr[current->size-1]=dato;
				current->arr[current->size]=aux;
				current->size++;
				
				Raiz->size = checksize(Raiz);
			
			}else{
				
				for (int i = current->size; i >= pos; --i)
				{
					current->arr[i] = current->arr[i-1];
				}
				current->arr[pos] = dato;
				current->size++;
				
				Raiz->size = checksize(Raiz);
				
			}
		}	
	}
	

}

void ListArr:: print(){
	Node* current = Inicial;
	int count = 0;
	cout<<"[ ";
	while(current != nullptr){
		if(count == current->size){
			cout<<"]";
			count = 0;
			current = current->cajanext;
			
			cout<<"[ ";
			
		}
		else{
			
			cout << current->arr[count] <<"("<<count<<") ";
			count++;
			
		}
	}
	cout<<" "<< endl;
} 

bool ListArr:: find(int soli){
	Node* current = Inicial;
	int count = 0;
	while(current != nullptr){

		
		if(current->arr[count] == soli){
			cout<< "Existe "<< soli << endl;
			return true;
		}
		count++;
		if(count == current->size){
			
			current = current->cajanext;
			count = 0;
		}
		
	}
	cout<< "No existe"<< endl;
	return false;
} 
