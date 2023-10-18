#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

#define NMAX 1000

bool maze[ NMAX ][ NMAX ];
int dist[ NMAX ][ NMAX ];
pair<int, int> A, B;

void cleanMaze(int n){
	for(int i = 0; i < n; i++)
		for( int j = 0 ; j < n ; j++ )
			maze[ i ][ j ] = 0, dist[ i ][ j ] = -1;
}

char cell(int i, int j){
	if( i == B.first and j == B.second ) return 'B';
	if( i == A.first and j == A.second ) return 'A';
	return maze[ i ][ j ] ? ' ':'*';
}

void showMaze(int n){
	for(int i = 0; i < n; i++){
		for( int j = 0 ; j < n ; j++ )
			cout << cell(i, j);
		cout << endl;
	}
}

bool check(int a, int b, int n){
	return a > 0 && b > 0 && a < n && b < n && dist[ a ][ b ] == -1;
}

void randomDFS(int i, int j, int n, int d){

	dist[ i ][ j ] = d;
	maze[ i ][ j ] = true;

	random_device rd;
	mt19937 g(rd());

	vector< pair<int, int> > moves{{2, 0}, {-2, 0}, {0, 2}, {0, -2}};
	shuffle( moves.begin(), moves.end() , g);

	int x, y;

	for( auto move: moves ){
		x = move.first;
		y = move.second;
		if( !check(i + x, j + y, n) ) continue;
    		maze[ i + x/2 ][ j + y/2 ] = true;
		randomDFS( i + x, j + y, n, d + 1);
	}

}

void findB(int n){
	int xB, yB;
	for(int i = 0; i < n; i++)
		for( int j = 0 ; j < n ; j++ ){
			xB = B.first;
			yB = B.second;
			if( dist[ xB ][ yB ] < dist[ i ][ j ] )
				B = make_pair( i , j );
		}
}

void createMaze2D(int n){
	A = make_pair(1, 1);
	B = make_pair(-1, -1);

	cleanMaze(n);
	randomDFS( 1, 1, n , 0 );
	findB(n);
	showMaze(n);
}

int main(){
	createMaze2D(21);
}
