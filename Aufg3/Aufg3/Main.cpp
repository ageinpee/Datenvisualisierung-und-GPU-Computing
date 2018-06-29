#define STB_IMAGE_WRITE_IMPLEMENTATION

//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "vector.h"
#include mpi.h
#include <stb_image_write.h>

std::list<int> task3_1(int c);
void print_task3_1(std::list<int> sol);
void task3_2(int x, int y);
std::vector<int> gen_img(int x, int y);
void integrate(VectorField field, Vector start, int value, int visited, bool direction,
	int xres, int yres, std::vector<int> img);

int main()
{
	char cmdin = '0';
	int num = 0;

	while (cmdin != 'q') {
		std::cout << "Druecke q zum beenden." << std::endl;
		std::cout << "Druecke a um Aufg 1 zu starten." << std::endl;
		std::cout << "Druecke b um Aufg 2 zu starten." << std::endl;
		std::cin >> cmdin;
		if (cmdin == 'a') {
			//lese Datei und führe encrypt auf ihr aus
			std::cout << "-----------------------------------------------" << std::endl;
			std::cout << "Gebe eine Zahl c ein fuer die Formel x+y+z=c:" << std::endl;
			std::cin >> num;
			print_task3_1(task3_1(num));
			std::cout << "-----------------------------------------------" << std::endl;
		} else if (cmdin == 'b') {
			std::cout << "-----------------------------------------------" << std::endl;
			task3_2(100, 100);
		}
	}
	return 0;
}

void task3_2(int xres, int yres) 
{
	std::vector<int> img = gen_img(xres, yres);
	std::vector<int> img_out = gen_img(xres, yres);
	VectorField vecs((double)xres, (double)yres);

	for (std::vector<int>::iterator it = img.begin(); it != img.end(); it++) {
		int xpos = std::distance(img.begin(), it) % xres;
		int ypos = std::distance(img.begin(), it) / yres;

		//std::cout << vecs.vector_at(xpos, ypos).x << ", " << vecs.vector_at(xpos, ypos).y << std::endl;

		int value = img[xres*xpos + ypos];
		int visited = 1;
		Vector start(xpos + 0.5, ypos + 0.5);

		integrate(vecs, start, value, visited, true, //true = direction-->forward
			xres, yres, img);
		integrate(vecs, start, value, visited, false, //false = direction-->backwards
			xres, yres, img);

		//std::cout << img[*it] << ", " << value / visited << std::endl;
		img_out[xres*xpos + ypos] = value / visited;
	}
	
	std::string name = "LIC.bmp";
	stbi_write_bmp(name.c_str(), xres, yres, 1, img_out.data());
}

void integrate(VectorField field, Vector start, int value, int visited, bool direction,
				 int xres, int yres, std::vector<int> img) {
	Vector current = start;

	for (int i = 0; i < 50; i++) {
		if (direction) {
			current = current + field.vector_at(current).with_len(0.5);
		}
		else {
			current = current - field.vector_at(current).with_len(0.5);
		}
	}

	if (current.x >= 0 && current.x < xres && current.y >= 0 && current.y < yres) {
		value += img[(xres-1)*current.x + current.y];
		visited++;
	}
}

std::vector<int> gen_img(int x, int y)
{
	std::vector<int> img;
	img.assign(x*y, 0);

	std::srand(std::time(0));

	for (std::vector<int>::iterator it = img.begin(); it != img.end(); it++) {
		int random = (std::rand() % 2) * 255;
		std::cout << random << std::endl;
		*it = random;
	}
	return img;
}

std::list<int> task3_1(int c) 
{
	std::list<int> solutions;

	for (int i = 0; i <= c; i++) {
		for (int j = 0; j <= c - i; j++) {
			for (int k = 0; k <= c - i - j; k++) {
				if (i + j + k == c) {
					solutions.push_back(i);
					solutions.push_back(j);
					solutions.push_back(k);
				}
			}
		}
	}
	return solutions;
}

void print_task3_1(std::list<int> sol) {
std::cout << "x y z" << std::endl;
	for (std::list<int>::iterator it = sol.begin(); it != sol.end(); it++) {
		std::cout << *it << ' ';
		int count = std::distance(sol.begin(), it)+1;
		if (count % 3 == 0 && count != 0) {
			std::cout << std::endl;
		}
	}
}