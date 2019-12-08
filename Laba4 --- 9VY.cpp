#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class DATA
{
	string firstname;
	string secondname;
	string thirdname;
	string diag;
	string adrs;
	int mednum;
public:
	void Setfirstname(string firstnameValue)
	{
		firstname = firstnameValue;
	}
	void Setsecondname(string secondnameValue)
	{
		secondname = secondnameValue;
	}
	void Setthirdname(string thirdnameValue)
	{
		thirdname = thirdnameValue;
	}
	void Setdiag(string diagValue)
	{
		diag = diagValue;
	}
	void Setadrs(string adrsValue)
	{
		adrs = adrsValue;
	}
	void Setmednum(int mednumValue) 
	{
		mednum = mednumValue;
	}
	void print()
	{
		cout << "----------------------------------------\n"<< "Фамилия: " << secondname << "\nИмя: " << firstname << "\nОтчество: " <<thirdname << "\nДиагноз: " << diag << "\nАдрес: " << adrs << "\nНомер мед. книжки: " << mednum << "\n----------------------------------------" << endl;
	}
};

void addPac()
{
	ofstream fout;
	string path = "myFile.txt";
	fout.open(path, ofstream::app);
	if (!fout.is_open())
		cout << "Can not open " << path << endl;
	else
	{
		DATA firstPacient;
		string fstname, scndname, thrdname, diagn, adress;
		int nummed;
		cout << "Введите имя: "; cin >> fstname; firstPacient.Setfirstname(fstname);
		cout << "Введите фамилию: "; cin >> scndname; firstPacient.Setsecondname(scndname);
		cout << "Введите отчество: "; cin >> thrdname; firstPacient.Setthirdname(thrdname);
		cout << "Введите диагноз: "; cin >> diagn; firstPacient.Setdiag(diagn);
		cout << "Введите адрес: "; cin >> adress; firstPacient.Setadrs(adress);
		cout << "Введите номер мед. карты: "; cin >> nummed; firstPacient.Setmednum(nummed);
		system("cls");
		firstPacient.print();
		fout.write((char*)&firstPacient, sizeof(DATA));
	}
	fout.close();

}

int main()
{
	int select;
	string path = "myFile.txt";
	ifstream fin;
	do
	{
		cout << endl << endl << "[1]Добавить пациента в базу\n[2]Считать данные из базы\n[0]Выход\nВыберите от 0-2: " << endl; cin >> select; system("cls");
		switch (select) {
		case 1:
			addPac();
			break;
		case 2:
			fin.open(path);
			if (!fin.is_open())
			{
				cout << "Не могу прочитать " << path << " попробуйте снова";
			}
			else
			{
				DATA readDATA;
				while (fin.read((char*)&readDATA, sizeof(DATA)))
				{
					readDATA.print();
				}
				fin.close();
			}
			break;
		default: if (select != 0) { cout << "Введите верное значение!"; }
			   else { cout << "Спасибо за использование!" << endl; }
		}
	} while (select != 0);
}