/*
 * \file ReferenceException.cpp
 * \brief Classes ReferenceException, ReferenceDejaPresenteException et ReferenceAbsenteException
 * \author Équipe 14
 * \date 2022-10-12
 *
 */


#include "ReferenceException.h"

using namespace std;


/*
 * \brief Classe ReferenceException, hérite de runtime_error
 * \param[in] p_raison
 */
ReferenceException::ReferenceException (const string& p_raison) : runtime_error (p_raison) { }


/*
 * \brief Classe ReferenceDejaPresenteException, hérite de la classe ReferenceException
 * \param[in] p_raison
 */
ReferenceDejaPresenteException::ReferenceDejaPresenteException (const std::string& p_raison) : ReferenceException (p_raison) { }


/*
 * \brief Classe ReferenceAbsenteException, hérite de la classe ReferenceException
 * \param[in] p_raison
 */
ReferenceAbsenteException::ReferenceAbsenteException (const std::string& p_raison) : ReferenceException (p_raison) { }