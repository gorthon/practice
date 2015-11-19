#ifndef __DOBOGL_H__
#define __DOBOGL_H__ 1

#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

#define DGL_PI (GLfloat) 3.141592653589f;

void dglCopy3f(GLfloat* from, GLfloat* to);
void dglCopy4f(GLfloat* from, GLfloat* to);
void dglCopyQ(GLfloat *from, GLfloat *to);
void dglAdd3f(GLfloat* v1, GLfloat* v2, GLfloat* res);
void dglAdd4f(GLfloat* v1, GLfloat* v2, GLfloat* res);
void dglAddQ(GLfloat *p, GLfloat *q, GLfloat *res);
void dglSubtract3f(GLfloat* v1, GLfloat* v2, GLfloat* res);
void dglSubtract4f(GLfloat* v1, GLfloat* v2, GLfloat* res);
void dglSubtractQ(GLfloat *p, GLfloat *q, GLfloat *res);
void dglScalar3f(GLfloat a, GLfloat* v, GLfloat* res);
void dglScalar4f(GLfloat a, GLfloat* v, GLfloat* res);
void dglScalarQ(GLfloat s, GLfloat *p, GLfloat *res);
GLfloat dglMagnitude3f(GLfloat* vec);
GLfloat dglMagnitude4f (GLfloat* vec);
GLfloat dglNormQ(GLfloat *p);
void dglNormalize3f(GLfloat* v, GLfloat* res);
void dglNormalize4f(GLfloat* v, GLfloat* res);
void dglNormalizeQ(GLfloat *p, GLfloat *res);
GLfloat dglDot3f(GLfloat* v1, GLfloat* v2);
GLfloat dglDot4f(GLfloat* v1, GLfloat* v2);
void dglCross3f(GLfloat* v1, GLfloat* v2, GLfloat* res);
void dglConjugateQ(GLfloat *p, GLfloat *res);
void dglMultiplyQ(GLfloat *p, GLfloat *q, GLfloat *res);

GLfloat dglGetRadians3f(GLfloat* v1, GLfloat* v2);
GLfloat dglGetRadians4f(GLfloat* v1, GLfloat* v2);
GLfloat dglGetDegrees3f(GLfloat* v1, GLfloat* v2);
GLfloat dglGetDegrees4f(GLfloat* v1, GLfloat* v2);

void dglReflect3f(GLfloat *r, GLfloat *n, GLfloat *res);
void dglRefract3f(GLfloat *r, GLfloat *n, GLfloat eta, GLfloat *res);

void dglIdentity22f(GLfloat *res);
void dglIdentity33f(GLfloat *res);
void dglIdentity44f(GLfloat *res);

// parameters appear as transpose of A here:
GLfloat dglDeterminant4f(
	GLfloat e00, GLfloat e10,
	GLfloat e01, GLfloat e11);
GLfloat dglDeterminant22f(GLfloat* A);
GLfloat dglDeterminant9f(
	GLfloat e00, GLfloat e10, GLfloat e20,
	GLfloat e01, GLfloat e11, GLfloat e21,
	GLfloat e02, GLfloat e12, GLfloat e22);
GLfloat dglDeterminant33f(GLfloat* A);
GLfloat dglDeterminant16f(
	GLfloat e00, GLfloat e10, GLfloat e20, GLfloat e30,
	GLfloat e01, GLfloat e11, GLfloat e21, GLfloat e31,
	GLfloat e02, GLfloat e12, GLfloat e22, GLfloat e32,
	GLfloat e03, GLfloat e13, GLfloat e23, GLfloat e33);
GLfloat dglDeterminant44f(GLfloat* A);
void dglMultiply33f3f(GLfloat* A, GLfloat* v, GLfloat* res);
void dglMultiply44f4f(GLfloat* A, GLfloat* v, GLfloat* res);
void dglMultiply33f33f(GLfloat* A, GLfloat* B, GLfloat* res);
void dglMultiply44f44f(GLfloat* A, GLfloat* B, GLfloat* res);
void dglTranslate3f(GLfloat x, GLfloat y, GLfloat z, GLfloat *res);
void dglRotateX(GLfloat phi, GLfloat *res);
void dglRotateY(GLfloat theta, GLfloat *res);
void dglRotateZ(GLfloat psi, GLfloat *res);
void dglRotateXYZ(GLfloat phi, GLfloat theta, GLfloat psi, GLfloat *res);
void dglScale(GLfloat sx, GLfloat sy, GLfloat sz, GLfloat *res);
void dglRotateTR(GLfloat theta, GLfloat x, GLfloat y, GLfloat z, GLfloat *res);
void dglLookat(GLfloat *eye, GLfloat *poi, GLfloat *up, GLfloat *res);

#endif