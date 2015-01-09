#include "BTagWeight2.hpp"
#include <math.h>
#include <iostream>
using namespace std;
bool BTagWeight::filter(int t)
{
  return (t >= minTags && t <= maxTags);
}
double BTagWeight::weight(vector<JetInfo> jets, int tags)
{
  if(!filter(tags))
    {
      // std::cout << "This event should not pass the selection, what is it doing here?" << std::endl;
      return 0;
    }
  int njets=jets.size();
  int comb= 1 << njets;
  double pMC=0;
  double pData=0;
  for(int i=0;i < comb; i++)
    {
      double mc=1.;
      double data=1.;
      int ntagged=0;
      for(int j=0;j<njets;j++)
	{
	  bool tagged = ((i >> j) & 0x1) == 1;
	  if(tagged)
	    {
	      ntagged++;
	      mc*=jets[j].eff;
	      data*=jets[j].eff*jets[j].sf;
	    }
	  else
	    {
	      mc*=(1.-jets[j].eff);
	      data*=(1.-jets[j].eff*jets[j].sf);
	    }
	}
      if(filter(ntagged))
	{
	  //std::cout << mc << " " << data << endl;
	  pMC+=mc;
	  pData+=data;
	}
    }
  if(pMC==0) return 0;
  return pData/pMC;
}
