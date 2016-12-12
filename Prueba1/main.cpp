#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <GLUT/glut.h>
//#include <GL/glut.h>
#define Pi 3.1416
#include <math.h>
#include <string>
#include <thread>
using namespace std;
int bandera = 0;
int puntoF = 0;
int tiempo = 0;
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
    "vvv+++++++xxxxxxxx+xxx+xxxxxxxxx+xxxx+vvv",
    "xxx+++++++++++++++++++c+++++++++++++++xxx",
    "xxx+xxxxxxxxxxxxxx+xxx+xxxxxxxxxxxxxx+xxx",
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
    "oxx+xoxx++++++++++sxox+++++++++++xxox+xxo",
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

char copia[42][42]={
    "ooooooooooooooooooooooooooooooooooooooooo",
    "oxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxo",
    "oxxpxxoxx++++++++++xxx+++++++++++xxoxxxxo",
    "oxx+xxoxx+xxxxxxxx+xox+xxxxxxxxx+xxoxxxxo",
    "oxx+xxoxx+xxooooxx+xox+xxoooooxx+xxoxxxxo",
    "oxx+xxxxx+xxooooxx+xox+xxoooooxx+xxoxrxxo",
    "vvv+++++++xxxxxxxx+xxx+xxxxxxxxx+xxxx+vvv",
    "xxx+++++++++++++++++++c+++++++++++++++xxx",
    "xxx+xxxxxxxxxxxxxx+xxx+xxxxxxxxxxxxxx+xxx",
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
    "oxx+xoxx++++++++++sxox+++++++++++xxox+xxo",
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

int posCereza[2] = {28,18};
GLfloat position[4][2] = {{7,22},{27,18},{5,38},{37,35}};
bool comidoC,comidoB,comidoR,comidoI;

bool comidos[4] = {false,false,false,false};

string puntaje = "Puntaje: ";
string vida = "Vidas: ";
bool comible = false;
int vidas = 3;
int cereza = 0;
bool cherry = true;

void duerme();
void reload();
int Random(int min, int max);
void impriprimir();
void moverarriba(int x,int y, char c);
void moverabajo(int x, int y, char c);
void moverizquierda(int x, int y, char c);
void moverderecha(int x,int y, char c);
int mas();

int mas(){
        int puntos = 0;
        for(int i=0;i<42;i++){
            
            for(int j=0;j<42;j++)
            {
                if(mapa[i][j]=='+')
                    puntos+=1;
            }
            
        }
        return puntos;
}

void duerme(){
    
}

int Random(int min,int  max)
{
    int output = min + (rand() % (int)(max - min + 1));
    return output;
}

void Texto(char *string,GLfloat x,GLfloat y,GLfloat z){
    char *c;
    glRasterPos3f(x,y,z);
    glColor3f(1.0, 1.0, 1.0);
    for (c=string; *c !='\0'; c++){
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *c);
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
    return puntos + puntoF;
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
    char aux;
    duerme();
    if(mapa[x][y-1]=='x' || mapa[x][y-1] == 'v'){
    }else{
        if(mapa[x][y-1] == 'p'){
            if(!comible){
                impriprimir();
                reload();
            }else{
                return;
            }
        }else if(mapa[x][y-1] != c){
            aux = mapa[x][y-1];
            mapa[x][y-1] = c;
            mapa[x][y] = aux;
        }else{
            //moverabajo(x, y, c);
        }
        switch (c) {
            case 'c':
                position[0][1] -= 1;
                break;
            case 'b':
                position[1][1] -= 1;
                break;
            case 'r':
                position[2][1] -= 1;
                break;
            case 'i':
                position[3][1] -= 1;
                break;
        }
    }
    
}
void moverabajo(int x,int y,char c){
    duerme();
    char aux;
    if(mapa[x][y+1]=='x'  || mapa[x][y+1] == 'v'){
    }else{
        if(mapa[x][y+1] == 'p'){
            if(!comible){
                impriprimir();
                reload();
            }else{
                return;
            }
        }else if(mapa[x][y+1] != c){
            aux = mapa[x][y+1];
            mapa[x][y+1] = c;
            mapa[x][y] = aux;
        }else{
            //moverarriba(x, y, c);
        }
        switch (c) {
            case 'c':
                position[0][1] += 1;
                break;
            case 'b':
                position[1][1] += 1;
                break;
            case 'r':
                position[2][1] += 1;
                break;
            case 'i':
                position[3][1] += 1;
                break;
        }
    }
    
}

void moverderecha(int x,int y,char c)
{
    char aux;
    duerme();
    if(mapa[x+1][y]=='x' || mapa[x+1][y] == 'v'){
    }else{
        if(mapa[x+1][y] == 'p'){
            if(!comible){
                impriprimir();
                reload();
            }else{
                return;
            }
        }else if(mapa[x+1][y] != c){
            aux = mapa[x+1][y];
            mapa[x+1][y] = c;
            mapa[x][y] = aux;
        }else{
            //moverizquierda(x, y, c);
        }
        switch (c) {
            case 'c':
                position[0][0] += 1;
                break;
            case 'b':
                position[1][0] += 1;
                break;
            case 'r':
                position[2][0] += 1;
                break;
            case 'i':
                position[3][0] += 1;
                break;
        }
    }
    
}

void moverizquierda(int x,int y,char c)
{
    char aux;
    duerme();
    if(mapa[x-1][y]=='x' || mapa[x-1][y] == 'v'){
    }else{
        if(mapa[x-1][y] == 'p'){
            if(!comible){
                impriprimir();
                reload();
            }else{
                return;
            }
        }else if(mapa[x-1][y] != c){
            aux = mapa[x-1][y];
            mapa[x-1][y] = c;
            mapa[x][y] = aux;
        }else{
            //moverderecha(x, y, c);
        }
        switch (c){
            case 'c':
                position[0][0] -= 1;
                break;
            case 'b':
                position[1][0] -= 1;
                break;
            case 'r':
                position[2][0] -= 1;
                break;
            case 'i':
                position[3][0] -= 1;
                break;
        }
    }
    
}


void dibujarCirculo(GLfloat px,GLfloat py,GLfloat pz,GLfloat escala,GLfloat c1,GLfloat c2,GLfloat c3){
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
            if(mapa[i][j] == 's'){
                dibujarCirculo(tmpx,tmpy,0.1,.05,1.0,0.0,0.0);
            }
            if(comible){
                if(mapa[i][j]=='c'){
                    if(comidoC){}else{
                        dibujarCirculo(tmpx,tmpy,0.1,.10,0.0,0.0,1.0);
                        dibujarCirculo(tmpx-0.03,tmpy,0.18,.03,1.0,1.0,1.0);
                        dibujarCirculo(tmpx+0.03,tmpy,0.18,.03,1.0,1.0,1.0);
                        dibujarCirculo(tmpx-0.03,tmpy,0.20,.02,0.0,0.0,0.0);
                        dibujarCirculo(tmpx+0.03,tmpy,0.20,.02,0.0,0.0,0.0);
                    }
                }
                if(mapa[i][j]=='b'){
                    if(comidoB){}else{
                        dibujarCirculo(tmpx,tmpy,0.1,.10,0.0,0.0,1.0);
                        dibujarCirculo(tmpx-0.03,tmpy,0.18,.03,1.0,1.0,1.0);
                        dibujarCirculo(tmpx+0.03,tmpy,0.18,.03,1.0,1.0,1.0);
                        dibujarCirculo(tmpx-0.03,tmpy,0.20,.02,0.0,0.0,0.0);
                        dibujarCirculo(tmpx+0.03,tmpy,0.20,.02,0.0,0.0,0.0);
                    }
                }
                if(mapa[i][j]=='i'){
                    if(comidoI){}else{
                        dibujarCirculo(tmpx,tmpy,0.1,.10,0.0,0.0,1.0);
                        dibujarCirculo(tmpx-0.03,tmpy,0.18,.03,1.0,1.0,1.0);
                        dibujarCirculo(tmpx+0.03,tmpy,0.18,.03,1.0,1.0,1.0);
                        dibujarCirculo(tmpx-0.03,tmpy,0.20,.02,0.0,0.0,0.0);
                        dibujarCirculo(tmpx+0.03,tmpy,0.20,.02,0.0,0.0,0.0);
                    }
                }
                if(mapa[i][j]=='r'){
                    if(comidoR){}else{
                        dibujarCirculo(tmpx,tmpy,0.1,.10,0.0,0.0,1.0);
                        dibujarCirculo(tmpx-0.03,tmpy,0.18,.03,1.0,1.0,1.0);
                        dibujarCirculo(tmpx+0.03,tmpy,0.18,.03,1.0,1.0,1.0);
                        dibujarCirculo(tmpx-0.03,tmpy,0.20,.02,0.0,0.0,0.0);
                        dibujarCirculo(tmpx+0.03,tmpy,0.20,.02,0.0,0.0,0.0);
                    }
                }
            }else{
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
                    dibujarCirculo(tmpx,tmpy,0.1,.10,0.0,0.5,0.0);
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
            }
            tmpy-=0.1;
        }
        tmpx+=0.1;
    }
}

