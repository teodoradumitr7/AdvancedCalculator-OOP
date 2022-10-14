#include <iostream>
#include <string>
#include <iomanip>
#include <deque>
#include <fstream>
double invalid = -1;
double valid = 1;
using namespace std;

class Numar {
private:
	double nr = 0;
public:
	Numar();
	Numar(double n);
	~Numar();
	void setNr(double n);
	double getNr();
	Numar(const Numar& n);
	Numar& operator=(const Numar& n);
	bool verificaNrNegativ();
	void estePozitiv();
	Numar operator+(double valoare);
	friend Numar operator+(double valoare, Numar n);
	Numar operator-(double valoare);
	friend Numar operator-(double valoare, Numar n);
	Numar operator*(double valoare);
	friend Numar operator*(double valoare, Numar n);
	Numar operator/(double valoare);
	friend Numar operator/(double valoare, Numar n);
	Numar operator+(const Numar& n);
	Numar operator-(const Numar& n);
	Numar operator/(const Numar& n);
	Numar operator*(const Numar& n);
	friend ostream& operator<<(ostream& out, Numar n)
	{
		out << n.getNr() << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Numar& n)
	{
		double val;
		in >> val;
		n.setNr(val);
		return in;
	}

	friend ofstream& operator<<(ofstream& f, Numar n)
	{
		if (f.is_open())
		{
			f << n.getNr();
			f << endl;
		}
		return f;
	}

};
Numar::Numar()
{
	nr = 0;
}

Numar::Numar(double n)
{
	nr = n;
}
double Numar::getNr()
{
	return nr;
}

void Numar::setNr(double n)
{
	if (n != NULL)
	{
		nr = n;
	}

}
Numar::Numar(const Numar& n)
{
	if (n.nr != NULL)
	{
		nr = n.nr;
	}

}
Numar::~Numar()
{
	//cout << "S-a apelat destructorul";
}

Numar& Numar::operator=(const Numar& n)
{
	if (this != &n)
	{
		if (n.nr != NULL)
		{
			nr = n.nr;
		}
	}
	return *this;
}
Numar Numar::operator+(double valoare)
{
	Numar copie = *this;
	copie.nr = copie.nr + valoare;
	return copie;
}
Numar Numar::operator-(double valoare)
{
	Numar copie = *this;
	copie.nr = copie.nr - valoare;
	return copie;
}
Numar Numar:: operator*(double valoare)
{
	Numar copie = *this;
	copie.nr = copie.nr * valoare;
	return copie;
}


Numar Numar::operator/(double valoare)
{
	Numar copie = *this;
	if (valoare != 0)
	{
		copie.nr = copie.nr / valoare;
		return copie;
	}
	else return NULL;
}
Numar Numar::operator+(const Numar& n) {
	Numar copie = *this;
	if (n.nr != NULL)
	{
		copie.nr = copie.nr + n.nr;
		return copie;

	}
	return NULL;
}
Numar Numar::operator-(const Numar& n) {
	Numar copie = *this;
	if (n.nr != NULL)
	{
		copie.nr = copie.nr - n.nr;
		return copie;

	}
	return NULL;
}
Numar Numar::operator*(const Numar& n) {
	Numar copie = *this;
	if (n.nr != NULL)
	{
		copie.nr = copie.nr * n.nr;
		return copie;

	}
	return NULL;
}
Numar Numar::operator/(const Numar& n) {
	Numar copie = *this;
	if (n.nr != 0)
	{
		copie.nr = copie.nr / n.nr;
		return copie;

	}
	return NULL;
}

bool Numar::verificaNrNegativ()
{
	return nr < 0;
}

void Numar::estePozitiv()
{
	if (nr < 0)
	{
		nr = nr * (-1);
	}

}

Numar operator+(double valoare, Numar n)
{
	n.nr = n.nr + valoare;
	return n;
}
Numar operator-(double valoare, Numar n)
{
	n.nr = n.nr - valoare;
	return n;
}
Numar operator*(double valoare, Numar n)
{
	n.nr = n.nr * valoare;
	return n;
}
Numar operator/(double valoare, Numar n)
{
	if (n.nr > 0)
	{
		n.nr = n.nr + valoare;
		return n;
	}
	return NULL;
}




class Ecuatie {
private:
	//ecuatia citita de la tastatura
	char* ecuatia;
	const int id;
	//doar valorile numerice extrase din ecuatie
	double* numere = nullptr;
	//valorile numerice din vectorul numere, in vector dinamic de tip Numar
	Numar* num;
	//cate numere au fost date de la tastatura
	int nr = 0;
	//operatiile din cadrul ecuatiei
	char* operatii = nullptr;
public:
	Ecuatie();
	Ecuatie(char* ecuatieData, int idEcuatie);
	~Ecuatie();
	Ecuatie(const Ecuatie& e);
	Ecuatie& operator=(const Ecuatie& e);
	void setEcuatie(const char* ecuatieData);
	void setNumere(double* vector, int numr);
	void setOperatii(const char* oper);
	void setNum(Numar* numer, int nume);
	int getNr();
	char* getEcuatie();
	char* getOperatii();
	double* getNumere();
	Numar* getNum();
	void verificaNegativ();
	double& verificaParanteze();
	double& operator[](int index);
	bool operator!();

	friend ostream& operator<<(ostream& out, Ecuatie e)
	{
		out << "Ecuatia data: ";
		if (e.getEcuatie() != nullptr)
		{
			out << e.getEcuatie() << endl;
		}
		if (e.getEcuatie() != nullptr)
		{
			for (int i = 0; i < e.nr; i++)
				out << e.numere[i] << " ";
		}
		out << endl;
		out << "Operatiile: ";
		if (e.getOperatii() != nullptr)out << e.getOperatii() << endl;
		else out << endl;
		out << "Numerele: ";
		if (e.num != NULL)
		{
			for (int i = 0; i < e.nr; i++)
			{
				out << e.num[i].getNr() << " ";
			}
		}
		else out << endl;
		out << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Ecuatie& e)
	{
		cout << "Ecuatia este:";
		in >> ws;
		string ecuatiaNoua;
		getline(in, ecuatiaNoua);
		e.setEcuatie(ecuatiaNoua.c_str());
		return in;
	}

	friend ifstream& operator>>(ifstream& f, Ecuatie& c)
	{
		if (f.is_open())
		{
			char ec[256];
			f >> ws;
			f.getline(ec, 255);
			c.setEcuatie(ec);
		}
		return f;
	}
};



Ecuatie::Ecuatie() :id(0)
{
	ecuatia = new char[4];
	strcpy_s(ecuatia, 4, "N/A");
	numere = nullptr;
	nr = 0;
	operatii = nullptr;
	num = new Numar[1];
	num[0] = NULL;


}

