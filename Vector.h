//
//  Vector.h
//  Clue
//
//  Created by Jonathan Gillis on 2/9/15.
//  Copyright (c) 2015 JDG Corp. All rights reserved.
//

#ifndef __Clue__Vector__
#define __Clue__Vector__

namespace jdg {

	template<class value_type>
	class vec3
	{

		value_type components[3];
	public:
		vec3();
		vec3(vec3<value_type> const& rhs);
		value_type getMagnitude();

		//Arithmetic functions
		vec3& operator+=(vec3 const& rhs);

		///scalar multiplication
		vec3& operator*=(value_type scalar);
	};
}


#endif /* defined(__Clue__Vector__) */
