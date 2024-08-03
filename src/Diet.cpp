#ifndef DIET_CPP_
#define DIET_CPP_



double daily_water(Usuario user){
    return (0.035*user.weight_);
}
double calc_metabolism(Usuario user){
    if(user.sexo_ = 'H'){ // homem
        return (66 + 13.8*user.weight_ + 5*user.height_ - 6.8*(2024-user.birth_year_)); 
    }else{                //mulher
        return(655 + 9.6*user.weight_ + 1,8*user.height_ - 4.7*(2024-user.birth_year_));
    }
}

#endif