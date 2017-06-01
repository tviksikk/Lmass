#ifndef LIST_H
#define LIST_H
#include <iostream>

template <class T>
class SpisokMass
{  
   private:
	   int* list; 
	   int start; 
	   T* data; 
	   int usagecolvo; 
	   int maxCount; 
	   int end; 
   public:
	SpisokMass(int =1);
	SpisokMass(SpisokMass&);
	T get0(int);
	~SpisokMass();
	void del2();
	int get2(int);
	void del1();
	int get1();
	void add1(T);
	void add2(T);
	bool end0(int);
	void printDoblication()
	{
		for (int i = get1(); !end0(i); i = get2(i))
		{
			for (int z = get2(i); !end0(z); z = get2(z))
			{
				if(get0(i) == get0(z))
    				std::cout << get0(i) << " ";
			}
		}
	}
};
 
template <class T>
 SpisokMass<T>::SpisokMass<T>(int a)
{ 
	maxCount=a;
	usagecolvo= start= end =0;
	list= new int[maxCount];
	data= new T[maxCount];
	for(int i=0; i<maxCount; i++)
	{ 
		list[i]=-1;
		data[i]=0;
	}
}

template <class T>
SpisokMass<T>::SpisokMass<T>(SpisokMass<T>&a)
{
	maxCount=a.maxCount;
	usagecolvo=a.usagecolvo;
	start=a.start;
	end=a.end;
	list = new int[maxCount];
	data = new T[maxCount];
	for (int i = 0; i<maxCount; i++)
	{
		list[i] = a.list[i];
		data[i] = a.data[i];
	}
}

template <class T>
SpisokMass<T>::~SpisokMass<T>()
{
	delete[] list;
	delete[] data;
}

template <class T>
void SpisokMass<T>:: add1(T a)
{
	if(usagecolvo==0)
	{ 
	   list[0]=-2;
	   start=0;
	   end=0;
	   data[start]=a;

	}
	else
	{ 
		for(int i=0;i<maxCount;i++)
		{ 
			if(list[i]==-1)
			{
			  list[i]=start;
			  start=i;
			  data[i]=a; 
			  break; 
			}
		}
	}
	usagecolvo++;
}

template <class T>
void SpisokMass<T>:: add2(T a)
{
	if(usagecolvo==0)
	{ 
	   list[0]=-2;
	   start=0;
	   end=0;
	   data[end]=a;
	}
	else
	{ 
		for(int i=0;i<maxCount;i++)
		{ 
			if(list[i]==-1)
			{
			  list[end]=i;
			  end=i;
			  data[i]=a; 
			  list[i]=-2;
			  break; 
			}
		}
	}usagecolvo++;
}

template <class T>
void SpisokMass<T>:: del1()
{
	int S=start;
	start=list[start];
	list[S]=-1;
	usagecolvo--;
}

template <class T>
void SpisokMass<T>:: del2()
{
	for(int i=0; i<maxCount; i++)
	{
	  if(list[i]==end)
	  {
	    list[end]=-1;
		list[i]=-2;
		end=i;
		usagecolvo--;
		return;
	  }
	}
}

template <class T>
int SpisokMass<T>:: get1()
{
	return start;
}

template <class T>
int SpisokMass<T>:: get2(int a)
{
    return list[a];
}

template <class T>
bool SpisokMass<T>:: end0(int a)
{
	if(a==-2)
	{ return true; }
	return false;
}

template <class T>
T SpisokMass<T>:: get0(int end)
{
	return data[end];
}

#endif 
