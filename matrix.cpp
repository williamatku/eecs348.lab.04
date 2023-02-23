#include <stdio.h>
#include <iostream>
#include <fstream>
#include "matrix.h"

void matrix::createMatrix()
{
	std::ifstream inFile;
	inFile.open("input.txt");
	inFile>>rows;
	inFile>>cols;
	grid = new double*[rows];
	grid_temp = new double*[rows];
	for(int i = 0; i<rows; i++){
		grid[i] = new double[cols];
		grid_temp[i] = new double[cols];
	}
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			inFile>>grid[i][j];
		}
	}
	return;
}

void matrix::printMatrix(){
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
				std::cout<<grid[i][j]<<"\t";
		}
		std::cout<<"\n";
	}
}

void matrix::addMatrix(){
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			grid_temp[i][j] = grid[i][j]+grid[i][j];
		}
	}
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			std::cout<<grid_temp[i][j]<<"\t";
		}
		std::cout<<"\n";
	}
}

// William Morris, 3057236
double matrix::getMax(){
	double max_element = 0; // init double var
	for (int i = 0; i < this->rows; i++) {
	for (int j = 0; j < this->cols; j++) {
		if (this->grid[i][j] > max_element) max_element = this->grid[i][j]; // assign any bigger element to max element
	}}
	return max_element;
}

// William Morris, 3057236
bool matrix::findElement(int no){
	bool found = 0; // no has not been found...
	for (int i = 0; i < this->rows; i++) {
	for (int j = 0; j < this->cols; j++) {
		if (this->grid[i][j] == no) { // if no exists within the matrix
			found = 1; // no has been found
			printf("Element found at %d, %d !\n",i,j); // alert the user
		};
	}}
	return found;
}

// William Morris, 3057236
void matrix::changeElement(int r, int c, int no){
	if (r >= this->rows || c >= this->cols) {
		return; // exit if r, c are out of bounds
	}
	this->grid[r][c] = no; // reassign grid at r, c = no
}

// William Morris, 3057236
void matrix::multiplyMatrix(){
	for(int i = 0; i<rows; i++){
	for(int j = 0; j<cols; j++){
		// For every matrix cell

		// Clean val of cell
		grid_temp[i][j] = 0;

		// And add 
		// every row element of matrix 1 * every col element of matrix 2
		// To the final result
		for (int k = 0; k<rows && k<cols; k++) {
			grid_temp[i][j] += grid[i][k]*grid[k][j];
		}
	}}


	// Print
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			std::cout<<grid_temp[i][j]<<"\t";
		}
		std::cout<<"\n";
	}
}

// William Morris, 3057236
void matrix::transposeMatrix() {
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			// print matrix in Transpose order, j, i vs i, j
			std::cout<<grid[j][i]<<"\t";
		}
		std::cout<<"\n";
	}
}

matrix::~matrix(){
        for(int i = 0; i<rows; i++){
                delete[] grid[i];
                delete[] grid_temp[i];
        }
        delete[] grid;
        delete[] grid_temp;
}