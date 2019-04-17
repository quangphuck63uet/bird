#include<SDL.h>

void applyIMG(SDL_Surface* surface, SDL_Surface* IMG, SDL_Rect* rect)
{
	SDL_BlitSurface(IMG, NULL, surface, rect);

}

void flydown(SDL_Surface* surface, SDL_Surface* IMG, SDL_Rect* rect, SDL_Window* window,SDL_Surface* font)
{
	SDL_Rect zore ;
	zore.x = 0;
	zore.y = 0;
	rect->y = rect->y + 5;
	applyIMG(surface, font, &zore);
	applyIMG(surface, IMG, rect);
	SDL_UpdateWindowSurface(window);
}

void flyup(SDL_Surface* surface, SDL_Surface* IMG, SDL_Rect *rect, SDL_Window* window, SDL_Surface* font)
{
	SDL_Rect zore;
	zore.x = 0;
	zore.y = 0;
	rect->y=rect->y-20;
	applyIMG(surface, font, &zore);
	applyIMG(surface, IMG, rect);
	SDL_UpdateWindowSurface(window);
	SDL_Delay(50);
}


int main(int argc, char* argv[])
{
	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL;
	SDL_Surface* IMG = NULL;
	SDL_Surface* font = NULL;
	SDL_Event e;
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;

	window = SDL_CreateWindow("flydown", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1330, 540, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);
	IMG = SDL_LoadBMP("Untitled1.bmp");
	font = SDL_LoadBMP("ece67cbf-2b51-4474-b2e5-2ce06e7c542d1.bmp");
	int t = 0;
	while (t < 5000) {
		if (SDL_PollEvent(&e) != 0) {
			//User presses a key
			if (e.type == SDL_KEYDOWN)
			{
				//Select surfaces based on key press
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					flyup(surface, IMG, &rect, window, font);
					break;
				}
			}
		}
		else
		{
			flydown(surface, IMG, &rect, window, font);
			SDL_Delay(10);
		}
		SDL_Delay(50);
	}


	return 0;
}
