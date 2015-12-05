#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#define P7

#include "../include/u-gine.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main(int argc, char* argv[]) {
	Screen::Instance().Open(800, 600, false);

#pragma region Practica 1 INIT
#ifdef P1
	int16 centerHeight, centerWidth, mouseX, mouseY, circleCenterX, circleCenterY, trueAngle;
	int16 angle = 0;
	String * title = new String();
	int32 distance;
#endif
#pragma endregion

#pragma region Practica 2 INIT
#ifdef P2
	String *fileName = new String();
	*fileName = "../data/soccer_npot.png";
	Image * ballTex=ResourceManager::Instance().LoadImage(*fileName);
	ballTex->SetMidHandle();
	double rotation = 0;
	double scale = 0;
	int increment = 1;
#endif
#pragma endregion

#pragma region Practica 3 INIT
#ifdef P3_1 or P3_2
	uint32 blendModeSRC;
	uint32 blendModeDST;
	String *boxFileName = new String();
	*boxFileName = "../data/box.jpg";
	Image * boxTex = ResourceManager::Instance().LoadImage(*boxFileName);
	String *LightFileName = new String();
	*LightFileName = "../data/light.png";
	Image * lightTex = ResourceManager::Instance().LoadImage(*LightFileName);
	uint16 thirdOfWidth = Screen::Instance().GetWidth() / 3;
	uint16 eighthOfHeight = Screen::Instance().GetHeight() / 8;
	uint16 sixthdOfWidth = Screen::Instance().GetWidth() / 6;
	uint16 eighthOfWidth = Screen::Instance().GetWidth() / 8;
#endif
#pragma endregion

#pragma region Practica 4-1 INIT
#ifdef P4_1
	srand(time(0));
	Array<Sprite *> *spriteArray = new Array<Sprite *>(4);
	struct spriteSpeed {
		double x, y;
		spriteSpeed(double x, double y) {
			this->x = x;
			this->y = y;
		}
	};
	spriteSpeed * userData;
	Sprite * currentSprite;
	double incX, incY;
	String *fileName = new String();
	int32 mouseX, mouseY;
	//Basquetball
	*fileName = "data/ball.png";
	Image * bBallTex = ResourceManager::Instance().LoadImage(*fileName);
	bBallTex->SetMidHandle();
	spriteArray->Add(new Sprite(bBallTex));
	spriteArray->Last()->SetBlendMode(Renderer::ALPHA);
	spriteArray->Last()->SetPosition((rand() % (Screen::Instance().GetWidth() - bBallTex->GetWidth())) + bBallTex->GetWidth() / 2, (rand() % (Screen::Instance().GetHeight()- bBallTex->GetHeight()))+ bBallTex->GetHeight() / 2);
	spriteArray->Last()->SetUserData(new spriteSpeed((rand()%100)+100, (rand() % 100) + 100));

	//Football
	*fileName = "data/soccer_npot.png";
	Image * fBallTex = ResourceManager::Instance().LoadImage(*fileName);
	fBallTex->SetMidHandle();
	spriteArray->Add(new Sprite(fBallTex));
	spriteArray->Last()->SetBlendMode(Renderer::ALPHA);
	spriteArray->Last()->SetPosition((rand() % (Screen::Instance().GetWidth() - fBallTex->GetWidth())) + fBallTex->GetWidth() / 2, (rand() % (Screen::Instance().GetHeight()- fBallTex->GetHeight())) + fBallTex->GetHeight() / 2);
	spriteArray->Last()->SetUserData(new spriteSpeed((rand() % 100) + 100, (rand() % 100) + 100));
	
	//Box
	*fileName = "data/box.jpg";
	Image * boxTex = ResourceManager::Instance().LoadImage(*fileName);
	boxTex->SetMidHandle();
	spriteArray->Add(new Sprite(boxTex));
	spriteArray->Last()->SetBlendMode(Renderer::ALPHA);
	spriteArray->Last()->SetPosition((rand() % (Screen::Instance().GetWidth()- boxTex->GetWidth())) + boxTex->GetWidth() / 2, (rand() % (Screen::Instance().GetHeight()- boxTex->GetHeight())) + boxTex->GetHeight() / 2);
	spriteArray->Last()->SetUserData(new spriteSpeed((rand() % 100) + 100, (rand() % 100) + 100));
	
	//Alien
	*fileName = "data/alien.png";
	Image * alienTex = ResourceManager::Instance().LoadImage(*fileName);
	alienTex->SetMidHandle();
	spriteArray->Add(new Sprite(alienTex));
	spriteArray->Last()->SetBlendMode(Renderer::ALPHA);
	spriteArray->Last()->SetPosition((rand() % (Screen::Instance().GetWidth()- alienTex->GetWidth())) + alienTex->GetWidth() / 2, (rand() % (Screen::Instance().GetHeight()- alienTex->GetHeight())) + alienTex->GetHeight() / 2);
	spriteArray->Last()->SetUserData(new spriteSpeed((rand() % 100) + 100, (rand() % 100) + 100));
