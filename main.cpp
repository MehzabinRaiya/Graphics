
#include <windows.h>
#include <GL/glut.h>
#include<math.h>>

# define PI           3.14159265358979323846



GLfloat i = 0.0f;
GLfloat j = 0.0f;
GLfloat x = 0.0f;
GLfloat y = 0.0f;
GLfloat m = 0.0f;

GLfloat l = 0.0f;
GLfloat b = 0.0f;
GLfloat k = 0.0f;

bool flag=true;
bool flagm=true;
bool flagd=true;
bool flage=true;
bool flagn=true;
bool flagnight=true;
bool flagevening=true;
bool flagmorning=true;
bool flagday=true;

GLfloat cloudposition = 0.0f;
GLfloat cloudspeed = 0.02f;

GLfloat rainposition = 0.0f;
GLfloat rainspeed = 0.01f;

GLfloat birdposition = 0.0f;
GLfloat birdspeed = 0.01f;

GLfloat birdposition1 = 0.0f;
GLfloat birdspeed1 = 0.05f;

GLfloat carposition = 0.0f;
GLfloat carspeed = 0.05f;

GLfloat truckposition = 0.0f;
GLfloat truckspeed = 0.05f;

GLfloat planeposition = 0.0f;
GLfloat planespeed = 0.05f;



GLfloat radius = 0.0f;

void initGL()
{
    glClearColor(0.0f, 0.5f, 0.5f, 0.0f); // Black and opaque
    //glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque

}

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}

void update(int value)
 {
     if (flagm)
     {
         flagnight=false;
         flagday=false;
         flagevening=false;
         flagmorning=true;
         flagm=false;
         l=0.4;
         k=0.8;
         b=1.2;
         glutTimerFunc(13000,update,0);
         glutPostRedisplay();
     }
    else if (flagd)
     {
         l=1.0;
         k=1.0;
         b=0.6;
         flagnight=false;
         flagmorning=false;
         flagday=true;
         flagevening=false;
         flagd=false;
         glutTimerFunc(10000,update,0);
         glutPostRedisplay();
     }
    else  if (flage)
     {
        l=0;
        k=.3;
        b=.3;
        flage=false;
        flagnight=false;
        flagmorning=false;
        flagday=false;
        flagevening=true;
        glutTimerFunc(10000,update,0);
        glutPostRedisplay();
     }
     else if (flagn)
     {
         l=0;
         k=0;
         b=0;

        flagn=false;
        flagnight=true;
        flagmorning=false;
        flagday=false;
        flagevening=false;
        glutTimerFunc(15000,update,0);
        glutPostRedisplay();
     }
     else
     {
    flagm=true;
    flagd=true;
    flage=true;
    flagn=true;
   glutTimerFunc(1000,update,0);
     }
 }

 void updatecloud(int value) {

    if(cloudposition > 1.5)
        cloudposition = -1.5f;

    cloudposition += cloudspeed;

	glutPostRedisplay();


	glutTimerFunc(100, updatecloud, 0);
}

 void updatecloud1(int value) {

    if(cloudposition < -1.5)
        cloudposition = 1.5f;

    cloudposition -= cloudspeed;

	glutPostRedisplay();


	glutTimerFunc(100, updatecloud1, 0);
}

void updaterain(int value) {


if(rainposition < -1.0)
        rainposition = 1.0f;

    rainposition -= rainspeed;


	glutPostRedisplay();


	glutTimerFunc(100, updaterain, 0);
}

void updatebird(int value) {


if(birdposition < -.9)
        birdposition = .9f;

    birdposition -= birdspeed;


	glutPostRedisplay();


	glutTimerFunc(100, updatebird, 0);
}

void updatebird1(int value) {


if(birdposition1 > 1.1)
        birdposition1 = -.9f;

    birdposition1 += birdspeed1;


	glutPostRedisplay();


	glutTimerFunc(100, updatebird1, 0);
}

void updatecar(int value) {


if(carposition < -1.5)
        carposition = .9f;

    carposition -= carspeed;


	glutPostRedisplay();


	glutTimerFunc(100, updatecar, 0);
}

void updatetruck(int value) {


if(truckposition > 1.5)
        truckposition = -1.5f;

    truckposition += truckspeed;


	glutPostRedisplay();


	glutTimerFunc(100, updatetruck, 0);
}

void updateplane(int value) {


if(planeposition < -1.5)
        planeposition = .9f;

    planeposition -= planespeed;


	glutPostRedisplay();


	glutTimerFunc(100, updateplane, 0);
}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 'p':
    planespeed = 0.0f;
    break;

case 'd':
    planespeed = 0.05f;
    break;

case 'c':
    carspeed = 0.0f;
    break;

case 'a':
    carspeed = 0.05f;
    break;

case 't':
    truckspeed = 0.0f;
    break;

case 'r':
    truckspeed = 0.05f;
    break;


glutPostRedisplay();


	}
}

void SpecialInput(int key, int x, int y)
{
switch(key)
{
case GLUT_KEY_UP:
//do something here

break;
case GLUT_KEY_DOWN:

break;
case GLUT_KEY_LEFT:

    glLoadIdentity();
glutTimerFunc(100, updatecloud1, 0);
break;

case GLUT_KEY_RIGHT:

   glLoadIdentity();
glutTimerFunc(100, updatecloud, 0);
break;
}
glutPostRedisplay();
}

void sound()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("aa.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

}

