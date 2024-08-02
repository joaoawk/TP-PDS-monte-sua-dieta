#ifndef DIETA_CPP_
#define DIETA_CPP_


double Dieta::Calcula_metabolismo(Usuario user){
    if(user.sexo_ = 'H'){ // homem
        return (66 + 13.8*user.weight_ + 5*user.height_ - 6.8*(2024-user.birth_year_)); //formula metabolismo;
    }else{                //mulher
        return(655 + 9.6*user.weight_ + 1,8*user.height_ - 4.7*(2024-user.birth_year_));//deveriamos colocar a 
                                                                                        //formula da idade como
                                                                                        //metodo .age()
    }
}
double Dieta::Calcula_agua_diaria(Usuario user){
    return (0.035*user.weight_); // 35ml para cada Kg.
}


#endif