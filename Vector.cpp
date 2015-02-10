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
jdg::vec3<value_type>::vec3(){
	components[0] = (value_type)0;
	components[1] = (value_type)0;
	components[2] = (value_type)0;
}

template<class value_type>
jdg::vec3<value_type>::vec3(vec3<value_type> const& rhs):
components(rhs.components) {
}

template<class value_type>
value_type jdg::vec3<value_type>::getMagnitude()
{
	return
	sqrt( pow(components[0], 2) +
		  pow(components[1], 2) +
		  pow(components[2], 2)
		 );
}

template<class value_type>
jdg::vec3<value_type>& jdg::vec3<value_type>::operator+= (vec3<value_type> const& rhs)
{
	components[0] += rhs.components[0];
	components[1] += rhs.components[1];
	components[2] += rhs.components[2];
}