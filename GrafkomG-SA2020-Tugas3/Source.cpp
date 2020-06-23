#include <iostream>
#include <GL/freeglut.h>

#define WINDOW_WIDTH 10
#define WINDOW_HEIGHT 10

#define CANVAS_WIDTH WINDOW_WIDTH
#define CANVAS_HEIGHT WINDOW_HEIGHT

unsigned char keyVal;

unsigned char arr[100];
int index = 0;
int flag = 0;

void OnRender() {

}

void myMouse(int button, int state, int x, int y) {
	if (state == GLUT_DOWN || state == GLUT_UP) {
		system("cls");
		std::cout << "Coordinat X : " << x << " | " << "Coordinat Y : " << y << std::endl;
	}
}

void myMouseMotion(int x, int y) {
	system("cls");
	std::cout << "Coordinat X : " << x << " | " << "Coordinat Y : " << y << std::endl;
}

void KeyboardDown(unsigned char key, int xMouse, int yMouse) {
	arr[index] = key;
	if (arr[index] != NULL) {
		std::cout << arr[index];
	}
	index++;
	glutPostRedisplay();
}

void KeyboardSpecialDown(int specKey, int xMouse, int yMouse) {
	std::cout << specKey;
	glutPostRedisplay();
}

void KeyboardUp(unsigned char key, int xMouse, int yMouse) {
	system("cls");
	arr[index - 1] = NULL;
}

void KeyboardSpecialUp(int specKey, int xMouse, int yMouse) {
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
	glutMouseFunc(myMouse);
	glutMotionFunc(myMouseMotion);
	glutKeyboardFunc(KeyboardDown);
	glutSpecialFunc(KeyboardSpecialDown);
	glutKeyboardUpFunc(KeyboardUp);
	glutSpecialUpFunc(KeyboardSpecialUp);
	glutMainLoop();
	return 0;
}