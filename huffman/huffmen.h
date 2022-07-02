/*
 * huffmen.h
 *
 *  Created on: May 8, 2017
 *      Author: ksemenov0
 */

#ifndef HUFFMEN_H_
#define HUFFMEN_H_

#include <iostream>
#include <iomanip>
#include <queue>
#include <map>
#include <climits> // for CHAR_BIT
#include <iterator>
#include <algorithm>



const int UniqueSymbols = 1 << CHAR_BIT;
const char* SampleString =
		"Four score and seven years ago our fathers brought forth on this continent,"
		" a new nation, conceived in Liberty, and dedicated to the proposition that all men are created equal. \n"
		"Now we are engaged in a great civil war, testing whether that nation, or any nation so conceived and "
		"so dedicated, can long endure. We are met on a great battle-field of that war. We have come to dedicate "
		"a portion of that field, as a final resting place for those who here gave their lives that that nation "
		"might live. It is altogether fitting and proper that we should do this. \n"
		"But, in a larger sense, we cannot dedicate -- we cannot consecrate -- we cannot hallow -- this ground. "
		"The brave men, living and dead, who struggled here, have consecrated it, far above our poor power to add or detract. "
		"The world will little note, nor long remember what we say here, but it can never forget what they did here. It is for us "
		"the living, rather, to be dedicated here to the unfinished work which they who fought here have thus far so nobly advanced. "
		"It is rather for us to be here dedicated to the great task remaining before us -- that from these honored dead we take "
		"increased devotion to that cause for which they gave the last full measure of devotion -- that we here highly resolve that these "
		"dead shall not have died in vain -- that this nation, under God, shall have a new birth of freedom -- and that government of "
		"the people, by the people, for the people, shall not perish from the earth.";
const std::string  word = "Four score and seven years ago our fathers brought forth on this continent,"
		" a new nation, conceived in Liberty, and dedicated to the proposition that all men are created equal. \n"
		"Now we are engaged in a great civil war, testing whether that nation, or any nation so conceived and "
		"so dedicated, can long endure. We are met on a great battle-field of that war. We have come to dedicate "
		"a portion of that field, as a final resting place for those who here gave their lives that that nation "
		"might live. It is altogether fitting and proper that we should do this. \n"
		"But, in a larger sense, we cannot dedicate -- we cannot consecrate -- we cannot hallow -- this ground. "
		"The brave men, living and dead, who struggled here, have consecrated it, far above our poor power to add or detract. "
		"The world will little note, nor long remember what we say here, but it can never forget what they did here. It is for us "
		"the living, rather, to be dedicated here to the unfinished work which they who fought here have thus far so nobly advanced. "
		"It is rather for us to be here dedicated to the great task remaining before us -- that from these honored dead we take "
		"increased devotion to that cause for which they gave the last full measure of devotion -- that we here highly resolve that these "
		"dead shall not have died in vain -- that this nation, under God, shall have a new birth of freedom -- and that government of "
		"the people, by the people, for the people, shall not perish from the earth.";

typedef std::vector<bool> HuffCode;
typedef std::map<char, HuffCode> HuffCodeMap;

class INode
{
public:
	const int f;

	virtual ~INode() {}

protected:
	INode(int f) : f(f) {}
};

class InternalNode : public INode
{
public:
	INode *const left;
	INode *const right;

	InternalNode(INode* c0, INode* c1) : INode(c0->f + c1->f), left(c0), right(c1) {}
	~InternalNode()
	{
		delete left;
		delete right;
	}
};

class LeafNode : public INode
{
public:
	const char c;

	LeafNode(int f, char c) : INode(f), c(c) {}
};

struct NodeCmp
{
	bool operator()(const INode* lhs, const INode* rhs) const
	{
		return lhs->f > rhs->f;
	}
};

INode* BuildTree(const int (&frequencies)[UniqueSymbols])
{
	std::priority_queue<INode*, std::vector<INode*>, NodeCmp> trees;



	for (int i = 0; i < UniqueSymbols; ++i)
	{
		if(frequencies[i] != 0)
			trees.push(new LeafNode(frequencies[i], (char)i));

	}
	while (trees.size() > 1)
	{
		INode* childR = trees.top();
		trees.pop();


		INode* childL = trees.top();
		trees.pop();

		INode* parent = new InternalNode(childR, childL);
		trees.push(parent);
	}

	return trees.top();
}

void GenerateCodes(const INode* node, const HuffCode& prefix, HuffCodeMap& outCodes)
{
	if (const LeafNode* lf = dynamic_cast<const LeafNode*>(node))
	{
		outCodes[lf->c] = prefix;

	}
	else if (const InternalNode* in = dynamic_cast<const InternalNode*>(node))
	{
		HuffCode leftPrefix = prefix;
		leftPrefix.push_back(false);
		GenerateCodes(in->left, leftPrefix, outCodes);

		HuffCode rightPrefix = prefix;
		rightPrefix.push_back(true);
		GenerateCodes(in->right, rightPrefix, outCodes);
	}
}
//void frequency()
//{
//
//	struct nodes
//	{
//		std::string letter;
//		int number;
//	};
//
//
//	std::vector <nodes> lists;
//
//	for(int i = 0; i < word.length();i++)
//	{
//
//		if(word[i] == lists[i])
//		{
//
//		}
//	}
//
//}

#endif /* HUFFMEN_H_ */
