#define STB_IMAGE_WRITE_IMPLEMENTATION

//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <iostream>
//#include <stb_image_write.h>
#include <glm/glm.hpp>

std::list<int> task3_1(int c);
void print_task3_1(std::list<int> sol);
void task3_2(int x, int y);
std::vector<int> gen_img(int x, int y);
glm::dvec2 gen_vec(int xpos, int ypos, int xres, int yres);

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
	
	for (std::vector<int>::iterator it = img.begin(); it != img.end(); it++) {
		int xpos = std::distance(img.begin(), it) % xres;
		int ypos = std::distance(img.begin(), it) / yres;
		std::cout << xpos << ", " << ypos << std::endl;
		std::cout << gen_vec(xpos, ypos, xres, yres)[0] << ", " << gen_vec(xpos, ypos, xres, yres)[1] << std::endl;
	}
}

glm::dvec2 gen_vec(int xpos, int ypos, int xres, int yres)
{
	glm::dvec2 v1 = glm::dvec2(-(ypos - (2 / 8) * yres), xpos - (1 / 5) * xres);
	glm::dvec2 v2 = glm::dvec2(ypos - (5 / 8) * yres, -(xpos - (7 / 10)*xres));
	return ( ( (v1) / (glm::abs(v1)*glm::abs(v1)) ) + ( (v2) / (glm::abs(v2)*glm::abs(v2)) ) ) / 
			glm::abs( ( (v1) / (glm::abs(v1)*glm::abs(v1)) ) + ( (v2) / (glm::abs(v2)*glm::abs(v2)) ) );
	// IND means floating point exceeded
	// check formula --> alternitives to glm?
}


std::vector<int> gen_img(int x, int y)
{
	std::vector<int> img;
	img.assign(x*y, 0);

	std::srand(std::time(0));
	std::cout << x << ", " << y << ", " << img.size() << std::endl;

	for (std::vector<int>::iterator it = img.begin(); it != img.end(); it++) {
		int random = std::rand() % 2;
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