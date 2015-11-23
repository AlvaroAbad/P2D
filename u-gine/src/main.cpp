#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "../include/u-gine.h"

int main(int argc, char* argv[]) {
	Screen::Instance().Open(800, 600, false);

#pragma region Practica 1 INIT
	/*int16 centerHeight, centerWidth, mouseX, mouseY, circleCenterX, circleCenterY, trueAngle;
	int16 angle = 0;
	String * title = new String();
	int32 distance;*/
#pragma endregion

#pragma region Practica 2 INIT
		String *fileName = new String();
		*fileName = "../data/soccer_npot.png";
		Image * ballTex=ResourceManager::Instance().LoadImage(*fileName);
		ballTex->SetMidHandle();
		double rotation = 0;
		double scale = 0;
		int increment = 1;
#pragma endregion

#pragma region Practica 3 INIT
	/*uint32 blendModeSRC;
	uint32 blendModeDST;
	String *boxFileName = new String();
	*boxFileName = "data/box.jpg";
	Image * boxTex = ResourceManager::Instance().LoadImage(*boxFileName);
	String *LightFileName = new String();
	*LightFileName = "data/light.png";
	Image * lightTex = ResourceManager::Instance().LoadImage(*LightFileName);
	uint16 thirdOfWidth = Screen::Instance().GetWidth() / 3;
	uint16 eighthOfHeight = Screen::Instance().GetHeight() / 8;
	uint16 sixthdOfWidth = Screen::Instance().GetWidth() / 6;
	uint16 eighthOfWidth = Screen::Instance().GetWidth() / 8;*/
#pragma endregion

	while (Screen::Instance().IsOpened() && !Screen::Instance().KeyPressed(GLFW_KEY_ESC)) {

#pragma region Practica 1 
		//angle++;
		//angle = WrapValue(angle, 360); //wrap counter between [0,360)
		//centerHeight = Screen::Instance().GetHeight() / 2; //calc Vertical center of viewPort
		//centerWidth = Screen::Instance().GetWidth() / 2; //calc Horizontal center of viewPort
		//mouseY = Screen::Instance().GetMouseY(); //get mouse position X
		//mouseX = Screen::Instance().GetMouseX(); //get mouse position Y

		//circleCenterY = Screen::Instance().GetMouseY()+(20*DegSin(angle)*-1); //calc center Y of circle orbiting square
		//circleCenterX = Screen::Instance().GetMouseX() +(20*DegCos(angle)); //calc center X of circle orbiting square
		//
		//*title = "Angle: ";
		//trueAngle = Angle(mouseX, mouseY, circleCenterX, circleCenterY);
		//*title += String::FromInt(trueAngle);
		//*title += "º-Distance: ";
		//distance = Distance(centerWidth, centerHeight, mouseX, mouseY);
		//*title += String::FromInt(distance);
		//
		//Screen::Instance().SetTitle(*title);

		//Renderer::Instance().SetColor(255,0,0,0);
		//Renderer::Instance().DrawRect(centerWidth - 10, centerHeight - 10,20,20);
		//
		//Renderer::Instance().SetColor(0, 255, 0, 0);
		//Renderer::Instance().DrawRect(mouseX - 5, mouseY - 5, 10, 10);
		//
		//Renderer::Instance().SetColor(0, 0, 255, 0);
		//Renderer::Instance().DrawEllipse(circleCenterX, circleCenterY, 5, 5);

		//// Refrescamos la pantalla
		//Screen::Instance().Refresh();
		//Renderer::Instance().Clear(0, 0, 0);
#pragma endregion

#pragma region Practica 2
scale += ((2 * increment) * Screen::Instance().ElapsedTime());
rotation += (30 * Screen::Instance().ElapsedTime());
if (scale >= 5) {
	increment = -1;
}
else if (scale <= 0.5) {
	increment = 1;
}
Renderer::Instance().DrawImage(ballTex, Screen::Instance().GetMouseX(), Screen::Instance().GetMouseY(),0, ballTex->GetWidth()*scale, ballTex->GetHeight()*scale,rotation);
#pragma endregion

#pragma region Practica 3-1
//Renderer::Instance().SetBlendMode(Renderer::SOLID);
//Renderer::Instance().SetColor(255, 255, 255, 255);
//Renderer::Instance().DrawRect(thirdOfWidth, 0, thirdOfWidth, Screen::Instance().GetHeight());
////SOLID
//	//RED
//Renderer::Instance().SetColor(255, 0, 0, 255);
//Renderer::Instance().DrawEllipse(3 * sixthdOfWidth, eighthOfHeight, 37, 37);
//	//GREEN
//Renderer::Instance().SetColor(0, 255, 0, 255);
//Renderer::Instance().DrawEllipse(3 * sixthdOfWidth-18, eighthOfHeight + 37, 37, 37);
//	//BLUE
//Renderer::Instance().SetColor(0, 0, 255, 255);
//Renderer::Instance().DrawEllipse(3 * sixthdOfWidth + 18, eighthOfHeight + 37, 37, 37);
////ALPHA
//Renderer::Instance().SetBlendMode(Renderer::ALPHA);
//	//RED
//Renderer::Instance().SetColor(255, 0, 0, 255);
//Renderer::Instance().DrawEllipse(sixthdOfWidth, 4*eighthOfHeight-37, 37, 37);
//	//GREEN
//Renderer::Instance().SetColor(0, 255, 0, 128);
//Renderer::Instance().DrawEllipse(sixthdOfWidth - 18, 4 * eighthOfHeight, 37, 37);
//	//BLUE
//Renderer::Instance().SetColor(0, 0, 255, 128);
//Renderer::Instance().DrawEllipse(sixthdOfWidth + 18, 4 * eighthOfHeight, 37, 37);
////MULTIPLICATIVE
//Renderer::Instance().SetBlendMode(Renderer::MULTIPLICATIVE);
//	//RED
//Renderer::Instance().SetColor(255, 0, 0, 255);
//Renderer::Instance().DrawEllipse(3*sixthdOfWidth, 7 * eighthOfHeight-37, 37, 37);
//	//GREEN
//Renderer::Instance().SetColor(0, 255, 0, 255);
//Renderer::Instance().DrawEllipse(3*sixthdOfWidth - 18, 7 * eighthOfHeight, 37, 37);
//	//BLUE
//Renderer::Instance().SetColor(0, 0, 255, 255);
//Renderer::Instance().DrawEllipse(3*sixthdOfWidth + 18, 7 * eighthOfHeight , 37, 37);
////ADDITIVE
//Renderer::Instance().SetBlendMode(Renderer::ADDITIVE);
//	//RED
//Renderer::Instance().SetColor(255, 0, 0, 255);
//Renderer::Instance().DrawEllipse(5*sixthdOfWidth, 4 * eighthOfHeight-37, 37, 37);
//	//GREEN
//Renderer::Instance().SetColor(0, 255, 0, 255);
//Renderer::Instance().DrawEllipse(5 * sixthdOfWidth - 18, 4 * eighthOfHeight, 37, 37);
//	//BLUE
//Renderer::Instance().SetColor(0, 0, 255, 255);
//Renderer::Instance().DrawEllipse(5 * sixthdOfWidth + 18, 4 * eighthOfHeight , 37, 37);
#pragma endregion

#pragma region Practica 3-2

		//Renderer::Instance().SetBlendMode(Renderer::SOLID);
		//for (unsigned int x = 0; x < 8; x++)
		//{
		//	for (unsigned int y = 0; y < 8; y++)
		//	{
		//		Renderer::Instance().SetBlendMode(Renderer::SOLID);
		//		Renderer::Instance().DrawImage(boxTex, (eighthOfWidth*x) + 20, (eighthOfHeight*y) + 5);
		//		switch (x) {
		//		case 0:
		//			switch (y) {
		//			case 0:
		//				glBlendFunc(GL_ZERO, GL_ZERO);
		//				break;
		//			case 1:
		//				glBlendFunc(GL_ZERO, GL_ONE);
		//				break;
		//			case 2:
		//				glBlendFunc(GL_ZERO, GL_SRC_COLOR);
		//				break;
		//			case 3:
		//				glBlendFunc(GL_ZERO, GL_DST_COLOR);
		//				break;
		//			case 4:
		//				glBlendFunc(GL_ZERO, GL_ONE_MINUS_SRC_COLOR);
		//				break;
		//			case 5:
		//				glBlendFunc(GL_ZERO, GL_ONE_MINUS_DST_COLOR);
		//				break;
		//			case 6:
		//				glBlendFunc(GL_ZERO, GL_SRC_ALPHA);
		//				break;
		//			case 7:
		//				glBlendFunc(GL_ZERO, GL_ONE_MINUS_SRC_ALPHA);
		//				break;
		//			}
		//			break;
		//		case 1:
		//			switch (y) {
		//			case 0:
		//				glBlendFunc(GL_ONE, GL_ZERO);
		//				break;
		//			case 1:
		//				glBlendFunc(GL_ONE, GL_ONE);
		//				break;
		//			case 2:
		//				glBlendFunc(GL_ONE, GL_SRC_COLOR);
		//				break;
		//			case 3:
		//				glBlendFunc(GL_ONE, GL_DST_COLOR);
		//				break;
		//			case 4:
		//				glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_COLOR);
		//				break;
		//			case 5:
		//				glBlendFunc(GL_ONE, GL_ONE_MINUS_DST_COLOR);
		//				break;
		//			case 6:
		//				glBlendFunc(GL_ONE, GL_SRC_ALPHA);
		//				break;
		//			case 7:
		//				glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
		//				break;
		//			}
		//			break;
		//		case 2:
		//			switch (y) {
		//			case 0:
		//				glBlendFunc(GL_SRC_COLOR, GL_ZERO);
		//				break;
		//			case 1:
		//				glBlendFunc(GL_SRC_COLOR, GL_ONE);
		//				break;
		//			case 2:
		//				glBlendFunc(GL_SRC_COLOR, GL_SRC_COLOR);
		//				break;
		//			case 3:
		//				glBlendFunc(GL_SRC_COLOR, GL_DST_COLOR);
		//				break;
		//			case 4:
		//				glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR);
		//				break;
		//			case 5:
		//				glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_DST_COLOR);
		//				break;
		//			case 6:
		//				glBlendFunc(GL_SRC_COLOR, GL_SRC_ALPHA);
		//				break;
		//			case 7:
		//				glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA);
		//				break;
		//			}
		//			break;
		//		case 3:
		//			switch (y) {
		//			case 0:
		//				glBlendFunc(GL_DST_COLOR, GL_ZERO);
		//				break;
		//			case 1:
		//				glBlendFunc(GL_DST_COLOR, GL_ONE);
		//				break;
		//			case 2:
		//				glBlendFunc(GL_DST_COLOR, GL_SRC_COLOR);
		//				break;
		//			case 3:
		//				glBlendFunc(GL_DST_COLOR, GL_DST_COLOR);
		//				break;
		//			case 4:
		//				glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_SRC_COLOR);
		//				break;
		//			case 5:
		//				glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_DST_COLOR);
		//				break;
		//			case 6:
		//				glBlendFunc(GL_DST_COLOR, GL_SRC_ALPHA);
		//				break;
		//			case 7:
		//				glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA);
		//				break;
		//			}
		//			break;
		//		case 4:
		//			switch (y) {
		//			case 0:
		//				glBlendFunc(GL_ONE_MINUS_SRC_COLOR, GL_ZERO);
		//				break;
		//			case 1:
		//				glBlendFunc(GL_ONE_MINUS_SRC_COLOR, GL_ONE);
		//				break;
		//			case 2:
		//				glBlendFunc(GL_ONE_MINUS_SRC_COLOR, GL_SRC_COLOR);
		//				break;
		//			case 3:
		//				glBlendFunc(GL_ONE_MINUS_SRC_COLOR, GL_DST_COLOR);
		//				break;
		//			case 4:
		//				glBlendFunc(GL_ONE_MINUS_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR);
		//				break;
		//			case 5:
		//				glBlendFunc(GL_ONE_MINUS_SRC_COLOR, GL_ONE_MINUS_DST_COLOR);
		//				break;
		//			case 6:
		//				glBlendFunc(GL_ONE_MINUS_SRC_COLOR, GL_SRC_ALPHA);
		//				break;
		//			case 7:
		//				glBlendFunc(GL_ONE_MINUS_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA);
		//				break;
		//			}
		//			break;
		//		case 5:
		//			switch (y) {
		//			case 0:
		//				glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
		//				break;
		//			case 1:
		//				glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE);
		//				break;
		//			case 2:
		//				glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_SRC_COLOR);
		//				break;
		//			case 3:
		//				glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_DST_COLOR);
		//				break;
		//			case 4:
		//				glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE_MINUS_SRC_COLOR);
		//				break;
		//			case 5:
		//				glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE_MINUS_DST_COLOR);
		//				break;
		//			case 6:
		//				glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_SRC_ALPHA);
		//				break;
		//			case 7:
		//				glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA);
		//				break;
		//			}
		//			break;
		//		case 6:
		//			switch (y) {
		//			case 0:
		//				glBlendFunc(GL_SRC_ALPHA, GL_ZERO);
		//				break;
		//			case 1:
		//				glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		//				break;
		//			case 2:
		//				glBlendFunc(GL_SRC_ALPHA, GL_SRC_COLOR);
		//				break;
		//			case 3:
		//				glBlendFunc(GL_SRC_ALPHA, GL_DST_COLOR);
		//				break;
		//			case 4:
		//				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_COLOR);
		//				break;
		//			case 5:
		//				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);
		//				break;
		//			case 6:
		//				glBlendFunc(GL_SRC_ALPHA, GL_SRC_ALPHA);
		//				break;
		//			case 7:
		//				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//				break;
		//			}
		//			break;
		//		case 7:
		//			switch (y) {
		//			case 0:
		//				glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ZERO);
		//				break;
		//			case 1:
		//				glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE);
		//				break;
		//			case 2:
		//				glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_COLOR);
		//				break;
		//			case 3:
		//				glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_DST_COLOR);
		//				break;
		//			case 4:
		//				glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE_MINUS_SRC_COLOR);
		//				break;
		//			case 5:
		//				glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);
		//				break;
		//			case 6:
		//				glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);
		//				break;
		//			case 7:
		//				glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//				break;
		//			}
		//			break;
		//		}
		//		Renderer::Instance().DrawImage(lightTex, (eighthOfWidth*x) + 20, (eighthOfHeight*y) + 5);

		//	}
		//}

#pragma endregion

		// Refrescamos la pantalla
		Screen::Instance().Refresh();
		Renderer::Instance().Clear(0, 0, 0);
	}
	ResourceManager::Instance().FreeResources();
	//delete(title);
	return 0;
}
