#pragma once
#include "Sample.h"

/*
- Stwórz klasę `Prediction`, dziedziczącą po klasie `Sample`, dodającą do niej zmienną `prediction`,
- Rozszerz ją o metodę statyczną `accuracy()`, przyjmującą wektor obiektów klasy `Prediction`, informującą o tym, w jakim odsetku ich zmienne `label` i `prediction` mają tę samą wartość.
*/

class Prediction : public Sample
{
	int prediction;

public:
	Prediction(int l, std::vector<float> f)
	{
		
	}
};