#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>

#define _WINDOW_WIDTH 500
#define _WINDOW_HEIGHT 500

int mode;

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT); //컬러버퍼에 초기화 색을 가함
	glColor3f(0.5, 0.5, 0.5); //색상 설정
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
	glViewport(0, 0, newWidth, newHeight); // 이 부분을 모두 뷰포트로 사용하겠다
	GLfloat WidthFactor = (GLfloat)newWidth / (GLfloat)_WINDOW_WIDTH; //300기준으로 팩터 변경
	GLfloat HeightFactor = (GLfloat)newHeight / (GLfloat)_WINDOW_HEIGHT; //300기준으로 팩터 변경
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
	glutInitWindowSize(_WINDOW_WIDTH, _WINDOW_HEIGHT); //처음 윈도우 
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Test"); //윈도우 창의 이름
	glClearColor(1.0, 1.0, 1.0, 1.0); //배경색을 지정한다

	//////////////callback 함수/////////////////
	glutDisplayFunc(myDisplay);   //Mydisplay 함수를 호출
	glutKeyboardFunc(myKeyboard);
	glutReshapeFunc(myReShape);   //reshape가 될 떄마다 호출되는 함수
	glutMainLoop(); 
	return 0;

}