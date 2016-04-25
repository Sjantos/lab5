#include "Sample.h"

Sample::Sample(int l, std::vector<float> f)
{
	label=l;
	features=f;
}

Sample::~Sample()
{

}

int Sample::getlabel()
{
	return label;
}

int Sample::getfeaturessize()
{
	return features.size();
}

/*std::vector<float>::iterator Sample::getfeatures()
{
	return features.begin();
}*/