#ifndef __DOBOGL_H__
#define __DOBOGL_H__ 1

#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

#define DGL_PI (GLfloat) 3.141592653589f;


void dglAdd3f(GLfloat* v1, GLfloat* v2, GLfloat* res);
// void dglAdd4f(GLfloat* v1, GLfloat* v2, GLfloat* res);
void dglSubtract3f(GLfloat* v1, GLfloat* v2, GLfloat* res);
// void dglSubtract4f(GLfloat* v1, GLfloat* v2, GLfloat* res);
void dglScalar3f(GLfloat a, GLfloat* v, GLfloat* res);
void dglScalar4f(GLfloat a, GLfloat* v, GLfloat* res);
GLfloat dglDot3f(GLfloat* v1, GLfloat* v2);
// GLfloat dglDot4f(GLfloat* v1, GLfloat* v2);
void dglCross3f(GLfloat* v1, GLfloat* v2, GLfloat* res);
GLfloat dglDeterminant33f(GLfloat* A);
GLfloat dglDeterminant22f(GLfloat* A);
void dglNormalize3f(GLfloat* v, GLfloat* res);
// void dglNormalize4f(GLfloat* v, GLfloat* res);
GLfloat dglGetRadians3f(GLfloat* v1, GLfloat* v2);
// GLfloat dglGetRadians4f(GLfloat* v1, GLfloat* v2);
GLfloat dglGetDegrees3f(GLfloat* v1, GLfloat* v2);
// GLfloat dglGetDegrees4f(GLfloat* v1, GLfloat* v2);
GLfloat dglMagnitude3f(GLfloat* vec);
// GLfloat dglMagnitude4f(GLfloat* vec);
void dglCopy3f(GLfloat* from, GLfloat* to);
void dglCopy4f(GLfloat* from, GLfloat* to);
void dglMultiply33f3f(GLfloat* A, GLfloat* v, GLfloat* res);
void dglMultiply44f4f(GLfloat* A, GLfloat* v, GLfloat* res);
void dglMultiply33f33f(GLfloat* A, GLfloat* B, GLfloat* res);
void dglMultiply44f44f(GLfloat* A, GLfloat* B, GLfloat* res);

#endif