
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

#define WINDOW_TITLE_PREFIX "doboGL"
#define DOBO_MAJOR_VERSION 4
#define DOBO_MINOR_VERSION 5
#define DOBO_STR_VERSION "450"

int window_width = 600,
	window_height = 600,
	window_handle = 0;

unsigned frame_count = 0;

GLuint
	rendering_program,
	vao;

void startup(int argc, char* argv[]);
void check_gl_error(GLenum error_code, const char* custom_msg);
void create_window(int argc, char* argv[]);
void window_resize_func(int w, int h);
void window_render_func(void);
void idle_func(void);
void timer_func(int n);
void keyboard_func(unsigned char c, int x, int y);
void create_vao(void);
GLuint create_shaders(void);
void render(void);
void shutdown(void);


int main(int argc, char* argv[]) {
	startup(argc, argv);

	glutMainLoop();

	exit(EXIT_SUCCESS);
}

void startup(int argc, char* argv[]) {
	GLenum glew_init_result;
	create_window(argc, argv);
	glewExperimental = GL_TRUE;
	glew_init_result = glewInit();

	check_gl_error(glew_init_result, "");

	fprintf(stdout, "INFO: OpenGL Version: %s\n", glGetString(GL_VERSION));

    rendering_program = create_shaders();
    create_vao();

}

void check_gl_error(GLenum error_code, const char* custom_msg) {
	if(GLEW_OK != error_code) {
		fprintf(
			stderr,
			"ERROR: %s %s\n",
			custom_msg,
			glewGetErrorString(error_code)
		);
		exit(EXIT_FAILURE);
	}
}

void create_window(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitContextVersion(DOBO_MAJOR_VERSION, DOBO_MINOR_VERSION);
	glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutSetOption(
		GLUT_ACTION_ON_WINDOW_CLOSE,
		GLUT_ACTION_GLUTMAINLOOP_RETURNS
	);
	glutInitWindowSize(window_width, window_height);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	window_handle = glutCreateWindow(WINDOW_TITLE_PREFIX);

	if(window_handle < 1) {
		fprintf(
			stderr,
			"ERROR: Could not create a rendering window.\n"
		);
		exit(EXIT_FAILURE);
	}

	glutReshapeFunc(window_resize_func);
	glutDisplayFunc(window_render_func);
	glutIdleFunc(idle_func);
	glutTimerFunc(0, timer_func, 0);
	glutCloseFunc(shutdown);
	glutKeyboardFunc(keyboard_func);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void window_resize_func(int w, int h) {
	window_width = w;
	window_height = h;
	glViewport(0, 0, window_width, window_height);
}

void window_render_func(void) {
	++frame_count;

	// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    const GLfloat bg_color[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    glClearBufferfv(GL_COLOR, 0, bg_color);

	glUseProgram(rendering_program);

	GLfloat attrib[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	GLfloat color[] = {0.0f, 0.6f, 0.8f, 1.0f};

	glVertexAttrib4fv(0, attrib);
	glVertexAttrib4fv(1, color);
	glPatchParameteri(GL_PATCH_VERTICES, 3);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_PATCHES, 0, 3);

	glutSwapBuffers();
}

void idle_func(void) {
	glutPostRedisplay();
}

void timer_func(int n) {
	frame_count = 0;
	glutTimerFunc(250, timer_func, 0);
}

void keyboard_func(unsigned char c, int x, int y) {
	switch(c) {
		case 't':
		case 'T':
			break;
		default:
			break;
	}
}

void create_vao(void) {
    glCreateVertexArrays(1, &vao);
    glBindVertexArray(vao);
}

GLuint create_shaders(void) {
	GLuint vs,
		tcs,
		tes,
		fs,
		program;

	const GLchar * vs_src[] = {
	    "#version 450 core\n"
	    "layout (location=0) in vec4 offset;\n"
	    // "layout (location=1) in vec4 color;\n"
	    // "out VS_OUT {\n"
	    // "	vec4 color;\n"
	    // "} vs_out;\n"
	    "void main(void) {\n"
	    "	const vec4 vertices[3] = vec4[3](\n"
	    "		vec4(0.25, -0.25, 0.5, 1.0),\n"
	    "		vec4(-0.25, -0.25, 0.5, 1.0),\n"
	    "		vec4(0.25, 0.25, 0.5, 1.0)\n"
	    "	);\n"
	    "   gl_Position=vertices[gl_VertexID] + offset;\n"
	    // "	vs_out.color = color;\n"
	    "}\n"
	};
	const GLchar * tcs_src[] = {
		"#version 450 core\n"
		"layout (vertices=3) out;\n"
	    // "in VS_OUT {\n"
	    // "	vec4 color;\n"
	    // "} tcs_in;\n"
	    // "out TCS_OUT {\n"
	    // "	vec4 color;\n"
	    // "} tcs_out;\n"
		"void main(void) {\n"
		"	if(gl_InvocationID == 0) {\n"
		"		gl_TessLevelInner[0] = 5.0;\n"
		"		gl_TessLevelOuter[0] = 5.0;\n"
		"		gl_TessLevelOuter[1] = 5.0;\n"
		"		gl_TessLevelOuter[2] = 5.0;\n"
		"	}\n"
		"	gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;\n"
		// "	tcs_out.color = tcs_in.color;\n"
		"}\n"
	};
	const GLchar * tes_src[] = {
		"#version 450 core\n"
		"layout (triangles, equal_spacing, cw) in;\n"
	    // "in TCS_OUT {\n"
	    // "	vec4 color;\n"
	    // "} tes_in;\n"
	    // "out TES_OUT {\n"
	    // "	vec4 color;\n"
	    // "} tes_out;\n"
		"void main(void) {\n"
		"	gl_Position = (gl_TessCoord.x * gl_in[0].gl_Position) +\n"
		"		(gl_TessCoord.y * gl_in[1].gl_Position) +\n"
		"		(gl_TessCoord.z * gl_in[2].gl_Position);\n"
		// "	tes_out = tes_in;\n"
		"}\n"
	};
	const GLchar * fs_src[] = {
	    "#version 450 core\n"
	    // "in VS_OUT {\n"
	    // "	vec4 color;\n"
	    // "} fs_in;\n"
	    "out vec4 color;\n"
	    "void main(void) {\n"
	    "	color = vec4(0.0, 0.8, 1.0, 1.0);\n"
	    // "   color = fs_in.color;\n"
	    "}\n"
	};

    vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, vs_src, NULL);
    glCompileShader(vs);

    tcs = glCreateShader(GL_TESS_CONTROL_SHADER);
    glShaderSource(tcs, 1, tcs_src, NULL);
    glCompileShader(tcs);

    tes = glCreateShader(GL_TESS_EVALUATION_SHADER);
    glShaderSource(tes, 1, tes_src, NULL);
    glCompileShader(tes);

    fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, fs_src, NULL);
    glCompileShader(fs);

    program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, tcs);
    glAttachShader(program, tes);
    glAttachShader(program, fs);
    glLinkProgram(program);

    glDeleteShader(vs);
    glDeleteShader(tcs);
    glDeleteShader(tes);
    glDeleteShader(fs);

    return program;
}

void shutdown(void) {
    glDeleteVertexArrays(1, &vao);
    glDeleteProgram(rendering_program);
}


