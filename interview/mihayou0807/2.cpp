#include <bits/stdc++.h>
using namespace std;

bool chaos = false;  // 是否处于混乱状态

class Hero {
 public:
  int hp;   // 生命值
  int att;  // 攻击力
  int def;  // 防御力
  int spd;  //速度

  Hero(int a, int b, int c, int d) : hp(a), att(b), def(c), spd(d) {}

  void simple_attack(Hero &hero);
  void active(Hero &hero);
  void passive(Hero &hero);
};

class Vivian : public Hero {
 public:
  bool att_inc;  // 为false时才可以提升攻击力
  string success = "I love V2V forever!";

  Vivian(int a, int b, int c, int d) : Hero(a, b, c, d) { att_inc = false; }

  void simple_attack(Hero &qian) { qian.hp -= max(att - qian.def, 0); }

  void active(Hero &qian) {
    qian.hp -= max(att - qian.def, 0);
    chaos = true;
  }

  void passive(Hero &qian) {
    if (hp < 31) {
      // 给俩英雄增加生命值
      hp += 20;
      qian.hp += 20;
      // 永久攻击力+15（仅限1次）
      if (att_inc == false) {
        att += 15;
        att_inc = true;
      }
    }
  }
};

class Qian : public Hero {
 public:
  int original_hp;
  string success = "Kalpas yame te!";

  Qian(int a, int b, int c, int d) : Hero(a, b, c, d) {
    chaos = false;
    original_hp = a;
  }

  void simple_attack(Hero &vivian) {
    if (chaos) {
      chaos = false;
      hp -= max(0, att - def);
    } else {
      vivian.hp -= max(0, att - vivian.def);
    }
  }

  void active(Hero &vivian) {
    if (hp >= 11) {
      hp -= 10;
      vivian.hp -= max(45 - vivian.def, 0);
      vivian.hp -= 20;  // 45固定伤害 + 20元素直接伤害
    } else {
      simple_attack(vivian);
    }
  }

  void passive(Hero &vivian) {
    // 更新攻击力
    // 考虑生命值超过初始的情况，攻击力不变化
    if (hp <= 100) {  // original_hp
      att = att + (100 - hp) / 5;
    }
  }
};

string solve(Vivian &vivian, Qian &qian) {
  int round = 1;
  while (vivian.hp > 0 && qian.hp > 0) {
    // 总是先触发被动
    if (vivian.spd > qian.spd) {
      // vivian速度快则先开始
      // vivian攻击

      vivian.passive(qian);
      if (round % 3 != 0) {
        // 普通攻击
        vivian.simple_attack(qian);
      } else {
        vivian.active(qian);
      }

      cout << "Vivian" << vivian.hp << endl;
      cout << "Qian" << qian.hp << endl;

      // 判断是否死亡
      if (qian.hp <= 0) break;

      // qian攻击
      qian.passive(vivian);
      if (round % 3 != 0) {
        // 普通攻击
        qian.simple_attack(vivian);
      } else {
        qian.active(vivian);
      }

      cout << "Vivian" << vivian.hp << endl;
      cout << "Qian" << qian.hp << endl;

      if (vivian.hp <= 0) break;

    } else {
      // qian速度快或一样
      // qian攻击
      qian.passive(vivian);
      if (round % 3 != 0) {
        // 普通攻击
        qian.simple_attack(vivian);
      } else {
        qian.active(vivian);
      }

      cout << "Vivian" << vivian.hp << endl;
      cout << "Qian" << qian.hp << endl;

      if (vivian.hp <= 0) break;

      // vivian攻击
      vivian.passive(qian);
      if (round % 3 != 0) {
        // 普通攻击
        vivian.simple_attack(qian);
      } else {
        vivian.active(qian);
      }

      cout << "Vivian" << vivian.hp << endl;
      cout << "Qian" << qian.hp << endl;

      // 判断是否死亡
      if (qian.hp <= 0) break;
    }

    ++round;
  }
  if (qian.hp <= 0) return vivian.success;

  return qian.success;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int hp, att, def, spd;
    cin >> hp >> att >> def >> spd;
    Vivian vivian(hp, att, def, spd);
    cin >> hp >> att >> def >> spd;
    Qian qian(hp, att, def, spd);
    cout << solve(vivian, qian) << endl;
  }

  return 0;
}

/*
3
100 100 100 100
100 1 1 1
100 100 1 100
100 100 1 1
100 20 12 25
100 23 9 261
*/