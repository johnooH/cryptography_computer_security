
//
// lab_Encryption.cpp
//
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

void init_code(map<char, char> &code, map<char, char> &decode);
void encryption(map<char, char>&code, string &message, string &codedMSG);

int main()
{
	map<char, char>
		code,       // use code map to encrypt message
		decode;     // use decode map to decrypt message

	init_code(code, decode);    // populate code and decode keys

								//-------encryption------------------
	string message, codedMSG, decodedMSG;

	do
	{
		cout << "Enter a message ('end' to stop): \n";
		getline(cin, message);
		encryption(code, message, codedMSG);
		cout << "---  coded message: " << codedMSG << endl;

		encryption(decode, codedMSG, decodedMSG);
		cout << "--- decode message: " << decodedMSG << endl;
		cout << endl;

	} while (message != "end");

	system("pause");
	return 0;
}

void encryption(map<char, char>&code, string &message, string &codedMSG)
{
	char en_ch; // ecryption string character
	int mess_size = message.size(); //length of message string
	string temp_string = "";

	for (int i = 0; i < mess_size; i++) {
		en_ch = message[i]; // get character of message string
		temp_string += code.find(en_ch)->second; // set codedMSG to encreypted/decrypted value associated
	}

	codedMSG = temp_string;// copy temp string to codedMSG
}

