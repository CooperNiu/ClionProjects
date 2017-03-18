//
// Created by Cooper on 15/03/2017.
//

#ifndef FLOWSHOP_JOBTYPE_H
#define FLOWSHOP_JOBTYPE_H

class Jobtype
{
 public:
  int operator <= (Jobtype a)const
  {
	  return (key <= a.key);
  }
  
  int key, index;
  bool job;
};

#endif //FLOWSHOP_JOBTYPE_H
