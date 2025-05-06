#include "Player.h"
#include"TextureManager.h"
#define HEIGHT 600
#define WIDTH 800
#include<iostream>
using namespace std;

void Player::Render(SDL_Renderer* ren)
{
	animationTimer++;

	if (animationTimer < 16)
	{
		SDL_RenderCopyEx(ren, getTexture(), &getSrc(), &getDest(), 0, nullptr, SDL_FLIP_NONE);  // anh 1
	}
	else if (animationTimer >= 16 && animationTimer <= 32)
	{
		SDL_RenderCopyEx(ren, Tex1, &getSrc(), &getDest(), 0, nullptr, SDL_FLIP_NONE); //anh 2
	}
	else if (animationTimer > 32)
	{
		SDL_RenderCopyEx(ren, Tex2, &getSrc(), &getDest(), 0, nullptr, SDL_FLIP_NONE); //anh 3
	}
	if (animationTimer > 48)
	{
		animationTimer = 0;
	}
}

void Player::reset() {
    setSrc(0, 0, 32,24 );  // con chim lay ra tu anh
    setDest(25, HEIGHT / 3, 38,28 );  // con chim hien trong game
        inJump = false;

    accelerator = 0;
    jumpHeight = -6;  //tốc độ bay
    Ypos = HEIGHT / 3;
    jumpTimer = 0;
    lastJump = 0;
    animationTimer = 0;

}

void Player::Gravity()
{
	if (JumpState())
	{

		accelerator = accelerator + 0.07;
		jumpHeight = jumpHeight + gravity;
		Ypos = Ypos + gravity + accelerator + jumpHeight;
		setDest(25, Ypos,38 , 28);
		if (jumpHeight > 0)
		{
			inJump = false;
			jumpHeight = -6;
		}
	}
	else
	{

		accelerator = accelerator + 0.07;

		Ypos = Ypos + gravity + accelerator;
		setDest(25, Ypos, 38, 28);
	}
//	cerr << jumpHeight<< ", "<<Ypos<<endl;

}

void Player::Jump()
{
	if (jumpTimer - lastJump > 180)
	{
		accelerator = 0;

		inJump = true;
		lastJump = jumpTimer;
	}
	else
	{
		Gravity();
	}
}

void Player::GetJumpTime()
{
	jumpTimer = SDL_GetTicks();
}

bool Player::JumpState()
{
	return inJump;
}


void Player::CreateTexture1(const char* address, SDL_Renderer* ren)
{
	Tex1 = TextureManager::Texture(address, ren);
}

void Player::CreateTexture2(const char* address, SDL_Renderer* ren)
{
	Tex2 = TextureManager::Texture(address, ren);
}