Ecuatie::Ecuatie(char* ecuatieData, int idEcuatie) :id(idEcuatie) {
	if (ecuatieData != nullptr)
	{
		ecuatia = new char[strlen(ecuatieData) + 1];
		strcpy_s(ecuatia, strlen(ecuatieData) + 1, ecuatieData);
		int n1 = 0, n2 = 0, virgula = 0;
		for (int i = 0; i < strlen(ecuatieData) + 1; i++)
		{
			if (strchr("+-*/^#()[]", ecuatia[i]) != nullptr)
				n1++;
			if (strchr(".", ecuatia[i]) != nullptr)
				virgula++;
		}
		n2 = strlen(ecuatia) + 1 - n1;
		num = new Numar[n2 + 1];
		numere = new double[n2 + 1];
		operatii = new char[n1 + 1];
		int i = 0, k = 0, o = 0;
		while (ecuatia[i] == '[' || ecuatia[i] == '(' || ecuatia[i] == '-' || ecuatia[i] == ' ')i++;
		while (i < strlen(ecuatia) + 1)
		{
			numere[k] = 0;
			while ((ecuatia[i] >= 48 && ecuatia[i] <= 57) || ecuatia[i] == 46)
			{
				if (ecuatia[i] == 46)
				{
					int v = 1;
					i++;
					while (ecuatia[i] >= 48 && ecuatia[i] <= 57)
					{
						double p = 1;
						for (int i = 0; i < v; i++)
							p = p * 10;
						p = 1 / p;
						numere[k] = numere[k] + p * (ecuatia[i] - 48);
						i++;
						v++;
					}
				}
				else {
					numere[k] = numere[k] * 10 + (ecuatia[i] - 48);
					i++;
				}
			}
			while (!((ecuatia[i] >= 48 && ecuatia[i] <= 57) || ecuatia[i] == 46))
				i++;
			k++;
		}
		if (ecuatia[0] == '-')numere[0] = numere[0] * (-1);
		for (int i = 0; i < k; i++)
		{
			num[i].setNr(numere[i]);
		}
		nr = k;
		for (i = 0; i < strlen(ecuatia) + 1; i++)
		{
			if (!((ecuatia[i] >= 48 && ecuatia[i] <= 57) || ecuatia[i] == 46) && ecuatia[i] != ' ')
			{
				operatii[o++] = ecuatia[i];

			}
			operatii[o] = '\0';

		}
		if (ecuatia[0] == '-')
		{
			for (int j = 0; j < strlen(operatii); j++)
			{
				operatii[j] = operatii[j + 1];
			}
		}
	}
	else {
		ecuatia = new char[4];
		strcpy_s(ecuatia, 4, "N/A");
		numere = nullptr;
		nr = 0;
		operatii = nullptr;
		num = new Numar[1];
		num[0] = NULL;
	}

}

Ecuatie::~Ecuatie() {
	if (operatii != nullptr)
	{
		delete[] operatii;
		operatii = nullptr;
	}
	if (ecuatia != nullptr)
	{
		delete[] ecuatia;
		ecuatia = nullptr;
	}

	if (numere != nullptr)
	{
		delete[] numere;
		numere = nullptr;
	}
	if (num != nullptr)
	{
		delete[] num;
		num = nullptr;
	}
}

Ecuatie::Ecuatie(const Ecuatie& e) :id(e.id)
{
	if (e.ecuatia != nullptr)
	{
		ecuatia = new char[strlen(e.ecuatia) + 1];
		strcpy_s(ecuatia, strlen(e.ecuatia) + 1, e.ecuatia);
		if (e.operatii != nullptr)
		{
			operatii = new char[strlen(e.operatii) + 1];
			strcpy_s(operatii, strlen(e.operatii) + 1, e.operatii);
		}
		if (e.numere != nullptr && e.nr != 0)
		{
			nr = e.nr;
			numere = new double[nr];
			for (int i = 0; i < nr; i++)
			{
				numere[i] = e.numere[i];
			}
		}
		if (e.num != nullptr)
		{
			num = new Numar[nr];
			for (int i = 0; i < nr; i++)
			{
				num[i] = e.num[i];
			}
		}
	}
	else {
		ecuatia = new char[4];
		strcpy_s(ecuatia, 4, "N/A");
		numere = nullptr;
		nr = 0;
		operatii = nullptr;
		num = new Numar[1];
		num[0] = NULL;
	}
}



Ecuatie& Ecuatie:: operator=(const Ecuatie& e) {
	if (this != &e)
	{
		if (operatii != nullptr)
		{
			delete[] operatii;
			operatii = nullptr;
		}
		if (ecuatia != nullptr)
		{
			delete[] ecuatia;
			ecuatia = nullptr;
		}

		if (numere != nullptr)
		{
			delete[] numere;
			numere = nullptr;
		}
		if (num != nullptr)
		{
			delete[] num;
			num = nullptr;
		}
		if (e.ecuatia != nullptr)
		{
			ecuatia = new char[strlen(e.ecuatia) + 1];
			strcpy_s(ecuatia, strlen(e.ecuatia) + 1, e.ecuatia);
			if (e.operatii != nullptr)
			{
				operatii = new char[strlen(e.operatii) + 1];
				strcpy_s(operatii, strlen(e.operatii) + 1, e.operatii);
			}
			if (e.numere != nullptr && e.nr != 0)
			{
				nr = e.nr;
				numere = new double[nr];
				for (int i = 0; i < nr; i++)
				{
					numere[i] = e.numere[i];
				}
			}
			if (e.num != nullptr)
			{
				num = new Numar[nr];
				for (int i = 0; i < nr; i++)
				{
					num[i] = e.num[i];
				}
			}
		}
	}
	return *this;

}