#endif
#pragma endregion

#pragma region Practica 4-2 INIT
#ifdef P4_2
	srand(time(0));
	Array<Sprite *> *spriteArray = new Array<Sprite *>(4);
	Sprite * currentSprite;
	String *fileName = new String();
	int32 mouseX, mouseY;

	*fileName = "data/alien.png";
	Image * alienTex = ResourceManager::Instance().LoadImage(*fileName);
	alienTex->SetMidHandle();

	//Alien 1
	spriteArray->Add(new Sprite(alienTex));
	spriteArray->Last()->SetBlendMode(Renderer::ALPHA);
	spriteArray->Last()->SetPosition(0 + alienTex->GetWidth()/2,0 + alienTex->GetHeight() / 2);

	//Alien 2
	spriteArray->Add(new Sprite(alienTex));
	spriteArray->Last()->SetBlendMode(Renderer::ALPHA);
	spriteArray->Last()->SetPosition(800 - alienTex->GetWidth() / 2, 0 + alienTex->GetHeight() / 2);

	//Alien 3
	spriteArray->Add(new Sprite(alienTex));
	spriteArray->Last()->SetBlendMode(Renderer::ALPHA);
	spriteArray->Last()->SetPosition(0 + alienTex->GetWidth() / 2, 600 - alienTex->GetHeight() / 2);

	//Alien 4
	spriteArray->Add(new Sprite(alienTex));
	spriteArray->Last()->SetBlendMode(Renderer::ALPHA);
	spriteArray->Last()->SetPosition(800 - alienTex->GetWidth() / 2, 600 - alienTex->GetHeight() / 2);
#endif
#pragma endregion

#pragma region Practica 5-1 INIT
#ifdef P5_1
	Array<Sprite *> *spriteArray = new Array<Sprite *>(4);
	Sprite * currentSprite;
	String *fileName = new String();
	int32 mouseX, mouseY;

	*fileName = "data/alienanim.png";
	Image * alienTex = ResourceManager::Instance().LoadImage(*fileName,8,1);
	alienTex->SetMidHandle();

	//Alien 1
	spriteArray->Add(new Sprite(alienTex));
	spriteArray->Last()->SetBlendMode(Renderer::ALPHA);
	spriteArray->Last()->SetPosition(0 + alienTex->GetWidth()/2,0 + alienTex->GetHeight() / 2);
	spriteArray->Last()->SetFPS(16);
	spriteArray->Last()->SetScale(4, 4);

	//Alien 2
	spriteArray->Add(new Sprite(alienTex));
	spriteArray->Last()->SetBlendMode(Renderer::ALPHA);
	spriteArray->Last()->SetPosition(800 - alienTex->GetWidth() / 2, 0 + alienTex->GetHeight() / 2);
	spriteArray->Last()->SetFPS(16);
	spriteArray->Last()->SetScale(4, 4);

	//Alien 3
	spriteArray->Add(new Sprite(alienTex));
	spriteArray->Last()->SetBlendMode(Renderer::ALPHA);
	spriteArray->Last()->SetPosition(0 + alienTex->GetWidth() / 2, 600 - alienTex->GetHeight() / 2);
	spriteArray->Last()->SetFPS(16);
	spriteArray->Last()->SetScale(4, 4);

	//Alien 4
	spriteArray->Add(new Sprite(alienTex));
	spriteArray->Last()->SetBlendMode(Renderer::ALPHA);
	spriteArray->Last()->SetPosition(800 - alienTex->GetWidth() / 2, 600 - alienTex->GetHeight() / 2);
	spriteArray->Last()->SetFPS(16);
	spriteArray->Last()->SetScale(4, 4);
#endif
#pragma endregion

#pragma region Practica 5-2 INIT
#ifdef P5_2
	int32 mouseX, mouseY;
	String *fileName = new String();
	*fileName = "data/animation.xml";
	SkeletonSprite *skeleton = new SkeletonSprite(*fileName);
	skeleton->SetBlendMode(Renderer::ALPHA);
	skeleton->SetFPS(32);
