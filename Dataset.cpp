#include "Dataset.h"

void Dataset::push_back(Sample* s)
{
	//int samplesize=0;
	if(dataset_vector.empty())
	{
		dataset_vector.push_back(s);
		samplesize=s->getfeaturessize();
	}
	else if(!dataset_vector.empty() && s->getfeaturessize()==samplesize)
	{
		dataset_vector.push_back(s);
	}
		//dataset_vector.push_back(s);
}

void Dataset::show()
{
	std::vector<Sample *>::iterator it=dataset_vector.begin();
	while(it!=dataset_vector.end())
	{
		(*it)->show();
		it++;
	}
	//printf("Size %d  ", dataset_vector.size());
}

int Dataset::size()
{
	return dataset_vector.size();
}