void Ecuatie::setEcuatie(const char* ecuatieData) {
	if (ecuatieData != nullptr)
	{
		ecuatia = new char[strlen(ecuatieData) + 1];
		strcpy_s(ecuatia, strlen(ecuatieData) + 1, ecuatieData);
		int n1 = 0, n2 = 0, virgula = 0;
		for (int i = 0; i < strlen(ecuatieData) + 1; i++)
		{
			if (strchr("+-*/^#()[]", ecuatia[i]) != nullptr)
				n1++;
			if (strchr(".", ecuatia[i]) != nullptr)
				virgula++;
		}
		n2 = strlen(ecuatia) + 1 - n1;
		numere = new double[n2 + 1];
		num = new Numar[n2 + 1];
		operatii = new char[n1 + 1];
		int i = 0, k = 0, o = 0;
		while (ecuatia[i] == '[' || ecuatia[i] == '(' || ecuatia[i] == '-' || ecuatia[i] == ' ')i++;
		while (i < strlen(ecuatia) + 1)
		{
			numere[k] = 0;
			while ((ecuatia[i] >= 48 && ecuatia[i] <= 57) || ecuatia[i] == 46)
			{
				if (ecuatia[i] == 46)
				{
					i++;
					int v = 1;
					while (ecuatia[i] >= 48 && ecuatia[i] <= 57)
					{
						double p = 1;
						for (int i = 0; i < v; i++)
							p = p * 10;
						p = 1 / p;
						numere[k] = numere[k] + p * (ecuatia[i] - 48);
						i++;
						v++;
					}
				}
				else {
					numere[k] = numere[k] * 10 + (ecuatia[i] - 48);
					i++;
				}
			}

			while (!((ecuatia[i] >= 48 && ecuatia[i] <= 57) || ecuatia[i] == 46))
				i++;
			k++;
		}
		if (ecuatia[0] == '-')numere[0] = numere[0] * (-1);
		nr = k;
		for (int i = 0; i < k; i++)
		{
			num[i].setNr(numere[i]);
		}
		for (i = 0; i < strlen(ecuatia) + 1; i++)
		{
			if (!((ecuatia[i] >= 48 && ecuatia[i] <= 57) || ecuatia[i] == 46) && ecuatia[i] != ' ')
			{
				operatii[o++] = ecuatia[i];

			}
			operatii[o] = '\0';

		}
		if (ecuatia[0] == '-')
			for (int j = 0; j < strlen(operatii); j++)
			{
				operatii[j] = operatii[j + 1];

			}
	}
}

char* Ecuatie::getEcuatie() {
	if (ecuatia != nullptr)
	{
		char* copie = new char[strlen(ecuatia) + 1];
		strcpy_s(copie, strlen(ecuatia) + 1, ecuatia);
		return copie;
	}
	return nullptr;
}

char* Ecuatie::getOperatii() {
	if (operatii != nullptr)
	{
		char* copia = new char[strlen(operatii) + 1];
		strcpy_s(copia, strlen(operatii) + 1, operatii);
		return copia;
	}
	return nullptr;
}

double* Ecuatie::getNumere() {
	if (numere != nullptr && nr != 0)
	{
		double* copi = new double[nr];
		for (int i = 0; i < nr; i++) {
			copi[i] = numere[i];
		}
		return copi;
	}
	return nullptr;
}
int Ecuatie::getNr()
{
	return nr;
}

Numar* Ecuatie::getNum()
{
	Numar* copia = new Numar[nr];
	for (int i = 0; i < nr; i++)
	{
		copia[i] = num[i];
	}
	return copia;
}

void Ecuatie::verificaNegativ()
{
	if (operatii != nullptr && operatii[0] == '-')
	{
		if (numere != nullptr && nr > 0)
		{
			numere[0] = numere[0] * (-1);
		}
		if (num != nullptr)
		{
			double invers = num[0].getNr();
			invers = invers * (-1);
			num[0].setNr(invers);
		}
		for (int i = 0; i < strlen(operatii); i++)
		{
			operatii[i] = operatii[i + 1];
		}
	}
}

//valideaza corectitudinea parantezelor introduse
double& Ecuatie::verificaParanteze()
{
	if (operatii != nullptr)
	{
		int np = 0, nP = 0;
		for (int i = 0; i < strlen(operatii) + 1; i++)
		{
			if (operatii[i] == '(' || operatii[i] == ')')
			{
				np++;
			}
			else if (operatii[i] == '[' || operatii[i] == ']')
			{
				nP++;
			}
		}
		if (nP > np)
		{
			return invalid;
		}
		if (np % 2 != 0 || nP % 2 != 0)
		{
			return invalid;
		}
		return valid;
	}
}

double& Ecuatie::operator[](int index)
{
	if (index >= 0 && numere != nullptr && index < nr)
	{
		return numere[index];
	}
	else { return invalid; }
}

//verifica daca exista numere introduse
bool Ecuatie::operator!()
{
	if (nr > 0) {
		return true;
	}
	return false;
}

void Ecuatie::setNumere(double* vector, int numr) {
	if (vector != nullptr && nr > 0)
	{
		if (numere != nullptr)
		{
			delete[] numere;
			numere = nullptr;
		}
		numere = new double[numr];
		for (int i = 0; i < numr; i++)
		{
			numere[i] = vector[i];
		}
		nr = numr;

	}

}
void Ecuatie::setOperatii(const char* oper) {
	if (oper != nullptr)
	{
		char* copie = new char[strlen(oper) + 1];
		if (operatii != nullptr)
		{
			delete[] operatii;
			operatii = nullptr;
		}
		int k = 0;
		for (int i = 0; i < strlen(oper); i++)
		{
			if (!((oper[i] >= 48 && oper[i] <= 57) || oper[i] == 46) && oper[i] != ' ')
			{
				copie[k++] = oper[i];
			}
		}
		copie[k] = '\0';
		operatii = new char[strlen(copie) + 1];
		strcpy_s(operatii, strlen(copie) + 1, copie);
	}

}
void Ecuatie::setNum(Numar* numer, int nume) {
	if (nume > 0 && numer != nullptr)
	{
		for (int i = 0; i < nume; i++)
			num[i] = numer[i];
	}
}




class Calcule
{
private:
	static string tip;
	Ecuatie ec;
public:
	Calcule();
	Calcule(const Ecuatie& e);
	Calcule(const Calcule& c);
	~Calcule();
	Calcule& operator=(const Calcule& c);
	Ecuatie getEcuatie();
	void setEcuatie(const Ecuatie& e);
	virtual bool operator<(int num);
	bool operator>(int num);
	double faceCalcul();
	virtual bool verificareOrdine();
	string rezultatulEc(double rez);
	static void setTip(string tipul) {
		if (tipul.length() > 0)
		{
			Calcule::tip = tipul;
		}
	}
	static string getTip()
	{
		return tip;
	}


	friend istream& operator>>(istream& in, Calcule& c) {
		cout << "Ecuatia este: ";
		Ecuatie e;
		string ec;
		in >> ec;
		e.setEcuatie(ec.c_str());
		c.setEcuatie(e);
		return in;
	}
	friend ostream& operator<<(ostream& out, Calcule c)
	{
		out << c.getEcuatie() << endl;
		return out;

	}
	friend ofstream& operator<<(ofstream& f, Calcule c)
	{
		if (f.is_open())
		{
			double r = c.faceCalcul();
			if ((float)r != (int)0) {
				f << c.rezultatulEc(r);
			}
			else f << 0;
		}
		return f;
	}

	friend ifstream& operator>>(ifstream& f, Calcule& c)
	{
		if (f.is_open())
		{
			Ecuatie e;
			f >> ws;
			f >> e;
			c.setEcuatie(e);

		}
		return f;
	}
};