void MiddlePart()
{
        glColor3ub(204,0,0);
    GLfloat x=.27f; GLfloat y=-.09f; GLfloat radius =.5f;
	int triangleAmount = 200; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    glLineWidth(2.3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.07,.2);
    glVertex2f(.6,.2);
    glVertex2f(-.07,-.6);
    glVertex2f(.6,-.6);
    glVertex2f(-.1,.5);
    glVertex2f(.59,.5);
    glVertex2f(-.07,-.05);
    glVertex2f(.6,-.05);
    glVertex2f(-.07,-.32);
    glVertex2f(.6,-.32);
    glEnd();

    glLineWidth(1.0);

    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(-0.03,.8);
    glVertex2f(0.05,.2);

    glVertex2f(-0.01,.8);
    glVertex2f(0.07,.2);

    glVertex2f(0.01,.8);
    glVertex2f(0.09,.2);

    glVertex2f(0.03,.8);
    glVertex2f(0.11,.2);

    glVertex2f(0.05,.8);
    glVertex2f(0.13,.2);

    glVertex2f(0.07,.8);
    glVertex2f(0.15,.2);

    glVertex2f(0.09,.8);
    glVertex2f(0.17,.2);

    glVertex2f(0.11,.8);
    glVertex2f(0.19,.2);

    glVertex2f(0.13,.8);
    glVertex2f(0.21,.2);

    glVertex2f(0.15,.8);
    glVertex2f(0.23,.2);

    glVertex2f(0.17,.8);
    glVertex2f(0.25,.2);

    glVertex2f(0.19,.8);
    glVertex2f(0.25,.2);

    glVertex2f(0.21,.8);
    glVertex2f(0.27,.2);

    glVertex2f(0.23,.8);
    glVertex2f(0.29,.2);

    glVertex2f(0.25,.8);
    glVertex2f(0.31,.2);

    glVertex2f(0.27,.8);
    glVertex2f(0.33,.2);

    glVertex2f(0.29,.8);
    glVertex2f(0.35,.2);

    glVertex2f(0.31,.8);
    glVertex2f(0.37,.2);

    glVertex2f(0.33,.8);
    glVertex2f(0.39,.2);

    glVertex2f(0.35,.8);
    glVertex2f(0.41,.2);

    glVertex2f(0.37,.8);
    glVertex2f(0.43,.2);

    glVertex2f(0.39,.8);
    glVertex2f(0.45,.2);

    glVertex2f(0.41,.8);
    glVertex2f(0.47,.2);

    glVertex2f(0.43,.8);
    glVertex2f(0.49,.2);

    glVertex2f(0.45,.8);
    glVertex2f(0.51,.2);

    glVertex2f(0.47,.8);
    glVertex2f(0.53,.2);

    glVertex2f(0.49,.8);
    glVertex2f(0.55,.2);

    glVertex2f(0.51,.8);
    glVertex2f(0.57,.2);

    glVertex2f(0.02,.2);
    glVertex2f(0.02,-.6);

    glVertex2f(0.04,.2);
    glVertex2f(0.04,-.6);

    glVertex2f(0.06,.2);
    glVertex2f(0.06,-.6);

    glVertex2f(0.08,.2);
    glVertex2f(0.08,-.6);

    glVertex2f(0.1,.2);
    glVertex2f(0.1,-.6);

    glVertex2f(0.12,.2);
    glVertex2f(0.12,-.6);

    glVertex2f(0.14,.2);
    glVertex2f(0.14,-.6);

    glVertex2f(0.16,.2);
    glVertex2f(0.16,-.6);

    glVertex2f(0.18,.2);
    glVertex2f(0.18,-.6);

    glVertex2f(0.2,.2);
    glVertex2f(0.2,-.6);

    glVertex2f(0.22,.2);
    glVertex2f(0.22,-.6);

    glVertex2f(0.24,.2);
    glVertex2f(0.24,-.6);

    glVertex2f(0.26,.2);
    glVertex2f(0.26,-.6);

    glVertex2f(0.28,.2);
    glVertex2f(0.28,-.6);

    glVertex2f(0.3,.2);
    glVertex2f(0.3,-.6);

    glVertex2f(0.32,.2);
    glVertex2f(0.32,-.6);

    glVertex2f(0.34,.2);
    glVertex2f(0.34,-.6);

    glVertex2f(0.36,.2);
    glVertex2f(0.36,-.6);

    glVertex2f(0.38,.2);
    glVertex2f(0.38,-.6);

    glVertex2f(0.4,.2);
    glVertex2f(0.4,-.6);

    glVertex2f(0.42,.2);
    glVertex2f(0.42,-.6);

    glVertex2f(0.44,.2);
    glVertex2f(0.44,-.6);

    glVertex2f(0.46,.2);
    glVertex2f(0.46,-.6);

    glVertex2f(0.48,.2);
    glVertex2f(0.48,-.6);

    glVertex2f(0.5,.2);
    glVertex2f(0.5,-.6);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.12,.8);
    glVertex2f(-.05,.8);
    glVertex2f(0.03,.2);
    glVertex2f(-0.07,.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(.2,.8);
    glVertex2f(.25,.8);
    glVertex2f(0.31,.2);
    glVertex2f(0.22,.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(.53,.8);
    glVertex2f(.59,.8);
    glVertex2f(0.6,.2);
    glVertex2f(0.51,.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.12,0.8);
    glVertex2f(.59,0.8);
    glVertex2f(0.59,.9);
    glVertex2f(-0.12,.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(.51,0.2);
    glVertex2f(.6,0.2);
    glVertex2f(0.6,-.6);
    glVertex2f(0.51,-.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(.22,.2);
    glVertex2f(.31,.2);
    glVertex2f(0.31,-.6);
    glVertex2f(0.22,-.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.07,.2);
    glVertex2f(.03,.2);
    glVertex2f(0.03,-.6);
    glVertex2f(-0.07,-.6);
    glEnd();

}

void LeftPart()
{


    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.0,-.2);
    glVertex2f(0.31,-.2);

    glVertex2f(0.0,-.4);
    glVertex2f(0.31,-.4);

    glVertex2f(0.0,-.6);
    glVertex2f(0.31,-.6);

    glVertex2f(0.0,-.8);
    glVertex2f(0.31,-.8);
    glEnd();



    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.0,0.0);
    glVertex2f(0.0,-0.8);

    glVertex2f(0.02,0.0);
    glVertex2f(0.02,-0.8);

    glVertex2f(0.04,0.0);
    glVertex2f(0.04,-0.8);

    glVertex2f(0.06,0.0);
    glVertex2f(0.06,-0.8);

    glVertex2f(0.08,0.0);
    glVertex2f(0.08,-0.8);

    glVertex2f(0.1,0.0);
    glVertex2f(0.1,-0.8);

    glVertex2f(0.12,0.0);
    glVertex2f(0.12,-0.8);

    glVertex2f(0.14,0.0);
    glVertex2f(0.14,-0.8);

    glVertex2f(0.16,0.0);
    glVertex2f(0.16,-0.8);

    glVertex2f(0.18,0.0);
    glVertex2f(0.18,-0.8);

    glVertex2f(0.2,0.0);
    glVertex2f(0.2,-0.8);

    glVertex2f(0.22,0.0);
    glVertex2f(0.22,-0.8);

    glVertex2f(0.24,0.0);
    glVertex2f(0.24,-0.8);

    glEnd();






    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.0,0.0);
    glVertex2f(0.06,0.035);
    glVertex2f(0.06,-0.8);
    glVertex2f(0.0,-0.8);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.06,0.03);
    glVertex2f(0.25,0.055);
    glVertex2f(0.25,-0.02);
    glVertex2f(0.06,-0.05);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.25,0.06);
    glVertex2f(0.31,0.06);
    glVertex2f(0.31,-0.8);
    glVertex2f(0.25,-0.8);

    glEnd();
}

void RightPart()
{
    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.0,-.2);
    glVertex2f(0.31,-.2);

    glVertex2f(0.0,-.4);
    glVertex2f(0.31,-.4);

    glVertex2f(0.0,-.6);
    glVertex2f(0.31,-.6);

    glVertex2f(0.0,-.8);
    glVertex2f(0.31,-.8);
    glEnd();



    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.0,0.0);
    glVertex2f(0.0,-0.8);

    glVertex2f(0.02,0.0);
    glVertex2f(0.02,-0.8);

    glVertex2f(0.04,0.0);
    glVertex2f(0.04,-0.8);

    glVertex2f(0.06,0.0);
    glVertex2f(0.06,-0.8);

    glVertex2f(0.08,0.0);
    glVertex2f(0.08,-0.8);

    glVertex2f(0.1,0.0);
    glVertex2f(0.1,-0.8);

    glVertex2f(0.12,0.0);
    glVertex2f(0.12,-0.8);

    glVertex2f(0.14,0.0);
    glVertex2f(0.14,-0.8);

    glVertex2f(0.16,0.0);
    glVertex2f(0.16,-0.8);

    glVertex2f(0.18,0.0);
    glVertex2f(0.18,-0.8);

    glVertex2f(0.2,0.0);
    glVertex2f(0.2,-0.8);

    glVertex2f(0.22,0.0);
    glVertex2f(0.22,-0.8);

    glVertex2f(0.24,0.0);
    glVertex2f(0.24,-0.8);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.0,0.06);
    glVertex2f(0.06,0.055);
    glVertex2f(0.06,-0.8);
    glVertex2f(0.0,-0.8);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.06,0.06);
    glVertex2f(0.25,0.035);
    glVertex2f(0.25,-0.05);
    glVertex2f(0.06,-0.03);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.25,0.035);
    glVertex2f(0.31,0.03);
    glVertex2f(0.31,-0.8);
    glVertex2f(0.25,-0.8);

    glEnd();

}

void mountain1()
{
    glBegin(GL_POLYGON);
    glColor3ub(0,80,0);

    glVertex2f(-0.2,0.0);
    glVertex2f(0.0,0.4);
    glVertex2f(0.4,0.0);
    glVertex2f(0.45,0.7);
    glVertex2f(0.8,0.0);

	glEnd();
}

void Base()
{
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.9,0.0);
    glVertex2f(0.9,0.0);
    glVertex2f(0.9,0.09);
    glVertex2f(-0.9,0.09);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.9,0.0);
    glVertex2f(.9,0.0);

    glVertex2f(-.9,0.015);
    glVertex2f(.9,0.015);

    glVertex2f(-.9,0.03);
    glVertex2f(.9,0.03);

    glVertex2f(-.9,0.045);
    glVertex2f(.9,0.045);

    glVertex2f(-.9,0.06);
    glVertex2f(.9,0.06);

    glVertex2f(-.9,0.075);
    glVertex2f(.9,0.075);

    glVertex2f(-.9,0.09);
    glVertex2f(.9,0.09);

    glVertex2f(-.9,0.0);
    glVertex2f(-.9,0.09);

    glVertex2f(.9,0.0);
    glVertex2f(.9,0.09);

    glEnd();

    glLineWidth(1);

}

void mountain2()
{

    glBegin(GL_POLYGON);
    glColor3ub(0,70,0);

    glVertex2f(-0.2,0.0);
    glVertex2f(0.0,0.4);
    glVertex2f(0.4,0.0);
    glVertex2f(0.45,0.7);
    glVertex2f(0.8,0.0);
    glVertex2f(0.85,0.5);
    glVertex2f(1.0,0.0);

	glEnd();
}

void sun()
{


    glColor3ub(255,140,0);
	glBegin(GL_TRIANGLE_FAN);
			 GLfloat x=0.6f; GLfloat y=0.75f;  GLfloat radius =.09f;
	GLfloat triangleAmount = 150; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius

	GLfloat twicePi = 2.0f * PI;


				glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}


	glEnd();

	///surjer dandi

	glLineWidth(4);
    glBegin(GL_LINES);
	glVertex2f(.609,.85);
	glVertex2f(.609,.96);
	glVertex2f(.67,.82);
	glVertex2f(.77,.92);
	glVertex2f(.7,.75);
	glVertex2f(.82,.75);
    glVertex2f(.67,.68);
	glVertex2f(.76,.6);
	glVertex2f(.609,.65);
	glVertex2f(.609,.54);
	glVertex2f(.52,.68);
	glVertex2f(.42,.59);
	glVertex2f(.5,.75);
	glVertex2f(.39,.75);
	glVertex2f(.53,.82);
	glVertex2f(.42,.9);

    glEnd();
    //glPopMatrix();
}

