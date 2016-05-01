#include "Sample.h"
#include <cstdlib>
#include <cstdio>

Sample::Sample(int l, std::vector<float> f)
{
	this->label=l;
	this->features=f;
}

int Sample::getlabel()
{
	return label;
}

int Sample::getfeaturessize()
{
	return features.size();
}

void Sample::show()
{
	printf("Label: %d", label);//cout<<"Label: "<<label<<endl;
	printf("Features: ");//cout<<"Features ";
	std::vector<float>::iterator it=features.begin();
	while(it!=features.end())
	{
		printf(" %.2f", *it);//cout<<" "<<*it;
		it++;
	}
	printf("\n");
}

std::vector<float> Sample::getfeatures()
{
	return features;
}