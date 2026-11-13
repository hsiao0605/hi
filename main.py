int main() {

    srand(static_cast<unsigned int>(time(0)));

    string name;

    cout << "請輸入你的角色名稱：";
    getline(cin, name);

    if (name.empty()) {
        name = "Student";
    }

    GameManager game(name);

    game.startGame();

    return 0;
}
