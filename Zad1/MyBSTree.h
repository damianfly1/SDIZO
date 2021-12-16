#pragma once
#include <iostream>
#include <time.h>
#include <fstream>
#include <windows.h>
#include <string>
#define COUNT 10

using namespace std;

struct TreeNode {
	int key = NULL;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
	TreeNode* parent = NULL;
};

class MyBSTree {

private:
	TreeNode* root = NULL; //wskaznik na korzen
	int* vec_left; //wskaznik na talblice uzywana przy wyswietlaniu
	void deleteNode(TreeNode*); //usun jeden z wezlow
	void deleteChildren(TreeNode* node); //usun wszyskie wezly
	TreeNode* findNode(int); //znajdz wezel
	TreeNode* findSuccessor(TreeNode*); //znajdz nastepnika
	TreeNode* findPredecessor(TreeNode*); //znajdz poprzednika
	TreeNode* findMinKey(TreeNode*); //znajdz klucz mininalny
	TreeNode* findMaxKey(TreeNode*); //znajdz klucz maksymalny	
	void rotateRight(TreeNode*); //rotacja w prawo
	void rotateLeft(TreeNode*); //rotacja w lewo
	int countNodes(); //policz liczbe wezlow w drzewie wyprostowanym
	void printTree(TreeNode*, int); //wyswietl drzewo

public:
	~MyBSTree(); //dekonstruktor 
	void createRandom(int);
	bool createFromFile(); //utworz z pliku
	bool createRandom(); //utworz losowo 
	void showAll(); //wyswietl 
	bool findElement(int); //zwroc informacje czy wezel istnieje
	void insertNode(int); //wstaw wezel
	void deleteKey(int); //wstaw wezel
	bool empty(); //zwroc informacje czy struktura pusta
	void createLinearTree(); //wyprostuj drzewo
	void createBalancedTree(); //zbalansuj drzewo
};