string Calcule::tip = "Necunoscut";
Calcule::Calcule()
{
	ec.setEcuatie(nullptr);
}
Calcule::Calcule(const Ecuatie& e)
{
	ec = e;

}
Calcule::Calcule(const Calcule& c)
{

	ec = c.ec;

}
Calcule::~Calcule()
{

}
Calcule& Calcule::operator=(const Calcule& c)
{
	if (this != &c)
	{
		ec = c.ec;
	}
	return *this;
}


void Calcule::setEcuatie(const Ecuatie& e)
{
	ec = e;
}

double Calcule::faceCalcul()
{
	char* op = ec.getOperatii();
	double* nr = ec.getNumere();
	int n = ec.getNr();
	int ok = 0; int okp = 0;
	double val = 0;
	for (int i = 0; i < strlen(op); i++)
		if (op[i] == '[' || op[i] == ']')
		{
			okp++;
		}
		else if (op[i] == '(' || op[i] == ')')
		{
			ok++;
		}
	if (ok == 0)
	{
		int j = 0;
		double partial;
		while (j < strlen(op) + 1)
		{
			partial = 1;
			if (op[j] == '^') {
				for (int p = 0; p < nr[j + 1]; p++)
					partial = partial * nr[j];
				nr[j] = partial;
				for (int k = j + 2; k < n + 1; k++)
					nr[k - 1] = nr[k];
				n--;
				for (int k = j; k < strlen(op); k++)
					op[k] = op[k + 1];
				j--;
			}
			else if (op[j] == '#') {

				partial = pow(nr[j], (1.0 / nr[j + 1]));
				nr[j] = partial;
				for (int k = j + 2; k < n + 1; k++)
					nr[k - 1] = nr[k];
				n--;
				for (int k = j; k < strlen(op); k++)
					op[k] = op[k + 1];
				j--;

			}j++;

		}
		j = 0;
		while (j < strlen(op) + 1)
		{
			partial = 0;
			if (op[j] == '*') {
				partial = nr[j] * nr[j + 1];
				nr[j] = partial;
				for (int k = j + 2; k < n + 1; k++)
					nr[k - 1] = nr[k];
				n--;
				for (int k = j; k < strlen(op); k++)
					op[k] = op[k + 1];
				j--;
			}
			else if (op[j] == '/') {
				if (nr[j + 1] != 0)
				{
					partial = nr[j] / nr[j + 1];
					nr[j] = partial;
					for (int k = j + 2; k < n + 1; k++)
						nr[k - 1] = nr[k];
					n--;
					for (int k = j; k < strlen(op); k++)
						op[k] = op[k + 1];
					j--;
				}
				else {
					cout << "Eroare impartire la ";
					return 0;
				}
			}j++;

		}
		val = nr[0];
		for (j = 0; j < strlen(op); j++)
		{
			if (op[j] == '+')
				val = val + nr[j + 1];
			else val = val - nr[j + 1];
		}
	}
	else if (okp > 0 && ok > 0)
	{
		while (ok > 0 && okp > 0)
		{
			int incep = 0;
			while (op[incep] != '(')incep++;
			int final = incep + 1;
			while (op[final] != ')')final++;
			int intre = incep + 1;
			int finalp = 0;
			while (op[finalp] != ']')finalp++;
			int incepp = 0;
			while (op[incepp] != '[')incepp++;
			double partial;
			if (incep < finalp && incepp < final)
			{
				while (intre < final)
				{
					partial = 1;
					if (op[intre] == '^') {
						for (int p = 0; p < nr[intre - 1]; p++)
							partial = partial * nr[intre - 2];
						nr[intre - 2] = partial;
						for (int k = intre - 1; k < n; k++)
							nr[k] = nr[k + 1];
						n--;
						for (int k = intre; k < strlen(op); k++)
							op[k] = op[k + 1];
						intre--;
						final--;
					}
					else if (op[intre] == '#') {

						partial = pow(nr[intre - 2], (1.0 / nr[intre - 1]));
						nr[intre - 2] = partial;
						for (int k = intre - 1; k < n; k++)
							nr[k] = nr[k + 1];
						n--;
						for (int k = intre; k < strlen(op); k++)
							op[k] = op[k + 1];
						intre--;
						final--;

					}intre++;

				}
				intre = incep + 1;
				while (intre < final)
				{
					partial = 0;
					if (op[intre] == '*') {
						partial = nr[intre - 2] * nr[intre - 1];
						nr[intre - 2] = partial;
						for (int k = intre - 1; k < n; k++)
							nr[k] = nr[k + 1];
						n--;
						for (int k = intre; k < strlen(op); k++)
							op[k] = op[k + 1];
						intre--;
						final--;
					}
					else if (op[intre] == '/') {
						if (nr[intre - 1] != 0)
						{
							partial = nr[intre - 2] / nr[intre - 1];
							nr[intre - 2] = partial;
							for (int k = intre - 1; k < n; k++)
								nr[k] = nr[k + 1];
							n--;
							for (int k = intre; k < strlen(op); k++)
								op[k] = op[k + 1];
							intre--;
							final--;
						}
						else {
							cout << "Eroare impartire la ";
							return 0;
						}
					}
					intre++;

				}
				intre = incep + 1;
				final = incep;
				while (op[final] != ')')final++;
				while (intre < final)
				{
					if (op[intre] == '+')
					{
						nr[intre - 2] = nr[intre - 2] + nr[intre - 1];
						for (int k = intre - 1; k < n; k++)
							nr[k] = nr[k + 1];
						n--;
						for (int k = intre; k < strlen(op); k++)
							op[k] = op[k + 1];
						intre--;
						final--;
					}
					else {
						nr[intre - 2] = nr[intre - 2] - nr[intre - 1];
						for (int k = intre - 1; k < n; k++)
							nr[k] = nr[k + 1];
						n--;
						for (int k = intre; k < strlen(op); k++)
							op[k] = op[k + 1];
						intre--;
						final--;
					}
					intre++;

				}
				ok -= 2;
				for (int k = incep; k < strlen(op); k++)
					op[k] = op[k + 1];
				final = incep;
				while (op[final] != ')')final++;
				for (int k = final; k < strlen(op); k++)
					op[k] = op[k + 1];

			}
			else if (incep > finalp)
			{
				while (intre < final)
				{
					partial = 1;
					if (op[intre] == '^') {
						for (int p = 0; p < nr[intre - 2]; p++)
							partial = partial * nr[intre - 3];
						nr[intre - 3] = partial;
						for (int k = intre - 2; k < n; k++)
							nr[k] = nr[k + 1];
						n--;
						for (int k = intre; k < strlen(op); k++)
							op[k] = op[k + 1];
						intre--;
						final--;
					}
					else if (op[intre] == '#') {

						partial = pow(nr[intre - 3], (1.0 / nr[intre - 2]));
						nr[intre - 3] = partial;
						for (int k = intre - 2; k < n; k++)
							nr[k] = nr[k + 1];
						n--;
						for (int k = intre; k < strlen(op); k++)
							op[k] = op[k + 1];
						intre--;
						final--;

					}intre++;

				}
				intre = incep + 1;
				while (intre < final)
				{
					partial = 0;
					if (op[intre] == '*') {
						partial = nr[intre - 3] * nr[intre - 2];
						nr[intre - 3] = partial;
						for (int k = intre - 2; k < n; k++)
							nr[k] = nr[k + 1];
						n--;
						for (int k = intre; k < strlen(op); k++)
							op[k] = op[k + 1];
						intre--;
						final--;
					}
					else if (op[intre] == '/') {
						if (nr[intre - 2] != 0)
						{
							partial = nr[intre - 3] / nr[intre - 2];
							nr[intre - 3] = partial;
							for (int k = intre - 2; k < n; k++)
								nr[k] = nr[k + 1];
							n--;
							for (int k = intre; k < strlen(op); k++)
								op[k] = op[k + 1];
							intre--;
							final--;
						}
						else {
							cout << "Eroare impartire la ";
							return 0;
						}
					}
					intre++;

				}
				intre = incep + 1;
				final = incep;
				while (op[final] != ')')final++;
				while (intre < final)
				{
					if (op[intre] == '+')
					{
						nr[intre - 3] = nr[intre - 3] + nr[intre - 2];
						for (int k = intre - 2; k < n; k++)
							nr[k] = nr[k + 1];
						n--;
						for (int k = intre; k < strlen(op); k++)
							op[k] = op[k + 1];
						intre--;
						final--;
					}
					else {
						nr[intre - 3] = nr[intre - 3] - nr[intre - 2];
						for (int k = intre - 2; k < n; k++)
							nr[k] = nr[k + 1];
						n--;
						for (int k = intre; k < strlen(op); k++)
							op[k] = op[k + 1];
						intre--;
						final--;
					}
					intre++;

				}
				ok -= 2;
				for (int k = incep; k < strlen(op); k++)
					op[k] = op[k + 1];
				final = incep;
				while (op[final] != ')')final++;
				for (int k = final; k < strlen(op); k++)
					op[k] = op[k + 1];

			}
			else if (final < incepp)
			{
				while (intre < final)
				{
					partial = 1;
					if (op[intre] == '^') {
						for (int p = 0; p < nr[intre]; p++)
							partial = partial * nr[intre - 1];
						nr[intre - 1] = partial;
						for (int k = intre; k < n; k++)
							nr[k] = nr[k + 1];
						n--;
						for (int k = intre; k < strlen(op); k++)
							op[k] = op[k + 1];
						intre--;
						final--;
					}
					else if (op[intre] == '#') {

						partial = pow(nr[intre - 1], (1.0 / nr[intre]));
						nr[intre - 1] = partial;
						for (int k = intre; k < n; k++)
							nr[k] = nr[k + 1];
						n--;
						for (int k = intre; k < strlen(op); k++)
							op[k] = op[k + 1];
						intre--;
						final--;

					}intre++;

				}
				intre = incep + 1;
				while (intre < final)
				{
					partial = 0;
					if (op[intre] == '*') {
						partial = nr[intre - 1] * nr[intre];
						nr[intre - 1] = partial;
						for (int k = intre; k < n; k++)
							nr[k] = nr[k + 1];
						n--;
						for (int k = intre; k < strlen(op); k++)
							op[k] = op[k + 1];
						intre--;
						final--;
					}
					else if (op[intre] == '/') {
						if (nr[intre] != 0)
						{
							partial = nr[intre - 1] / nr[intre];
							nr[intre - 1] = partial;
							for (int k = intre; k < n; k++)
								nr[k] = nr[k + 1];
							n--;
							for (int k = intre; k < strlen(op); k++)
								op[k] = op[k + 1];
							intre--;
							final--;
						}
						else {
							cout << "Eroare impartire la ";
							return 0;
						}
					}
					intre++;

				}
				intre = incep + 1;
				while (intre < final)
				{
					if (op[intre] == '+')
					{
						nr[intre - 1] = nr[intre - 1] + nr[intre];
						for (int k = intre; k < n; k++)
							nr[k] = nr[k + 1];
						n--;
						for (int k = intre; k < strlen(op); k++)
							op[k] = op[k + 1];
						intre--;
						final--;
					}
					else {
						nr[intre - 1] = nr[intre - 1] - nr[intre];
						for (int k = intre; k < n; k++)
							nr[k] = nr[k + 1];
						n--;
						for (int k = intre; k < strlen(op); k++)
							op[k] = op[k + 1];
						intre--;
						final--;
					}
					intre++;

				}
				ok -= 2;
				for (int k = incep; k < strlen(op); k++)
					op[k] = op[k + 1];
				final = incep;
				while (op[final] != ')')final++;
				for (int k = final; k < strlen(op); k++)
					op[k] = op[k + 1];
			}
		}
		while (okp != 0)
		{
			int incep = 0;
			while (op[incep] != '[')incep++;
			int final = incep + 1;
			while (op[final] != ']')final++;
			int intre = incep + 1;
			double partial;
			while (intre < final)
			{
				partial = 1;
				if (op[intre] == '^') {
					for (int p = 0; p < nr[intre]; p++)
						partial = partial * nr[intre - 1];
					nr[intre - 1] = partial;
					for (int k = intre; k < n; k++)
						nr[k] = nr[k + 1];
					n--;
					for (int k = intre; k < strlen(op); k++)
						op[k] = op[k + 1];
					intre--;
					final--;
				}
				else if (op[intre] == '#') {

					partial = pow(nr[intre - 1], (1.0 / nr[intre]));
					nr[intre - 1] = partial;
					for (int k = intre; k < n; k++)
						nr[k] = nr[k + 1];
					n--;
					for (int k = intre; k < strlen(op); k++)
						op[k] = op[k + 1];
					intre--;
					final--;

				}intre++;

			}
			intre = incep + 1;
			while (intre < final)
			{
				partial = 0;
				if (op[intre] == '*') {
					partial = nr[intre - 1] * nr[intre];
					nr[intre - 1] = partial;
					for (int k = intre; k < n; k++)
						nr[k] = nr[k + 1];
					n--;
					for (int k = intre; k < strlen(op); k++)
						op[k] = op[k + 1];
					intre--;
					final--;
				}
				else if (op[intre] == '/') {
					if (nr[intre] != 0)
					{
						partial = nr[intre - 1] / nr[intre];
						nr[intre - 1] = partial;
						for (int k = intre; k < n; k++)
							nr[k] = nr[k + 1];
						n--;
						for (int k = intre; k < strlen(op); k++)
							op[k] = op[k + 1];
						intre--;
						final--;
					}
					else {
						cout << "Eroare impartire la ";
						return 0;
					}
				}intre++;

			}

			intre = incep + 1;
			while (intre < final)
			{
				if (op[intre] == '+')
				{
					nr[intre - 1] = nr[intre - 1] + nr[intre];
					for (int k = intre; k < n; k++)
						nr[k] = nr[k + 1];
					n--;
					for (int k = intre; k < strlen(op); k++)
						op[k] = op[k + 1];
					intre--;
					final--;
				}
				else {
					nr[intre - 1] = nr[intre - 1] - nr[intre];
					for (int k = intre; k < n; k++)
						nr[k] = nr[k + 1];
					n--;
					for (int k = intre; k < strlen(op); k++)
						op[k] = op[k + 1];
					intre--;
					final--;
				}
				intre++;

			}
			okp -= 2;
			for (int k = incep; k < strlen(op); k++)
				op[k] = op[k + 1];
			final = incep;
			while (op[final] != ']')final++;
			for (int k = final; k < strlen(op); k++)
				op[k] = op[k + 1];
		}
		int j = 0;
		double partial;
		while (j < strlen(op) + 1)
		{
			partial = 1;
			if (op[j] == '^') {
				for (int p = 0; p < nr[j + 1]; p++)
					partial = partial * nr[j];
				nr[j] = partial;
				for (int k = j + 2; k < n + 1; k++)
					nr[k - 1] = nr[k];
				n--;
				for (int k = j; k < strlen(op); k++)
					op[k] = op[k + 1];
				j--;
			}
			else if (op[j] == '#') {

				partial = pow(nr[j], (1.0 / nr[j + 1]));
				nr[j] = partial;
				for (int k = j + 2; k < n + 1; k++)
					nr[k - 1] = nr[k];
				n--;
				for (int k = j; k < strlen(op); k++)
					op[k] = op[k + 1];
				j--;

			}j++;

		}
		j = 0;
		while (j < strlen(op) + 1)
		{
			partial = 0;
			if (op[j] == '*') {
				partial = nr[j] * nr[j + 1];
				nr[j] = partial;
				for (int k = j + 2; k < n + 1; k++)
					nr[k - 1] = nr[k];
				n--;
				for (int k = j; k < strlen(op); k++)
					op[k] = op[k + 1];
				j--;
			}
			else if (op[j] == '/') {
				if (nr[j + 1] != 0)
				{
					partial = nr[j] / nr[j + 1];
					nr[j] = partial;
					for (int k = j + 2; k < n + 1; k++)
						nr[k - 1] = nr[k];
					n--;
					for (int k = j; k < strlen(op); k++)
						op[k] = op[k + 1];
					j--;
				}
				else {
					cout << "Eroare impartire la ";
					return 0;
				}
			}j++;

		}
		val = nr[0];
		for (j = 0; j < strlen(op); j++)
		{
			if (op[j] == '+')
				val = val + nr[j + 1];
			else val = val - nr[j + 1];
		}
	}
	else if (ok > 0)
	{
		while (ok > 0)
		{
			int incep = 0;
			while (op[incep] != '(')incep++;
			int final = incep + 1;
			while (op[final] != ')')final++;
			int intre = incep + 1;
			double partial;
			while (intre < final)
			{
				partial = 1;
				if (op[intre] == '^') {
					for (int p = 0; p < nr[intre]; p++)
						partial = partial * nr[intre - 1];
					nr[intre - 1] = partial;
					for (int k = intre; k < n; k++)
						nr[k] = nr[k + 1];
					n--;
					for (int k = intre; k < strlen(op); k++)
						op[k] = op[k + 1];
					intre--;
					final--;
				}
				else if (op[intre] == '#') {

					partial = pow(nr[intre - 1], (1.0 / nr[intre]));
					nr[intre - 1] = partial;
					for (int k = intre; k < n; k++)
						nr[k] = nr[k + 1];
					n--;
					for (int k = intre; k < strlen(op); k++)
						op[k] = op[k + 1];
					intre--;
					final--;

				}intre++;

			}
			intre = incep + 1;
			while (intre < final)
			{
				partial = 0;
				if (op[intre] == '*') {
					partial = nr[intre - 1] * nr[intre];
					nr[intre - 1] = partial;
					for (int k = intre; k < n; k++)
						nr[k] = nr[k + 1];
					n--;
					for (int k = intre; k < strlen(op); k++)
						op[k] = op[k + 1];
					intre--;
					final--;
				}
				else if (op[intre] == '/') {
					if (nr[intre] != 0)
					{
						partial = nr[intre - 1] / nr[intre];
						nr[intre - 1] = partial;
						for (int k = intre; k < n; k++)
							nr[k] = nr[k + 1];
						n--;
						for (int k = intre; k < strlen(op); k++)
							op[k] = op[k + 1];
						intre--;
						final--;
					}
					else {
						cout << "Eroare impartire la ";
						return 0;
					}
				}
				intre++;

			}
			intre = incep + 1;
			while (intre < final)
			{
				if (op[intre] == '+')
				{
					nr[intre - 1] = nr[intre - 1] + nr[intre];
					for (int k = intre; k < n; k++)
						nr[k] = nr[k + 1];
					n--;
					for (int k = intre; k < strlen(op); k++)
						op[k] = op[k + 1];
					intre--;
					final--;
				}
				else {
					nr[intre - 1] = nr[intre - 1] - nr[intre];
					for (int k = intre; k < n; k++)
						nr[k] = nr[k + 1];
					n--;
					for (int k = intre; k < strlen(op); k++)
						op[k] = op[k + 1];
					intre--;
					final--;
				}
				intre++;

			}
			ok -= 2;
			for (int k = incep; k < strlen(op); k++)
				op[k] = op[k + 1];
			final = incep;
			while (op[final] != ')')final++;
			for (int k = final; k < strlen(op); k++)
				op[k] = op[k + 1];
		}
		int j = 0;
		double partial;
		while (j < strlen(op) + 1)
		{
			partial = 1;
			if (op[j] == '^') {
				for (int p = 0; p < nr[j + 1]; p++)
					partial = partial * nr[j];
				nr[j] = partial;
				for (int k = j + 2; k < n + 1; k++)
					nr[k - 1] = nr[k];
				n--;
				for (int k = j; k < strlen(op); k++)
					op[k] = op[k + 1];
				j--;
			}
			else if (op[j] == '#') {

				partial = pow(nr[j], (1.0 / nr[j + 1]));
				nr[j] = partial;
				for (int k = j + 2; k < n + 1; k++)
					nr[k - 1] = nr[k];
				n--;
				for (int k = j; k < strlen(op); k++)
					op[k] = op[k + 1];
				j--;

			}j++;

		}
		j = 0;
		while (j < strlen(op) + 1)
		{
			partial = 0;
			if (op[j] == '*') {
				partial = nr[j] * nr[j + 1];
				nr[j] = partial;
				for (int k = j + 2; k < n + 1; k++)
					nr[k - 1] = nr[k];
				n--;
				for (int k = j; k < strlen(op); k++)
					op[k] = op[k + 1];
				j--;
			}
			else if (op[j] == '/') {
				if (nr[j + 1] != 0)
				{
					partial = nr[j] / nr[j + 1];
					nr[j] = partial;
					for (int k = j + 2; k < n + 1; k++)
						nr[k - 1] = nr[k];
					n--;
					for (int k = j; k < strlen(op); k++)
						op[k] = op[k + 1];
					j--;
				}
				else {
					cout << "Eroare impartire la ";
					return 0;
				}
			}j++;

		}
		val = nr[0];
		for (j = 0; j < strlen(op); j++)
		{
			if (op[j] == '+')
				val = val + nr[j + 1];
			else val = val - nr[j + 1];
		}
	}
	return val;
}


