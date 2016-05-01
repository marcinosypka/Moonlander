#define _CRT_SECURE_NO_WARNINGS
#include <windows.h> // Window defines
#include <gl\gl.h> 
#include <gl\glu.h> 
#include <iostream>
#include <iostream>
#include "RESOURCE.H"
#include "Shape.h"
#include "Cone.h"
#include "vector3f.h"
#include "World.h"

const LPCTSTR lpszAppName = (LPCTSTR)"MoonLander";
static HINSTANCE hInstance;
static const unsigned int BITMAP_ID = 0x4D42;
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

static GLsizei lastHeight;
static GLsizei lastWidth;
// Opis tekstury
BITMAPINFOHEADER	bitmapInfoHeader;	// nag3�wek obrazu
unsigned char*		bitmapData;			// dane tekstury
unsigned int		texture[2];			// obiekt tekstury
										
// Color Palette handle
HPALETTE hPalette = NULL;



World* world = new World();

//############# FUNCTION PROTOTYPES ########################

LRESULT CALLBACK WndProc(HWND hWnd,UINT    message, WPARAM  wParam, LPARAM  lParam);
// Dialog procedure for about box
BOOL APIENTRY AboutDlgProc(HWND hDlg, UINT message, UINT wParam, LONG lParam);

// Set Pixel Format function - forward declaration
void SetDCPixelFormat(HDC hDC);



void ukladWspolrzednych(void) {

	GLfloat xa[3] = { -300.0f,0.0f, 0.0f };
	GLfloat xb[3] = { 300.0f,0.0f, 0.0f };
	GLfloat xc[3] = { 295.0f,-1.0f,-1.0f };
	GLfloat xd[3] = { 295.0f, 1.0f,-1.0f };
	GLfloat xe[3] = { 295.0f, 1.0f, 1.0f };
	GLfloat xf[3] = { 295.0f,-1.0f, 1.0f };

	GLfloat ya[3] = { 0.0f,-300.0f,0.0f };
	GLfloat yb[3] = { 0.0f, 300.0f,0.0f };
	GLfloat yc[3] = { -1.0f, 295.0f,-1.0f };
	GLfloat yd[3] = { 1.0f, 295.0f,-1.0f };
	GLfloat ye[3] = { 1.0f, 295.0f, 1.0f };
	GLfloat yf[3] = { -1.0f, 295.0f, 1.0f };

	GLfloat za[3] = { 0.0f, 0.0f,-300.0f };
	GLfloat zb[3] = { 0.0f, 0.0f, 300.0f };
	GLfloat zc[3] = { -1.0f,-1.0f, 295.0f };
	GLfloat zd[3] = { 1.0f,-1.0f, 295.0f };
	GLfloat ze[3] = { 1.0f, 1.0f, 295.0f };
	GLfloat zf[3] = { -1.0f, 1.0f, 295.0f };
	glColor3f(0.0f, 0.0f, 0.0f);

	//oo x
	glBegin(GL_LINES);
	glVertex3fv(xa);
	glVertex3fv(xb);
	glEnd();
	//grot
	glFrontFace(GL_CW);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3fv(xb);
	glVertex3fv(xc);
	glVertex3fv(xd);
	glVertex3fv(xe);
	glVertex3fv(xf);
	glVertex3fv(xc);
	glEnd();
	glFrontFace(GL_CCW);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3fv(xc);
	glVertex3fv(xd);
	glVertex3fv(xf);
	glVertex3fv(xe);
	glEnd();
	//oo y
	glBegin(GL_LINES);
	glVertex3fv(ya);
	glVertex3fv(yb);
	glEnd();
	glFrontFace(GL_CW);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3fv(yb);
	glVertex3fv(yc);
	glVertex3fv(yd);
	glVertex3fv(ye);
	glVertex3fv(yf);
	glVertex3fv(yc);
	glEnd();
	glFrontFace(GL_CCW);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3fv(yc);
	glVertex3fv(yd);
	glVertex3fv(yf);
	glVertex3fv(ye);
	glEnd();
	//oo z
	glBegin(GL_LINES);
	glVertex3fv(za);
	glVertex3fv(zb);
	glEnd();
	glFrontFace(GL_CW);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3fv(zb);
	glVertex3fv(zc);
	glVertex3fv(zd);
	glVertex3fv(ze);
	glVertex3fv(zf);
	glVertex3fv(zc);
	glEnd();
	glFrontFace(GL_CCW);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3fv(zc);
	glVertex3fv(zd);
	glVertex3fv(zf);
	glVertex3fv(ze);
	glEnd();
}



