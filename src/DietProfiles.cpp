#include "../include/DietProfiles.hpp"
#include "../include/Login.hpp"
#include <unordered_map>

void DietProfiles::set_basal_metabolism(int weight, int height, char gender, int birth_year) {
  switch(gender) {
    case 'H':
      calories_ = (66.47 + 13.75 * user_.weight_ + 5.003 * user_.height_ - 6.755 * (2024 - user_.birth_year_));
    case 'M':
      calories_ = (655.1 + 9.563 * user_.weight_ + 1.850 * user_.height_ - 4.676 * (2024 - user_.birth_year_));
  }
}

DietProfiles::DietProfiles(const Login::User &user) : user_(user) {
  set_basal_metabolism(user_.weight_, user_.height_, user_.gender_, user_.birth_year_);
}

int DietProfiles::get_basal_metabolism() {
  return calories_;
}

int DietProfiles::get_daily_water() {
  return (35 * user_.weight_);
}

int DietProfiles::get_needed_calories() {
  float base_calories = static_cast<float>(get_basal_metabolism());

  float multiplier = 1.1f + (user_.level_ - 1) * 0.12f;

  base_calories *= multiplier;

  if (user_.objective_ == "bulking") {
    base_calories += 500;
  } else if (user_.objective_ == "cutting") {
    base_calories -= 500;
  }

  return static_cast<int>(base_calories);
}

std::unordered_map<std::string, float> DietProfiles::get_macros() {
  std::unordered_map<std::string, float> macros;
  float calories = static_cast<float>(get_needed_calories());
  macros["carbs"] = 0.6 * calories / 4.0;
  macros["proteins"] = 0.3 * calories / 4.0;
  macros["fats"] = 0.2 * calories / 9.0;
  return macros;
}
