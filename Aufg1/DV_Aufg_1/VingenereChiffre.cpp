#pragma once
#include <iostream>
#include <string>
#include <fstream>

std::string encrypt() {

	return "e";
}

std::string decrypt() {
	return "v";
}

int main() {
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
	
	while (cmdin != 'q') {
		std::cout << "Druecke entweder v, e oder q." << std::endl;
		std::cin >> cmdin;
		if (cmdin == 'e') {
			//lese Datei und führe encrypt auf ihr aus
			std::cout << encrypt() << std::endl;
		}
		else if (cmdin == 'v') {
			//lese Datei und führe decrypt auf ihr aus
			std::cout << decrypt() << std::endl;
		};
	};
	return 0;
}

