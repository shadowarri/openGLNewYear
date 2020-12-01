/*
 * main.cc
 *
 *  Created on: 16 нояб. 2020 г.
 *      Author: work
 */
#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>


#include "GameWindow.h"


int main (int, char **)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	try {

		GameWindow w;

		w.main_loop();

	} catch (std::exception & e) {
		std::cerr << "Произошла ошибка при выполнении программы:"
				<< std::endl
				<< e.what()
				<< std::endl;
		return 1;
	} catch (...) {
		std::cerr << "Произошла неизвестная ошибка!" << std::endl;
		return 1;
	}

	return 0;
}



