//
//  Vector.cpp
//  Clue
//
//  Created by Jonathan Gillis on 2/9/15.
//  Copyright (c) 2015 JDG Corp. All rights reserved.
//
#include "Vector.h"
#include <cmath>

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

/* TODO
template<class value_type>
jdg::vector3<value_type>::vector3(std::initializer_list<value_type> init)
{
	components[0] = init[0];
	components[1] = init[1];
	components[2] = init[2];
}
*/

template<class value_type>
value_type jdg::vector3<value_type>::getX() const
{
	return components[0];
}

template<cla/Users/gillis/Projects/Clue/Clue/test.cppss value_type>
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
