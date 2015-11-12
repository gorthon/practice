#include "dobogl.h"

GLfloat dglMagnitude3f(GLfloat * vec) {
	return (GLfloat) sqrt(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);
}
GLfloat dglMagnitude4f(GLfloat * vec) {
	return (GLfloat) sqrt(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);
}
void dglCopy3f(GLfloat * from, GLfloat * to) {
	if(to == NULL)
		to = (GLfloat *)malloc((sizeof from[0]) * 3);
	to[0] = from[0];
	to[1] = from[1];
	to[2] = from[2];
}
void dglCopy4f(GLfloat * from, GLfloat * to) {
	if(to == NULL)
		to = (GLfloat *)malloc((sizeof from[0]) * 3);
	to[0] = from[0];
	to[1] = from[1];
	to[2] = from[2];
	to[3] = from[3];
}
GLfloat* dglMultiply33f3f(GLfloat * A, GLfloat * v) {
	GLfloat* ret = (GLfloat *)malloc((sizeof A[0]) * 3);
	ret[0] = A[0]*v[0]+A[3]*v[1]+A[6]*v[2];
	ret[1] = A[1]*v[0]+A[4]*v[1]+A[7]*v[2];
	ret[2] = A[2]*v[0]+A[5]*v[1]+A[8]*v[2];
	return ret;
}
GLfloat* dglMultiply44f4f(GLfloat * A, GLfloat * v) {
	GLfloat* ret = (GLfloat *)malloc((sizeof A[0]) * 4);
	ret[0] = A[0]*v[0]+A[4]*v[1]+A[8]*v[2]+A[12]*v[3];
	ret[1] = A[1]*v[0]+A[5]*v[1]+A[9]*v[2]+A[13]*v[3];
	ret[2] = A[2]*v[0]+A[6]*v[1]+A[10]*v[2]+A[14]*v[3];
	ret[3] = A[3]*v[0]+A[7]*v[1]+A[11]*v[2]+A[15]*v[3];
	return ret;
}
GLfloat* dglMultiply33f33f(GLfloat * A, GLfloat * B) {
	GLfloat* ret = (GLfloat *)malloc((sizeof A[0]) * 9);
	ret[0] = A[0]*B[0]+A[3]*B[1]+A[6]*B[2];
	ret[1] = A[1]*B[0]+A[4]*B[1]+A[7]*B[2];
	ret[2] = A[2]*B[0]+A[5]*B[1]+A[8]*B[2];
	ret[3] = A[0]*B[3]+A[3]*B[4]+A[6]*B[5];
	ret[4] = A[1]*B[3]+A[4]*B[4]+A[7]*B[5];
	ret[5] = A[2]*B[3]+A[5]*B[4]+A[8]*B[5];
	ret[6] = A[0]*B[6]+A[3]*B[7]+A[6]*B[8];
	ret[7] = A[1]*B[6]+A[4]*B[7]+A[7]*B[8];
	ret[8] = A[2]*B[6]+A[5]*B[7]+A[8]*B[8];
	return ret;
}
GLfloat* dglMultiply44f44f(GLfloat * A, GLfloat * B) {
	GLfloat* ret = (GLfloat *)malloc((sizeof A[0]) * 16);
	ret[0] = A[0]*B[0]+A[4]*B[1]+A[8]*B[2]+A[12]*B[3];
	ret[1] = A[1]*B[0]+A[5]*B[1]+A[9]*B[2]+A[13]*B[3];
	ret[2] = A[2]*B[0]+A[6]*B[1]+A[10]*B[2]+A[14]*B[3];
	ret[3] = A[3]*B[0]+A[7]*B[1]+A[11]*B[2]+A[15]*B[3];
	ret[4] = A[0]*B[4]+A[4]*B[5]+A[8]*B[6]+A[12]*B[7];
	ret[5] = A[1]*B[4]+A[5]*B[5]+A[9]*B[6]+A[13]*B[7];
	ret[6] = A[2]*B[4]+A[6]*B[5]+A[10]*B[6]+A[14]*B[7];
	ret[7] = A[3]*B[4]+A[7]*B[5]+A[11]*B[6]+A[15]*B[7];
	ret[8] = A[0]*B[8]+A[4]*B[9]+A[8]*B[10]+A[12]*B[11];
	ret[9] = A[1]*B[8]+A[5]*B[9]+A[9]*B[10]+A[13]*B[11];
	ret[10] = A[2]*B[8]+A[6]*B[9]+A[10]*B[10]+A[14]*B[11];
	ret[11] = A[3]*B[8]+A[7]*B[9]+A[11]*B[10]+A[15]*B[11];
	ret[12] = A[0]*B[12]+A[4]*B[13]+A[8]*B[14]+A[12]*B[15];
	ret[13] = A[1]*B[12]+A[5]*B[13]+A[9]*B[14]+A[13]*B[15];
	ret[14] = A[2]*B[12]+A[6]*B[13]+A[10]*B[14]+A[14]*B[15];
	ret[15] = A[3]*B[12]+A[7]*B[13]+A[11]*B[14]+A[15]*B[15];
	return ret;
}