#endif
#pragma endregion

#pragma region Practica 6 INIT
#ifdef P6
	String *fileName = new String();
	*fileName = "../data/arial16.png";
	String *text = new String();
	Font *font = ResourceManager::Instance().LoadFont(*fileName);
	*text = "Hola, Mundo";
	double speedX, speedY;
	speedX = rand() % 127 + 128;
	speedY = rand() % 127 + 128;
	double x, y;
	x = y = 0;
	uint16 r, g, b, a;
	r = g = b = 255;
#endif
#pragma endregion 

#pragma region Practica 7 INIT
#ifdef P7_1

#endif
#pragma endregion

	while (Screen::Instance().IsOpened() && !Screen::Instance().KeyPressed(GLFW_KEY_ESC)) {

#pragma region Practica 1 
#ifdef P1
		angle++;
		angle = WrapValue(angle, 360); //wrap counter between [0,360)
		centerHeight = Screen::Instance().GetHeight() / 2; //calc Vertical center of viewPort
		centerWidth = Screen::Instance().GetWidth() / 2; //calc Horizontal center of viewPort
		mouseY = Screen::Instance().GetMouseY(); //get mouse position X
		mouseX = Screen::Instance().GetMouseX(); //get mouse position Y

		circleCenterY = Screen::Instance().GetMouseY()+(20*DegSin(angle)*-1); //calc center Y of circle orbiting square
		circleCenterX = Screen::Instance().GetMouseX() +(20*DegCos(angle)); //calc center X of circle orbiting square
		
		*title = "Angle: ";
		trueAngle = Angle(mouseX, mouseY, circleCenterX, circleCenterY);
		*title += String::FromInt(trueAngle);
		*title += "º-Distance: ";
		distance = Distance(centerWidth, centerHeight, mouseX, mouseY);
		*title += String::FromInt(distance);
		
		Screen::Instance().SetTitle(*title);

		Renderer::Instance().SetColor(255,0,0,0);
		Renderer::Instance().DrawRect(centerWidth - 10, centerHeight - 10,20,20);
		
		Renderer::Instance().SetColor(0, 255, 0, 0);
		Renderer::Instance().DrawRect(mouseX - 5, mouseY - 5, 10, 10);
		
		Renderer::Instance().SetColor(0, 0, 255, 0);
		Renderer::Instance().DrawEllipse(circleCenterX, circleCenterY, 5, 5);

		// Refrescamos la pantalla
		Screen::Instance().Refresh();
		Renderer::Instance().Clear(0, 0, 0);
#endif
#pragma endregion

#pragma region Practica 2
#ifdef P2
	scale += ((2 * increment) * Screen::Instance().ElapsedTime());
	rotation += (30 * Screen::Instance().ElapsedTime());
	if (scale >= 5) {
		increment = -1;
	}
	else if (scale <= 0.5) {
		increment = 1;
	}
	Renderer::Instance().DrawImage(ballTex, Screen::Instance().GetMouseX(), Screen::Instance().GetMouseY(),0, ballTex->GetWidth()*scale, ballTex->GetHeight()*scale,rotation);
#endif
#pragma endregion

#pragma region Practica 3-1
#ifdef P3_1
	Renderer::Instance().SetBlendMode(Renderer::SOLID);
	Renderer::Instance().SetColor(255, 255, 255, 255);
	Renderer::Instance().DrawRect(thirdOfWidth, 0, thirdOfWidth, Screen::Instance().GetHeight());
	//SOLID
		//RED
	Renderer::Instance().SetColor(255, 0, 0, 255);
	Renderer::Instance().DrawEllipse(3 * sixthdOfWidth, eighthOfHeight, 37, 37);
		//GREEN
	Renderer::Instance().SetColor(0, 255, 0, 255);
	Renderer::Instance().DrawEllipse(3 * sixthdOfWidth-18, eighthOfHeight + 37, 37, 37);
		//BLUE
	Renderer::Instance().SetColor(0, 0, 255, 255);
	Renderer::Instance().DrawEllipse(3 * sixthdOfWidth + 18, eighthOfHeight + 37, 37, 37);
	//ALPHA
	Renderer::Instance().SetBlendMode(Renderer::ALPHA);
		//RED
	Renderer::Instance().SetColor(255, 0, 0, 255);
	Renderer::Instance().DrawEllipse(sixthdOfWidth, 4*eighthOfHeight-37, 37, 37);
		//GREEN
	Renderer::Instance().SetColor(0, 255, 0, 128);
	Renderer::Instance().DrawEllipse(sixthdOfWidth - 18, 4 * eighthOfHeight, 37, 37);
		//BLUE
	Renderer::Instance().SetColor(0, 0, 255, 128);
	Renderer::Instance().DrawEllipse(sixthdOfWidth + 18, 4 * eighthOfHeight, 37, 37);
	//MULTIPLICATIVE
	Renderer::Instance().SetBlendMode(Renderer::MULTIPLICATIVE);
		//RED
	Renderer::Instance().SetColor(255, 0, 0, 255);
	Renderer::Instance().DrawEllipse(3*sixthdOfWidth, 7 * eighthOfHeight-37, 37, 37);
		//GREEN
	Renderer::Instance().SetColor(0, 255, 0, 255);
	Renderer::Instance().DrawEllipse(3*sixthdOfWidth - 18, 7 * eighthOfHeight, 37, 37);
		//BLUE
	Renderer::Instance().SetColor(0, 0, 255, 255);
	Renderer::Instance().DrawEllipse(3*sixthdOfWidth + 18, 7 * eighthOfHeight , 37, 37);
	//ADDITIVE
	Renderer::Instance().SetBlendMode(Renderer::ADDITIVE);
		//RED
	Renderer::Instance().SetColor(255, 0, 0, 255);
	Renderer::Instance().DrawEllipse(5*sixthdOfWidth, 4 * eighthOfHeight-37, 37, 37);
		//GREEN
	Renderer::Instance().SetColor(0, 255, 0, 255);
	Renderer::Instance().DrawEllipse(5 * sixthdOfWidth - 18, 4 * eighthOfHeight, 37, 37);
		//BLUE
	Renderer::Instance().SetColor(0, 0, 255, 255);
	Renderer::Instance().DrawEllipse(5 * sixthdOfWidth + 18, 4 * eighthOfHeight , 37, 37);
#endif
#pragma endregion

#pragma region Practica 3-2
#ifdef P3_2
		Renderer::Instance().SetBlendMode(Renderer::SOLID);
		for (unsigned int x = 0; x < 8; x++)
		{
			for (unsigned int y = 0; y < 8; y++)
			{
				Renderer::Instance().SetBlendMode(Renderer::SOLID);
				Renderer::Instance().DrawImage(boxTex, (eighthOfWidth*x) + 20, (eighthOfHeight*y) + 5);
				switch (x) {
				case 0:
					switch (y) {
					case 0:
						glBlendFunc(GL_ZERO, GL_ZERO);
						break;
					case 1:
						glBlendFunc(GL_ZERO, GL_ONE);
						break;
					case 2:
						glBlendFunc(GL_ZERO, GL_SRC_COLOR);
						break;
					case 3:
						glBlendFunc(GL_ZERO, GL_DST_COLOR);
						break;
					case 4:
						glBlendFunc(GL_ZERO, GL_ONE_MINUS_SRC_COLOR);
						break;
					case 5:
						glBlendFunc(GL_ZERO, GL_ONE_MINUS_DST_COLOR);
						break;
					case 6:
						glBlendFunc(GL_ZERO, GL_SRC_ALPHA);
						break;
					case 7:
						glBlendFunc(GL_ZERO, GL_ONE_MINUS_SRC_ALPHA);
						break;
					}
					break;
				case 1:
					switch (y) {
					case 0:
						glBlendFunc(GL_ONE, GL_ZERO);
						break;
					case 1:
						glBlendFunc(GL_ONE, GL_ONE);
						break;
					case 2:
						glBlendFunc(GL_ONE, GL_SRC_COLOR);
						break;
					case 3:
						glBlendFunc(GL_ONE, GL_DST_COLOR);
						break;
					case 4:
						glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_COLOR);
						break;
					case 5:
						glBlendFunc(GL_ONE, GL_ONE_MINUS_DST_COLOR);
						break;
					case 6:
						glBlendFunc(GL_ONE, GL_SRC_ALPHA);
						break;
					case 7:
						glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
						break;
					}
					break;
				case 2:
					switch (y) {
					case 0:
						glBlendFunc(GL_SRC_COLOR, GL_ZERO);
						break;
					case 1:
						glBlendFunc(GL_SRC_COLOR, GL_ONE);
						break;
					case 2:
						glBlendFunc(GL_SRC_COLOR, GL_SRC_COLOR);
						break;
					case 3:
						glBlendFunc(GL_SRC_COLOR, GL_DST_COLOR);
						break;
					case 4:
						glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR);
						break;
					case 5:
						glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_DST_COLOR);
						break;
					case 6:
						glBlendFunc(GL_SRC_COLOR, GL_SRC_ALPHA);
						break;
					case 7:
						glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA);
						break;
					}
					break;
				case 3:
					switch (y) {
					case 0:
						glBlendFunc(GL_DST_COLOR, GL_ZERO);
						break;
					case 1:
						glBlendFunc(GL_DST_COLOR, GL_ONE);
						break;
					case 2:
						glBlendFunc(GL_DST_COLOR, GL_SRC_COLOR);
						break;
					case 3:
						glBlendFunc(GL_DST_COLOR, GL_DST_COLOR);
						break;
					case 4:
						glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_SRC_COLOR);
						break;
					case 5:
						glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_DST_COLOR);
						break;
					case 6:
						glBlendFunc(GL_DST_COLOR, GL_SRC_ALPHA);
						break;
					case 7:
						glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA);
						break;
					}
					break;
				case 4:
					switch (y) {
					case 0:
						glBlendFunc(GL_ONE_MINUS_SRC_COLOR, GL_ZERO);
						break;
					case 1:
						glBlendFunc(GL_ONE_MINUS_SRC_COLOR, GL_ONE);
						break;
					case 2:
						glBlendFunc(GL_ONE_MINUS_SRC_COLOR, GL_SRC_COLOR);
						break;
					case 3:
						glBlendFunc(GL_ONE_MINUS_SRC_COLOR, GL_DST_COLOR);
						break;
					case 4:
						glBlendFunc(GL_ONE_MINUS_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR);
						break;
					case 5:
						glBlendFunc(GL_ONE_MINUS_SRC_COLOR, GL_ONE_MINUS_DST_COLOR);
						break;
					case 6:
						glBlendFunc(GL_ONE_MINUS_SRC_COLOR, GL_SRC_ALPHA);
						break;
					case 7:
						glBlendFunc(GL_ONE_MINUS_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA);
						break;
					}
					break;
				case 5:
					switch (y) {
					case 0:
						glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
						break;
					case 1:
						glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE);
						break;
					case 2:
						glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_SRC_COLOR);
						break;
					case 3:
						glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_DST_COLOR);
						break;
					case 4:
						glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE_MINUS_SRC_COLOR);
						break;
					case 5:
						glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE_MINUS_DST_COLOR);
						break;
					case 6:
						glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_SRC_ALPHA);
						break;
					case 7:
						glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA);
						break;
					}
					break;
				case 6:
					switch (y) {
					case 0:
						glBlendFunc(GL_SRC_ALPHA, GL_ZERO);
						break;
					case 1:
						glBlendFunc(GL_SRC_ALPHA, GL_ONE);
						break;
					case 2:
						glBlendFunc(GL_SRC_ALPHA, GL_SRC_COLOR);
						break;
					case 3:
						glBlendFunc(GL_SRC_ALPHA, GL_DST_COLOR);
						break;
					case 4:
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_COLOR);
						break;
					case 5:
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);
						break;
					case 6:
						glBlendFunc(GL_SRC_ALPHA, GL_SRC_ALPHA);
						break;
					case 7:
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						break;
					}
					break;
				case 7:
					switch (y) {
					case 0:
						glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ZERO);
						break;
					case 1:
						glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE);
						break;
					case 2:
						glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_COLOR);
						break;
					case 3:
						glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_DST_COLOR);
						break;
					case 4:
						glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE_MINUS_SRC_COLOR);
						break;
					case 5:
						glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);
						break;
					case 6:
						glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);
						break;
					case 7:
						glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						break;
					}
					break;
				}
				Renderer::Instance().DrawImage(lightTex, (eighthOfWidth*x) + 20, (eighthOfHeight*y) + 5);
			}
		}
