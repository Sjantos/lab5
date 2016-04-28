#pragma once
#include <vector>

/*
- Stwórz klasę `Sample`, zawierającą:
    - zmienną całkowitą `label`,
    - wektor liczb zmiennoprzecinkowych `features`,
- w konstruktorze klasy `Sample` przyjmuj oba te parametry,
- stwórz też dla nich *gettery*.
*/

class Sample 
{
	int label;
	std::vector<float> features;

public:
	Sample()
	{}
	Sample(int l, std::vector<float> f);
	int getlabel();
	int getfeaturessize();
	void show();
	std::vector<float> getfeatures();
	//~Sample();
};