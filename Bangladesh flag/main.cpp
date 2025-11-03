#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>


void drawBangladeshFlag() {

    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(-1.5f, -0.9f, 0.0f);
        glVertex3f( 1.5f, -0.9f, 0.0f);
        glVertex3f( 1.5f,  0.9f, 0.0f);
        glVertex3f(-1.5f,  0.9f, 0.0f);
    glEnd();


    glColor3f(0.89f, 0.0f, 0.13f);
    float cx = -0.3f;
    float cy =  0.0f;
    float r  =  0.45f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int i = 0; i <= 360; i++) {
            float angle = i * 3.1416f / 180.0f;
            float x = cx + r * cos(angle);
            float y = cy + r * sin(angle);
            glVertex2f(x, y);
        }
    glEnd();
}


void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -3.0f);

    drawBangladeshFlag();

    glutSwapBuffers();
}


void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)width / (float)height, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}


void keyboard(unsigned char key, int, int) {
    if (key == 27 || key == 'q' || key == 'Q')
        exit(0);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutCreateWindow("Bangladesh National Flag");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return EXIT_SUCCESS;
}
