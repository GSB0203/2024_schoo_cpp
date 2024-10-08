//https://nypc.github.io/2018/2018_online_4
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

const int numOfPlayer = 8;
const int score[] = {10, 8, 6, 5, 4, 3, 2, 1};

//선수 클래스
class Player {
private:
    //팀 종류(red,  blue)
  string teamType;
    //점수(10 ~ 0)
  int score;
    //기록(초단위로 바꾼값)
  double record;
public:
    //생성자
    explicit Player(string teamType="", int score=0, double record=0.0) : teamType(std::move(teamType)), score(score), record(record) {}
    //get, set 메서드들
    const string &getTeamType() const {
      return teamType;
    }

    void setTeamType(const string &teamType) {
      Player::teamType = teamType;
    }

    int getScore() const {
      return score;
    }

    void setScore(int score) {
      Player::score = score;
    }

    double getRecord() const {
      return record;
    }

    void setRecord(double record) {
      Player::record = record;
    }
};

//게임 클래스
class Game {
private:
//게임종류(스피드전, 아이템전)
    string type;
//이긴팀(blue or red)
    string winner;
//선수배열(벡터)
    vector<Player> players;
//팀별 점수합계(blue, red)
    int blueScore, redScore;

//승자 세팅(아이템전 -player[0]의 팀에따라 결정, 스피드전 - 두팀의 합산스코어를 비교)
    void setWinner() {
//item
      if(type == "item") {
        if(players[0].getTeamType() == "blue")
          winner = "blue";
        else
          winner = "red";
      }
//speed
      else {
//두팀의 스코어가 같을 경우(첫번째 주자의 팀이 승리)
        if (redScore == blueScore) {
          if (players[0].getTeamType() == "red")
            winner = "red";
          else
            winner = "blue";
        }
//아닌경우 합산스코어가 높은 팀이 승리
        else if(redScore > blueScore)
          winner = "red";
        else
          winner = "blue";
      }
    }

public:
//생성자
    explicit Game(string type = "", string winner ="", int blueScore =0, int redScore=0) : type(std::move(
            type)), winner(std::move(winner)), players(numOfPlayer), blueScore(blueScore), redScore(redScore) {}

//정렬기준(오름차순)
    static bool sortRank(const Player& p1, const Player& p2) {
      return p1.getRecord() < p2.getRecord();
    }

//기록에 따른 점수처리
    void update() {
//먼저 기록 정렬(players[0] ->1등기록이 되도록)
      std::sort(players.begin(), players.end(), sortRank);

//플레이어를 for문으로 돌면서 record에 따른 score 책정(1등과 10초 이상 차이시 0점)
      int order =0;
      double bestRec = 0.0;
      for(auto &player: players){
//1등 기록 베스트 기록으로 저장
        if(order == 0) {
          bestRec = player.getRecord();
          player.setScore(score[order]);
        }
//나머지는 베스트기록과 비교해서 10초이상 차이나면 recode 0점
        else if(player.getRecord() >= bestRec + 10.0) {
          player.setScore(0);
        }
//아니면 10~1점까지 저장
        else
          player.setScore(score[order]);
//팀별 점수를 즉각 합산
        if(player.getTeamType() == "blue")
          blueScore += player.getScore();
        else
          redScore += player.getScore();
        order ++;
      }

//승자 세팅
      setWinner();
    }

//static 문자열기록(xx:xx.xx) -> 숫자 기록(xxx초)으로 변경
    static double getTimeRecord(const string& strRec, char c){
      string str;
      double dRec;
      int token;
//':'문자가 있는 인덱스 값 찾아서 token에 저장
      token = strRec.find(c);
//분단위 부터 잘라서 초로 바꾸어 저장
      str = strRec.substr(0, token);
      dRec = atof(str.c_str()) *60;
//초단위 잘라서 더해서 최종저장
      str = strRec.substr(++token, strRec.length());
      dRec = dRec +atof(str.c_str());
      return dRec;
    }

//get, set 메서드들
    const string &getType() const {
      return type;
    }

    void setType(const string &type) {
      Game::type = type;
    }

    const string &getWinner() const {
      return winner;
    }


    vector<Player> &getPlayers(){
      return players;
    }

    void setPlayers(const vector<Player> &players) {
      Game::players = players;
    }

    int getBlueScore() const {
      return blueScore;
    }

    void setBlueScore(int blueScore) {
      Game::blueScore = blueScore;
    }

    int getRedScore() const {
      return redScore;
    }

    void setRedScore(int redScore) {
      Game::redScore = redScore;
    }
};


int main() {
  //테스트 케이스 수(t) 입력
  int t; cin>>t;
  //t계수 만큼 게임, 팀 종류 및 기록 입력받고 저장
  vector<Game> games(t);
  for(int i=0;i<t;i++) {
    //게임 종류 입력 및 저장
    string type; cin>>type;
    games[i].setType(type);
    //팀 종류 및 기록 입력 저장
    for(int j=0;j<numOfPlayer;j++) {
      string team, rec;
      cin>>team>>rec;

      games[i].getPlayers()[j].setTeamType(team);
      games[i].getPlayers()[j].setRecord(Game::getTimeRecord(rec, ':'));
    }
  }
  //게임 결과 출력
  for(auto game : games) {
    game.update();
    cout<<game.getWinner()<<endl;
  }
  return 0;
}

