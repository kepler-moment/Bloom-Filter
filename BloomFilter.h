/*
 * BloomFilter.h
 *
 *  Created on: 2014Äê9ÔÂ13ÈÕ
 *      Author: Kepler-Moment
 */

#ifndef BLOOMFILTER_H_
#define BLOOMFILTER_H_

#include<bitset>
#include<string>
#include<cstdlib>
#include "BloomFilter.h"
#include "MurmurHash3.h"
using namespace std;

#define MAXNUMOFBITS 1 << 20
#define NUMOFPRIMERNUMS 46

const int primerNumber[NUMOFPRIMERNUMS] = {2,3,5,7,11,13,17,19,23,29,
							31,37,41,43,47,53,59,61,67,71,
							73,79,83,89,97,101,103,107,109,113,
							127,131,137,139,149,151,157,163,167,
							173,179,181,191,193,197,199};

class BloomFilter
{
private:
	bitset<MAXNUMOFBITS> bf;			//
	unsigned int k;					//number of hashes
public:
	BloomFilter(unsigned int numOfHashes);

	//insert key words str into BloomFilter
	void insert(string str);

	//reset BloomFilter
	void reset(unsigned int numOfHashes);

	//search str
	bool search(string str);
};


#endif /* BLOOMFILTER_H_ */
