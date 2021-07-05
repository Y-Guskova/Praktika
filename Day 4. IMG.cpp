#include <iostream>

using namespace std; 


//Структура данных для работы с изображением

struct Image 
{
  int mx;
  int my;
  int* points;
}

// Создание изображения 

void createImage(Image* img,int tmx, int tmy)
{
	img->mx = tmx;
	ing->my = tmy;
	int->points = new int[tmx * tmy];
}	

// Отображение изображения на экран в pnm формате 

void showImage(Image* img)
{
	int a;
	for ( int i = 0; i < tmy; i++ )
	{
		for ( int j = 0; j < tmx; j++ )
		{
			a = ( i * tmx + j )
			cout << img->mx[tmx * tmy];
		}
	}
}

// Добавить точки на изображение 

void setPointImage(Image* img,int x, int y,int color)
{
	img->points[(x * tmx + y)] = color;
}

// Получение точки на изображении

int setPointImage1(Image* img,int x, int y,int color)
{
	color = img->points[(x * tmx + y)];
	cout << "Точка (" << x << ", " << y << ") цвета: ";
}

// Отображениие изображения на экран в pnm фформате 

void saveToPnmFile(Image* img, string fileName)
{
	
}

// Тесты

int TestCreateImage(Image* img, int tmx, int tmy)
{
	if ((tmx <= 0) || (tmy <= 0))
	{
		return -1;
	}
	return 0;
}

void TestsetPointImage(Image* img,int x, int y,int color) 
{
	if ((color < 0) || (color > 255))
	{
		return -1;
	}
}

int TestSetPointImage1(Image* img,int x, int y,int color)
{
	if ((x > tmx) || (y > tmy))
	{
		return -1;
	}
}











