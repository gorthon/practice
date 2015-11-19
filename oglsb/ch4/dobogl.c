#include "dobogl.h"


void dglCopy3f(GLfloat* from, GLfloat* to) {
	to[0] = from[0];
	to[1] = from[1];
	to[2] = from[2];
}
void dglCopy4f(GLfloat* from, GLfloat* to) {
	to[0] = from[0];
	to[1] = from[1];
	to[2] = from[2];
	to[3] = from[3];
}
void dglCopyQ(GLfloat *from, GLfloat *to) {
	dglCopy4f(from, to);
}
void dglAdd3f(GLfloat* v1, GLfloat* v2, GLfloat* res) {
	res[0] = v1[0] + v2[0];
	res[1] = v1[1] + v2[1];
	res[2] = v1[2] + v2[2];
}
void dglAdd4f(GLfloat* v1, GLfloat* v2, GLfloat* res) {
	res[0] = v1[0] + v2[0];
	res[1] = v1[1] + v2[1];
	res[2] = v1[2] + v2[2];
	res[3] = v1[3] + v2[3];
}
void dglAddQ(GLfloat *p, GLfloat *q, GLfloat *res) {
	dglAdd4f(p, q, res);
}
void dglSubtract3f(GLfloat* v1, GLfloat* v2, GLfloat* res) {
	res[0] = v1[0] - v2[0];
	res[1] = v1[1] - v2[1];
	res[2] = v1[2] - v2[2];
}
void dglSubtract4f(GLfloat* v1, GLfloat* v2, GLfloat* res) {
	res[0] = v1[0] - v2[0];
	res[1] = v1[1] - v2[1];
	res[2] = v1[2] - v2[2];
	res[3] = v1[3] - v2[3];
}
void dglSubtractQ(GLfloat *p, GLfloat *q, GLfloat *res) {
	dglSubtract4f(p, q, res);
}
void dglScalar3f(GLfloat a, GLfloat* v, GLfloat* res) {
	res[0] = a * v[0];
	res[1] = a * v[1];
	res[2] = a * v[2];
}
void dglScalar4f(GLfloat a, GLfloat* v, GLfloat* res) {
	res[0] = a * v[0];
	res[1] = a * v[1];
	res[2] = a * v[2];
	res[3] = a * v[3];
}
void dglScalarQ(GLfloat s, GLfloat *p, GLfloat *res) {
	dglScalar4f(s, p, res);
}
GLfloat dglDot3f(GLfloat* v1, GLfloat* v2) {
	return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
}
GLfloat dglDot4f(GLfloat* v1, GLfloat* v2) {
	return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2] + v1[3]*v2[3];
}
GLfloat dglMagnitude3f(GLfloat* v) {
	return (GLfloat) sqrt(dglDot3f(v,v));
}
GLfloat dglMagnitude4f (GLfloat* v) {
	return (GLfloat) sqrt(dglDot4f(v,v));
}
GLfloat dglNormQ(GLfloat *p) {
	return dglMagnitude4f(p);
}
void dglNormalize3f(GLfloat* v, GLfloat* res) {
	dglScalar3f(1/dglMagnitude3f(v), v, res);
}
void dglNormalize4f(GLfloat* v, GLfloat* res) {
	dglScalar4f(1/dglMagnitude4f(v), v, res);
}
void dglNormalizeQ(GLfloat *p, GLfloat *res) {
	dglNormalize4f(p, res);
}
void dglCross3f(GLfloat* v1, GLfloat* v2, GLfloat* res) {
	res[0] = v1[1]*v2[2] - v1[2]*v2[1];
	res[1] = v1[0]*v2[2] - v1[2]*v2[0];
	res[2] = v1[0]*v2[1] - v1[1]*v2[0];
}
void dglConjugateQ(GLfloat *p, GLfloat *res) {
	res[0] = p[0];
	res[1] = -p[1];
	res[2] = -p[2];
	res[3] = -p[3];
}
void dglMultiplyQ(GLfloat *p, GLfloat *q, GLfloat *res) {
	res[0] = p[0]*q[0] - p[1]*q[1] - p[2]*q[2] - p[3]*q[3]; // s
	res[1] = p[0]*q[1] + p[1]*q[0] + p[2]*q[3] - p[3]*q[2]; // i
	res[2] = p[0]*q[2] - p[1]*q[3] + p[2]*q[0] + p[3]*q[1]; // j
	res[3] = p[0]*q[3] + p[1]*q[2] - p[2]*q[1] + p[3]*q[0]; // k
}
void dglReciprocalQ(GLfloat *p, GLfloat *res) {
	GLfloat *tmp = malloc((sizeof p[0]) * 4);
	dglConjugateQ(p, tmp);
	dglScalarQ(1/dglDot4f(p,p), tmp, res);
	free(tmp);
}

