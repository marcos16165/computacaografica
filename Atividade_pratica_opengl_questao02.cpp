#include <glut.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

// Constantes
#define QUADRADO  1
#define TRIANGULO 2
#define LOSANGO   3
#define CIRCULO   4

// Variáveis Globais
char texto[30];
GLfloat win, r, g, b;
GLint view_w, view_h, primitiva;
int Cx; 
int Cy;

//Funções definidas pelo usuário 
	void DesenhaCirculo2(void);
	void DesenhaTriangulo(void);
	void DesenhaLosango(void);
	void DesenhaCirculo(void);
	void DesenhaTexto(char *string);
	void GerenciaTecladdo(unsigned char key, int x, int y);

//---------------------------------------------------------------	
// Função que desenha um quadrado
void DesenhaQuadrado(void)
{
     glBegin(GL_QUADS);
               glVertex2f(-25.0f, -25.0f);
               glVertex2f(-25.0f, 25.0f);
               glVertex2f(25.0f, 25.0f);
               glVertex2f(25.0f, -25.0f);               
     glEnd();
}

//--------------------------------------------------------------
// Função que desenha um triângulo
void DesenhaTriangulo(void)
{
     glBegin(GL_TRIANGLES);
               glVertex2f(-25.0f, -25.0f);
               glVertex2f(0.0f, 25.0f);
               glVertex2f(25.0f, -25.0f);              
     glEnd();
}

//---------------------------------------------------------------
// Função que desenha um losango
void DesenhaLosango(void)
{
     glBegin(GL_POLYGON);
               glVertex2f(-25.0f, 0.0f);
               glVertex2f(0.0f, 25.0f);
               glVertex2f(25.0f, 0.0f);
               glVertex2f(0.0f, -25.0f);               
     glEnd();
}

//---------------------------------------------------------------
//Função desenha círculo
 void DesenhaCirculo(void) 
 { float angulo;
  float raio=50; 
  int Nlinhas=100; 
 while(raio>0) { 
 glBegin ( GL_LINE_LOOP );
   for(int i = 0; i < Nlinhas ; i++) 
    { angulo = i*2*M_PI/Nlinhas; 
      glVertex2f (Cx + (cos(angulo)*raio) ,Cy+ (sin(angulo) * raio));
	}
 glEnd();
 raio-=0.5;
 }
 }
 
 //----------------------------------------------------------------
 //função desenha texto
 void DesenhaTexto(char *string) 
{  
  	glPushMatrix();
        // Posição na tela onde o texto será colocado          
        glRasterPos2f(-win,win-(win*0.08)); 
        // Exibe caracter a caracter
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*string++); 
	glPopMatrix();
}
//----------------------------------------------------------------
// Função callback chamada para fazer o desenho
void Desenha(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity(); 
     glClear(GL_COLOR_BUFFER_BIT);
     
     // Desenha uma primitiva     
     switch (primitiva) {
            case QUADRADO:  DesenhaQuadrado();
                            break;
            case TRIANGULO: DesenhaTriangulo();                          
                            break;
            case LOSANGO:   DesenhaLosango();                       
                            break;
            case CIRCULO:   DesenhaCirculo();
							break;

     }

     //DesenhaTexto(texto);
     glutSwapBuffers();
}

//---------------------------------------------------------------
// Inicializa parâmetros de rendering
void Inicializa (void)
{   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    win=150.0f;
    primitiva = QUADRADO;
    strcpy(texto, "(0,0)");
    Cx = 10; 
    Cy = 10;
}

//----------------------------------------------------------------
// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{ 
    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);
    view_w = w;
    view_h = h;                   

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-win, win, -win, win);
}

//---------------------------------------------------------------
// Função callback chamada sempre que o mouse é movimentado
// sobre a janela GLUT com um botão pressionado
void MoveMouseBotaoPressionado(int x, int y)
{
     sprintf(texto, "Botao pressionado (%d,%d)", x, y);
     glutPostRedisplay();
}

//---------------------------------------------------------------
// Função callback chamada sempre que o mouse é movimentado
// sobre a janela GLUT 
void MoveMouse(int x, int y)
{
     sprintf(texto, "(%d,%d)", x, y);
     glutPostRedisplay();
}

//-----------------------------------------------------------------
// Função callback chamada para gerenciar eventos de teclado
void GerenciaTeclado(unsigned char key, int x, int y)
{
    switch (key) {
            case 'R': 
            case 'r':// muda a cor corrente para vermelho
                     glColor3f(1.0f, 0.0f, 0.0f);
                     break;
            case 'G':
            case 'g':// muda a cor corrente para verde
                     glColor3f(0.0f, 1.0f, 0.0f);
                     break;
            case 'B':
            case 'b':// muda a cor corrente para azul
                     glColor3f(0.0f, 0.0f, 1.0f);
                     break;
    }
    glutPostRedisplay();
}

//-----------------------------------------------------------------
// Gerenciamento do menu com as opções de primitivas           
void MenuPrimitiva(int op)
{
   switch(op) {
            case 0:
                     primitiva = QUADRADO;
                     break;
            case 1:
                     primitiva = TRIANGULO;
                     break;
            case 2:
                     primitiva = LOSANGO;
                     break;
            case 3:
                     primitiva = CIRCULO;
                     break;
                     
    }
    glutPostRedisplay();
}   

//---------------------------------------------     
// Gerenciamento do menu principal           
void MenuPrincipal(int op)
{
     switch(op) {
     case 0:
       exit(0);
     break;}
}

//---------------------------------------------            
// Criacao do Menu
void CriaMenu() 
{
    int menu, submenu2;

    submenu2 = glutCreateMenu(MenuPrimitiva);
    glutAddMenuEntry("Quadrado",0);
    glutAddMenuEntry("Triângulo",1);
    glutAddMenuEntry("Losango",2);
    glutAddMenuEntry("Circulo",3);
    
    menu = glutCreateMenu(MenuPrincipal);
    glutAddSubMenu("Primitivas",submenu2);
    glutAddMenuEntry("Sair",0);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

//------------------------------------------------------         
// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{        
    if (button == GLUT_RIGHT_BUTTON)
         if (state == GLUT_DOWN) 
            CriaMenu();
         
    glutPostRedisplay();
}

//---------------------------------------------------                 
// Programa Principal 
int main(void)
{
	//glutInit(int *pargc , char **argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);     
    glutInitWindowSize(350,350);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Atividade OpenGL");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutMotionFunc(MoveMouseBotaoPressionado); 
    glutPassiveMotionFunc(MoveMouse);
    glutKeyboardFunc(GerenciaTeclado); 
    glutMouseFunc(GerenciaMouse); 
    Inicializa();
    glutMainLoop();
}
