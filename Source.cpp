#include<GL/freeglut.h>
#include<stdio.h>
#include<time.h>

int no;
int flag = 0;

void output(int x, int y, float r, float g, float b, char*string)
{
	glColor3f(r, g, b);
	int len, i;
	len = (int)strlen(string);
	//point[0] -= length+4;
	//point[1] -= 6;
	glRasterPos2d(x, y);
	for (i = 0; i < len; i++)
	{
		//glColor3f(0.0, 0.0, 0.0);
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
	}
}

void start()
{
	output(90, 90, 1.0, 1.0, 1.0, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	output(120,10,1.0,0.5,0.9,"Press Enter to continue");
}



void client(float r,float g,float b,int xmin,int ymin,int xmax,int ymax)
{
	glColor3f(r, g, b);
	//glColor3f(0.9, 0.5, 0.1);
	glBegin(GL_POLYGON);
	glVertex2i(xmin, ymin);//10,10
	glVertex2i(xmax, ymin);//50,10
	glVertex2i(xmax, ymax);//50,70
	glVertex2i(xmin, ymax);//10,70
	glEnd();
	output(220, 30, 0.0, 0.0, 0.0, "Client 2");
	output(20, 30, 0.0, 0.0, 0.0, "Client 1");
}

void server()
{
	glColor4f(0.0, 0.2, 0.6,0.1);
	glBegin(GL_POLYGON);
	glVertex2i(110, 10);
	glVertex2i(150, 10);
	glVertex2i(150, 70);
	glVertex2i(110, 70);
	glEnd();
	/*glColor3f(0.6, 0.3, 0.0);
	glBegin(GL_POLYGON);
	glVertex2i(155,30);
	glVertex2i(155,50);
	glVertex2i(165,50);
	glVertex2i(165,30);
	glEnd();*/
	output(120, 30, 1.0, 1.0, 1.0, "Server");
}




double x_pos=0.0, y_pos=0.0;
void sendreq(double x_pos, double y_pos)
{
	glColor3f(0.0, 0.5, 0.0);//green
	glBegin(GL_POLYGON);
	glVertex2d(x_pos, y_pos);
	glVertex2d(x_pos, y_pos - 5.0);
	glVertex2d(x_pos + 5.0, y_pos - 5.0);
	glVertex2d(x_pos + 5.0, y_pos);
	glEnd();
	
}

int x1_line = 0, y1_line = 0;
int x2_line = 0, y2_line = 0;
void request1(int x1, int y1, int x2, int y2)
{
	glColor3f(1.0, 1.0, 1.0);//black
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
	//sendreq(50.0, 67.5);
}

/*void client_backend(int xm,int ym,int xa,int ya)
{
	glColor3f(0.5, 0.0,0.5);//black
	glBegin(GL_POLYGON);
	glVertex2f(xm,ym);//15,15
	glVertex2f(xm, ya);//15,25
	glVertex2f(xa, ya);//25,25
	glVertex2f(xa, ym);//25,15
	glEnd();
}*/

void sendreq1(double x_pos, double y_pos,float r,float g,float b)
{
	//request1(50, 60, 100, 60);
	glColor4f(r, g, b,0.5);//red cookie
	glBegin(GL_POLYGON);
	glVertex2d(x_pos, y_pos);
	glVertex2d(x_pos, y_pos + 3.5);
	glVertex2d(x_pos + 5.0, y_pos + 3.5);
	glVertex2d(x_pos + 5.0, y_pos);
	glEnd();
}

void sendreq2(double x_pos, double y_pos)
{
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2d(x_pos, y_pos);
	glVertex2d(x_pos, y_pos - 5.0);
	glVertex2d(x_pos + 5.0, y_pos - 5.0);
	glVertex2d(x_pos + 5.0, y_pos);
	glEnd();
}



int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0,p51=0, p21 = 0, n = 0,p6=0;
float tx = 0, ty = 0, tx1 = 0, ty1 = 0, tx2 = 0,ty2=0;

void send()
{
	glPushMatrix();
	if (tx < 85.0)
	{
		tx = tx + 0.02;
	}
	else
	{
		p1 = 0;
		//tx = 0;
	}
    //tx = 0;
	glutPostRedisplay();
	glPopMatrix();
	}

void pool()
{
	p1 = 0;
	glPushMatrix();
	if (tx1 > -90 )
	{
		tx1 = tx1 - 0.02;
		ty1 = -80;
		ty1 += 1;
	}
	else if (ty1 > -50)
	{
		ty1 = ty1 - 0.01;
	}
	else
	{
		p2 = 0;
		tx1 = 0;
	}
	//tx = 0;
	glutPostRedisplay();
	glPopMatrix();

}

void send2()
{
	//p1 = 0;
	glPushMatrix();
	if (tx1 > -90)
	{
		tx1 = tx1 - 0.02;
		//ty1 = -80;
		//ty1 += 1;
	}
	else
	{
		p1 = 0;
		tx1 = 0;
	}
	//tx = 0;
	glutPostRedisplay();
	glPopMatrix();
}

void pool2()
{
	p1 = 0;
	glPushMatrix();
	if (tx < 85.0)
	{
		tx = tx + 0.02;
	}
	else
	{
		p2 = 0;
		//tx = 0;
	}
	//tx = 0;
	glutPostRedisplay();
	glPopMatrix();
}

void store()
{
	glPushMatrix();
	if (ty2 <30)
	{
		ty2 = ty2 - 0.05;
	}
	else
	{
		p3 = 0;
	}
	glutPostRedisplay();
	glPopMatrix();
}

void menu(int id)
{
	if (id == 1)
	{
		
		if (no == 1)
		{
			n = 1;
			p1 = 1;
			p5 = 0;
			tx = 0;
			glutIdleFunc(send);
		}
		else if (no == 2)
		{
			n = 1;
			p1 = 1;
			p5 = 0;
			tx1 = 0;
			glutIdleFunc(send2);
		}
		/*glutPostRedisplay();
		p2 = 1;
		tx1 = 0;
		n = 10;
		glutIdleFunc(pool);*/
	}
	else if (id == 2)
	{
		
		if (no == 1)
		{
			n = 10;
			p2 = 1;//p1 = p3 = p4 = p5 = 0;
			tx1 = 0;//ty1 = 0;//p3 = 1;
			p21 = 1;
			glutIdleFunc(pool);
		}
		else if (no==2)
		{
			n = 10;
			p2 = 1;//p1 = p3 = p4 = p5 = 0;
			tx = 0;//ty1 = 0;//p3 = 1;
			p21 = 1;
			glutIdleFunc(pool2);
		}
		//glutIdleFunc(pool);
	}
	else if (id == 3)
	{
		n = 15;
		p3 = 1;//p1 = p2 = p4 = p5 = 0;
		ty2 = 0;
		tx2 = 0;
		glutIdleFunc(store);
	}
	else if (id == 4)
	{
		
		if (no==1)
		{
			n = 10;
			p4 = 1;
			p1 = p2 = p3 = p5 = 0;
			tx = 0;
			glutIdleFunc(send);
		}
		else if (no == 2)
		{
			n = 10;
			p4 = 1;
			p1 = p2 = p3 = p5 = 0;
			tx1 = 0;
			glutIdleFunc(send2);
		}
	}
	else if (id == 5)
	{
		
		if (no == 1)
		{
			n = 10;
			p5 = 1;
			p1 = p2 = p3 = p4 = 0;
			tx = 0;
			glutIdleFunc(send);
		}
		else if (no == 2)
		{
			n = 10;
			p5 = 1;
			p1 = p2 = p3 = p4 = 0;
			tx1 = 0;
			glutIdleFunc(send2);
		}
	}
	else if (id == 6) {
		p6 = 1;
	}
	//glutPostRedisplay();
}

int k = 0; int k1 = 1; int tq = 0;


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.01);
	if (k1 == 1) {
		glPushMatrix();
		start();
		glPopMatrix();
	}
	if (k == 1) {
		client(0.9, 0.5, 0.1, 10, 10, 50, 70);
		//client_backend(15, 15, 25, 25);
		server();
		client(0.9, 0.8, 0.4, 210, 10, 250, 70);
		//client_backend(235, 15, 245, 25);
		//network();
		//glutPostRedisplay();
		//glutTimerFunc(1000 / 60, timer, 0);
		if (tq == 0) {
			output(110, 150, 1.0, 1.0, 1.0, "Press '1' for Client 1");
			output(110, 140, 1.0, 1.0, 1.0, "Press '2' for Client 2");
		}
		glPopMatrix();
		if (no == 1)
		{
			glPushMatrix();
			output(115, 130, 1.0, 0.0, 0.0, "Client 1 selected");
			glPopMatrix();
			if (p1 == 1)
			{
				request1(50, 65, 110, 65);
				output(60, 90, 1.0, 1.0, 1.0, "Request sent");
			}
			glPushMatrix();
			glTranslatef(tx, ty, 0.0);
			if (p1 == 1)
			{
				sendreq(50.0, 67.5);

			}
			glPopMatrix();
			glPushMatrix();
			if (p2 == 1)
			{
				request1(50, 65, 110, 65);
				char *time[20] = { "0:0","0:1","0:2","0:3","0:4","0:5","0:6","0:7","0:8","0:9","0:10" };
				if (p21 == 1)
				{
					for (int i = 0; i <= 10; i++)
					{
						output(60, 110, 0.5, 0.0, 0.5, time[i]);
					}
					output(60, 90, 1.0, 1.0, 1.0, "Cookie appended");
					output(60, 80, 1.0, 0.0, 0.0, "RED Cookie-User specific");
					output(60, 100, 1.0, 1.0, 1.0, "User-id:");
					output(85, 100, 1.0, 0.0, 0.0, "User A");
				}
			}
			glPopMatrix();
			glPushMatrix();
			//request1(50, 60, 100, 60);
			glTranslatef(tx1, ty, 0.0);
			if (p2 == 1)
			{

				//output(70, 100, 0.5, 0.0, 0.5, "00:10");
				sendreq(110.0, 67.5);
				sendreq1(110.0, 67.5, 0.5, 0.0, 0.0);

			}
			glPopMatrix();
			glPushMatrix();
			glTranslatef(tx, ty, 0.0);
			if (p3 == 1)
			{
				sendreq(50.0, 67.5);
				sendreq1(50.0, 67.5, 0.5, 0.0, 0.0);

			}
			glPopMatrix();
			glPushMatrix();
			glTranslatef(tx2, ty2, 0.0);
			if (p3 == 1)
			{
				sendreq(50.0, 67.5);
				sendreq1(50.0, 67.5, 0.5, 0.0, 0.0);
			}
			glPopMatrix();
			glPushMatrix();
			if (p4 == 1)
			{
				request1(50, 50, 110, 50);
				output(60, 90, 1.0, 0.0, 0.0, "Cookie attached with request");
			}
			glPopMatrix();
			glPushMatrix();
			glTranslatef(tx, ty, 0.0);
			if (p4 == 1)
			{

				//sendreq();

				sendreq2(50.0, 50.0);
				sendreq1(50.0, 50.0, 0.5, 0.0, 0.0);

			}
			glPopMatrix();
			glPushMatrix();
			if (p5 == 1)
			{
				output(60, 90, 1.0, 1.0, 1.0, "Cookie expired");
				request1(50, 35, 110, 35);
				//p51 = 1;
				/*glutPostRedisplay();
				output(70, 90, 0.0, 0.0, 0.0, "Cookie expired");
				glutPostRedisplay();
				output(70, 90, 1.0, 1.0, 1.0, "Cookie expired");
				glutPostRedisplay();*/

			}
			glPopMatrix();
			glPushMatrix();
			glTranslatef(tx, ty, 0.0);
			if (p5 == 1)
			{
				sendreq(50.0, 37.5);
			}
			glPopMatrix();
			glPushMatrix();
			if (p6 == 1) {
				p1 = p2 = p3 = p4 = p5 = 0;
				output(130, 100, 0.0, 1.0, 0.0, "THANK YOU");
				tq = 1;
			}
			glPopMatrix();
		}
		else if (no == 2)
		{
		glPushMatrix();
		output(115, 130, 1.0, 0.9, 0.4, "Client 2 selected");
		glPopMatrix();
			if (p1 == 1)
			{
				request1(150, 65, 210, 65);
			}
			glPushMatrix();
			glTranslatef(tx1, ty, 0.0);
			if (p1 == 1)
			{
				sendreq(210.0, 67.5);

			}
			glPopMatrix();
			glPushMatrix();
			if (p2 == 1)
			{
				request1(150, 65, 210, 65);
				char *time[20] = { "0:0","0:1","0:2","0:3","0:4","0:5","0:6","0:7","0:8","0:9","0:10" };
				if (p21 == 1)
				{
					for (int i = 0; i <= 10; i++)
					{
						output(170, 110, 0.5, 0.0, 0.5, time[i]);
					}
					output(160, 90, 1.0, 1.0, 1.0, "Cookie appended");
					output(160, 80, 1.0, 0.9, 0.5, "YELLOW cookie - User specific");
					output(160, 100, 1.0, 1.0, 1.0, "User-id:");
					output(185, 100, 1.0, 0.9, 0.5, "User B");
				}
			}
			glPopMatrix();
			glPushMatrix();
			//request1(50, 60, 100, 60);
			glTranslatef(tx, ty, 0.0);
			if (p2 == 1)
			{

				//output(70, 100, 0.5, 0.0, 0.5, "00:10");
				sendreq(150.0, 67.5);
				sendreq1(150.0, 67.5, 1.0, 0.9, 0.5);

			}
			glPopMatrix();
			glPushMatrix();
			glTranslatef(tx, ty, 0.0);
			if (p3 == 1)
			{
				sendreq(210.0, 67.5);
				sendreq1(210.0, 67.5, 1.0, 0.9, 0.5);

			}
			glPopMatrix();
			glPushMatrix();
			glTranslatef(tx2, ty2, 0.0);
			if (p3 == 1)
			{
				sendreq(210.0, 67.5);
				sendreq1(210.0, 67.5, 1.0, 0.9, 0.5);
			}
			glPopMatrix();
			glPushMatrix();
			if (p4 == 1)
			{
				request1(150, 50, 210, 50);
				output(160, 90, 1.0, 0.9, 0.5, "Cookie appended with request");
			}
			glPopMatrix();
			glPushMatrix();
			glTranslatef(tx1, ty, 0.0);
			if (p4 == 1)
			{

				//sendreq();

				sendreq2(210.0, 50.0);
				sendreq1(210.0, 50.0, 1.0, 0.9, 0.5);

			}
			glPopMatrix();
			glPushMatrix();
			if (p5 == 1)
			{
				output(160, 90, 1.0, 1.0, 1.0, "Cookie expired");
				request1(150, 35, 210, 35);
				//p51 = 1;


			}
			glPopMatrix();
			glPushMatrix();
			glTranslatef(tx1, ty, 0.0);
			if (p5 == 1)
			{
				sendreq(210.0, 37.5);
				//newmenu();
			}
			glPopMatrix();
			glPushMatrix();
			if (p6 == 1) {
				p1 = p2 = p3 = p4 = p5 = 0;
				tq = 1;
				output(110, 150, 0.0, 1.0, 0.0, "THANK YOU");
			}
			glPopMatrix();

		}
	}
	glFlush();
	glutSwapBuffers();

}

