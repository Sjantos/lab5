#include "Sample.h"
#include "Dataset.h"
#include "Prediction.h"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
#include <cmath>

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

void fileload(string filename);
void filldataset(int percent, Dataset *set);
double distance(Sample s1, Sample s2);
void sort( double tab[][2], int left, int right );

vector <Prediction *> knn(Dataset *train, Dataset *test, int k);
std::vector<Sample> vectorofsamples;
Dataset train, test;
int numberofsamples;




int main(int argc, char const *argv[])
{
	string filename = argv[1];
	//int k = atoi(argv[2]);
	fileload(filename);
	srand(time(NULL));
	numberofsamples=vectorofsamples.size();
	//cout<<numberofsamples<<endl;
	int perc=numberofsamples/5;
	//cout<<"perc "<<perc<<endl;
	filldataset(perc, &train);
	//cout<<endl<<endl<<numberofsamples;
	filldataset(numberofsamples, &test);
	train.show();
	test.show();





}

void fileload(string filename)
{
	fstream file;
	file.open(filename, fstream::in);
	string row;
	while(file.good())
	{
		getline(file, row);
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

		std::vector<float> featvector;
		string::iterator ite=feat.begin();
		string number="";
		while(ite!=feat.end())
		{
			if(*ite==com)
			{
				float num=atof(number.c_str());
				featvector.push_back(num);
				number="";
			}
			else
			{
				number+=*ite;
			}
			ite++;
		}
		float num=atof(number.c_str());
		featvector.push_back(num);
		int l=atoi(label.c_str());
		featvector.erase(featvector.begin());
		Sample sam(l, featvector);
		//sam.show();
		vectorofsamples.push_back(sam);
	}
	file.close();
}

void filldataset(int percent, Dataset *set)
{
	for(int i=0; i<percent; i++)
	{
		int index=rand()%numberofsamples;
		set->push_back(vectorofsamples[index]);
		vectorofsamples.erase(vectorofsamples.begin()+index);
		numberofsamples--;
	}
}

double distance(Sample s1, Sample s2)
{
	double distance=0;
	for(int i=0; i<s1.getfeaturessize(); i++)
	{
		distance+=pow(s1.getfeatures()[i]-s2.getfeatures()[i],2);
	}
	distance=sqrt(distance);

	return distance;
}

vector <Prediction *> knn(Dataset *train, Dataset *test, int k)
{
	std::vector<Prediction *> predictions;
	for(unsigned int i=0; i<test->dataset_vector.size(); i++)
	{
		Prediction p(test->dataset_vector[i].getlabel(), test->dataset_vector[i].getfeatures());
		predictions.push_back(&p);
		/*double distancetab[train->dataset_vector.size()][2];
		for(unsigned int j=0; j<test->dataset_vector.size(); j++)
		{
			distance[j][0]=distance(*train->dataset_vector[j], *test->dataset_vector[i]);
			distance[j][1]=train->dataset_vector[j]->getlabel();

		}
		sort(distance, 0, train->dataset_vector.size()-1);*/
	}

	return predictions;
}

void sort( double tab[][2], int left, int right )
 {
    int i = left;
    int j = right;
    double x = tab[( left + right ) / 2 ][0];
    do
    {
    	while( tab[ i ][0] < x ) i++;
         
        while( tab[ j ][0] > x ) j--;        
        if( i <= j )
        {
            swap( tab[ i ][0], tab[ j ][0] );
            swap( tab[ i ][1], tab[ j ][1] );            
            i++;
            j--;
        }
     }while( i <= j );
     
    if( left < j ) sort( tab, left, j );
    if( right > i ) sort( tab, i, right );
     
 }

 /*int popular(double tab[][2], int k)
 {
 	int size=0;
 	for(int i=0; i<k; i++) if(size<tab[i][1]) size=tab[i][1];
 	int t[size+1];
 	for(int i=0; i<size+1; i++) t[i]=0;

 }*/