void init_code(map<char, char> &code, map<char, char> &decode)
{
	map<char, char> key1 = {
		{ ' ', ',' },{ '!', '!' },{ '"', 'X' },{ '#', 'Q' },{ '$', ' ' },
	{ '%', ';' },{ '&', 'D' },{ '\'', 'v' } ,{ '(', ' = ' } ,{ ')', 'M' } ,
	{ '*', 'a' } ,{ '+', 'N' },{ ',', '@' } ,{ '-', 'd' } ,{ '.', 'r' } ,
	{ '/', 'S' },{ '0', ':' },{ '1', 'V' } ,{ '2', 'z' } ,{ '3', '1' } ,
	{ '4', '(' },{ '5', 'O' },{ '6', '6' } ,{ '7', 'B' } ,{ '8', '>' } ,
	{ '9', '\'' },{ ':', '&' },{ ';', 'p' } ,{ '<', 'y' } ,{ '=', '$' } ,
	{ '>', '"' },{ '?', 'T' },{ '@', 'J' } ,{ 'A', 'C' } ,{ 'B', 'c' } ,
	{ 'C', 'Z' },{ 'D', '9' },{ 'E', '#' } ,{ 'F', 'e' } ,{ 'G', '0' } ,
	{ 'H', 'f' },{ 'I', 'E' },{ 'J', '.' } ,{ 'K', '}' } ,{ 'L', '8' } ,
	{ 'M', 'g' },{ 'N', 's' },{ 'O', 'x' } ,{ 'P', '4' } ,{ 'Q', 'h' } ,
	{ 'R', '_' },{ 'S', 'A' },{ 'T', '5' } ,{ 'U', '<' } ,{ 'V', 'I' } ,
	{ 'W', '{' },{ 'X', 't' },{ 'Y', 'm' } ,{ 'Z', 'u' } ,{ '[', ']' } ,
	{ '\\', 'Y' },{ ']', 'n' },{ '^', 'b' } ,{ '_', '*' } ,{ '`', '%' } ,
	{ 'a', '2' },{ 'b', '7' },{ 'c', 'R' } ,{ 'd', 'l' } ,{ 'e', 'i' } ,
	{ 'f', 'j' },{ 'g', '/' },{ 'h', 'w' } ,{ 'i', 'K' } ,{ 'j', '|' } ,
	{ 'k', 'F' },{ 'l', 'H' },{ 'm', 'q' } ,{ 'n', 'W' } ,{ 'o', '`' } ,
	{ 'p', '+' },{ 'q', 'G' },{ 'r', '^' } ,{ 's', 'U' } ,{ 't', ')' } ,
	{ 'u', '[' },{ 'v', '?' },{ 'w', 'L' } ,{ 'x', '3' } ,{ 'y', 'o' } ,
	{ 'z', 'P' },{ '{', '\\' },{ '|', 'k' } ,{ '}', '-' } };

	map<char, char> key2 = {
		{ ' ', '$' } ,{ '!', '!' } ,{ '"', '>' } ,{ '#', 'E' } ,{ '$', '=' } ,
	{ '%', '`' } ,{ '&', ':' } ,{ '\'', '9' } ,{ '(', '4' } ,{ ')', 't' } ,
	{ '*', '_' } ,{ '+', 'p' } ,{ ',', ' ' } ,{ '-', '}' } ,{ '.', 'J' } ,
	{ '/', 'g' } ,{ '0', 'G' } ,{ '1', '3' } ,{ '2', 'a' } ,{ '3', 'x' } ,
	{ '4', 'P' } ,{ '5', 'T' } ,{ '6', '6' } ,{ '7', 'b' } ,{ '8', 'L' } ,
	{ '9', 'D' } ,{ ':', '0' } ,{ ';', '%' } ,{ '<', 'U' } ,{ '=', '(' } ,
	{ '>', '8' } ,{ '?', 'v' } ,{ '@', ',' } ,{ 'A', 'S' } ,{ 'B', '7' } ,
	{ 'C', 'A' } ,{ 'D', '&' } ,{ 'E', 'I' } ,{ 'F', 'k' } ,{ 'G', 'q' } ,
	{ 'H', 'l' } ,{ 'I', 'V' } ,{ 'J', '@' } ,{ 'K', 'i' } ,{ 'L', 'w' } ,
	{ 'M', ')' } ,{ 'N', '+' } ,{ 'O', '5' } ,{ 'P', 'z' } ,{ 'Q', '#' } ,
	{ 'R', 'c' } ,{ 'S', '/' } ,{ 'T', '?' } ,{ 'U', 's' } ,{ 'V', '1' } ,
	{ 'W', 'n' } ,{ 'X', '"' } ,{ 'Y', '\\' } ,{ 'Z', 'C' } ,{ '[', 'u' } ,
	{ '\\', '{' } ,{ ']', '[' } ,{ '^', 'r' } ,{ '_', 'R' } ,{ '`', 'o' } ,
	{ 'a', '*' } ,{ 'b', '^' } ,{ 'c', 'B' } ,{ 'd', '-' } ,{ 'e', 'F' } ,
	{ 'f', 'H' } ,{ 'g', 'M' } ,{ 'h', 'Q' } ,{ 'i', 'e' } ,{ 'j', 'f' } ,
	{ 'k', '|' } ,{ 'l', 'd' } ,{ 'm', 'Y' } ,{ 'n', ']' } ,{ 'o', 'y' } ,
	{ 'p', ';' } ,{ 'q', 'm' } ,{ 'r', '.' } ,{ 's', 'N' } ,{ 't', 'X' } ,
	{ 'u', 'Z' } ,{ 'v', '\'' } ,{ 'w', 'h' } ,{ 'x', 'O' } ,{ 'y', ' < ' } ,
	{ 'z', '2' } ,{ '{', 'W' } ,{ '|', 'j' } ,{ '}', 'K' } };

	code = key1;
	decode = key2;
}

/*

Enter a message ('end' to stop):
This is my secret message...
---  coded message: 5wKU,KU,qo,UiR^i),qiUU2/irrr
--- decode message: This is my secret message...

Enter a message ('end' to stop):
sharon.wu@reedleycollege.edu
---  coded message: Uw2^`WrL[J^iilHioR`HHi/iril[
--- decode message: sharon.wu@reedleycollege.edu

Enter a message ('end' to stop):
Programming is fun
---  coded message: 4^`/^2qqKW/,KU,j[W
--- decode message: Programming is fun

Enter a message ('end' to stop):
iWl
---  coded message: K{H
--- decode message: iWl

Enter a message ('end' to stop):
end
---  coded message: iWl
--- decode message: end

Press any key to continue . . .
Press any key to continue . . .
*/