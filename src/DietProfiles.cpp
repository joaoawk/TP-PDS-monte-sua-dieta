#include "../include/DietProfiles.hpp"
#include "../include/Login.hpp"



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
  int base_calories = get_basal_metabolism();
  if (user_.objective_ == "bulking") {
    base_calories += 500;
  } else if (user_.objective_ == "cutting") {
    base_calories -= 500;
  }

  return base_calories;
}

