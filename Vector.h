//
//  Vector.h
//  Clue
//
//  Created by Jonathan Gillis on 2/9/15.
//  Copyright (c) 2015 JDG Corp. All rights reserved.
//

#ifndef __Clue__Vector__
#define __Clue__Vector__

#include <initializer_list>

namespace jdg {

	template<class value_type=double>
	class vector3
	{

		value_type components[3];
	public:
		vector3();
		explicit vector3(vector3<value_type> const& rhs);
		vector3(std::initializer_list<value_type> init);
		value_type getMagnitude();

		value_type& operator[](size_t idx){
			return components[idx];
		}

		//Arithmetic functions
		vector3& operator+=(vector3 const& rhs);

		///scalar multiplication
		vector3& operator*=(value_type scalar);
	};
	
	template<class value_type>
	value_type dotP(vector3<value_type> const& lhs, vector3<value_type> const& rhs);
}


#endif /* defined(__Clue__Vector__) */
