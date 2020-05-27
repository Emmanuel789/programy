#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>

using namespace std;

int J = 10, Q = 10, K = 10;
int A = 11;

int cards [] = {2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A};

bool gameplay = 1; //zmienna spradzajaca stan rozgrywki

int computer[10];		//tablice przechowujace wartosci wylosowanych kart
int player[10];

int sumcomp;		//suma kart gracza i krupiera
int sumplay;

void suma( int comp[], int play[]){	//obliczanie i wypisanie sumy kart w reku
	sumcomp = 0;
	sumplay = 0;
	
	for (int i=0; i<10; i++){
		sumplay +=play[i];
		
		if (sumcomp<17){
		sumcomp +=comp[i];
		}
	}
	
	//cout<<"Suma krupiera: " << sumcomp <<endl;
	cout<<"Suma gracza:   " << sumplay <<endl;
}

void sprawdz (){					//sprawdzenie kart- decyzja gracza
	if (sumplay >21){
		cout<< "Suma kart wieksza niz 21, przegrywasz!"<<endl;
		gameplay = 0;
	}
	
	if (sumplay > sumcomp || sumcomp > 21)
		{cout<<"Wygrywasz!"<<endl;}
	
	else if (sumcomp > sumplay)
		{cout<<"Przegrywasz!"<<endl;}
		
	else if (sumcomp == sumplay)
		{cout<<"Remis"<<endl;}

	gameplay = false;
}
	
void lose(){
	if (sumplay >21){
		cout<< "You lose"<<endl;
		gameplay = 0;
	}
	
}
	
int wybieranie(){
	int wybor;
	cout<<"Wybierz: sprawdz (1), lub dobierz karte (inna cyfra)"<<endl;
	cin>> wybor;
	cout<<endl<<endl;
	return wybor;
}

void pokaz(int ile){		//funkcja pokazujaca karty w reku gracza i 1 krupiera
	
	cout<<computer[1]<<endl<<endl;
	
	for (int i=0; i<ile; i++){
	cout<<computer[i]<<endl;
	}
	cout<< endl;
	
	for (int i=0; i<ile; i++){
	cout<<player[i]<<endl;
	}
	cout<< endl;
}


int main(){
	
	srand (time(NULL) );
	
	cout<<endl<<"Zadaniem gracza jest uzyskanie jak najbliżej ";
	cout<<"(ale nie więcej niż) 21 punktów. ";
	cout<<"Jeżeli gracz po dobraniu kart ma więcej niż 21 punktów, przegrywa."<<endl;
	cout<<"Gracz podejmuje decyzję – albo dobiera karty, aby uzyskać wynik bliższy ";
	cout<<"sumie 21, albo zatrzymuje te karty które posiada i sprawdza."<<endl;
	cout<<"Dla gracza widoczna jest tylko jedna z dwóch kart krupiera."<<endl<<endl;
		
	
//Rozpoczecie gry, gracz i krupier losuja po dwie karty
		
	int a = 0, b =0;
		
	for(int i=0; i<4; i++){
		int random = rand()%13;
		
		if ( i%2 == 0){		// 1 i 3 karta dla krupiera
			computer[a] = cards[random];
			a++;
		}
					
		else {				// 2 i 4 karta dla gracza
			player[b] = cards[random];
			b++;
		}
						
	}
		
	for (int i=2; i<10; i++){		//dopelnienie kart krupiera
		int random = rand()%13;
		computer[i] = random;
	}
		
	//pokaz(2);	// pokaz karty w reku krupiera i gracza
	
	//suma(computer, player);
	cout<<"  Pierwsza karta krupiera: "<<computer[0]<<endl<<endl;
	//Runda 1. 
	cout<<"  Karty gracza: "<<player[0]<<", "<<player[1]<<endl<<endl;

int karta = 3;

for (;;){
	//cout<<endl<<"nowy obieg"<<endl;
	//cout<<"Karta nr: "<<karta<<endl<<endl;
	
	
	
	int wybor = wybieranie();	//Gracz podejmuje decyzje czy dobiera karte czy czeka 
	
	if (wybor == 1){
	suma(computer, player);
	cout<<"Suma krupiera: " << sumcomp <<endl;
	sprawdz();
	}
			
	else{
			
			computer[karta-1] = rand()%13;
			player[karta-1] = rand()%13;
			
			cout<<"  Pierwsza karta krupiera: "<<computer[0]<<endl<<endl;
			
			suma(computer, player);
			cout<<endl;
		
			lose();
	}

	if (gameplay == false){
		cout<<endl<<"Koniec gry"<<endl;
		break;
	}

karta++;

}
}
 
