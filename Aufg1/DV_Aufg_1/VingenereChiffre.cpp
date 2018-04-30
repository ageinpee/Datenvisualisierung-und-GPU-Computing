#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

std::string file_input() {
	std::string file_path = "";
	std::string content = "";
	std::cout << "Please enter a filename:" << std::endl;
	std::cin >> file_path;
	std::fstream f(file_path);
	
	if (f.is_open()) {
		std::cout << "-----------------------------------------------" << std::endl;
		content.assign((std::istreambuf_iterator<char>(f)),
			(std::istreambuf_iterator<char>()));
		std::cout << content << std::endl;
	}
	else {
		std::cout << "file could not be found" << std::endl;
	}
	f.close();
	std::transform(content.begin(), content.end(), content.begin(), ::toupper);
	return content;
}

bool file_output(std::string output) {
	std::ofstream f("data_crypt.txt");
	f << output << std::endl;
	f.close();
	return false;
}

//encrypt = verschlüsseln. activated when 'v' is pressed
std::string encrypt(std::string key, std::string quad[]) {
	std::string data = file_input();
	std::string enc_str = "";
	int index_key = 0;

	for (unsigned index_data = 0; index_data < data.length()-1; ++index_data) {
		if (data.at(index_data) == ' ') {
			enc_str += ' ';
		}
		else {
			enc_str += (quad[int(key.at(index_key)) - 65].at(int(data.at(index_data)) - 65));

			index_key += 1;
			if (index_key == key.length()) {
				index_key = 0;
			}
		}
	}
	file_output(enc_str);
	return enc_str;
}

// decrypt = entschlüsseln. activated when 'e' is pressed
std::string decrypt(std::string key, std::string quad[]) {
	std::string data = file_input();
	std::string dec_str = "";
	int index_key = 0;

	for (unsigned index_data = 0; index_data < data.length()-1; ++index_data) {
		if (data.at(index_data) == ' ') {
			dec_str += ' ';
		}
		else {
			std::string row = quad[int(key.at(index_key)) - 65];
			dec_str += (quad[0].at(row.find(data.at(index_data))));
			
			index_key += 1;
			if (index_key == key.length()) {
				index_key = 0;
			}
		}
	}
	return dec_str;
}

int main() {
	char cmdin = '0';
	std::string infile = "";
	std::string key = "HAMBURG";
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
			std::cout << "-----------------------------------------------" << std::endl;
			std::cout << decrypt(key, VingenereQuad) << std::endl;
			std::cout << "-----------------------------------------------" << std::endl;
		}
		else if (cmdin == 'v') {
			//lese Datei und führe decrypt auf ihr aus
			std::cout << "-----------------------------------------------" << std::endl;
			std::cout << encrypt(key, VingenereQuad) << std::endl;
			std::cout << "-----------------------------------------------" << std::endl;
		}
	}
	return 0;
}

