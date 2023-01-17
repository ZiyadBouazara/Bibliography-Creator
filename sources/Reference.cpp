/*
 * \file Reference.cpp
 * \brief Classe Reference
 * \author Emilio Lemus
 * \date 2022-10-12
 *
 */

#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include "Reference.h"
#include "validationFormat.h"

using namespace std;

namespace biblio
{


  /*
   * \brief constructeur de la classe
   *
   * \param[in] p_auteurs sois un ou plusieur auteur
   * \pre valide en fonction de util::validerNom
   * \param[in] p_titre
   * \pre ne peu pas etre vide
   * \param[in] p_annee l'année d'édition
   * \pre doit etre supérieur a 0
   * \param[in] p_identifiant est soit un code ISSN ou ISBN
   * \pre valid selon util::validerCodeIssn ou util::validerCodeIsbn
   *
   */

  Reference::Reference (const std::string& p_auteurs, const std::string& p_titre, const unsigned int& p_annee, const std::string& p_identifiant)
  : m_auteurs (p_auteurs), m_titre (p_titre), m_annee (p_annee), m_identifiant (p_identifiant)
  {

    PRECONDITION (util::validerFormatNom (p_auteurs));
    PRECONDITION (p_auteurs.size () > 0);
    PRECONDITION (p_titre.size () > 0);
    PRECONDITION (p_annee > 0);
    PRECONDITION (p_identifiant.size () > 0);

    POSTCONDITION (m_auteurs == p_auteurs);
    POSTCONDITION (m_titre == p_titre);
    POSTCONDITION (m_annee == p_annee);
    POSTCONDITION (m_identifiant == p_identifiant);

    INVARIANTS ();
  }


  /*
   * \brief surcharge de l'operateur ==, compare tout les atribue de deux reference
   * \param[in] p_reference une autre Reference
   * \return un booleen indiquant si les deux references sont identique ou non
   */

  bool Reference::operator== (const Reference& p_reference) const
  {
    if (m_auteurs == p_reference.reqAuteurs () && m_titre == p_reference.reqTitre () &&
        m_annee == p_reference.reqAnnee () && m_identifiant == p_reference.reqIdentifiant ())
      {
        return true;
      }
    else
      {
        return false;
      }
  }


  /*
   * \brief Accesseur de l'attributs auteurs
   * \return une string de l'auteur de la reference
   */

  const std::string &
  Reference::reqAuteurs () const
  {
    return m_auteurs;
  }


  /*
   * \brief Accesseur de l'attributs Titre
   * \return une string du titre de la reference
   */

  const std::string &
  Reference::reqTitre () const
  {
    return m_titre;
  }


  /*
   * \brief Accesseur de l'attributs annee
   * \return un int de l'annee d'édition de la reference
   */

  const unsigned int&
  Reference::reqAnnee () const
  {
    return m_annee;
  }


  /*
   * \brief Accesseur de l'attributs identifiant
   * \return une string de l'identifiant de la reference
   */

  const std::string &
  Reference::reqIdentifiant () const
  {
    return m_identifiant;
  }


  /*
   * \brief modifie l'annee d'édition
   */

  void
  Reference::asgAnnee (const unsigned int& p_annee)
  {
    PRECONDITION (p_annee > 0);
    m_annee = p_annee;
    POSTCONDITION (m_annee == p_annee);

    INVARIANTS ();
  }


  /*
   * \brief construction de la reference
   * \return une string avec la reference contruite
   */

  const std::string
  Reference::reqReferenceFormate () const
  {
    std::stringstream formatage;
    formatage << m_auteurs << ". " << m_titre << ".";


    return formatage.str ();
  }


  /*
   * \brief verification de l'invarience des atribues de la Reference
   */

  void
  Reference::verifieInvariant () const
  {
    INVARIANT ((util::validerCodeIsbn (m_identifiant) || util::validerCodeIssn (m_identifiant)));
    INVARIANT (util::validerFormatNom (m_auteurs));
    INVARIANT (m_titre.length () > 0);
    INVARIANT (m_annee > 0);
  }
} // namespace biblio
