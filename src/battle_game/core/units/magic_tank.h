#pragma once
#include "battle_game/core/unit.h"
#include "battle_game/core/units/tiny_tank.h"
namespace battle_game::unit {
class MagicTank : public Tank {
 public:
  MagicTank(GameCore *game_core, uint32_t id, uint32_t player_id);
  void Render() override;
  void Update() override;

  [[nodiscard]] bool IsHit(glm::vec2 position) const override;

 protected:
  void TankMove(float move_speed, float rotate_angular_speed);
  void TurretRotate();
  void Protect();
  void Death();
  void ProtectClick();
  void DeathClick();
  void Magic();
  void Fire();

  [[nodiscard]] const char *UnitName() const override;
  [[nodiscard]] const char *Author() const override;

  float turret_rotation_{0.0f};
  bool protecteed = false;
  uint32_t protectskill_countdown_ = {0};
  uint32_t protectcool_countdown_ = 60;
  uint32_t deathcool_countdown_ = 0;
  uint32_t fire_count_down_ = 0;
  uint32_t mine_count_down_ = 0;
};
}  // namespace battle_game::unit
