#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <GLUT/glut.h>
//#include <GL/glut.h>
#define Pi 3.1416
#include <math.h>
#include <string>
using namespace std;

GLdouble anguloY=0;
GLdouble anguloX=0;
GLdouble anguloZ=0;
GLdouble px=-1.8;
GLdouble py=1.9;
GLint escala=3;
GLfloat xi=0;
GLfloat yi=0;
GLint xpc=2;
GLint ypc=3;
char mapa[42][42]={
    "ooooooooooooooooooooooooooooooooooooooooo",
    "oxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxo",
    "oxxpxxoxx++++++++++xxx+++++++++++xxoxxxxo",
    "oxx+xxoxx+xxxxxxxx+xox+xxxxxxxxx+xxoxxxxo",
    "oxx+xxoxx+xxooooxx+xox+xxoooooxx+xxoxxxxo",
    "oxx+xxxxx+xxooooxx+xox+xxoooooxx+xxoxrxxo",
    "oxx+++++++xxxxxxxx+xxx+xxxxxxxxx+xxxx+xxo",
    "oxx+++++++++++++++++++c+++++++++++++++xxo",
    "oxx+xxxxxxxxxxxxxx+xxx+xxxxxxxxxxxxxx+xxo",
    "oxx+xooooooooooxxx+xox+xoooooooooooox+xxo",
    "oxx+xooxxxxxxxxxxx+xxx+xxxxxxxxxxxxox+xxo",
    "oxx+xoox+++++++++++xox++++++++++xooox+xxo",
    "oxx+xooxxxxxxxxxxx+xox+xxxxxxxxxxxxox+xxo",
    "oxx+xoooooooooooox+xox+xoooooooooooox+xxo",
    "oxx+xoxxxxxxxxxxxx+xox+xxxxxxxxxxxxox+xxo",
    "oxx+xoxx+++++++++++xox+++++++++++xxox+xxo",
    "oxx+xoxx+xxxxxxxxx+xox+xxxxxxxxx+xxox+xxo",
    "oxx+xoxx+xooooooox+xox+xooooooox+xxox+xxo",
    "oxx+xoxx+xooooooox+xox+xooooooox+xxox+xxo",
    "oxx+xoxx+xxxxxxxxx+xox+xxxxxxxxx+xxox+xxo",
    "oxx+xoxx+++++++++++xox+++++++++++xxox+xxo",
    "oxx+xoxx+xxxxxxxxx+xox+xxxxxxxxx+xxox+xxo",
    "oxx+xoxx+xooooooox+xox+xooooooox+xxox+xxo",
    "oxx+xoxx+xxxxoooox+xox+xooooxxxx+xxox+xxo",
    "oxx+xoxx++++xoooox+xox+xoooox++++xxox+xxo",
    "oxx+xoxx+xxxxoooox+xox+xooooxxxx+xxox+xxo",
    "oxx+xoxx+xooooooox+xox+xooooooox+xxox+xxo",
    "oxx+xoxx+xoooooooxbxox+xooooooox+xxox+xxo",
    "oxx+xoxx+xxxxxxxxx+xox+xxxxxxxxx+xxox+xxo",
    "oxx+xoxx+++++++++++xox+++++++++++xxox+xxo",
    "oxx+xoxxxxxxxxxxxx+xox+xxxxxxxxxxxxox+xxo",
    "oxx+xoooooooooooox+xox+xoooooooooooox+xxo",
    "oxx+xxxxxxxxxxxxxx+xxx+xxxxxxxxxxxxxx+xxo",
    "oxx+++++++++++++++++++++++++++++++++++xxo",
    "oxx+xxx+xxxxxxxxxxxxxxxxxxxxxxxxx+xxx+xxo",
    "oxx+xox+xooooooooooooooooooooooox+xox+xxo",
    "oxx+xxx+xxxxxxxxxxxxxxxxxxxxxxxxx+xxx+xxo",
    "oxx++++++++++++++++++++++++++++++++i++xxo",
    "oxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxo",
    "ooooooooooooooooooooooooooooooooooooooooo",
};

