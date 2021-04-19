#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>

#define _WINDOW_WIDTH 500
#define _WINDOW_HEIGHT 500

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT); //�÷����ۿ� �ʱ�ȭ ���� ����
	glColor3f(0.0, 0.5, 1.0); //���� ����
	glBegin(GL_POLYGON); //�簢��
		glVertex3f(-0.5, -0.5, 0.0); //���ϴ� ��ǥ
		glVertex3f(0.5, -0.5, 0.0); //���ϴ� ��ǥ
		glVertex3f(0.5, 0.5, 0.0); //�»�� ��ǥ
		glVertex3f(-0.5, 0.5, 0.0); //���� ��ǥ
	glEnd();
	glFlush();
}
void myReShape(int newWidth, int newHeight)
{
	glViewport(0, 0, newWidth, newHeight); // �� �κ��� ��� ����Ʈ�� ����ϰڴ�
	GLfloat WidthFactor = (GLfloat)newWidth / (GLfloat)_WINDOW_WIDTH; //���� ������ â�������� �������� ����
	GLfloat HeightFactor = (GLfloat)newHeight / (GLfloat)_WINDOW_HEIGHT; //���� ������ â�������� �������� ����
	glMatrixMode(GL_PROJECTION); //�Ʒ� ������ ���ٰ� ���� ���ڴٰ� ����
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor,-1.0,1.0);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(_WINDOW_WIDTH, _WINDOW_HEIGHT); //ó�� ������ 
	glutInitWindowPosition(0, 0);
	glClearColor(1.0, 1.0, 1.0, 1.0); //������ �����Ѵ�
	glutCreateWindow("Test"); //������ â�� �̸�
	glutDisplayFunc(myDisplay);  //Mydisplay �Լ��� ȣ��
	glutReshapeFunc(myReShape);  //reshape�� �� ������ ȣ��Ǵ� �Լ�
	glutMainLoop(); 
	return 0;

}