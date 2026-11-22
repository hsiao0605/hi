#pragma once
// Action:所有行動的抽象父類別。
// Template Method:perform() 固定「檢查 → 扣行動點 → 執行效果」的順序,
// 子類別只需要實作 apply()(以及視需要覆寫 canDo())。
#include <string>
#include <utility>
#include <vector>
#include "campus/Player.h"

namespace campus {

class Action {
public:
    Action(std::string name, int cost, int minHealth = 20)
        : name_(std::move(name)), cost_(cost), minHealth_(minHealth) {}
    virtual ~Action() = default;

    // 成功執行回傳 true;不能做時留下訊息、數值不變、回傳 false
    bool perform(Player& p);

    // 預設條件:健康 >= minHealth 且行動點足夠
    virtual bool canDo(const Player& p) const;

    // 給選單顯示的效果說明,例如 "學業 +8、壓力 +5、健康 -3"
    virtual std::string describe() const = 0;

    const std::string& getName() const { return name_; }
    int getCost() const { return cost_; }

protected:
    virtual void apply(Player& p) = 0;  // 純虛擬函式,子類別一定要實作

    int minHealth() const { return minHealth_; }
    // 把 {{"學業",8},{"壓力",5}} 變成 "學業 +8、壓力 +5"
    static std::string formatEffects(const std::vector<std::pair<std::string, int>>& effects);

private:
    std::string name_;
    int cost_;
    int minHealth_;
};

}  // namespace campus
