#include "ListArr.h"
#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <time.h>
#include <cstdlib>

using namespace std;
int main(){
	ListArr arbolito(1000,1000);
	/*arbolito.insert_right(60);
	arbolito.print();
    arbolito.insert_left(1);
    arbolito.print();
    
	arbolito.insert_left(2);
	arbolito.print();
	
	arbolito.insert_left(3);
	arbolito.print();
	
	arbolito.insert_right(40);
	arbolito.print();
	
	arbolito.insert_right(50);
	arbolito.print();
	arbolito.insert_left(3);
	arbolito.print();
	arbolito.insert_left(3);
	arbolito.insert_left(3);
	arbolito.insert(100,2);
	arbolito.insert(100,2);
	arbolito.insert(100,2);
	arbolito.find(50);
	arbolito.find(100);
	arbolito.find(523);*/

	int datos[100000];
	int random[100000];
	
	srand(time(NULL));
	
	int num;
	
	for(int i = 0; i<40000; i++){
		num = 0 + rand()%(101) ;
		
		
		if((num>=0) && (num<=35)){
				
			random[i] = 1;			
		}
		
		if(num > 45 && num <= 65){
			random[i] = 2;
		}
		if(num>65 && num<=100){
			random[i] = 3;
		}
		
	}
	
	for(int i = 0; i<40000;i++){
		
		cout<< random[i]<< " ";
	}
	cout<< ""<<endl;
	for(int i = 0; i<40000;i++){
		num = 0 + rand()%(5000) ;
		datos[i] = num;
	}
	cout<<"" <<endl;
	for(int i = 0; i<40000;i++){
		
		cout<< datos[i]<< " ";
	}
	cout<<"" <<endl;
	float promedio;
	int total = 3;
	
    for(int i = 0; i< 1;i++){
    	auto start_time= chrono::high_resolution_clock::now();
	
		for(int i = 0; i<40000; i++){
			if(random[i] == 1){
				arbolito.insert_left(i);
			}
			if(random[i] == 2){
				
				arbolito.insert(i, i/2);
			}
			if(random[i] == 3){
				arbolito.insert_right(i);
			}
				
		}
	
		auto end_time=chrono::high_resolution_clock::now();
    	chrono::duration<float, milli> duration = end_time - start_time;
    	cout<< duration.count()<<"s\n"<<endl;
	}
	
	
	
	
	arbolito.print();
	cout<< "Total Final de la Raiz:" << arbolito.size()<<endl;
	arbolito.~ListArr();
	return 0;
}


