#include <iostream>
#include <GL/freeglut.h>

#define WINDOW_WIDTH 10
#define WINDOW_HEIGHT 10

#define CANVAS_WIDTH WINDOW_WIDTH
#define CANVAS_HEIGHT WINDOW_HEIGHT

void OnRender() {

}

void KeyboardDown(unsigned char key, int xMouse, int yMouse) {
	std::cout << key;
	glutPostRedisplay();
}

void KeyboardSpecialDown(int key, int xMouse, int yMouse) {
	std::cout << key;
	glutPostRedisplay();
}

void KeyboardUp(unsigned char key, int xMouse, int yMouse) {
	system("cls");
}

void KeyboardSpecialUp(int key, int xMouse, int yMouse) {
	system("cls");
}

void myInit() {
	glClearColor(0, 0, 0, 1);
	gluOrtho2D(0, CANVAS_WIDTH, 0, CANVAS_HEIGHT);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Event Handler Test");
	glutDisplayFunc(OnRender);
	glutKeyboardFunc(KeyboardDown);
	glutSpecialFunc(KeyboardSpecialDown);
	glutKeyboardUpFunc(KeyboardUp);
	glutSpecialUpFunc(KeyboardSpecialUp);
	glutMainLoop();
	return 0;
}