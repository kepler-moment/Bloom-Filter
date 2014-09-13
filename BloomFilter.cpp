/*
 * BloomFilter.cpp
 *
 *  Created on: 2014Äê9ÔÂ13ÈÕ
 *      Author: Kepler-Moment
 */


#include "BloomFilter.h"
#include "MurmurHash3.h"
#include<assert.h>

BloomFilter::BloomFilter(unsigned int numOfHashes)
{
	assert(numOfHashes < NUMOFPRIMERNUMS);
	k = numOfHashes;
}

void BloomFilter::insert(string str)
{
	for(unsigned i = 0;i < k;i++)
	{
		unsigned hashkey;
		MurmurHash3_x86_32(str.c_str(),str.length(),primerNumber[i],&hashkey);
		hashkey %= MAXNUMOFBITS;
		bf.set(hashkey);
	}
}

bool BloomFilter::search(string str)
{
	for(unsigned i = 0;i < k;i++)
	{
		unsigned hashkey;
		MurmurHash3_x86_32(str.c_str(),str.length(),primerNumber[i],&hashkey);
		hashkey %= MAXNUMOFBITS;
		if(!bf[hashkey])
			return false;
	}
	return true;
}

void BloomFilter::reset(unsigned int numOfHashes)
{
	assert(numOfHashes < NUMOFPRIMERNUMS);
	k = numOfHashes;
	bf.reset();
}
