#ifndef USER_INPUT_H_INCLUDED
#define USER_INPUT_H_INCLUDED

/*
* Simple user input library that makes writing of exercises easier.
* Provide simple functionality to get user input from console.
* Note: library does not protect you from integer overflow problem of scanf
* that we are using under the hood. Writing of robust user input library is too redundant for
* learning purposes.
* See https://stackoverflow.com/questions/28007600/detecting-integral-overflow-with-scanf for more info.
*/

/** \brief Get integer value from user console input.
 *
 * \param minValue const int Minimal acceptable value for user input (int < minValue).
 * \param maxValue const int Maximal acceptable value for user input (int > maxValue).
 * \param prompt const char* Prompt for user input.
 * \param error const char* Message in case user entered incorrect value.
 * \return Int value got from user input.
 */
int getIntFromUser(const int minValue,
                   const int maxValue,
                   const char* prompt,
                   const char* error);

/** \brief Get double value from user console input.
 *
 * \param minValue const double Minimal acceptable value for user input (double < minValue).
 * \param maxValue const double Maximal acceptable value for user input (double > maxValue).
 * \param prompt const char* Prompt for user input.
 * \param error const char* Message in case user entered incorrect value.
 * \return Double value got from user input.
 */
double getDoubleFromUser(const double minValue,
                         const double maxValue,
                         const char* prompt,
                         const char* error);

#endif // USER_INPUT_H_INCLUDED