Ecuatie Calcule::getEcuatie()
{
	return ec;
}

bool Calcule::operator<(int num)
{
	if (ec.getNr() < num)return true;
	return false;
}

bool Calcule::operator>(int num)
{
	if (ec.getNr() > num)return true;
	return false;
}

bool Calcule::verificareOrdine()
{
	if (ec.getOperatii() != nullptr)
	{
		int puncte = 0;
		char* ecua = ec.getEcuatie();
		for (int i = 0; i < strlen(ecua) + 1; i++)
			if (ecua[i] == '.')
			{
				puncte++;
			}
		if (puncte > 1)
		{
			int inceppunc = 0;
			while (puncte > 1)
			{
				int ok = 0;
				while (ecua[inceppunc] != '.' && inceppunc < strlen(ecua))inceppunc++;
				int urmatpunc = inceppunc + 1;
				while (ecua[urmatpunc] != '.' && urmatpunc < strlen(ecua))urmatpunc++;
				for (int i = inceppunc; i <= urmatpunc; i++)
					if (strchr("+/*-^#", ecua[i]) != nullptr)ok++;
				if (ok == 0)return false;
				inceppunc = urmatpunc - 1;
				puncte = puncte - 1;
			}

		}
		int ok = 0, okp = 0;
		char* copie = new char[strlen(ec.getOperatii()) + 1];
		strcpy_s(copie, strlen(ec.getOperatii()) + 1, ec.getOperatii());
		for (int i = 0; i < strlen(ec.getOperatii()); i++)
			if (copie[i] == '(' || copie[i] == ')')
			{
				ok++;
			}
			else if (copie[i] == ']' || copie[i] == '[')
			{
				okp++;
			}
		if (ok == 0 && okp == 0)
		{
			return true;
		}
		if (ok % 2 != 0 || okp % 2 != 0)return false;
		if ((ok < okp) && okp != 0)return false;
		if (okp > 0)
		{
			int incepp = 0; int finalp = 0;
			while (copie[incepp] != '[')incepp++;
			while (copie[finalp] != ']')finalp++;
			if (incepp > finalp)return false;
			int ok1 = 0; int ok2 = 0;
			for (int i = incepp; i < finalp; i++)
			{
				if (copie[i] == '(') { ok1++; }
				else if (copie[i] == ')') { ok2++; }
			}
			if (ok1 == 0 || ok2 == 0 || ok1 != ok2)
			{
				return false;
			}
		}
		if (ok > 0)
		{
			int incepp = 0; int finalp = 0;
			while (copie[incepp] != '(')incepp++;
			while (copie[finalp] != ')')finalp++;
			if (incepp > finalp)return false;
			for (int i = incepp + 1; i < finalp; i++)
			{
				if (copie[i] == '(')return false;
			}
		}

		return true;
	}
}

