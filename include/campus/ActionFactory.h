#pragma once
// Factory 模式:集中建立行動物件,GameEngine 不用知道每個子類別的名字。
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "campus/Action.h"
#include "campus/Config.h"
#include "campus/Rng.h"

namespace campus {

class ActionFactory {
public:
    ActionFactory(const Config& cfg, Rng& rng);

    // id:study / lateNight / sleep / work / club / play;不認識的 id 回傳 nullptr
    std::unique_ptr<Action> create(const std::string& id) const;
    // 依選單順序建立全部行動
    std::vector<std::unique_ptr<Action>> createAll() const;

    // 新增行動時只要在這裡註冊一個 creator,主程式完全不用改
    void registerAction(const std::string& id,
                        std::function<std::unique_ptr<Action>()> creator);
    const std::vector<std::string>& ids() const { return order_; }

private:
    std::map<std::string, std::function<std::unique_ptr<Action>()>> creators_;
    std::vector<std::string> order_;
};

}  // namespace campus
