#include "dobogl.h"


void dglAdd3f(GLfloat* v1, GLfloat* v2, GLfloat* res) {
	if(res == NULL)
		res = (GLfloat *)malloc((sizeof v1[0]) * 3);
	res[0] = v1[0] + v2[0];
	res[1] = v1[1] + v2[1];
	res[2] = v1[2] + v2[2];
}
void dglAdd4f(GLfloat* v1, GLfloat* v2, GLfloat* res) {
	if(res == NULL)
		res = (GLfloat *)malloc((sizeof v1[0]) * 4);
	res[0] = v1[0] + v2[0];
	res[1] = v1[1] + v2[1];
	res[2] = v1[2] + v2[2];
	res[3] = v1[3] + v2[3];
}
void dglSubtract3f(GLfloat* v1, GLfloat* v2, GLfloat* res) {
	if(res == NULL)
		res = (GLfloat *)malloc((sizeof v1[0]) * 3);
	res[0] = v1[0] - v2[0];
	res[1] = v1[1] - v2[1];
	res[2] = v1[2] - v2[2];
}
void dglSubtract4f(GLfloat* v1, GLfloat* v2, GLfloat* res) {
	if(res == NULL)
		res = (GLfloat *)malloc((sizeof v1[0]) * 4);
	res[0] = v1[0] - v2[0];
	res[1] = v1[1] - v2[1];
	res[2] = v1[2] - v2[2];
	res[3] = v1[3] - v2[3];
}
void dglScalar3f(GLfloat a, GLfloat* v, GLfloat* res) {
	if(res == NULL)
		res = (GLfloat *)malloc((sizeof v[0]) * 3);
	res[0] = a * v[0];
	res[1] = a * v[1];
	res[2] = a * v[2];
}
void dglScalar4f(GLfloat a, GLfloat* v, GLfloat* res) {
	if(res == NULL)
		res = (GLfloat *)malloc((sizeof v[0]) * 4);
	res[0] = a * v[0];
	res[1] = a * v[1];
	res[2] = a * v[2];
	res[3] = a * v[3];
}
GLfloat dglDot3f(GLfloat* v1, GLfloat* v2) {
	return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
}
GLfloat dglDot4f(GLfloat* v1, GLfloat* v2) {
	return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2] + v1[3]*v2[3];
}
// void dglCross3f(GLfloat* v1, GLfloat* v2) {}
// void dglCross4f(GLfloat* v1, GLfloat* v2) {}

// GLfloat dglDeterminant44f(GLfloat* A) {}
GLfloat dglDeterminant33f(GLfloat* A) {
	return A[0]*(A[4]*A[8]-A[5]*A[7]) - A[3]*(A[1]*A[8]-A[2]*A[7]) + A[6]*(A[1]*A[5]-A[2]*A[4]);
}
GLfloat dglDeterminant22f(GLfloat* A) {
	return A[0]*A[3] - A[1]*A[2];
}

// GLfloat dgl3f(GLfloat* v1, GLfloat* v2) {}
// GLfloat dgl4f(GLfloat* v1, GLfloat* v2) {}

void dglNormalize3f(GLfloat* v, GLfloat* res) {
	if(res == NULL)
		res = (GLfloat *)malloc((sizeof v[0]) * 3);
	dglScalar3f(1/dglMagnitude3f(v), v, res);
}
void dglNormalize4f(GLfloat* v, GLfloat* res) {
	if(res == NULL)
		res = (GLfloat *)malloc((sizeof v[0]) * 4);
	dglScalar4f(1/dglMagnitude4f(v), v, res);
}

GLfloat dglGetRadians3f(GLfloat* v1, GLfloat* v2) {
	GLfloat *nv1, *nv2;
	GLfloat res;

	dglNormalize3f(v1, nv1);
	dglNormalize3f(v2, nv2);
	res = (GLfloat) acos(dglDot3f(nv1,nv2));
	free(nv1);
	free(nv2);

	return res;
}
GLfloat dglGetRadians4f(GLfloat* v1, GLfloat* v2) {
	GLfloat *nv1, *nv2;
	GLfloat res;

	dglNormalize4f(v1, nv1);
	dglNormalize4f(v2, nv2);
	res = (GLfloat) acos(dglDot4f(nv1,nv2));
	free(nv1);
	free(nv2);

	return res;
}
GLfloat dglGetDegrees3f(GLfloat* v1, GLfloat* v2) {
	return dglGetDegrees3f(v1, v2) * 180 / DGL_PI;
}
GLfloat dglGetDegrees4f(GLfloat* v1, GLfloat* v2) {
	return dglGetDegrees4f(v1, v2) * 180 / DGL_PI;
}



