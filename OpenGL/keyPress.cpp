#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>

#define _WINDOW_WIDTH 500
#define _WINDOW_HEIGHT 500

int mode;

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT); //�÷����ۿ� �ʱ�ȭ ���� ����
	glColor3f(0.5, 0.5, 0.5); //���� ����
    if (mode == 0)
	{
		glutWireCube(0.5);
	}
	else
	{
		glutWireSphere(0.5,20,20);
	}
	glFlush();
}
void myReShape(int newWidth, int newHeight)
{
	glViewport(0, 0, newWidth, newHeight); // �� �κ��� ��� ����Ʈ�� ����ϰڴ�
	GLfloat WidthFactor = (GLfloat)newWidth / (GLfloat)_WINDOW_WIDTH; //300�������� ���� ����
	GLfloat HeightFactor = (GLfloat)newHeight / (GLfloat)_WINDOW_HEIGHT; //300�������� ���� ����
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor,-1.0,1.0);
}
void myKeyboard(unsigned char keyPress, int x, int y)
{
	switch (keyPress)
	{
	case'a': mode += 1; glutDisplayFunc(myDisplay); break;
	case'b': mode -= 1; glutDisplayFunc(myDisplay); break;
	case'Q': exit(0);
	case'q': exit(0);
	case 27:exit(0);
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(_WINDOW_WIDTH, _WINDOW_HEIGHT); //ó�� ������ 
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Test"); //������ â�� �̸�
	glClearColor(1.0, 1.0, 1.0, 1.0); //������ �����Ѵ�

	//////////////callback �Լ�/////////////////
	glutDisplayFunc(myDisplay);   //Mydisplay �Լ��� ȣ��
	glutKeyboardFunc(myKeyboard);
	glutReshapeFunc(myReShape);   //reshape�� �� ������ ȣ��Ǵ� �Լ�
	glutMainLoop(); 
	return 0;

}