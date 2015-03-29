#include "stdafx.h"
#include "Vista.h"


Vista::Vista()
{
	/*************************************************************/
	/* Parte SDL												 */
	/*************************************************************/

	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return;
	}
	IMG_Init(IMG_INIT_PNG);
	
	SDL_Window *win = SDL_CreateWindow("Mortal Fighter", 100, 100, Parser::getInstancia().getVentana().getAnchoPx(), Parser::getInstancia().getVentana().getAltoPx(), SDL_WINDOW_SHOWN);
	if (win == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return;
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr){
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return;
	}

	std::string imagePath = "The_Pit_II_2.png";
	SDL_Surface *png = IMG_Load(imagePath.c_str());
	if (png == nullptr){
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "IMG_Load Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return;
	}

	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, png);
	SDL_FreeSurface(png);
	if (tex == nullptr){
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return;
	}

	SDL_RenderClear(ren);
	SDL_RenderCopy(ren, tex, NULL, NULL);
	SDL_RenderPresent(ren);

	SDL_Delay(2000);

	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);

	IMG_Quit();
	SDL_Quit();

}


Vista::~Vista()
{
}
