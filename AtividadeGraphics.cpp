  /*
    * Projeto: Implementação da biblioteca graphics
    * Autor: Joyce Claine e Marcos Monteiro 
	* Dados: 
	* Versao: 1.0
	* Data da ultima modificao:19/02/219
    * Descrição: Primeita atividade de computação gráfica
*/


#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

#define SIGN(x) ((x) < 0 ? (-1) : (1))
#define ABS(x) ((x) < 0 ? (-x) : (x))
#define FALSE 0
#define TRUE 1
#define Pi 3.14159

using namespace std;
int p1[2], p2[2],p3[2],XMAX,YMAX;

//--------------------------------------------------------------------------
//------------------MENU------------------
//--------------------------------------------------------------------------

void menu(){
    cout << "----------------- MENU -----------------" << endl;
    cout << "[0] Limpar Tela" << endl;//OK
    cout << "[1] Algoritmo Reta: Equacao Geral" << endl;//OK
    cout << "[2] Algoritmo Reta: Equacao Diferencial" << endl;//OK
    cout << "[3] Algoritmo Reta: Bresenham" << endl; //OK
    cout << "[4] Algoritmo Circuferencia: Equacao Parametrica" << endl; //Não Implementado 
    cout << "[5] Algoritmo Circunferencia: Ponto Medio" << endl; //OK
    cout << "[6] Desenhar Retangulo" << endl; //OK
    cout << "[7] Desenhar Poligono" << endl; //OK
    cout << "[8] Preencher Poligono" << endl; //Não Implementado
    cout << "[9] Tracejado" << endl; //OK
	cout << "[10] Construir Grade na Janela" << endl; //OK
    cout << "[11] Sair" << endl; //OK
    cout << "----------------------------------------" << endl;
}

//--------------------------------------------------------------------------
//------------------EQUAÇÃO GERAL------------------
//--------------------------------------------------------------------------

void EquacaoGeral(int p1[2],int p2[2]){ 
	int y, x, x1, x2, y1, y2, m, b;
	x1=p1[0];
	x2=p2[0];
	y1=p1[1];
	y2=p2[1];
	if(x1 == x2){
		for(y = y1; y < y2 ;y++)
			putpixel(x1,YMAX-y,1);
	}else{
		m = (y2-y1)/(x2-x1);
		b = y2 - m*x2;
		for(x = x1; x < x2; x++){
			y = m*x + b;
			putpixel(x,YMAX-y,1);
		}
	}
}

//--------------------------------------------------------------------------
//------------------EQUAÇÃO DIFERENCIAL------------------
//--------------------------------------------------------------------------

void DDA(int p1[2], int p2[2]){
	int x, x1, x2, y1, y2;
	float y, m;
	int valor;
	x1=p1[0];
	x2=p2[0];
	y1=p1[1];
	y2=p2[1];
	m = (y2-y1)/(x2-x1); /* 0 < |m| < 1 */
	for (x = x1; x <= x2; x++) {
		y= y1+ m*(x-x1);
	putpixel(x, round(y), valor);
	}
}

//--------------------------------------------------------------------------
//------------------BRESENHAM------------------
//--------------------------------------------------------------------------

void Bresenham(int x1, int y1, int x2, int y2){
	int i,Sinalx,Sinaly,x,y,Troca;
	float Dx,Dy,tmp,P;
	Dx= ABS((x2-x1));
	Dy= ABS((y2-y1));
	Sinalx=SIGN((x2-x1));
	Sinaly=SIGN((y2-y1));
	x = x1;
	y = y1;
	if (Sinalx < 0)
	  x -=1;
	if (Sinaly < 0 )
	  y -= 1;
// trocar Dx por Dy dependendo da inclinacao da reta
	Troca= FALSE;
 	if (Dy > Dx){
  		tmp= Dx;
    	Dx= Dy;
    	Dy= tmp;
    	Troca= TRUE;
   }
	P= 2*Dy-Dx;
  	for(i=0;i<Dx;i++){
		putpixel(x,YMAX-y,5);
		while(P>=0) { 
	  		if(Troca)
				x = x+Sinalx;
      		else
       			y=y+Sinaly;
     		P = P -2*Dx;
    }
    if(Troca)
    	y = y+Sinaly;
    else
    	x = x+Sinalx;
    P= P +2*Dy;
   } 
		 
}   

//--------------------------------------------------------------------------
//------------------EQUAÇÃO PARAMÉTRICA------------------
//--------------------------------------------------------------------------






//--------------------------------------------------------------------------
//------------------ALGORITMO DO PONTO MÉDIO------------------
//--------------------------------------------------------------------------

//------------------SIMETRIA DE ORDEM 8------------------

void CirclePoints(int x,int y,int color){	
	putpixel( x, y, color);
	putpixel( x, -y, color);
	putpixel(-x, y, color); 
	putpixel(-x, -y, color);
	putpixel( y, x, color);
	putpixel( y, -x, color);
	putpixel(-y, x, color);
	putpixel(-y, -x, color);
}

void MidpointCircle(int radius,int value){
	int x = 0;
	int y = radius;
	int d = 1 - radius;
	CirclePoints(x, y, value);
	while(y > x) {
		if(d < 0)
			d += 2*x + 3;
		else{
			d += 2*(x - y) + 5;
			y--;}
		x++;
		CirclePoints(x, y, value);
	}
}

//--------------------------------------------------------------------------
//------------------RETANGULO------------------
//--------------------------------------------------------------------------

void Retangulo( int x1, int y1, int x2, int y2){
    //bases
	Bresenham(x1, y1, x2, y2);
    Bresenham(x1, y1*2, x2, y2*2); 
    
	//lados
	Bresenham(x1, y1, x1, y1*2);
	Bresenham(x2, y2, x2, y2*2);
  
}

