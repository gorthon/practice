#ifndef __DOBOGL_H__
#define __DOBOGL_H__ 1


#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

GLfloat dglMagnitude3f(GLfloat * vec);
GLfloat dglMagnitude4f(GLfloat * vec);
void dglCopy3f(GLfloat * from, GLfloat * to);
void dglCopy4f(GLfloat * from, GLfloat * to);
GLfloat* dglMultiply33f3f(GLfloat * A, GLfloat * v);
GLfloat* dglMultiply44f4f(GLfloat * A, GLfloat * v);
GLfloat* dglMultiply33f33f(GLfloat * A, GLfloat * v);
GLfloat* dglMultiply44f44f(GLfloat * A, GLfloat * v);

#endif