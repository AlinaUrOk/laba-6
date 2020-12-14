// laba_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <string>

#include <stdio.h> 
#include <conio.h> 
#include <fstream>
#include <iostream>
using namespace std;

bool type(string s) {
	bool f = true;
	for (int i = 0; i < s.size(); i++)
	{
		if (((int)s[i] - 48 >= 0 && (int)s[i] - 48 <= 9) || (s[i] == '-' && i == 0) || s[i] == '.')
		{
			continue;
		}
		return false;

	}
	int n = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '.')
		{
			n++;
			if (i == 0)
			{
				return false;
			}
		}
	}
	if (s.size() == 0)
	{
		return false;
	}
	if (s[s.size() - 1] == '.' || n > 1) {
		return false;
	}


	if (s[0] == '0' && s[1] != '.')
	{
		return false;
	}
	if (s[0] == '-' && s[1] == '0' && s[2] != '.')
	{
		return false;
	}

	return f;

}


struct fl 
{
	float num;
};


int main(int argc, char* argv[])
{

	fl pack;
	FILE* f;

	fopen_s(&f, "D://data.txt", "wb+");
	string line, s;
	ifstream in("Текст.txt");
	if (in.is_open())
	{
		while (getline(in, line))
		{
			for (int i = 0; i < line.size(); i++)
			{
				bool q = true;
				string numberStr = "";
				while (line[i] != ' ' && line[i] != '\n' && line[i] != '\0' && i < line.size()) {
					numberStr += line[i];
					i++;
				}

				if (type(numberStr))
				{
					float num = stof(numberStr);
					pack.num = num;
					fwrite(&pack, sizeof(fl), 1, f);
				}
			}

		}
	}
	fseek(f, 0L, SEEK_END);
	int sz = ftell(f);
	fseek(f, 0L, SEEK_SET);
	in.close();

	for (int i = 0; i < sz / 4; i++)
	{
		fseek(f, i * sizeof(fl), SEEK_SET);
		fread(&pack, sizeof(fl), 1, f);

		printf("%f\n", pack.num);

	}

	fclose(f);

	return 0;
}