#endif
#pragma endregion

#pragma region Practica 4-1
#ifdef P4_1
		for (unsigned int i = 0; i < spriteArray->Size(); i++){
			currentSprite = (*spriteArray)[i];
			userData = static_cast<spriteSpeed *>(currentSprite->GetUserData());
			incX = userData->x*Screen::Instance().ElapsedTime();
			incY = userData->y*Screen::Instance().ElapsedTime();
			if ((currentSprite->GetX() + incX) + (currentSprite->GetImage()->GetWidth() / 2)>Screen::Instance().GetWidth() || (currentSprite->GetX() + incX) - (currentSprite->GetImage()->GetWidth() / 2) < 0) {
				currentSprite->SetX(currentSprite->GetX() + (incX*-1));
				userData->x = userData->x*-1;
			}
			else {
				currentSprite->SetX(currentSprite->GetX() + incX);
			}
			if ((currentSprite->GetY() + incY) + (currentSprite->GetImage()->GetHeight() / 2) > Screen::Instance().GetHeight() || (currentSprite->GetY() + incY) - (currentSprite->GetImage()->GetHeight() / 2) < 0) {
				currentSprite->SetY(currentSprite->GetY() + (incY*-1));
				userData->y = userData->y*-1;
			}
			else {
				currentSprite->SetY(currentSprite->GetY() + incY);
			}
			currentSprite->Render();
		}
