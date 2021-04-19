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

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutWireSphere(0.3, 15, 15);
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
void mouseButton(int button, int states, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && states == GLUT_UP) // ���콺 ���� ��ư�� ���ȴٰ� ������ ����
	{
		glColor3f(1, 0, 0); //���� 1, 0, 0���� ����
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv); //glut �ʱ�ȭ �� �ִ� ��ũ�� �Լ�
	glutInitDisplayMode(GLUT_RED); //���÷��� ��带 RGB����
	glutCreateWindow("test"); //Windowâ�� �̸���test��
	glutDisplayFunc(display); //display�Լ� ��� ����
	glutReshapeFunc(myReShape);
	glutMouseFunc(mouseButton); //���콺 �ݹ� �Լ� ȣ��
	glutMainLoop(); //���� ����
	return 0;

}