string Calcule::rezultatulEc(double rez)
{
	string l = to_string(rez);
	int i = l.length() - 1;
	int poz = 0;
	for (int i = 0; i < l.length(); i++)
		if (l[i] == '.')poz = i;
	if (poz != 0)
	{
		int nr = 0;
		while (i > 0 && l[i] == '0' && i > poz)
		{
			l[i] = '\0';
			i--;
		}
		if (l[i] == '.')
			l[i] = '\0';

	}
	return l;
}


class Displayable {
private:

public:

	virtual void tipulAfisarii(char c, Calcule obj) = 0;
	virtual void salvareRezultat(Calcule obj) = 0;
	virtual void salvareVector(double* obj, int i, char* erori) = 0;
};


string valide(double rez)
{
	string l = to_string(rez);
	int i = l.length() - 1;
	int poz = 0;
	for (int i = 0; i < l.length(); i++)
		if (l[i] == '.')poz = i;
	if (poz != 0)
	{
		int nr = 0;
		while (i > 0 && l[i] == '0' && i > poz)
		{
			l[i] = '\0';
			i--;
		}
		if (l[i] == '.')
			l[i] = '\0';

	}
	return l;
}


class Fisier :public Displayable
{
private:
public:
	Fisier()
	{

	}

	void tipulAfisarii(char c, Calcule obj) override {
		if (c == 'a')
		{
			char fis[40];
			cout << "Fisierul este: ";
			cin >> ws;
			cin.getline(fis, 39);
			ofstream g(fis, ios::app);
			g << obj;
			cout << endl;
			g.close();
		}
		else if (c == 'b')
		{
			char bin[40];
			cout << "Fisierul este: ";
			cin >> ws;
			cin.getline(bin, 39);
			ofstream f(bin, ios::binary);
			double rez = obj.faceCalcul();
			string rezultat;
			if ((float)rez != (int)0) {
				rezultat = obj.rezultatulEc(rez);
			}
			else rezultat = "0";
			int lungime = rezultat.length();
			f.write((char*)&lungime, sizeof(lungime));
			f.write(rezultat.c_str(), lungime + 1);
			f.close();
		}

	}

