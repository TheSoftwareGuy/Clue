//
//  Vector.h
//  Clue
//
//  Created by Jonathan Gillis on 2/9/15.
//  Copyright (c) 2015 JDG Corp. All rights reserved.
//

#ifndef __Clue__Vector__
#define __Clue__Vector__

//TODO
//#include <initializer_list>
#include <cstddef>
using std::size_t;

namespace jdg {

	template<class value_type>
	class vector3
	{
		friend class vec3Test;
		value_type components[3];
	public:
		vector3();
		explicit vector3(vector3<value_type> const& rhs);

		vector3(std::initializer_list<value_type> init);

		value_type getX() const;

		value_type getY() const;

		value_type getZ() const;

		value_type getMagnitude();

		value_type& operator[](const size_t idx);

		//Arithmetic functions
		vector3& operator+=(vector3 const& rhs);

		///scalar multiplication
		vector3& operator*=(value_type scalar);
	};
	
	template<class value_type>
	value_type dotP(vector3<value_type> const& lhs, vector3<value_type> const& rhs);
}


//Implementations
template<class value_type>
jdg::vector3<value_type>::vector3()
{
	components[0] = (value_type)0;
	components[1] = (value_type)0;
	components[2] = (value_type)0;
}

template<class value_type>
jdg::vector3<value_type>::vector3(vector3<value_type> const& rhs):
components(rhs.components)
{
}

 template<class value_type>
 jdg::vector3<value_type>::vector3(std::initializer_list<value_type> init)
 {
	 components[0] = static_cast<value_type>(0);
	 components[1] = static_cast<value_type>(0);
	 components[2] = static_cast<value_type>(0);
	 int i =0;
	 for(auto iter=init.begin(); iter != init.end(); ++i, ++iter){
		 components[i] = *iter;
	 }
 }


template<class value_type>
value_type jdg::vector3<value_type>::getX() const
{
	return components[0];
}

template<class value_type>
value_type jdg::vector3<value_type>::getY() const
{
	return components[1];
}

template<class value_type>
value_type jdg::vector3<value_type>::getZ() const
{
	return components[2];
}

template<class value_type>
value_type jdg::vector3<value_type>::getMagnitude()
{
	return
	sqrt( pow(components[0], 2) +
	  pow(components[1], 2) +
	  pow(components[2], 2)
		 );
}

template<class value_type>
value_type& jdg::vector3<value_type>::operator[](const size_t idx)
{
	return components[idx];
}

template<class value_type>
jdg::vector3<value_type>& jdg::vector3<value_type>::operator+= (vector3<value_type> const& rhs)
{
	components[0] += rhs.components[0];
	components[1] += rhs.components[1];
	components[2] += rhs.components[2];

	return *this;
}

template<class val_t>
jdg::vector3<val_t>& jdg::vector3<val_t>::operator*=(val_t scalar)
{
	*this[0] *= scalar;
	*this[1] *= scalar;
	*this[2] *= scalar;
	return *this;
}

template<class value_type>
value_type jdg::dotP(vector3<value_type> const&lhs, vector3<value_type> const& rhs)
{
	return lhs[0]*rhs[0] + lhs[1]*rhs[1] + lhs[2]*rhs[2];
}




#endif /* defined(__Clue__Vector__) */
