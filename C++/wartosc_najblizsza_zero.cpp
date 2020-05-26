#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int flag=0;
int a;  //najmniejsza wartosc tablicy


int main()
{
	
cout<<endl<<"Program wyszukuje liczby najblizszej 0 z podanego zbioru."<<endl;
cout<<"W przypadku dwoch liczb o tej samej wartosci bezwzglednej zwracana jest wartosc dodatnia"<<endl<<endl;	
	
int arr[6]={};

cout<<"podaj 6 liczb:"<<endl;

//uzupelnianie tablicy
for (int i=0; i<6; i++)
	{
		cin>>arr[i];
	}

//sprawdzenie, czy ktorys z elementow jest rowny 0
for(int j=0; j<6; j++)
	{
		if(arr[j]==0)
		{
		cout<<"jeden z elementow tablicy jest rowny 0"<<endl<<endl;
		flag=1;
		break;
		}
	}
	
if (flag==0)
{
//sprawdzenie elementu najblizszego 0

a=arr[0];

for (int x=1; x<6; x++)
{
	if( abs(a)>abs(arr[x]) )
	a=arr[x];
}

//w przypadku obecnosci dodatniej i ujemnej najmniejszej liczby o tej samej wartosci bezwzglednej zwroc dodatnia
for (int y=1; y<6; y++)
{
	if (abs(a)==arr[y])
	a=abs(a);	
}


cout<<endl<<"Liczba najblizsza 0 to "<<a<<endl;
return 0;
}

}