	void salvareRezultat(Calcule obj) override
	{
		double rez = obj.faceCalcul();
		string rezultat = obj.rezultatulEc(rez);
		cout << "Pentru urmatoarea ecuatie rezultatul necesar folosirii este " << rezultat << endl;
	}

	void salvareVector(double* obj, int i, char* erori) override
	{
		char fis[40];
		cout << "Fisierul este: ";
		cin >> ws;
		cin.getline(fis, 39);
		ofstream g(fis);
		for (int j = 0; j < i; j++)
		{
			if (erori[j] != 'e')
			{
				string rez = valide(obj[j]);
				g << rez;
			}
			else {
				g << "Imposibil";
			}
			g << endl;
		}
		g.close();
	}
};


class Consola :public Displayable
{
private:
public:
	Consola()
	{

	}
	void tipulAfisarii(char c, Calcule obj) override {
		if (c == 'c')
		{
			double rez = obj.faceCalcul();
			if ((float)rez != (int)0) {
				string rezultat = obj.rezultatulEc(rez);
				cout << rezultat;
			}
			else cout << "0";
			cout << endl;
		}
	}
	void salvareRezultat(Calcule obj) override
	{
		double rez = obj.faceCalcul();
		string rezultat = obj.rezultatulEc(rez);
		cout << "Pentru urmatoarea ecuatie rezultatul necesar folosirii este " << rezultat << endl;
	}
	void salvareVector(double* obj, int i, char* erori) override
	{
		for (int j = 0; j < i; j++)
		{
			if (erori[j] != 'e')
			{
				string rez = valide(obj[j]);
				cout << rez;
			}
			else {
				cout << "Imposibil";
			}
			cout << endl;
		}
	}
};


