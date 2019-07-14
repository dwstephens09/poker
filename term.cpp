/* File: term.cpp
 * Course: CS216-00x
 * Project: Lab12 (as part of Project 3)
 * Purpose: the implementation of member functions for the Term class.
 *
 */
#include <iostream>
#include "term.h"

// default constructor
Term::Term()
{
	query = "";
	weight = 0;
}

// initializes a term with the given query string and weight
Term::Term(string query, long weight)
{
	this->query = query;
	this->weight = weight;
}

// compares the two terms in descending order by weight
// compares the two terms in descending order by weight
// if the order of T1 and T2 in descending order by weight, return 1;
// if T1 and T2 are of the same weight, return 0;
// otherwise return -1
int Term::compareByWeight(const Term& T1, const Term& T2)
{
	if (T1.weight > T2.weight)
		return 1;
	else if (T1.weight < T2.weight)
		return -1;
	else
		return 0;	
}

// compares the two terms in lexicographic order but using only the first r characters of each query
int Term::compareByPrefix(const Term& T1, const Term& T2, int r)
{
	string term1 = T1.query.substr(0,r);
	string term2 = T2.query.substr(0,r);

	if (term1 < term2)
		return 1;
	else if (term1 > term2)
		return -1;
	else
		return 0;
}

// operator overloading for operators "<" and "<<"
// they both are defined as friend functions

// define the operator "<" for Term class
bool operator<(const Term& T1, const Term& T2)
{
	if (T1.query < T2.query)
		return true;
	else
		return false;
}

// define the operator "<<" for Term class
// to send the Term object to the cout, in the following format:
// the weight, followed by a tab key, followed by the query
ostream& operator<<(ostream &out, const Term& t)
{
    // return (out << b.name << "\t( ID: " << setfill('0') << setw(DIGITS) << b.ID << " ) ---> " << b.coordinate); 
	return (out << t.weight << "\t" << t.query);
}
