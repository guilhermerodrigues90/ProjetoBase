#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <stdio.h>
#include <math.h>
#include<iostream>
using namespace std;

GLfloat angle = 0.0;

void createMenu(void);
void menu(int value);
void disp(void);

static int win;
static int menyid;
static int animeringsmeny;
static int springmeny;
static int quadrado_grandemeny;
static int conemeny;
static int chaleirameny;
static int val = 0;
static int fyrkantRoed = 1;
static int fyrkantGroen = 0;
static int fyrkantBla = 0;
static int trekantRoed = 1;
static int trekantGroen = 0;
static int trekantBla = 0;
float a,b,c;

int main(int argc, char **argv){

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);
win = glutCreateWindow("GLUT MENU");
createMenu();
glClearColor(0.0,0.0,0.0,0.0);
glutDisplayFunc(disp);
glutMainLoop();
}

void createMenu(void){

animeringsmeny = glutCreateMenu(menu);

glutAddMenuEntry("Branco", 1);
glutAddMenuEntry("Vermelho", 2);
glutAddMenuEntry("Azul", 3);

springmeny = glutCreateMenu(menu);

glutAddMenuEntry("Branco", 4);
glutAddMenuEntry("Vermelho", 5);
glutAddMenuEntry("Azul", 6);

quadrado_grandemeny = glutCreateMenu(menu);

glutAddMenuEntry("Branco", 7);
glutAddMenuEntry("Vermelho", 8);
glutAddMenuEntry("Azul", 9);

conemeny = glutCreateMenu(menu);

glutAddMenuEntry("Branco", 10);
glutAddMenuEntry("Vermelho", 11);
glutAddMenuEntry("Azul", 12);

chaleirameny = glutCreateMenu(menu);

glutAddMenuEntry("Branco", 13);
glutAddMenuEntry("Vermelho", 14);
glutAddMenuEntry("Azul", 15);
menyid = glutCreateMenu(menu);

    glutAddMenuEntry("Limpar", 100);
glutAddSubMenu("Traingulo", animeringsmeny);
glutAddSubMenu("Quadrado", springmeny);
glutAddSubMenu("Quadrado Grande", quadrado_grandemeny);
glutAddSubMenu("Cone", conemeny);
glutAddSubMenu("Chaleira", chaleirameny);
glutAddMenuEntry("Sair", 0);

glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void triangulo(float a, float b,float c){

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3d(a, b, c);
    glVertex2f( 0.0f, 0.0f);
    glVertex2f( 0.25f, 0.50f);
    glVertex2f( 0.50f, 0.0f);
    glEnd();
    glutSwapBuffers();
}

void quadrado(float a, float b, float c){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
glColor3d(a, b, c);
glVertex2f( 0.0f, 0.0f);
    glVertex2f( 0.50f, 0.0f);
    glVertex2f( 0.50f, 0.50f);
    glVertex2f( 0.0f, 0.50f);
    glEnd();
    glutSwapBuffers();
}

void quadrado_grande(float a, float b, float c){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3d(a, b, c);

    glVertex2f(-1.0f, 0.0f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(0.0f, -1.0f);

    glEnd();
    glutSwapBuffers();
}

void cone(float a, float b, float c){
    glPushMatrix();
    glColor3d(a, b, c);
    glRotated(65, -1.0, 0.0, 0.0);
    glutWireCone(0.5, 1.0, 50, 50);
    glPopMatrix();
}

void chaleira(float a, float b, float c){
    glPushMatrix();
    glColor3d(a, b, c);
    glutSolidTeapot(0.5);
    glPopMatrix();
}
void limpa(){
    glClear(GL_COLOR_BUFFER_BIT);
    glEnd();
    glutSwapBuffers();
}

void disp(void){
    float tempoEntrada;
    float tempoSaida;

glClear(GL_COLOR_BUFFER_BIT);

tempoEntrada = (float) glutGet(GLUT_ELAPSED_TIME);

if(val == 100){
            limpa();
}else if(val == 1){
        triangulo(1.0,1.0,1.0);
}else if(val == 2){
        triangulo(1.0,0.0,0.0);
}else if(val == 3){
        triangulo(0.0,0.0,1.0);
}else if(val == 4){
   quadrado(1.0,1.0,1.0);
    }else if(val == 5){
   quadrado(1.0,0.0,0.0);
    }else if(val == 6){
   quadrado(0.0,0.0,1.0);
    }else if(val == 7){
   quadrado_grande(1.0,1.0,1.0);
    }else if(val == 8){
   quadrado_grande(1.0,0.0,0.0);
    }else if(val == 9){
   quadrado_grande(0.0,0.0,1.0);
    }else if(val == 10){
   cone(1.0,1.0,1.0);
    }else if(val == 11){
   cone(1.0,0.0,0.0);
    }else if(val == 12){
   cone(0.0,0.0,1.0);
    }else if(val == 13){
   chaleira(1.0,1.0,1.0);
    }else if(val == 14){
   chaleira(1.0,0.0,0.0);
    }else if(val == 15){
   chaleira(0.0,0.0,1.0);
}
glFlush();
tempoSaida = (float) glutGet(GLUT_ELAPSED_TIME);
cout << "Tempo: "<<tempoSaida - tempoEntrada << "\n";
}



void menu(int value){
if(value == 0){
glutDestroyWindow(win);
exit(0);
}else{
val=value;
}
glutPostRedisplay();
}
