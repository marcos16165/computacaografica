  /*
    * Projeto: Implementação em OpenGL
    * Autor: Joyce Claine e Marcos Monteiro 
	* Dados: 
	* Versao: 1.0
	* Data da ultima modificao:06/03/2020
    * Descrição: Segunda atividade de computação gráfica
*/

#include <glut.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

// Constantes
#define ESPESSURA  1
#define COLORIDO 2

//variaveis globais 
int x, y, trelica, primitiva;

//----------------------------------------------------------------
//função desenha texto
 void DesenhaTexto(void *font, char *string) 
{
	// Exibe caractere a caractere
	while(*string)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,*string++); 
}

void RetanguloJanela(){
	//RETÂNGULO NA JANELA
	glBegin(GL_LINE_STRIP);
		//Ponto lado superior esquerdo
		glVertex2f(-4.5,4.5);
		
		//Ponto lado superior direito
		glVertex2f(4.5,4.5);	
		
		//Ponto lado inferior direito
		glVertex2f(4.5,-4.5);	
		
		//Ponto lado inferior direito
		glVertex2f(-4.5,-4.5);
		
		//Ponto lado superior esquerdo(Retorna ao pono inicial formando o retângulo)
		glVertex2f(-4.5,4.5);
	glEnd();
	
		//Linha do centro 
	glBegin(GL_LINE_STRIP);
		//Linha centro
		glVertex2f(0,4.5);
		glVertex2f(0,-4.5);
	glEnd();
}

void DesenhaTrelica(float grossuraLinha ){	
//Treliça retângulo
	glLineWidth(grossuraLinha);
	glBegin(GL_LINE_STRIP);
		//Ponto superior lado esquerdo
		glVertex2f(-3,3.5);
		
		//Ponto inferior lado esquerdo
		glVertex2f(-3,-3.5);	
		
		//Ponto inferior lado Direito
		glVertex2f(-2,-3.5);
		
		//Ponto superior lado direito
		glVertex2f(-2,3.5);	
	
		//Ponto lado inferior direito
		glVertex2f(-3,3.5);	
	glEnd();

//Treliça pontos internos 
	glBegin(GL_LINE_STRIP);
		//Ponto superior lado esquerdo
		glVertex2f(-3,3.5);
		
		//Ponto superior lado direito
		glVertex2f(-2,1.75);	
		
		//Ponto centro lado esquedo
		glVertex2f(-3,0);
		
		//Ponto lado inferior lado direito
		glVertex2f(-2,-1.75);	
	
		//Ponto lado inferior esquerdo
		glVertex2f(-3,-3.5);	
	glEnd();
}

//Desenhar triangulo usando a função GL_LINE_STRIP
void DesenhaTriangulo(){
	glColor3f(0,0,0); // Preto
    	glBegin(GL_LINE_STRIP); 
        glVertex2f(1.5,1.74); //Ponto inferior esquerdo
        glVertex2f(2.5,1.74); //Ponto inferior direito
		glVertex2f(2,3); //Ponto superior centro
		glVertex2f(1.5,1.75); //Início 
    glEnd(); 
     
}
//Desenhar triangulo usando a função GL_TRIANGLE_STRIP
void TrianguloStrip(){
	glColor3f(255,0,0); // Amarelo
    glBegin(GL_TRIANGLE_STRIP); 
        glVertex2f(1.5,1.75); //Ponto inferior esquerdo
        glVertex2f(2.5,1.75); //Ponto inferior direito
		glVertex2f(2,3); //Ponto superior centro
		glVertex2f(1.5,1.75); //Início 
    glEnd(); 
     
}

//Desenhar quadrado usando a função GL_LINE_STRIP
void DesenharQuadrado(){
	glColor3f(0,0,0); // Preto
    	glBegin(GL_LINE_STRIP); 
        glVertex2f(0.5f, 1.0f); //Ponto superior esquerdo
        glVertex2f(0.5f, -0.25f); //Ponto inferior esquerdo
        glVertex2f(1.76f, -0.26f); //Ponto inferior direito
        glVertex2f(1.75f, 1.0f); //Ponto superior esquerdo
        glVertex2f(0.5f, 1.0f); //Ponto superior esquerdo 
    glEnd();    
}