GLfloat dglGetRadians3f(GLfloat* v1, GLfloat* v2) {
	return (GLfloat) acos(dglDot3f(v1,v2) / (dglMagnitude3f(v1) * dglMagnitude3f(v2)));
}
GLfloat dglGetRadians4f(GLfloat* v1, GLfloat* v2) {
	return (GLfloat) acos(dglDot4f(v1,v2) / (dglMagnitude4f(v1) * dglMagnitude4f(v2)));
}
GLfloat dglGetDegrees3f(GLfloat* v1, GLfloat* v2) {
	return dglGetDegrees3f(v1, v2) * 180 / DGL_PI;
}
GLfloat dglGetDegrees4f(GLfloat* v1, GLfloat* v2) {
	return dglGetDegrees4f(v1, v2) * 180 / DGL_PI;
}

void dglReflect3f(GLfloat *r, GLfloat *n, GLfloat *res) {
	GLfloat *tmp = malloc((sizeof r[0]) * 3);
	dglScalar3f(2 * dglDot3f(r, n), n, tmp);
	dglSubtract3f(r, tmp, res);
	free(tmp);
}

void dglRefract3f(GLfloat *r, GLfloat *n, GLfloat eta, GLfloat *res) {
	GLfloat *tmp1 = malloc((sizeof r[0]) * 3),
		*tmp2 = malloc((sizeof r[0]) * 3);
	GLfloat dot,k;
	dot = dglDot3f(r,n);
	k = 1 - eta*eta * (1 - (dot*dot));
	if(k < 0) {
		res[0] = 0;
		res[1] = 0;
		res[2] = 0;
	} else {
		dglScalar3f(eta, r, tmp1);
		dglScalar3f(eta * dot + (GLfloat)sqrt(k), n, tmp2);
		dglSubtract3f(tmp1, tmp2, res);
	}
	free(tmp1);
	free(tmp2);
}



void dglIdentity22f(GLfloat *res) {
	res[0] = 1;
	res[1] = 0;
	res[2] = 0;
	res[3] = 1;
}
void dglIdentity33f(GLfloat *res) {
	res[0] = 1;
	res[1] = 0;
	res[2] = 0;
	res[3] = 0;
	res[4] = 1;
	res[5] = 0;
	res[6] = 0;
	res[7] = 0;
	res[8] = 1;
}
void dglIdentity44f(GLfloat *res) {
	res[0] = 1;
	res[1] = 0;
	res[2] = 0;
	res[3] = 0;
	res[4] = 0;
	res[5] = 1;
	res[6] = 0;
	res[7] = 0;
	res[8] = 0;
	res[9] = 0;
	res[10] = 1;
	res[11] = 0;
	res[12] = 0;
	res[13] = 0;
	res[14] = 0;
	res[15] = 1;
}

