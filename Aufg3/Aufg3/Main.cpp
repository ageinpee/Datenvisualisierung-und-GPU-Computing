#define STB_IMAGE_WRITE_IMPLEMENTATION

//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
#include <string>
#include <list>
#include <iostream>
#include <stb_image_write.h>
//#include <glm/glm.hpp>

std::list<int> task3_1(int c);
void print_task3_1(std::list<int> sol);
void test3_2(int x, int y);

int main()
{
	char cmdin = '0';
	int num = 0;

	while (cmdin != 'q') {
		std::cout << "Druecke q zum beenden. Druecke a Aufg 1 zu starten." << std::endl;
		std::cin >> cmdin;
		if (cmdin == 'a') {
			//lese Datei und führe encrypt auf ihr aus
			std::cout << "-----------------------------------------------" << std::endl;
			std::cout << "Gebe eine Zahl c ein fuer die Formel x+y+z=c:" << std::endl;
			std::cin >> num;
			print_task3_1(task3_1(num));
			std::cout << "-----------------------------------------------" << std::endl;
		}
	}
	return 0;
}

void test3_2(int x, int y) 
{
	
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