void init(int w,int h)
{
	
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 300.0, 0.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
}

/*void timer(int)
{

	//glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
	while (x_pos < 105.0)
	{
		x_pos += 0.15;
		if (y_pos > 57.5)
		{
			y_pos -= 0.10;
			break;
		}
	}
}*/

void keys(unsigned char key, int x, int y) {
	if (key == 13)
		k = 1; k1 = 0;
	if (key == 49)
		no = 1;
	if (key == 50)
		no = 2;
	glutPostRedisplay();
}



void main(int argc, char **argv)
{

	
	//printf_s("Enter the Client no.");
	//scanf_s("%d", &no);
	

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(300, 50);
	glutInitWindowSize(1000, 600);
	glutCreateWindow("WEB COOKIES");
	glutDisplayFunc(display);
	glutKeyboardFunc(keys);
	glutReshapeFunc(init);
	glutCreateMenu(menu);
	glutAddMenuEntry("Establish_connection", 1);
	glutAddMenuEntry("Accept", 2);
	//glutAddMenuEntry("store", 3);
	glutAddMenuEntry("Send_first_request", 4);
	glutAddMenuEntry("Establish_after_expiry", 5);
	glutAddMenuEntry("Exit", 6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	
	//glutMouseFunc(mouseClicks);

	//glutTimerFunc(0000, timer, 0);
	glutMainLoop();

}
