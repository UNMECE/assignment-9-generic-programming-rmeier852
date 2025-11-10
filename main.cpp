#include<iostream>
#include<cmath>
using namespace std;


template <typename T>

class GenericArray
{
	private:
		T* array;
		int array_size=0;

	public:
		//default constructors
		GenericArray(){array_size=0; array=0;}

		//destructors
		~GenericArray(){delete[] array;}

		//functions
		void addElement(T element)
		{
			T *newArray = new T[array_size+1];
			//copy everything from old array into new array using for loop
			for(int i=0; i<array_size; i++)
			{
				newArray[i]=array[i];
			}
			//add 1 new element to the end of new array
			array_size++;
			newArray[array_size-1]=element;
		
			//delete the old array
			delete []array;

			//update array
			array=newArray;
		}

		T at(int index){T value=array[index]; return value;}

		int size(){return array_size;}

		T sum()
		{
			T sumTemp=0; 
			for(int i=0; i<array_size; i++)
			{
				sumTemp+=array[i];
			}
			return sumTemp;
		}

		T max()
		{
			T maxTemp=array[0];
			for(int i=1; i<array_size; i++)
			{
				if(maxTemp<array[i])
				{
					maxTemp=array[i];
				}
			}
			return maxTemp;
		}

		T min()
		{
			T minTemp=array[0];
			for(int i=1; i<array_size; i++)
			{
				if(minTemp>array[i])
				{
					minTemp=array[i];
				}
			}
			return minTemp;
		}
	
		T* sliceArray(int begin, int end)
        	{
                	int new_size=end-begin+1;
			T* slice = new T[new_size];
                	for(int i=0; i<new_size; i++)
                	{
                        	slice[i]=array[begin+i];
                	}

                	return slice;
		}
};

int main()
{

	GenericArray<int> int_array;

	int_array.addElement(10);
	int_array.addElement(20);
	int_array.addElement(6);
	int_array.addElement(2);
	int_array.addElement(38);
	int_array.addElement(-4);

	cout<<"At index 2 the value is: "<<int_array.at(2)<<endl;
	cout<<"Size of the array: "<<int_array.size()<<endl;
	cout<<"Sum of the array: "<<int_array.sum()<<endl;
	cout<<"Max of the array: "<<int_array.max()<<endl;
	cout<<"Min of the array: "<<int_array.min()<<endl;

	int* sliced_array=int_array.sliceArray(1,3);
	cout<<"Sliced Array from 1-3:"<<endl;
	cout<<"[";
	for(int i=0; i<3; i++)
	{
		cout<<sliced_array[i]<<", ";
	}
	cout<<"]"<<endl;

	return 0;
}
