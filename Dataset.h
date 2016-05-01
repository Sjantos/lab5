#pragma once
#include <vector>
#include "Sample.h"
#include <cstdio>

/*
- Stwórz klasę `Dataset`, zawierającą:
    - wektor obiektów klasy `Sample`,
    - metodę `push_back()`, dodającą nową próbkę do wektora:
        - metoda ta powinna sprawdzać, czy wektor `features` dla każdej z wprowadzanych próbek jest tej samej długości.
*/

class Dataset 
{
public:
	std::vector<Sample *> dataset_vector;
	int samplesize=0;

public:
	Dataset()
	{};
	void push_back(Sample* s);
	void show();
	int size();
};