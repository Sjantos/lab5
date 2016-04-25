#include "Sample.h"
#include "Dataset.h"
#include "Prediction.h"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>

/*
- Jako argumenty wiersza poleceń programu, przekaż nazwę pliku oraz liczbę całkowitą `k`,
- dla celów testowych, w repozytorium znajduje się plik `wine.csv`,
- wczytaj plik `wine.csv` do wektora obiektów typu `Sample` tak, aby pierwsza jego kolumna określała `label`, a pozostałe znalazły się w wektorze `features`,
- stwórz dwa obiekty klasy `Dataset`. Pierwszy nazwij `train`, drugi `test`,
- do `train` wprowadź losowe 20% wczytanych z pliku obiektów, a do `test`, resztę,
- zaimplementuj funkcję `knn()`, zwracającą wektor obiektów klasy `Prediction` przyjmującą jako argumenty dwa obiekty typu `Dataset` (`train` i `test`) i zmienną całkowitą `k`:
    - utwórz w niej wektor `predictions`:
    - do utworzonego wektora wprowadź kopie wszystkich obiektów (mają typ `Sample`) znajdujących się w `test`, uzupełniając dla nich wartość `prediction`, według następującego schematu:

>   Dla każdego obiektu ze zbioru testowego znajdź `k` obiektów ze zbioru uczącego, którego cechy (`features`) znajdują się w najmniejszej od niego [odległości](https://pl.wikipedia.org/wiki/Odległość). Za `prediction` uznaj `label`, który powtarza się najczęściej wśród znalezionych.
>   

- Wyświetl użytkownikowi informacje o zbiorze (nazwa pliku, liczba próbek, liczba cech) oraz jakość klasyfikacji (`accuracy()`).
*/

using namespace std;

vector <Prediction *> knn(Dataset *train, Dataset *test, int k);

int main(int argc, char const *argv[])
{
	string filename = argv[1];
	//int k = atoi(argv[2]);
	fstream file;
	file.open(filename, fstream::in);
	std::vector<Sample> vectorofsamples;
	string row;
	while(file.good())
	{
		getline(file, row);
		//cout<<row<<endl;
		string::iterator it=row.begin();
		bool comma=false;
		string label="", feat=""; char com=',';
		while(it!=row.end())
		{
			if(*it==com) comma=true;
			if(comma)
			{
				feat+=*it;
			}
			else
			{
				label+=*it;
			}
			it++;
		}
		cout<<"LABEL "<<label<<"    FEAT "<<feat<<endl;
	}
	file.close();
}