#include <iostream>
#include <ctime>
#include <cstdint>

#define GEN_SIZE 4

using namespace std;

/*! @brief  Cell class
	@param genome
	Genome of the cell
	@param age
	Age of the cell
*/ 
class Cell {
	public:
		Cell(string genome) {
			genome.resize(GEN_SIZE);
			this->genome = genome;
		}
		string getGenome() {
			return genome;
		}
		void setGenome(const string genome) {
			this->genome.resize(GEN_SIZE);
			this->genome = genome;
		}
	private:
		string genome;
		uint32_t age = 0;
	friend string merge(const Cell c1, const Cell c2);
	friend string mergeM(const Cell c1, const Cell c2, const uint16_t probMutation, const string mutationLetters);
};

string merge(const Cell c1, const Cell c2) {
	string res;
	res.resize(GEN_SIZE);
	for(uint32_t i = 0; i < c1.genome.length(); i++) {
		if (rand() % 2 == 0) {
			res[i] = c1.genome[i];
		} else {
			res[i] = c2.genome[i];
		}
	}
	return res;
}

string mergeM(const Cell c1, const Cell c2, const uint16_t probMutation, const string mutationLetters) {
	string res;
	res.resize(GEN_SIZE);
	for(uint32_t i = 0; i < c1.genome.length(); i++) {
		if (rand() % 2 == 0) {
			res[i] = c1.genome[i];
		} else {
			res[i] = c2.genome[i];
		}
	}
	if ((rand() % 100) + 1 <= probMutation) {
		res[rand() % GEN_SIZE] = mutationLetters[rand() % mutationLetters.length()];
	}
	return res;
}

int32_t main(int32_t argc, char* argv[])
{
	srand(time(NULL));
	Cell c1("abcd");
	Cell c2("dcba");
	Cell c3(mergeM(c1, c2, 100, "efgh"));
	cout << c3.getGenome() << endl;
	system("pause");
	return 0;
}
