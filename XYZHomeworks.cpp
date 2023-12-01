/**
 * @file XYZHomeworks.cpp
 *
 * @brief XYZ homeworks of c++ of game developers
 *
 * @author @sup4eg
 *
 */


#include <iostream>
#include <string>
using namespace std;


constexpr int NUM_BALLS = 20; //compile time constant

class XYZHomework12 {


public:  

  //Get index here
  int getArticle() {
 
	cout << "Enter article: ";
	int article = -1;
	cin >> article;

	return article;
  }

  //Check that article is right
  bool isCorrectArticle(int article) {
	if (article < 0 || article > NUM_BALLS - 1) {
	  cout << "Incorrect article!" << endl;
	  return false;
	}
	return true;
  }

  void initializeBallsArray(int balls[]) {
	for (int i = 0; i < NUM_BALLS; ++i) {
	  balls[i] = 0;
	}
	readBallsInArray(balls);
  }

  void readBallsInArray(int balls[]) {
	for (int i = 0; i < NUM_BALLS; ++i) {
	  cout << "balls[" << i << "] = " << balls[i] << endl;
	}
  }
  
  //1
  void addBall(int balls[], int article) {
	if (isCorrectArticle(article)) {
	  balls[article] += 1;
	  readBallsByArticle(balls, article, true);
	}
  }

  //2
  void removeBall(int balls[], int article) {
	if (isCorrectArticle(article)) {
	  balls[article] -= 1;
	  readBallsByArticle(balls, article, true);
	}
  }

  //3
  void readBallsByArticle(int balls[], int article, int isArticleSave) {
	string articleLog = "There are " + to_string(balls[article]) + " balls of article " + to_string(article);
	if (isArticleSave) {
	  cout << articleLog << endl;
	}
	else {
	  if (isCorrectArticle(article)) {
		cout << articleLog << endl;
	  }
	}
  }

  //4
  void countTotalBalls(int balls[]) {
	int sum = 0;
	for (int i = 0; i < NUM_BALLS; ++i) {
	  sum += balls[i];
	}
	cout << "The total amount of balls in array is: " << sum << endl;
  }

  //5
  void checkNeededBalls(int balls[]) {
	for (int i = 0; i < NUM_BALLS; ++i) {
	  if (balls[i] == 0) {
		cout << "There are no balls of article " << i << endl;
	  }
	}
  }
  

  //Run main manager here
  void runBallsManager() {
	int balls[NUM_BALLS];
	initializeBallsArray(balls);

	bool sholdContinue = true;
	while (sholdContinue) {

	  cout << "List of commands: " << endl;
	  cout << "0 - Exit" << endl;
	  cout << "1 - Add ball" << endl;
	  cout << "2 - Remove ball" << endl;
	  cout << "3 - Count balls" << endl;
	  cout << "4 - Total balls" << endl;
	  cout << "5 - Needed balls" << endl;
	  cout << ">: ";
	  string command;
	  cin >> command;

	  if (command == "1") {
		addBall(balls, getArticle());
	  }
	  else if (command == "2") {
		removeBall(balls, getArticle());
	  }
	  else if (command == "3") {
		readBallsByArticle(balls, getArticle(), false);
	  }
	  else if (command == "4") {
		countTotalBalls(balls);
	  }
	  else if (command == "5") {
		checkNeededBalls(balls);
	  }
	  else if (command == "0") {
		cout << "Bye!" << endl;
		sholdContinue = false;
	  }
	  else {
		cout << "Unknows commmand " << command << endl;
	  }

	}

  }

};


int main()
{
  XYZHomework12 homework12 = XYZHomework12();
  homework12.runBallsManager();
}