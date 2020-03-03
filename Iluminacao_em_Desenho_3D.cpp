#include <glut.h>
#include <stdlib.h>
void Desenha(void){
glEnable(GL_DEPTH_TEST);
// Cor de fundo da Janela cinza
	glClearColor(0.5,0.5,0.5,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	//Desenhando o cubo
	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();
	
	glTranslatef (-2.0, 0.0, 0.0);
	glScalef (2.0, 1.0, 4.0);
	glutSolidCube (1.0);
	glPopMatrix();
	//Desenhando a Esfera
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glTranslatef (2.0, 0.0, 0.0);
	glutSolidSphere(2.0,30,30);
	glPopMatrix();
	glutSwapBuffers();
	}
	//Permite o redimensionamento da janela sem distorção
void RedimensionarJanela(GLsizei w, GLsizei h){
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	if (h==0) h=1; //prevenindo divisão por zero
	gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef (0.0, 0.0, -10.0);
}

void Teclado(unsigned char key, int x, int y){
	switch (key) {
	case 27: // tecla Esc (encerra o programa)
	exit(0);
	break;
	}
	}
	void inicializa(void){
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClearColor(0.5,0.5,0.5,1.0);
	}
	int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	inicializa();
	glutDisplayFunc(Desenha);
	glutReshapeFunc(RedimensionarJanela);
	glutKeyboardFunc(Teclado);
	glutMainLoop();
}
