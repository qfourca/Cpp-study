#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>

#define _WINDOW_WIDTH 500
#define _WINDOW_HEIGHT 500

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT); //컬러버퍼에 초기화 색을 가함
	glColor3f(0.0, 0.5, 1.0); //색상 설정
	glBegin(GL_POLYGON); //사각형
		glVertex3f(-0.5, -0.5, 0.0); //좌하단 좌표
		glVertex3f(0.5, -0.5, 0.0); //우하단 좌표
		glVertex3f(0.5, 0.5, 0.0); //좌상단 좌표
		glVertex3f(-0.5, 0.5, 0.0); //우상단 좌표
	glEnd();
	glFlush();
}
void myReShape(int newWidth, int newHeight)
{
	glViewport(0, 0, newWidth, newHeight); // 이 부분을 모두 뷰포트로 사용하겠다
	GLfloat WidthFactor = (GLfloat)newWidth / (GLfloat)_WINDOW_WIDTH; //시작 원도우 창기준으로 가로팩터 변경
	GLfloat HeightFactor = (GLfloat)newHeight / (GLfloat)_WINDOW_HEIGHT; //시작 윈도우 창기준으로 세로팩터 변경
	glMatrixMode(GL_PROJECTION); //아래 세줄은 원근감 없이 보겠다고 지정
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor,-1.0,1.0);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(_WINDOW_WIDTH, _WINDOW_HEIGHT); //처음 윈도우 
	glutInitWindowPosition(0, 0);
	glClearColor(1.0, 1.0, 1.0, 1.0); //배경색을 지정한다
	glutCreateWindow("Test"); //윈도우 창의 이름
	glutDisplayFunc(myDisplay);  //Mydisplay 함수를 호출
	glutReshapeFunc(myReShape);  //reshape가 될 떄마다 호출되는 함수
	glutMainLoop(); 
	return 0;

}