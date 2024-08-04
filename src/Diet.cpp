#ifndef DIET_CPP_
#define DIET_CPP_


 // [0] = Kcal total, [1] = g de proteinas, [2] = g de gorduras, [3] = g de carboidratos
vector<double> Diet::Diet(Usuario user){
    Diet_[0] = Diet::calc_metabolism(user);
    Diet_[1] = (Diet::calc_protein(user));
    Diet_[2] = (Diet::calc_fats(user));
    Diet_[3] = (Diet::calc_carbs(user));
    return Diet_;
}
double Diet::daily_water(Usuario user){
    return (0.035*user.weight_);
}
double Diet::calc_metabolism(Usuario user){
    if(user.sexo_ = 'H'){ // homem
        return (66 + 13.8*user.weight_ + 5*user.height_ - 6.8*(2024-user.birth_year_)); 
    }else{                //mulher
        return(655 + 9.6*user.weight_ + 1,8*user.height_ - 4.7*(2024-user.birth_year_));
    }
}

double Diet::calc_protein(Usuario user){
    if(user.objective_ == "bulking"){
        return 0.25*calc_metabolism(user)/4;
    }else if(user.objective_ == "cutting"){
        0.3*calc_metabolism(user)/4;
    }else{ //maintaince
        0.5*calc_metabolism(user)/4;
    }
}
double  Diet::calc_fats(Usuario user){
    if(user.objective_ == "bulking"){
        return 0.15*calc_metabolism(user)/9;
    }else if(user.objective_ == "cutting"){
        0.3*calc_metabolism(user)/9;
    }else{ //maintaince
        0.3*calc_metabolism(user)/9;
    }
}
 double Diet::calc_carbs(Usuario user){
    if(user.objective_ == "bulking"){
        return 0.6*calc_metabolism(user)/4;
    }else if(user.objective_ == "cutting"){
        0.4*calc_metabolism(user)/4;
    }else{ //maintaince
        0.2*calc_metabolism(user)/4;
    }
 }
 /*
bulking
60% carb 25% proteína 15% gordura

maintaince
40% carb 30% proteína 30% gordura

cutting
20% carb 50% proteina 30% gordura
*/
#endif