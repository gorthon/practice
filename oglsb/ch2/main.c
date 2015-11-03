
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

clock_t t0;

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
	t0 = clock();

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

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(rendering_program);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	// float delta_t = (((float)clock() - (float)t0) / (float)CLOCKS_PER_SEC) * 100.0f; // in 10s of ms
 //    const GLfloat color[] = {
 //        (float)sin(delta_t) * 0.5f + 0.5f,
 //        (float)cos(delta_t) * 0.5f + 0.5f,
 //        0.0f,
 //        1.0f
 //    };
 //    glClearBufferfv(GL_COLOR, 0, color);

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
	GLuint vertex_shader,
		fragment_shader,
		program;

	const GLchar * vertex_shader_source[] = {
	    "#version 450 core\n"
	    "void main(void) {\n"
	    "	const vec4 vertices[3] = vec4[3](\n"
	    "		vec4(0.25, -0.25, 0.5, 1.0),\n"
	    "		vec4(-0.25, -0.25, 0.5, 1.0),\n"
	    "		vec4(0.25, 0.25, 0.5, 1.0)\n"
	    "	);\n"
	    "   gl_Position=vertices[gl_VertexID];\n"
	    "}\n"
	};
	const GLchar * fragment_shader_source[] = {
	    "#version 450 core\n"
	    "out vec4 color;\n"
	    "void main(void) {\n"
	    "   color = vec4(0.0,0.8,1.0,1.0);\n"
	    "}\n"
	};

    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
    glCompileShader(vertex_shader);

    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
    glCompileShader(fragment_shader);

    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return program;
}

void render(void) {
}

void shutdown(void) {
    glDeleteVertexArrays(1, &vao);
    glDeleteProgram(rendering_program);
}


