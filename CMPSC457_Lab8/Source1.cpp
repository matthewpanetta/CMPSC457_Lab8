
#include <GL/glut.h>

GLubyte r[16] = {
	0x00, 0x00, 0x41, 0x42, 0x44, 0x48, 0x50, 0x60, 0x78,	// The image is 8x16, so each byte represents a row.
	0x44, 0x42, 0x42, 0x44, 0x78, 0x00, 0x00 };				

void init()
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);	// Unpack byte-aligned pixels
	glClearColor(0.0, 0.0, 0.0, 1.0);		// Clear color = black
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2f(57.0, 45.0);				 // Center the bitmap on screen
	glBitmap(8, 16, 0.0, 0.0, 0.0, 0.0, r);	 // Draw the 8x16 image from the r array
	glFlush();
}


void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLfloat)w, 0.0, (GLfloat)h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{

	/* Initialize mode and open a window in upper left corner of screen */
	/* Window title is name of program (arg[0]) */

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(100, 100);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("bitmap");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();
	glEnable(GL_COLOR_LOGIC_OP);
	glLogicOp(GL_XOR);
	glutMainLoop();

}
