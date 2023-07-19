#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;
vector<int> encoding(string s1)
{
	cout << "\n\n\t\t\t\t\tEncoding\n";
	unordered_map<string, int> table;
	for (int i = 0; i <= 255; i++)
	{
		string ch = "";
		ch += char(i);
		table[ch] = i;
	}

	string p = "", c = "";
	p += s1[0];
	int code = 256;
	vector<int> output_code;
	// cout << "String\tOutput_Code\tAddition\n";
	for (int i = 0; i < s1.length(); i++)
	{
		if (i != s1.length() - 1)
			c += s1[i + 1];
		if (table.find(p + c) != table.end())
		{
			p = p + c;
		}
		else
		{
			// cout << p << "\t" << table[p] << "\t\t"
			// 	 << p + c << "\t" << code << endl;
			output_code.push_back(table[p]);
			table[p + c] = code;
			code++;
			p = c;
		}
		c = "";
	}
	// cout << p << "\t" << table[p] << endl;
	output_code.push_back(table[p]);
	return output_code;
}

void decoding(vector<int> op)
{
	cout << "\n\n\t\t\t\t\tDecoding.....\n\n";
	unordered_map<int, string> table;
	string final="";
	for (int i = 0; i <= 255; i++)
	{
		string ch = "";
		ch += char(i);
		table[i] = ch;
	}
	int old = op[0], n;
	string s = table[old];
	string c = "";
	c += s[0];
	cout << s;
	int count = 256;
	for (int i = 0; i < op.size() - 1; i++)
	{
		n = op[i + 1];
		if (table.find(n) == table.end())
		{
			s = table[old];
			s = s + c;
		}
		else
		{
			s = table[n];
		}
		cout << s;
		c = "";
		c += s[0];
		table[count] = table[old] + c;
		count++;
		old = n;
	}
	while (true)
	{
		cout << "\n\nplease enter any key to continue..........";
		if (getch())
			break;
	}
	system("cls");
}

string fileOpen()
{
	string fileName, temp, fString = "";
	cout << "\n\n\t\t\t\t\tEnter the name of the file you want to compress :-> ";
	cin >> fileName;
	fstream file;
	file.open(fileName, ios::in);
	while (!file.eof())
	{
		getline(file, temp);
		fString += temp + "\n";
	}
	file.close();
	return fString;
}

void store(vector<int> output_code)
{
	string temp = "";
	fstream file;
	file.open("compressed.txt", ios::out);
	for (int i = 0; i < output_code.size(); i++)
	{
		temp += output_code[i];
	}
	cout << "\n\n\t\t\t\t\tValues have been stored in the file successfully.\n";
	while (true)
	{
		cout << "\n\n\t\t\t\t\tplease enter any key to continue..........";
		if (getch())
			break;
	}
	system("cls");
	file << temp;
	file.close();
}

string read()
{
	string temp, fString = "";
	fstream file;
	file.open("compressed.txt", ios::in);
	while (!file.eof())
	{
		getline(file, temp);
		fString += temp;
	}
	file.close();
	return fString;
}

int main()
{
	string s = "", comp;
	int choice;
	vector<int> output_code;
	int dummy;
	system("cls");

	cout << "\t\t\t\t#########################################################################################\n";
	cout << "\t\t\t\t#\t\t\t\t\t\t\t\t\t\t\t#\n";
	cout << "\t\t\t\t#.......................................................................................#\n";
	cout << "\t\t\t\t#\t\t\t\t\t\t\t\t\t\t\t#\n";
	cout << "\t\t\t\t#\t\t\t\t\tWELCOME TO\t\t\t\t\t#\n";
	cout << "\t\t\t\t#\t\t\t\t\t\t\t\t\t\t\t#\n";
	cout << "\t\t\t\t#\t\t\t\tTEXT COMPRESSION SYSTEM USING\t\t\t\t#\n";
	cout << "\t\t\t\t#\t\t\t\t\t\t\t\t\t\t\t#\n";
	cout << "\t\t\t\t#\t\t\t\t LEMPEL-ZIV-WELCH ALGORITHM\t\t\t\t#\n";
	cout << "\t\t\t\t#\t\t\t\t\t\t\t\t\t\t\t#\n";
	cout << "\t\t\t\t#.......................................................................................#\n";
	cout << "\t\t\t\t#\t\t\t\t\t\t\t\t\t\t\t#\n";
	cout << "\t\t\t\t#########################################################################################\n";


	while (true)
	{
		cout << "\n\nplease enter any key to continue..........";
		if (getch())
			break;
	}
	system("cls");

	while (true)
	{
		cout<<"\t\t\t\t\t\t==========================================================================\n";
		cout<<"\t\t\t\t\t\t------------------FILE STRUCTURE LABORATORY MINI PROJECT------------------\n";
		cout<<"\t\t\t\t\t\t==========================================================================\n";
		cout<<"\t\t\t\t\t\t--------------------------TEXT FILE COMPRESSION---------------------------\n";
		cout<<"\t\t\t\t\t\t|\t 4SF20IS101 - SOORAJ S M && 4SF20IS109 - VAIBHAV S NAIK\t\t |\n";
		cout<<"\t\t\t\t\t\t==========================================================================\n";
		cout << "\n\n\n\n";



		cout << "\t\t\t\t\t-----------------------------------------------------------------------------------------\n";
		cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t|\n";
		cout << "\t\t\t\t\t|\t\t\t\t\t1) Compress \t\t\t\t\t|\n";
		cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t|\n";
		cout << "\t\t\t\t\t|\t\t\t\t\t2) Decompress\t\t\t\t\t|\n";
		cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t|\n";
		cout << "\t\t\t\t\t|\t\t\t\t\t3) Exit \t\t\t\t\t|\n";
		cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t|\n";
		cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t|\n";
		cout << "\t\t\t\t\t-----------------------------------------------------------------------------------------\n";
		cout << "\n\n\n\t\t\t\t\tEnter Your Choice :-> ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			s = fileOpen();
			output_code = encoding(s);
			// cout << "Output Codes are: ";
			// for (int i = 0; i < output_code.size(); i++)
			// {
			// 	cout << output_code[i] << " ";
			// }
			store(output_code);
			cout << endl;
			break;
		case 2:
			// comp=read();
			// output_code.clear();
			// output_code.push_back(stoi(comp));
			decoding(output_code);
			cout << endl;
			break;

		case 3:
		system("cls");
			exit(0);

		default:
			cout << "Please Enter a Valid statement";
			break;
		}
	}

	// cout << "Output Codes are: ";
	// for (int i = 0; i < output_code.size(); i++)
	// {
	// 	cout << output_code[i] << " ";
	// }
	// cout << endl;
	// decoding(output_code);
}
