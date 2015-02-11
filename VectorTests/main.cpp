//
//  main.cpp
//  VectorTests
//
//  Created by Jonathan Gillis on 2/9/15.
//  Copyright (c) 2015 JDG Corp. All rights reserved.
//

#include <gtest/gtest.h>
#include <iostream>
#include <cmath>
#include "math/Vector.h"

using vec3 = jdg::vector3<double>;
class vec3Test  : public ::testing::Test
{
protected:
};

TEST_F(vec3Test, TestDefaultConstructor)
{
	vec3 vec;

	EXPECT_EQ(0, vec[0]);
	EXPECT_EQ(0, vec[1]);
	EXPECT_EQ(0, vec[2]);
}


TEST_F(vec3Test, TestInitializerListConstructor )
{
	vec3 * v = new vec3({12.0, 1.2, 14.6});

	EXPECT_EQ(12.0, (*v)[0]);
	EXPECT_EQ(1.2,  (*v)[1]);
	EXPECT_EQ(14.6, (*v)[2]);
	delete v;

	//test with only 2-length list
	v = new vec3({12.0, 1.2});
	EXPECT_EQ(12.0, (*v)[0]);
	EXPECT_EQ(1.2,  (*v)[1]);
	EXPECT_EQ(0.0,  (*v)[2]);
	delete v;

	//test with only 1 element in list
	v = new vec3({112.0});
	EXPECT_EQ(112.0, (*v)[0]);
	EXPECT_EQ(0.0,   (*v)[1]);
	EXPECT_EQ(0.0,   (*v)[2]);
	delete v;
}

TEST_F(vec3Test, TestMagnitude)
{
	vec3 testVec;
	testVec[0] = 3.0;
	testVec[1] = 4.0;
	testVec[2] = 3.0;

	EXPECT_EQ(sqrt(
			  pow(3.0,2)
			+ pow(4.0,2)
			+ pow(3.0,2))
			  ,
			  testVec.getMagnitude()
			  );

}

TEST_F(vec3Test, TestDotProduct)
{
	vec3 r, F;
	r[0] = 12.0;
	F[1] = 12.0;

	EXPECT_EQ(0, dotP(r,F));
}



int main(int argc, char * argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