void plane()
{
    glBegin(GL_POLYGON);
    glColor3ub(119,156,153);
    //glColor3ub(84,74,74);
    //glColor3ub(176,196,222);
    //glColor3ub(105,105,105);

    glVertex2f(0.75f, -0.1f);
    glVertex2f(0.7f, 0.12f);
    glVertex2f(0.6f, 0.1f);
    glVertex2f(0.5f, -0.1f);
    glVertex2f(-0.55f, -0.1f);
    glVertex2f(-0.6f, -0.2f);
    glVertex2f(-0.7f, -0.25f);
    glVertex2f(-0.8f, -0.3f);
    glVertex2f(-0.85f, -0.35f);
    glVertex2f(-0.8f, -0.4f);
    glVertex2f(-0.75f, -0.45f);
    glVertex2f(-0.6f, -0.5f);
    glVertex2f(0.2f, -0.5f);
    glVertex2f(0.7f, -0.3f);

    glEnd();


    ///design line

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.85,-.35);
    glVertex2f(-.45,-.35);
    glVertex2f(-.45,-.35);
    glVertex2f(-.45,-.1);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.45,-.3);
    glVertex2f(.45,-.3);
    glVertex2f(.45,-.3);
    glVertex2f(.5,-.1);

    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(150,0,0);
    glVertex2f(-.42,-.32);
    glVertex2f(.45,-.32);

    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(150,0,0);
    glVertex2f(-.42,-.34);
    glVertex2f(.45,-.34);

    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(150,0,0);
    glVertex2f(-.42,-.36);
    glVertex2f(.45,-.36);

    glEnd();

    ///Windows

    glBegin(GL_POLYGON);

    glColor3ub(255,255,80);
    glVertex2f(-.6,-.23);
    glVertex2f(-.67,-.3);
    glVertex2f(-.5,-.3);
    glVertex2f(-.5,-.23);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(255,255,80);
    glVertex2f(-.4,-.21);
    glVertex2f(-.4,-.25);
    glVertex2f(-.33,-.25);
    glVertex2f(-.33,-.21);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(255,255,80);
    glVertex2f(-.3,-.21);
    glVertex2f(-.3,-.25);
    glVertex2f(-.23,-.25);
    glVertex2f(-.23,-.21);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(255,255,80);
    glVertex2f(-.2,-.21);
    glVertex2f(-.2,-.25);
    glVertex2f(-.13,-.25);
    glVertex2f(-.13,-.21);
    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(255,255,80);
    glVertex2f(-.1,-.21);
    glVertex2f(-.1,-.25);
    glVertex2f(-.03,-.25);
    glVertex2f(-.03,-.21);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(255,255,80);
    glVertex2f(0,-.21);
    glVertex2f(0,-.25);
    glVertex2f(.07,-.25);
    glVertex2f(.07,-.21);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(255,255,80);
    glVertex2f(.1,-.21);
    glVertex2f(.1,-.25);
    glVertex2f(.17,-.25);
    glVertex2f(.17,-.21);
    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(255,255,80);
    glVertex2f(.2,-.21);
    glVertex2f(.2,-.25);
    glVertex2f(.27,-.25);
    glVertex2f(.27,-.21);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(255,255,80);
    glVertex2f(.3,-.21);
    glVertex2f(.3,-.25);
    glVertex2f(.37,-.25);
    glVertex2f(.37,-.21);
    glEnd();


    ///plane wheel
    glColor3f(1.0f, 1.0f, 1.0f);
     GLfloat x=.1f; GLfloat y=-.545f; GLfloat radius =.045f;
	 GLfloat triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
			 x=0.012f;  y=-.545f;  radius =.045f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

				glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
			 x=-0.7f;  y=-.512f;  radius =.045f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

				glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void Stairs()
{

    glBegin(GL_QUADS);
    glColor3ub(128,66,0);
    glVertex2f(-.9,-0.15);
    glVertex2f(.9,-0.15);
    glVertex2f(1.0,-.45);
    glVertex2f(-1.0,-.45);

    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(128,66,0);
    glVertex2f(1.0,-.45);
    glVertex2f(-1.0,-.45);
    glVertex2f(-1.0,-.5);
    glVertex2f(1.0,-.5);

    glEnd();

    glLineWidth(1.1);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.9,-.15);
    glVertex2f(.9,-.15);
    glVertex2f(1.0,-.45);
    glVertex2f(-1.0,-.45);
    glVertex2f(-0.9,-.15);
    glVertex2f(-1.0,-.45);
    glVertex2f(0.9,-.15);
    glVertex2f(1.0,-.45);
    glVertex2f(1.0,-.45);
    glVertex2f(1.0,-.5);
    glVertex2f(1.0,-.5);
    glVertex2f(-1.0,-.5);
    glVertex2f(1.0,-.49);
    glVertex2f(-1.0,-.49);
    glVertex2f(1.0,-.48);
    glVertex2f(-1.0,-.48);
    glVertex2f(1.0,-.47);
    glVertex2f(-1.0,-.47);
    glVertex2f(1.0,-.46);
    glVertex2f(-1.0,-.46);


    glEnd();
}

void Road()
{
     glBegin(GL_QUADS);
    glColor3ub(32,32,32);

    glVertex2f(1.0,-0.15);
    glVertex2f(-1.0,-0.15);
    glVertex2f(-1.0,-1.0);
    glVertex2f(1.0,-1.0);

    glEnd();

        ///Road er Line


    //glLineWidth(9);
    glBegin(GL_LINES);

    glColor3ub(255,255,255);
    glVertex2f(-1.0,-.75);
    glVertex2f(-0.9,-.75);
    glVertex2f(-0.8,-.75);
    glVertex2f(-0.7,-.75);
    glVertex2f(-0.6,-.75);
    glVertex2f(-0.5,-.75);
    glVertex2f(-0.4,-.75);
    glVertex2f(-0.3,-.75);
    glVertex2f(-0.2,-.75);
    glVertex2f(-0.1,-.75);
    glVertex2f(0.0,-.75);
    glVertex2f(0.1,-.75);
    glVertex2f(0.2,-.75);
    glVertex2f(0.3,-.75);
    glVertex2f(0.4,-.75);
    glVertex2f(0.5,-.75);
    glVertex2f(0.6,-.75);
    glVertex2f(0.7,-.75);
    glVertex2f(0.8,-.75);
    glVertex2f(0.9,-.75);

    glEnd();


}

void LampPost()
{
    glBegin(GL_QUADS);
    glColor3ub(163,163,163);
    glVertex2f(-0.8,-1.0);
    glVertex2f(-0.77,-1.0);
    glVertex2f(-0.77,-0.7);
    glVertex2f(-0.8,-0.7);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(163,163,163);
    glVertex2f(-0.8,-.7);
    glVertex2f(-0.9,-.7);
    glVertex2f(-0.9,-0.72);
    glVertex2f(-0.8,-0.72);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(163,163,163);
    glVertex2f(-0.77,-.7);
    glVertex2f(-0.67,-.7);
    glVertex2f(-0.67,-0.72);
    glVertex2f(-0.77,-0.72);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(163,163,163);
    glVertex2f(-0.67,-.72);
    glVertex2f(-0.69,-.72);
    glVertex2f(-0.69,-0.67);
    glVertex2f(-0.67,-0.67);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(163,163,163);
    glVertex2f(-0.9,-.72);
    glVertex2f(-0.88,-.72);
    glVertex2f(-0.88,-0.67);
    glVertex2f(-0.9,-0.67);

    glEnd();
}

void Car()
{
     //body
    glBegin(GL_QUADS);
	glColor3ub(155,0,0);
	glVertex2f(.9,-.68);
	glVertex2f(.5,-.68);
	glVertex2f(.5,-.58);
	glVertex2f(.9,-.58);

    glEnd();

    //glLoadIdentity();
    glBegin(GL_QUADS);
	glColor3ub(155,0,0);
	glVertex2f(.55,-.58);
	glVertex2f(.87,-.58);
	glVertex2f(.84,-.48);
	glVertex2f(.6,-.48);

    glEnd();

    //window

    //glLoadIdentity();
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2f(.57,-.56);
	glVertex2f(.67,-.56);
	glVertex2f(.67,-.5);
	glVertex2f(.61,-.5);

    glEnd();

    //glLoadIdentity();
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2f(.7,-.56);
	glVertex2f(.85,-.56);
	glVertex2f(.83,-.5);
	glVertex2f(.7,-.5);

    glEnd();

   /* glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(+0.6,-0.68,+0.0);
    glutSolidSphere(0.045 , 50 , 50) ;

    glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(+0.8,-0.68,+0.0);
    glutSolidSphere(0.045 , 50 , 50) ;
*/

    glColor3f(0.0f, 0.0f, 0.0f);
     GLfloat x=.6f; GLfloat y=-.69f; GLfloat radius =.042f;
	 GLfloat triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
			 x=.8f;  y=-.69f;  radius =.045f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

				glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}


