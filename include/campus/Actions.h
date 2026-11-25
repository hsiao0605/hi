#pragma once
// 六種具體行動。數值都從 balance.json 讀,預設值就是提案裡的暫定數值。
#include <memory>
#include "campus/Action.h"
#include "campus/Config.h"
#include "campus/Rng.h"
#include "campus/StudyStrategy.h"

namespace campus {

class StudyAction : public Action {
public:
    StudyAction(const Config& cfg, std::unique_ptr<StudyStrategy> strategy);
    std::string describe() const override;
protected:
    void apply(Player& p) override;
private:
    int academic_, stress_, health_;
    std::unique_ptr<StudyStrategy> strategy_;
};

class LateNightStudyAction : public Action {
public:
    explicit LateNightStudyAction(const Config& cfg);
    bool canDo(const Player& p) const override;  // 健康 >= minHealth_
    std::string describe() const override;
protected:
    void apply(Player& p) override;
private:
    int academic_, stress_, health_, needHealth_, streakPenalty_;
};

class SleepAction : public Action {
public:
    explicit SleepAction(const Config& cfg);
    bool canDo(const Player& p) const override;  // 任何時候都可以睡(只要還有行動點)
    std::string describe() const override;
protected:
    void apply(Player& p) override;
private:
    int health_, stress_;
};

class WorkAction : public Action {
public:
    explicit WorkAction(const Config& cfg);
    std::string describe() const override;
protected:
    void apply(Player& p) override;
private:
    int money_, health_, stress_;
};

class ClubAction : public Action {
public:
    ClubAction(const Config& cfg, Rng& rng);
    std::string describe() const override;
protected:
    void apply(Player& p) override;
private:
    int social_, stress_, health_, bonusSocial_;
    double eventChance_;
    Rng& rng_;
};

class PlayAction : public Action {
public:
    explicit PlayAction(const Config& cfg);
    bool canDo(const Player& p) const override;  // 身上要有足夠的錢
    std::string describe() const override;
protected:
    void apply(Player& p) override;
private:
    int social_, stress_, academic_, money_;  // money_ 為負數(花費)
};

}  // namespace campus
