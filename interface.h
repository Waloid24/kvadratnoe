//--------------------------------------------------------------------------
//! @file interface.h
//--------------------------------------------------------------------------

#ifndef INTERFACE_H
#define INTERFACE_H

// rename (user_iteraction.h)

double menu(void); 

//===========================================================================
//!
//! @brief Функция проверяет значения введённых коэффициентов на корректность
//! 
//! @param Функция не принимает аргументов
//!
//! @return Возвращает верное значение коэффициента
//!
//---------------------------------------------------------------------------
double check_coefficient_for_corret();

//---------------------------------------------------------------------------
//!
//! @brief Функция, которая вводит значения в структуру
//! 
//! @param Функция принимает указатель на структуру
//! 
//! @see check_coefficient_for_corret()
//!
//! @note Выводит получившееся квадратное уравнение
//!
//! @return Функция не возвращает значение коэффициента
//!
//----------------------------------------------------------------------------
void enter_coefficients_for_eq (struct coef_and_sol * eq);

//----------------------------------------------------------------------------
//!
//! @breif Функция, выводит результат решения квадратного уравнения
//!
//! @param Функция принимает указатель на структуру
//!
//! @return Функция выводит количество решений квадратного уравнения
//!
//----------------------------------------------------------------------------
void output_solutions_this_equation (struct coef_and_sol * eq);

#endif
