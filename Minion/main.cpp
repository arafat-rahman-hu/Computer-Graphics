#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>

void fillCircle(float cx, float cy, float r, int segments = 50) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= segments; ++i) {
        float theta = 2.0f * 3.1416f * i / segments;
        glVertex2f(cx + r * cosf(theta), cy + r * sinf(theta));
    }
    glEnd();
}

void fillRect(float x1, float y1, float x2, float y2) {
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void drawMinion() {

    glColor3f(1.0f, 0.9f, 0.0f);
    fillRect(-0.5f, -0.6f, 0.5f, 0.6f);
    fillCircle(0.0f, 0.6f, 0.5f);

    glColor3f(0.0f, 0.5f, 0.5f);
    fillRect(-0.5f, -0.6f, 0.5f, -0.1f);

    glBegin(GL_POLYGON);
    glVertex2f(-0.5f, -0.1f);
    glVertex2f(-0.3f, 0.25f);
    glVertex2f(-0.2f, 0.25f);
    glVertex2f(0.0f, -0.1f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.5f, -0.1f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.2f, 0.25f);
    glVertex2f(0.0f, -0.1f);
    glEnd();


    glColor3f(0.0f, 0.4f, 0.4f);
    fillRect(-0.15f, -0.35f, 0.15f, -0.15f);


    glColor3f(1.0f, 0.9f, 0.0f);
    fillRect(-0.7f, 0.1f, -0.5f, -0.05f);
    fillRect(0.5f, 0.1f, 0.7f, -0.05f);


    glColor3f(0.3f, 0.15f, 0.05f);
    fillCircle(-0.7f, 0.0f, 0.07f);
    fillCircle(0.7f, 0.0f, 0.07f);


    glColor3f(0.0f, 0.5f, 0.5f);
    fillRect(-0.35f, -0.6f, -0.15f, -0.85f);
    fillRect(0.15f, -0.6f, 0.35f, -0.85f);


    glColor3f(0.3f, 0.15f, 0.05f);
    fillRect(-0.4f, -0.85f, -0.1f, -0.9f);
    fillRect(0.1f, -0.85f, 0.4f, -0.9f);

    glColor3f(0.3f, 0.3f, 0.3f);
    fillCircle(-0.2f, 0.55f, 0.23f);
    fillCircle(0.2f, 0.55f, 0.23f);


    glColor3f(1.0f, 0.9f, 0.0f);
    fillCircle(-0.2f, 0.55f, 0.18f);
    fillCircle(0.2f, 0.55f, 0.18f);

    glColor3f(1.0f, 1.0f, 1.0f);
    fillCircle(-0.2f, 0.55f, 0.1f);
    fillCircle(0.2f, 0.55f, 0.1f);

    glColor3f(0.0f, 0.0f, 0.0f);
    fillCircle(-0.2f, 0.55f, 0.05f);
    fillCircle(0.2f, 0.55f, 0.05f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.1f, 0.3f);
    glVertex2f(0.0f, 0.28f);
    glVertex2f(0.1f, 0.3f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    drawMinion();
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspect = (float)w / h;
    if (aspect >= 1)
        glOrtho(-1.0f * aspect, 1.0f * aspect, -1.0f, 1.0f, -1.0f, 1.0f);
    else
        glOrtho(-1.0f, 1.0f, -1.0f / aspect, 1.0f / aspect, -1.0f, 1.0f);
}

void keyboard(unsigned char key, int, int) {
    if (key == 27 || key == 'q' || key == 'Q') exit(0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Minion Character");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