HPALETTE GetOpenGLPalette(HDC hDC)
{
	HPALETTE hRetPal = NULL;	// Handle to palette to be created
	PIXELFORMATDESCRIPTOR pfd;	// Pixel Format Descriptor
	LOGPALETTE *pPal;			// Pointer to memory for logical palette
	int nPixelFormat;			// Pixel format index
	int nColors;				// Number of entries in palette
	int i;						// Counting variable
	BYTE RedRange, GreenRange, BlueRange;
	// Range for each color entry (7,7,and 3)


	// Get the pixel format index and retrieve the pixel format description
	nPixelFormat = GetPixelFormat(hDC);
	DescribePixelFormat(hDC, nPixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

	// Does this pixel format require a palette?  If not, do not create a
	// palette and just return NULL
	if (!(pfd.dwFlags & PFD_NEED_PALETTE))
		return NULL;

	// Number of entries in palette.  8 bits yeilds 256 entries
	nColors = 1 << pfd.cColorBits;

	// Allocate space for a logical palette structure plus all the palette entries
	pPal = (LOGPALETTE*)malloc(sizeof(LOGPALETTE) + nColors*sizeof(PALETTEENTRY));

	// Fill in palette header 
	pPal->palVersion = 0x300;		// Windows 3.0
	pPal->palNumEntries = nColors; // table size

								   // Build mask of all 1's.  This creates a number represented by having
								   // the low order x bits set, where x = pfd.cRedBits, pfd.cGreenBits, and
								   // pfd.cBlueBits.  
	RedRange = (1 << pfd.cRedBits) - 1;
	GreenRange = (1 << pfd.cGreenBits) - 1;
	BlueRange = (1 << pfd.cBlueBits) - 1;

	// Loop through all the palette entries
	for (i = 0; i < nColors; i++)
	{
		// Fill in the 8-bit equivalents for each component
		pPal->palPalEntry[i].peRed = (i >> pfd.cRedShift) & RedRange;
		pPal->palPalEntry[i].peRed = (unsigned char)(
			(double)pPal->palPalEntry[i].peRed * 255.0 / RedRange);

		pPal->palPalEntry[i].peGreen = (i >> pfd.cGreenShift) & GreenRange;
		pPal->palPalEntry[i].peGreen = (unsigned char)(
			(double)pPal->palPalEntry[i].peGreen * 255.0 / GreenRange);

		pPal->palPalEntry[i].peBlue = (i >> pfd.cBlueShift) & BlueRange;
		pPal->palPalEntry[i].peBlue = (unsigned char)(
			(double)pPal->palPalEntry[i].peBlue * 255.0 / BlueRange);

		pPal->palPalEntry[i].peFlags = (unsigned char)NULL;
	}


	// Create the palette
	hRetPal = CreatePalette(pPal);

	// Go ahead and select and realize the palette for this device context
	SelectPalette(hDC, hRetPal, FALSE);
	RealizePalette(hDC);

	// Free the memory used for the logical palette structure
	free(pPal);

	// Return the handle to the new palette
	return hRetPal;
}
void ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat nRange = 200.0f;
	GLfloat fAspect;
	// Prevent a divide by zero
	if (h == 0)
		h = 1;

	lastWidth = w;
	lastHeight = h;

	fAspect = (GLfloat)w / (GLfloat)h;
	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
	if (w <= h)
		glOrtho(-nRange, nRange, -nRange*h / w, nRange*h / w, -nRange, nRange);
	else
		glOrtho(-nRange*w / h, nRange*w / h, -nRange, nRange, -nRange, nRange);

	// Establish perspective: 
	/*
	gluPerspective(60.0f,fAspect,1.0,400);
	*/

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void SetupRC()
{
	// Light values and coordinates
	//GLfloat  ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	//GLfloat  diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	//GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
	//GLfloat	 lightPos[] = { 0.0f, 150.0f, 150.0f, 1.0f };
	//GLfloat  specref[] =  { 1.0f, 1.0f, 1.0f, 1.0f };


	glEnable(GL_DEPTH_TEST);	// Hidden surface removal
	glFrontFace(GL_CCW);		// Counter clock-wise polygons face out
								//glEnable(GL_CULL_FACE);		// Do not calculate inside of jet

								// Enable lighting
								//glEnable(GL_LIGHTING);

								// Setup and enable light 0
								//glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
								//glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
								//glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
								//glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
								//glEnable(GL_LIGHT0);

								// Enable color tracking
								//glEnable(GL_COLOR_MATERIAL);

								// Set Material properties to follow glColor values
								//glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

								// All materials hereafter have full specular reflectivity
								// with a high shine
								//glMaterialfv(GL_FRONT, GL_SPECULAR,specref);
								//glMateriali(GL_FRONT,GL_SHININESS,128);


								// White background
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Black brush
	glColor3f(0.0, 0.0, 0.0);
}
void ReduceToUnit(float vector[3])
{
	float length;

	// Calculate the length of the vector		
	length = (float)sqrt((vector[0] * vector[0]) +
		(vector[1] * vector[1]) +
		(vector[2] * vector[2]));

	// Keep the program from blowing up by providing an exceptable
	// value for vectors that may calculated too close to zero.
	if (length == 0.0f)
		length = 1.0f;

	// Dividing each element by the length will result in a
	// unit normal vector.
	vector[0] /= length;
	vector[1] /= length;
	vector[2] /= length;
}
void calcNormal(float v[3][3], float out[3])
{
	float v1[3], v2[3];
	static const int x = 0;
	static const int y = 1;
	static const int z = 2;

	// Calculate two vectors from the three points
	v1[x] = v[0][x] - v[1][x];
	v1[y] = v[0][y] - v[1][y];
	v1[z] = v[0][z] - v[1][z];

	v2[x] = v[1][x] - v[2][x];
	v2[y] = v[1][y] - v[2][y];
	v2[z] = v[1][z] - v[2][z];

	// Take the cross product of the two vectors to get
	// the normal vector which will be stored in out
	out[x] = v1[y] * v2[z] - v1[z] * v2[y];
	out[y] = v1[z] * v2[x] - v1[x] * v2[z];
	out[z] = v1[x] * v2[y] - v1[y] * v2[x];

	// Normalize the vector (shorten length to one)
	ReduceToUnit(out);
}
void RenderScene(void)
{
	//float normal[3];	// Storeage for calculated surface normal

	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Save the matrix state and do the rotations
	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);

	/////////////////////////////////////////////////////////////////
	// MIEJSCE NA KOD OPENGL DO TWORZENIA WLASNYCH SCEN:		   //
	/////////////////////////////////////////////////////////////////
	//ukladWspolrzednych();

	world->render();

	//Spos�b na odr�nienie "przedniej" i "tylniej" �ciany wielok�ta:

	glPolygonMode(GL_BACK, GL_LINE);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	// Flush drawing commands
	glFlush();
}
void SetDCPixelFormat(HDC hDC)
{
	int nPixelFormat;

	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),  // Size of this structure
		1,                                                              // Version of this structure    
		PFD_DRAW_TO_WINDOW |                    // Draw to Window (not to bitmap)
		PFD_SUPPORT_OPENGL |					// Support OpenGL calls in window
		PFD_DOUBLEBUFFER,                       // Double buffered
		PFD_TYPE_RGBA,                          // RGBA Color mode
		24,                                     // Want 24bit color 
		0,0,0,0,0,0,                            // Not used to select mode
		0,0,                                    // Not used to select mode
		0,0,0,0,0,                              // Not used to select mode
		32,                                     // Size of depth buffer
		0,                                      // Not used to select mode
		0,                                      // Not used to select mode
		PFD_MAIN_PLANE,                         // Draw in main plane
		0,                                      // Not used to select mode
		0,0,0 };                                // Not used to select mode

												// Choose a pixel format that best matches that described in pfd
	nPixelFormat = ChoosePixelFormat(hDC, &pfd);

	// Set the pixel format for the device context
	SetPixelFormat(hDC, nPixelFormat, &pfd);
}
unsigned char *LoadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader)
{
	FILE *filePtr;							// wskaYnik pozycji pliku
	BITMAPFILEHEADER	bitmapFileHeader;		// nag3�wek pliku
	unsigned char		*bitmapImage;			// dane obrazu
	int					imageIdx = 0;		// licznik pikseli
	unsigned char		tempRGB;				// zmienna zamiany sk3adowych

												// otwiera plik w trybie "read binary"
	filePtr = fopen(filename, "rb");
	if (filePtr == NULL)
		return NULL;

	// wczytuje nag3�wek pliku
	fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr);

	// sprawdza, czy jest to plik formatu BMP
	if (bitmapFileHeader.bfType != BITMAP_ID)
	{
		fclose(filePtr);
		return NULL;
	}

	// wczytuje nag3�wek obrazu
	fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);

	// ustawia wskaYnik pozycji pliku na pocz1tku danych obrazu
	fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);

	// przydziela pamiea buforowi obrazu
	bitmapImage = (unsigned char*)malloc(bitmapInfoHeader->biSizeImage);

	// sprawdza, czy uda3o sie przydzielia pamiea
	if (!bitmapImage)
	{
		free(bitmapImage);
		fclose(filePtr);
		return NULL;
	}

	// wczytuje dane obrazu
	fread(bitmapImage, 1, bitmapInfoHeader->biSizeImage, filePtr);

	// sprawdza, czy dane zosta3y wczytane
	if (bitmapImage == NULL)
	{
		fclose(filePtr);
		return NULL;
	}

	// zamienia miejscami sk3adowe R i B 
	for (imageIdx = 0; imageIdx < bitmapInfoHeader->biSizeImage; imageIdx += 3)
	{
		tempRGB = bitmapImage[imageIdx];
		bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
		bitmapImage[imageIdx + 2] = tempRGB;
	}

	// zamyka plik i zwraca wskaYnik bufora zawieraj1cego wczytany obraz
	fclose(filePtr);
	return bitmapImage;
}