class Verifica : public Calcule
{
private:
public:
	Verifica()
	{

	}
	Verifica(const Ecuatie& e) :Calcule(e)
	{

	}
	bool verificareOrdine() override
	{
		if (this->verificareCorect(*this))
			return true;

	}
	bool operator<(int num) override {
		if (num > 0)
			return true;
		return false;
	}
	bool verificareCorect(Calcule obj);
	bool verificareCalcul(Calcule obj);
};

bool Verifica::verificareCorect(Calcule obj)
{
	if (obj.verificareOrdine())
		return 1;
	return 0;
}

bool Verifica::verificareCalcul(Calcule obj)
{
	if (obj.faceCalcul())
		return 1;
	return 0;
}




void meniu()
{
	int functiiPrincipale;
	char functiiSecundare;
	int exit = 0;
	int nrbin = 0;
	do {
		cout << "1.Introducere ecuatie de la tastatura\n2.Citire ecuatie din fisier\n3.Exit\n";
		cin >> functiiPrincipale;
		switch (functiiPrincipale)
		{
		case 1:
		{Ecuatie e;
		cin >> e;
		Calcule obiect;
		obiect.setEcuatie(e);
		Verifica v;
		deque<char> inlocuit;
		if (v.verificareCorect(obiect))
		{
			cout << "a.Salvare rezultate in fisier text\nb.Salvare rezultat intermediar in fisier binar\nc.Afisare rezultat la consola\n";
			cin >> functiiSecundare;
			if (functiiSecundare == 'a' || functiiSecundare == 'b')
			{
				Fisier tip;
				tip.tipulAfisarii(functiiSecundare, obiect);
				if (functiiSecundare == 'b')nrbin++;

			}
			else {
				Consola tip;
				tip.tipulAfisarii(functiiSecundare, obiect);
			}
			if (nrbin > 0)
			{
				cout << "Doriti sa folositi rezultatul din fisierul binar? da/nu ";
				string raspuns;
				cin >> raspuns;
				if (raspuns == "da") {
					char bin[40];
					cout << "Fisierul folosit pentru salvarea anterioara este: ";
					cin >> ws;
					cin.getline(bin, 39);
					ifstream f(bin, ios::binary);
					int length = 0;
					f.read((char*)&length, sizeof(length));
					char* buffer = new char[length + 1];
					f.read(buffer, length + 1);
					string rezult;
					rezult = buffer;
					char data[255];
					cout << "Introduceti ecuatia in care se va folosi rezultatul anterior, inlocuind valoarea sa cu x: ";
					cin >> data;
					for (int i = 0; i < strlen(data); i++)
					{
						inlocuit.push_back(data[i]);
					}
					int ok = 0;
					while (inlocuit[ok] != 'x')ok++;
					inlocuit.erase(inlocuit.begin() + ok);
					int k = 0;
					while (k < rezult.length() && rezult[k] != '\0')
					{
						inlocuit.insert(inlocuit.begin() + ok + k, rezult[k]);
						k++;
					}
					int m = inlocuit.size();
					for (int j = 0; j < m; j++)
						data[j] = inlocuit[j];
					data[m] = '\0';
					e.setEcuatie(data);
					obiect.setEcuatie(e);
					if (v.verificareCalcul(obiect))
						cout << obiect.faceCalcul() << endl;

					cout << "Doriti sa salvati rezultatul in fisier binar? da/nu ";
					string raspuns;
					cin >> raspuns;
					if (raspuns == "da")
					{
						Fisier tip;
						tip.tipulAfisarii('b', obiect);
					}

				}
			}
		}
		else cout << "Imposibil" << endl;

		break;
		}

		case 2: {Calcule obiect;
			ifstream h;
			char fis[40];
			cout << "Fisierul este: ";
			cin >> ws;
			cin.getline(fis, 39);
			h.open(fis);
			int i;
			h >> i;
			cout << "a.Salvare rezultate in fisier text\nb.Afisare rezultat la consola\n";
			cin >> functiiSecundare;
			if (functiiSecundare == 'b') {
				double* c = new double[i]; int k = 0; char* erori = new char[i];
				while (i != 0) {
					h >> obiect;
					Verifica v;
					if (v.verificareCorect(obiect))
					{
						if ((float)obiect.faceCalcul() != (int)0)
						{
							c[k++] = obiect.faceCalcul();
						}
						else c[k++] = 0;
					}
					else {
						erori[k] = 'e'; c[k++] = 0;
					}
					i--;

				}
				Consola tip;
				tip.salvareVector(c, k, erori);
			}
			else {
				double* c = new double[i + 1]; int k = 0; int cop = i;
				char* erori = new char[i + 1];
				for (int j = 0; j < i; j++)
					erori[j] = 'c';
				while (i != 0) {
					h >> obiect;
					Verifica v;
					if (v.verificareCorect(obiect))
					{
						if ((float)obiect.faceCalcul() != (int)0)
						{
							c[k++] = obiect.faceCalcul();
						}
						else c[k++] = 0;
					}
					else {
						erori[k] = 'e'; c[k++] = 0;
					}
					i--;
				}
				Fisier tip;
				tip.salvareVector(c, cop, erori);
			}
			h.close();
			break;

		}
		case 3:
		{
			cout << "Exit";
			return;
			break;
		}


		}
	} while (functiiPrincipale != '3');
}


int main(int argc, char** argv)
{

	cout << "Numar ecuatii: " << argc - 1 << endl;
	if (argc > 1) {
		for (int i = 1; i < argc; i++)
		{
			cout << "Ecuatia [" << i << "]: " << argv[i] << endl;
			Ecuatie e;
			e.setEcuatie(argv[i]);
			Calcule obj;
			obj.setEcuatie(e);
			Verifica v;
			if (v.verificareCorect(obj))
			{
				if ((float)obj.faceCalcul() != (int)0)
					cout << "Rezultat= " << obj.faceCalcul() << endl;
				else cout << "Rezultat= " << 0 << endl;
			}
			else { cout << "Imposibil " << endl; }
		}

	}

	meniu();


}