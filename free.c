#include "terrain.h"

/**
 * freegrid - libera memoria de un grid
 * @grid: grid a liberar
 */
void freegrid(SDL_Point ***grid)
{
	int k, i;

	for (k = 0; k < 2; k++)
	{
		for (i = 0; i < 8; i++)
		{
			free(grid[k][i]);
		}
		free(grid[k]);
	}
	free(grid);
}

/**
 * freenumbers - libera memoria de un arreglo 2D de numeros
 * @numbers: arreglo 2D de numeros a liberar
 */
void freenumbers(int **numbers)
{
	int i;

	for (i = 0; i < 8; i++)
		free(numbers[i]);
	free(numbers);
}

/**
 * salir - salir del programa y destruir el render
 * @ren: render
 * @win: ventana
 */
void salir(SDL_Renderer *ren, SDL_Window *win)
{
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