int APIENTRY WinMain(HINSTANCE       hInst,
	HINSTANCE       hPrevInstance,
	LPSTR           lpCmdLine,
	int                     nCmdShow)
{
	MSG                     msg;            // Windows message structure
	WNDCLASS        wc;                     // Windows class structure
	HWND            hWnd;           // Storeage for window handle

	hInstance = hInst;

	// Register Window style
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	// No need for background brush for OpenGL window
	wc.hbrBackground = NULL;

	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU);
	wc.lpszClassName = lpszAppName;

	// Register the window class
	if (RegisterClass(&wc) == 0)
		return FALSE;


	// Create the main application window
	hWnd = CreateWindow(
		lpszAppName,
		lpszAppName,

		// OpenGL requires WS_CLIPCHILDREN and WS_CLIPSIBLINGS
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,

		// Window position and size
		50, 50,
		400, 400,
		NULL,
		NULL,
		hInstance,
		NULL);

	// If window was not created, quit
	if (hWnd == NULL)
		return FALSE;

	world->initiate();
	world->populate();

	// Display the window
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	// Process application messages until the application closes
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}




// Window procedure, handles all messages for this program
LRESULT CALLBACK WndProc(HWND    hWnd,
	UINT    message,
	WPARAM  wParam,
	LPARAM  lParam)
{
	static HGLRC hRC;               // Permenant Rendering context
	static HDC hDC;                 // Private GDI Device context

	switch (message)
	{
		// Window creation, setup for OpenGL
	case WM_CREATE:
		// Store the device context
		hDC = GetDC(hWnd);

		// Select the pixel format
		SetDCPixelFormat(hDC);

		// Create palette if needed
		hPalette = GetOpenGLPalette(hDC);

		// Create the rendering context and make it current
		hRC = wglCreateContext(hDC);
		wglMakeCurrent(hDC, hRC);
		SetupRC();
		glGenTextures(2, &texture[0]);                  // tworzy obiekt tekstury			

														// 3aduje pierwszy obraz tekstury:
		bitmapData = LoadBitmapFile("Bitmapy\\checker.bmp", &bitmapInfoHeader);

		glBindTexture(GL_TEXTURE_2D, texture[0]);       // aktywuje obiekt tekstury

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

		// tworzy obraz tekstury
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmapInfoHeader.biWidth,
			bitmapInfoHeader.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmapData);

		if (bitmapData)
			free(bitmapData);

		// 3aduje drugi obraz tekstury:
		bitmapData = LoadBitmapFile("Bitmapy\\crate.bmp", &bitmapInfoHeader);
		glBindTexture(GL_TEXTURE_2D, texture[1]);       // aktywuje obiekt tekstury

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

		// tworzy obraz tekstury
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmapInfoHeader.biWidth,
			bitmapInfoHeader.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmapData);

		if (bitmapData)
			free(bitmapData);

		// ustalenie sposobu mieszania tekstury z t3em
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		break;

		// Window is being destroyed, cleanup
	case WM_DESTROY:
		// Deselect the current rendering context and delete it
		wglMakeCurrent(hDC, NULL);
		wglDeleteContext(hRC);

		// Delete the palette if it was created
		if (hPalette != NULL)
			DeleteObject(hPalette);

		// Tell the application to terminate after the window
		// is gone.
		PostQuitMessage(0);
		break;

		// Window is resized.
	case WM_SIZE:
		// Call our function which modifies the clipping
		// volume and viewport
		ChangeSize(LOWORD(lParam), HIWORD(lParam));
		break;


		// The painting function.  This message sent by Windows 
		// whenever the screen needs updating.
	case WM_PAINT:
	{
		// Call OpenGL drawing code
		RenderScene();

		SwapBuffers(hDC);

		// Validate the newly painted client area
		ValidateRect(hWnd, NULL);
	}
	break;

	// Windows is telling the application that it may modify
	// the system palette.  This message in essance asks the 
	// application for a new palette.
	case WM_QUERYNEWPALETTE:
		// If the palette was created.
		if (hPalette)
		{
			int nRet;

			// Selects the palette into the current device context
			SelectPalette(hDC, hPalette, FALSE);

			// Map entries from the currently selected palette to
			// the system palette.  The return value is the number 
			// of palette entries modified.
			nRet = RealizePalette(hDC);

			// Repaint, forces remap of palette in current window
			InvalidateRect(hWnd, NULL, FALSE);

			return nRet;
		}
		break;


		// This window may set the palette, even though it is not the 
		// currently active window.
	case WM_PALETTECHANGED:
		// Don't do anything if the palette does not exist, or if
		// this is the window that changed the palette.
		if ((hPalette != NULL) && ((HWND)wParam != hWnd))
		{
			// Select the palette into the device context
			SelectPalette(hDC, hPalette, FALSE);

			// Map entries to system palette
			RealizePalette(hDC);

			// Remap the current colors to the newly realized palette
			UpdateColors(hDC);
			return 0;
		}
		break;

		// Key press, check for arrow keys to do cube rotation.
	case WM_KEYDOWN:
	{
		if (wParam == VK_UP)
			xRot -= 5.0f;

		if (wParam == VK_DOWN)
			xRot += 5.0f;

		if (wParam == VK_LEFT)
			yRot -= 5.0f;

		if (wParam == VK_RIGHT)
			yRot += 5.0f;

		xRot = GLfloat((const int)xRot % 360);
		yRot = GLfloat((const int)yRot % 360);

		
		InvalidateRect(hWnd, NULL, FALSE);
	}
	break;

	// A menu command
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
			// Exit the program
		case ID_FILE_EXIT:
			DestroyWindow(hWnd);
			break;

			// Display the about box
		case ID_HELP_ABOUT:
			DialogBox(hInstance,
				MAKEINTRESOURCE(IDD_DIALOG_ABOUT),
				hWnd,
				(DLGPROC)AboutDlgProc);
			break;
		}
	}
	break;


	default:   // Passes it on if unproccessed
		return (DefWindowProc(hWnd, message, wParam, lParam));

	}

	return (0L);
}




