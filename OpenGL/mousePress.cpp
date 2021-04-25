#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>

/*
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush(); //������ �߰��߰� �ѷ���
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv); //glut �ʱ�ȭ �� �ִ� ��ũ�� �Լ�
	glutInitDisplayMode(GLUT_RED); //���÷��� ��带 RGB����
	glutCreateWindow("test"); //Windowâ�� �̸���test��
	glutDisplayFunc(display); //display�Լ� ��� ����
	glutMainLoop(); //���� ����
	return 0;

}*/
//gl ���α׷����� �⺻ Ʋ
// ���콺 �ݹ��Լ��� �̺�Ʈ��

//glutMouseFunc (void (*func)int button,int state,intx,iny));
//int button�� �Է¹��� ���콺 ��ư�� ������ �˷��ִ� ����
// GLUT_LEFT_BUTTON, GLUT_RIGHT_BUTTON, GLUT_MIDDLE_BUTTON
//int state�� ���콺�� Ŭ�� Ÿ�̹��� �˷��ִ� ����
// GLUT_DOWN ���콺�� ������ ��, GLUT_UP ���콺�� �������� ��
//glutMoctionFunc (void (*func)(int x,int y))
// ���콺�� ����ä�� �������� �� ���� ��ȯ�ϴ� �Լ�
//glutPassiveMoctionFunc (void (*func)(int x,int y))
// ���콺�� ������ ���� ä�� �������� �� ���� ��ȯ�ϴ� �Լ�
//glutEntryFunc (void (*func)(int state))
// ���콺�� ������ â �ٱ����� ������ �� �ൿ�� ����

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640

GLfloat r = 1.0, g = 1.0, b = 1.0;
GLint cur_x = -1, cur_y = -1;
int mode = 0;
int hiddenMode = 1;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	if (hiddenMode == 1)
	{
		if (mode == 0)
		{
			glutWireSphere(0.3, 15, 15);
		}
		else if (mode == 1)
		{
			glutWireTeapot(0.3);
		}
	}
	else
	{
	}
	glFlush(); //������ �߰��߰� �ѷ���
}

void myReShape(int newWidth, int newHeight)
{
	glViewport(0, 0, newWidth, newHeight); // �� �κ��� ��� ����Ʈ�� ����ϰڴ�
	GLfloat WidthFactor = (GLfloat)newWidth / (GLfloat)WINDOW_WIDTH; //���� ������ â�������� �������� ����
	GLfloat HeightFactor = (GLfloat)newHeight / (GLfloat)WINDOW_HEIGHT; //���� ������ â�������� �������� ����
	glMatrixMode(GL_PROJECTION); //�Ʒ� ������ ���ٰ� ���� ���ڴٰ� ����
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
}
void myKeyboard(unsigned char keyPress, int x, int y)
{
	switch (keyPress)
	{
	case'A':
	case'a':r = 1.0, g = 1.0, b = 1.0; glutPostRedisplay(); display(); break;
	case 27:exit(0);
	}
}
void mouseButton(int button, int states, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && states == GLUT_UP) // ���콺 ���� ��ư�� ���ȴٰ� ������ ����
	{
		mode = (mode + 1) % 2;
		glutPostRedisplay();
	}
}
void mouseDrag(int x, int y)
{
	GLint dx, dy;
	if (cur_x >= 0 || cur_y >= 0)
	{
		dx = abs(x - cur_x);
		dy = abs(y - cur_y);
		GLint sum = dx + dy;
		//r = (r - 0.1) < 0 ? 0 : r - 0.1; //��Ʈ
		g = (g - 0.01) < 0 ? 0 : g - 0.01; //��ȫ
		b = (b - 0.01) < 0 ? 0 : b - 0.01; //���
		glColor3f(r, g, b);
		glutPostRedisplay();
	}

	cur_x = x;
	cur_y = y;
}
void overWindow(int state)
{
	if (state == GLUT_LEFT)
	{
		hiddenMode = 0;
	}
	else
	{
		hiddenMode = 1;
	}
	glutPostRedisplay();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv); //glut �ʱ�ȭ �� �ִ� ��ũ�� �Լ�
	glutInitDisplayMode(GLUT_RED); //���÷��� ��带 RGB����
	glutCreateWindow("test"); //Windowâ�� �̸���test��

	//------------------<�ݹ� �Լ�>-------------------//
	glutDisplayFunc(display); //display�Լ� ��� ����
	glutKeyboardFunc(myKeyboard); //Ű���� �Է� �ݹ��� �߻����� �� ����Ǵ� �Լ�
	glutReshapeFunc(myReShape); //reShape �ݹ��� �߻����� �� myReShape ghcnf
	glutMouseFunc(mouseButton); //���콺 �ݹ� �Լ� ȣ��
	glutMotionFunc(mouseDrag); //���콺�� ���������� mouseDrag�Լ� ȣ��
	glutEntryFunc(overWindow); //���콺�� ������ â ������ ������ �� ȣ��Ǵ� �ݹ� �Լ�
	glutMainLoop(); //���� ����
	return 0;

}