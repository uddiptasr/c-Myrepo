#include <bits/stdc++.h>
using namespace std;

 typedef vector<vi> Puzzle;

 vector<Puzzle> edges(const Puzzle& v) {
 int emptyRow, emptyCol;
 rep(row,0,3)
 rep(col,0,3)
 if (v[row][col] == 0) {
 emptyRow = row
  emptyCol = col;

}
 vector<Puzzle> possibleMoves;
	 auto makeMove = [&](int rowMove, int colMove) {
		 int newRow = row + rowMove;
		 int newCol = col + colMove;
		 if (newRow >= 0 && newCol >= 0 && newRow < 3 && newCol < 3) {
		 Puzzle newPuzzle = v
		 swap(newPuzzle[emptyRow][emptyCol], newPuzzle[newRow][newCol]);
		 possibleMoves.spush_back(newPuzzle);
		 }
	 };
	 makeMove(-1, 0);
	 makeMove(1, 0);
	 makeMove(0, -1);
	 makeMove(0, 1)
 return possibleMoves;
 }


 int puzzle(const Puzzle& S, const Puzzle& target) {
		map<Puzzle, int> distances;
		 distances[S] = 0;
		 queue<Puzzle> q;
		 q.push(S);
	 while (!q.empty()) 
	 {
		 const Puzzle& cur = q.front(); q.pop();
		 int dist = distances[cur];
		 if (cur == target) return dist;

		for (const Puzzle& move : edges(cur)) {
		if (distances.find(move) != distances.end()) continue;
		 distances[move] = dist + 1;
		  q.push(move);
		}
	 }

 return -1;