void Tree()
{
    glBegin(GL_POLYGON);
    glColor3ub(51,25, 0);
	glVertex2f(-0.865f,-0.3f);
	glVertex2f(-0.865f,0.0f);
	glVertex2f(-0.84f,0.0f);
	glVertex2f(-0.84f,-0.3f); //root
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(0, 120, 0);
	glVertex2f(-0.865f,0.0f);
	glVertex2f(-0.91f,0.0f);
	glVertex2f(-0.875f,0.05f);
	glVertex2f(-0.9f,0.05f);
	glVertex2f(-0.862f,0.1f);
	glVertex2f(-0.88f,0.1f);
	glVertex2f(-0.8525f,0.15f);
	glVertex2f(-0.825f,0.1f);
	glVertex2f(-0.838f,0.1f);
	glVertex2f(-0.805f,0.05f);
	glVertex2f(-0.83f,0.05f);
	glVertex2f(-0.795f,0.0f); //left mid
	glVertex2f(-0.865f,0.0f);
	glEnd();
}
void Bird()
{
    glBegin(GL_TRIANGLES);
    glColor3ub(204,0,0);
    glVertex2f(0.0,0.0);
    glVertex2f(0.1,0.0);
    glVertex2f(0.05,0.15);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255,0,0);
    glVertex2f(0.0,0.0);
    glVertex2f(0.1,0.0);
    glVertex2f(0.2,0.15);
    glEnd();

}

void cloud()
{
    ///cloud1




	 //   glColor3f(1.0f, 1.0f, 1.0f);
	 glColor3ub(222,222,222);
    GLfloat a=.1f; GLfloat b=.545f; GLfloat radius11 =.25f;
    GLfloat	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(a, b); // center of circle
		for(int d = 0; d <= triangleAmount;d++) {
			glVertex2f(
		            a + (radius11 * cos(d *  twicePi / triangleAmount)),
			    b + (radius11 * sin(d * twicePi / triangleAmount))
			);
		}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
			 a=0.35f;  b=.49f;  radius11 =.2f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

				glVertex2f(a, b); // center of circle
		for(int d = 0; d <= triangleAmount;d++) {
			glVertex2f(
		            a + (radius11 * cos(d *  twicePi / triangleAmount)),
			    b + (radius11 * sin(d * twicePi / triangleAmount))
			);
		}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
			 a=-0.15f;  b=.49f;  radius11 =.2f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

				glVertex2f(a, b); // center of circle
		for(int d = 0; d <= triangleAmount;d++) {
			glVertex2f(
		            a + (radius11 * cos(d *  twicePi / triangleAmount)),
			    b + (radius11 * sin(d * twicePi / triangleAmount))
			);
		}
	glEnd();

	//glPopMatrix();


}

