/*
 * \file ValisationFormat.h
 * \brief initialisation des fonctions de validation de format
 * \author Emilio Lemus
 * \date 2022-11-28
 *
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H
#include <string>

/*
 * \namespace util
 * \brief namespace permetant la validation des entrés de l'utilisateur
 */

namespace util
{

  bool validerFormatNom (const std::string& p_nom);
  bool validerCodeIssn (const std::string & p_issn);
  bool
  validerCodeIsbn (const std::string& p_isbn);
} // namespace util
#endif /* VALIDATIONFORMAT_H */
