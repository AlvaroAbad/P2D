#include "../include/parallaxscene.h"
ParallaxScene::ParallaxScene(Image * imageBack, Image * imageFront) :Scene(imageFront) {
	this->backLayer = imageBack;
	this->frontLayer = imageFront;
	this->backX=0;
	this->backY = 0;
	this->frontX = 0;
	this->frontY = 0;
	this->relBackSpeedX = 0.5;
	this->relBackSpeedY = 0.5;
	this->relFrontSpeedX = 1;
	this->relFrontSpeedY = 1;
	this->autoBackSpeedX = 0.25;
	this->autoBackSpeedY = 0.25;
	this->autoFrontSpeedX = 0.5;
	this->autoFrontSpeedY = 0.5;
}
void ParallaxScene::Update(double elapsed, Map * map){
	Scene::Update(elapsed, map);
}
void ParallaxScene::RenderBackground() const{
}