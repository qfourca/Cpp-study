#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>

/*
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush(); //내용을 중간중간 뿌려라
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv); //glut 초기화 해 주는 매크로 함수
	glutInitDisplayMode(GLUT_RED); //디스플레이 모드를 RGB모드로
	glutCreateWindow("test"); //Window창의 이름을test로
	glutDisplayFunc(display); //display함수 계속 실행
	glutMainLoop(); //메인 루프
	return 0;

}*/
//gl 프로그래밍의 기본 틀
// 마우스 콜백함수의 이벤트들

//glutMouseFunc (void (*func)int button,int state,intx,iny));
//int button은 입력받은 마우스 버튼의 종류를 알려주는 변수
// GLUT_LEFT_BUTTON, GLUT_RIGHT_BUTTON, GLUT_MIDDLE_BUTTON
//int state는 마우스의 클릭 타이밍을 알려주는 변수
// GLUT_DOWN 마우스가 눌렸을 때, GLUT_UP 마우스가 떨어졌을 때
//glutMoctionFunc (void (*func)(int x,int y))
// 마우스가 눌린채로 움직였을 때 값을 반환하는 함수
//glutPassiveMoctionFunc (void (*func)(int x,int y))
// 마우스가 눌리지 않은 채로 움직였을 때 값을 반환하는 함수
//glutEntryFunc (void (*func)(int state))
// 마우스가 윈도우 창 바깥으로 나가면 할 행동을 지정

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
	glFlush(); //내용을 중간중간 뿌려라
}

void myReShape(int newWidth, int newHeight)
{
	glViewport(0, 0, newWidth, newHeight); // 이 부분을 모두 뷰포트로 사용하겠다
	GLfloat WidthFactor = (GLfloat)newWidth / (GLfloat)WINDOW_WIDTH; //시작 원도우 창기준으로 가로팩터 변경
	GLfloat HeightFactor = (GLfloat)newHeight / (GLfloat)WINDOW_HEIGHT; //시작 윈도우 창기준으로 세로팩터 변경
	glMatrixMode(GL_PROJECTION); //아래 세줄은 원근감 없이 보겠다고 지정
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
	if (button == GLUT_LEFT_BUTTON && states == GLUT_UP) // 마우스 왼쪽 버튼이 눌렸다가 떨어진 상태
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
		//r = (r - 0.1) < 0 ? 0 : r - 0.1; //민트
		g = (g - 0.01) < 0 ? 0 : g - 0.01; //분홍
		b = (b - 0.01) < 0 ? 0 : b - 0.01; //노랑
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
	glutInit(&argc, argv); //glut 초기화 해 주는 매크로 함수
	glutInitDisplayMode(GLUT_RED); //디스플레이 모드를 RGB모드로
	glutCreateWindow("test"); //Window창의 이름을test로

	//------------------<콜백 함수>-------------------//
	glutDisplayFunc(display); //display함수 계속 실행
	glutKeyboardFunc(myKeyboard); //키보드 입력 콜백이 발생했을 때 실행되는 함수
	glutReshapeFunc(myReShape); //reShape 콜백이 발생했을 때 myReShape ghcnf
	glutMouseFunc(mouseButton); //마우스 콜백 함수 호출
	glutMotionFunc(mouseDrag); //마우스가 움직였을떄 mouseDrag함수 호출
	glutEntryFunc(overWindow); //마우스가 윈도우 창 밖으로 나갔을 때 호출되는 콜백 함수
	glutMainLoop(); //메인 루프
	return 0;

}