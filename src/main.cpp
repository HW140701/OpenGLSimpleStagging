#define GLUT_DISABLE_ATEXIT_HACK

#include "glew.h"
#include "freeglut.h"
#include <iostream>

static float roangles;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_DEPTH_TEST);

}

void display(void)
{
	if (glewInit() != GLEW_OK)
	{
		std::cout << "glew Î´³õÊ¼»¯" << std::endl;
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	glRotatef(roangles, 0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 1.0);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 1.0, 0.0);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 1.0);
	glVertex3f(1.0, 0.0, 0.0);

	glEnd();
	glPopMatrix();
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 30.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -3.6);
	glRotatef(45, 1.0, 0.0, 0.0);
}
void idle()
{
	roangles += 0.01f;
	glutPostRedisplay();
}
/* ARGSUSED1 */
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	glutIdleFunc(idle);
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}