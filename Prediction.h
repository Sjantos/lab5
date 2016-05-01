#pragma once
#include "Sample.h"
#include <cstdio>

/*
- Stwórz klasę `Prediction`, dziedziczącą po klasie `Sample`, dodającą do niej zmienną `prediction`,
- Rozszerz ją o metodę statyczną `accuracy()`, przyjmującą wektor obiektów klasy `Prediction`, informującą o tym, w jakim odsetku ich zmienne `label` i `prediction` mają tę samą wartość.
*/

class Prediction : public Sample
{
public:
	int prediction;

public:
	Prediction(int l, std::vector<float> f):Sample(l, f)
	{
		/*label=l;
		features=f;*/
		//prediction=p;
	}
	static float accuracy(std::vector<Prediction *> vectorofpredicts)
	{
		int good=0;
		std::vector<Prediction *>::iterator it=vectorofpredicts.begin();
		while(it!=vectorofpredicts.end())
		{
			//printf("label: %d   predi: %d \n", (*it)->getlabel(), (*it)->prediction);
			if((*it)->getlabel()==(*it)->prediction) good++;
			it++;
		}
		//printf("good: %d", good);

		return (float)good/(float)vectorofpredicts.size();
	}
};