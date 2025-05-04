
#include "Background.h"

void Background::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), nullptr, nullptr);
}

void Background::GroundRender(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}

void Background::GroundUpdate1()
{
	if (distance1 <= -330)
	{
		distance1 = 336;
	}
	else
	{
		distance1--;
		setSrc(0, 0, 336,112 );
		setDest(distance1, 420, 336,112 );
	}
}

void Background::GroundUpdate2()
{
	if (distance2 <= -330)
	{
		distance2 = 336;
	}
	else
	{
		distance2--;
		setSrc(0, 0, 336, 112);
		setDest(distance2, 420, 336,112 );
	}
}