void cloud1()
{
    //glColor3f(1.0f, 1.0f, 1.0f);
     glColor3ub(222,222,222);
     GLfloat a=.1f; GLfloat b=.545f; GLfloat radius11 =.25f;
	 GLfloat triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(a, b); // center of circle
		for(int d = 0; d <= triangleAmount;d++) {
			glVertex2f(
		            a + (radius11 * cos(d *  twicePi / triangleAmount)),
			    b + (radius11 * sin(d * twicePi / triangleAmount))
			);
		}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
			 a=0.35f;  b=.49f;  radius11 =.2f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

				glVertex2f(a, b); // center of circle
		for(int d = 0; d <= triangleAmount;d++) {
			glVertex2f(
		            a + (radius11 * cos(d *  twicePi / triangleAmount)),
			    b + (radius11 * sin(d * twicePi / triangleAmount))
			);
		}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
			 a=-0.15f;  b=.49f;  radius11 =.2f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

				glVertex2f(a, b); // center of circle
		for(int d = 0; d <= triangleAmount;d++) {
			glVertex2f(
		            a + (radius11 * cos(d *  twicePi / triangleAmount)),
			    b + (radius11 * sin(d * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void display()
{
    glClearColor(l,k,b,0);
    glClear(GL_COLOR_BUFFER_BIT);

    ///______________________MORNING____________________________///

    if(flagmorning)
    {
        ///SUN
	glLoadIdentity();

	//glPushMatrix();
//glTranslatef(0.0f,position2, 0.0f);

    glTranslatef(+0.25, +0.2, +0.0);
    glScalef(.7,.8,0);

    //glPopMatrix();
    sun();

    ///HOUSE

    glLoadIdentity();
    glTranslatef(-1.27f, +0.0f, +0.0f);
    //glScalef(.5,.5,0);

    glBegin(GL_QUADS);

    glColor3ub(123,123,123);
    glVertex2f(.3,-.3);
    glVertex2f(.3,.7);
    glVertex2f(.6,.7);
    glVertex2f(.6,-.3);

    glColor3ub(0,0,0);
    glVertex2f(.58,.7);
    glVertex2f(.58,.77);
    glVertex2f(.51,.77);
    glVertex2f(.51,.7);

     glColor3ub(255,255,0);
    glVertex2f(.34,0.65);
    glVertex2f(.43,0.65);
    glVertex2f(.43,0.6);
    glVertex2f(.34,0.6);

    glColor3ub(0,0,0);
    glVertex2f(.34,0.55);
    glVertex2f(.43,0.55);
    glVertex2f(.43,0.5);
    glVertex2f(.34,0.5);

    glColor3ub(255,255,0);
    glVertex2f(.34,0.45);
    glVertex2f(.43,0.45);
    glVertex2f(.43,0.4);
    glVertex2f(.34,0.4);

    glColor3ub(255,255,0);
    glVertex2f(.34,0.35);
    glVertex2f(.43,0.35);
    glVertex2f(.43,0.3);
    glVertex2f(.34,0.3);

    glColor3ub(255,255,0);
    glVertex2f(.34,0.25);
    glVertex2f(.43,0.25);
    glVertex2f(.43,0.2);
    glVertex2f(.34,0.2);

    glColor3ub(0,0,0);
    glVertex2f(.34,0.15);
    glVertex2f(.43,0.15);
    glVertex2f(.43,0.1);
    glVertex2f(.34,0.1);

    glColor3ub(255,255,0);
    glVertex2f(.34,0.05);
    glVertex2f(.43,0.05);
    glVertex2f(.43,0.0);
    glVertex2f(.34,0.0);

    glColor3ub(255,255,0);
    glVertex2f(.34,-0.05);
    glVertex2f(.43,-0.05);
    glVertex2f(.43,-0.1);
    glVertex2f(.34,-0.1);

    glColor3ub(255,255,0);
    glVertex2f(.34,-0.15);
    glVertex2f(.43,-0.15);
    glVertex2f(.43,-0.2);
    glVertex2f(.34,-0.2);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.65);
    glVertex2f(.56,0.65);
    glVertex2f(.56,0.6);
    glVertex2f(.47,0.6);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.55);
    glVertex2f(.56,0.55);
    glVertex2f(.56,0.5);
    glVertex2f(.47,0.5);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.45);
    glVertex2f(.56,0.45);
    glVertex2f(.56,0.4);
    glVertex2f(.47,0.4);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.35);
    glVertex2f(.56,0.35);
    glVertex2f(.56,0.3);
    glVertex2f(.47,0.3);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.25);
    glVertex2f(.56,0.25);
    glVertex2f(.56,0.2);
    glVertex2f(.47,0.2);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.15);
    glVertex2f(.56,0.15);
    glVertex2f(.56,0.1);
    glVertex2f(.47,0.1);

    //glColor3ub(255,255,0);
    glColor3ub(0,0,0);
    glVertex2f(.47,0.05);
    glVertex2f(.56,0.05);
    glVertex2f(.56,0.0);
    glVertex2f(.47,0.0);

    glColor3ub(255,255,0);
    glVertex2f(.47,-0.05);
    glVertex2f(.56,-0.05);
    glVertex2f(.56,-0.1);
    glVertex2f(.47,-0.1);

    glColor3ub(255,255,0);
    glVertex2f(.47,-0.15);
    glVertex2f(.56,-0.15);
    glVertex2f(.56,-0.2);
    glVertex2f(.47,-0.2);

    glEnd();


    ///cloud1
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(cloudposition,0.0f, 0.0f);


    glTranslatef(+0.1, +0.6, +0.0);
    glScalef(.3,.3,0);
    cloud();
    glPopMatrix();

    ///cloud2

    glLoadIdentity();
    glPushMatrix();
    glTranslatef(cloudposition,0.0f, 0.0f);


//glTranslatef(position2,0.0, 0.0);

    glTranslatef(-0.8, +0.65, +0.0);
    glScalef(.3,.3,0);

    cloud1();
    glPopMatrix();

        ///MounTain
    glLoadIdentity();
    glTranslatef(-0.82, -0.15 ,+0.0);
    glScalef(1.0,1.3,0);

    glEnable(GL_LIGHTING);//Enable Light Effect

  GLfloat global_ambient[] = {0.0,1.7,0.0, 0.1};//ambient RGBA intensity of light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//A lighting model parameter.

    mountain1();

    glDisable(GL_LIGHTING);//Enable Light Effect




	///Mountain2

    glLoadIdentity();
    glTranslatef(+0.05, -0.15, +0.0);
    glScalef(.99,.99,0);


    mountain2();



    ///Road

    glLoadIdentity();
    Road();


    ///Stairs
    glLoadIdentity();
    Stairs();

    ///Birdie
    glLoadIdentity();


    glPushMatrix();
    glTranslatef(birdposition,0.0f, 0.0f);
    glTranslatef(-0.5,+0.7,+0.0);
    glScalef(.5,0.8,0.0);
    Bird();

    glPopMatrix();

    glLoadIdentity();

    glPushMatrix();
    glTranslatef(birdposition,0.0f, 0.0f);
    glTranslatef(-0.58,+0.75,+0.0);
    glScalef(.4,0.7,0.0);
    Bird();

    glPopMatrix();

    glLoadIdentity();

    glPushMatrix();
    glTranslatef(birdposition,0.0f, 0.0f);
    glTranslatef(-0.39,+0.75,+0.0);
    glScalef(.4,0.7,0.0);
    Bird();
    glPopMatrix();


///middlepart

    glLoadIdentity();
    glTranslatef(-0.15,+0.15,+0.0);
    glScalef(.55,.65,0.0);

    //glLoadIdentity();
    MiddlePart();

///Left part1

    glLoadIdentity();
    glTranslatef(-0.6,+0.4,+0.0);
    glScalef(.9,.8,0.0);

    //glLoadIdentity();
    LeftPart();

    ///Left part1

    glLoadIdentity();
    glTranslatef(-0.88,+0.24,+0.0);
    glScalef(.7,.6,0.0);

    LeftPart();

    ///Right Part

    glLoadIdentity();
    glTranslatef(+0.3,+0.4,+0.0);
    glScalef(.9,.81,0.0);

    RightPart();

    ///Right Part1

    glLoadIdentity();
    glTranslatef(+0.65,+0.24,+0.0);
    glScalef(.7,.6,0.0);

    RightPart();



    ///Base

    glLoadIdentity();
    glTranslatef(+0.0,-0.335,+0.0);
    glScalef(1.05,1.0,0.0);
    Base();




    ///LampPost

    glLoadIdentity();
    LampPost();



    glLoadIdentity();
    glTranslatef(+0.8,+0.0,+0.0);
    LampPost();



    glLoadIdentity();
    glTranslatef(+1.6,+0.0,+0.0);
    LampPost();

    ///lamp er Light

    glLoadIdentity();
    glColor3ub(255,255,255);
    glTranslatef(+0.71,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    glLoadIdentity();

    glTranslatef(+0.92,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;


    glLoadIdentity();

    glTranslatef(+0.12,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    glLoadIdentity();

    glTranslatef(-.09,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    glLoadIdentity();
    glTranslatef(-.68,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    glLoadIdentity();
    glTranslatef(-.89,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    ///Tree

    glLoadIdentity();
    glTranslatef(-0.1,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+0.25,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+0.45,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+0.65,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+1.015,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+1.21,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+1.41,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    ///manush1
    glLoadIdentity();
    glTranslatef(+0.0,-0.15,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(0,0,180);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.05);
    glVertex2f(-.3,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.05);
    glVertex2f(-.45,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush2
    glLoadIdentity();
    glTranslatef(+0.15,-0.15,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(0,180,0);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush3
    glLoadIdentity();
    glTranslatef(+0.3,-0.15,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(180,99,55);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush4
    glLoadIdentity();
    glTranslatef(+0.45,-0.15,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(180,0,180);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.05);
    glVertex2f(-.3,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.05);
    glVertex2f(-.45,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush5
    glLoadIdentity();
    glTranslatef(+0.6,-0.15,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(0,180,180);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush6
    glLoadIdentity();
    glTranslatef(+0.75,-0.17,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(0,255,180);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush7
    glLoadIdentity();
    glTranslatef(+0.9,-0.17,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(80,0,120);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush8
    glLoadIdentity();
    glTranslatef(+1.05,-0.15,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(80,80,220);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.05);
    glVertex2f(-.3,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.05);
    glVertex2f(-.45,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush9
     glLoadIdentity();
    glTranslatef(+1.15,-0.15,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(200,80,80);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush10
     glLoadIdentity();
    glTranslatef(+1.3,-0.17,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(80,130,120);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush11
     glLoadIdentity();
    glTranslatef(-0.2,-0.17,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(80,0,120);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush12
     glLoadIdentity();
    glTranslatef(-.35,-0.15,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(80,80,0);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush13
     glLoadIdentity();
    glTranslatef(-.5,-0.17,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(80,255,120);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;


    ///manush14
     glLoadIdentity();
    glTranslatef(+1.0,-0.3,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(200,180,80);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush15
     glLoadIdentity();
    glTranslatef(+.8,-0.3,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(0,130,120);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush16
     glLoadIdentity();
    glTranslatef(-0.1,-0.3,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(180,0,220);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush17
     glLoadIdentity();
    glTranslatef(-.25,-0.3,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(80,80,80);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush18
     glLoadIdentity();
    glTranslatef(-.35,-0.3,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(80,45,120);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush19
    glLoadIdentity();
    glTranslatef(+0.12,-0.3,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(180,220,220);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.05);
    glVertex2f(-.3,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.05);
    glVertex2f(-.45,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush20
    glLoadIdentity();
    glTranslatef(+0.27,-0.3,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(80,80,40);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.05);
    glVertex2f(-.3,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.05);
    glVertex2f(-.45,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush21
    glLoadIdentity();
    glTranslatef(+0.42,-0.3,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(0,0,220);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.05);
    glVertex2f(-.3,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.05);
    glVertex2f(-.45,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush22
    glLoadIdentity();
    glTranslatef(+0.57,-0.3,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(80,255,255);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.05);
    glVertex2f(-.3,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.05);
    glVertex2f(-.45,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;


    }

    ///______________________DAY_________________________________///

    else if(flagday)
    {
        ///SUN
	glLoadIdentity();

	//glPushMatrix();
//glTranslatef(0.0f,position2, 0.0f);

    glTranslatef(+0.25, +0.05, +0.0);
    glScalef(.7,.8,0);

    //glPopMatrix();
    sun();

    ///HOUSE

    glLoadIdentity();
    glTranslatef(-1.27f, +0.0f, +0.0f);
    //glScalef(.5,.5,0);

    glBegin(GL_QUADS);

    glColor3ub(123,123,123);
    glVertex2f(.3,-.3);
    glVertex2f(.3,.7);
    glVertex2f(.6,.7);
    glVertex2f(.6,-.3);

    glColor3ub(0,0,0);
    glVertex2f(.58,.7);
    glVertex2f(.58,.77);
    glVertex2f(.51,.77);
    glVertex2f(.51,.7);

     glColor3ub(255,255,0);
    glVertex2f(.34,0.65);
    glVertex2f(.43,0.65);
    glVertex2f(.43,0.6);
    glVertex2f(.34,0.6);

    glColor3ub(0,0,0);
    glVertex2f(.34,0.55);
    glVertex2f(.43,0.55);
    glVertex2f(.43,0.5);
    glVertex2f(.34,0.5);

    glColor3ub(255,255,0);
    glVertex2f(.34,0.45);
    glVertex2f(.43,0.45);
    glVertex2f(.43,0.4);
    glVertex2f(.34,0.4);

    glColor3ub(255,255,0);
    glVertex2f(.34,0.35);
    glVertex2f(.43,0.35);
    glVertex2f(.43,0.3);
    glVertex2f(.34,0.3);

    glColor3ub(255,255,0);
    glVertex2f(.34,0.25);
    glVertex2f(.43,0.25);
    glVertex2f(.43,0.2);
    glVertex2f(.34,0.2);

    glColor3ub(0,0,0);
    glVertex2f(.34,0.15);
    glVertex2f(.43,0.15);
    glVertex2f(.43,0.1);
    glVertex2f(.34,0.1);

    glColor3ub(255,255,0);
    glVertex2f(.34,0.05);
    glVertex2f(.43,0.05);
    glVertex2f(.43,0.0);
    glVertex2f(.34,0.0);

    glColor3ub(255,255,0);
    glVertex2f(.34,-0.05);
    glVertex2f(.43,-0.05);
    glVertex2f(.43,-0.1);
    glVertex2f(.34,-0.1);

    glColor3ub(255,255,0);
    glVertex2f(.34,-0.15);
    glVertex2f(.43,-0.15);
    glVertex2f(.43,-0.2);
    glVertex2f(.34,-0.2);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.65);
    glVertex2f(.56,0.65);
    glVertex2f(.56,0.6);
    glVertex2f(.47,0.6);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.55);
    glVertex2f(.56,0.55);
    glVertex2f(.56,0.5);
    glVertex2f(.47,0.5);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.45);
    glVertex2f(.56,0.45);
    glVertex2f(.56,0.4);
    glVertex2f(.47,0.4);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.35);
    glVertex2f(.56,0.35);
    glVertex2f(.56,0.3);
    glVertex2f(.47,0.3);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.25);
    glVertex2f(.56,0.25);
    glVertex2f(.56,0.2);
    glVertex2f(.47,0.2);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.15);
    glVertex2f(.56,0.15);
    glVertex2f(.56,0.1);
    glVertex2f(.47,0.1);

    //glColor3ub(255,255,0);
    glColor3ub(0,0,0);
    glVertex2f(.47,0.05);
    glVertex2f(.56,0.05);
    glVertex2f(.56,0.0);
    glVertex2f(.47,0.0);

    glColor3ub(255,255,0);
    glVertex2f(.47,-0.05);
    glVertex2f(.56,-0.05);
    glVertex2f(.56,-0.1);
    glVertex2f(.47,-0.1);

    glColor3ub(255,255,0);
    glVertex2f(.47,-0.15);
    glVertex2f(.56,-0.15);
    glVertex2f(.56,-0.2);
    glVertex2f(.47,-0.2);

    glEnd();

    ///cloud1
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(cloudposition,0.0f, 0.0f);


    glTranslatef(+0.1, +0.6, +0.0);
    glScalef(.3,.3,0);
    cloud();
    glPopMatrix();

    ///cloud2

    glLoadIdentity();
    glPushMatrix();
    glTranslatef(cloudposition,0.0f, 0.0f);


//glTranslatef(position2,0.0, 0.0);

    glTranslatef(-0.8, +0.65, +0.0);
    glScalef(.3,.3,0);

    cloud1();
    glPopMatrix();




        ///MounTain
    glLoadIdentity();
    glTranslatef(-0.82, -0.15 ,+0.0);
    glScalef(1.0,1.3,0);

    glEnable(GL_LIGHTING);//Enable Light Effect

  GLfloat global_ambient[] = {0.0,1.7,0.0, 0.1};//ambient RGBA intensity of light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//A lighting model parameter.

    mountain1();

    glDisable(GL_LIGHTING);//Enable Light Effect




	///Mountain2

    glLoadIdentity();
    glTranslatef(+0.05, -0.15, +0.0);
    glScalef(.99,.99,0);


    mountain2();



    ///Road

    glLoadIdentity();
    Road();


    ///Stairs
    glLoadIdentity();
    Stairs();

    ///Birdie
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(birdposition,0.0f, 0.0f);

    glTranslatef(-0.5,+0.7,+0.0);
    glScalef(.5,0.8,0.0);
    Bird();
    glPopMatrix();


///middlepart

    glLoadIdentity();
    glTranslatef(-0.15,+0.15,+0.0);
    glScalef(.55,.65,0.0);

    //glLoadIdentity();
    MiddlePart();

///Left part1

    glLoadIdentity();
    glTranslatef(-0.6,+0.4,+0.0);
    glScalef(.9,.8,0.0);

    //glLoadIdentity();
    LeftPart();

    ///Left part1

    glLoadIdentity();
    glTranslatef(-0.88,+0.24,+0.0);
    glScalef(.7,.6,0.0);

    LeftPart();

    ///Right Part

    glLoadIdentity();
    glTranslatef(+0.3,+0.4,+0.0);
    glScalef(.9,.81,0.0);

    RightPart();

    ///Right Part1

    glLoadIdentity();
    glTranslatef(+0.65,+0.24,+0.0);
    glScalef(.7,.6,0.0);

    RightPart();



    ///Base

    glLoadIdentity();
    glTranslatef(+0.0,-0.335,+0.0);
    glScalef(1.05,1.0,0.0);
    Base();


    ///______manush


    ///manush1
    glLoadIdentity();
    glTranslatef(+0.0,-0.15,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(0,0,180);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.05);
    glVertex2f(-.3,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.05);
    glVertex2f(-.45,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush2
    glLoadIdentity();
    glTranslatef(+0.15,-0.15,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(0,180,0);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;



    ///manush3
    glLoadIdentity();
    glTranslatef(+0.45,-0.15,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(180,0,180);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.05);
    glVertex2f(-.3,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.05);
    glVertex2f(-.45,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush4
    glLoadIdentity();
    glTranslatef(+0.6,-0.15,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(0,180,180);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;



    ///manush5
    glLoadIdentity();
    glTranslatef(+0.9,-0.17,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(80,0,120);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush6
    glLoadIdentity();
    glTranslatef(+1.05,-0.15,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(80,80,220);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.05);
    glVertex2f(-.3,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.05);
    glVertex2f(-.45,.05);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;


    ///manush7
     glLoadIdentity();
    glTranslatef(-0.2,-0.17,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(80,0,120);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;

    ///manush8
     glLoadIdentity();
    glTranslatef(-.35,-0.15,+0.0);

    glBegin(GL_QUADS);
    glColor3ub(80,80,0);
    glVertex2f(-.4,0.0);
    glVertex2f(-.35,0.0);
    glVertex2f(-.35,-0.15);
    glVertex2f(-.4,-0.15);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.39,-0.15);
    glVertex2f(-.39,-.25);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.35,-0.02);
    glVertex2f(-.3,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-0.02);
    glVertex2f(-.45,-.12);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-.36,-0.15);
    glVertex2f(-.36,-.25);
    glEnd();

    //glLoadIdentity();
    glColor3ub(0,0,0);
    glTranslatef(-0.375,+0.02,+0.0);
    glutSolidSphere(0.027 , 50 , 50) ;




    ///truck
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(truckposition,0.0f, 0.0f);
    glTranslatef(+0.0,+0.15,+0.0);
    //glScalef(1.05,1.0,0.0);


    glBegin(GL_QUADS);
	glColor3ub(195,0,255);
	glVertex2f(-.95,-.68);
	glVertex2f(-.55,-.68);
	glVertex2f(-.55,-.58);
	glVertex2f(-.95,-.58);

    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(55,55,155);
	glVertex2f(-.55,-.58);
	glVertex2f(-.72,-.58);
	glVertex2f(-.72,-.48);
	glVertex2f(-.58,-.48);

	glEnd();

    //glLoadIdentity();
    glBegin(GL_QUADS);
	glColor3ub(255,255,80);
	glVertex2f(-.57,-.56);
	glVertex2f(-.67,-.56);
	glVertex2f(-.67,-.5);
	glVertex2f(-.59,-.5);

    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
     GLfloat x=-.6f; GLfloat y=-.69f; GLfloat radius =.042f;
	 GLfloat triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
			 x=-.8f;  y=-.69f;  radius =.045f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

				glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPopMatrix();


    ///LampPost

    glLoadIdentity();
    LampPost();



    glLoadIdentity();
    glTranslatef(+0.8,+0.0,+0.0);
    LampPost();



    glLoadIdentity();
    glTranslatef(+1.6,+0.0,+0.0);
    LampPost();

    ///lamp er Light

    glLoadIdentity();
    glColor3ub(255,255,255);
    glTranslatef(+0.71,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    glLoadIdentity();

    glTranslatef(+0.92,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;


    glLoadIdentity();

    glTranslatef(+0.12,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    glLoadIdentity();

    glTranslatef(-.09,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    glLoadIdentity();
    glTranslatef(-.68,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    glLoadIdentity();
    glTranslatef(-.89,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    ///Tree

    glLoadIdentity();
    glTranslatef(-0.1,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+0.25,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+0.45,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+0.65,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+1.015,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+1.21,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+1.41,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();





    }


    ///_______________________EVENING____________________________///

   else if(flagevening)

    {

        ///SUN
	glLoadIdentity();

	//glPushMatrix();
//glTranslatef(0.0f,position2, 0.0f);

    glTranslatef(+0.25, -0.33, +0.0);
    glScalef(.7,.8,0);

    //glPopMatrix();
    sun();

        ///HOUSE

    glLoadIdentity();
    glTranslatef(-1.27f, +0.0f, +0.0f);
    //glScalef(.5,.5,0);

    glBegin(GL_QUADS);

    glColor3ub(123,123,123);
    glVertex2f(.3,-.3);
    glVertex2f(.3,.7);
    glVertex2f(.6,.7);
    glVertex2f(.6,-.3);

    glColor3ub(0,0,0);
    glVertex2f(.58,.7);
    glVertex2f(.58,.77);
    glVertex2f(.51,.77);
    glVertex2f(.51,.7);

     glColor3ub(255,255,0);
    glVertex2f(.34,0.65);
    glVertex2f(.43,0.65);
    glVertex2f(.43,0.6);
    glVertex2f(.34,0.6);

    glColor3ub(0,0,0);
    glVertex2f(.34,0.55);
    glVertex2f(.43,0.55);
    glVertex2f(.43,0.5);
    glVertex2f(.34,0.5);

    glColor3ub(255,255,0);
    glVertex2f(.34,0.45);
    glVertex2f(.43,0.45);
    glVertex2f(.43,0.4);
    glVertex2f(.34,0.4);

    glColor3ub(255,255,0);
    glVertex2f(.34,0.35);
    glVertex2f(.43,0.35);
    glVertex2f(.43,0.3);
    glVertex2f(.34,0.3);

    glColor3ub(255,255,0);
    glVertex2f(.34,0.25);
    glVertex2f(.43,0.25);
    glVertex2f(.43,0.2);
    glVertex2f(.34,0.2);

    glColor3ub(0,0,0);
    glVertex2f(.34,0.15);
    glVertex2f(.43,0.15);
    glVertex2f(.43,0.1);
    glVertex2f(.34,0.1);

    glColor3ub(255,255,0);
    glVertex2f(.34,0.05);
    glVertex2f(.43,0.05);
    glVertex2f(.43,0.0);
    glVertex2f(.34,0.0);

    glColor3ub(255,255,0);
    glVertex2f(.34,-0.05);
    glVertex2f(.43,-0.05);
    glVertex2f(.43,-0.1);
    glVertex2f(.34,-0.1);

    glColor3ub(255,255,0);
    glVertex2f(.34,-0.15);
    glVertex2f(.43,-0.15);
    glVertex2f(.43,-0.2);
    glVertex2f(.34,-0.2);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.65);
    glVertex2f(.56,0.65);
    glVertex2f(.56,0.6);
    glVertex2f(.47,0.6);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.55);
    glVertex2f(.56,0.55);
    glVertex2f(.56,0.5);
    glVertex2f(.47,0.5);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.45);
    glVertex2f(.56,0.45);
    glVertex2f(.56,0.4);
    glVertex2f(.47,0.4);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.35);
    glVertex2f(.56,0.35);
    glVertex2f(.56,0.3);
    glVertex2f(.47,0.3);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.25);
    glVertex2f(.56,0.25);
    glVertex2f(.56,0.2);
    glVertex2f(.47,0.2);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.15);
    glVertex2f(.56,0.15);
    glVertex2f(.56,0.1);
    glVertex2f(.47,0.1);

    //glColor3ub(255,255,0);
    glColor3ub(0,0,0);
    glVertex2f(.47,0.05);
    glVertex2f(.56,0.05);
    glVertex2f(.56,0.0);
    glVertex2f(.47,0.0);

    glColor3ub(255,255,0);
    glVertex2f(.47,-0.05);
    glVertex2f(.56,-0.05);
    glVertex2f(.56,-0.1);
    glVertex2f(.47,-0.1);

    glColor3ub(255,255,0);
    glVertex2f(.47,-0.15);
    glVertex2f(.56,-0.15);
    glVertex2f(.56,-0.2);
    glVertex2f(.47,-0.2);

    glEnd();

    ///cloud1
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(cloudposition,0.0f, 0.0f);


    glTranslatef(+0.1, +0.6, +0.0);
    glScalef(.3,.3,0);
    cloud();
    glPopMatrix();

    ///cloud2

    glLoadIdentity();
    glPushMatrix();
    glTranslatef(cloudposition,0.0f, 0.0f);


//glTranslatef(position2,0.0, 0.0);

    glTranslatef(-0.8, +0.65, +0.0);
    glScalef(.3,.3,0);

    cloud1();
    glPopMatrix();




        ///MounTain
    glLoadIdentity();
    glTranslatef(-0.82, -0.15 ,+0.0);
    glScalef(1.0,1.3,0);

    glEnable(GL_LIGHTING);//Enable Light Effect

  GLfloat global_ambient[] = {0.0,1.7,0.0, 0.1};//ambient RGBA intensity of light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//A lighting model parameter.

    mountain1();

    glDisable(GL_LIGHTING);//Enable Light Effect




	///Mountain2

    glLoadIdentity();
    glTranslatef(+0.05, -0.15, +0.0);
    glScalef(.99,.99,0);


    mountain2();



    ///Road

    glLoadIdentity();
    Road();


    ///Stairs
    glLoadIdentity();
    Stairs();

    ///Birdie
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(birdposition1,0.0f, 0.0f);

    glTranslatef(-0.5,+0.5,+0.0);
    glScalef(.5,0.8,0.0);
    Bird();

    glPopMatrix();

    glLoadIdentity();

    glPushMatrix();
    glTranslatef(birdposition1,0.0f, 0.0f);

    glTranslatef(-0.58,+0.55,+0.0);
    glScalef(.4,0.7,0.0);
    Bird();

    glPopMatrix();

    glLoadIdentity();

    glPushMatrix();
    glTranslatef(birdposition1,0.0f, 0.0f);

    glTranslatef(-0.39,+0.55,+0.0);
    glScalef(.4,0.7,0.0);
    Bird();
    glPopMatrix();


///middlepart

    glLoadIdentity();
    glTranslatef(-0.15,+0.15,+0.0);
    glScalef(.55,.65,0.0);

    //glLoadIdentity();
    MiddlePart();

///Left part1

    glLoadIdentity();
    glTranslatef(-0.6,+0.4,+0.0);
    glScalef(.9,.8,0.0);

    //glLoadIdentity();
    LeftPart();

    ///Left part1

    glLoadIdentity();
    glTranslatef(-0.88,+0.24,+0.0);
    glScalef(.7,.6,0.0);

    LeftPart();

    ///Right Part

    glLoadIdentity();
    glTranslatef(+0.3,+0.4,+0.0);
    glScalef(.9,.81,0.0);

    RightPart();

    ///Right Part1

    glLoadIdentity();
    glTranslatef(+0.65,+0.24,+0.0);
    glScalef(.7,.6,0.0);

    RightPart();



    ///Base

    glLoadIdentity();
    glTranslatef(+0.0,-0.335,+0.0);
    glScalef(1.05,1.0,0.0);
    Base();

    ///Car


    glLoadIdentity();

    glPushMatrix();
    glTranslatef(carposition,0.0f, 0.0f);

    glTranslatef(+0.0,+0.0,+0.0);
    glScalef(1.0,1.0,0.0);
    Car();
    glPopMatrix();




    ///LampPost

    glLoadIdentity();
    LampPost();



    glLoadIdentity();
    glTranslatef(+0.8,+0.0,+0.0);
    LampPost();



    glLoadIdentity();
    glTranslatef(+1.6,+0.0,+0.0);
    LampPost();

    ///lamp er Light

    glLoadIdentity();
    glColor3ub(255,255,80);
    glTranslatef(+0.71,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    glLoadIdentity();

    glTranslatef(+0.92,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;


    glLoadIdentity();

    glTranslatef(+0.12,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    glLoadIdentity();

    glTranslatef(-.09,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    glLoadIdentity();
    glTranslatef(-.68,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    glLoadIdentity();
    glTranslatef(-.89,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    ///Tree

    glLoadIdentity();
    glTranslatef(-0.1,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+0.25,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+0.45,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+0.65,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+1.015,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+1.21,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+1.41,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

///rain
    glLineWidth(1.5);
      glColor3ub(0,0,255);
    glTranslatef(rainposition,rainposition,0);
    for (GLfloat c = -5.5 ; c <= 5.5 ; c+=.1)
        for(GLfloat e = -5.5 ; e <= 5.5 ; e+=.1){
            glPointSize(3);
            glBegin(GL_LINES);
            glVertex2f(c,e);
            glVertex2f(c-.03,e-.03);
            glEnd();

        }
    glTranslatef(rainposition,rainposition,0);



    }


    ///________________________NIGHT KING_________________________///

     else if(flagnight)


    {

        ///Moon

        glLoadIdentity();

        glTranslatef(+0.25, +0.2, +0.0);
    glScalef(.7,.8,0);

        glColor3ub(225,225,225);
	glBegin(GL_TRIANGLE_FAN);
			 GLfloat x=0.6f; GLfloat y=0.75f;  GLfloat radius =.09f;
	GLfloat triangleAmount = 200; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius

	GLfloat twicePi = 2.0f * PI;


				glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}


	glEnd();


        ///HOUSE

    glLoadIdentity();
    glTranslatef(-1.27f, +0.0f, +0.0f);
    //glScalef(.5,.5,0);

    glBegin(GL_QUADS);

    glColor3ub(123,123,123);
    glVertex2f(.3,-.3);
    glVertex2f(.3,.7);
    glVertex2f(.6,.7);
    glVertex2f(.6,-.3);

    glColor3ub(0,0,0);
    glVertex2f(.58,.7);
    glVertex2f(.58,.77);
    glVertex2f(.51,.77);
    glVertex2f(.51,.7);

     glColor3ub(255,255,0);
    glVertex2f(.34,0.65);
    glVertex2f(.43,0.65);
    glVertex2f(.43,0.6);
    glVertex2f(.34,0.6);

    glColor3ub(0,0,0);
    glVertex2f(.34,0.55);
    glVertex2f(.43,0.55);
    glVertex2f(.43,0.5);
    glVertex2f(.34,0.5);

    glColor3ub(255,255,0);
    glVertex2f(.34,0.45);
    glVertex2f(.43,0.45);
    glVertex2f(.43,0.4);
    glVertex2f(.34,0.4);

    glColor3ub(255,255,0);
    glVertex2f(.34,0.35);
    glVertex2f(.43,0.35);
    glVertex2f(.43,0.3);
    glVertex2f(.34,0.3);

    glColor3ub(255,255,0);
    glVertex2f(.34,0.25);
    glVertex2f(.43,0.25);
    glVertex2f(.43,0.2);
    glVertex2f(.34,0.2);

    glColor3ub(0,0,0);
    glVertex2f(.34,0.15);
    glVertex2f(.43,0.15);
    glVertex2f(.43,0.1);
    glVertex2f(.34,0.1);

    glColor3ub(255,255,0);
    glVertex2f(.34,0.05);
    glVertex2f(.43,0.05);
    glVertex2f(.43,0.0);
    glVertex2f(.34,0.0);

    glColor3ub(255,255,0);
    glVertex2f(.34,-0.05);
    glVertex2f(.43,-0.05);
    glVertex2f(.43,-0.1);
    glVertex2f(.34,-0.1);

    glColor3ub(255,255,0);
    glVertex2f(.34,-0.15);
    glVertex2f(.43,-0.15);
    glVertex2f(.43,-0.2);
    glVertex2f(.34,-0.2);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.65);
    glVertex2f(.56,0.65);
    glVertex2f(.56,0.6);
    glVertex2f(.47,0.6);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.55);
    glVertex2f(.56,0.55);
    glVertex2f(.56,0.5);
    glVertex2f(.47,0.5);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.45);
    glVertex2f(.56,0.45);
    glVertex2f(.56,0.4);
    glVertex2f(.47,0.4);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.35);
    glVertex2f(.56,0.35);
    glVertex2f(.56,0.3);
    glVertex2f(.47,0.3);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.25);
    glVertex2f(.56,0.25);
    glVertex2f(.56,0.2);
    glVertex2f(.47,0.2);

    glColor3ub(255,255,0);
    glVertex2f(.47,0.15);
    glVertex2f(.56,0.15);
    glVertex2f(.56,0.1);
    glVertex2f(.47,0.1);

    //glColor3ub(255,255,0);
    glColor3ub(0,0,0);
    glVertex2f(.47,0.05);
    glVertex2f(.56,0.05);
    glVertex2f(.56,0.0);
    glVertex2f(.47,0.0);

    glColor3ub(255,255,0);
    glVertex2f(.47,-0.05);
    glVertex2f(.56,-0.05);
    glVertex2f(.56,-0.1);
    glVertex2f(.47,-0.1);

    glColor3ub(255,255,0);
    glVertex2f(.47,-0.15);
    glVertex2f(.56,-0.15);
    glVertex2f(.56,-0.2);
    glVertex2f(.47,-0.2);

    glEnd();


    ///cloud1
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(cloudposition,0.0f, 0.0f);


    glTranslatef(+0.1, +0.6, +0.0);
    glScalef(.3,.3,0);
    glEnable(GL_LIGHTING);//Enable Light Effect

  GLfloat global_ambient3[] = {3.3, 3.3, 3.3, 0.1};//ambient RGBA intensity of light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient3);//A lighting model parameter.


    cloud();

    glDisable(GL_LIGHTING);//Enable Light Effect
    glPopMatrix();

    ///cloud2

    glLoadIdentity();
    glPushMatrix();
    glTranslatef(cloudposition,0.0f, 0.0f);


//glTranslatef(position2,0.0, 0.0);

    glTranslatef(-0.8, +0.65, +0.0);
    glScalef(.3,.3,0);

     glEnable(GL_LIGHTING);//Enable Light Effect

  GLfloat global_ambient2[] = {3.3, 3.3, 3.3, 0.1};//ambient RGBA intensity of light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient2);//A lighting model parameter.


    cloud1();

    glDisable(GL_LIGHTING);//Enable Light Effect
    glPopMatrix();



        ///MounTain
    glLoadIdentity();
    glTranslatef(-0.82, -0.15 ,+0.0);
    glScalef(1.0,1.3,0);

    glEnable(GL_LIGHTING);//Enable Light Effect

  GLfloat global_ambient[] = {0.0,1.7,0.0, 0.1};//ambient RGBA intensity of light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//A lighting model parameter.

    mountain1();

    glDisable(GL_LIGHTING);//Enable Light Effect




	///Mountain2

    glLoadIdentity();
    glTranslatef(+0.05, -0.15, +0.0);
    glScalef(.99,.99,0);


    mountain2();


    ///plane

    glLoadIdentity();

	glPushMatrix();
    glTranslatef(planeposition,0.0f, 0.0f);

    glTranslatef(+0.0, +0.9, +0.0);
    glScalef(.25,.25,0);

    plane();
    glPopMatrix();

    ///Road

    glLoadIdentity();
    Road();


    ///Stairs
    glLoadIdentity();
    Stairs();





///middlepart

    glLoadIdentity();
    glTranslatef(-0.15,+0.15,+0.0);
    glScalef(.55,.65,0.0);

    //glLoadIdentity();
    MiddlePart();

///Left part1

    glLoadIdentity();
    glTranslatef(-0.6,+0.4,+0.0);
    glScalef(.9,.8,0.0);

    //glLoadIdentity();
    LeftPart();

    ///Left part1

    glLoadIdentity();
    glTranslatef(-0.88,+0.24,+0.0);
    glScalef(.7,.6,0.0);

    LeftPart();

    ///Right Part

    glLoadIdentity();
    glTranslatef(+0.3,+0.4,+0.0);
    glScalef(.9,.81,0.0);

    RightPart();

    ///Right Part1

    glLoadIdentity();
    glTranslatef(+0.65,+0.24,+0.0);
    glScalef(.7,.6,0.0);

    RightPart();



    ///Base

    glLoadIdentity();
    glTranslatef(+0.0,-0.335,+0.0);
    glScalef(1.05,1.0,0.0);
    Base();

    ///Truck

    glLoadIdentity();
    glPushMatrix();
    glTranslatef(truckposition,0.0f, 0.0f);
    glTranslatef(+0.0,+0.15,+0.0);
    //glScalef(1.05,1.0,0.0);


    glBegin(GL_QUADS);
	glColor3ub(195,0,255);
	glVertex2f(-.95,-.68);
	glVertex2f(-.55,-.68);
	glVertex2f(-.55,-.58);
	glVertex2f(-.95,-.58);

    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(55,55,155);
	glVertex2f(-.55,-.58);
	glVertex2f(-.72,-.58);
	glVertex2f(-.72,-.48);
	glVertex2f(-.58,-.48);

	glEnd();

    //glLoadIdentity();
    glBegin(GL_QUADS);
	glColor3ub(255,255,80);
	glVertex2f(-.57,-.56);
	glVertex2f(-.67,-.56);
	glVertex2f(-.67,-.5);
	glVertex2f(-.59,-.5);

    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    x=-.6f;  y=-.69f;  radius =.042f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	  twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
			 x=-.8f;  y=-.69f;  radius =.045f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

				glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPopMatrix();

    ///Car


    glLoadIdentity();

    glPushMatrix();
    glTranslatef(carposition,0.0f, 0.0f);

    glTranslatef(+0.0,+0.0,+0.0);
    glScalef(1.0,1.0,0.0);
    Car();
    glPopMatrix();

    ///LampPost

    glLoadIdentity();
    LampPost();



    glLoadIdentity();
    glTranslatef(+0.8,+0.0,+0.0);
    LampPost();



    glLoadIdentity();
    glTranslatef(+1.6,+0.0,+0.0);
    LampPost();

    ///lamp er Light

    glLoadIdentity();
    glColor3ub(255,255,0);
    glTranslatef(+0.71,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    glLoadIdentity();

    glTranslatef(+0.92,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;


    glLoadIdentity();

    glTranslatef(+0.12,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    glLoadIdentity();

    glTranslatef(-.09,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    glLoadIdentity();
    glTranslatef(-.68,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    glLoadIdentity();
    glTranslatef(-.89,-0.64,+0.0);
    glutSolidSphere(0.025 , 50 , 50) ;

    ///Tree

    glLoadIdentity();
    glTranslatef(-0.1,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+0.25,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+0.45,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+0.65,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+1.015,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+1.21,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();

    glLoadIdentity();
    glTranslatef(+1.41,-0.8,+0.0);
    //glScalef(1.05,1.0,0.0);
    Tree();



    }





    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);          // Initialize GLUT
    glutInitWindowSize(960,660);
    glutCreateWindow("Shohid Minar Project");
    glutDisplayFunc(display);//
    initGL();
    glutIdleFunc(Idle);//glutIdleFunc sets the global idle callback to be func so a GLUT program can perform background processing tasks or continuous animation when window system events are not being received.

    glutTimerFunc(100,update,0);
    //glutTimerFunc(100,updatecloud,0);
    glutTimerFunc(100,updaterain,0);
    glutTimerFunc(100,updatebird,0);
    glutTimerFunc(100,updatebird1,0);
    glutTimerFunc(100,updatecar,0);
    glutTimerFunc(100,updatetruck,0);
    glutTimerFunc(100,updateplane,0);
    glutKeyboardFunc(handleKeypress);
    glutSpecialFunc(SpecialInput);
    sound();


    glutMainLoop();
    return 0;
}
