#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdlib.h>     
#include <time.h>       

template <class T>
class Array {
   private:
			T				*values;
			unsigned int	_size;

   public:
		Array() : values(new T()), _size(0) {};
		Array(unsigned int n) : values(new T[n]), _size(n) {}
		Array(const Array &array): values( new T[array.size()] ), _size(array.size())  {
			for ( unsigned int i = 0 ; i < _size; i++ )
				values[i] = array.values[i];
		};
    	~Array() { delete [] values; }

	Array& operator=(const Array& otherArray) 
	{
		if ( this != &otherArray ) 
		{
			delete [] values;
			values = new T[otherArray.size()];
			_size = otherArray.size();
			for ( unsigned int i = 0 ; i < _size; i++ )
				values[i] = otherArray[i];
		}
		return *this;
	}

	T& operator[](unsigned int idx) const 
	{
		if ( idx >= _size )
            throw OutOfArrayRangeException();
		return values[idx];
	}


	unsigned int size() const {return _size;};



	class OutOfArrayRangeException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Index is out of range";}
	};
};

template < typename T >
std::ostream& operator<<( std::ostream& out, const Array<T>& arr ) {
    for ( unsigned int i (0); i < arr.size(); i++ )
        out << arr[i] << " ";
    return out;
}
#endif