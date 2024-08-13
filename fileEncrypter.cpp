#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

const uint64_t key = 1234567890;

inline int16_t getSize(int64_t size) {
	if(size < 8) {return size;} else {return 8;}
}
 
int32_t main(int32_t const argc, char const *argv[])
{	
	fstream infile ("DesertEnc.jpg", fstream::binary | fstream::in);
	fstream outfile ("Desert.jpg", fstream::binary | fstream::out);

	infile.seekg(0, ios::end);
	int64_t size = infile.tellg();
	infile.seekg(0);
	char buffer[8] = {};
	uint64_t buff = 0;
	int64_t lastSize = size;
	cout << size << endl;
	for(uint64_t i = 0; i < ceil((long double)size / 8.0); i++) {
		if(lastSize < 8) {
			infile.read(buffer, lastSize);
		} else {
			infile.read(buffer, 8);
		}
		
		for(uint64_t j = 0; j < getSize(lastSize); j++)
		{
			buff |= (long long)buffer[j] << (j * 8);
		}
		
		buff ^= key;

		for(uint64_t j = 0; j < getSize(lastSize); j++)
		{
			buffer[j] = (long long)buff >> (j * 8);
		}
		
		if(lastSize < 8) {
			outfile.write(buffer, lastSize);
		} else {
			outfile.write(buffer, 8);
		}

		lastSize -= 8;
	}
	return 0;
}