// Dialog procedure.
BOOL APIENTRY AboutDlgProc(HWND hDlg, UINT message, UINT wParam, LONG lParam)
{

	switch (message)
	{
		// Initialize the dialog box
	case WM_INITDIALOG:
	{
		int i;
		GLenum glError;

		// glGetString demo
		SetDlgItemText(hDlg, IDC_OPENGL_VENDOR, (LPCSTR)glGetString(GL_VENDOR));
		SetDlgItemText(hDlg, IDC_OPENGL_RENDERER, (LPCSTR)glGetString(GL_RENDERER));
		SetDlgItemText(hDlg, IDC_OPENGL_VERSION, (LPCSTR)glGetString(GL_VERSION));
		SetDlgItemText(hDlg, IDC_OPENGL_EXTENSIONS, (LPCSTR)glGetString(GL_EXTENSIONS));

		// gluGetString demo
		SetDlgItemText(hDlg, IDC_GLU_VERSION, (LPCSTR)gluGetString(GLU_VERSION));
		SetDlgItemText(hDlg, IDC_GLU_EXTENSIONS, (LPCSTR)gluGetString(GLU_EXTENSIONS));


		// Display any recent error messages
		i = 0;
		do {
			glError = glGetError();
			SetDlgItemText(hDlg, IDC_ERROR1 + i, (LPCSTR)gluErrorString(glError));
			i++;
		} while (i < 6 && glError != GL_NO_ERROR);


		return (TRUE);
	}
	break;

	// Process command messages
	case WM_COMMAND:
	{
		// Validate and Make the changes
		if (LOWORD(wParam) == IDOK)
			EndDialog(hDlg, TRUE);
	}
	break;

	// Closed from sysbox
	case WM_CLOSE:
		EndDialog(hDlg, TRUE);
		break;
	}

	return FALSE;
}