// parameters appear as transpose of A here:
GLfloat dglDeterminant4f(
	GLfloat e00, GLfloat e10,
	GLfloat e01, GLfloat e11) {
	return e00*e11 - e01*e10;
}
GLfloat dglDeterminant22f(GLfloat* A) {
	return dglDeterminant4f(A[0], A[1], A[2], A[3]);
}
GLfloat dglDeterminant9f(
	GLfloat e00, GLfloat e10, GLfloat e20,
	GLfloat e01, GLfloat e11, GLfloat e21,
	GLfloat e02, GLfloat e12, GLfloat e22) {
	return e00*dglDeterminant4f(
			e11, e21,
			e12, e22)
		 - e01*dglDeterminant4f(
		 	e10, e20,
		 	e12, e22)
		 + e02*dglDeterminant4f(
		 	e10, e20,
		 	e11, e21);
}
GLfloat dglDeterminant33f(GLfloat* A) {
	return dglDeterminant9f(A[0], A[1], A[2], A[3], A[4], A[5], A[6], A[7], A[8]);
}
GLfloat dglDeterminant16f(
	GLfloat e00, GLfloat e10, GLfloat e20, GLfloat e30,
	GLfloat e01, GLfloat e11, GLfloat e21, GLfloat e31,
	GLfloat e02, GLfloat e12, GLfloat e22, GLfloat e32,
	GLfloat e03, GLfloat e13, GLfloat e23, GLfloat e33) {
	return e00*dglDeterminant9f(
			e11, e21, e31,
			e12, e22, e32,
			e13, e23, e33)
		 - e01*dglDeterminant9f(
		 	e10, e20, e30,
		 	e12, e22, e32,
		 	e13, e23, e33)
		 + e02*dglDeterminant9f(
		 	e10, e20, e30,
		 	e11, e21, e31,
		 	e13, e23, e33)
		 - e03*dglDeterminant9f(
		 	e10, e20, e30,
		 	e11, e21, e31,
		 	e12, e22, e32);
}
GLfloat dglDeterminant44f(GLfloat* A) {
	return dglDeterminant16f(A[0], A[1], A[2], A[3], A[4], A[5], A[6], A[7], A[8], A[9], A[10], A[11], A[12], A[13], A[14], A[15]);
}

