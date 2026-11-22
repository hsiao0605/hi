# 大學生存日記 Campus Survival

AOOP 期末專題:用 C++物件導向設計做的回合制文字養成遊戲。
玩家要在一個學期(16 週 × 5 天 × 每天 3 行動點)內平衡「學業、健康、壓力、社交」,應付隨機事件,走向 7 種結局之一。

## 編譯與執行

需要:g++(C++17)、CMake ≥ 3.16。
```bash
cmake -S . -B build
cmake --build build -j

cd build
./campus_survival                  # 開始遊戲(讀取同資料夾的 balance.json)
./campus_survival --seed 42        # 固定亂數種子(每次事件都一樣)
./campus_survival --config ../balance_tuned.json   # 用調校版數值
./campus_tests                     # 單元測試(GoogleTest)
./simulate --runs 2000             # 數值平衡模擬器
```

Ubuntu 安裝相依套件:`sudo apt install g++ cmake libgtest-dev nlohmann-json3-dev`
Windows(VS Code + MinGW)直接用 CMake 即可,第一次建置會自動下載相依套件。

## 遊戲操作

主選單輸入 `1` 開新遊戲、`2` 繼續存檔。每天:早上可能有事件(輸入選項編號)→ 白天輸入行動編號(`0` 結束這天、`q` 離開)→ 晚上自動結算。
每週末自動存檔到 `save.json`;遊戲結束(任何結局)後存檔會被刪除。中途按 `q` 離開會回到上個週末的存檔。
