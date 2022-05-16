#include "terrain.h"

/**
 * _atoi - convierte string a entero
 * @s: the string
 * Return: entero
 */
int _atoi(char *s)
{
	int i, integer, sign = 1;

	i = 0;
	integer = 0;

	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		integer = (integer * 10) + (sign * (s[i] - '0'));
		i++;
	}
	return (integer);
}

/**
 * _strdup - copia string en un espacio de memoria nuevo
 * @str: string a copiar
 * Return: copia de string
 */
char *_strdup(char *str)
{
	int i, l;
	char *new;

	if (!str)
	{
		return (0);
	}
	for (l = 0; str[l] != '\0';)
	{
		l++;
	}
	new = malloc(sizeof(char) * l + 1);
	if (!new)
	{
		return (0);
	}
	for (i = 0; i < l; i++)
	{
		new[i] = str[i];
	}
	new[l] = str[l];
	return (new);
}

/**
 * splitstring - crea un arreglo de palabras de un string
 * @str: string
 * @delim: delimitador
 * Return: arreglo de palabras
 */
char **splitstring(char *str, const char *delim)
{
	int i, wn;
	char **array;
	char *token;
	char *copy;

	copy = _strdup(str);

	token = strtok(copy, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = _strdup(token);

	i = 1;
	wn = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		array = realloc(array, (sizeof(char *) * wn));
		array[i] = _strdup(token);
		i++;
		wn++;
	}
	free(copy);
	return (array);
}

/**
 * freearv - libera la memoria del arreglo de palabras
 *@arv: arreglo
 */

void freearv(char **arv)
{
	int i;

	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
}

/**
 * get_altitudes - lee el archivo de altitudes
 * guarda las altitudes en un arrelgo 2D de enteros
 * @argv: arreglo de enteros
 * Return: arreglo de enteros 2D
 */
int **get_altitudes(char **argv)
{
	char buffer[1024];
	char **lines;
	char **chars[8];
	int **numbers;
	int fd, i, j;

	fd = open(argv[1], O_RDWR);
	read(fd, buffer, 1023);
	close(fd);

	numbers = malloc(sizeof(int *) * 8);
	for (i = 0; i < 8; i++)

		numbers[i] = malloc(sizeof(int) * 8);
	lines = splitstring(buffer, "\n");

	for (i = 0; lines[i]; i++)
	{
		chars[i] = splitstring(lines[i], " ");
	}

	for (j = 0; j < 8; j++)
	{
		for (i = 0; i < 8; i++)
		{
			numbers[j][i] = _atoi(chars[j][i]);
		}
	}

	freearv(lines);
	for (i = 0; i < 8; i++)
		freearv(chars[i]);

	return (numbers);
}
