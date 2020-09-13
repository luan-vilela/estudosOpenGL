// COMPILAR: g++ sorvete.cpp -o app -lglut -lGLU -lGL
#include <GL/freeglut.h>
#include <math.h>
#define PI 3.1415926535898
#define ACAI glColor3f(1,0,0);

void triangulo();
void circulo(int posX, int posY, int raio, float pontosCirculo);

void init(){
    glClearColor(0, 0, 1, 0); // black e opaque
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-250,250,-250,250);
    
}
//Desenha um círculo com centro posX e posY
void circulo(int posX, int posY, int raio, float pontosCirculo){
    float angle = 0;
    glBegin(GL_POLYGON);
    for (int i = 0; i < pontosCirculo; i++) {
        angle = i*PI/180;
        glVertex2f(posX+raio*cos(angle), posY+raio*sin(angle));
    }
    glEnd();
}
// display
void desenha(){
    glClear(GL_COLOR_BUFFER_BIT); // limpar buffer

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    //BOLAS DE SORVETE
    glColor3f(1.0,0.0,0.0);
    circulo(0, -1, 50, 180);
    
    glColor3f(0.0f, 0.1f, 0.0f);
    circulo(0, 95, 50, 360);

    glColor3f(0.5f, 1.0f, 1.0f);
    circulo(0, 190, 50, 360);

    //CASQUINHA
    triangulo();
    glFlush();

}

void triangulo(){
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
        glVertex2d(-40, 0);
        glVertex2d(40, 0);
        glVertex2d(0, -150);
    glEnd();
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(120, 120);
    glutInitWindowSize(480,480);
    glutCreateWindow("Sorvete");

    glutDisplayFunc(desenha);
    glutIdleFunc(desenha);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();
    return 0;
}