///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2014 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2008-08-31
// Updated : 2008-08-31
// Licence : This source is under MIT License
// File    : test/core/type_mat4x3.cpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <glm/vector_relational.hpp>
#include <glm/mat4x3.hpp>
#include <vector>

static int test_operators()
{
	glm::mat4x3 l(1.0f);
	glm::mat4x3 m(1.0f);
	glm::vec4 u(1.0f);
	glm::vec3 v(1.0f);
	float x = 1.0f;
	glm::vec3 a = m * u;
	glm::vec4 b = v * m;
	glm::mat4x3 n = x / m;
	glm::mat4x3 o = m / x;
	glm::mat4x3 p = x * m;
	glm::mat4x3 q = m * x;
	bool R = m != q;
	bool S = m == l;

	return (S && !R) ? 0 : 1;
}

int test_ctr()
{
	int Error(0);

#if(GLM_HAS_INITIALIZER_LISTS)
	glm::mat4x3 m0(
		glm::vec3(0, 1, 2), 
		glm::vec3(3, 4, 5),
		glm::vec3(6, 7, 8),
		glm::vec3(9, 10, 11));

	glm::mat4x3 m1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

	glm::mat4x3 m2{
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		{9, 10, 11}};

	for(int i = 0; i < m0.length(); ++i)
		Error += glm::all(glm::equal(m0[i], m2[i])) ? 0 : 1;

	for(int i = 0; i < m1.length(); ++i)
		Error += glm::all(glm::equal(m1[i], m2[i])) ? 0 : 1;

	std::vector<glm::mat4x3> v1{
		{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
		{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
	};

	std::vector<glm::mat4x3> v2{
		{
			{ 0, 1, 2 },
			{ 4, 5, 6 },
			{ 8, 9, 10 },
			{ 12, 13, 14 }
		},
		{
			{ 0, 1, 2 },
			{ 4, 5, 6 },
			{ 8, 9, 10 },
			{ 12, 13, 14 }
		}
	};

#endif//GLM_HAS_INITIALIZER_LISTS

	return Error;
}

int main()
{
	int Error = 0;

	Error += test_ctr();
	Error += test_operators();

	return Error;
}