#endif
#pragma endregion

#pragma region Practica 4-2
#ifdef P4_2
		mouseX = Screen::Instance().GetMouseX();
		mouseY = Screen::Instance().GetMouseY();
		
		for (unsigned int i = 0; i < spriteArray->Size(); i++) {
				currentSprite = (*spriteArray)[i];
				currentSprite->MoveTo(mouseX, mouseY, 100+(i*100));
		
				if (currentSprite->GetX() == mouseX && currentSprite->GetY() == mouseY) {
					currentSprite->RotateTo(0, 30);
				}
				else {
					if (currentSprite->GetX() < mouseX) {
						currentSprite->RotateTo(-15, 30);
					}
					else {
						currentSprite->RotateTo(15, 30);
					}
				}
		
				currentSprite->Update(Screen::Instance().ElapsedTime());
				currentSprite->Render();
		}
#endif
#pragma endregion

#pragma region Practica 5-1
#ifdef P5_1 
mouseX = Screen::Instance().GetMouseX();
mouseY = Screen::Instance().GetMouseY();

for (unsigned int i = 0; i < spriteArray->Size(); i++) {
		currentSprite = (*spriteArray)[i];
		currentSprite->MoveTo(mouseX, mouseY, 100+(i*100));

		if (currentSprite->GetX() == mouseX && currentSprite->GetY() == mouseY) {
			currentSprite->RotateTo(0, 30);
		}
		else {
			if (currentSprite->GetX() < mouseX) {
				currentSprite->RotateTo(-15, 30);
			}
			else {
				currentSprite->RotateTo(15, 30);
			}
		}

		currentSprite->Update(Screen::Instance().ElapsedTime());
		currentSprite->Render();
}
#endif
#pragma endregion