string puntaje = "Puntaje: ";


void Texto(char *string,GLfloat x,GLfloat y,GLfloat z){
    char *c;
    glRasterPos3f(x,y,z);
    for (c=string; *c !='\0'; c++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
}

int puntos()
{
    int puntos =0;
    for(int i=0;i<42;i++){
        
        for(int j=0;j<42;j++)
        {
            if(mapa[i][j]=='.')
                puntos+=1;
        }
        
    }
    return puntos;
}
void impriprimir()
{
    for(int i=0;i<42;i++){
        
        for(int j=0;j<42;j++)
        {
            printf("%c",mapa[i][j]);
        }
        printf("\n");
    }
}

void moverarriba(int x,int y,char c)
{
    if(mapa[x][y-1]=='x')
    {}else{
        if(mapa[x][y-1]=='.')
        {	mapa[x][y-1]=c;
            mapa[x][y]='.';
        }else{
            if(mapa[x][y-1]=='+')
                mapa[x][y-1]=c;
            mapa[x][y]='+';
            
        }
    }
    
}
void moverabajo(int x,int y,char c)
{
    if(mapa[x][y+1]=='x')
    {}else{
        if(mapa[x][y+1]=='.')
        {	mapa[x][y+1]=c;
            mapa[x][y]='.';
        }else{
            if(mapa[x][y+1]=='+')
                mapa[x][y+1]=c;
            mapa[x][y]='+';
            
        }
    }
	   
}

void moverderecha(int x,int y,char c)
{
    if(mapa[x+1][y]=='x')
    {}else{
        if(mapa[x+1][y]=='.')
        {	mapa[x+1][y]=c;
            mapa[x][y]='.';
        }else{
            if(mapa[x+1][y]=='+')
                mapa[x+1][y]=c;
            mapa[x][y]='+';
            
        }
    }
    
}

void moverizquierda(int x,int y,char c)
{
    if(mapa[x-1][y]=='x')
    {}else
        if(mapa[x-1][y]=='.')
        {	mapa[x-1][y]=c;
            mapa[x][y]='.';
        }else{
            if(mapa[x-1][y]=='+')
                mapa[x-1][y]=c;
            mapa[x][y]='+';
            
        }
    
}



void dibujarCirculo(GLfloat px,GLfloat py,GLfloat pz,GLfloat escala,GLfloat c1,GLfloat c2,GLfloat c3)
{
    glPushMatrix();
    glTranslatef(px,py,pz);
    glRotatef(45, 0, 1, 1);
    glScalef(1.0, 1.0, 1.0);
    glColor3f(c1,c2,c3 );
    glutSolidSphere(escala,15,15);
    glPopMatrix();
    
}





void dibujarCubo(GLfloat px1,GLfloat py1 ,GLfloat pz1){
    //ladoblanco
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(px1+0.1,py1-0.1,pz1+0.1);
    glVertex3f(px1+0.1,py1+0.1,pz1+0.1);
    glVertex3f(px1-0.1,py1+0.1,pz1+0.1);
    glVertex3f(px1-0.1,py1-0.1,pz1+0.1);
    glEnd();
    //ladomorado
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex3f(px1+0.1,py1-0.1,pz1-0.1);
    glVertex3f(px1+0.1,py1+0.1,pz1-0.1);
    glVertex3f(px1+0.1,py1+0.1,pz1+0.1);
    glVertex3f(px1+0.1,py1-0.1,pz1+0.1);
    glEnd();
    
    //ladoazul
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(px1+0.1,py1+0.1,pz1+0.1);
    glVertex3f(px1+0.1,py1+0.1,pz1-0.1);
    glVertex3f(px1-0.1,py1+0.1,pz1-0.1);
    glVertex3f(px1-0.1,py1+0.1,pz1+0.1);
    glEnd();
    //ladoverde
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(px1-0.1,py1-0.1,pz1+0.1);
    glVertex3f(px1-0.1,py1+0.1,pz1+0.1);
    glVertex3f(px1-0.1,py1+0.1,pz1-0.1);
    glVertex3f(px1-0.1,py1-0.1,pz1-0.1);
    glEnd();
    
    // lado rojo
    glBegin(GL_POLYGON);
    glColor3f(   1.0, 0.0, 0.0 );
    glVertex3f( px1+0.1, py1-0.1, pz1-0.1 );
    glVertex3f( px1+0.1, py1-0.1, pz1+0.1 );
    glVertex3f( px1-0.1, py1-0.1, pz1+0.1 );
    glVertex3f( px1-0.1, py1-0.1, pz1-0.1 );
    glEnd();
}

void pintar_matriz(){
    GLfloat tmpx=-2.0;
    GLfloat tmpy=2.0;
    
    for(int i=0;i<42;i++){
        tmpy=2.0;
        for(int j=0;j<42;j++)
        {
            if(mapa[i][j]=='p'){
                dibujarCirculo(tmpx,tmpy,0.1,.10,1.0,1.0,0.0);
                dibujarCirculo(tmpx-0.03,tmpy,0.18,.035,1.0,1.0,1.0);
                dibujarCirculo(tmpx+0.03,tmpy,0.18,.035,1.0,1.0,1.0);
                dibujarCirculo(tmpx-0.03,tmpy,0.20,.02,0.117,0.564,1.0);
                dibujarCirculo(tmpx+0.03,tmpy,0.20,.02,0.117,0.564,1.0);}
            if(mapa[i][j]=='+')
                dibujarCirculo(tmpx,tmpy,.04,0.02,1.0,1.0,0.0);
            if(mapa[i][j]=='o')
                dibujarCubo(tmpx,tmpy,.10);
            if(mapa[i][j]=='c'){
                dibujarCirculo(tmpx,tmpy,0.1,.10,1.0,0.5,0.0);
                dibujarCirculo(tmpx-0.03,tmpy,0.18,.03,1.0,1.0,1.0);
                dibujarCirculo(tmpx+0.03,tmpy,0.18,.03,1.0,1.0,1.0);
                dibujarCirculo(tmpx-0.03,tmpy,0.20,.02,0.0,0.0,0.0);
                dibujarCirculo(tmpx+0.03,tmpy,0.20,.02,0.0,0.0,0.0);
            }
            if(mapa[i][j]=='b'){
                dibujarCirculo(tmpx,tmpy,0.1,.10,1.0,0.0,0.0);
                dibujarCirculo(tmpx-0.03,tmpy,0.18,.03,1.0,1.0,1.0);
                dibujarCirculo(tmpx+0.03,tmpy,0.18,.03,1.0,1.0,1.0);
                dibujarCirculo(tmpx-0.03,tmpy,0.20,.02,0.0,0.0,0.0);
                dibujarCirculo(tmpx+0.03,tmpy,0.20,.02,0.0,0.0,0.0);
            }
            if(mapa[i][j]=='i'){
                dibujarCirculo(tmpx,tmpy,0.1,.10,0.0,0.0,1.0);
                dibujarCirculo(tmpx-0.03,tmpy,0.18,.03,1.0,1.0,1.0);
                dibujarCirculo(tmpx+0.03,tmpy,0.18,.03,1.0,1.0,1.0);
                dibujarCirculo(tmpx-0.03,tmpy,0.20,.02,0.0,0.0,0.0);
                dibujarCirculo(tmpx+0.03,tmpy,0.20,.02,0.0,0.0,0.0);
            }
            if(mapa[i][j]=='r'){
                dibujarCirculo(tmpx,tmpy,0.1,.10,1.0,0.4,0.7);
                dibujarCirculo(tmpx-0.03,tmpy,0.18,.03,1.0,1.0,1.0);
                dibujarCirculo(tmpx+0.03,tmpy,0.18,.03,1.0,1.0,1.0);
                dibujarCirculo(tmpx-0.03,tmpy,0.20,.02,0.0,0.0,0.0);
                dibujarCirculo(tmpx+0.03,tmpy,0.20,.02,0.0,0.0,0.0);
            }
            tmpy-=0.1;
        }
        tmpx+=0.1;
    }
}

void ArrowKey(int key,int x,int y){
    
    switch (key){
            
        case GLUT_KEY_RIGHT:
            if(px<2&(mapa[xpc+1][ypc]=='+'||mapa[xpc+1][ypc]=='.')){
                px+=0.1;
                mapa[xpc][ypc]='.';
                xpc+=1;
                mapa[xpc][ypc]='p';
                
            }
            break;
        case GLUT_KEY_LEFT:
            if(px>-2&(mapa[xpc-1][ypc]=='+'||mapa[xpc-1][ypc]=='.')){
                px-=0.1;
                mapa[xpc][ypc]='.';
                xpc-=1;
                mapa[xpc][ypc]='p';
            }
            break;
        case GLUT_KEY_UP:
            if(py<2&(mapa[xpc][ypc-1]=='+'||mapa[xpc][ypc-1]=='.')){
                py+=0.1;
                mapa[xpc][ypc]='.';
                ypc-=1;
                mapa[xpc][ypc]='p';
            }
            break;
        case GLUT_KEY_DOWN:
            
            if(py>-2&&(mapa[xpc][ypc+1]=='+'||mapa[xpc][ypc+1]=='.')){
                py-=0.1;
                mapa[xpc][ypc]='.';
                ypc+=1;
                mapa[xpc][ypc]='p';
            }
            break;
            
        case GLUT_KEY_HOME:
            if(escala > 5)
                escala=5;
            cout << "Aumentando Escala" << endl;
            escala=escala+1;
            break;
        case GLUT_KEY_END:
            cout << "Disminuyendo escala" << endl;
            escala=2;
            break;
        case GLUT_KEY_F1:
            cout << "Rotando negativamente" << endl;
            anguloZ-=5;
            break;
        case GLUT_KEY_F2:
            cout << "Rotando positivamente" << endl;
            anguloZ+=5;
            break;
        case GLUT_KEY_F3:
            cout << "Rotando negativamente" << endl;
            anguloX-=5;
            break;
        case GLUT_KEY_F4:
            cout << "Rotando positivamente" << endl;
            anguloX+=5;
            break;		
        case GLUT_KEY_F5:
            cout << "Rotando negativamente" << endl;
            anguloY+=5;
            break;	
        case GLUT_KEY_F6:
            cout << "Rotando positivamente" << endl;
            anguloY-=5;
            break;		
        default:
            break;
    }
    glutPostRedisplay();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0,0.0,0.5,0.0,0.0,0.0,0.0,1.0,0.0);
    
    glPushMatrix();
    glTranslatef(xi,yi,-3);
    glScaled(escala,escala,1.0);
    glRotated(anguloX,1.0,0.0,0.0);
    glRotated(anguloY,0.0,1.0,0.0);
    glRotated(anguloZ,0.0,0.0,1.0);
    
    glBegin(GL_POLYGON);   //PISO
    glColor3f(0.5,0.1,0.5);	
    glVertex3f(-2,2,0);
    glVertex3f(2,2,0);
    glVertex3f(2,-2,0);
    glVertex3f(-2,-2,0);	
    glEnd();	
    pintar_matriz();
    
    Texto("PACMAN",0,2.5,.30);
    string lol = puntaje + std::to_string(puntos());
    char array[lol.size()+1];
    strcpy(array, lol.c_str());
    Texto(array,0,-2.5,.50);
    
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
    
}

void reshape(int w,int h){
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0,10.0,-10.0,10.0,0.1,20.0);
    glMatrixMode(GL_MODELVIEW);	
}

void keyboard(unsigned char key,int x,int y){
    switch(key){
        case 28:
            exit(0);
            break;
    }	
}

int main(int argc,char** argv){
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(1900,700);	
    glutInitWindowPosition(0,0);
    glutCreateWindow("Pac-Man");
    glEnable(GL_DEPTH_TEST);
    init();	
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);
    glutSpecialFunc(ArrowKey);
    glutMainLoop();
    
    return 0;	
}
