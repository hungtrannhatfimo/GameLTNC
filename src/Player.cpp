#include "Player.h"
#include"TextureManager.h"
#define HEIGHT 600
#define WIDTH 800
#include<iostream>
// Inside Player class


void Player::Render(SDL_Renderer* ren)
{
	animationTimer++;

//	if (animationTimer >= 16) {
//        currentFrame = (currentFrame + 1) % clips.size();
//        animationTimer = 0;
//	}
//
//	SDL_Rect srcRect = clips[currentFrame];
//    SDL_Rect destRect = getDest();
//
//	SDL_RenderCopyEx(ren, texture, &srcRect, &destRect, 0 , nullptr, SDL_FLIP_NONE);
	if (animationTimer < 16)
	{
		SDL_RenderCopyEx(ren, getTexture(), &getSrc(), &getDest(), 0, nullptr, SDL_FLIP_NONE);
	}
	else if (animationTimer >= 16 && animationTimer <= 32)
	{
		SDL_RenderCopyEx(ren, Tex1, &getSrc(), &getDest(), 0, nullptr, SDL_FLIP_NONE);
	}
	else if (animationTimer > 32)
	{
		SDL_RenderCopyEx(ren, Tex2, &getSrc(), &getDest(), 0, nullptr, SDL_FLIP_NONE);
	}
	if (animationTimer > 48)
	{
		animationTimer = 0;
	}
}

void Player::reset() {
    setSrc(0, 0, 24, 32);
    setDest(25, HEIGHT / 2, 28, 38);
        inJump = false;
    accelerator1 = 0;
    accelerator2 = 0;
    jumpHeight = -6;
    Ypos = HEIGHT / 2;   // match Ypos to center of screen
    jumpTimer = 0;
    lastJump = 0;
    animationTimer = 0;  // optional: reset animation too

}

void Player::Gravity()
{
	if (JumpState())
	{
		accelerator1 = accelerator1 + 0.035;
		accelerator2 = accelerator2 + 0.035;
		jumpHeight = jumpHeight + gravity;
		Ypos = Ypos + gravity + accelerator1 + accelerator2 + jumpHeight;
		setDest(25, Ypos, 28, 38);
		if (jumpHeight > 0)
		{
			inJump = false;
			jumpHeight = -6;
		}
	}
	else
	{

		accelerator1 = accelerator1 + 0.035;
		accelerator2 = accelerator2 + 0.035;
		Ypos = Ypos + gravity + accelerator1 + accelerator2;
		setDest(25, Ypos, 28, 38);
	}

}

void Player::Jump()
{
	if (jumpTimer - lastJump > 180)
	{
		accelerator1 = 0;
		accelerator2 = 0;
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

//bool Player::CreateTexture1(const char* filePath, SDL_Renderer* renderer) {
//    SDL_Texture* texture = IMG_LoadTexture(renderer, filePath);
//    if (!texture) {
//        std::cerr << "Failed to load texture: " << IMG_GetError() << std::endl;
//        return false;  // Return false if loading fails
//    }
//
//    this->texture = texture;  // Assuming this->texture stores the loaded texture
//    return true;  // Return true if loading is successful
//}
//
//bool Player::CreateTexture2(const char* filePath, SDL_Renderer* renderer) {
//    SDL_Texture* texture = IMG_LoadTexture(renderer, filePath);
//    if (!texture) {
//        std::cerr << "Failed to load texture: " << IMG_GetError() << std::endl;
//        return false;  // Return false if loading fails
//    }
//
//    this->texture = texture;  // Assuming this->texture stores the loaded texture
//    return true;  // Return true if loading is successful
//}

void Player::CreateTexture1(const char* address, SDL_Renderer* ren)
{
	Tex1 = TextureManager::Texture(address, ren);
}

void Player::CreateTexture2(const char* address, SDL_Renderer* ren)
{
	Tex2 = TextureManager::Texture(address, ren);
}