void ArrowKey(int key,int x,int y){
    char aux,comer;
    switch (key){
        case GLUT_KEY_RIGHT:
            if(px < 2 && (mapa[xpc+1][ypc] == 'c' || mapa[xpc+1][ypc] == 'b' || mapa[xpc+1][ypc] == 'i' || mapa[xpc+1][ypc] == 'r')){
                aux = mapa[xpc+1][ypc];
                if(!comible){
                    Texto("Has perdido",0, 2.5, .30);
                    printf("Muerto");
                    reload();
                }else{
                    comer = mapa[xpc+1][ypc];
                    switch (comer) {
                        case 'c':
                            comidos[0] = true;
                            comidoC = true;
                            break;
                        case 'b':
                            comidos[1] = true;
                            comidoB = true;
                            break;
                        case 'r':
                            comidos[2] = true;
                            comidoR = true;
                            break;
                        case 'i':
                            comidos[3] = true;
                            comidoI = true;
                            break;
                        default:
                            break;
                    }
                    px+=0.1;
                    mapa[xpc][ypc]='.';
                    xpc+=1;
                    mapa[xpc][ypc]='p';
                    puntoF += 1000;
                    
                }
            }else{
                if((mapa[xpc+1][ypc]=='+'||mapa[xpc+1][ypc]=='.')){
                    px+=0.1;
                    mapa[xpc][ypc]='.';
                    xpc+=1;
                    mapa[xpc][ypc]='p';
                }else if(mapa[xpc+1][ypc] == 's'){
                    comible = true;
                    cherry = true;
                    px+=0.1;
                    mapa[xpc][ypc]='.';
                    xpc+=1;
                    mapa[xpc][ypc]='p';
                }
            }
            break;
        case GLUT_KEY_LEFT:
            if(px > -2 && (mapa[xpc-1][ypc] == 'c' || mapa[xpc-1][ypc] == 'b' || mapa[xpc-1][ypc] == 'i' || mapa[xpc-1][ypc] == 'r')){
                if(!comible){
                    Texto("Has perdido",0, 2.5, .30);
                    printf("Muerto");
                    reload();
                }else{
                    comer = mapa[xpc-1][ypc];
                    switch (comer) {
                        case 'c':
                            comidos[0] = true;
                            comidoC = true;
                            break;
                        case 'b':
                            comidos[1] = true;
                            comidoB = true;
                            break;
                        case 'r':
                            comidos[2] = true;
                            comidoR = true;
                            break;
                        case 'i':
                            comidos[3] = true;
                            comidoI = true;
                            break;
                        default:
                            break;
                    }
                    px-=0.1;
                    mapa[xpc][ypc]='.';
                    xpc-=1;
                    mapa[xpc][ypc]='p';
                    puntoF += 1000;
                }
            }else{
                if((mapa[xpc-1][ypc]=='+'||mapa[xpc-1][ypc]=='.')){
                    px-=0.1;
                    mapa[xpc][ypc]='.';
                    xpc-=1;
                    mapa[xpc][ypc]='p';
                }else if(mapa[xpc-1][ypc]=='s'){
                    comible = true;
                    cherry = true;
                    px-=0.1;
                    mapa[xpc][ypc]='.';
                    xpc-=1;
                    mapa[xpc][ypc]='p';
                }
            }
            break;
        case GLUT_KEY_UP:
            if(xpc==7&&ypc==3){
                mapa[xpc][ypc]='.';
                px=-1.3;
                py=-1.5;
                mapa[7][37]='p';
                xpc=7;
                ypc=37;
            }else if(py < 2 && (mapa[xpc][ypc-1] == 'c' || mapa[xpc][ypc-1] == 'b' || mapa[xpc][ypc-1] == 'i' || mapa[xpc][ypc-1] == 'r')){
                if(!comible){
                    Texto("Has perdido",0, 2.5, .30);
                    printf("Muerto");
                    reload();
                }else{
                    comer = mapa[xpc][ypc-1];
                    switch (comer) {
                        case 'c':
                            comidos[0] = true;
                            comidoC = true;
                            break;
                        case 'b':
                            comidos[1] = true;
                            comidoB = true;
                            break;
                        case 'r':
                            comidos[2] = true;
                            comidoR = true;
                            break;
                        case 'i':
                            comidos[3] = true;
                            comidoI = true;
                            break;
                        default:
                            break;
                    }
                    py+=0.1;
                    mapa[xpc][ypc]='.';
                    ypc-=1;
                    mapa[xpc][ypc]='p';
                    puntoF += 1000;
                }
            }else{
                if((mapa[xpc][ypc-1]=='+'||mapa[xpc][ypc-1]=='.')){
                    py+=0.1;
                    mapa[xpc][ypc]='.';
                    ypc-=1;
                    mapa[xpc][ypc]='p';
                }else if (mapa[xpc][ypc-1] == 's'){
                    comible = true;
                    cherry = true;
                    py+=0.1;
                    mapa[xpc][ypc]='.';
                    ypc-=1;
                    mapa[xpc][ypc]='p';
                }
            }
            break;
        case GLUT_KEY_DOWN:
            if(xpc==7&&ypc==37){
                mapa[xpc][ypc]='.';
                px=-1.3;
                py=1.9;
                mapa[7][3]='p';
                xpc=7;
                ypc=3;
            }else if(py > -2 && (mapa[xpc][ypc+1] == 'c' || mapa[xpc][ypc+1] == 'b' || mapa[xpc][ypc+1] == 'i' || mapa[xpc][ypc+1] == 'r')){
                if(!comible){
                    Texto("Has perdido",0, 2.5, .30);
                    printf("Muerto");
                    reload();
                }else{
                    comer = mapa[xpc][ypc+1];
                    switch (comer) {
                        case 'c':
                            comidos[0] = true;
                            comidoC = true;
                            break;
                        case 'b':
                            comidos[1] = true;
                            comidoB = true;
                            break;
                        case 'r':
                            comidos[2] = true;
                            comidoR = true;
                            break;
                        case 'i':
                            comidos[3] = true;
                            comidoI = true;
                            break;
                        default:
                            break;
                    }
                    py-=0.1;
                    mapa[xpc][ypc]='.';
                    ypc+=1;
                    mapa[xpc][ypc]='p';
                    puntoF += 1000;
                }
            }else{
                if((mapa[xpc][ypc+1]=='+'||mapa[xpc][ypc+1]=='.')){
                    py-=0.1;
                    mapa[xpc][ypc]='.';
                    ypc+=1;
                    mapa[xpc][ypc]='p';
                }else if(mapa[xpc][ypc+1]=='s'){
                    comible = true;
                    cherry = true;
                    py-=0.1;
                    mapa[xpc][ypc]='.';
                    ypc+=1;
                    mapa[xpc][ypc]='p';
                }
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
    Texto(array,-2,-2.5,.50);
    
    lol = vida + std::to_string(vidas);
    char array1[lol.size()+1];
    strcpy(array1, lol.c_str());
    Texto(array1,2,-2.5,.50);
    
    bandera++;
    if(bandera > 5){
        bandera = 0;
    }else{
        if (bandera % 5 == 0){
            int random = Random(1, 4);
            char c[4] = {'c','b','r','i'};
            int rand = Random(0, 3);
            printf("%d",rand);
            switch (random) {
                case 1:
                    if(!comidos[rand])
                        moverizquierda(position[rand][0], position[rand][1],c[rand]);
                    break;
                case 2:
                    if(!comidos[rand])
                        moverderecha(position[rand][0], position[rand][1],c[rand]);
                    break;
                case 3:
                    if(!comidos[rand])
                        moverarriba(position[rand][0], position[rand][1],c[rand]);
                    break;
                case 4:
                    if(!comidos[rand])
                        moverabajo(position[rand][0], position[rand][1],c[rand]);
                    break;
            }
        }

    }
    
    if(cherry && cereza < 2000){
        cereza++;
    }else{
        cherry = false;
        cereza = 0;
        if(mapa[posCereza[0]][posCereza[1]] == '.' || mapa[posCereza[0]][posCereza[1]] == '+'){
            mapa[posCereza[0]][posCereza[1]] = 's';
        }else{
            mapa[posCereza[0]][posCereza[1]-1] = 's';
        }
    }
    
    if(mas() == 0){
        Texto("GANASTE", 0, 0, 3);
        sleep(1);
        exit(0);
    }
    
    if(vidas <= 0){
        Texto("Perdiste", 0, 0, 2);
        sleep(4);
        exit(0);
    }
    if(comible && tiempo < 800){
        tiempo++;
    }else{
        comible = false;
        tiempo = 0;
        comidoB = comidoC = comidoI = comidoR = false;
        comidos[0] = comidos[1] = comidos[2] = comidos[3] = false;
    }
    
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

void reload(){
    impriprimir();
    int i;
    for (i = 0; i < 42; i++) {
        strcpy(mapa[i], copia[i]);
    }
    anguloY=0;
    anguloX=0;
    anguloZ=0;
    px=-1.8;
    py=1.9;
    escala=3;
    xi=0;
    yi=0;
    xpc=2;
    ypc=3;
    vidas--;
    position[0][0] = 7;
    position[0][1] = 22;
    position[1][0] = 27;
    position[1][1] = 18;
    position[2][0] = 5;
    position[2][1] = 38;
    position[3][0] = 37;
    position[3][1] = 35;
    puntoF = 0;
    sleep(2);
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
