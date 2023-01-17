/*
 * \file Journal.cpp
 * \brief Classe journal
 * \author Emilio Lemus
 * \date 2022-11-28
 *
 */

#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include "Journal.h"
#include "Reference.h"
#include "validationFormat.h"

using namespace std;

namespace biblio
{


  /*
   * \brief constructeur de la class
   *
   * \param[in] p_auteurs sois un ou plusieur auteur
   * \pre valide en fonction de util::validerFormatNom
   * \param[in] p_titre
   * \pre ne peu pas etre vide
   * \param[in] p_annee l'année d'édition
   * \pre doit etre supérieur a 0
   * \param[in] p_identifiant est un code ISSN
   * \pre valid selon util::validerCodeIssn
   * \param[in] p_nom nom du journal dans le quel est publier la reference
   * \pre ne peu pas etre vide
   * \param[in] p_volume volume
   * \pre doit etre supérieur a 0
   * \param[in] p_numero numero de la reference
   * \pre doit etre supérieur a 0
   * \param[in] p_page premiere page de la reference dans le journal
   * \pre doit etre supérieur a 0
   *
   */

  Journal::Journal (const std::string& p_auteurs, const std::string& p_titre,
                    const unsigned int& p_annee, const std::string& p_identifiant,
                    const std::string& p_nom, const unsigned int& p_volume,
                    const unsigned int& p_numero, const unsigned int& p_page)
  : Reference (p_auteurs, p_titre, p_annee, p_identifiant), m_nom (p_nom),
  m_volume (p_volume), m_numero (p_numero), m_page (p_page)
  {

    PRECONDITION (p_nom.size () > 0);
    PRECONDITION (p_volume > 0);
    PRECONDITION (p_numero > 0);
    PRECONDITION (p_page > 0);
    PRECONDITION (util::validerCodeIssn (p_identifiant));

    POSTCONDITION (m_nom == p_nom);
    POSTCONDITION (m_volume == p_volume);
    POSTCONDITION (m_numero == p_numero);
    POSTCONDITION (m_page == p_page);


    INVARIANTS ();

  }


  /*
   * \brief Accesseur de l'attributs nom
   * \return une string du nom de la revue
   */

  const string
  Journal::reqNom () const
  {
    return m_nom;
  }


  /*
   * \brief Accesseur de l'attributs volume
   * \return int du volume de la revue
   */

  int
  Journal::reqVolume () const
  {
    return m_volume;
  }


  /*
   * \brief Accesseur de l'attributs numero
   * \return int du numero de la revue
   */

  int
  Journal::reqNumero () const
  {
    return m_numero;
  }


  /*
   * \brief Accesseur de l'attributs page
   * \return int de la page ou ce retrouve la reference
   */

  int
  Journal::reqPage () const
  {
    return m_page;
  }


  /*
   * \brief construction de la reference d'un journal
   * \return une string avec la reference d'un journal contruite
   */

  const string
  Journal::reqReferenceFormate () const
  {
    stringstream formatage;
    formatage << Reference::reqReferenceFormate () << " " << m_nom
            << ", vol. " << m_volume << ", no. " << m_numero << ", pp. "
            << m_page << ", " << reqAnnee () << ". "
            << Reference::reqIdentifiant () << ".";

    return formatage.str ();
  }


  /*
   * \brief clonage de l'objet Journal courant
   * \return un pointeur vers un nouvel objet Journal qui est clone de celui courant
   */

  Reference*
  Journal::clone () const
  {
    return new Journal (*this);
  }


  /*
   * \brief verification de l'invarience des atribues du Journal
   */

  void
  Journal::verifieInvariant () const
  {
    INVARIANT (m_nom.length () > 0);
    INVARIANT (m_volume > 0);
    INVARIANT (m_numero > 0);
    INVARIANT (m_page > 0);
    INVARIANT (util::validerCodeIssn (Reference::reqIdentifiant ()));
  }
} // namespace biblio