#include "dobogl.h"

GLfloat dglMagnitude3f(GLfloat * vec) {
	return (GLfloat) sqrt(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);
}
GLfloat dglMagnitude4f(GLfloat * vec) {
	return (GLfloat) sqrt(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);
}
void dglCopy3f(GLfloat * from, GLfloat * to) {
	if(to == NULL)
		to = (GLfloat *)malloc((sizeof GLfloat) * 3);
	to[0] = from[0];
	to[1] = from[1];
	to[2] = from[2];
}
void dglCopy4f(GLfloat * from, GLfloat * to) {
	if(to == NULL)
		to = (GLfloat *)malloc((sizeof GLfloat) * 3);
	to[0] = from[0];
	to[1] = from[1];
	to[2] = from[2];
	to[3] = from[3];
}
GLfloat* dglMultiply33f3f(GLfloat * A, GLfloat * v) {
	GLfloat* ret = {
		A[0]*v[0]+A[3]*v[1]+A[6]*v[2],
		A[1]*v[0]+A[4]*v[1]+A[7]*v[2],
		A[2]*v[0]+A[5]*v[1]+A[8]*v[2]
	};
	return ret;
}
GLfloat* dglMultiply44f4f(GLfloat * A, GLfloat * v) {
	GLfloat* ret = {
		A[0]*v[0]+A[3]*v[1]+A[6]*v[2],
		A[1]*v[0]+A[4]*v[1]+A[7]*v[2],
		A[2]*v[0]+A[5]*v[1]+A[8]*v[2]
	};
	return ret;
}
GLfloat* dglMultiply33f33f(GLfloat * A, GLfloat * v) {
	GLfloat* ret = {
		A[0]*v[0]+A[3]*v[1]+A[6]*v[2],
		A[1]*v[0]+A[4]*v[1]+A[7]*v[2],
		A[2]*v[0]+A[5]*v[1]+A[8]*v[2]
	};
	return ret;
}
GLfloat* dglMultiply44f44f(GLfloat * A, GLfloat * v) {
	GLfloat* ret = {
		A[0]*v[0]+A[3]*v[1]+A[6]*v[2],
		A[1]*v[0]+A[4]*v[1]+A[7]*v[2],
		A[2]*v[0]+A[5]*v[1]+A[8]*v[2]
	};
	return ret;
}