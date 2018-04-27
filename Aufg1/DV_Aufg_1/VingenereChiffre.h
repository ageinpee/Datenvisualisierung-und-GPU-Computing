#pragma once
#include <iostream>
#include <string>
#include <fstream>


class VingenereChiffre
{
public:
	VingenereChiffre();
	~VingenereChiffre();

	char cmdin = '0';
	std::string infile = "";
	std::string key = "Hamburg";
	std::string VingenereQuad[26] = { 
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
		"BCDEFGHIJKLMNOPQRSTUVWXYZA",
		"CDEFGHIJKLMNOPQRSTUVWXYZAB",
		"DEFGHIJKLMNOPQRSTUVWXYZABC",
		"EFGHIJKLMNOPQRSTUVWXYZABCD",
		"FGHIJKLMNOPQRSTUVWXYZABCDE",
		"GHIJKLMNOPQRSTUVWXYZABCDEF",
		"HIJKLMNOPQRSTUVWXYZABCDEFG",
		"IJKLMNOPQRSTUVWXYZABCDEFGH", 
		"JKLMNOPQRSTUVWXYZABCDEFGHI", 
		"KLMNOPQRSTUVWXYZABCDEFGHIJ", 
		"LMNOPQRSTUVWXYZABCDEFGHIJK", 
		"MNOPQRSTUVWXYZABCDEFGHIJKL", 
		"NOPQRSTUVWXYZABCDEFGHIJKLM",
		"OPQRSTUVWXYZABCDEFGHIJKLMN", 
		"PQRSTUVWXYZABCDEFGHIJKLMNO", 
		"QRSTUVWXYZABCDEFGHIJKLMNOP",
		"RSTUVWXYZABCDEFGHIJKLMNOPQ",
		"STUVWXYZABCDEFGHIJKLMNOPQR", 
		"TUVWXYZABCDEFGHIJKLMNOPQRS",
		"UVWXYZABCDEFGHIJKLMNOPQRST", 
		"VWXYZABCDEFGHIJKLMNOPQRSTU", 
		"WXYZABCDEFGHIJKLMNOPQRSTUV", 
		"XYZABCDEFGHIJKLMNOPQRSTUVW", 
		"YZABCDEFGHIJKLMNOPQRSTUVWX",
		"ZABCDEFGHIJKLMNOPQRSTUVWXY" };

	int main() {
		while (cmdin != 'q') {
			std::cout << "Drücke entweder v, e oder q.";
			std::cin >> cmdin;
			if (cmdin == 'e') {

				//lese Datei und führe encrypt auf ihr aus
			}
			else if (cmdin >> cmdin == 'v') {
				//lese Datein und führe decrypt auf ihr aus
			};
		};
		return 0;
	}

protected: 

	std::string encrypt() {

		return "e";
	}
	
	std::string decrypt() {
		return "v";
	}
};