#pragma region Practica 5-2
#ifdef P5_2
	mouseX = Screen::Instance().GetMouseX();
	mouseY = Screen::Instance().GetMouseY();
	skeleton->SetPosition(mouseX, mouseY);
	skeleton->Update(Screen::Instance().ElapsedTime());
	skeleton->Render();
#endif
#pragma endregion

#pragma region Practica 6
#ifdef P6
		x += speedX*Screen::Instance().ElapsedTime();
		y += speedY*Screen::Instance().ElapsedTime();
		if (x + font->GetTextWidth(*text) > Screen::Instance().GetWidth()) {
			x = Screen::Instance().GetWidth() - font->GetTextWidth(*text);
			speedX *= -1;
			r = rand() % 255;
			g = rand() % 255;
			b = rand() % 255;
		}
		else if(x<=0) {
			x =0;
			speedX *= -1;
			r = rand() % 255;
			g = rand() % 255;
			b = rand() % 255;
		}
		if ( y + font->GetTextHeight(*text) >= Screen::Instance().GetHeight()) {
			y = Screen::Instance().GetHeight() - font->GetTextHeight(*text);
			speedY *= -1;
			r = rand() % 255;
			g = rand() % 255;
			b = rand() % 255;
		}
		else if (y <= 0) {
			y = 0;
			speedY *= -1;
			r = rand() % 255;
			g = rand() % 255;
			b = rand() % 255;
		}
		Renderer::Instance().SetColor(r, g, b, 225);
		Renderer::Instance().DrawText(font, *text, x, y);
#endif
#pragma endregion

#pragma region Practica 7-1
#ifdef P7_1

#endif
#pragma endregion
		// Refrescamos la pantalla
		Screen::Instance().Refresh();
		Renderer::Instance().Clear(0, 0, 0);
	}

	ResourceManager::Instance().FreeResources();
	//delete(title);
	/*for (unsigned int i = 0; i < spriteArray->Size(); i++) {
		delete((*spriteArray)[i]->GetUserData());
		(*spriteArray)[i]->SetUserData(nullptr);
	}*/
	return 0;
}