//--------------------------------------------------------------------------
//------------------POLIGONO------------------
//--------------------------------------------------------------------------

void Poligono(int x1, int y1, int x2, int y2){

		//Basses 
		Bresenham(x1, y1, x2, y2);
		Bresenham(x1, y1*3, x2, y2*3);
		
		//Lados direito 
		Bresenham(x2, y2, x1*2.44, y1*2);
		Bresenham(x2, y2*3, x1*2.44, y1*2);
		
		//Lado esquerdo
		Bresenham(x1, y1, x1*0.5, y1*2);
		Bresenham(x1, y1*3, x1*0.5, y1*2);
}	

//--------------------------------------------------------------------------
//------------------TRACEJADO------------------
//--------------------------------------------------------------------------

void Tracejado(int x1, int y1, int x2, int y2){
    int i,Sinalx,Sinaly,x,y,Troca, cont=0;
    float Dx,Dy,tmp,P;
    Dx= ABS((x2-x1));
    Dy= ABS((y2-y1));
    Sinalx=SIGN((x2-x1));
    Sinaly=SIGN((y2-y1));
    x = x1;
    y = y1;
    if (Sinalx < 0)
      x -=1;
    if (Sinaly < 0 )
      y -= 1;
    Troca= FALSE;
     if (Dy > Dx){
          tmp= Dx;
        Dx= Dy;
        Dy= tmp;
        Troca= TRUE;
   }
    P= 2*Dy-Dx;
      for(i=0;i<Dx;i++){
          if(i%30==0)
              while(cont<5){
                putpixel(x+cont,YMAX-y,1);
                cont+=1;
            }
        cont=0;

        /*while(P>=0) { 
              if(Troca)
                x = x+Sinalx;
              else
                   y=y+Sinaly;
             P = P -2*Dx;
    }*/
    if(Troca)
        y = y+Sinaly;
    else
        x = x+Sinalx;
    P= P +2*Dy;
   } 
}

//--------------------------------------------------------------------------
//------------------PREEENCHER POLIGONO------------------
//--------------------------------------------------------------------------

void fillPoligono(){
	
}

//--------------------------------------------------------------------------
//------------------CONSTRUIR GRADE NA JANELA------------------
//--------------------------------------------------------------------------

void gradeJanela(){
	Tracejado(15, 30, 15, 438);//lado esquedo
	Tracejado(15, 30, 700, 30);//baixo
	
	Tracejado(15, 430, 700, 430);//cima
	Tracejado(690, 40, 690, 430);//lado direito
}

//--------------------------------------------------------------------------
//------------------MAIN------------------
//--------------------------------------------------------------------------

int main(){
	XMAX = 720; YMAX = 440;
    int x1,x2,y1,y2, opcao;
	
    do{
		menu();	
		cout << "\nEscolha uma opcao: ";
		cin >> opcao;
	
    switch (opcao) {
    	
    case 0: //limpar tela 
        system("cls || clear");
        break;
        
  	case 1: //Algoritmo Reta: Equacao Geral     
		cout<<"Digite o ponto inicial da reta (X1,Y1): ";
		cin>>p1[0]>>p1[1];
		cout<<"Digite o ponto final da reta (X2,Y2): ";
		cin>>p2[0]>>p2[1];
		initwindow(XMAX, YMAX);
		EquacaoGeral(p1,p2);
		getch( );
		closegraph( );
		break;
			
  	case 2: //Algoritmo Reta: Equacao Diferencial
	    cout<<"Digite o ponto inicial da reta (X1,Y1): ";
		cin>>p1[0]>>p1[1];
		cout<<"Digite o ponto final da reta (X2,Y2): ";
		cin>>p2[0]>>p2[1];
		initwindow(XMAX, YMAX);
		DDA(p1, p2);
		getch( );
		closegraph( );
		break;
		
	case 3: //bresenham   
    	cout<<"Digite o ponto inicial (X1,Y1): ";
		cin>>x1>>y1;
		cout<<"Digite o ponto final (X2,Y2): ";
		cin>>x2>>y2;
		initwindow(XMAX, YMAX);
		Bresenham(x1, y1, x2, y2);			
		getch( );
		closegraph( );
		break;

	case 5:	//ponto medio
		cout<<"Digite o ponto inicial e final: ";
		cin>>x1>>y1;	
		initwindow(XMAX, YMAX);
		MidpointCircle(x1, y1);
		getch( );
		closegraph( );
		break;

	case 6:  //desenhar retangulo
    	initwindow(XMAX, YMAX);
		Retangulo(150, 150, 450, 150);
		getch( );
		closegraph( );
		break;
		
	case 7: //desenhar poligono
	    initwindow(XMAX, YMAX);
	    Poligono(230, 110, 450, 110);
		getch( );
		closegraph( );
		break;	
	
	case 8: //preencher poligono
		initwindow(XMAX, YMAX);
		//setbkcolor(3);
	    //cleardevice();
		//Poligono(230, 110, 450, 110);
		//fillpoly(4, Poligono(230, 110, 450, 110))
		getch( );
		closegraph( );
		break;	
	
	case 9: //tracejado
    	cout<<"Digite o ponto inicial (X1,Y1): ";
		cin>>x1>>y1;
		cout<<"Digite o ponto final (X2,Y2): ";
		cin>>x2>>y2;
		initwindow(XMAX, YMAX);
		Tracejado(x1, y1, x2, y2);
		getch( );
		closegraph( );
		break;	
	
	case 10: //construir grade na janela
		initwindow(XMAX, YMAX);//janela 720x440
	    gradeJanela();
		getch( );
		closegraph( );
		break;	
	
	case 11: //sair
		break;	
	  }	
	}
	
	while (opcao != 10);

return  0;
}