GLfloat dglMagnitude3f(GLfloat* vec) {
	return (GLfloat) sqrt(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);
}
GLfloat dglMagnitude4f(GLfloat* vec) {
	return (GLfloat) sqrt(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);
}
void dglCopy3f(GLfloat* from, GLfloat* to) {
	if(to == NULL)
		to = (GLfloat*)malloc((sizeof from[0]) * 3);
	to[0] = from[0];
	to[1] = from[1];
	to[2] = from[2];
}
void dglCopy4f(GLfloat* from, GLfloat* to) {
	if(to == NULL)
		to = (GLfloat*)malloc((sizeof from[0]) * 3);
	to[0] = from[0];
	to[1] = from[1];
	to[2] = from[2];
	to[3] = from[3];
}
void dglMultiply33f3f(GLfloat* A, GLfloat* v, GLfloat* res) {
	if(res == NULL)
		res = (GLfloat *)malloc((sizeof A[0]) * 3);
	res[0] = A[0]*v[0]+A[3]*v[1]+A[6]*v[2];
	res[1] = A[1]*v[0]+A[4]*v[1]+A[7]*v[2];
	res[2] = A[2]*v[0]+A[5]*v[1]+A[8]*v[2];
}
void dglMultiply44f4f(GLfloat* A, GLfloat* v, GLfloat* res) {
	if(res == NULL)
		res = (GLfloat*)malloc((sizeof A[0]) * 4);
	res[0] = A[0]*v[0]+A[4]*v[1]+A[8]*v[2]+A[12]*v[3];
	res[1] = A[1]*v[0]+A[5]*v[1]+A[9]*v[2]+A[13]*v[3];
	res[2] = A[2]*v[0]+A[6]*v[1]+A[10]*v[2]+A[14]*v[3];
	res[3] = A[3]*v[0]+A[7]*v[1]+A[11]*v[2]+A[15]*v[3];
}
void dglMultiply33f33f(GLfloat* A, GLfloat* B, GLfloat* res) {
	if(res == NULL)
		res = (GLfloat*)malloc((sizeof A[0]) * 9);
	res[0] = A[0]*B[0]+A[3]*B[1]+A[6]*B[2];
	res[1] = A[1]*B[0]+A[4]*B[1]+A[7]*B[2];
	res[2] = A[2]*B[0]+A[5]*B[1]+A[8]*B[2];
	res[3] = A[0]*B[3]+A[3]*B[4]+A[6]*B[5];
	res[4] = A[1]*B[3]+A[4]*B[4]+A[7]*B[5];
	res[5] = A[2]*B[3]+A[5]*B[4]+A[8]*B[5];
	res[6] = A[0]*B[6]+A[3]*B[7]+A[6]*B[8];
	res[7] = A[1]*B[6]+A[4]*B[7]+A[7]*B[8];
	res[8] = A[2]*B[6]+A[5]*B[7]+A[8]*B[8];
}
void dglMultiply44f44f(GLfloat* A, GLfloat* B, GLfloat* res) {
	if(res == NULL)
		res = (GLfloat*)malloc((sizeof A[0]) * 16);
	res[0] = A[0]*B[0]+A[4]*B[1]+A[8]*B[2]+A[12]*B[3];
	res[1] = A[1]*B[0]+A[5]*B[1]+A[9]*B[2]+A[13]*B[3];
	res[2] = A[2]*B[0]+A[6]*B[1]+A[10]*B[2]+A[14]*B[3];
	res[3] = A[3]*B[0]+A[7]*B[1]+A[11]*B[2]+A[15]*B[3];
	res[4] = A[0]*B[4]+A[4]*B[5]+A[8]*B[6]+A[12]*B[7];
	res[5] = A[1]*B[4]+A[5]*B[5]+A[9]*B[6]+A[13]*B[7];
	res[6] = A[2]*B[4]+A[6]*B[5]+A[10]*B[6]+A[14]*B[7];
	res[7] = A[3]*B[4]+A[7]*B[5]+A[11]*B[6]+A[15]*B[7];
	res[8] = A[0]*B[8]+A[4]*B[9]+A[8]*B[10]+A[12]*B[11];
	res[9] = A[1]*B[8]+A[5]*B[9]+A[9]*B[10]+A[13]*B[11];
	res[10] = A[2]*B[8]+A[6]*B[9]+A[10]*B[10]+A[14]*B[11];
	res[11] = A[3]*B[8]+A[7]*B[9]+A[11]*B[10]+A[15]*B[11];
	res[12] = A[0]*B[12]+A[4]*B[13]+A[8]*B[14]+A[12]*B[15];
	res[13] = A[1]*B[12]+A[5]*B[13]+A[9]*B[14]+A[13]*B[15];
	res[14] = A[2]*B[12]+A[6]*B[13]+A[10]*B[14]+A[14]*B[15];
	res[15] = A[3]*B[12]+A[7]*B[13]+A[11]*B[14]+A[15]*B[15];
}