//Desenhar quadrado usando a função GL_QUAD
void QuadradoStrip(){
	glColor3f(255,255,0); // Amarelo
    glBegin(GL_QUADS); 
        glVertex2f(0.5f, 1.0f); //Ponto superior esquerdo
        glVertex2f(0.5f, -0.25f); //Ponto inferior esquerdo
        glVertex2f(1.75f, -0.25f); //Ponto inferior direito
        glVertex2f(1.75f, 1.0f); //Ponto superior esquerdo
    glEnd();    
}

//Poligono
void Poligono(){
	glColor3f(0,0,1); //azul
    glBegin(GL_TRIANGLE_STRIP); 
        glVertex2f(2.0f, -1.0f); 
        glVertex2f(3.0f, -1.0f); 
        glVertex2f(3.5f, -2.0f); 
        glVertex2f(1.5f, -2.0f);
        glVertex2f(2.0f, -1.0f); 
	glEnd(); 
}

//Desenhar poligono
void DesenharPoligono(){
	glColor3f(0,0,0); //preto
    glBegin(GL_LINE_STRIP); 
        glVertex2f(2.0f, -1.0f); 
        glVertex2f(3.0f, -1.0f); 
        glVertex2f(3.5f, -2.0f); 
        glVertex2f(1.5f, -2.0f);
        glVertex2f(2.0f, -1.0f); 
	glEnd(); 
}

//----------------------------------------------------------------
// Função callback chamada para fazer o desenho
void Desenha(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0); //Cor da linha

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5, 5, -5, 5);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	DesenhaTrelica(1);
	RetanguloJanela();
	
	DesenhaTriangulo();
		
	DesenharQuadrado();
		
	DesenharPoligono();
	
	 // Desenha uma primitiva     
    switch (trelica) {
            case ESPESSURA: glColor3f(0,0,0);
							//glLineWidth(3.0f);  // aumenta a espessura das linhas
							DesenhaTrelica(3);
                            break;
    }  
     
     switch (primitiva) {
            case COLORIDO: 
							
							TrianguloStrip();
							QuadradoStrip();
							Poligono();
                            break;
    } 
    
    glColor3f(1,0,0); 
	//Exibe o nome no canto inferior esquerdo da tela
    glRasterPos2f(-4.8,-4.8); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"Dupla: Marcos e Joyce");
	
	//Exibe o "A" no canto superior da tela
	glRasterPos2f(-4.4,4.2); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"A");
	
	//Exibe o "B" no canto superior da tela
	glRasterPos2f(0.1,4.2); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"B");
	glutSwapBuffers();
}

// Gerenciamento do menu trelica           
void MenuTrelica(int op)
{
   switch(op) {
            case 0:
                    trelica = ESPESSURA;
                    break;                    
    }
    glutPostRedisplay();
}   

// Gerenciamento do menu primitiva           
void MenuPrimitiva(int op)
{
   switch(op) {
            case 0:
                    primitiva = COLORIDO;
                    break;                    
    }
    glutPostRedisplay();
}  
      
// Gerenciamento do menu principal           
void MenuPrincipal(int op)
{
     switch(op) {
     case 0:
       exit(0);
     break;}
}

// Criacao do Menu
void CriaMenu() 
{
    int menu,submenu1,submenu2;
	
	submenu1 = glutCreateMenu(MenuPrimitiva);
    glutAddMenuEntry("Colorido",0);
    
    submenu2 = glutCreateMenu(MenuTrelica);
    glutAddMenuEntry("Espessura",0);
       
    menu = glutCreateMenu(MenuPrincipal);
    glutAddSubMenu("Primitva",submenu1);
    glutAddSubMenu("Treliça",submenu2);
    glutAddMenuEntry("Sair",0);

    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

//---------------------------------------------------------------
// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{        
    if (button == GLUT_RIGHT_BUTTON)
         if (state == GLUT_DOWN) 
            CriaMenu();
         
    glutPostRedisplay();
}

//---------------------------------------------------------------
// Inicializa parâmetros de rendering
void Inicializa (void)
{
   // Define a cor de fundo de tela como branca
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glLoadIdentity();
	gluOrtho2D(-25, 100,-25,100);
	
	glMatrixMode(GL_MODELVIEW);
}

//---------------------------------------------------                 
// Programa Principal 
int main(void){
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);     
     glutInitWindowSize(800,600);
     glutCreateWindow(" ");
     glutDisplayFunc(Desenha);
     glutMouseFunc(GerenciaMouse); 
     Inicializa();
     glutMainLoop();
}
