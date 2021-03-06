///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2014 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2011-01-15
// Updated : 2012-05-02
// Licence : This source is under MIT licence
// File    : test/core/func_matrix.cpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <glm/matrix.hpp>

using namespace glm;

int test_matrixCompMult()
{
	int Error(0);

	{
		mat2 m(0, 1, 2, 3);
		mat2 n = matrixCompMult(m, m);
		Error += n == mat2(0, 1, 4, 9) ? 0 : 1;
	}

	{
		mat2x3 m(0, 1, 2, 3, 4, 5);
		mat2x3 n = matrixCompMult(m, m);
		Error += n == mat2x3(0, 1, 4, 9, 16, 25) ? 0 : 1;
	}

	{
		mat2x4 m(0, 1, 2, 3, 4, 5, 6, 7);
		mat2x4 n = matrixCompMult(m, m);
		Error += n == mat2x4(0, 1, 4, 9, 16, 25, 36, 49) ? 0 : 1;
	}

	{
		mat3 m(0, 1, 2, 3, 4, 5, 6, 7, 8);
		mat3 n = matrixCompMult(m, m);
		Error += n == mat3(0, 1, 4, 9, 16, 25, 36, 49, 64) ? 0 : 1;
	}

	{
		mat3x2 m(0, 1, 2, 3, 4, 5);
		mat3x2 n = matrixCompMult(m, m);
		Error += n == mat3x2(0, 1, 4, 9, 16, 25) ? 0 : 1;
	}

	{
		mat3x4 m(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
		mat3x4 n = matrixCompMult(m, m);
		Error += n == mat3x4(0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121) ? 0 : 1;
	}

	{
		mat4 m(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
		mat4 n = matrixCompMult(m, m);
		Error += n == mat4(0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225) ? 0 : 1;
	}

	{
		mat4x2 m(0, 1, 2, 3, 4, 5, 6, 7);
		mat4x2 n = matrixCompMult(m, m);
		Error += n == mat4x2(0, 1, 4, 9, 16, 25, 36, 49) ? 0 : 1;
	}

	{
		mat4x3 m(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
		mat4x3 n = matrixCompMult(m, m);
		Error += n == mat4x3(0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121) ? 0 : 1;
	}

	return Error;
}

int test_outerProduct()
{


	return 0;
}

int test_transpose()
{
	int Error(0);

	{
		mat2 m(0, 1, 2, 3);
		mat2 t = transpose(m);
		Error += t == mat2(0, 2, 1, 3) ? 0 : 1;
	}

	{
		mat2x3 m(0, 1, 2, 3, 4, 5);
		mat3x2 t = transpose(m);
		Error += t == mat3x2(0, 3, 1, 4, 2, 5) ? 0 : 1;
	}

	{
		mat2x4 m(0, 1, 2, 3, 4, 5, 6, 7);
		mat4x2 t = transpose(m);
		Error += t == mat4x2(0, 4, 1, 5, 2, 6, 3, 7) ? 0 : 1;
	}

	{
		mat3 m(0, 1, 2, 3, 4, 5, 6, 7, 8);
		mat3 t = transpose(m);
		Error += t == mat3(0, 3, 6, 1, 4, 7, 2, 5, 8) ? 0 : 1;
	}

	{
		mat3x2 m(0, 1, 2, 3, 4, 5);
		mat2x3 t = transpose(m);
		Error += t == mat2x3(0, 2, 4, 1, 3, 5) ? 0 : 1;
	}

	{
		mat3x4 m(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
		mat4x3 t = transpose(m);
		Error += t == mat4x3(0, 4, 8, 1, 5, 9, 2, 6, 10, 3, 7, 11) ? 0 : 1;
	}

	{
		mat4 m(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
		mat4 t = transpose(m);
		Error += t == mat4(0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15) ? 0 : 1;
	}

	{
		mat4x2 m(0, 1, 2, 3, 4, 5, 6, 7);
		mat2x4 t = transpose(m);
		Error += t == mat2x4(0, 2, 4, 6, 1, 3, 5, 7) ? 0 : 1;
	}

	{
		mat4x3 m(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
		mat3x4 t = transpose(m);
		Error += t == mat3x4(0, 3, 6, 9, 1, 4, 7, 10, 2, 5, 8, 11) ? 0 : 1;
	}

	return Error;
}

int test_determinant()
{


	return 0;
}

int test_inverse()
{
	int Failed(0);

	glm::mat4x4 A4x4(
		glm::vec4(1, 0, 1, 0), 
		glm::vec4(0, 1, 0, 0), 
		glm::vec4(0, 0, 1, 0), 
		glm::vec4(0, 0, 0, 1));
	glm::mat4x4 B4x4 = inverse(A4x4);
	glm::mat4x4 I4x4 = A4x4 * B4x4;
	Failed += I4x4 == glm::mat4x4(1) ? 0 : 1;

	glm::mat3x3 A3x3(
		glm::vec3(1, 0, 1), 
		glm::vec3(0, 1, 0), 
		glm::vec3(0, 0, 1));
	glm::mat3x3 B3x3 = glm::inverse(A3x3);
	glm::mat3x3 I3x3 = A3x3 * B3x3;
	Failed += I3x3 == glm::mat3x3(1) ? 0 : 1;

	glm::mat2x2 A2x2(
		glm::vec2(1, 1), 
		glm::vec2(0, 1));
	glm::mat2x2 B2x2 = glm::inverse(A2x2);
	glm::mat2x2 I2x2 = A2x2 * B2x2;
	Failed += I2x2 == glm::mat2x2(1) ? 0 : 1;

	return Failed;
}


int main()
{
	int Failed = 0;
	Failed += test_matrixCompMult();
	Failed += test_outerProduct();
	Failed += test_transpose();
	Failed += test_determinant();
	Failed += test_inverse();
	return Failed;
}