void dglMultiply33f3f(GLfloat* A, GLfloat* v, GLfloat* res) {
	res[0] = A[0]*v[0]+A[3]*v[1]+A[6]*v[2];
	res[1] = A[1]*v[0]+A[4]*v[1]+A[7]*v[2];
	res[2] = A[2]*v[0]+A[5]*v[1]+A[8]*v[2];
}
void dglMultiply44f4f(GLfloat* A, GLfloat* v, GLfloat* res) {
	res[0] = A[0]*v[0]+A[4]*v[1]+A[8]*v[2]+A[12]*v[3];
	res[1] = A[1]*v[0]+A[5]*v[1]+A[9]*v[2]+A[13]*v[3];
	res[2] = A[2]*v[0]+A[6]*v[1]+A[10]*v[2]+A[14]*v[3];
	res[3] = A[3]*v[0]+A[7]*v[1]+A[11]*v[2]+A[15]*v[3];
}
void dglMultiply33f33f(GLfloat* A, GLfloat* B, GLfloat* res) {
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

void dglTranslate3f(GLfloat x, GLfloat y, GLfloat z, GLfloat *res) {
	dglIdentity44f(res);
	res[12] = x;
	res[13] = y;
	res[14] = z;
}

void dglRotateX(GLfloat phi, GLfloat *res) {
	GLfloat cosPhi = (GLfloat)cos(phi),
		sinPhi = (GLfloat)sin(phi);
	dglIdentity44f(res);
	res[5] = cosPhi;
	res[6] = -sinPhi;
	res[9] = sinPhi;
	res[10] = cosPhi;
}
void dglRotateY(GLfloat theta, GLfloat *res) {
	GLfloat cosTheta = (GLfloat)cos(theta),
		sinTheta = (GLfloat)sin(theta);
	dglIdentity44f(res);
	res[0] = cosTheta;
	res[2] = sinTheta;
	res[8] = -sinTheta;
	res[10] = cosTheta;
}
void dglRotateZ(GLfloat psi, GLfloat *res) {
	GLfloat cosPsi = (GLfloat)cos(psi),
		sinPsi = (GLfloat)sin(psi);
	dglIdentity44f(res);
	res[0] = cosPsi;
	res[1] = sinPsi;
	res[4] = -sinPsi;
	res[5] = cosPsi;
}
void dglRotateXYZ(GLfloat phi, GLfloat theta, GLfloat psi, GLfloat *res) {
	GLfloat cosPhi = (GLfloat)cos(phi),
		sinPhi = (GLfloat)sin(phi),
		cosTheta = (GLfloat)cos(theta),
		sinTheta = (GLfloat)sin(theta),
		cosPsi = (GLfloat)cos(psi),
		sinPsi = (GLfloat)sin(psi);
	dglIdentity44f(res);
	res[0] = cosTheta*cosPsi;
	res[1] = -cosTheta*sinPsi;
	res[2] = sinTheta;
	res[4] = cosPhi*sinPsi + sinPhi*sinTheta*cosPsi;
	res[5] = cosPhi*cosPsi - sinPhi*sinTheta*sinPsi;
	res[6] = -sinPhi*cosTheta;
	res[8] = sinPhi*sinPsi - cosPhi*sinTheta*cosPsi;
	res[9] = sinPhi*cosPsi + cosPhi*sinTheta*sinPsi;
	res[10] = cosPhi*cosTheta;
}
void dglScale(GLfloat sx, GLfloat sy, GLfloat sz, GLfloat *res) {
	dglIdentity44f(res);
	res[0] = sx;
	res[5] = sy;
	res[10] = sz;
}

void dglRotateTR(GLfloat theta, GLfloat x, GLfloat y, GLfloat z, GLfloat *res) {
	GLfloat *u = malloc((sizeof x)*3),
		uMag, nx, ny, nz,
		cosTheta = cos(theta),
		sinTheta = sin(theta),
		oneMinusCosTheta;
	oneMinusCosTheta = 1 - cosTheta;
	u[0] = x;
	u[1] = y;
	u[2] = z;
	uMag = dglMagnitude3f(u);
	nx = x / uMag;
	ny = y / uMag;
	nz = z / uMag;

	dglIdentity44f(res);
	res[0] = (1 - 2*nx*nx) * cosTheta;
	res[1] = nx*ny*oneMinusCosTheta + nz*sinTheta;
	res[2] = nx*nz*oneMinusCosTheta - ny*sinTheta;
	res[4] = nx*ny*oneMinusCosTheta - nz*sinTheta;
	res[5] = (1 - 2*ny*ny) * cosTheta;
	res[6] = ny*nz*oneMinusCosTheta + nx*sinTheta;
	res[8] = nx*nz*oneMinusCosTheta + ny*sinTheta;
	res[9] = ny*nz*oneMinusCosTheta - nx*sinTheta;
	res[10] = (1 - 2*nz*nz) * cosTheta;

	free(u);
}

void dglLookat(GLfloat *eye, GLfloat *poi, GLfloat *up, GLfloat *res) {
	GLfloat *forward = malloc((sizeof eye[0])*3),
		*side = malloc((sizeof eye[0])*3),
		*upOrthogonal = malloc((sizeof eye[0])*3),
		*tmp = malloc((sizeof eye[0])*3);
	dglSubtract3f(poi, eye, tmp);
	dglNormalize3f(tmp, forward);
	dglCross3f(forward, up, side);
	dglCross3f(side, forward, upOrthogonal);
	res[0] = side[0];
	res[1] = side[1];
	res[2] = side[2];
	res[3] = 0;
	res[4] = upOrthogonal[0];
	res[5] = upOrthogonal[1];
	res[6] = upOrthogonal[2];
	res[7] = 0;
	res[8] = forward[0];
	res[9] = forward[1];
	res[10] = forward[2];
	res[11] = 0;
	res[12] = -eye[0];
	res[13] = -eye[1];
	res[14] = -eye[2];
	res[15] = 1;
	free(forward);
	free(side);
	free(upOrthogonal);
	free(tmp);
}

void dglFrustrum(GLfloat top, GLfloat right, GLfloat bottom, GLfloat left, GLfloat near, GLfloat far, GLfloat *res) {
	
}