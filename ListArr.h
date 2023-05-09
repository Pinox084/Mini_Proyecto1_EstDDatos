#include <queue>
#include <iostream>
using namespace std;
class ListArr{

private:


	struct Node{

		int size; //Tamaño total
		int n;	//Capacidad Total
		
		Node* Nodeizq;
		Node* Nodeder;
		int* arr;
		Node* cajanext;
		Node(int total){
			
			n = total;
			size = 0;
			Node* Nodeizq = nullptr;
			Node* Nodeder = nullptr;
			arr= new int[total];
			Node* cajanext= nullptr;
			
		}
		Node(){
			
			size = 0;
			Node* Nodeizq = nullptr;
			Node* Nodeder = nullptr;
			int* arr= nullptr;
			Node* cajanext= nullptr;
		}

	};
	std::queue<Node*> ListRes;
	int countarr;
	Node* Raiz=nullptr;
	Node* Inicial=nullptr;
	Node* Final=nullptr;
	
	

public:

	ListArr(int capacity, int particiones);
	
	~ListArr();
	
	int size(); 
	
	void Ramas();

	void DestRamas(Node* nodo);

	void DestArr();
 
	void insert_left(int dato);
	
	void insert_right(int dato); 
	
	int checksize(Node* arreglo);
	
	void insert(int dato, int pos);
	
	void print(); 
	
	bool find(int soli); 
	


};
